#include "AgoraSDKObject.h"

namespace agora {
    namespace unity {              
        CAgoraSDKObject *CAgoraSDKObject::cAgoraSDKObjectInstance = NULL;
        CAgoraSDKObject::~CAgoraSDKObject()
        {    
            irtcEngine = NULL;
            if (cWrapperRtcEngineEventHandler)
            {
                delete cWrapperRtcEngineEventHandler;
                cWrapperRtcEngineEventHandler = NULL;
            }
           
            if (_unityVideoFrameObserver)
            {
                delete _unityVideoFrameObserver;
                _unityVideoFrameObserver = NULL;
            }

            if (packetObserver)
            {
                delete packetObserver;
                packetObserver = NULL;
            }

            if (metaDataObserver)
            {
                delete metaDataObserver;
                metaDataObserver = NULL;
            }
            
            AgoraAudioRecordingDeviceManager::releaseInstance();
            AgoraAudioPlaybackDeviceManager::releaseInstance();
            AgoraVideoDeviceManager::releaseInstance();
            AudioRawDataControl::releaseInstance();
            VideoRawDataControl::releaseInstance();
            VideoRender::releaseInstance();
        }

        CAgoraSDKObject::CAgoraSDKObject()
        {
            cWrapperRtcEngineEventHandler = new CWrapperRtcEngineEventHandler();
            packetObserver = new PacketObserver();
            metaDataObserver = new MetaDataObserver();
            audioRawDataControl = AudioRawDataControl::getInstance();
            videoRawDataControl = VideoRawDataControl::getInstance();
            _videoRender = VideoRender::getInstance();
            audioFrame.buffer = NULL;
        }

        CAgoraSDKObject *CAgoraSDKObject::getCAgoraSDKObject()
        {
            return cAgoraSDKObjectInstance;
        }

        CAgoraSDKObject *CAgoraSDKObject::getCAgoraSDKInstance()
        {
            if (cAgoraSDKObjectInstance == NULL)
                cAgoraSDKObjectInstance = new CAgoraSDKObject();

            return cAgoraSDKObjectInstance;
        }

        IRtcEngine *CAgoraSDKObject::getIRtcEngine()
        {
            if (irtcEngine)
                return irtcEngine;

            return NULL;
        }

        AudioRawDataControl *CAgoraSDKObject::getAudioRawDataControl()
        {
            if (audioRawDataControl)
                return audioRawDataControl;

            return NULL;
        }
        
        VideoRawDataControl *CAgoraSDKObject::getVideoRawDataControl()
        {
            if (videoRawDataControl)
                return videoRawDataControl;

            return NULL;
        }

        void CAgoraSDKObject::releaseCAgoraSDKInstance()
        {
            if (cAgoraSDKObjectInstance)
            {
                delete cAgoraSDKObjectInstance;
                cAgoraSDKObjectInstance = NULL;
            }
        }

        bool CAgoraSDKObject::createEngine(const char *appId)
        {
            RtcEngineContext engineContext;
            engineContext.appId = appId;
            engineContext.eventHandler = getCWrapperRtcEngineEventHandler();
            #ifdef WRAPPER_IOS
            @autoreleasepool {
            Class AgoraRtcCryptoLoader = NSClassFromString(@"AgoraRtcCryptoLoader");
                if (AgoraRtcCryptoLoader != nil) {
                    id rtcCrypto = [[AgoraRtcCryptoLoader alloc] init];
                }
            }
            #endif
            irtcEngine = createAgoraRtcEngine();
            if (irtcEngine)
            {
                int init = irtcEngine->initialize(engineContext);
                setAppType();
                return init==0;
            }
            return false;
        }

        bool CAgoraSDKObject::createEngine2(const char *appId, unsigned int areaCode)
        {
            RtcEngineContext engineContext;
            if (areaCode != 0) {
                engineContext.areaCode = areaCode;
            }
            engineContext.appId = appId;
            engineContext.eventHandler = getCWrapperRtcEngineEventHandler();
            #ifdef WRAPPER_IOS
            @autoreleasepool {
            Class AgoraRtcCryptoLoader = NSClassFromString(@"AgoraRtcCryptoLoader");
                if (AgoraRtcCryptoLoader != nil) {
                    id rtcCrypto = [[AgoraRtcCryptoLoader alloc] init];
                }
            }
            #endif
            irtcEngine = createAgoraRtcEngine();
            if (irtcEngine)
            {
                bool init = irtcEngine->initialize(engineContext);
                setAppType();
                return init;
            }
            return false;       
        }

        void CAgoraSDKObject::setAppType()
        {
            IRtcEngine3 *irtcEngine3 = reinterpret_cast<IRtcEngine3 *>(irtcEngine);
            int a = irtcEngine3->setAppType(APP_TYPE_UNITY);
        }

        CWrapperRtcEngineEventHandler *CAgoraSDKObject::getCWrapperRtcEngineEventHandler()
        {
            return cWrapperRtcEngineEventHandler;
        }

