#include "AgoraAudioPlaybackDeviceManager.h"

namespace agora {
   	namespace unity {

		AgoraAudioPlaybackDeviceManager *AgoraAudioPlaybackDeviceManager::_agoraAudioPlaybackDeviceManagerInstance;

		AgoraAudioPlaybackDeviceManager::AgoraAudioPlaybackDeviceManager()
		{

		}

		AgoraAudioPlaybackDeviceManager::~AgoraAudioPlaybackDeviceManager()
		{
			if (_aAudioDeviceManager && _aAudioDeviceManager->get())
			{
				releaseAAudioPlaybackDeviceManager();
			}
		}

		AgoraAudioPlaybackDeviceManager *AgoraAudioPlaybackDeviceManager::getInstance()
		{
			if (_agoraAudioPlaybackDeviceManagerInstance == NULL)
			{
				_agoraAudioPlaybackDeviceManagerInstance = new AgoraAudioPlaybackDeviceManager();
			}
			return _agoraAudioPlaybackDeviceManagerInstance;
		}

		void AgoraAudioPlaybackDeviceManager::releaseInstance()
		{
			if (_agoraAudioPlaybackDeviceManagerInstance)
			{
				delete _agoraAudioPlaybackDeviceManagerInstance;
				_agoraAudioPlaybackDeviceManagerInstance = NULL;
			}
		}

		bool AgoraAudioPlaybackDeviceManager::creatAAudioPlaybackDeviceManager(IRtcEngine *irtcEngine)
		{
			if (_aAudioDeviceManager == NULL)
			{
				_aAudioDeviceManager = new AAudioDeviceManager(irtcEngine);
				if (_aAudioDeviceManager->get() != NULL)
				{
					_iPlaybackDevicesCollection = (*_aAudioDeviceManager)->enumeratePlaybackDevices();

					if (_iPlaybackDevicesCollection)
					{
						return true;
					}
					else
					{
						if (_iPlaybackDevicesCollection)
						{
							_iPlaybackDevicesCollection->release();
							_iPlaybackDevicesCollection = NULL;
						}
						delete _aAudioDeviceManager;
						_aAudioDeviceManager = NULL;
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

		int AgoraAudioPlaybackDeviceManager::releaseAAudioPlaybackDeviceManager()
		{
			if (_aAudioDeviceManager)
			{
				if (_iPlaybackDevicesCollection)
				{
					_iPlaybackDevicesCollection->release();
					_iPlaybackDevicesCollection = NULL;
				}

				_aAudioDeviceManager->release();
				delete _aAudioDeviceManager;
				_aAudioDeviceManager = NULL;
			}
			return 0;
		}

		int AgoraAudioPlaybackDeviceManager::getPlaybackDeviceCount()
		{
			if (_iPlaybackDevicesCollection)
			{
				return _iPlaybackDevicesCollection->getCount();
			}
			return NOT_INIT_AUDIO_DEVICE_MANAGER;
		}

		int AgoraAudioPlaybackDeviceManager::getPlaybackDevice(int index, char deviceName[LENGTH_MAX], char deviceId[LENGTH_MAX])
		{
			if (_iPlaybackDevicesCollection)
			{
				return _iPlaybackDevicesCollection->getDevice(index, deviceName, deviceId);
			}
			return NOT_INIT_AUDIO_DEVICE_MANAGER;
		}

		int AgoraAudioPlaybackDeviceManager::getCurrentPlaybackDevice(char deviceId[LENGTH_MAX])
		{
			if (_aAudioDeviceManager && _aAudioDeviceManager->get())
			{
				return _aAudioDeviceManager->get()->getPlaybackDevice(deviceId);
			}
			return NOT_INIT_AUDIO_DEVICE_MANAGER;
		}

		int AgoraAudioPlaybackDeviceManager::getCurrentPlaybackDeviceInfo(char deviceName[LENGTH_MAX], char deviceId[LENGTH_MAX])
		{
			if (_aAudioDeviceManager && _aAudioDeviceManager->get())
			{
				return _aAudioDeviceManager->get()->getPlaybackDeviceInfo(deviceId, deviceName);
			}
			return NOT_INIT_AUDIO_DEVICE_MANAGER;
		}

		int AgoraAudioPlaybackDeviceManager::setPlaybackDevice(const char deviceId[LENGTH_MAX])
		{
			if (_aAudioDeviceManager && _aAudioDeviceManager->get())
			{
				return _aAudioDeviceManager->get()->setPlaybackDevice(deviceId);
			}
			return NOT_INIT_AUDIO_DEVICE_MANAGER;
		}

		int AgoraAudioPlaybackDeviceManager::setPlaybackDeviceVolume(int volume)
		{
			if (_aAudioDeviceManager && _aAudioDeviceManager->get())
			{
				return _aAudioDeviceManager->get()->setPlaybackDeviceVolume(volume);
			}
			return NOT_INIT_AUDIO_DEVICE_MANAGER;
		}

		int AgoraAudioPlaybackDeviceManager::getPlaybackDeviceVolume()
		{
			if (_aAudioDeviceManager && _aAudioDeviceManager->get())
			{
				int volume = -1;
				_aAudioDeviceManager->get()->getPlaybackDeviceVolume(&volume);
				return volume;
			}
			return NOT_INIT_AUDIO_DEVICE_MANAGER;
		}

		int AgoraAudioPlaybackDeviceManager::setPlaybackDeviceMute(bool mute)
		{
			if (_aAudioDeviceManager && _aAudioDeviceManager->get())
			{
				return _aAudioDeviceManager->get()->setPlaybackDeviceMute(mute);
			}
			return NOT_INIT_AUDIO_DEVICE_MANAGER;
		}

		bool AgoraAudioPlaybackDeviceManager::isPlaybackDeviceMute()
		{
			if (_aAudioDeviceManager && _aAudioDeviceManager->get())
			{
				bool mute = false;
				_aAudioDeviceManager->get()->getPlaybackDeviceMute(&mute);
				return mute;
			}
			return false;
		}

		int AgoraAudioPlaybackDeviceManager::startPlaybackDeviceTest(const char *testAudioFilePath)
		{
			if (_aAudioDeviceManager && _aAudioDeviceManager->get())
			{
				return (*_aAudioDeviceManager)->startPlaybackDeviceTest(testAudioFilePath);
			}
			return NOT_INIT_AUDIO_DEVICE_MANAGER;
		}

		int AgoraAudioPlaybackDeviceManager::stopPlaybackDeviceTest()
		{
			if (_aAudioDeviceManager && _aAudioDeviceManager->get())
			{
				return (*_aAudioDeviceManager)->stopPlaybackDeviceTest();
			}
			return NOT_INIT_AUDIO_DEVICE_MANAGER;
		}
	}
}