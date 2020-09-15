# Agora RTC C# Windows Application Demo
### In this repository, it shows how to use agora windows sdk to build a C# based windows application.

it includes below projects:

## rtcCSharpWrapper
  CLI wrapper for agora windows SDK which expose the interface for C# layer
## rtcCSharpWrapperDemo
  An sample Windows Application which includes a full wrapper class for agoraRtcEngine on C#. And a simple implementation for sharing a windows desktop application to remote user.
- [C# version Agora API Reference](https://github.com/AgoraIO-Solutions/rtcCSharpWrapperDemo/blob/master/rtcCSharpWrapperDemo/mainpage.md)
## IPC
  Communication Interface for C# dual-process
## ScreenShareProcess
  Sub Process Implementation for screen sharing
  
## How to build and run demo
- The demo developed with Agrora Windows SDK 3.0.1
- download the windows sdk and copy the include and lib folder under rtcCSharpWrapperDemo\native_sdk
- open rtcCSharpWrapperDemo.sln with Virtual Studio 2017
- retarget the solution to align your windows sdk if needed
- set target to Debug x64 cpu
- set rtcCSharpWrapperDemo as startup project
- build entire solution
- copy all files from SDK/dll folder to rtcCSharpWrapperDemo\rtcCSharpWrapperDemo\bin\x64\Debug
- run the project

## How to use cross communication
Need install Newtonsoft.Json from nuget for parsing json object
#### Sender:
```
PushMessage message = new PushMessage()
{
	messageType = IPC.MessageType.START_SHARE_BY_WINDOW,
	messageBody = JsonConvert.SerializeObject(screenInfo),
};
IPCChannel.SendMessage(ipcName: SUB_PROCESS, command: JsonConvert.SerializeObject(message));
```
#### Receiver:
```
private IPC.IPCChannel _ipc;
private string PROCESS_ID = "sub";
_ipc = new IPC.IPCChannel(this, PROCESS_ID);
_ipc.OnMessage += OnMessage;
private int OnMessage(IWin32Window receiver, string message)
{
	IPC.PushMessage pushMessage = JsonConvert.DeserializeObject<IPC.PushMessage>(message);
}
```
