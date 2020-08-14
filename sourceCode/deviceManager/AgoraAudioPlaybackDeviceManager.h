#ifndef AGORA_AUDIO_PLAYBACK_DEVICE_MANAGER
#define AGORA_AUDIO_PLAYBACK_DEVICE_MANAGER

#include "../common_header.h"
//#ifdef WRAPPER_WINDOWS 
#define NOT_INIT_AUDIO_DEVICE_MANAGER -10000000;

namespace agora {
	namespace unity {
		class AgoraAudioPlaybackDeviceManager
		{
		private:
			static AgoraAudioPlaybackDeviceManager *_agoraAudioPlaybackDeviceManagerInstance;
			AAudioDeviceManager *_aAudioDeviceManager = nullptr;
			IAudioDeviceCollection *_iPlaybackDevicesCollection = nullptr;
			AgoraAudioPlaybackDeviceManager();

		public:
			~AgoraAudioPlaybackDeviceManager();
			static AgoraAudioPlaybackDeviceManager *getInstance();
			static void releaseInstance();
			virtual bool creatAAudioPlaybackDeviceManager(IRtcEngine *irtcEngine);
			virtual int releaseAAudioPlaybackDeviceManager();
			virtual int getPlaybackDeviceCount();
			virtual int getPlaybackDevice(int index, char deviceName[LENGTH_MAX], char deviceId[LENGTH_MAX]);
			virtual int getCurrentPlaybackDevice(char deviceId[LENGTH_MAX]);
			virtual int getCurrentPlaybackDeviceInfo(char deviceName[LENGTH_MAX], char deviceId[LENGTH_MAX]);
			virtual int setPlaybackDevice(const char deviceId[LENGTH_MAX]);
			virtual int setPlaybackDeviceVolume(int volume);
			virtual int getPlaybackDeviceVolume();
			virtual int setPlaybackDeviceMute(bool mute);
			virtual bool isPlaybackDeviceMute();
			virtual int startPlaybackDeviceTest(const char *testAudioFilePath);
			virtual int stopPlaybackDeviceTest();
		};
	}
}
#endif