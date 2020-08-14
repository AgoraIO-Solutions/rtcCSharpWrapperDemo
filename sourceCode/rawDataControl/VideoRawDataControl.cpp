#include "VideoRawDataControl.h"

namespace agora {
    namespace unity {

    VideoRawDataControl *VideoRawDataControl::_videoRawDataControlInstace = NULL;

    VideoRawDataControl::VideoRawDataControl()
    {

    }

    VideoRawDataControl *VideoRawDataControl::getInstance()
    {
        if (_videoRawDataControlInstace == NULL)
        {
            _videoRawDataControlInstace = new VideoRawDataControl();
        }
        return _videoRawDataControlInstace;
    }
    
    void VideoRawDataControl::releaseInstance()
    {
        if (_videoRawDataControlInstace)
        {
            delete _videoRawDataControlInstace;
            _videoRawDataControlInstace = NULL;
        }
    }

    bool VideoRawDataControl::onCaptureVideoFrame(IVideoFrameObserver::VideoFrame& _videoFrame)
    {
        _videoFrameObserverListMutex.lock();
        if (_onCaptureVideoFrame != NULL)
        {
            _onCaptureVideoFrame(_videoFrame.type, _videoFrame.width, _videoFrame.height, _videoFrame.yStride,  _videoFrame.yBuffer, _videoFrame.rotation, _videoFrame.renderTimeMs);
        }
        std::list<IVideoFrameObserver*>::iterator _iterator;
        for (_iterator = _videoFrameObserverList.begin(); _iterator != _videoFrameObserverList.end(); _iterator++)
        {
            (*_iterator)->onCaptureVideoFrame(_videoFrame);
        }
        _videoFrameObserverListMutex.unlock();
        return true;
    }

    bool VideoRawDataControl::onRenderVideoFrame(unsigned int uid, IVideoFrameObserver::VideoFrame& _videoFrame)
    {
        _videoFrameObserverListMutex.lock();
        if (_onRenderVideoFrame != NULL)
        {
            _onRenderVideoFrame(uid, _videoFrame.type, _videoFrame.width, _videoFrame.height, _videoFrame.yStride, _videoFrame.yBuffer, _videoFrame.rotation, _videoFrame.renderTimeMs);
        }
        std::list<IVideoFrameObserver*>::iterator _iterator;
        for (_iterator = _videoFrameObserverList.begin(); _iterator != _videoFrameObserverList.end(); _iterator++)
        {
            (*_iterator)->onRenderVideoFrame(uid, _videoFrame);
        }
        _videoFrameObserverListMutex.unlock();
        return true;
    }

    bool VideoRawDataControl::isMultipleChannelFrameWanted()
    {
        return isMultiChannelWanted;
    }
    
    bool VideoRawDataControl::onRenderVideoFrameEx(const char *channelId, unsigned int uid, VideoFrame& videoFrame)
    {
        _videoFrameObserverListMutex.lock();
        std::list<IVideoFrameObserver*>::iterator _iterator;
        for (_iterator = _videoFrameObserverList.begin(); _iterator != _videoFrameObserverList.end(); _iterator++)
        {
            (*_iterator)->onRenderVideoFrameEx(channelId, uid, videoFrame);
        }
        _videoFrameObserverListMutex.unlock();
        return true;
    }


    IVideoFrameObserver::VIDEO_FRAME_TYPE VideoRawDataControl::getVideoFormatPreference() 
    { 
        return _videoFrameType; 
    }

    int VideoRawDataControl::setMirrorApplied(bool wheatherApply)
    {
        _mirrorApply = wheatherApply;
        return 0;
    }
    
    int VideoRawDataControl::setRotationApplied(bool wheatherApply)
    {
        _rotationApply = wheatherApply;
        return 0;
    }

    bool VideoRawDataControl::getRotationApplied() 
    { 
        return _rotationApply; 
    }
    bool VideoRawDataControl::getMirrorApplied() 
    { 
        return _mirrorApply; 
    }

    int VideoRawDataControl::addVideoFrameObserver(IVideoFrameObserver *_videoFrameObserver)
    {
        _videoFrameObserverListMutex.lock();
        _videoFrameObserverList.push_back(_videoFrameObserver);
        _videoFrameObserverListMutex.unlock();
        return 0;
    }

    int VideoRawDataControl::removeVideoFrameObserver(IVideoFrameObserver *_videoFrameObserver)
    {
        _videoFrameObserverListMutex.lock();
        std::list<IVideoFrameObserver*>::iterator it;
        for (it = _videoFrameObserverList.begin(); it != _videoFrameObserverList.end(); it++)
        {
            if ((*it) == _videoFrameObserver)
            {
                _videoFrameObserverList.erase(it);
                break;
            }
        }
        _videoFrameObserverListMutex.unlock();
        return 0;
    }

    VideoRawDataControl::~VideoRawDataControl()
    {
        clearData();
    }

    void VideoRawDataControl::clearData()
    {
        _videoFrameObserverListMutex.lock();
        _videoFrameObserverList.clear();
        _videoFrameObserverListMutex.unlock();
    }

    bool VideoRawDataControl::checkWheatherInVideoObserverList(IVideoFrameObserver *_videoFrameObserver)
    {
        _videoFrameObserverListMutex.lock();
        std::list<IVideoFrameObserver*>::iterator it;
        for (it = _videoFrameObserverList.begin(); it != _videoFrameObserverList.end(); it++)
        {
            if (*it == _videoFrameObserver)
            {
                _videoFrameObserverListMutex.unlock();
                return true;
            }
        }
        _videoFrameObserverListMutex.unlock();
        return false;
    }

    void VideoRawDataControl::initEventOnCaptureVideoFrame(FUNC_OnCaptureVideoFrame onCaptureVideoFrame)
    {
        _videoFrameObserverListMutex.lock();
        _onCaptureVideoFrame = onCaptureVideoFrame;
        _videoFrameObserverListMutex.unlock();
    }

    void VideoRawDataControl::initEventOnRenderVideoFrame(FUNC_OnRenderVideoFrame onRenderVideoFrame)
    {
        _videoFrameObserverListMutex.lock();
        _onRenderVideoFrame = onRenderVideoFrame;
        _videoFrameObserverListMutex.unlock();
    }

    bool VideoRawDataControl::isRegisted()
    {
        return isRegiste;
    }
    
    void VideoRawDataControl::setRegisted(bool isRegisted)
    {   
        isRegiste = isRegisted;
    }

    int VideoRawDataControl::setMultiChannelWanted(bool isMultiChannel)
    {
        isMultiChannelWanted = isMultiChannel;
        return 0;
    }

    bool VideoRawDataControl::getMultiChannelWanted()
    {
        return isMultiChannelWanted;
    }
    }
}
