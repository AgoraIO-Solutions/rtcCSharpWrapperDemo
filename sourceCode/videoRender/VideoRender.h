#ifndef VIDEO_RENDER_WRAPPER
#define VIDEO_RENDER_WRAPPER
#include "VideoRenderFactory.h"
#include "RenderInterface.h"
#include "../common_header.h"
// #include "unity/IUnityGraphics.h"
// #include "unity/IUnityInterface.h"
#include "UserVideoFrameData.h"

namespace agora
{
    namespace unity
    {
        enum UNITY_RENDER_MODE
        {
            RENDER_RAWDATA = 100,
            REDNER_OPENGL_ES2 = 101,
            RENDER_UNITY_LOW_LEVEL_INTERFACE = 102,
        };

        class VideoRender
        {
        private:
            VideoRender();
            static VideoRender* videoRenderInstance;
            RenderInterface *_videoRender = NULL;
            std::map<unsigned int, UserVideoFrameData *> _cachedUserMap;
            std::map<std::string, std::map<unsigned int, UserVideoFrameData *> *> _cacheMultiChannelUser;
            std::mutex _mMapMutex;
            VideoRenderFactory _videoRenderFactory;
            UNITY_RENDER_MODE _renderMode = (UNITY_RENDER_MODE)100;

        public:
            static VideoRender* getInstance();
            static void releaseInstance();
            ~VideoRender();
            virtual void addUserVideoInfo(unsigned int _userId, unsigned int _textureId);
            virtual void removeUserVideoInfo(unsigned int _userId);
            virtual void clearData();
            virtual void addVideoFrame(unsigned int _userId, agora::media::IVideoFrameObserver::VideoFrame& videoFrame);
            virtual void startRenderVideo(int _userId);
            virtual UserVideoFrameData* getCachedUserVideoFrame(unsigned int uid);
            virtual int updateVideoRawData(void *data, unsigned int _userId);
            virtual int updateTexture(unsigned int _textureId, unsigned int _userId);
            virtual int setRenderMode(UNITY_RENDER_MODE renderMode);
            virtual unsigned int createTexture();
            virtual void deleteTexture(int textureId);
            virtual void addUserVideoInfo(char *channelId, unsigned int _userId, unsigned int _textureId);
            virtual void removeUserVideoInfo(char *channelId, unsigned int _userId);
            virtual void addVideoFrame(char *_channelId, unsigned int _userId, agora::media::IVideoFrameObserver::VideoFrame& videoFrame);
            virtual UserVideoFrameData* getCachedUserVideoFrame(char *channelId, unsigned int uid);
            virtual int updateVideoRawData(void *data, char *channelId, unsigned int uid);
        };      
    }
}
#endif