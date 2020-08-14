#ifndef I_AGORA_UNITY_INTERFACE_PLUGIN
#define I_AGORA_UNITY_INTERFACE_PLUGIN
#define WRAPPER_WINDOWS
#if defined WRAPPER_ANDROID
#include "../../../include/AgoraBase.h"
#include "../../../include/IAgoraMediaEngine.h"
#include "../../../include/IAgoraRtcEngine.h"
#include "../../../include/IAgoraService.h"

#else
#if defined WRAPPER_IOS
#include "../include/AgoraBase.h"
#include "../include/IAgoraMediaEngine.h"
#include "../include/IAgoraRtcEngine.h"
#include "../include/IAgoraService.h"
#else 
#if defined WRAPPER_MAC
#include "../../include/AgoraBase.h"
#include "../../include/IAgoraMediaEngine.h"
#include "../../include/IAgoraRtcEngine.h"
#include "../../include/IAgoraService.h"
#else
#if defined WRAPPER_WINDOWS
#include "../../native_sdk/include/AgoraBase.h"
#include "../../native_sdk/include/IAgoraMediaEngine.h"
#include "../../native_sdk/include/IAgoraRtcEngine.h"
#include "../../native_sdk/include/IAgoraService.h"
#include "../../native_sdk/include/IAgoraRtcEngine2.h"
#else
#endif
#endif
#endif
#endif

namespace agora
{
    namespace unity
    {
        class IAgoraUnityInterface
        {
            public:
                virtual int registeVideoRawDataObserver() = 0;
                
                virtual int unRegisteVideoRawDataObserver() = 0;
            
                virtual int addVideoFrameObserver(agora::media::IVideoFrameObserver *_videoFrameObserver) = 0;
            
                virtual int removeVideoFrameObserver(agora::media::IVideoFrameObserver *_videoFrameObserver) = 0;
            
                virtual bool checkWheatherInVideoObserverList(agora::media::IVideoFrameObserver *_videoFrameObserver) = 0;
            
                virtual int registeAudioRawDataObserver() = 0;
            
                virtual int unRegisteAudioRawDataObserver() = 0;
            
                virtual int addAudioFrameObserver(agora::media::IAudioFrameObserver *_audioFrameObserver) = 0;
            
                virtual int removeAudioFrameObserver(agora::media::IAudioFrameObserver *_audioFrameObserver) = 0;
            
                virtual bool checkWheatherInAudioObserverList(agora::media::IAudioFrameObserver *_audioFrameObserver) = 0;

                virtual agora::rtc::IRtcEngine *getIRtcEngine() = 0;
        };
        
        extern "C" agora::unity::IAgoraUnityInterface *getInstance();

        extern "C" void releaseIAgoraUnityInterfaceInstance();
    }
}

#endif
