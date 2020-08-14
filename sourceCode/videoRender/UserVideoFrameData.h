#ifndef USER_VIDEO_FRAME_DATA_WRAPPER
#define USER_VIDEO_FRAME_DATA_WRAPPER
#include "../common_header.h"

namespace agora {
    namespace unity {
        class UserVideoFrameData {
        public:
            void *_videoDataPtr = NULL;
            int _videoDataWidth;
            int _videoDataHeight;
            unsigned int textureId;
            unsigned int uid;
            std::string channelId;
            int _beforeVideoDataWidth;
            int _beforeVideoDataHeight;


        public:
            UserVideoFrameData(unsigned int uid, unsigned int tId);
            UserVideoFrameData(unsigned int uid);
            ~UserVideoFrameData();
            virtual void setVideoFrame(agora::media::IVideoFrameObserver::VideoFrame& videoframe);
            virtual void* getVideoFrame();
            virtual void setUid(unsigned int uid);
            virtual void setTextureId(unsigned int tId);
            virtual unsigned int getUid();
            virtual unsigned int getTextureId();
            virtual void resetVideoFrame();
        };      
    }
}
#endif