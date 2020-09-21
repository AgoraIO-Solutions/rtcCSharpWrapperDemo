#include "facade_screen_capture.h"
#include <TlHelp32.h>
#include <stdio.h>

FacadeScreenCapture::FacadeScreenCapture()
{

}
void FacadeScreenCapture::StopMonitorThread()
{
	m_bScreenCaptureStarted = false;

	if (m_hMonitorThread)
	{
		WaitForSingleObject(m_hMonitorThread, INFINITE);
		CloseHandle(m_hMonitorThread);
		m_hMonitorThread = NULL;
	}
}
bool KillProcess(DWORD dwPid)
{
	HANDLE killHandle = OpenProcess(PROCESS_TERMINATE, FALSE, dwPid);
	if (killHandle == NULL)
		return false;

	TerminateProcess(killHandle, 0);
	CloseHandle(killHandle);

	return true;
}
FacadeScreenCapture::~FacadeScreenCapture()
{
	StopMonitorThread();

	if (m_hMonitorThread)
	{
		::FreeLibrary(m_hIPCModule);
		m_hIPCModule = NULL;
	}
	KillProcess(getGameProcessID("stub-process.exe"));
	KillProcess(getGameProcessID("agora_game_record.exe"));
	KillProcess(getGameProcessID("get-d3dfun-offset.exe"));
}
CStringA FacadeScreenCapture::s2cs(const std::string &str) {

	int nLen = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length() + 1, NULL, 0);
	WCHAR *LpWstr = new WCHAR[nLen];
	ZeroMemory(LpWstr, nLen);
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length() + 1, LpWstr, nLen);

	CString strReturn(LpWstr);
	delete[] LpWstr;

	return strReturn;
}
std::string FacadeScreenCapture::getAbsoluteDir() {

	TCHAR path[MAX_PATH] = { 0 };
	GetModuleFileName(nullptr, path, MAX_PATH);

	std::string filePath = CStringA(path).GetBuffer();
	return filePath.substr(0, filePath.rfind("\\") + 1);
}
void FacadeScreenCapture::start_hook(const std::string &processName, const std::string &cmdLine, int timeout)
{
	STARTUPINFO si;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_HIDE;
	PROCESS_INFORMATION pi;
	ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));

	//CStringA CmdLine;
	std::string fullpath = getAbsoluteDir() + processName;
	//CmdLine.Format(("%s \"%s\""), s2cs(fullpath), s2cs(cmdLine));
	char chCmd[1024] = { 0 };
	sprintf(chCmd, "%s \"%s\"", fullpath.c_str(), cmdLine.c_str());
	if (!CreateProcessA(NULL, chCmd, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
		return;

	WaitForSingleObject(pi.hThread, timeout);

	if (pi.hProcess)
		CloseHandle(pi.hProcess);

	if (pi.hThread)
		CloseHandle(pi.hThread);

	return;
}
void FacadeScreenCapture::start_game_process(const char* GameName)
{
	STARTUPINFO si;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);

	PROCESS_INFORMATION pi;
	ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));

	if (!CreateProcess(GameName, NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
		return;

	if (pi.hProcess)
		CloseHandle(pi.hProcess);

	if (pi.hThread)
		CloseHandle(pi.hThread);
}
struct handle_data {
	unsigned long process_id;
	HWND best_handle;
};

BOOL IsMainWindow(HWND handle)
{
	return GetWindow(handle, GW_OWNER) == (HWND)0 && IsWindowVisible(handle);
}

BOOL CALLBACK EnumWindowsCallback(HWND handle, LPARAM lParam)
{
	handle_data& data = *(handle_data*)lParam;
	unsigned long process_id = 0;
	GetWindowThreadProcessId(handle, &process_id);
	if (data.process_id != process_id || !IsMainWindow(handle)) {
		return TRUE;
	}
	data.best_handle = handle;
	return FALSE;
}
HWND FindMainWindow(unsigned long process_id)
{
	handle_data data;
	data.process_id = process_id;
	data.best_handle = 0;
	EnumWindows(EnumWindowsCallback, (LPARAM)&data);
	return data.best_handle;
}
void FacadeScreenCapture::init_process_env(const char* GameName)
{
	//get d3d function offset
	KillProcess(getGameProcessID("get-d3dfun-offset.exe"));
	start_hook(TEXT("get-d3dfun-offset.exe"), "", 1000);

	//hook api
	KillProcess(getGameProcessID("stub-process.exe"));
	start_hook(TEXT("stub-process.exe"), GameName, 100);

	//start game process
	start_game_process(GameName);
}


DWORD FacadeScreenCapture::getGameProcessID(const char* GameName)
{
	std::string strGameName = GameName;
	if (strGameName.empty()) return 0;

	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(pe32);

	HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == INVALID_HANDLE_VALUE)
		return 0;

	BOOL bMore = ::Process32First(hProcessSnap, &pe32);
	while (bMore)
	{
		if (strGameName.find((char *)pe32.szExeFile) != std::string::npos)
		{
			::CloseHandle(hProcessSnap);

			//10s
			const int HwndWaitTime = 500;
			Sleep(HwndWaitTime);

			return pe32.th32ProcessID;
		}

		bMore = ::Process32Next(hProcessSnap, &pe32);
	}

	::CloseHandle(hProcessSnap);
	return 0;
}
