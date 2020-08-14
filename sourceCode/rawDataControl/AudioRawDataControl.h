#ifndef AUDIO_RAW_DATA_CONTROL_WRAPPER
#define AUDIO_RAW_DATA_CONTROL_WRAPPER
#include "../common_header.h"

namespace agora
{
    namespace unity
    {
        class AudioRawDataControl : public agora::media::IAudioFrameObserver
        {
        private:
            AudioRawDataControl();
            static AudioRawDataControl *_audioRawDataControlInstace;
            std::list<IAudioFrameObserver*> _audioFrameObserverList;
            std::mutex _audioFrameObserverListMutex;
            FUNC_OnRecordAudioFrame _onRecordAudioFrame = NULL;
            FUNC_OnPlaybackAudioFrame _onPlaybackAudioFrame = NULL;
            FUNC_OnMixedAudioFrame _onMixedAudioFrame = NULL;
            FUNC_OnPlaybackAudioFrameBeforeMixing _onPlaybackAudioFrameBeforeMixing = NULL;
            FUNC_OnPullAudioFrame _onPullAudioFrame = NULL;

        public:
            ~AudioRawDataControl();
            static AudioRawDataControl *getInstance();
            static void releaseInstance();
            virtual int addAudioFrameObserver(IAudioFrameObserver *_audioFrameObserver);
            virtual int removeAudioFrameObserver(IAudioFrameObserver *_audioFrameObserver);
            virtual bool checkWheatherInAudioObserverList(IAudioFrameObserver *_audioFrameObserver);
            virtual void clearData();
            virtual int pullAudioFrame(IAudioFrameObserver::AudioFrame audioFrame);
            virtual bool onRecordAudioFrame(IAudioFrameObserver::AudioFrame& audioFrame);
            virtual bool onPlaybackAudioFrame(IAudioFrameObserver::AudioFrame& audioFrame);
            virtual bool onMixedAudioFrame(IAudioFrameObserver::AudioFrame& audioFrame);
            virtual bool onPlaybackAudioFrameBeforeMixing(unsigned int uid, IAudioFrameObserver::AudioFrame& audioFrame);
            virtual void initEventonRecordAudioFrame(FUNC_OnRecordAudioFrame onRecordAudioFrame);
            virtual void initEventonPlaybackAudioFrame(FUNC_OnPlaybackAudioFrame onPlaybackAudioFrame);
            virtual void initEventonMixedAudioFrame(FUNC_OnMixedAudioFrame onMixedAudioFrame);
            virtual void initEventonPlaybackAudioFrameBeforeMixing(FUNC_OnPlaybackAudioFrameBeforeMixing onPlaybackAudioFrameBeforeMixing);
            virtual void initEventonPullAudioFrame(FUNC_OnPullAudioFrame onPullAudioFrame);

        };
    }
}
#endif
