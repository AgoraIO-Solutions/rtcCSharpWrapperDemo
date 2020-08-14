#include "VideoRender.h"

namespace agora {
    namespace unity {
        VideoRender *VideoRender::videoRenderInstance = NULL;
        VideoRender::VideoRender()
        {
            
        }

        VideoRender *VideoRender::getInstance()
        {
            if (videoRenderInstance == NULL)
            {
                 videoRenderInstance = new VideoRender();
            }  
            return videoRenderInstance;
        }

        void VideoRender::releaseInstance()
        {
            if (videoRenderInstance)
            {
                delete videoRenderInstance;
                videoRenderInstance = NULL;
            }
        }

        VideoRender::~VideoRender()
        {
            clearData();
        }

        void VideoRender::addUserVideoInfo(unsigned int _userId, unsigned int _textureId)
        {
            _mMapMutex.lock();
            std::map<unsigned int, UserVideoFrameData *>::iterator it;
            it = _cachedUserMap.find(_userId);
            if (it == _cachedUserMap.end())
            {
                UserVideoFrameData *cachedUser = new UserVideoFrameData(_userId, _textureId);
                _cachedUserMap[_userId] = cachedUser;
            }
            else
            {
                UserVideoFrameData *cachedUser = it->second;
                cachedUser->textureId = _textureId;
                cachedUser->uid = _userId;
            }
            _mMapMutex.unlock();
        }

        void VideoRender::removeUserVideoInfo(unsigned int _userId)
        {
            _mMapMutex.lock();
            std::map<unsigned int, UserVideoFrameData *>::iterator _iterator;
            _iterator = _cachedUserMap.find(_userId);
            if (_iterator == _cachedUserMap.end())
            {
            }
            else
            {
                UserVideoFrameData* _cachedUser = _iterator->second;
                if (_cachedUser)
                {
                    delete _cachedUser;
                    _cachedUser = NULL;
                }   
                _cachedUserMap.erase(_iterator);
            }
            _mMapMutex.unlock();
        }

        void VideoRender::addUserVideoInfo(char *channelId, unsigned int _userId, unsigned int _textureId)
        {
            _mMapMutex.lock();
            std::map<std::string, std::map<unsigned int, UserVideoFrameData *> *>::iterator it; 
            it = _cacheMultiChannelUser.find(channelId);
            if (it == _cacheMultiChannelUser.end())
            {
                std::map<unsigned int, UserVideoFrameData *>* _cacheUserVideoFrameMap = new std::map<unsigned int, UserVideoFrameData *>();
                UserVideoFrameData *cachedUser = new UserVideoFrameData(_userId, _textureId);
                (*_cacheUserVideoFrameMap)[_userId] = cachedUser;
                _cacheMultiChannelUser[channelId] = _cacheUserVideoFrameMap;
            }
            else
            {
                std::map<unsigned int, UserVideoFrameData *> *_cacheUserVideoFrameMap = it->second;
                if (_cacheUserVideoFrameMap)
                {
                    std::map<unsigned int, UserVideoFrameData *>::iterator iter = (*_cacheUserVideoFrameMap).find(_userId);
                    if (iter == (*_cacheUserVideoFrameMap).end())
                    {
                        UserVideoFrameData *cachedUser = new UserVideoFrameData(_userId, _textureId);
                        (*_cacheUserVideoFrameMap)[_userId] = cachedUser;
                    }
                    else
                    {
                        UserVideoFrameData *cachedUser = iter->second;
                        if(cachedUser)
                        {
                            cachedUser->textureId = _textureId;
                            cachedUser->uid = _userId;
                        }
                    }
                }
            }
            _mMapMutex.unlock();
        }

        void VideoRender::removeUserVideoInfo(char *channelId, unsigned int _userId)
        {
            _mMapMutex.lock();
            std::map<std::string, std::map<unsigned int, UserVideoFrameData *> *>::iterator it;
            it = _cacheMultiChannelUser.find(channelId);
            if (it == _cacheMultiChannelUser.end())
            {

            }
            else
            {
                std::map<unsigned int, UserVideoFrameData *> *_cachedUserVideoFrameMap = it->second;
                if (_cachedUserVideoFrameMap)
                {
                    std::map<unsigned int, UserVideoFrameData *>::iterator _iterator = (*_cachedUserVideoFrameMap).find(_userId);
                    if (_iterator == (*_cachedUserVideoFrameMap).end())
                    {

                    }
                    else
                    {
                        UserVideoFrameData *cachedUser = _iterator->second;
                        if (cachedUser)
                        {
                            delete cachedUser;
                            cachedUser = NULL;
                        }
                        (*_cachedUserVideoFrameMap).erase(_iterator);
                    }
                }
            }
            _mMapMutex.unlock();
        }

