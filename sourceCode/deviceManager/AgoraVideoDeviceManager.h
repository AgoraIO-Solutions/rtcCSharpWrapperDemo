#ifndef AGORA_VIDEO_DEVICE_MANAGER

#define AGORA_VIDEO_DEVICE_MANAGER
#include "../common_header.h"

#define NOT_INIT_AVIDEOMANAGER -10000000;
namespace agora
{
    namespace unity
    {
		class AgoraVideoDeviceManager
		{
		private:
			static AgoraVideoDeviceManager *_agoraVideoDeviceManagerInstance;
			AVideoDeviceManager *_aVideoDeviceManager = nullptr;
			IVideoDeviceCollection *_iVideoDeviceCollection = nullptr;
			AgoraVideoDeviceManager();

		public:
			~AgoraVideoDeviceManager();
			static AgoraVideoDeviceManager *getInstance();
			static void releaseInstance();
			virtual int startVideoDeviceTest(void *hwnd);
			virtual int stopVideoDeviceTest();
			virtual bool createAVideoDeviceManager(IRtcEngine *irtcEngine);
			virtual int releaseAVideoDeviceManager();
			virtual int getVideoDeviceCollectionCount();
			virtual int getVideoDeviceCollectionDevice(int index, char deviceName[LENGTH_MAX], char deviceId[LENGTH_MAX]);
			virtual int getCurrentVideoDevice(char deviceId[LENGTH_MAX]);
			virtual int setVideoDeviceCollectionDevice(const char deviceId[LENGTH_MAX]);
		};
	}
}
#endif 


