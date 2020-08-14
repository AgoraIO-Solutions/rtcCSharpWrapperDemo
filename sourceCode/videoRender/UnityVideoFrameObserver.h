#ifndef UNITY_VIDEO_OBSERVER
#define UNITY_VIDEO_OBSERVER
#include "../common_header.h"
#include "UserVideoFrameData.h"
#include "VideoRender.h"

namespace agora
{
  namespace unity
  {
    class UnityVideoFrameObserver : public agora::media::IVideoFrameObserver
    {
    public:
      UnityVideoFrameObserver();
      ~UnityVideoFrameObserver();

      virtual bool onCaptureVideoFrame(IVideoFrameObserver::VideoFrame &videoFrame) override;
      virtual bool onRenderVideoFrame(unsigned int uid, IVideoFrameObserver::VideoFrame &videoFrame) override;
      virtual bool onRenderVideoFrameEx(const char *channelId, unsigned int uid, VideoFrame& videoFrame) override;
      int setVideoRender(VideoRender *_videoRender);
      int removeVideoRender();

    private:
      VideoRender *_videoRender;
    };
  }
}
#endif