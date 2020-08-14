#include "IAgoraUnityEngine.h"



namespace agora {
    namespace unity {
        int IAgoraUnityEngine::registeVideoRawDataObserver()
        {
            return CAgoraSDKObject::getCAgoraSDKInstance()->registeVideoRawDataObserver();
        }
            
        int IAgoraUnityEngine::unRegisteVideoRawDataObserver()
        {
            return CAgoraSDKObject::getCAgoraSDKInstance()->unRegisteVideoRawDataObserver();
        }
            
        int IAgoraUnityEngine::addVideoFrameObserver(agora::media::IVideoFrameObserver *_videoFrameObserver)
        {
            CAgoraSDKObject::getCAgoraSDKInstance()->addVideoFrameObserver(_videoFrameObserver);
            return 0;
        }
            
        int IAgoraUnityEngine::removeVideoFrameObserver(agora::media::IVideoFrameObserver *_videoFrameObserver)
        {
            CAgoraSDKObject::getCAgoraSDKInstance()->removeVideoFrameObserver(_videoFrameObserver);
            return 0;
        }

        bool IAgoraUnityEngine::checkWheatherInVideoObserverList(agora::media::IVideoFrameObserver *_videoFrameObserver)
        {
            return CAgoraSDKObject::getCAgoraSDKInstance()->checkWheatherInVideoObserverList(_videoFrameObserver);
        }

        int IAgoraUnityEngine::registeAudioRawDataObserver()
        {
            return CAgoraSDKObject::getCAgoraSDKInstance()->registeAudioRawDataObserver();
        }

        int IAgoraUnityEngine::unRegisteAudioRawDataObserver()
        {
            return CAgoraSDKObject::getCAgoraSDKInstance()->unRegisteVideoRawDataObserver();
        }

        int IAgoraUnityEngine::addAudioFrameObserver(agora::media::IAudioFrameObserver *_audioFrameObserver)
        {
            CAgoraSDKObject::getCAgoraSDKInstance()->addAudioFrameObserver(_audioFrameObserver);
            return 0;
        }

        int IAgoraUnityEngine::removeAudioFrameObserver(agora::media::IAudioFrameObserver *_audioFrameObserver)
        {
            CAgoraSDKObject::getCAgoraSDKInstance()->removeAudioFrameObserver(_audioFrameObserver);
            return 0;
        }

        bool IAgoraUnityEngine::checkWheatherInAudioObserverList(agora::media::IAudioFrameObserver *_audioFrameObserver)
        {
            return CAgoraSDKObject::getCAgoraSDKInstance()->checkWheatherInAudioObserverList(_audioFrameObserver);
        }

        agora::rtc::IRtcEngine *IAgoraUnityEngine::getIRtcEngine()
        {
            return CAgoraSDKObject::getCAgoraSDKInstance()->getIRtcEngine();
        }

        static agora::unity::IAgoraUnityInterface *iAgoraUnityInterfaceInstance = NULL;

        extern "C" agora::unity::IAgoraUnityInterface *getInstance()
        {   
            if (iAgoraUnityInterfaceInstance)
            {
                iAgoraUnityInterfaceInstance = new IAgoraUnityEngine();
            }
            return iAgoraUnityInterfaceInstance;
        }

        extern "C" void releaseIAgoraUnityInterfaceInstance()
        {
            if (iAgoraUnityInterfaceInstance)
            {
                delete iAgoraUnityInterfaceInstance;
                iAgoraUnityInterfaceInstance = NULL;
            }
        }   
    }
}
