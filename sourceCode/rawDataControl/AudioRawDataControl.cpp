#include "AudioRawDataControl.h"

namespace agora {
    namespace unity {
    
    AudioRawDataControl *AudioRawDataControl::_audioRawDataControlInstace = NULL;

    AudioRawDataControl::AudioRawDataControl()
    {

    }

    AudioRawDataControl::~AudioRawDataControl()
    {
        clearData();
    }

    AudioRawDataControl *AudioRawDataControl::getInstance()
    {
        if (_audioRawDataControlInstace == NULL)
        {
            _audioRawDataControlInstace = new AudioRawDataControl();
        }
        return _audioRawDataControlInstace;
    }

    void AudioRawDataControl::releaseInstance()
    {   
        if (_audioRawDataControlInstace)
        {
            delete _audioRawDataControlInstace;
            _audioRawDataControlInstace = NULL;
        }
    }

    int AudioRawDataControl::addAudioFrameObserver(IAudioFrameObserver *_audioFrameObserver)
    {
        _audioFrameObserverListMutex.lock();  
        _audioFrameObserverList.push_back(_audioFrameObserver);
        _audioFrameObserverListMutex.unlock();
        return 0;
    }

    int AudioRawDataControl::removeAudioFrameObserver(IAudioFrameObserver *_audioFrameObserver)
    {
        _audioFrameObserverListMutex.lock();
        std::list<IAudioFrameObserver*>::iterator _iterator;
        for (_iterator = _audioFrameObserverList.begin(); _iterator != _audioFrameObserverList.end(); _iterator++)
        {
            if ((*_iterator) == _audioFrameObserver)
            {
                _audioFrameObserverList.erase(_iterator);
                break;
            }
        } 
        _audioFrameObserverListMutex.unlock();
        return 0;
    }

    bool AudioRawDataControl::checkWheatherInAudioObserverList(IAudioFrameObserver *_audioFrameObserver)
    {
         _audioFrameObserverListMutex.lock();
        std::list<IAudioFrameObserver*>::iterator _iterator;
        for (_iterator = _audioFrameObserverList.begin(); _iterator != _audioFrameObserverList.end(); _iterator++)
        {
            if ((*_iterator) == _audioFrameObserver)
            {
                _audioFrameObserverListMutex.unlock();
                return true;
            }
        }
        _audioFrameObserverListMutex.unlock();
        return false;
    }

    void AudioRawDataControl::clearData()
    {
        _audioFrameObserverListMutex.lock();
        _audioFrameObserverList.clear();
        _audioFrameObserverListMutex.unlock(); 
    }

    bool AudioRawDataControl::onRecordAudioFrame(IAudioFrameObserver::AudioFrame& audioFrame)
    {
        _audioFrameObserverListMutex.lock();
        if (_onRecordAudioFrame != NULL)
        {
            _onRecordAudioFrame((int)audioFrame.type, audioFrame.samples, audioFrame.bytesPerSample, audioFrame.channels, audioFrame.samplesPerSec, audioFrame.buffer, audioFrame.renderTimeMs, audioFrame.avsync_type);
        }

        for (auto iterator = _audioFrameObserverList.begin(); iterator != _audioFrameObserverList.end(); iterator++)
        {
            (*iterator)->onRecordAudioFrame(audioFrame);
        }
        _audioFrameObserverListMutex.unlock();
        return true;
    }

    bool AudioRawDataControl::onPlaybackAudioFrame(IAudioFrameObserver::AudioFrame& audioFrame)
    {
        _audioFrameObserverListMutex.lock();
        if (_onPlaybackAudioFrame != NULL)
        {
            _onPlaybackAudioFrame((int)audioFrame.type, audioFrame.samples, audioFrame.bytesPerSample, audioFrame.channels, audioFrame.samplesPerSec, audioFrame.buffer, audioFrame.renderTimeMs, audioFrame.avsync_type);
        }
        std::list<IAudioFrameObserver*>::iterator _iterator;
        for (_iterator = _audioFrameObserverList.begin(); _iterator != _audioFrameObserverList.end(); _iterator++)
        {
            (*_iterator)->onPlaybackAudioFrame(audioFrame);
        }
        _audioFrameObserverListMutex.unlock();
        return true;
    }

