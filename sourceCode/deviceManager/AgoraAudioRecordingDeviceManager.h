#ifndef AGORA_AUDIO_DEVICE_MANAGER
#define AGORA_AUDIO_DEVICE_MANAGER
#include "../common_header.h"
#define NOT_INIT_AUDIO_DEVICE_MANAGER -10000000;

namespace agora {
	namespace unity {
		class AgoraAudioRecordingDeviceManager
		{
		private:
			static AgoraAudioRecordingDeviceManager *_agoraAudioRecordingDeviceManagerInstance;
			AAudioDeviceManager *_aAudioDeviceManager = nullptr;
			IAudioDeviceCollection *_iRecordingDevicesCollection = nullptr;
			AgoraAudioRecordingDeviceManager();

		public:
			~AgoraAudioRecordingDeviceManager();
			static AgoraAudioRecordingDeviceManager *getInstance();
			static void releaseInstance();
			virtual bool creatAAudioRecordingDeviceManager(IRtcEngine *irtcEngine);
			virtual int releaseAAudioRecordingDeviceManager();
			virtual int getRecordingDeviceCount();
			virtual int getRecordingDevice(int index, char deviceName[LENGTH_MAX], char deviceId[LENGTH_MAX]);
			virtual int getCurrentRecordingDevice(char deviceId[LENGTH_MAX]);
			virtual int getCurrentRecordingDeviceInfo(char deviceName[LENGTH_MAX], char deviceId[LENGTH_MAX]);
			virtual int setRecordingDevice(const char deviceId[LENGTH_MAX]);
			virtual int setRecordingDeviceVolume(int volume);
			virtual int getRecordingDeviceVolume();
			virtual int setRecordingDeviceMute(bool mute);
			virtual bool isRecordingDeviceMute();
			virtual int startRecordingDeviceTest(int indicationInterval);
			virtual int stopRecordingDeviceTest();
		};
	}
}

#endif
