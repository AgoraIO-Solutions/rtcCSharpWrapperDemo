#include "UserVideoFrameData.h"

namespace agora {
    namespace unity {
        UserVideoFrameData::UserVideoFrameData(unsigned int userId, unsigned int tId)
        {
            uid = userId;
            textureId = tId;
            _videoDataHeight = -1;
            _videoDataWidth = -1;
        }

        UserVideoFrameData::UserVideoFrameData(unsigned int userId)
        {
            uid = userId;
            textureId = -1;
            _videoDataHeight = -1;
            _videoDataWidth = -1;
        }

        UserVideoFrameData::~UserVideoFrameData()
        {
            if (_videoDataPtr)
            {
                free(_videoDataPtr);
                _videoDataPtr = NULL;
            }
        }

        void UserVideoFrameData::setVideoFrame(agora::media::IVideoFrameObserver::VideoFrame& videoframe)
        {
            if (_videoDataHeight <= 0 || _videoDataWidth <= 0)
            {
                _videoDataPtr = malloc(videoframe.width * videoframe.height * 4);
            }
            //for resize video frame
            else if (_videoDataHeight != videoframe.height || _videoDataWidth != videoframe.width)
            {
                if (_videoDataPtr)
                {
                    free(_videoDataPtr);
                    _videoDataPtr = NULL;
                    _videoDataPtr = malloc(videoframe.width * videoframe.height * 4);
                }
            }
            _videoDataHeight = videoframe.height;
            _videoDataWidth = videoframe.width;
            if (_videoDataPtr && videoframe.yBuffer)
            {
                memcpy(_videoDataPtr, videoframe.yBuffer, videoframe.width * videoframe.height * 4);
            }
            else
            {
                if (!_videoDataPtr)
                {

                }
                else
                {

                }
            }
            
        }

        void UserVideoFrameData::resetVideoFrame()
        {

        }

        void* UserVideoFrameData::getVideoFrame()
        {
            if(_videoDataPtr)
            {
                return _videoDataPtr;
            }
            return NULL;
        }

        void UserVideoFrameData::setUid(unsigned int u)
        {
            uid = u;
        }

        unsigned int UserVideoFrameData::getUid()
        {
           return uid;
        }

        void UserVideoFrameData::setTextureId(unsigned int tId)
        {
            textureId = tId;
        }

        unsigned int UserVideoFrameData::getTextureId()
        {
            return textureId;
        }
    }
} // agora