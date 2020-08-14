#include "AgoraVideoDeviceManager.h"

namespace agora {
	namespace unity {
		AgoraVideoDeviceManager *AgoraVideoDeviceManager::_agoraVideoDeviceManagerInstance = NULL;

		AgoraVideoDeviceManager::AgoraVideoDeviceManager() {

		}

		AgoraVideoDeviceManager::~AgoraVideoDeviceManager()
		{
			if (_aVideoDeviceManager)
			{
				releaseAVideoDeviceManager();
			}
		}

		AgoraVideoDeviceManager *AgoraVideoDeviceManager::getInstance()
		{
			if (_agoraVideoDeviceManagerInstance == NULL)
			{
				_agoraVideoDeviceManagerInstance = new AgoraVideoDeviceManager();
			}
			return _agoraVideoDeviceManagerInstance;
		}

		void AgoraVideoDeviceManager::releaseInstance()
		{
			if (_agoraVideoDeviceManagerInstance)
			{
				delete _agoraVideoDeviceManagerInstance;
				_agoraVideoDeviceManagerInstance = NULL;
			}
		}

		bool AgoraVideoDeviceManager::createAVideoDeviceManager(IRtcEngine *irtcEngine)
		{
			if (_aVideoDeviceManager == NULL)
			{
				_aVideoDeviceManager = new AVideoDeviceManager(irtcEngine);
				if (_aVideoDeviceManager->get() != NULL)
				{
					_iVideoDeviceCollection = (*_aVideoDeviceManager)->enumerateVideoDevices();
					if (_iVideoDeviceCollection)
					{
						return true;
					}
					else
					{
						delete _aVideoDeviceManager;
						_aVideoDeviceManager = NULL;
						return false;
					}
				}
				else 
				{
					return false;
				}
			}
			return true;
		}

		int AgoraVideoDeviceManager::releaseAVideoDeviceManager() {
			if (_aVideoDeviceManager)
			{
				if (_iVideoDeviceCollection)
				{
					_iVideoDeviceCollection->release();
					_iVideoDeviceCollection = NULL;
				}
				_aVideoDeviceManager->release();
				delete _aVideoDeviceManager;
				_aVideoDeviceManager = NULL;
			}
			return 0;
		}

		int AgoraVideoDeviceManager::startVideoDeviceTest(void *hwnd)
		{
			if (_aVideoDeviceManager && _aVideoDeviceManager->get())
			{
				return (*_aVideoDeviceManager)->startDeviceTest(hwnd);
			}
			return NOT_INIT_AVIDEOMANAGER;
		}

		int AgoraVideoDeviceManager::stopVideoDeviceTest()
		{
			if (_aVideoDeviceManager && _aVideoDeviceManager->get())
			{
				return (*_aVideoDeviceManager)->stopDeviceTest();
			}
			return NOT_INIT_AVIDEOMANAGER;
		}

		int AgoraVideoDeviceManager::getVideoDeviceCollectionCount()
		{
			if (_aVideoDeviceManager && _iVideoDeviceCollection)
			{
				return _iVideoDeviceCollection->getCount();
			}
			else
			{
				return NOT_INIT_AVIDEOMANAGER;
			}
		}

		int AgoraVideoDeviceManager::getVideoDeviceCollectionDevice(int index, char deviceName[LENGTH_MAX], char deviceId[LENGTH_MAX])
		{
			if (_aVideoDeviceManager && _iVideoDeviceCollection)
			{
				return _iVideoDeviceCollection->getDevice(index, deviceName, deviceId);
			}
			return NOT_INIT_AVIDEOMANAGER;
		}

		int AgoraVideoDeviceManager::getCurrentVideoDevice(char deviceId[LENGTH_MAX])
		{
			if (_aVideoDeviceManager && _aVideoDeviceManager->get())
			{
				return (*_aVideoDeviceManager)->getDevice(deviceId);
			}
			return NOT_INIT_AVIDEOMANAGER;
		}

		int AgoraVideoDeviceManager::setVideoDeviceCollectionDevice(const char deviceId[LENGTH_MAX])
		{
			if (_aVideoDeviceManager && _aVideoDeviceManager->get())
			{
				return (*_aVideoDeviceManager)->setDevice(deviceId);
			}
			return NOT_INIT_AVIDEOMANAGER;
		}	
	}
}
