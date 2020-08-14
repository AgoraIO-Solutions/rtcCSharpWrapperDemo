#ifndef I_AGORA_UNITY_ENGINE
#define I_AGORA_UNITY_ENGINE

#include "IAgoraUnityInterface.h"
#include "../AgoraSDKObject.h"

namespace agora
{
    namespace unity
    {
        class IAgoraUnityEngine : public IAgoraUnityInterface
        {
            public:
                virtual int registeVideoRawDataObserver();
                
                virtual int unRegisteVideoRawDataObserver();
            
                virtual int addVideoFrameObserver(agora::media::IVideoFrameObserver *_videoFrameObserver);
            
                virtual int removeVideoFrameObserver(agora::media::IVideoFrameObserver *_videoFrameObserver);
            
                virtual bool checkWheatherInVideoObserverList(agora::media::IVideoFrameObserver *_videoFrameObserver);
            
                virtual int registeAudioRawDataObserver();
            
                virtual int unRegisteAudioRawDataObserver();
            
                virtual int addAudioFrameObserver(agora::media::IAudioFrameObserver *_audioFrameObserver);
            
                virtual int removeAudioFrameObserver(agora::media::IAudioFrameObserver *_audioFrameObserver);
            
                virtual bool checkWheatherInAudioObserverList(agora::media::IAudioFrameObserver *_audioFrameObserver);

                virtual agora::rtc::IRtcEngine *getIRtcEngine();

        };
   }
}
#endif