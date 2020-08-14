#include "UnityVideoFrameObserver.h"

namespace agora {
    namespace unity {
        UnityVideoFrameObserver::UnityVideoFrameObserver()
        {

        }

        UnityVideoFrameObserver::~UnityVideoFrameObserver()
        {
            removeVideoRender();
        }

        bool UnityVideoFrameObserver::onCaptureVideoFrame(IVideoFrameObserver::VideoFrame &videoFrame)
        {
            if (videoFrame.type != agora::media::IVideoFrameObserver::FRAME_TYPE_RGBA)
            {
                return false;
            }

            if (_videoRender)
            {
                _videoRender->addVideoFrame(0, videoFrame);
            }
            return true;
        }

        bool UnityVideoFrameObserver::onRenderVideoFrame(unsigned int uid, IVideoFrameObserver::VideoFrame &videoFrame)
        {
            if (videoFrame.type != agora::media::IVideoFrameObserver::FRAME_TYPE_RGBA)
            {
                return false;
            }

            if (_videoRender)
            {
                _videoRender->addVideoFrame(uid, videoFrame);
            }
            return true;
        }

        bool UnityVideoFrameObserver::onRenderVideoFrameEx(const char *channelId, unsigned int uid, VideoFrame& videoFrame)
        {
            if (videoFrame.type != agora::media::IVideoFrameObserver::FRAME_TYPE_RGBA)
            {
                return false;
            }

            if (_videoRender)
            {
                _videoRender->addVideoFrame((char *)channelId, uid, videoFrame);
            }
            return true;
        }

        int UnityVideoFrameObserver::setVideoRender(VideoRender *videoRender)
        {
            if (videoRender)
            {
                _videoRender = videoRender;
                return 0;
            }
            return NOT_INIT_ENGINE;
        }

        int UnityVideoFrameObserver::removeVideoRender()
        {
            _videoRender = NULL;
            return 0;
        }
    }
}
