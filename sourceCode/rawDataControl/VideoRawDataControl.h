#ifndef VIDEO_RAW_DATA_CONTROL
#define VIDEO_RAW_DATA_CONTROL
#include "../common_header.h"

namespace agora
{
    namespace unity
    {
        class VideoRawDataControl : public agora::media::IVideoFrameObserver
        {
        private: 
            VideoRawDataControl();
            static VideoRawDataControl *_videoRawDataControlInstace;
            std::list<IVideoFrameObserver*> _videoFrameObserverList;
            std::mutex _videoFrameObserverListMutex;
            FUNC_OnCaptureVideoFrame _onCaptureVideoFrame = NULL;
            FUNC_OnRenderVideoFrame _onRenderVideoFrame = NULL;
            bool isRegiste = false;
            IVideoFrameObserver::VIDEO_FRAME_TYPE _videoFrameType = IVideoFrameObserver::VIDEO_FRAME_TYPE::FRAME_TYPE_RGBA;
            bool _rotationApply = true;
            bool _mirrorApply = false;  
            bool isMultiChannelWanted = false;

        public:
            ~VideoRawDataControl();
            static VideoRawDataControl *getInstance();
            static void releaseInstance();
            virtual bool onCaptureVideoFrame(IVideoFrameObserver::VideoFrame& _videoFrame);
            virtual bool onRenderVideoFrame(unsigned int uid, IVideoFrameObserver::VideoFrame& _videoFrame);
            virtual bool isMultipleChannelFrameWanted() override;
            virtual bool onRenderVideoFrameEx(const char *channelId, unsigned int uid, VideoFrame& videoFrame) override;
            virtual IVideoFrameObserver::VIDEO_FRAME_TYPE getVideoFormatPreference();
            virtual bool getRotationApplied();
            virtual bool getMirrorApplied();
            virtual int setMirrorApplied(bool wheatherApply);
            virtual int setRotationApplied(bool wheatherApply);
            virtual int addVideoFrameObserver(IVideoFrameObserver *_videoFrameObserver);
            virtual int removeVideoFrameObserver(IVideoFrameObserver *_videoFrameObserver);
            virtual bool checkWheatherInVideoObserverList(IVideoFrameObserver *_videoFrameObserver);
            virtual void clearData();
            virtual void initEventOnCaptureVideoFrame(FUNC_OnCaptureVideoFrame onCaptureVideoFrame);
            virtual void initEventOnRenderVideoFrame(FUNC_OnRenderVideoFrame onRenderVideoFrame);
            virtual bool isRegisted();
            virtual void setRegisted(bool isRegisted);

            virtual int setMultiChannelWanted(bool isMultiChannel);
            virtual bool getMultiChannelWanted();
        };
    }
}
#endif