    bool AudioRawDataControl::onMixedAudioFrame(IAudioFrameObserver::AudioFrame& audioFrame)
    {
        _audioFrameObserverListMutex.lock();
        if (_onMixedAudioFrame != NULL)
        {
            _onMixedAudioFrame((int)audioFrame.type, audioFrame.samples, audioFrame.bytesPerSample, audioFrame.channels, audioFrame.samplesPerSec, audioFrame.buffer, audioFrame.renderTimeMs, audioFrame.avsync_type);
        }
        std::list<IAudioFrameObserver*>::iterator _iterator;
        for (_iterator = _audioFrameObserverList.begin(); _iterator != _audioFrameObserverList.end(); _iterator++)
        {
            (*_iterator)->onMixedAudioFrame(audioFrame);
        }
        _audioFrameObserverListMutex.unlock();
        return true;
    }

    bool AudioRawDataControl::onPlaybackAudioFrameBeforeMixing(unsigned int uid, IAudioFrameObserver::AudioFrame& audioFrame)
    {
        _audioFrameObserverListMutex.lock();
        if (_onPlaybackAudioFrameBeforeMixing != NULL)
        {
            _onPlaybackAudioFrameBeforeMixing(uid, (int)audioFrame.type, audioFrame.samples, audioFrame.bytesPerSample, audioFrame.channels, audioFrame.samplesPerSec, audioFrame.buffer, audioFrame.renderTimeMs, audioFrame.avsync_type);
        }
        std::list<IAudioFrameObserver*>::iterator _iterator;
        for (_iterator = _audioFrameObserverList.begin(); _iterator != _audioFrameObserverList.end(); _iterator++)
        {
            (*_iterator)->onPlaybackAudioFrameBeforeMixing(uid, audioFrame);
        }
        _audioFrameObserverListMutex.unlock();
        return true;
    }
    
    void AudioRawDataControl::initEventonRecordAudioFrame(FUNC_OnRecordAudioFrame onRecordAudioFrame)
    {
         _audioFrameObserverListMutex.lock();
        _onRecordAudioFrame = onRecordAudioFrame;
         _audioFrameObserverListMutex.unlock();
    }
    
    void AudioRawDataControl::initEventonPlaybackAudioFrame(FUNC_OnPlaybackAudioFrame onPlaybackAudioFrame)
    {
        _audioFrameObserverListMutex.lock();
        _onPlaybackAudioFrame = onPlaybackAudioFrame;
        _audioFrameObserverListMutex.unlock();
    }

    void AudioRawDataControl::initEventonMixedAudioFrame(FUNC_OnMixedAudioFrame onMixedAudioFrame)
    {
        _audioFrameObserverListMutex.lock();
        _onMixedAudioFrame = onMixedAudioFrame;
        _audioFrameObserverListMutex.unlock();
    }

    void AudioRawDataControl::initEventonPlaybackAudioFrameBeforeMixing(FUNC_OnPlaybackAudioFrameBeforeMixing onPlaybackAudioFrameBeforeMixing)
    {
        _audioFrameObserverListMutex.lock();
        _onPlaybackAudioFrameBeforeMixing = onPlaybackAudioFrameBeforeMixing;
        _audioFrameObserverListMutex.unlock();
    }

    void AudioRawDataControl::initEventonPullAudioFrame(FUNC_OnPullAudioFrame onPullAudioFrame)
    {
        _audioFrameObserverListMutex.lock();
        _onPullAudioFrame = onPullAudioFrame;
        _audioFrameObserverListMutex.unlock();
    }

    int AudioRawDataControl::pullAudioFrame(IAudioFrameObserver::AudioFrame audioFrame)
    {
        _audioFrameObserverListMutex.lock();
        if (_onPullAudioFrame != NULL)
        {
            _onPullAudioFrame((int)audioFrame.type, audioFrame.samples, audioFrame.bytesPerSample, audioFrame.channels, audioFrame.samplesPerSec, audioFrame.buffer, audioFrame.renderTimeMs, audioFrame.avsync_type);
        }
        _audioFrameObserverListMutex.unlock();
        return 0;
    }
}
}