        void VideoRender::clearData()
        {
            _mMapMutex.lock();
            std::map<unsigned int, UserVideoFrameData *>::iterator _iterator;
            for(_iterator = _cachedUserMap.begin(); _iterator != _cachedUserMap.end();)
            {
                UserVideoFrameData *cachedUser = _iterator->second; 
                if(cachedUser)
                {
                    delete cachedUser;
                    cachedUser = NULL;
                }
                _cachedUserMap.erase(_iterator++);
            }

            std::map<std::string, std::map<unsigned int, UserVideoFrameData *> *>::iterator _multiChannleIterator;
            for (_multiChannleIterator = _cacheMultiChannelUser.begin(); _multiChannleIterator != _cacheMultiChannelUser.end();)
            {
                std::map<unsigned int, UserVideoFrameData *> *cacheMultiChannelUserVideoFrameData = _multiChannleIterator->second;
                if (cacheMultiChannelUserVideoFrameData)
                {
                    std::map<unsigned int, UserVideoFrameData *>::iterator cacheMultiChannelUserVideoFrameDataIterator;
                    for (cacheMultiChannelUserVideoFrameDataIterator = (*cacheMultiChannelUserVideoFrameData).begin(); cacheMultiChannelUserVideoFrameDataIterator != (*cacheMultiChannelUserVideoFrameData).end();)
                    {
                        UserVideoFrameData *cachedUser = cacheMultiChannelUserVideoFrameDataIterator->second;
                        if (cachedUser)
                        {
                            delete cachedUser;
                            cachedUser = NULL;
                        }
                        (*cacheMultiChannelUserVideoFrameData).erase(cacheMultiChannelUserVideoFrameDataIterator++);
                    }
                    (*cacheMultiChannelUserVideoFrameData).clear();
                    delete cacheMultiChannelUserVideoFrameData;
                    cacheMultiChannelUserVideoFrameData = NULL;
                    _cacheMultiChannelUser.erase( _multiChannleIterator++);
                }
            }
            _cacheMultiChannelUser.clear();

            if (_videoRender)
            {
                delete _videoRender;
                _videoRender = NULL;
            }
            _mMapMutex.unlock();
        }

        void VideoRender::addVideoFrame(unsigned int uid, agora::media::IVideoFrameObserver::VideoFrame& videoFrame)
        {
            _mMapMutex.lock();
            std::map<unsigned int, UserVideoFrameData *>::iterator _iterator;
            _iterator = _cachedUserMap.find(uid);
            if (_iterator != _cachedUserMap.end())
            {
                UserVideoFrameData* cachedUser = _iterator->second;
                if(cachedUser)
                {
                    cachedUser->setVideoFrame(videoFrame);
                }
            }
            _mMapMutex.unlock();
        }

        void VideoRender::addVideoFrame(char *_channelId, unsigned int _userId, agora::media::IVideoFrameObserver::VideoFrame& videoFrame)
        {
            _mMapMutex.lock();
            std::map<std::string, std::map<unsigned int, UserVideoFrameData *> *>::iterator it = _cacheMultiChannelUser.find(_channelId);

            if (it != _cacheMultiChannelUser.end())
            {
                std::map<unsigned int, UserVideoFrameData *> *_cacheUserVideoFrameMap = it->second;
                std::map<unsigned int, UserVideoFrameData *>::iterator _cacheUserVideoFrameMapIterator = (*_cacheUserVideoFrameMap).find(_userId);
                if (_cacheUserVideoFrameMapIterator != (*_cacheUserVideoFrameMap).end())
                {
                    UserVideoFrameData* cachedUser = _cacheUserVideoFrameMapIterator->second;
                    if(cachedUser)
                    {
                        cachedUser->setVideoFrame(videoFrame);
                    }
                }
                else
                {

                }
            }
            _mMapMutex.unlock();           
        }

        void VideoRender::startRenderVideo(int userId)
        {
             _mMapMutex.lock();
            if (_videoRender)
            { 
                UserVideoFrameData* _cachedUserVideoFrame = getCachedUserVideoFrame(userId);
                if (_cachedUserVideoFrame && _cachedUserVideoFrame->_videoDataPtr)
                {
                    _videoRender->startRenderVideo(_cachedUserVideoFrame);  
                    _cachedUserVideoFrame->resetVideoFrame();  
                } else {
                        
                }
            }
            else
            {

            } 
            _mMapMutex.unlock(); 
        }

