#include "AgoraAudioRecordingDeviceManager.h"

namespace agora {
	namespace unity {
		AgoraAudioRecordingDeviceManager *AgoraAudioRecordingDeviceManager::_agoraAudioRecordingDeviceManagerInstance;
		AgoraAudioRecordingDeviceManager::AgoraAudioRecordingDeviceManager()
		{

		}

		AgoraAudioRecordingDeviceManager::~AgoraAudioRecordingDeviceManager()
		{
			if (_aAudioDeviceManager && _aAudioDeviceManager->get())
			{
				releaseAAudioRecordingDeviceManager();
			}
		}

		AgoraAudioRecordingDeviceManager *AgoraAudioRecordingDeviceManager::getInstance()
		{
			if (_agoraAudioRecordingDeviceManagerInstance == NULL)
			{
				_agoraAudioRecordingDeviceManagerInstance = new AgoraAudioRecordingDeviceManager();
			}
			return _agoraAudioRecordingDeviceManagerInstance;
		}

		void AgoraAudioRecordingDeviceManager::releaseInstance()
		{
			if (_agoraAudioRecordingDeviceManagerInstance)
			{
				delete _agoraAudioRecordingDeviceManagerInstance;
				_agoraAudioRecordingDeviceManagerInstance = NULL;
			}
		}
		
		bool AgoraAudioRecordingDeviceManager::creatAAudioRecordingDeviceManager(IRtcEngine *irtcEngine)
		{
			if (_aAudioDeviceManager == NULL)
			{
				_aAudioDeviceManager = new AAudioDeviceManager(irtcEngine); 
				if (_aAudioDeviceManager->get() != NULL)
				{
					_iRecordingDevicesCollection = (*_aAudioDeviceManager)->enumerateRecordingDevices();
					if (_iRecordingDevicesCollection)
					{
						return true;
					}
					else 
					{
						if (_iRecordingDevicesCollection)
						{
							_iRecordingDevicesCollection->release();
							_iRecordingDevicesCollection = NULL;
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
		
		int AgoraAudioRecordingDeviceManager::releaseAAudioRecordingDeviceManager()
		{ 
			if (_aAudioDeviceManager)
			{
				if (_iRecordingDevicesCollection)
				{
					_iRecordingDevicesCollection->release();
					_iRecordingDevicesCollection = NULL;
				}
				_aAudioDeviceManager->release();
				delete _aAudioDeviceManager;
				_aAudioDeviceManager = NULL;
			}
			return 0;
		}

		int AgoraAudioRecordingDeviceManager::getRecordingDeviceCount()
		{
			if (_iRecordingDevicesCollection)
			{
				return _iRecordingDevicesCollection->getCount();
			}
			return NOT_INIT_AUDIO_DEVICE_MANAGER;
		}
		
		int AgoraAudioRecordingDeviceManager::getRecordingDevice(int index, char deviceName[LENGTH_MAX], char deviceId[LENGTH_MAX])
		{
			if (_iRecordingDevicesCollection)
			{
				return _iRecordingDevicesCollection->getDevice(index, deviceName, deviceId);
			}
			return NOT_INIT_AUDIO_DEVICE_MANAGER;
		}

		int AgoraAudioRecordingDeviceManager::getCurrentRecordingDevice(char deviceId[LENGTH_MAX])
		{
			if (_aAudioDeviceManager && _aAudioDeviceManager->get())
			{
				return _aAudioDeviceManager->get()->getRecordingDevice(deviceId);
			}
			return NOT_INIT_AUDIO_DEVICE_MANAGER;
		}

		int AgoraAudioRecordingDeviceManager::getCurrentRecordingDeviceInfo(char deviceName[LENGTH_MAX], char deviceId[LENGTH_MAX])
		{
			if (_aAudioDeviceManager && _aAudioDeviceManager->get())
			{
				if (_aAudioDeviceManager && _aAudioDeviceManager->get())
				{
					return _aAudioDeviceManager->get()->getRecordingDeviceInfo(deviceId, deviceName);
				}
			}
			return NOT_INIT_AUDIO_DEVICE_MANAGER;
		}

		int AgoraAudioRecordingDeviceManager::setRecordingDevice(const char deviceId[LENGTH_MAX])
		{
			if (_aAudioDeviceManager && _aAudioDeviceManager->get())
			{
				return _aAudioDeviceManager->get()->setRecordingDevice(deviceId);
			}
			return NOT_INIT_AUDIO_DEVICE_MANAGER;
		}

		int AgoraAudioRecordingDeviceManager::setRecordingDeviceVolume(int volume)
		{
			if (_aAudioDeviceManager && _aAudioDeviceManager->get())
			{
				return _aAudioDeviceManager->get()->setRecordingDeviceVolume(volume);
			}
			return NOT_INIT_AUDIO_DEVICE_MANAGER;
		}

		int AgoraAudioRecordingDeviceManager::getRecordingDeviceVolume()
		{
			if (_aAudioDeviceManager && _aAudioDeviceManager->get())
			{
				int volume = -1;
				_aAudioDeviceManager->get()->getRecordingDeviceVolume(&volume);
				return volume;
			}
			return NOT_INIT_AUDIO_DEVICE_MANAGER;
		}

		int AgoraAudioRecordingDeviceManager::setRecordingDeviceMute(bool mute)
		{
			if (_aAudioDeviceManager && _aAudioDeviceManager->get())
			{
				return _aAudioDeviceManager->get()->setRecordingDeviceMute(mute);
			}
			return NOT_INIT_AUDIO_DEVICE_MANAGER;
		}

		bool AgoraAudioRecordingDeviceManager::isRecordingDeviceMute()
		{
			if (_aAudioDeviceManager && _aAudioDeviceManager->get())
			{
				bool mute = false;
				_aAudioDeviceManager->get()->getRecordingDeviceMute(&mute);
				return mute;
			}
			return NOT_INIT_AUDIO_DEVICE_MANAGER;
		}

		int AgoraAudioRecordingDeviceManager::startRecordingDeviceTest(int indicationInterval)
		{
			if (_aAudioDeviceManager && _aAudioDeviceManager->get())
			{
				return (*_aAudioDeviceManager)->startRecordingDeviceTest(indicationInterval);
			}
			return NOT_INIT_AUDIO_DEVICE_MANAGER;
		}

		int AgoraAudioRecordingDeviceManager::stopRecordingDeviceTest()
		{
			if (_aAudioDeviceManager && _aAudioDeviceManager->get())
			{
				return (*_aAudioDeviceManager)->stopRecordingDeviceTest();
			}
			return NOT_INIT_AUDIO_DEVICE_MANAGER;
		}
	}
} 