        int CAgoraSDKObject::joinChannel(const char *channelKey, const char *channelName, const char *info, uid_t uid)
        {
            if (irtcEngine)  
                return irtcEngine->joinChannel(channelKey, channelName, info, uid);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::leaveChannel()
        {
            if (irtcEngine)
                return irtcEngine->leaveChannel();

            return NOT_INIT_ENGINE;
        }

        void CAgoraSDKObject::deleteEngine()
        {   
            if (irtcEngine)
            {
                releaseAllChannel();
                irtcEngine->release(true);
                irtcEngine = NULL;
            }
        }

        const char *CAgoraSDKObject::getSdkVersion()
        {
            if (irtcEngine)
                return irtcEngine->getVersion(0);

            return NOT_INIT_ENGINE_CHAR;
        }

        int CAgoraSDKObject::renewToken(const char *token)
        {
            if (irtcEngine)
                return irtcEngine->renewToken(token);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::enableLastmileTest()
        {
            if (irtcEngine)
                return irtcEngine->enableLastmileTest();
            
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::disableLastmileTest()
        {
            if (irtcEngine)
                return irtcEngine->disableLastmileTest();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::enableVideo()
        {   if (irtcEngine)
                return irtcEngine->enableVideo();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::disableVideo()
        {
            if (irtcEngine)
                return irtcEngine->disableVideo();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::enableLocalVideo(bool enabled)
        {   
            if (irtcEngine)
                return irtcEngine->enableLocalVideo(enabled);

            return NOT_INIT_ENGINE;    
        }

        int CAgoraSDKObject::setupLocalVideo(int hwnd, int renderMode, uid_t uid, void *priv)
        {
            if (irtcEngine)
            {
                VideoCanvas videoCanvas;
                videoCanvas.view = reinterpret_cast<void *>(hwnd);
                videoCanvas.renderMode = renderMode;
                videoCanvas.uid = uid;
                videoCanvas.priv = priv;
                return irtcEngine->setupLocalVideo(videoCanvas);
            }

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setupRemoteVideo(int hwnd, int renderMode, uid_t uid, void *priv)
        {
            if (irtcEngine)
            {
                VideoCanvas videoCanvas;
                videoCanvas.view = reinterpret_cast<void *>(hwnd);
                videoCanvas.renderMode = renderMode;
                videoCanvas.uid = uid;
                videoCanvas.priv = priv;
                return irtcEngine->setupRemoteVideo(videoCanvas);
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setLocalRenderMode(int renderMode)
        {
            if (irtcEngine)
                return irtcEngine->setLocalRenderMode((RENDER_MODE_TYPE)renderMode);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setRemoteRenderMode(uid_t userId, int renderMode)
        {
            if (irtcEngine)
                return irtcEngine->setRemoteRenderMode(userId, (RENDER_MODE_TYPE)renderMode);
            
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setLocalVideoMirrorMode(int mirrorMode)
        {
            if (irtcEngine)
                return irtcEngine->setLocalVideoMirrorMode((VIDEO_MIRROR_MODE_TYPE)mirrorMode);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::startPreview()
        {   
            if (irtcEngine)
                return irtcEngine->startPreview();

            return NOT_INIT_ENGINE;    
        }

        int CAgoraSDKObject::stopPreview()
        {
            if (irtcEngine)
                return irtcEngine->stopPreview();
            
            return NOT_INIT_ENGINE;  
        }

        int CAgoraSDKObject::enableAudio()
        {
            if (irtcEngine)
                return irtcEngine->enableAudio();

            return NOT_INIT_ENGINE; 
        }

        int CAgoraSDKObject::enableLocalAudio(bool enabled)
        {   if (irtcEngine)
                return irtcEngine->enableLocalAudio(enabled);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::disableAudio()
        {
            if (irtcEngine)
                return irtcEngine->disableAudio();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setParameters(const char *options)
        {
            if (irtcEngine)
                return irtcEngine->setParameters(options);
                
            return NOT_INIT_ENGINE;
        }

        char *CAgoraSDKObject::getParameter(const char *parameter, const char *args)
        {
            return 0;
        }

        std::string CAgoraSDKObject::getCallId()
        {
            if (irtcEngine)
            {
                agora::util::AString sCallId;
                irtcEngine->getCallId(sCallId);
                return sCallId->data();
            }
            return NOT_INIT_ENGINE_CHAR;
        }

        int CAgoraSDKObject::rate(const char *callId, int rating, const char *desc)
        {   if (irtcEngine)
                return irtcEngine->rate(callId, rating, desc);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::complain(const char *callId, const char *desc)
        {   if (irtcEngine)
                return irtcEngine->complain(callId, desc);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setEnableSpeakerphone(int enabled)
        {
#if defined(WRAPPER_ANDROID) || (defined(WRAPPER_IOS))
            if (irtcEngine)
                return irtcEngine->setEnableSpeakerphone(enabled);
            
            return NOT_INIT_ENGINE;
#else
            return NOT_SUPPORT_API;
#endif
        }

        bool CAgoraSDKObject::isSpeakerphoneEnabled()
        {
#if defined(WRAPPER_ANDROID) || (defined(WRAPPER_IOS))
            if (irtcEngine)
                return irtcEngine->isSpeakerphoneEnabled();

            return NOT_INIT_ENGINE;
#else
            return NOT_SUPPORT_API;
#endif
        }

        int CAgoraSDKObject::setDefaultAudioRouteToSpeakerphone(bool defaultToSpeaker)
        {
#if defined(WRAPPER_ANDROID) || (defined(WRAPPER_IOS))
            if (irtcEngine)
                return irtcEngine->setDefaultAudioRouteToSpeakerphone(defaultToSpeaker);

            return NOT_INIT_ENGINE;
#else
            return NOT_SUPPORT_API;
#endif
        }

        int CAgoraSDKObject::setSpeakerphoneVolume(int volume)
        {
            return NOT_SUPPORT_API;
        }

        int CAgoraSDKObject::enableAudioVolumeIndication(int interval, int smooth, bool report_vad)
        {
            if (irtcEngine)
                return irtcEngine->enableAudioVolumeIndication(interval, smooth, report_vad);

            return NOT_INIT_ENGINE; 
        }

        int CAgoraSDKObject::startAudioRecording(const char *filePath, int quality)
        {
            if (irtcEngine)
                return irtcEngine->startAudioRecording(filePath, (AUDIO_RECORDING_QUALITY_TYPE)quality);

            return NOT_INIT_ENGINE; 
        }

        int CAgoraSDKObject::startAudioRecording(const char* filePath, int sampleRate, int quality)
        {
            if (irtcEngine)
                return irtcEngine->startAudioRecording(filePath, sampleRate, (AUDIO_RECORDING_QUALITY_TYPE)quality);
              
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::stopAudioRecording()
        {
            if (irtcEngine)
                return irtcEngine->stopAudioRecording();

            return NOT_INIT_ENGINE; 
        }

        int CAgoraSDKObject::startAudioMixing(const char *filePath, bool loopBack, bool replace, int cycle)
        {
            if (irtcEngine)
                return irtcEngine->startAudioMixing(filePath, loopBack, replace, cycle);

            return NOT_INIT_ENGINE; 
        }

        int CAgoraSDKObject::stopAudioMixing()
        {
            if (irtcEngine)
                return irtcEngine->stopAudioMixing();

            return NOT_INIT_ENGINE; 
        }

        int CAgoraSDKObject::pauseAudioMixing()
        {
            if (irtcEngine)
                return irtcEngine->pauseAudioMixing();

            return NOT_INIT_ENGINE; 
        }

        int CAgoraSDKObject::resumeAudioMixing()
        {
            if (irtcEngine)
                return irtcEngine->resumeAudioMixing();
            
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::adjustAudioMixingVolume(int volume)
        {
            if (irtcEngine)
                return irtcEngine->adjustAudioMixingVolume(volume);
            
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::getAudioMixingDuration()
        {
            if (irtcEngine)
                return irtcEngine->getAudioMixingDuration();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::getAudioMixingCurrentPosition()
        {
            if (irtcEngine)
                return irtcEngine->getAudioMixingCurrentPosition();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setAudioMixingPosition(int pos)
        {
            if (irtcEngine)
                return irtcEngine->setAudioMixingPosition(pos);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::startEchoTest()
        {
            if (irtcEngine)
                return irtcEngine->startEchoTest();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::startEchoTest(int intervalInSeconds)
        {
            if (irtcEngine)
                return irtcEngine->startEchoTest(intervalInSeconds);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::stopEchoTest()
        {
            if (irtcEngine)
                return irtcEngine->stopEchoTest();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::muteLocalAudioStream(bool muted)
        {
            if (irtcEngine)
                return irtcEngine->muteLocalAudioStream(muted);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::muteAllRemoteAudioStreams(bool muted)
        {
            if (irtcEngine)
                return irtcEngine->muteAllRemoteAudioStreams(muted);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::muteRemoteAudioStream(uid_t uid, bool muted)
        {
            if (irtcEngine)
                return irtcEngine->muteRemoteAudioStream(uid, muted);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::switchCamera()
        {
#if defined(WRAPPER_ANDROID) || (defined(WRAPPER_IOS))
            if (irtcEngine)
                return irtcEngine->switchCamera();

            return NOT_INIT_ENGINE;
#else
            return NOT_SUPPORT_API;
#endif
        }

        int CAgoraSDKObject::setVideoProfile(int profile, bool swapWidthAndHeight)
        {
            if (irtcEngine)
                return irtcEngine->setVideoProfile((VIDEO_PROFILE_TYPE)profile, swapWidthAndHeight);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::muteLocalVideoStream(bool muted)
        {
            if (irtcEngine)
                return irtcEngine->muteLocalVideoStream(muted);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::muteAllRemoteVideoStreams(bool muted)
        {
            if (irtcEngine)
                return irtcEngine->muteAllRemoteVideoStreams(muted);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::muteRemoteVideoStream(uid_t uid, bool muted)
        {
            if (irtcEngine)
                return irtcEngine->muteRemoteVideoStream(uid, muted);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setLogFile(const char *filePath)
        {
            if (irtcEngine)
                return irtcEngine->setLogFile(filePath);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setLogFilter(unsigned int filter)
        {
            if (irtcEngine)
                return irtcEngine->setLogFilter(filter);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setChannelProfile(int profile)
        {
            if (irtcEngine)
                return irtcEngine->setChannelProfile((CHANNEL_PROFILE_TYPE)profile);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setClientRole(int role)
        {
            if (irtcEngine)
                return irtcEngine->setClientRole((CLIENT_ROLE_TYPE)role);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::enableDualStreamMode(bool enabled)
        {
            if (irtcEngine)
                return irtcEngine->enableDualStreamMode(enabled);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setEncryptionMode(const char *encryptionMode)
        {
            if (irtcEngine)
                return irtcEngine->setEncryptionMode(encryptionMode);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setEncryptionSecret(const char *secret)
        {
            if (irtcEngine)
                return irtcEngine->setEncryptionSecret(secret);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setRemoteVideoStreamType(uid_t uid, int streamType)
        {
            if (irtcEngine)
                return irtcEngine->setRemoteVideoStreamType(uid, (REMOTE_VIDEO_STREAM_TYPE)streamType);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::startRecordingService(const char *recordingKey)
        {
            // if (irtcEngine)
            // {
            //     RtcEngineParameters rtcEngineParameters(irtcEngine);
            //     return rtcEngineParameters.startRecordingService(recordingKey);
            // }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::stopRecordingService(const char *recordingKey)
        {
            // if (irtcEngine)
            // {
            //     RtcEngineParameters rtcEngineParameters(irtcEngine);
            //     return rtcEngineParameters.stopRecordingService(recordingKey);
            // }
            return NOT_INIT_ENGINE;
        }
        int CAgoraSDKObject::refreshRecordingServiceStatus()
        {
            // if (irtcEngine)
            // {
            //     RtcEngineParameters rtcEngineParameters(irtcEngine);
            //     return rtcEngineParameters.refreshRecordingServiceStatus();
            // }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::createDataStream(int *streamId, bool reliable, bool ordered)
        {
            if (irtcEngine)
                return irtcEngine->createDataStream(streamId, reliable, ordered);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::sendStreamMessage(int streamId, const char *data, size_t length)
        {
            if (irtcEngine)
                return irtcEngine->sendStreamMessage(streamId, data, length);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setRecordingAudioFrameParametersWithSampleRate(int sampleRate, int channel, int mode, int samplesPerCall)
        {
            if (irtcEngine)
                return irtcEngine->setRecordingAudioFrameParameters(sampleRate, channel, (RAW_AUDIO_FRAME_OP_MODE_TYPE)mode, samplesPerCall);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setPlaybackAudioFrameParametersWithSampleRate(int sampleRate, int channel, int mode, int samplesPerCall)
        {
            if (irtcEngine)
                return irtcEngine->setPlaybackAudioFrameParameters(sampleRate, channel, (RAW_AUDIO_FRAME_OP_MODE_TYPE)mode, samplesPerCall);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::adjustRecordingSignalVolume(int volume)
        {
            if (irtcEngine)
                return irtcEngine->adjustRecordingSignalVolume(volume);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::adjustPlaybackSignalVolume(int volume)
        {
            if (irtcEngine)
                return irtcEngine->adjustPlaybackSignalVolume(volume);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setHighQualityAudioParametersWithFullband(int fullband, int stereo, int fullBitrate)
        {
            if (irtcEngine)
                return RtcEngineParameters(irtcEngine).setHighQualityAudioParameters(fullband, stereo, fullBitrate);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::enableInEarMonitoring(bool enabled)
        {
#if defined(WRAPPER_ANDROID) || (defined(WRAPPER_IOS))
            if (irtcEngine)
                return irtcEngine->enableInEarMonitoring(enabled);

            return NOT_INIT_ENGINE;
#else
            return NOT_SUPPORT_API;
#endif
        }

        int CAgoraSDKObject::enableWebSdkInteroperability(bool enabled)
        {
            if (irtcEngine)
                return irtcEngine->enableWebSdkInteroperability(enabled);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setVideoQualityParameters(bool preferFrameRateOverImageQuality)
        {
            if (irtcEngine)
                return RtcEngineParameters(irtcEngine).setVideoQualityParameters(preferFrameRateOverImageQuality);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setPlaybackDeviceVolume(int volume)
        {
            if (irtcEngine)
                return RtcEngineParameters(irtcEngine).setPlaybackDeviceVolume(volume);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::getEffectsVolume()
        {
            if (irtcEngine)
                return irtcEngine->getEffectsVolume();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setEffectsVolume(int volume)
        {
            if (irtcEngine)
                return irtcEngine->setEffectsVolume(volume);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::playEffect(int soundId, const char *filePath, int loopCount, double pitch, double pan, int gain, bool publish)
        {
            if (irtcEngine)
                return irtcEngine->playEffect(soundId, filePath, loopCount, pitch, pan, gain, publish);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::stopEffect(int soundId)
        {
            if (irtcEngine)
                return irtcEngine->stopEffect(soundId);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::stopAllEffects()
        {
            if (irtcEngine)
                return irtcEngine->stopAllEffects();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::preloadEffect(int soundId, char *filePath)
        {
            if (irtcEngine)
                return irtcEngine->preloadEffect(soundId, filePath);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::unloadEffect(int soundId)
        {
            if (irtcEngine)
                return irtcEngine->unloadEffect(soundId);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::pauseEffect(int soundId)
        {
            if (irtcEngine)
                return irtcEngine->pauseEffect(soundId);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::pauseAllEffects()
        {
            if (irtcEngine)
                return irtcEngine->pauseAllEffects();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::resumeEffect(int soundId)
        {
            if (irtcEngine)
                return irtcEngine->resumeEffect(soundId);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::resumeAllEffects()
        {
            if (irtcEngine)
                return irtcEngine->resumeAllEffects();
            
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setRemoteVoicePosition(uid_t uid, double pan, double gain)
        {
            if (irtcEngine)
                return irtcEngine->setRemoteVoicePosition(uid, pan, gain);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::enableSoundPositionIndication(bool enabled)
        {
            if (irtcEngine)
                return irtcEngine->enableSoundPositionIndication(enabled);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setVoiceOnlyMode(bool enabled)
        {
            // if (irtcEngine)
            //     return irtcEngine->setVoiceOnlyMode(enabled);

            // return NOT_INIT_ENGINE;
            return 0;
        }

        int CAgoraSDKObject::setDefaultMuteAllRemoteAudioStreams(bool mute)
        {
            if (irtcEngine)
                return irtcEngine->setDefaultMuteAllRemoteAudioStreams(mute);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setDefaultMuteAllRemoteVideoStreams(bool mute)
        {
            if (irtcEngine)
                return irtcEngine->setDefaultMuteAllRemoteVideoStreams(mute);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setMultiChannelWant(bool multiChannelWant)
        {
            if (irtcEngine)
            {
                return videoRawDataControl->setMultiChannelWanted(multiChannelWant);
            }
            return NOT_INIT_ENGINE;
        }

        bool CAgoraSDKObject::getMultiChannelWanted()
        {
            if (irtcEngine)
            {
                return videoRawDataControl->getMultiChannelWanted();
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::enableVideoObserver()
        {
            if (irtcEngine)
            {
                if (_unityVideoFrameObserver)
                {
                    bool wheatherInList = checkWheatherInVideoObserverList(_unityVideoFrameObserver);
                    if (!wheatherInList)
                    {
                        _unityVideoFrameObserver->setVideoRender(_videoRender);
                        addVideoFrameObserver(_unityVideoFrameObserver);
                    }
                }
                else
                {
                    _unityVideoFrameObserver = new UnityVideoFrameObserver();
                    _unityVideoFrameObserver->setVideoRender(_videoRender);
                    addVideoFrameObserver(_unityVideoFrameObserver);
                }
                return registeVideoRawDataObserver();
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::disableVideoObserver()
        {
            if (irtcEngine)
            {
                unRegisteVideoRawDataObserver();
                if (_unityVideoFrameObserver)
                {
                    removeVideoFrameObserver(_unityVideoFrameObserver);
                    _unityVideoFrameObserver->removeVideoRender();
                    delete _unityVideoFrameObserver;
                    _unityVideoFrameObserver = NULL;
                    return 0;
                }
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::registeAudioRawDataObserver()
        {
            if (irtcEngine)
            {
                agora::util::AutoPtr<agora::media::IMediaEngine> mediaEngine;
                mediaEngine.queryInterface(irtcEngine, agora::AGORA_IID_MEDIA_ENGINE);

                if (mediaEngine)
                {
                    return mediaEngine->registerAudioFrameObserver(audioRawDataControl);
                }
                return -1;
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::unRegisteAudioRawDataObserver()
        {
            if (irtcEngine)
            {
                agora::util::AutoPtr<agora::media::IMediaEngine> mediaEngine;
                mediaEngine.queryInterface(irtcEngine, agora::AGORA_IID_MEDIA_ENGINE);
                if (mediaEngine)
                {
                    return mediaEngine->registerAudioFrameObserver(NULL);
                }
                return -1;
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::pullAudioFrame(void *audioBuffer, int type, int samples, int bytesPerSample, int channels, int samplesPerSec, long long renderTimeMs, int avsync_type)
        {
            if (irtcEngine)
            {
                agora::util::AutoPtr<agora::media::IMediaEngine> mediaEngine;
                mediaEngine.queryInterface(irtcEngine, agora::AGORA_IID_MEDIA_ENGINE);
                if (mediaEngine && audioBuffer)
                {
                    audioFrame.type = (IAudioFrameObserver::AUDIO_FRAME_TYPE)type;
                    audioFrame.buffer = audioBuffer;
                    audioFrame.samples = samples;
                    audioFrame.bytesPerSample = bytesPerSample;
                    audioFrame.channels = channels;
                    audioFrame.samplesPerSec = samplesPerSec;
                    audioFrame.renderTimeMs = renderTimeMs;
                    audioFrame.avsync_type = avsync_type;
                    int ret = -10;
                    if (audioFrame.buffer)
                    {
                        ret = mediaEngine->pullAudioFrame(&audioFrame);
                    }
                    return ret;
                }
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::generateNativeTexture()
        {
            // if (irtcEngine)
            // {
            //     int texId = videoFrameObserver.createTexture();
            //     return texId;
            // }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::updateTexture(int texId, unsigned char *data, unsigned int uid)
        {
            // if (irtcEngine)
            //     return videoFrameObserver.updateTexture(texId, data, uid);

            return NOT_INIT_ENGINE;
        }

        void CAgoraSDKObject::deleteTexture(int tex)
        {
            // if (irtcEngine)
            //     videoFrameObserver.deleteTexture(tex);
        }

        int CAgoraSDKObject::getConnectionState()
        {
            if (irtcEngine)
                return (int)irtcEngine->getConnectionState();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setAudioProfile(int audioProfile, int scenario)
        {
            if (irtcEngine)
                return irtcEngine->setAudioProfile((AUDIO_PROFILE_TYPE)audioProfile, (AUDIO_SCENARIO_TYPE)scenario);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setVideoEncoderConfiguration(int width, int height, int frameRate, int minFrameRate, int bitrate, int minBitrate, int orientationMode, int degradationPreference, int videoMirrorMode)
        {
            if (irtcEngine)
            {
                VideoEncoderConfiguration videoEncoderConfiguration;   
                videoEncoderConfiguration.dimensions = VideoDimensions(width, height);
                videoEncoderConfiguration.frameRate = (FRAME_RATE)frameRate;
                videoEncoderConfiguration.minFrameRate = minFrameRate;
                videoEncoderConfiguration.bitrate = bitrate;
                videoEncoderConfiguration.minBitrate = minBitrate;
                videoEncoderConfiguration.orientationMode = (ORIENTATION_MODE)orientationMode;
                videoEncoderConfiguration.degradationPreference = (DEGRADATION_PREFERENCE)degradationPreference;
                videoEncoderConfiguration.mirrorMode = (VIDEO_MIRROR_MODE_TYPE)videoMirrorMode;
                return irtcEngine->setVideoEncoderConfiguration(videoEncoderConfiguration);
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::adjustAudioMixingPlayoutVolume(int volume)
        {
            if (irtcEngine)
                return RtcEngineParameters(irtcEngine).adjustAudioMixingPlayoutVolume(volume);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::adjustAudioMixingPublishVolume(int volume)
        {
            if (irtcEngine)
                return RtcEngineParameters(irtcEngine).adjustAudioMixingPublishVolume(volume);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setVolumeOfEffect(int soundId, int volume)
        {
            if (irtcEngine)
                return RtcEngineParameters(irtcEngine).setVolumeOfEffect(soundId, volume);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setRecordingAudioFrameParameters(int sampleRate, int channel, int mode, int samplesPerCall)
        {
            if (irtcEngine)
                return RtcEngineParameters(irtcEngine).setRecordingAudioFrameParameters(sampleRate, channel, (RAW_AUDIO_FRAME_OP_MODE_TYPE)mode, samplesPerCall);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setPlaybackAudioFrameParameters(int sampleRate, int channel, int mode, int samplesPerCall)
        {
            if (irtcEngine)
                return RtcEngineParameters(irtcEngine).setPlaybackAudioFrameParameters(sampleRate,channel, (RAW_AUDIO_FRAME_OP_MODE_TYPE)mode, samplesPerCall);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setMixedAudioFrameParameters(int sampleRate, int samplesPerCall)
        {
            if (irtcEngine)
                return RtcEngineParameters(irtcEngine).setMixedAudioFrameParameters(sampleRate, samplesPerCall);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setLocalPublishFallbackOption(int option)
        {
            if (irtcEngine)
                return RtcEngineParameters(irtcEngine).setLocalPublishFallbackOption(STREAM_FALLBACK_OPTIONS(option));

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setRemoteSubscribeFallbackOption(int option)
        {
            if (irtcEngine)
                return RtcEngineParameters(irtcEngine).setRemoteSubscribeFallbackOption(STREAM_FALLBACK_OPTIONS(option));

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setRemoteDefaultVideoStreamType(int remoteVideoStreamType)
        {
            if (irtcEngine)
                return RtcEngineParameters(irtcEngine).setRemoteDefaultVideoStreamType((REMOTE_VIDEO_STREAM_TYPE)remoteVideoStreamType);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::addPublishStreamUrl(const char *url, bool transcodingEnabled)
        {
            if (irtcEngine)
                return irtcEngine->addPublishStreamUrl(url, transcodingEnabled);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::removePublishStreamUrl(const char *url)
        {
            if (irtcEngine)
                return irtcEngine->removePublishStreamUrl(url);

            return NOT_INIT_ENGINE;
        }

        const char *CAgoraSDKObject::getErrorDescription(int code)
        {
            if (irtcEngine)
                return irtcEngine->getErrorDescription(code);

            return NOT_INIT_ENGINE_CHAR;
        }

        int CAgoraSDKObject::setLocalVoiceChanger(int voiceChanger)
        {
            if (irtcEngine)
                return irtcEngine->setLocalVoiceChanger((VOICE_CHANGER_PRESET)voiceChanger);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setLocalVoiceReverbPreset(int reverbPreset)
        {
            if (irtcEngine)
                return irtcEngine->setLocalVoiceReverbPreset((AUDIO_REVERB_PRESET)reverbPreset);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setLocalVoicePitch(double pitch)
        {
            if (irtcEngine)
                return irtcEngine->setLocalVoicePitch(pitch);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setLocalVoiceEqualization(int bandFrequency, int bandGain)
        {
            if (irtcEngine)
                return irtcEngine->setLocalVoiceEqualization((AUDIO_EQUALIZATION_BAND_FREQUENCY)bandFrequency, bandGain);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setLocalVoiceReverb(int reverbKey, int value)
        {
            if (irtcEngine)
                return irtcEngine->setLocalVoiceReverb((AUDIO_REVERB_TYPE)reverbKey, value);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setLiveTranscoding(int width, int height, int videoBitrate, int videoFramerate, bool lowLatency, int videoGroup, int video_codec_profile, unsigned int backgroundColor,unsigned int userCount, const char *transcodingUserInfo, const char *transcodingExtraInfo, const char *metaData, const char *watermarkRtcImageUrl, int watermarkRtcImageX,int watermarkRtcImageY, int watermarkRtcImageWidth, int watermarkRtcImageHeight, const char *backgroundImageRtcImageUrl, int backgroundImageRtcImageX, int backgroundImageRtcImageY,int backgroundImageRtcImageWidth, int backgroundImageRtcImageHeight, int audioSampleRate, int audioBitrate, int audioChannels, int audioCodecProfile)
        {
            if (irtcEngine)
            {
                LiveTranscoding liveTranscoding;
                liveTranscoding.width = width;
                liveTranscoding.height = height;
                liveTranscoding.videoBitrate = videoBitrate;
                liveTranscoding.videoFramerate = videoFramerate;
                liveTranscoding.lowLatency = lowLatency;
                liveTranscoding.videoGop = videoGroup;
                liveTranscoding.videoCodecProfile = (VIDEO_CODEC_PROFILE_TYPE)video_codec_profile;
                liveTranscoding.backgroundColor = backgroundColor;
                liveTranscoding.userCount = userCount;
                liveTranscoding.transcodingExtraInfo = transcodingExtraInfo;
                liveTranscoding.metadata = metaData;

                TranscodingUser *transcodingUserList = nullptr;
                if (userCount > 0) {
                    transcodingUserList = new TranscodingUser[userCount];
                }

                if (transcodingUserList && transcodingUserInfo != NULL && userCount > 0 && transcodingUserInfo != "") {
                    char transcodingUserListInfo[LENGTH_MAX];
                    strcpy(transcodingUserListInfo, transcodingUserInfo);
                    char *splitStr = "\t";
                    char *temp;
                    for(int i = 0; i < userCount; i++) {
                        if (i == 0) {
                            temp = strtok(transcodingUserListInfo, splitStr);
                        } else {
                            temp = strtok(NULL, splitStr);
                        }
                        TranscodingUser transcodingUser;
                        transcodingUser.uid = (unsigned int)atoi(temp);
                        temp = strtok(NULL, splitStr);
                        transcodingUser.x = atoi(temp);
                        temp = strtok(NULL, splitStr);
                        transcodingUser.y = atoi(temp);
                        temp = strtok(NULL, splitStr);
                        transcodingUser.width = atoi(temp);
                        temp = strtok(NULL, splitStr);
                        transcodingUser.height = atoi(temp);
                        temp = strtok(NULL, splitStr);
                        transcodingUser.zOrder = atoi(temp);
                        temp = strtok(NULL, splitStr);
                        transcodingUser.alpha = atof(temp);
                        temp = strtok(NULL, splitStr);
                        transcodingUser.audioChannel = atof(temp);
                        transcodingUserList[i] = transcodingUser;
                    }
                    liveTranscoding.transcodingUsers = transcodingUserList;
                }
                RtcImage watermark;
                watermark.url = watermarkRtcImageUrl;
                watermark.x = watermarkRtcImageX;
                watermark.y = watermarkRtcImageY;
                watermark.width = watermarkRtcImageWidth;
                watermark.height = watermarkRtcImageHeight;
                liveTranscoding.watermark = &watermark;
                RtcImage backgroundImage;
                backgroundImage.url = backgroundImageRtcImageUrl;
                backgroundImage.x = backgroundImageRtcImageX;
                backgroundImage.y = backgroundImageRtcImageY;
                backgroundImage.width = backgroundImageRtcImageWidth;
                backgroundImage.height = backgroundImageRtcImageHeight;
                liveTranscoding.backgroundImage = &backgroundImage;
                liveTranscoding.audioSampleRate = (AUDIO_SAMPLE_RATE_TYPE)audioSampleRate;
                liveTranscoding.audioBitrate = audioBitrate;
                liveTranscoding.audioChannels = audioChannels;
                liveTranscoding.audioCodecProfile = (AUDIO_CODEC_PROFILE_TYPE)audioCodecProfile;
                int ret = irtcEngine->setLiveTranscoding(liveTranscoding);
                if (transcodingUserList) {
                    delete transcodingUserList;
                    transcodingUserList = nullptr;
                }
                return ret;
            }
            else
            {
                return NOT_INIT_ENGINE;
            }
        }

        // video device manager
        bool CAgoraSDKObject::createAVideoDeviceManager()
        {
            if (irtcEngine)
                return AgoraVideoDeviceManager::getInstance()->createAVideoDeviceManager(irtcEngine);

            return NOT_INIT_ENGINE;
        }
        
        int CAgoraSDKObject::releaseAVideoDeviceManager()
        {
            if (irtcEngine)
                return AgoraVideoDeviceManager::getInstance()->releaseAVideoDeviceManager();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::startVideoDeviceTest(void *hwnd)
        {
            if (irtcEngine)
                return AgoraVideoDeviceManager::getInstance()->startVideoDeviceTest(hwnd);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::stopVideoDeviceTest()
        {
            if (irtcEngine)
                return AgoraVideoDeviceManager::getInstance()->stopVideoDeviceTest();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::getVideoDeviceCollectionCount()
        {
            if (irtcEngine)
                return AgoraVideoDeviceManager::getInstance()->getVideoDeviceCollectionCount();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::getCurrentVideoDevice(char deviceId[LENGTH_MAX])
        {
            if (irtcEngine)
                return AgoraVideoDeviceManager::getInstance()->getCurrentVideoDevice(deviceId);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::getVideoDeviceCollectionDevice(int index, char *deviceName, char *deviceId)
        {
            if (irtcEngine)
                return AgoraVideoDeviceManager::getInstance()->getVideoDeviceCollectionDevice(index, deviceName, deviceId);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setVideoDeviceCollectionDevice(const char *deviceId)
        {
            if (irtcEngine)
                return AgoraVideoDeviceManager::getInstance()->setVideoDeviceCollectionDevice(deviceId);

            return NOT_INIT_ENGINE;
        }

        // audio recording device manager
        bool CAgoraSDKObject::creatAAudioRecordingDeviceManager()
        {
            if (irtcEngine)
                return AgoraAudioRecordingDeviceManager::getInstance()->creatAAudioRecordingDeviceManager(irtcEngine);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::releaseAAudioRecordingDeviceManager()
        {
            if (irtcEngine)
                return AgoraAudioRecordingDeviceManager::getInstance()->releaseAAudioRecordingDeviceManager();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::getAudioRecordingDeviceCount()
        {
            if (irtcEngine)
                return AgoraAudioRecordingDeviceManager::getInstance()->getRecordingDeviceCount();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::getAudioRecordingDevice(int index, char *auduioRecordingDeviceName, char *auduioRecordingDeviceId)
        {
            if (irtcEngine)
                return AgoraAudioRecordingDeviceManager::getInstance()->getRecordingDevice(index, auduioRecordingDeviceName, auduioRecordingDeviceId);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::getCurrentRecordingDevice(char deviceId[LENGTH_MAX])
        {
            if (irtcEngine)
                return AgoraAudioRecordingDeviceManager::getInstance()->getCurrentRecordingDevice(deviceId);
        
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::getCurrentRecordingDeviceInfo(char deviceName[LENGTH_MAX], char deviceId[LENGTH_MAX])
        {
            if (irtcEngine)
                return AgoraAudioRecordingDeviceManager::getInstance()->getCurrentRecordingDeviceInfo(deviceName, deviceId);
        
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::getCurrentPlaybackDevice(char deviceId[LENGTH_MAX])
        {
            if (irtcEngine)
                return AgoraAudioPlaybackDeviceManager::getInstance()->getCurrentPlaybackDevice(deviceId);
        
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::getCurrentPlaybackDeviceInfo(char deviceName[LENGTH_MAX], char deviceId[LENGTH_MAX])
        {
            if (irtcEngine)
                return AgoraAudioPlaybackDeviceManager::getInstance()->getCurrentPlaybackDeviceInfo(deviceName, deviceId);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setAudioRecordingDevice(const char *deviceId)
        {  
            if (irtcEngine)
                return AgoraAudioRecordingDeviceManager::getInstance()->setRecordingDevice(deviceId);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setAudioRecordingDeviceVolume(int volume)
        {
            if (irtcEngine)
                return AgoraAudioRecordingDeviceManager::getInstance()->setRecordingDeviceVolume(volume);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::getAudioRecordingDeviceVolume()
        {
            if (irtcEngine)
                return AgoraAudioRecordingDeviceManager::getInstance()->getRecordingDeviceVolume();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setAudioRecordingDeviceMute(bool mute)
        {
            if (irtcEngine)
                return AgoraAudioRecordingDeviceManager::getInstance()->setRecordingDeviceMute(mute);

            return NOT_INIT_ENGINE;
        }

        bool CAgoraSDKObject::isAudioRecordingDeviceMute()
        {
            if (irtcEngine)
                return AgoraAudioRecordingDeviceManager::getInstance()->isRecordingDeviceMute();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::startAudioRecordingDeviceTest(int indicationInterval)
        {
            if (irtcEngine)
                return AgoraAudioRecordingDeviceManager::getInstance()->startRecordingDeviceTest(indicationInterval);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::stopAudioRecordingDeviceTest()
        {
            if (irtcEngine)
                return AgoraAudioRecordingDeviceManager::getInstance()->stopRecordingDeviceTest();

            return NOT_INIT_ENGINE;
        }

        //audio playback device manager
        bool CAgoraSDKObject::creatAAudioPlaybackDeviceManager()
        {   
            if (irtcEngine)
                return AgoraAudioPlaybackDeviceManager::getInstance()->creatAAudioPlaybackDeviceManager(irtcEngine);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::releaseAAudioPlaybackDeviceManager()
        {
            if (irtcEngine)
                return AgoraAudioPlaybackDeviceManager::getInstance()->releaseAAudioPlaybackDeviceManager();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::getAudioPlaybackDeviceCount()
        {
            if (irtcEngine)
                return AgoraAudioPlaybackDeviceManager::getInstance()->getPlaybackDeviceCount();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::getAudioPlaybackDevice(int index, char *deviceName, char *deviceId)
        {
            if (irtcEngine)
                return AgoraAudioPlaybackDeviceManager::getInstance()->getPlaybackDevice(index, deviceName, deviceId);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setAudioPlaybackDevice(const char *deviceId)
        {
            if (irtcEngine)
                return AgoraAudioPlaybackDeviceManager::getInstance()->setPlaybackDevice(deviceId);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setAudioPlaybackDeviceVolume(int volume)
        {
            if (irtcEngine)
                return AgoraAudioPlaybackDeviceManager::getInstance()->setPlaybackDeviceVolume(volume);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::getAudioPlaybackDeviceVolume()
        {
            if (irtcEngine)
                return AgoraAudioPlaybackDeviceManager::getInstance()->getPlaybackDeviceVolume();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setAudioPlaybackDeviceMute(bool mute)
        {
            if (irtcEngine)
                return AgoraAudioPlaybackDeviceManager::getInstance()->setPlaybackDeviceMute(mute);

            return NOT_INIT_ENGINE;
        }

        bool CAgoraSDKObject::isAudioPlaybackDeviceMute()
        {
            if (irtcEngine)
                return AgoraAudioPlaybackDeviceManager::getInstance()->isPlaybackDeviceMute();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::startAudioPlaybackDeviceTest(const char *testAudioFilePath)
        {
            if (irtcEngine)
                return AgoraAudioPlaybackDeviceManager::getInstance()->startPlaybackDeviceTest(testAudioFilePath);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::stopAudioPlaybackDeviceTest()
        {
            if (irtcEngine)
                return AgoraAudioPlaybackDeviceManager::getInstance()->stopPlaybackDeviceTest();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::getAudioMixingPlayoutVolume()
        {
            if (irtcEngine)
                return irtcEngine->getAudioMixingPlayoutVolume();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::getAudioMixingPublishVolume()
        {
            if (irtcEngine)
                return irtcEngine->getAudioMixingPublishVolume();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::pushVideoFrame(int type, int format, void *videoBuffer, int stride, int height, int cropLeft, int cropTop, int cropRight, int cropBottom, int rotation, long timestamp)
        {
            if (irtcEngine)
            {
                agora::util::AutoPtr<agora::media::IMediaEngine> mediaEngine;
                mediaEngine.queryInterface(irtcEngine, agora::AGORA_IID_MEDIA_ENGINE);
                if (mediaEngine)
                {
                    ExternalVideoFrame videoFrame;
                    videoFrame.type = (ExternalVideoFrame::VIDEO_BUFFER_TYPE)type;
                    videoFrame.format = (ExternalVideoFrame::VIDEO_PIXEL_FORMAT)format;
                    videoFrame.stride = stride;
                    videoFrame.height = height;
                    videoFrame.buffer = videoBuffer; 
                    videoFrame.cropLeft = cropLeft;
                    videoFrame.cropTop = cropTop;
                    videoFrame.cropBottom = cropBottom;
                    videoFrame.cropRight = cropRight;
                    videoFrame.rotation = rotation;
                    videoFrame.timestamp = timestamp;
                    return mediaEngine->pushVideoFrame(&videoFrame);;
                }
                else
                {
                    return -1;
                }
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setExternalVideoSource(bool enable, bool useTexture)
        {
            if (irtcEngine)
            {
                agora::util::AutoPtr<agora::media::IMediaEngine> mediaEngine;
                mediaEngine.queryInterface(irtcEngine, agora::AGORA_IID_MEDIA_ENGINE);
                if (mediaEngine)
                {
                    return mediaEngine->setExternalVideoSource(enable, useTexture);
                }
                else
                {
                    return -1;
                }
            }
                return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setExternalAudioSource(bool enabled, int sampleRate, int channels)
        {
            if (irtcEngine)
            {
                return irtcEngine->setExternalAudioSource(enabled, sampleRate, channels);
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::pushAudioFrame(int mediaSourceType, int audioFrameType, int samples, int bytesPerSample, int channels, int samplesPerSec, void *buffer, int64_t renderTimeMs, int avsync_type, bool wrap)
        {
            if (irtcEngine)
            {
                agora::util::AutoPtr<agora::media::IMediaEngine> mediaEngine;
                mediaEngine.queryInterface(irtcEngine, agora::AGORA_IID_MEDIA_ENGINE);
                if (mediaEngine)
                {
                    IAudioFrameObserver::AudioFrame audioFrame;
                    audioFrame.type = (IAudioFrameObserver::AUDIO_FRAME_TYPE)audioFrameType;
                    audioFrame.samples = samples;
                    audioFrame.bytesPerSample = bytesPerSample;
                    audioFrame.channels = channels;
                    audioFrame.samplesPerSec = samplesPerSec;
                    audioFrame.buffer = buffer;
                    audioFrame.renderTimeMs = renderTimeMs;
                    audioFrame.avsync_type = avsync_type;
                    return mediaEngine->pushAudioFrame((MEDIA_SOURCE_TYPE)mediaSourceType, &audioFrame, wrap);
                }
                else
                {
                    return -1;
                }
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::pushAudioFrame(int audioFrameType, int samples, int bytesPerSample, int channels, int samplesPerSec, void *buffer,int64_t renderTimeMs, int avsync_type)
        {
            if (irtcEngine)
            {
                agora::util::AutoPtr<agora::media::IMediaEngine> mediaEngine;
                mediaEngine.queryInterface(irtcEngine, agora::AGORA_IID_MEDIA_ENGINE);
                if (mediaEngine)
                {
                    IAudioFrameObserver::AudioFrame audioFrame;
                    audioFrame.type = (IAudioFrameObserver::AUDIO_FRAME_TYPE)audioFrameType;
                    audioFrame.samples = samples;
                    audioFrame.bytesPerSample = bytesPerSample;
                    audioFrame.channels = channels;
                    audioFrame.samplesPerSec = samplesPerSec;
                    audioFrame.buffer = buffer;
                    audioFrame.renderTimeMs = renderTimeMs;
                    audioFrame.avsync_type = avsync_type;
                    return mediaEngine->pushAudioFrame(&audioFrame);
                }
                else
                {
                    return -1;
                }
            }
            return NOT_INIT_ENGINE;
        }

        void CAgoraSDKObject::setVideoRender(VideoRender *_render)
        {
            _videoRender = _render;
        }

        void CAgoraSDKObject::removeVideoRender()
        {
            _videoRender = NULL;
        }

        void CAgoraSDKObject::addUserVideoInfo(unsigned int uid, unsigned int textureId)
        {
            if (irtcEngine)
            {
                if (_videoRender)
                {
                    _videoRender->addUserVideoInfo(uid, textureId);
                }
            }
        }

        void CAgoraSDKObject::removeUserVideoInfo(unsigned int uid)
        {
            if (irtcEngine)
            {
                if (_videoRender)
                {
                    _videoRender->removeUserVideoInfo(uid);
                }
            }
        }

        void CAgoraSDKObject::startRenderVideo(int userId)
        {
            if (_videoRender)
            {
                _videoRender->startRenderVideo(userId);
            }
            else
            {
                //PRINTF("startRenderVideo  no videoRender");
            }
        }

        int CAgoraSDKObject::updateVideoRawData(void *data, unsigned int uid)
        {
            if (irtcEngine)
            {
                if (_videoRender)
                {
                    return _videoRender->updateVideoRawData(data, uid);
                }
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::addAudioFrameObserver(IAudioFrameObserver *_audioFrameObserver)
        {
            if (irtcEngine)
            {
                if (_audioFrameObserver)
                {
                    if (audioRawDataControl)
                        return audioRawDataControl->addAudioFrameObserver(_audioFrameObserver);
                }
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::removeAudioFrameObserver(IAudioFrameObserver *_audioFrameObserver)
        {
            if (irtcEngine)
            {
                if (_audioFrameObserver)
                {
                    if (audioRawDataControl)
                        return audioRawDataControl->removeAudioFrameObserver(_audioFrameObserver);
                }  
            }
            return NOT_INIT_ENGINE;
        }

        bool CAgoraSDKObject::checkWheatherInAudioObserverList(IAudioFrameObserver *_audioFrameObserver)
        {
            if (irtcEngine)
            {
                if (_audioFrameObserver)
                {
                    if (audioRawDataControl)
                        return audioRawDataControl->checkWheatherInAudioObserverList(_audioFrameObserver);
                }
            }
            return false;
        }

        int CAgoraSDKObject::addVideoFrameObserver(IVideoFrameObserver *_videoFrameObserver)
        {
            if (irtcEngine)
            {
                if (_videoFrameObserver)
                {
                    if (videoRawDataControl)
                        return videoRawDataControl->addVideoFrameObserver(_videoFrameObserver);
                }        
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::removeVideoFrameObserver(IVideoFrameObserver *_videoFrameObserver)
        {
            if (irtcEngine)
            {
                if (_videoFrameObserver)
                {
                    if (videoRawDataControl)
                        return videoRawDataControl->removeVideoFrameObserver(_videoFrameObserver);
                }
            }
            return NOT_INIT_ENGINE;
        }

        bool CAgoraSDKObject::checkWheatherInVideoObserverList(IVideoFrameObserver *_videoFrameObserver)
        {
            if (irtcEngine)
            {
                if (_videoFrameObserver)
                {
                    if (videoRawDataControl)
                        return videoRawDataControl->checkWheatherInVideoObserverList(_videoFrameObserver);
                }
            }
            return false;
        }

        int CAgoraSDKObject::registeVideoRawDataObserver()
        {
            if (irtcEngine)
            {
                if (videoRawDataControl)
                {
                    agora::util::AutoPtr<agora::media::IMediaEngine> mediaEngine;
                    mediaEngine.queryInterface(irtcEngine, agora::AGORA_IID_MEDIA_ENGINE);
                    if (mediaEngine)
                    {
                        videoRawDataControl->setRegisted(true);
                        return mediaEngine->registerVideoFrameObserver(videoRawDataControl);
                    }
                }
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::unRegisteVideoRawDataObserver()
        {
            if (irtcEngine)
            {
                agora::util::AutoPtr<agora::media::IMediaEngine> mediaEngine;
                mediaEngine.queryInterface(irtcEngine, agora::AGORA_IID_MEDIA_ENGINE);    
                if (mediaEngine)
                {
                    if (videoRawDataControl)
                    {
                        videoRawDataControl->setRegisted(false);
                    }
                    return mediaEngine->registerVideoFrameObserver(NULL);
                }
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setMirrorApplied(bool wheatherApply)
        {
            if (irtcEngine)
            {
                if (videoRawDataControl)
                {
                    return videoRawDataControl->setMirrorApplied(wheatherApply);
                }
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setRenderMode(int renderMode)
        {
            if (irtcEngine)
            {
                if (_videoRender)
                {
                    return _videoRender->setRenderMode((UNITY_RENDER_MODE)renderMode);
                }     
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setCameraCapturerConfiguration(int cameraCaptureConfiguration, int cameraDirection) 
        {
            if (irtcEngine)
            {
                CameraCapturerConfiguration config;
                config.preference = (CAPTURER_OUTPUT_PREFERENCE)cameraCaptureConfiguration;
                #if defined(WRAPPER_ANDROID) || (defined(WRAPPER_IOS))
                config.cameraDirection = (CAMERA_DIRECTION)cameraDirection;
                #else
                #endif
                return irtcEngine->setCameraCapturerConfiguration(config);
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setRemoteUserPriority(uid_t uid, int userPriority)
        {
            if (irtcEngine)
                return irtcEngine->setRemoteUserPriority(uid, (PRIORITY_TYPE)userPriority);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setLogFileSize(unsigned int fileSizeInKBytes)
        {
            if (irtcEngine)
                return irtcEngine->setLogFileSize(fileSizeInKBytes);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setExternalAudioSink(bool enabled, int sampleRate, int channels)
        {
            if (irtcEngine)
                return irtcEngine->setExternalAudioSink(enabled, sampleRate, channels);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::startLastmileProbeTest(bool probeUplink, bool probeDownlink, unsigned int expectedUplinkBitrate, unsigned int expectedDownlinkBitrate)
        {
            if (irtcEngine)
            {
                LastmileProbeConfig lastmileProbeConfig;
                lastmileProbeConfig.probeUplink = probeUplink;
                lastmileProbeConfig.probeDownlink = probeDownlink;
                lastmileProbeConfig.expectedUplinkBitrate = expectedUplinkBitrate;
                lastmileProbeConfig.expectedDownlinkBitrate = expectedDownlinkBitrate;
                return irtcEngine->startLastmileProbeTest(lastmileProbeConfig);
            }
            return NOT_INIT_ENGINE;
        }
       
        int CAgoraSDKObject::stopLastmileProbeTest()
        {
            if (irtcEngine)
                return irtcEngine->stopLastmileProbeTest();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::configPublisher(int width, int height, int framerate, int bitrate, int defaultLayout, int lifecycle, bool owner, int injectStreamWidth, int injectStreamHeight, const char *injectStreamUrl, const char *publishUrl, const char *rawStreamUrl, const char *extraInfo)
        {
            if (irtcEngine)
            {
                // PublisherConfiguration publisherConfiguration;
                // publisherConfiguration.width = width;
                // publisherConfiguration.height = height;
                // publisherConfiguration.framerate = framerate;
                // publisherConfiguration.bitrate = bitrate;
                // publisherConfiguration.defaultLayout = defaultLayout;
                // publisherConfiguration.lifecycle = lifecycle;
                // publisherConfiguration.owner = owner;
                // publisherConfiguration.injectStreamWidth = injectStreamWidth;
                // publisherConfiguration.injectStreamHeight = injectStreamHeight;
                // publisherConfiguration.injectStreamUrl = injectStreamUrl;
                // publisherConfiguration.publishUrl = publishUrl;
                // publisherConfiguration.rawStreamUrl = rawStreamUrl;
                // publisherConfiguration.extraInfo = extraInfo;
                // return irtcEngine->configPublisher(publisherConfiguration);
                return 0;
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::addVideoWatermark(const char *url, int x, int y, int width, int height)
        {
            if (irtcEngine)
            {
                RtcImage rtcImage;
                rtcImage.url = url;
                rtcImage.x = x;
                rtcImage.y = y;
                rtcImage.width = width;
                rtcImage.height = height;
                return irtcEngine->addVideoWatermark(rtcImage);
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::addVideoWatermark(const char* watermarkUrl, bool visibleInPreview, int positionInLandscapeX, int positionInLandscapeY, int positionInLandscapeWidth, int positionInLandscapeHeight, int positionInPortraitX, int positionInPortraitY, int positionInPortraitWidth, int positionInPortraitHeight)
        {
            if (irtcEngine)
            {
                WatermarkOptions watermarkOptions;
                watermarkOptions.visibleInPreview = visibleInPreview;
                Rectangle positionInLandscapeMode;
                positionInLandscapeMode.x = positionInLandscapeX;
                positionInLandscapeMode.y = positionInLandscapeY;
                positionInLandscapeMode.width = positionInLandscapeWidth;
                positionInLandscapeMode.height = positionInLandscapeHeight;
                Rectangle positionInPortraitMode;
                positionInPortraitMode.x = positionInPortraitX;
                positionInPortraitMode.y = positionInPortraitY;
                positionInPortraitMode.width = positionInPortraitWidth;
                positionInPortraitMode.height = positionInPortraitHeight;
                watermarkOptions.positionInLandscapeMode = positionInLandscapeMode;
                watermarkOptions.positionInPortraitMode = positionInPortraitMode;
                return irtcEngine->addVideoWatermark(watermarkUrl, watermarkOptions);
            }
            return NOT_INIT_ENGINE;
        }
       
        int CAgoraSDKObject::clearVideoWatermarks()
        {
            if (irtcEngine)
                return irtcEngine->clearVideoWatermarks();

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::registerLocalUserAccount(const char *appId, const char *userAccount)
        {
            if (irtcEngine)
                return irtcEngine->registerLocalUserAccount(appId, userAccount);

            return NOT_INIT_ENGINE;
        }
        
        int CAgoraSDKObject::joinChannelWithUserAccount(const char *token, const char *channelId, const char *userAccount)
        {
            if (irtcEngine)
                return irtcEngine->joinChannelWithUserAccount(token, channelId, userAccount);

            return NOT_INIT_ENGINE;
        }
        
        int CAgoraSDKObject::getUserInfoByUserAccount(const char *userAccount, UserInfo *userInfo)
        {
            if (irtcEngine)
                return irtcEngine->getUserInfoByUserAccount(userAccount, userInfo);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::getUserInfoByUid(uid_t uid, UserInfo *userInfo)
        {
            if (irtcEngine)
                return irtcEngine->getUserInfoByUid(uid, userInfo);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setBeautyEffectOptions(bool enabled, int lighteningContrastLevel, float lighteningLevel, float smoothnessLevel, float rednessLevel)
        {
            if (irtcEngine)
            {
                BeautyOptions beautyOptions;
                beautyOptions.lighteningContrastLevel = (BeautyOptions::LIGHTENING_CONTRAST_LEVEL)lighteningContrastLevel;
                beautyOptions.lighteningLevel = lighteningLevel;
                beautyOptions.smoothnessLevel = smoothnessLevel;
                beautyOptions.rednessLevel = rednessLevel;
                return irtcEngine->setBeautyEffectOptions(enabled, beautyOptions);
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setInEarMonitoringVolume(int volume)
        {
#if defined(WRAPPER_ANDROID) || (defined(WRAPPER_IOS))
            if (irtcEngine)
                return irtcEngine->setInEarMonitoringVolume(volume);

            return NOT_INIT_ENGINE;
#else
            return NOT_SUPPORT_API;
#endif
        }

        int CAgoraSDKObject::startScreenCaptureByDisplayId(unsigned int displayId, int x, int y, int width, int height, int screenCaptureVideoDimenWidth, int screenCaptureVideoDimenHeight, int screenCaptureFrameRate, int screenCaptureBitrate, bool screenCaptureCaptureMouseCursor)
        {
            if (irtcEngine)
            {
                #ifdef WRAPPER_MAC
                Rectangle rectangle;
                rectangle.x = x;
                rectangle.y = y;
                rectangle.width = width;
                rectangle.height = height;
                ScreenCaptureParameters screenCaptureParameters;
                screenCaptureParameters.dimensions.width = screenCaptureVideoDimenWidth;
                screenCaptureParameters.dimensions.height = screenCaptureVideoDimenHeight;
                screenCaptureParameters.frameRate = screenCaptureFrameRate;
                screenCaptureParameters.bitrate = screenCaptureBitrate;
                screenCaptureParameters.captureMouseCursor = screenCaptureCaptureMouseCursor;
                return irtcEngine->startScreenCaptureByDisplayId(displayId, rectangle, screenCaptureParameters);
                #else
                return NOT_SUPPORT_API;
                #endif
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::startScreenCaptureByScreenRect(int screenRectX, int screenRectY, int screenRectWidth, int screenRectHeight, int regionRectX, int regionRectY, int regionRectWidth, int regionRectHeight, int screenCaptureVideoDimenWidth, int screenCaptureVideoDimenHeight, int screenCaptureFrameRate, int screenCaptureBitrate, bool screenCaptureCaptureMouseCursor)
        {
            if (irtcEngine)
            {
                #ifdef WRAPPER_WINDOWS
                Rectangle screenRect;
                screenRect.x = screenRectX;
                screenRect.y = screenRectY;
                screenRect.width = screenRectWidth;
                screenRect.height = screenRectHeight;

                Rectangle regionRect;
                regionRect.x = regionRectX;
                regionRect.y = regionRectY;
                regionRect.width = regionRectWidth;
                regionRect.height = regionRectHeight;

                ScreenCaptureParameters screenCaptureParameters;
                screenCaptureParameters.dimensions.width = screenCaptureVideoDimenWidth;
                screenCaptureParameters.dimensions.height = screenCaptureVideoDimenHeight;
                screenCaptureParameters.frameRate = screenCaptureFrameRate;
                screenCaptureParameters.bitrate = screenCaptureBitrate;
                screenCaptureParameters.captureMouseCursor = screenCaptureCaptureMouseCursor;
                return irtcEngine->startScreenCaptureByScreenRect(screenRect, regionRect, screenCaptureParameters);
                #else
                return NOT_SUPPORT_API;
                #endif
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::startScreenCaptureByWindowId(int windowId, int regionRectX, int regionRectY, int regionRectWidth, int regionRectHeight,  int screenCaptureVideoDimenWidth, int screenCaptureVideoDimenHeight, int screenCaptureFrameRate, int screenCaptureBitrate, bool screenCaptureCaptureMouseCursor)
        {
            if (irtcEngine)
            {
#if defined(WRAPPER_WINDOWS) || (defined(WRAPPER_MAC))
                Rectangle regionRect;
                regionRect.x = regionRectX;
                regionRect.y = regionRectY;
                regionRect.width = regionRectWidth;
                regionRect.height = regionRectHeight;

                ScreenCaptureParameters screenCaptureParameters;
                screenCaptureParameters.dimensions.width = screenCaptureVideoDimenWidth;
                screenCaptureParameters.dimensions.height = screenCaptureVideoDimenHeight;
                screenCaptureParameters.frameRate = screenCaptureFrameRate;
                screenCaptureParameters.bitrate = screenCaptureBitrate;
                screenCaptureParameters.captureMouseCursor = screenCaptureCaptureMouseCursor;
                return irtcEngine->startScreenCaptureByWindowId(reinterpret_cast<void*>(windowId), regionRect, screenCaptureParameters);
#else
                return NOT_SUPPORT_API;
#endif
            }
            return NOT_INIT_ENGINE;
        }


		int CAgoraSDKObject::setTextureCapture() {
			if (irtcEngine)
			{
				RtcEngineParameters rtcEngineParameters(irtcEngine);
				//return rtcEngineParameters.setTextureCapture();
			}
			return NOT_INIT_ENGINE;
		}


		int CAgoraSDKObject::enableHardWareEncoder(int encoderID) {
			if (irtcEngine)
			{
				AParameter aparameter(irtcEngine);
				return (aparameter->setInt("che.hardware_encoding", encoderID)) == 0 ? TRUE : FALSE;
			}
			return NOT_INIT_ENGINE;
		}


        int CAgoraSDKObject::setScreenCaptureContentHint(int videoContentHint)
        {
            if (irtcEngine)
            {
#if defined(WRAPPER_WINDOWS) || (defined(WRAPPER_MAC))
                enum VideoContentHint hint;
                if (videoContentHint == 0)
                {
                    hint = CONTENT_HINT_NONE;
                }
                else if (videoContentHint == 1)
                {
                    hint = CONTENT_HINT_MOTION;
                }
                else
                {
                    hint = CONTENT_HINT_DETAILS;
                }
                return irtcEngine->setScreenCaptureContentHint(hint);
#else
                return NOT_SUPPORT_API;
#endif
            }
            return NOT_INIT_ENGINE;
        }
    
        int CAgoraSDKObject::updateScreenCaptureParameters(int screenCaptureVideoDimenWidth, int screenCaptureVideoDimenHeight, int screenCaptureFrameRate, int screenCaptureBitrate, bool screenCaptureCaptureMouseCursor)
        {
            if (irtcEngine)
            {
#if defined(WRAPPER_WINDOWS) || (defined(WRAPPER_MAC))
                ScreenCaptureParameters screenCaptureParameters;
                screenCaptureParameters.dimensions.width = screenCaptureVideoDimenWidth;
                screenCaptureParameters.dimensions.height = screenCaptureVideoDimenHeight;
                screenCaptureParameters.frameRate = screenCaptureFrameRate;
                screenCaptureParameters.bitrate = screenCaptureBitrate;
                screenCaptureParameters.captureMouseCursor = screenCaptureCaptureMouseCursor;
                return irtcEngine->updateScreenCaptureParameters(screenCaptureParameters);
#else
                return NOT_SUPPORT_API;
#endif
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::updateScreenCaptureRegion(int x, int y, int width, int height)
        {
            if (irtcEngine)
            {
#if defined(WRAPPER_WINDOWS) || (defined(WRAPPER_MAC))
                Rectangle rect;
                rect.x = x;
                rect.y = y;
                rect.width = width;
                rect.height = height;
                return irtcEngine->updateScreenCaptureRegion(rect);
#else
                return NOT_SUPPORT_API;
#endif
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::stopScreenCapture()
        {
            if (irtcEngine)
            {
#if defined(WRAPPER_WINDOWS) || (defined(WRAPPER_MAC))
                return irtcEngine->stopScreenCapture();
#else
                return NOT_SUPPORT_API;
#endif
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::addInjectStreamUrl(const char *url, int width, int height, int videoGop, int videoFramerate, int videoBitrate, int audioSampleRate, int audioBitrate, int audioChannels)
        {
            if (irtcEngine)
            {
                InjectStreamConfig injectStreamConfig;
                injectStreamConfig.width = width;
                injectStreamConfig.height = height;
                injectStreamConfig.videoGop = videoGop;
                injectStreamConfig.videoFramerate = videoFramerate;
                injectStreamConfig.videoBitrate = videoBitrate;
                injectStreamConfig.audioSampleRate = (AUDIO_SAMPLE_RATE_TYPE)audioSampleRate;
                injectStreamConfig.audioBitrate = audioBitrate;
                injectStreamConfig.audioChannels = audioChannels;
                return irtcEngine->addInjectStreamUrl(url, injectStreamConfig);
            }
            return NOT_INIT_ENGINE;
        }
       
        int CAgoraSDKObject::removeInjectStreamUrl(const char *url)
        {
            if (irtcEngine)
                return irtcEngine->removeInjectStreamUrl(url);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::enableLoopbackRecording(bool enabled, const char *deviceName)
        {
             if (irtcEngine)
             {
                #ifdef WRAPPER_WINDOWS
                return irtcEngine->enableLoopbackRecording(enabled, deviceName);
                #else
                #if defined (WRAPPER_MAC)
                return irtcEngine->enableLoopbackRecording(enabled, deviceName);
                #else
                return NOT_SUPPORT_API;
                #endif
                #endif
             }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setAudioSessionOperationRestriction(int restriction)
        {
            if (irtcEngine)
            {
                #ifdef WRAPPER_IOS
                return irtcEngine->setAudioSessionOperationRestriction((AUDIO_SESSION_OPERATION_RESTRICTION)restriction);
                #else
                return NOT_SUPPORT_API;
                #endif
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::switchChannel(const char *token, const char *channelId)
        {
            if (irtcEngine)
                return irtcEngine->switchChannel(token, channelId);

            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::startChannelMediaRelay(const char *srcChannelName, const char *srcToken , uid_t srcUid, const char *destChannelName, const char *destToken, uid_t destUid, int destCount)
        {
            if (irtcEngine)
            {
                ChannelMediaInfo srcChannelMediaInfo;
                srcChannelMediaInfo.channelName = srcChannelName;
                srcChannelMediaInfo.token = srcToken;
                srcChannelMediaInfo.uid = srcUid;

                ChannelMediaInfo destChannelMediaInfo;
                destChannelMediaInfo.channelName = destChannelName;
                destChannelMediaInfo.token = destToken;
                destChannelMediaInfo.uid = destUid;

                ChannelMediaRelayConfiguration channelMediaRelayConfiguration;
                channelMediaRelayConfiguration.srcInfo = &srcChannelMediaInfo;
                channelMediaRelayConfiguration.destInfos = &destChannelMediaInfo;
                channelMediaRelayConfiguration.destCount = destCount;
                return irtcEngine->startChannelMediaRelay(channelMediaRelayConfiguration);
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::updateChannelMediaRelay(const char *srcChannelName, const char *srcToken , uid_t srcUid, const char *destChannelName, const char *destToken, uid_t destUid, int destCount)
        {
            if (irtcEngine)
            {
                ChannelMediaInfo srcChannelMediaInfo;
                srcChannelMediaInfo.channelName = srcChannelName;
                srcChannelMediaInfo.token = srcToken;
                srcChannelMediaInfo.uid = srcUid;

                ChannelMediaInfo destChannelMediaInfo;
                destChannelMediaInfo.channelName = destChannelName;
                destChannelMediaInfo.token = destToken;
                destChannelMediaInfo.uid = destUid;

                ChannelMediaRelayConfiguration channelMediaRelayConfiguration;
                channelMediaRelayConfiguration.srcInfo = &srcChannelMediaInfo;
                channelMediaRelayConfiguration.destInfos = &destChannelMediaInfo;
                channelMediaRelayConfiguration.destCount = destCount;
                return irtcEngine->updateChannelMediaRelay(channelMediaRelayConfiguration);
            }
            return NOT_INIT_ENGINE; 
        }

        int CAgoraSDKObject::stopChannelMediaRelay()
        {
            if (irtcEngine)
                return irtcEngine->stopChannelMediaRelay();

            return NOT_INIT_ENGINE;
        }

        PacketObserver *CAgoraSDKObject::getPacketObserver()
        {
            if (irtcEngine)
            {
                if (packetObserver)
                {
                    return packetObserver;
                }
                else
                {
                    return NULL;
                }
            }
            return NULL;
        }
        
        int CAgoraSDKObject::registerPacketObserver()
        {
            if (irtcEngine)
            {
                if (!packetObserver)
                {
                    packetObserver = new PacketObserver();
                }
                return irtcEngine->registerPacketObserver(packetObserver);
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::unRegisterPacketObserver()
        {
            if (irtcEngine)
            {
                int ret = irtcEngine->registerPacketObserver(NULL);
                return ret;
            }
            return NOT_INIT_ENGINE;
        }

        MetaDataObserver *CAgoraSDKObject::getMetaDataObserver()
        {
            if (irtcEngine)
            {
                if (metaDataObserver)
                {
                    return metaDataObserver;
                }
                else
                {
                    return NULL;
                } 
            }
            return NULL;
        }

        int CAgoraSDKObject::sendMetadata(unsigned int uid, unsigned int size, unsigned char *buffer, long long timeStampMs)
        {
            if (irtcEngine)
            {
                if (metaDataObserver)
                {
                    metaDataObserver->sendMetadata(uid, size, buffer, timeStampMs);
                }
            }
            return 0;
        }

        int CAgoraSDKObject::registerMediaMetadataObserver(int metaDataType)
        {
            if (irtcEngine)
            {
                if (metaDataObserver)
                {
                    return irtcEngine->registerMediaMetadataObserver(metaDataObserver, (IMetadataObserver::METADATA_TYPE)metaDataType);
                }
            }
            return NOT_INIT_ENGINE;
        }
        
        int CAgoraSDKObject::unRegisterMediaMetadataObserver()
        {
            if (irtcEngine)
            {
                if (metaDataObserver)
                {
                    int ret = irtcEngine->registerMediaMetadataObserver(NULL, IMetadataObserver::METADATA_TYPE::VIDEO_METADATA);
                    metaDataObserver->clearData();
                    return ret;
                }
            }
            return NOT_INIT_ENGINE;
        }

        void CAgoraSDKObject::unRegisterAllObserver()
        {
            disableVideoObserver();
            unRegisteAudioRawDataObserver();
            unRegisterPacketObserver();
            unRegisterMediaMetadataObserver();
        }

        int CAgoraSDKObject::setDefaultEngineSettings()
        {
            if (irtcEngine)
            {
                #if defined(WRAPPER_ANDROID) || (defined(WRAPPER_IOS))
                irtcEngine->setDefaultAudioRouteToSpeakerphone(true);
                #else
                #endif
                AParameter aparameter(irtcEngine);
                aparameter->setParameters("{\"che.audio.specify.codec\":\"OPUS\"}");
                aparameter->setParameters("{\"che.audio.keep.audiosession\": true}");
                return 0;
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::adjustUserPlaybackSignalVolume(unsigned int uid, int volume)
        {
            if (irtcEngine)
            {
                return irtcEngine->adjustUserPlaybackSignalVolume(uid, volume);
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::setAudioMixingPitch(int pitch)
        {
            if (irtcEngine)
            {
                return irtcEngine->setAudioMixingPitch(pitch);
            }
            return NOT_INIT_ENGINE;
        }

        void *CAgoraSDKObject::createChannel(const char *channelId)
        {
            if (irtcEngine && channelId)
            {
                IChannel *channel = reinterpret_cast<IRtcEngine2 *>(irtcEngine)->createChannel(channelId);
                ChannelEventHandler *channelEventHandler = new ChannelEventHandler(channelId);
                channelInfo[channel] = channelEventHandler;
                return channel;
            }
            return NULL; 
        }

        void CAgoraSDKObject::releaseAllChannel()
        {
            if (irtcEngine)
            {
                std::map<IChannel*, ChannelEventHandler*>::iterator channelInfoIterator;
                for (channelInfoIterator = channelInfo.begin(); channelInfoIterator != channelInfo.end();)
                {
                    IChannel *channel = channelInfoIterator->first;
                    if (channel)
                    {
                        channel->leaveChannel();
                        channel->release();
                        channel = NULL;
                    }
                    ChannelEventHandler *channelEventHandler = channelInfoIterator->second;
                    if (channelEventHandler)
                    {
                        delete channelEventHandler;
                        channelEventHandler = NULL;
                    }
                    channelInfo.erase(channelInfoIterator++);
                }
                channelInfo.clear();
            }
        }

        void CAgoraSDKObject::setChannelEventHandler(void *channel)
        {
            if (irtcEngine && channel)
            {
                IChannel *_channel = reinterpret_cast<IChannel *>(channel);
                int ret = _channel->setChannelEventHandler(getChannelEventHandler(channel));
            }
        }
      
        int CAgoraSDKObject::releaseChannel(void *channel)
        {
            if (irtcEngine && channel)
            {
                IChannel *_channel = reinterpret_cast<IChannel *>(channel);
                std::map<IChannel *, ChannelEventHandler *>::iterator it = channelInfo.find(_channel);
                int ret = _channel->release();
                _channel = NULL;
                if (it != channelInfo.end()) 
                {
                    ChannelEventHandler *channelEventHandler = it->second;
                    delete channelEventHandler;
                    channelEventHandler = NULL;
                    channelInfo.erase(it);
                }
                return ret;
            }
            return NOT_INIT_ENGINE;
        }

        ChannelEventHandler *CAgoraSDKObject::getChannelEventHandler(void *channel)
        {
            IChannel *_channel = reinterpret_cast<IChannel *>(channel);
            std::map<IChannel*, ChannelEventHandler *>::iterator it = channelInfo.find(_channel);
            if (it != channelInfo.end())
            {
                ChannelEventHandler *channelEventHandler = it->second;
                return channelEventHandler;
            }
            else
            {
                return NULL;
            }  
        }

        int CAgoraSDKObject::joinChannel(void *channel, const char* token,
                                const char* info,
                                uid_t uid,
                                bool autoSubscribeAudio,
                                bool autoSubscribeVideo)
        {
            if (irtcEngine && channel)
            {
                ChannelMediaOptions channelMediaOptions;
                channelMediaOptions.autoSubscribeAudio = autoSubscribeAudio;
                channelMediaOptions.autoSubscribeVideo = autoSubscribeVideo;
                IChannel *_channel = reinterpret_cast<IChannel *>(channel);
                return _channel->joinChannel(token, info, uid, channelMediaOptions);
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::joinChannelWithUserAccount(void *channel, const char* token,
                                                const char* userAccount,
                                                bool autoSubscribeAudio,
                                                bool autoSubscribeVideo)
        {
            if (irtcEngine && channel)
            {
                ChannelMediaOptions channelMediaOptions;
                channelMediaOptions.autoSubscribeAudio = autoSubscribeAudio;
                channelMediaOptions.autoSubscribeVideo = autoSubscribeVideo;
                IChannel *_channel = reinterpret_cast<IChannel *>(channel);
                return _channel->joinChannelWithUserAccount(token, userAccount, channelMediaOptions);
            }
            return NOT_INIT_ENGINE;
        }
        
        int CAgoraSDKObject::leaveChannel(void *channel)
        {
            if (irtcEngine && channel)
            {
                IChannel *_channel = reinterpret_cast<IChannel *>(channel);
                return _channel->leaveChannel();
            }
            return NOT_INIT_ENGINE;
        }
        
        int CAgoraSDKObject::publish(void *channel)
        {
            if (irtcEngine && channel)
            {
                IChannel *_channel = reinterpret_cast<IChannel *>(channel);
                return _channel->publish();
            }
            return NOT_INIT_ENGINE;
        }
        
        int CAgoraSDKObject::unpublish(void *channel)
        {
            if (irtcEngine && channel)
            {
                IChannel *_channel = reinterpret_cast<IChannel *>(channel);
                return _channel->unpublish();
            }
            return NOT_INIT_ENGINE;
        }
        
        const char *CAgoraSDKObject::channelId(void *channel)
        {
            if (irtcEngine && channel)
            {
                IChannel *_channel = reinterpret_cast<IChannel *>(channel);
                return _channel->channelId();
            }
            return NOT_INIT_ENGINE_CHAR;
        }
        
        std::string CAgoraSDKObject::getCallId(void *channel)
        {
            if (irtcEngine && channel)
            {
                IChannel *_channel = reinterpret_cast<IChannel *>(channel);
                agora::util::AString sCallId;
                _channel->getCallId(sCallId);
                if (sCallId)
                {
                    return sCallId->data();
                }
                return "";
            }
            return NOT_INIT_ENGINE_CHAR;   
        }

        int CAgoraSDKObject::renewToken(void *channel, const char* token)
        {
            if (irtcEngine && channel)
            {
               IChannel *_channel = reinterpret_cast<IChannel *>(channel);
               return _channel->renewToken(token); 
            }
            return NOT_INIT_ENGINE;
        }
        
        int CAgoraSDKObject::setEncryptionSecret(void *channel, const char* secret)
        {
            if (irtcEngine && channel)
            {
               IChannel *_channel = reinterpret_cast<IChannel *>(channel);
               return _channel->setEncryptionSecret(secret); 
            }
            return NOT_INIT_ENGINE; 
        }
        
        int CAgoraSDKObject::setEncryptionMode(void *channel, const char* encryptionMode)
        {
            if (irtcEngine && channel)
            {
               IChannel *_channel = reinterpret_cast<IChannel *>(channel);
               return _channel->setEncryptionMode(encryptionMode); 
            }
            return NOT_INIT_ENGINE; 
        }
  
        int CAgoraSDKObject::setClientRole(void *channel, int role)
        {
            if (irtcEngine && channel)
            {
               IChannel *_channel = reinterpret_cast<IChannel *>(channel);
               return _channel->setClientRole((CLIENT_ROLE_TYPE)role); 
            }
            return NOT_INIT_ENGINE; 
        }
        
        int CAgoraSDKObject::setRemoteUserPriority(void *channel, uid_t uid, int userPriority)
        {
            if (irtcEngine && channel)
            {
               IChannel *_channel = reinterpret_cast<IChannel *>(channel);
               return _channel->setRemoteUserPriority(uid, (PRIORITY_TYPE)userPriority); 
            }
            return NOT_INIT_ENGINE; 
        }

        int CAgoraSDKObject::setRemoteVoicePosition(void *channel, uid_t uid, double pan, double gain)
        {
            if (irtcEngine && channel)
            {
               IChannel *_channel = reinterpret_cast<IChannel *>(channel);
               return _channel->setRemoteVoicePosition(uid, pan, gain); 
            }
            return NOT_INIT_ENGINE; 
        }

        int CAgoraSDKObject::setRemoteRenderMode(void *channel, uid_t userId, int renderMode, int mirrorMode)
        {
            return NOT_SUPPORT_API;
        }

        int CAgoraSDKObject::setDefaultMuteAllRemoteAudioStreams(void *channel, bool mute)
        {
            if (irtcEngine && channel)
            {
               IChannel *_channel = reinterpret_cast<IChannel *>(channel);
               return _channel->setDefaultMuteAllRemoteAudioStreams(mute); 
            }
            return NOT_INIT_ENGINE; 
        }
        
        int CAgoraSDKObject::setDefaultMuteAllRemoteVideoStreams(void *channel, bool mute)
        {
            if (irtcEngine && channel)
            {
               IChannel *_channel = reinterpret_cast<IChannel *>(channel);
               return _channel->setDefaultMuteAllRemoteVideoStreams(mute); 
            }
            return NOT_INIT_ENGINE; 
        }
        
        int CAgoraSDKObject::muteAllRemoteAudioStreams(void *channel, bool mute)
        {
            if (irtcEngine && channel)
            {
               IChannel *_channel = reinterpret_cast<IChannel *>(channel);
               return _channel->muteAllRemoteAudioStreams(mute); 
            }
            return NOT_INIT_ENGINE; 
        }

        int CAgoraSDKObject::adjustUserPlaybackSignalVolume(void *channel, uid_t userId, int volume)
        {
            if (irtcEngine && channel)
            {
               IChannel *_channel = reinterpret_cast<IChannel *>(channel);
               return _channel->adjustUserPlaybackSignalVolume(userId, volume); 
            }
            return NOT_INIT_ENGINE; 
        }

        int CAgoraSDKObject::muteRemoteAudioStream(void *channel, uid_t userId, bool mute)
        {
            if (irtcEngine && channel)
            {
               IChannel *_channel = reinterpret_cast<IChannel *>(channel);
               return _channel->muteRemoteAudioStream(userId, mute); 
            }
            return NOT_INIT_ENGINE; 
        }
        
        int CAgoraSDKObject::muteAllRemoteVideoStreams(void *channel, bool mute)
        {
            if (irtcEngine && channel)
            {
               IChannel *_channel = reinterpret_cast<IChannel *>(channel);
               return _channel->muteAllRemoteVideoStreams(mute); 
            }
            return NOT_INIT_ENGINE; 
        }
        
        int CAgoraSDKObject::muteRemoteVideoStream(void *channel, uid_t userId, bool mute)
        {
            if (irtcEngine && channel)
            {
               IChannel *_channel = reinterpret_cast<IChannel *>(channel);
               return _channel->muteRemoteVideoStream(userId, mute); 
            }
            return NOT_INIT_ENGINE; 
        }
        
        int CAgoraSDKObject::setRemoteVideoStreamType(void *channel, uid_t userId, int streamType)
        {
            if (irtcEngine && channel)
            {
               IChannel *_channel = reinterpret_cast<IChannel *>(channel);
               return _channel->setRemoteVideoStreamType(userId, (REMOTE_VIDEO_STREAM_TYPE)streamType); 
            }
            return NOT_INIT_ENGINE; 
        }
        
        int CAgoraSDKObject::setRemoteDefaultVideoStreamType(void *channel, int streamType)
        {
            if (irtcEngine && channel)
            {
               IChannel *_channel = reinterpret_cast<IChannel *>(channel);
               return _channel->setRemoteDefaultVideoStreamType((REMOTE_VIDEO_STREAM_TYPE)streamType); 
            }
            return NOT_INIT_ENGINE; 
        }

        int CAgoraSDKObject::createDataStream(void *channel, int* streamId, bool reliable, bool ordered)
        {
            if (irtcEngine && channel)
            {
               IChannel *_channel = reinterpret_cast<IChannel *>(channel);
               return _channel->createDataStream(streamId, reliable, ordered); 
            }
            return NOT_INIT_ENGINE; 
        }
        
        int CAgoraSDKObject::sendStreamMessage(void *channel, int streamId, const char* data, size_t length)
        {
            if (irtcEngine && channel)
            {
               IChannel *_channel = reinterpret_cast<IChannel *>(channel);
               return _channel->sendStreamMessage(streamId, data, length); 
            }
            return NOT_INIT_ENGINE; 
        }
        
        int CAgoraSDKObject::addPublishStreamUrl(void *channel, const char *url, bool transcodingEnabled)
        {
            if (irtcEngine && channel)
            {
               IChannel *_channel = reinterpret_cast<IChannel *>(channel);
               return _channel->addPublishStreamUrl(url, transcodingEnabled); 
            }
            return NOT_INIT_ENGINE; 
        }
        
        int CAgoraSDKObject::removePublishStreamUrl(void *channel, const char *url)
        {
            if (irtcEngine && channel)
            {
               IChannel *_channel = reinterpret_cast<IChannel *>(channel);
               return _channel->removePublishStreamUrl(url); 
            }
            return NOT_INIT_ENGINE; 
        }
        
        int CAgoraSDKObject::setLiveTranscoding(void *channel, int width, int height, int videoBitrate, int videoFramerate, bool lowLatency, int videoGroup, int video_codec_profile, unsigned int backgroundColor, unsigned int userCount, const char *transcodingUserInfo, const char *transcodingExtraInfo, const char *metaData, const char *watermarkRtcImageUrl, int watermarkRtcImageX, int watermarkRtcImageY, int watermarkRtcImageWidth, int watermarkRtcImageHeight, const char *backgroundImageRtcImageUrl, int backgroundImageRtcImageX, int backgroundImageRtcImageY, int backgroundImageRtcImageWidth, int backgroundImageRtcImageHeight, int audioSampleRate, int audioBitrate, int audioChannels, int audioCodecProfile)
        {
            if (irtcEngine && channel)
            {
                IChannel *_channel = reinterpret_cast<IChannel *>(channel);
                LiveTranscoding liveTranscoding;
                liveTranscoding.width = width;
                liveTranscoding.height = height;
                liveTranscoding.videoBitrate = videoBitrate;
                liveTranscoding.videoFramerate = videoFramerate;
                liveTranscoding.lowLatency = lowLatency;
                liveTranscoding.videoGop = videoGroup;
                liveTranscoding.videoCodecProfile = (VIDEO_CODEC_PROFILE_TYPE)video_codec_profile;
                liveTranscoding.backgroundColor = backgroundColor;
                liveTranscoding.userCount = userCount;

                TranscodingUser *transcodingUserList = nullptr;
                if (userCount > 0) {
                    transcodingUserList = new TranscodingUser[userCount];
                }

                if (transcodingUserList && transcodingUserInfo != NULL && userCount > 0 && transcodingUserInfo != "") {
                    char transcodingUserListInfo[LENGTH_MAX];
                    strcpy(transcodingUserListInfo, transcodingUserInfo);
                    char *splitStr = "\t";
                    char *temp;
                    for(int i = 0; i < userCount; i++) {
                        if (i == 0) {
                            temp = strtok(transcodingUserListInfo, splitStr);
                        } else {
                            temp = strtok(NULL, splitStr);
                        }
                        TranscodingUser transcodingUser;
                        transcodingUser.uid = (unsigned int)atoi(temp);
                        temp = strtok(NULL, splitStr);
                        transcodingUser.x = atoi(temp);
                        temp = strtok(NULL, splitStr);
                        transcodingUser.y = atoi(temp);
                        temp = strtok(NULL, splitStr);
                        transcodingUser.width = atoi(temp);
                        temp = strtok(NULL, splitStr);
                        transcodingUser.height = atoi(temp);
                        temp = strtok(NULL, splitStr);
                        transcodingUser.zOrder = atoi(temp);
                        temp = strtok(NULL, splitStr);
                        transcodingUser.alpha = atof(temp);
                        temp = strtok(NULL, splitStr);
                        transcodingUser.audioChannel = atof(temp);
                        transcodingUserList[i] = transcodingUser;
                    }
                    liveTranscoding.transcodingUsers = transcodingUserList;
                }
                liveTranscoding.transcodingExtraInfo = transcodingExtraInfo;
                liveTranscoding.metadata = metaData;
                RtcImage watermark;
                watermark.url = watermarkRtcImageUrl;
                watermark.x = watermarkRtcImageX;
                watermark.y = watermarkRtcImageY;
                watermark.width = watermarkRtcImageWidth;
                watermark.height = watermarkRtcImageHeight;
                liveTranscoding.watermark = &watermark;
                RtcImage backgroundImage;
                backgroundImage.url = backgroundImageRtcImageUrl;
                backgroundImage.x = backgroundImageRtcImageX;
                backgroundImage.y = backgroundImageRtcImageY;
                backgroundImage.width = backgroundImageRtcImageWidth;
                backgroundImage.height = backgroundImageRtcImageHeight;
                liveTranscoding.backgroundImage = &backgroundImage;
                liveTranscoding.audioSampleRate = (AUDIO_SAMPLE_RATE_TYPE)audioSampleRate;
                liveTranscoding.audioBitrate = audioBitrate;
                liveTranscoding.audioChannels = audioChannels;
                int ret = _channel->setLiveTranscoding(liveTranscoding);
                if (transcodingUserList) {
                    delete transcodingUserList;
                    transcodingUserList = nullptr;
                }
                return ret;
            }
            return NOT_INIT_ENGINE;
        }
        
        int CAgoraSDKObject::addInjectStreamUrl(void *channel, const char* url, int width, int height, int videoGop, int videoFramerate, int videoBitrate, int audioSampleRate, int audioBitrate, int audioChannels)
        {
            if (irtcEngine && channel)
            {
                IChannel *_channel = reinterpret_cast<IChannel *>(channel);
                InjectStreamConfig injectStreamConfig;
                injectStreamConfig.width = width;
                injectStreamConfig.height = height;
                injectStreamConfig.videoGop = videoGop;
                injectStreamConfig.videoFramerate = videoFramerate;
                injectStreamConfig.videoBitrate = videoBitrate;
                injectStreamConfig.audioSampleRate = (AUDIO_SAMPLE_RATE_TYPE)audioSampleRate;
                injectStreamConfig.audioBitrate = audioBitrate;
                injectStreamConfig.audioChannels = audioChannels;
                return _channel->addInjectStreamUrl(url, injectStreamConfig);
            }
            return NOT_INIT_ENGINE;        
        }
        
        int CAgoraSDKObject::removeInjectStreamUrl(void *channel, const char* url)
        {
            if (irtcEngine && channel)
            {
               IChannel *_channel = reinterpret_cast<IChannel *>(channel);
               return _channel->removeInjectStreamUrl(url); 
            }
            return NOT_INIT_ENGINE; 
        }
        
        int CAgoraSDKObject::startChannelMediaRelay(void *channel, const char *srcChannelName, const char *srcToken , uid_t srcUid, const char *destChannelName, const char *destToken, uid_t destUid, int destCount)
        {
            if (irtcEngine && channel)
            {
                IChannel *_channel = reinterpret_cast<IChannel *>(channel);
                ChannelMediaInfo srcChannelMediaInfo;
                srcChannelMediaInfo.channelName = srcChannelName;
                srcChannelMediaInfo.token = srcToken;
                srcChannelMediaInfo.uid = srcUid;

                ChannelMediaInfo destChannelMediaInfo;
                destChannelMediaInfo.channelName = destChannelName;
                destChannelMediaInfo.token = destToken;
                destChannelMediaInfo.uid = destUid;

                ChannelMediaRelayConfiguration channelMediaRelayConfiguration;
                channelMediaRelayConfiguration.srcInfo = &srcChannelMediaInfo;
                channelMediaRelayConfiguration.destInfos = &destChannelMediaInfo;
                channelMediaRelayConfiguration.destCount = destCount;
                return _channel->startChannelMediaRelay(channelMediaRelayConfiguration);
            }
            return NOT_INIT_ENGINE;
        }

        int CAgoraSDKObject::updateChannelMediaRelay(void *channel, const char *srcChannelName, const char *srcToken , uid_t srcUid, const char *destChannelName, const char *destToken, uid_t destUid, int destCount)
        {
            if (irtcEngine && channel)
            {
                IChannel *_channel = reinterpret_cast<IChannel *>(channel);
                ChannelMediaInfo srcChannelMediaInfo;
                srcChannelMediaInfo.channelName = srcChannelName;
                srcChannelMediaInfo.token = srcToken;
                srcChannelMediaInfo.uid = srcUid;

                ChannelMediaInfo destChannelMediaInfo;
                destChannelMediaInfo.channelName = destChannelName;
                destChannelMediaInfo.token = destToken;
                destChannelMediaInfo.uid = destUid;

                ChannelMediaRelayConfiguration channelMediaRelayConfiguration;
                channelMediaRelayConfiguration.srcInfo = &srcChannelMediaInfo;
                channelMediaRelayConfiguration.destInfos = &destChannelMediaInfo;
                channelMediaRelayConfiguration.destCount = destCount;
                return _channel->updateChannelMediaRelay(channelMediaRelayConfiguration);
            }
            return NOT_INIT_ENGINE;
        }
       
        int CAgoraSDKObject::stopChannelMediaRelay(void *channel)
        {
            if (irtcEngine && channel)
            {
               IChannel *_channel = reinterpret_cast<IChannel *>(channel);
               return _channel->stopChannelMediaRelay(); 
            }
            return NOT_INIT_ENGINE; 
        }
       
        int CAgoraSDKObject::getConnectionState(void *channel)
        {
            if (irtcEngine && channel)
            {
               IChannel *_channel = reinterpret_cast<IChannel *>(channel);
               return _channel->getConnectionState(); 
            }
            return NOT_INIT_ENGINE; 
        }
        
        int CAgoraSDKObject::updateVideoRawData(void *data, const char *channelId, unsigned int uid)
        {
            if (irtcEngine)
            {
                if (_videoRender)
                {
                    return _videoRender->updateVideoRawData(data, (char *)channelId, uid);
                }
            }
            return NOT_INIT_ENGINE;
        }

        void CAgoraSDKObject::addUserVideoInfo(const char *channelId, unsigned int _userId, unsigned int _textureId)
        {
            if (irtcEngine)
            {
                if (_videoRender)
                {
                    _videoRender->addUserVideoInfo((char *)channelId, _userId, _textureId);
                }
            }
        }

        void CAgoraSDKObject::removeUserVideoInfo(const char *channelId, unsigned int _userId)
        {
            if (irtcEngine)
            {
                if (_videoRender)
                {
                    _videoRender->removeUserVideoInfo((char *)channelId, _userId);
                }
            }
        }

        int CAgoraSDKObject::enableFaceDetection(bool enable)
        {
            #if defined(WRAPPER_ANDROID) || (defined(WRAPPER_IOS))
            if (irtcEngine)
                return irtcEngine->enableFaceDetection(enable);
            
            return NOT_INIT_ENGINE;
            #else
            return NOT_SUPPORT_API;
            #endif
        }
    }
}