        UserVideoFrameData* VideoRender::getCachedUserVideoFrame(unsigned int uid)
        {
            std::map<unsigned int, UserVideoFrameData *>::iterator _iterator;
            _iterator = _cachedUserMap.find(uid);
            UserVideoFrameData* _cachedUserVideoFrame = NULL;
            if (_iterator != _cachedUserMap.end())
            {
                _cachedUserVideoFrame = _iterator->second;
            }
            else
            {
                _cachedUserVideoFrame = NULL;
            } 
            return _cachedUserVideoFrame;
        }

        UserVideoFrameData* VideoRender::getCachedUserVideoFrame(char *channelId, unsigned int uid)
        {
            UserVideoFrameData* _cachedUserVideoFrame = NULL;
            std::map<std::string, std::map<unsigned int, UserVideoFrameData *> *>::iterator it = _cacheMultiChannelUser.find(channelId);
            if (it != _cacheMultiChannelUser.end())
            {
                std::map<unsigned int, UserVideoFrameData *> *_cacheUserVideoFrameMap = it->second;
                std::map<unsigned int, UserVideoFrameData *>::iterator cachedMultiChannelUserVideoFrameIterator = (*_cacheUserVideoFrameMap).find(uid);
                if (cachedMultiChannelUserVideoFrameIterator != (*_cacheUserVideoFrameMap).end())
                {
                    _cachedUserVideoFrame = cachedMultiChannelUserVideoFrameIterator->second;
                }
                else
                {
                    _cachedUserVideoFrame = NULL;
                }
            }
            return _cachedUserVideoFrame;
        }

        int VideoRender::setRenderMode(UNITY_RENDER_MODE renderMode)
        {
            _renderMode = renderMode;
            return 0;
        }

        int VideoRender::updateVideoRawData(void *data, unsigned int _userId)
        {
            _mMapMutex.lock();
            UserVideoFrameData *_cachedUserVideoFrame = getCachedUserVideoFrame(_userId);
            if (_cachedUserVideoFrame && _cachedUserVideoFrame->_videoDataPtr && data)
            {
                memcpy(data, _cachedUserVideoFrame->_videoDataPtr, _cachedUserVideoFrame->_videoDataWidth * _cachedUserVideoFrame->_videoDataHeight * 4);
                int widthAndHeight = (_cachedUserVideoFrame->_videoDataWidth << 16 | _cachedUserVideoFrame->_videoDataHeight);
                _cachedUserVideoFrame->resetVideoFrame();
                _mMapMutex.unlock();
                return widthAndHeight;    
            }
            _mMapMutex.unlock();
            return -1;
        }

        int VideoRender::updateVideoRawData(void *data, char *channelId, unsigned int uid)
        {   
            _mMapMutex.lock();
            UserVideoFrameData *_cachedUserVideoFrame = getCachedUserVideoFrame(channelId, uid);
            if (_cachedUserVideoFrame && _cachedUserVideoFrame->_videoDataPtr && data)
            {
                memcpy(data, _cachedUserVideoFrame->_videoDataPtr, _cachedUserVideoFrame->_videoDataWidth * _cachedUserVideoFrame->_videoDataHeight * 4);
                int widthAndHeight = (_cachedUserVideoFrame->_videoDataWidth << 16 | _cachedUserVideoFrame->_videoDataHeight);
                _cachedUserVideoFrame->resetVideoFrame();
                _mMapMutex.unlock();
                return widthAndHeight;    
            }
            _mMapMutex.unlock();
            return -1;
        }
                    
        int VideoRender::updateTexture(unsigned int _textureId, unsigned int _userId)
        {
            _mMapMutex.lock();
            if (_videoRender)
            {
                UserVideoFrameData *_cachedUserVideoFrame = getCachedUserVideoFrame(_userId);
                if (_cachedUserVideoFrame && _cachedUserVideoFrame->_videoDataPtr)
                {
                    _cachedUserVideoFrame->setTextureId(_textureId);
                    _videoRender->startRenderVideo(_cachedUserVideoFrame);
                    int widthAndHeight = (_cachedUserVideoFrame->_videoDataWidth << 16 | _cachedUserVideoFrame->_videoDataHeight);
                    _cachedUserVideoFrame->resetVideoFrame();
                    _mMapMutex.unlock();
                    return widthAndHeight;
                } else {

                }
            }
            else
            {

            }
            _mMapMutex.unlock();
            return -1;
        }
        
        unsigned int VideoRender::createTexture()
        {
            _mMapMutex.lock();
            if (_videoRender)
            {
                 unsigned int rn = _videoRender->createTexture();
                 _mMapMutex.unlock();
                return rn;
            }
            _mMapMutex.unlock();
            return -1;
        }

        void VideoRender::deleteTexture(int textureId)
        {
            _mMapMutex.lock();
            if (_videoRender)
            {
                _videoRender->deleteTexture(textureId);
            }
            _mMapMutex.unlock();
        }
    }
}
