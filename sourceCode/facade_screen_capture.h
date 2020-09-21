#pragma once
#include <string>
#include <atlstr.h>
#include "AgoraSDKObject.h"

//#define PROCESS_LEVEL_AUDIO_DATA


struct JoinChannelData
{
	std::string token;
	std::string channelName;
	std::string info;
	int uid;
};

struct ScreenCaptureData
{
	int fps;
	int bitrate;
	int width;
	int height;
	std::string GameName;

	ScreenCaptureData() :
		fps(60),
		width(1280),
		height(720),
		bitrate(4000000) {}
};

class FacadeScreenCapture
{
public:
	FacadeScreenCapture();
	~FacadeScreenCapture();
	DWORD	getGameProcessID(const char* GameName);
	void	init_process_env(const char* GameName);
protected:
	std::string getAbsoluteDir();
	CStringA s2cs(const std::string &str);
	void	start_hook(const std::string &processName, const std::string &cmdLine, int timeout);
	void	StopMonitorThread();
	void	start_game_process(const char* GameName);
private:
	volatile bool	m_bScreenCaptureStarted;

	std::string m_strLogPath;
	HMODULE m_hIPCModule;
	std::string m_strAppID;
	HANDLE		m_hMonitorThread;
	JoinChannelData m_joinchannelData;

	ScreenCaptureData m_ScreenCaptureData;
};