#include "IAgoraUnityAPI.h"

namespace agora {
    namespace unity {
        extern "C"
        {
        void initEventOnEngineCallback(FUNC_OnJoinChannelSuccess onJoinChannelSuccess, 
                                        FUNC_OnReJoinChannelSuccess onReJoinChannelSuccess, 
                                        FUNC_OnConnectionLost onConnectionLost, 
                                        FUNC_OnLeaveChannel onLeaveChannel, 
                                        FUNC_OnConnectionInterrupted onConnectionInterrupted, 
                                        FUNC_OnRequestToken onRequestToken,
                                        FUNC_OnUserJoined onUserJoined,
                                        FUNC_OnUserOffline onUserOffline,
                                        FUNC_OnAudioVolumeIndication onAudioVolumeIndication,
                                        FUNC_OnUserMuteAudio onUserMuteAudio,
                                        FUNC_OnSDKWarning onSDKWarning,
                                        FUNC_OnSDKError onSDKError,
                                        FUNC_OnRtcStats onRtcStats,
                                        FUNC_OnAudioMixingFinished onAudioMixingFinished,
                                        FUNC_OnAudioRouteChanged onAudioRouteChanged,
                                        FUNC_OnFirstRemoteVideoDecoded onFirstRemoteVideoDecoded,
                                        FUNC_OnVideoSizeChanged onVideoSizeChanged,
                                        FUNC_OnClientRoleChanged onClientRoleChanged,
                                        FUNC_OnUserMuteVideo onUserMuteVideo,
                                        FUNC_OnMicrophoneEnabled onMicrophoneEnabled,
                                        FUNC_OnApiExecuted onApiCallExecuted,
                                        FUNC_OnFirstLocalAudioFrame onFirstLocalAudioFrame,
                                        FUNC_OnFirstRemoteAudioFrame onFirstRemoteAudioFrame,
                                        FUNC_OnLastmileQuality onLastmileQuality,
                                        FUNC_OnAudioQuality onAudioQuality,
                                        FUNC_OnStreamInjectedStatus onStreamInjectedStatus,
                                        FUNC_OnStreamUnpublished onStreamUnpublished,
                                        FUNC_OnStreamPublished onStreamPublished,
                                        FUNC_OnStreamMessageError onStreamMessageError,
                                        FUNC_OnStreamMessage onStreamMessage,
                                        FUNC_OnConnectionBanned onConnectionBanned,
                                        FUNC_OnVideoStopped onVideoStopped,
                                        FUNC_OnTokenPrivilegeWillExpire onTokenPrivilegeWillExpire,
                                        FUNC_OnNetworkQuality onNetworkQuality,
                                        FUNC_OnLocalVideoStats onLocalVideoStats,
                                        FUNC_OnRemoteVideoStats onRemoteVideoStats,
                                        FUNC_OnRemoteAudioStats onRemoteAudioStats,
                                        FUNC_OnFirstLocalVideoFrame onFirstLocalVideoFrame,
                                        FUNC_OnFirstRemoteVideoFrame onFirstRemoteVideoFrame,
                                        FUNC_OnUserEnableVideo onUserEnableVideo,
                                        FUNC_OnAudioDeviceStateChanged onAudioDeviceStateChanged,
                                        FUNC_OnCameraReady onCameraReady,
                                        FUNC_OnCameraFocusAreaChanged onCameraFocusAreaChanged,
                                        FUNC_OnCameraExposureAreaChanged onCameraExposureAreaChanged,
                                        FUNC_OnRemoteAudioMixingBegin onRemoteAudioMixingBegin,
                                        FUNC_OnRemoteAudioMixingEnd onRemoteAudioMixingEnd,
                                        FUNC_OnAudioEffectFinished onAudioEffectFinished,
                                        FUNC_OnVideoDeviceStateChanged onVideoDeviceStateChanged,
                                        FUNC_OnRemoteVideoStateChanged onRemoteVideoStateChanged,
                                        FUNC_OnUserEnableLocalVideo onUserEnableLocalVideo,
                                        FUNC_OnLocalPublishFallbackToAudioOnly onLocalPublishFallbackToAudioOnly,
                                        FUNC_OnRemoteSubscribeFallbackToAudioOnly onRemoteSubscribeFallbackToAudioOnly,
                                        FUNC_OnConnectionStateChanged onConnectionStateChanged,
                                        FUNC_OnRemoteVideoTransportStats onRemoteVideoTransportStats,
                                        FUNC_OnRemoteAudioTransportStats onRemoteAudioTransportStats,
                                        FUNC_OnTranscodingUpdated onTranscodingUpdated,
                                        FUNC_OnAudioDeviceVolumeChanged onAudioDeviceVolumeChanged,
                                        FUNC_OnActiveSpeaker onActiveSpeaker,
                                        FUNC_OnMediaEngineStartCallSuccess onMediaEngineStartCallSuccess,
                                        FUNC_OnMediaEngineLoadSuccess onMediaEngineLoadSuccess,
                                        FUNC_OnAudioMixingStateChanged onAudioMixingStateChanged,
                                        FUNC_OnFirstRemoteAudioDecoded onFirstRemoteAudioDecoded,
                                        FUNC_OnLocalVideoStateChanged onLocalVideoStateChanged,
                                        FUNC_OnRtmpStreamingStateChanged onRtmpStreamingStateChanged,
                                        FUNC_OnNetworkTypeChanged onNetworkTypeChanged,
                                        FUNC_OnLastmileProbeResult onLastmileProbeResult,
                                        FUNC_OnLocalUserRegistered onLocalUserRegistered,
                                        FUNC_OnUserInfoUpdated onUserInfoUpdated,
                                        FUNC_OnLocalAudioStateChanged onLocalAudioStateChanged,
                                        FUNC_OnRemoteAudioStateChanged onRemoteAudioStateChanged,
                                        FUNC_OnLocalAudioStats onLocalAudioStats,
                                        FUNC_OnChannelMediaRelayStateChanged onChannelMediaRelayStateChanged,
                                        FUNC_OnChannelMediaRelayEvent onChannelMediaRelayEvent,
                                        FUNC_OnFacePositionChanged onFacePositionChanged)
            {
                CAgoraSDKObject::getCAgoraSDKInstance()->getCWrapperRtcEngineEventHandler()->initEventOnEngineCallback(onJoinChannelSuccess, 
                                         onReJoinChannelSuccess, 
                                         onConnectionLost, 
                                         onLeaveChannel, 
                                         onConnectionInterrupted, 
                                         onRequestToken,
                                         onUserJoined,
                                         onUserOffline,
                                         onAudioVolumeIndication,
                                         onUserMuteAudio,
                                         onSDKWarning,
                                         onSDKError,
                                         onRtcStats,
                                         onAudioMixingFinished,
                                         onAudioRouteChanged,
                                         onFirstRemoteVideoDecoded,
                                         onVideoSizeChanged,
                                         onClientRoleChanged,
                                         onUserMuteVideo,
                                         onMicrophoneEnabled,
                                         onApiCallExecuted,
                                         onFirstLocalAudioFrame,
                                         onFirstRemoteAudioFrame,
                                         onLastmileQuality,
                                         onAudioQuality,
                                         onStreamInjectedStatus,
                                         onStreamUnpublished,
                                         onStreamPublished,
                                         onStreamMessageError,
                                         onStreamMessage,
                                         onConnectionBanned,
                                         onVideoStopped,
                                         onTokenPrivilegeWillExpire,
                                         onNetworkQuality,
                                         onLocalVideoStats,
                                         onRemoteVideoStats,
                                         onRemoteAudioStats,
                                         onFirstLocalVideoFrame,
                                         onFirstRemoteVideoFrame,
                                         onUserEnableVideo,
                                         onAudioDeviceStateChanged,
                                         onCameraReady,
                                         onCameraFocusAreaChanged,
                                         onCameraExposureAreaChanged,
                                         onRemoteAudioMixingBegin,
                                         onRemoteAudioMixingEnd,
                                         onAudioEffectFinished,
                                         onVideoDeviceStateChanged,
                                         onRemoteVideoStateChanged,
                                         onUserEnableLocalVideo,
                                         onLocalPublishFallbackToAudioOnly,
                                         onRemoteSubscribeFallbackToAudioOnly,
                                         onConnectionStateChanged,
                                         onRemoteVideoTransportStats,
                                         onRemoteAudioTransportStats,
                                         onTranscodingUpdated,
                                         onAudioDeviceVolumeChanged,
                                         onActiveSpeaker,
                                         onMediaEngineStartCallSuccess,
                                         onMediaEngineLoadSuccess,
                                         onAudioMixingStateChanged,
                                         onFirstRemoteAudioDecoded,
                                         onLocalVideoStateChanged,
                                         onRtmpStreamingStateChanged,
                                         onNetworkTypeChanged,
                                         onLastmileProbeResult,
                                         onLocalUserRegistered,
                                         onUserInfoUpdated,
                                         onLocalAudioStateChanged,
                                         onRemoteAudioStateChanged,
                                         onLocalAudioStats,
                                         onChannelMediaRelayStateChanged,
                                         onChannelMediaRelayEvent,
                                         onFacePositionChanged);
            }

             void initChannelEventCallback(void *channel, FUNC_OnChannelWarning onWarning,
           // void initChannelEventCallback(FUNC_OnChannelWarning onWarning,
                                FUNC_OnChannelError onError,
                                FUNC_OnChannelJoinChannelSuccess onJoinChannelSuccess,
                                FUNC_OnChannelReJoinChannelSuccess onRejoinChannelSuccess,
                                FUNC_OnChannelLeaveChannel onLeaveChannel,
                                FUNC_OnChannelClientRoleChanged onClientRoleChanged,
                                FUNC_OnChannelUserJoined onUserJoined,
                                FUNC_OnChannelUserOffLine onUserOffline,
                                FUNC_OnChannelConnectionLost onConnectionLost,
                                FUNC_OnChannelRequestToken onRequestToken,
                                FUNC_OnChannelTokenPrivilegeWillExpire onTokenPrivilegeWillExpire,
                                FUNC_OnChannelRtcStats onRtcStats,
                                FUNC_OnChannelNetworkQuality onNetworkQuality,
                                FUNC_OnChannelRemoteVideoStats onRemoteVideoStats,
                                FUNC_OnChannelRemoteAudioStats onRemoteAudioStats,
                                FUNC_OnChannelRemoteAudioStateChanged onRemoteAudioStateChanged,
                                FUNC_OnChannelActiveSpeaker onActiveSpeaker,
                                FUNC_OnChannelVideoSizeChanged onVideoSizeChanged,
                                FUNC_OnChannelRemoteVideoStateChanged onRemoteVideoStateChanged,
                                FUNC_OnChannelStreamMessage onStreamMessage, 
                                FUNC_OnChannelStreamMessageError onStreamMessageError,
                                FUNC_OnChannelMediaRelayStateChanged2 onMediaRelayStateChanged,
                                FUNC_OnChannelMediaRelayEvent2 onMediaRelayEvent,
                                FUNC_OnChannelRtmpStreamingStateChanged onRtmpStreamingStateChanged,
                                FUNC_OnChannelTranscodingUpdated onTranscodingUpdated,
                                FUNC_OnChannelStreamInjectedStatus onStreamInjectedStatus, 
                                FUNC_OnChannelRemoteSubscribeFallbackToAudioOnly onRemoteSubscribeFallbackToAudioOnly,
                                FUNC_OnChannelConnectionStateChanged onConnectionStateChanged,
                                FUNC_OnChannelLocalPublishFallbackToAudioOnly onLocalPublishFallbackToAudioOnly)
            {
                ChannelEventHandler *channelEventHandler = CAgoraSDKObject::getCAgoraSDKInstance()->getChannelEventHandler(channel);
                if (channelEventHandler)
                {
                    channelEventHandler->initChannelEventCallback(onWarning,
                                                                onError,
                                                                onJoinChannelSuccess,
                                                                onRejoinChannelSuccess,
                                                                onLeaveChannel, 
                                                                onClientRoleChanged,
                                                                onUserJoined,
                                                                onUserOffline,
                                                                onConnectionLost,
                                                                onRequestToken,
                                                                onTokenPrivilegeWillExpire,
                                                                onRtcStats,
                                                                onNetworkQuality,
                                                                onRemoteVideoStats,
                                                                onRemoteAudioStats,
                                                                onRemoteAudioStateChanged,
                                                                onActiveSpeaker,
                                                                onVideoSizeChanged,
                                                                onRemoteVideoStateChanged,
                                                                onStreamMessage,
                                                                onStreamMessageError,
                                                                onMediaRelayStateChanged,
                                                                onMediaRelayEvent,
                                                                onRtmpStreamingStateChanged,
                                                                onTranscodingUpdated,
                                                                onStreamInjectedStatus,
                                                                onRemoteSubscribeFallbackToAudioOnly,
                                                                onConnectionStateChanged,
                                                                onLocalPublishFallbackToAudioOnly);
                }
                CAgoraSDKObject::getCAgoraSDKInstance()->setChannelEventHandler(channel);
            }

            void initEventOnCaptureVideoFrame(FUNC_OnCaptureVideoFrame onCaptureVideoFrame)
            {
                CAgoraSDKObject::getCAgoraSDKInstance()->getVideoRawDataControl()->initEventOnCaptureVideoFrame(onCaptureVideoFrame);
            }

            void initEventOnRenderVideoFrame(FUNC_OnRenderVideoFrame onRenderVideoFrame)
            {
                CAgoraSDKObject::getCAgoraSDKInstance()->getVideoRawDataControl()->initEventOnRenderVideoFrame(onRenderVideoFrame);
            }

            void initEventOnRecordAudioFrame(FUNC_OnRecordAudioFrame onRecordAudioFrame)
            {
                CAgoraSDKObject::getCAgoraSDKInstance()->getAudioRawDataControl()->initEventonRecordAudioFrame(onRecordAudioFrame);
            }

            void initEventOnPlaybackAudioFrame(FUNC_OnPlaybackAudioFrame onPlaybackAudioFrame)
            {
                CAgoraSDKObject::getCAgoraSDKInstance()->getAudioRawDataControl()->initEventonPlaybackAudioFrame(onPlaybackAudioFrame);
            }

            void initEventOnMixedAudioFrame(FUNC_OnMixedAudioFrame onMixedAudioFrame)
            {
                CAgoraSDKObject::getCAgoraSDKInstance()->getAudioRawDataControl()->initEventonMixedAudioFrame(onMixedAudioFrame);
            }

            void initEventOnPlaybackAudioFrameBeforeMixing(FUNC_OnPlaybackAudioFrameBeforeMixing onPlaybackAudioFrameBeforeMixing)
            {
                CAgoraSDKObject::getCAgoraSDKInstance()->getAudioRawDataControl()->initEventonPlaybackAudioFrameBeforeMixing(onPlaybackAudioFrameBeforeMixing);
            }

            void initEventOnPullAudioFrame(FUNC_OnPullAudioFrame onPullAudioFrame)
            {
                CAgoraSDKObject::getCAgoraSDKInstance()->getAudioRawDataControl()->initEventonPullAudioFrame(onPullAudioFrame);
            }

            int sendMetadata(unsigned int uid, unsigned int size, unsigned char *buffer, long long timeStampMs)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->sendMetadata(uid, size, buffer, timeStampMs);
            }

            void initEventOnPacketCallback(FUNC_OnReceiveAudioPacket onReceiveAudioPacket, FUNC_OnReceiveVideoPacket onReceiveVideoPacket, FUNC_OnSendAudioPacket onSendAudioPacket, FUNC_OnSendVideoPacket onSendVideoPacket)
            {
                CAgoraSDKObject::getCAgoraSDKInstance()->getPacketObserver()->initEventOnPacketCallback(onReceiveAudioPacket, onReceiveVideoPacket, onSendAudioPacket, onSendVideoPacket);
            }

            void initEventOnMetaDataCallback(FUNC_OnMetadataReceived onMetadataReceived, FUNC_OnReadyToSendMetadata onReadyToSendMetadata, FUNC_OnGetMaxMetadataSize onGetMaxMetadataSize)
            {
                CAgoraSDKObject::getCAgoraSDKInstance()->getMetaDataObserver()->initEventOnMetaDataCallback(onMetadataReceived, onReadyToSendMetadata, onGetMaxMetadataSize);
            }

            bool createEngine(const char *appId)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->createEngine(appId);
            }

            bool createEngine2(const char *appId, unsigned int areaCode)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->createEngine2(appId, areaCode);
            }

            bool deleteEngine()
            {
                CAgoraSDKObject::getCAgoraSDKInstance()->unRegisterAllObserver();
                CAgoraSDKObject::getCAgoraSDKInstance()->deleteEngine();
                CAgoraSDKObject::releaseCAgoraSDKInstance();
                return true;
            }

            const char *getSdkVersion()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->getSdkVersion();
            }

            int joinChannel(const char *channelKey, const char *channelName, const char *info, unsigned int uid)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->joinChannel(channelKey, channelName, info, uid);
            }

            int renewToken(const char *token)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->renewToken(token);
            }

            int leaveChannel()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->leaveChannel();
            }

            int enableLastmileTest()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->enableLastmileTest();
            }

            int disableLastmileTest()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->disableLastmileTest();
            }

            int startLastmileProbeTest(bool probeUplink, bool probeDownlink, unsigned int expectedUplinkBitrate, unsigned int expectedDownlinkBitrate)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->startLastmileProbeTest(probeUplink, probeDownlink, expectedUplinkBitrate, expectedDownlinkBitrate);
            }
            
            int stopLastmileProbeTest()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->stopLastmileProbeTest();
            }

            int configPublisher(int width, int height, int framerate, int bitrate, int defaultLayout, int lifecycle, bool owner, int injectStreamWidth, int injectStreamHeight, const char* injectStreamUrl, const char* publishUrl, const char* rawStreamUrl, const char* extraInfo)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->configPublisher(width, height, framerate, bitrate, defaultLayout, lifecycle, owner, injectStreamWidth, injectStreamHeight, injectStreamUrl, publishUrl, rawStreamUrl, extraInfo);
            }

            int addVideoWatermark(const char* url, int x, int y, int width, int height)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->addVideoWatermark(url, x, y, width, height);
            }

            int addVideoWatermark2(const char* watermarkUrl, bool visibleInPreview, int positionInLandscapeX, int positionInLandscapeY, int positionInLandscapeWidth, int positionInLandscapeHeight, int positionInPortraitX, int positionInPortraitY, int positionInPortraitWidth, int positionInPortraitHeight)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->addVideoWatermark(watermarkUrl, visibleInPreview, positionInLandscapeX, positionInLandscapeY, positionInLandscapeWidth, positionInLandscapeHeight, positionInPortraitX, positionInPortraitY, positionInPortraitWidth, positionInPortraitHeight);
            }
        
            int clearVideoWatermarks()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->clearVideoWatermarks();
            }

            int enableVideo()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->enableVideo();
            }

            int disableVideo()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->disableVideo();
            }

            int enableLocalVideo(bool enabled)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->enableLocalVideo(enabled);
            }

            int setupLocalVideo(int hwnd, int renderMode, uid_t uid, void* priv)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setupLocalVideo(hwnd, renderMode, uid, priv);
            }

            int setupRemoteVideo(int hwnd, int renderMode, uid_t uid, void* priv)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setupRemoteVideo(hwnd, renderMode, uid, priv);
            }

            int setLocalRenderMode(int renderMode)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setLocalRenderMode(renderMode);
            }

            int setRemoteRenderMode(uid_t userId, int renderMode)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setRemoteRenderMode(userId, renderMode);
            }

            int setLocalVideoMirrorMode(int mirrorMode)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setLocalVideoMirrorMode(mirrorMode);
            }

            int startPreview()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->startPreview();
            }

            int stopPreview()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->stopPreview();
            }

            int enableAudio()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->enableAudio();
            }

            int enableLocalAudio(bool enabled)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->enableLocalAudio(enabled);
            }

            int disableAudio()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->disableAudio();
            }

            int setParameters(const char *options)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setParameters(options);
            }

            char *getParameter(const char *parameter, const char *args)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->getParameter(parameter, args);
            }

            char *getCallId()
            {
                std::string sCallId = CAgoraSDKObject::getCAgoraSDKInstance()->getCallId();
                return strdup(sCallId.data());
            }

            void freeObject(void *obj)
            {
                if (obj)
                {
                    free(obj);
                }
            }

            int rate(const char *callId, int rating, const char *desc)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->rate(callId, rating, desc);
            }

            int complain(const char *callId, const char *desc)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->complain(callId, desc);
            }

            int setEnableSpeakerphone(int enabled)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setEnableSpeakerphone(enabled);
            }

            bool isSpeakerphoneEnabled()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->isSpeakerphoneEnabled();
            }

            int setDefaultAudioRoutetoSpeakerphone(bool defaultToSpeaker)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setDefaultAudioRouteToSpeakerphone(defaultToSpeaker);
            }

            int setSpeakerphoneVolume(int volume)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setSpeakerphoneVolume(volume);
            }

            int enableAudioVolumeIndication(int interval, int smooth, bool report_vad)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->enableAudioVolumeIndication(interval, smooth, report_vad);
            }

            int startAudioRecording(const char *filePath, int quality)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->startAudioRecording(filePath, quality);
            }

            int startAudioRecording2(const char* filePath, int sampleRate, int quality)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->startAudioRecording(filePath, sampleRate, quality);
            }

            int stopAudioRecording()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->stopAudioRecording();
            }

            int startAudioMixing(const char *filePath, bool loopBack, bool replace, int cycle)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->startAudioMixing(filePath, loopBack, replace, cycle);
            }

            int stopAudioMixing()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->stopAudioMixing();
            }

            int pauseAudioMixing()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->pauseAudioMixing();
            }

            int resumeAudioMixing()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->resumeAudioMixing();
            }

            int adjustAudioMixingVolume(int volume)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->adjustAudioMixingVolume(volume);
            }

            int getAudioMixingDuration()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->getAudioMixingDuration();
            }

            int getAudioMixingCurrentPosition()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->getAudioMixingCurrentPosition();
            }

            int setAudioMixingPosition(int pos)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setAudioMixingPosition(pos);
            }

            int startEchoTest()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->startEchoTest();
            }

            int startEchoTest2(int intervalInSeconds)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->startEchoTest(intervalInSeconds);
            }

            int stopEchoTest()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->stopEchoTest();
            }

            int muteLocalAudioStream(bool muted)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->muteLocalAudioStream(muted);
            }

            int muteAllRemoteAudioStreams(bool muted)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->muteAllRemoteAudioStreams(muted);
            }

            int muteRemoteAudioStream(unsigned int uid, bool muted)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->muteRemoteAudioStream(uid, muted);
            }

            int switchCamera()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->switchCamera();
            }

            int setVideoProfile(int profile, bool swapWidthAndHeight)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setVideoProfile(profile, swapWidthAndHeight);
            }

            int muteLocalVideoStream(bool muted)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->muteLocalVideoStream(muted);
            }

            int muteAllRemoteVideoStreams(bool muted)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->muteAllRemoteVideoStreams(muted);
            }

            int muteRemoteVideoStream(unsigned int uid, bool muted)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->muteRemoteVideoStream(uid, muted);
            }

            int setLogFile(const char *filePath)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setLogFile(filePath);
            }

            int setLogFilter(unsigned int filter)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setLogFilter(filter);
            }

            int setChannelProfile(int profile)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setChannelProfile(profile);
            }

            int setClientRole(int role)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setClientRole(role);
            }

            int enableDualStreamMode(bool enabled)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->enableDualStreamMode(enabled);
            }

            int setEncryptionMode(const char *encryptionMode)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setEncryptionMode(encryptionMode);
            }

            int setEncryptionSecret(const char *secret)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setEncryptionSecret(secret);
            }

            int setRemoteVideoStreamType(unsigned int uid, int streamType)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setRemoteVideoStreamType(uid, streamType);
            }

            int startRecordingService(const char *recordingKey)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->startRecordingService(recordingKey);
            }

            int stopRecordingService(const char *recordingKey)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->stopRecordingService(recordingKey);
            }

            int refreshRecordingServiceStatus()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->refreshRecordingServiceStatus();
            }

            int createDataStream(bool reliable, bool ordered)
            {
                int streamId = 0;
                int ret = 0;
                ret = CAgoraSDKObject::getCAgoraSDKInstance()->createDataStream(&streamId, reliable, ordered);
                if (ret == 0)
                {
                    ret = streamId;
                }
                else
                {

                }
                return ret;
            }

            int sendStreamMessage(int streamId, const char *data, size_t length)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->sendStreamMessage(streamId, data, length);
            }

            int setRecordingAudioFrameParametersWithSampleRate(int sampleRate, int channel, int mode, int samplesPerCall)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setRecordingAudioFrameParametersWithSampleRate(sampleRate, channel, mode, samplesPerCall);
            }

            int setPlaybackAudioFrameParametersWithSampleRate(int sampleRate, int channel, int mode, int samplesPerCall)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setPlaybackAudioFrameParametersWithSampleRate(sampleRate, channel, mode, samplesPerCall);
            }

            int setMixedAudioFrameParameters(int sampleRate, int samplesPerCall)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setMixedAudioFrameParameters(sampleRate, samplesPerCall);
            }

            int adjustRecordingSignalVolume(int volume)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->adjustRecordingSignalVolume(volume);
            }

            int adjustPlaybackSignalVolume(int volume)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->adjustPlaybackSignalVolume(volume);
            }

            int setHighQualityAudioParametersWithFullband(int fullband, int stereo, int fullBitrate)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setHighQualityAudioParametersWithFullband(fullband, stereo, fullBitrate);
            }

            int enableInEarMonitoring(bool enabled)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->enableInEarMonitoring(enabled);
            }

            int enableWebSdkInteroperability(bool enabled)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->enableWebSdkInteroperability(enabled);
            }

            int setVideoQualityParameters(bool preferFrameRateOverImageQuality)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setVideoQualityParameters(preferFrameRateOverImageQuality);
            }

            int setPlaybackDeviceVolume(int volume)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setPlaybackDeviceVolume(volume);
            }

            int getEffectsVolume()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->getEffectsVolume();
            }

            int setEffectsVolume(int volume)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setEffectsVolume(volume);
            }

            int playEffect(int soundId, const char *filePath, int loopCountPlayEffect, double pitch, double pan, int gain, bool publish)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->playEffect(soundId, filePath, loopCountPlayEffect, pitch, pan, gain, publish);
            }

            int stopEffect(int soundId)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->stopEffect(soundId);
            }

            int stopAllEffects()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->stopAllEffects();
            }

            int preloadEffect(int soundId, char *filePath)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->preloadEffect(soundId, filePath);
            }

            int unloadEffect(int soundId)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->unloadEffect(soundId);
            }

            int pauseEffect(int soundId)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->pauseEffect(soundId);
            }

            int pauseAllEffects()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->pauseAllEffects();
            }

            int resumeEffect(int soundId)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->resumeEffect(soundId);
            }

            int resumeAllEffects()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->resumeAllEffects();
            }

            int setRemoteVoicePosition(uid_t uid, double pan, double gain)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setRemoteVoicePosition(uid, pan, gain);
            }

            int setVoiceOnlyMode(bool enabled)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setVoiceOnlyMode(enabled);
            }

            int setDefaultMuteAllRemoteAudioStreams(bool mute)
            {

                return CAgoraSDKObject::getCAgoraSDKInstance()->setDefaultMuteAllRemoteAudioStreams(mute);
            }

            int setDefaultMuteAllRemoteVideoStreams(bool mute)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setDefaultMuteAllRemoteVideoStreams(mute);
            }

            int pushVideoFrame(int type, int format, void *videoBuffer, int stride, int height, int cropLeft, int cropTop, int cropRight, int cropBottom, int rotation, int64_t timestamp)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->pushVideoFrame(type, format, videoBuffer, stride, height, cropLeft, cropTop, cropRight, cropBottom, rotation, timestamp);
            }

            int setExternalVideoSource(bool enable, bool useTexture)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setExternalVideoSource(enable, useTexture);
            }

            int setExternalAudioSource(bool enabled, int sampleRate, int channels)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setExternalAudioSource(enabled, sampleRate, channels);
            }

            int pushAudioFrame_(int audioFrameType, int samples, int bytesPerSample, int channels, int samplesPerSec, void *buffer, int64_t renderTimeMs, int avsync_type)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->pushAudioFrame(audioFrameType, samples, bytesPerSample, channels, samplesPerSec, buffer, renderTimeMs, avsync_type);
            }

            int pushAudioFrame2_(int mediaSourceType, int audioFrameType, int samples, int bytesPerSample, int channels, int samplesPerSec, void *buffer, int64_t renderTimeMs, int avsync_type, bool wrap)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->pushAudioFrame(mediaSourceType, audioFrameType, samples, bytesPerSample, channels, samplesPerSec, buffer, renderTimeMs, avsync_type, wrap);
            }

            int generateNativeTexture()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->generateNativeTexture();
            }

            int updateTexture(int texId, unsigned char *data, unsigned int uid)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->updateTexture(texId, data, uid);
            }

            void deleteTexture(int tex)
            {
                CAgoraSDKObject::getCAgoraSDKInstance()->deleteTexture(tex);
            }

            int getConnectionState()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->getConnectionState();
            }

            int setAudioProfile(int audioProfile, int scenario)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setAudioProfile(audioProfile, scenario);
            }

            int setVideoEncoderConfiguration(int width, int height, int frameRate, int minFrameRate, int bitrate, int minBitrate, int orientationMode, int degradationPreference, int videoMirrorMode)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setVideoEncoderConfiguration(width, height, frameRate, minFrameRate, bitrate, minBitrate, orientationMode, degradationPreference, videoMirrorMode);
            }

            int adjustAudioMixingPlayoutVolume(int volume)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->adjustAudioMixingPlayoutVolume(volume);
            }

            int adjustAudioMixingPublishVolume(int volume)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->adjustAudioMixingPublishVolume(volume);
            }

            int setVolumeOfEffect(int soundId, int volume)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setVolumeOfEffect(soundId, volume);
            }

            int setRecordingAudioFrameParameters(int sampleRate, int channel, int mode, int samplesPerCall)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setRecordingAudioFrameParameters(sampleRate, channel, mode, samplesPerCall);
            }

            int setPlaybackAudioFrameParameters(int sampleRate, int channel, int mode, int samplesPerCall)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setPlaybackAudioFrameParameters(sampleRate, channel, mode, samplesPerCall);
            }

            int setLocalPublishFallbackOption(int option)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setLocalPublishFallbackOption(option);
            }

            int setRemoteSubscribeFallbackOption(int option)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setRemoteSubscribeFallbackOption(option);
            }

            int setRemoteDefaultVideoStreamType(int remoteVideoStreamType)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setRemoteDefaultVideoStreamType(remoteVideoStreamType);
            }

            int addPublishStreamUrl(const char *url, bool transcodingEnabled)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->addPublishStreamUrl(url, transcodingEnabled);
            }

            int removePublishStreamUrl(const char *url)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->removePublishStreamUrl(url);
            }

            const char *getErrorDescription(int code)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->getErrorDescription(code);
            }

            int setLiveTranscoding(int width, int height, int videoBitrate, int videoFramerate, bool lowLatency, int videoGroup, int video_codec_profile, unsigned int backgroundColor, unsigned int userCount, const char *transcodingUserInfo, const char *transcodingExtraInfo, const char *metaData, const char *watermarkRtcImageUrl, int watermarkRtcImageX, int watermarkRtcImageY, int watermarkRtcImageWidth, int watermarkRtcImageHeight, const char *backgroundImageRtcImageUrl, int backgroundImageRtcImageX, int backgroundImageRtcImageY, int backgroundImageRtcImageWidth, int backgroundImageRtcImageHeight, int audioSampleRate, int audioBitrate, int audioChannels, int audioCodecProfile)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setLiveTranscoding(width, height, videoBitrate, videoFramerate, lowLatency, videoGroup, video_codec_profile, backgroundColor, userCount, transcodingUserInfo, transcodingExtraInfo, metaData, watermarkRtcImageUrl, watermarkRtcImageX, watermarkRtcImageY, watermarkRtcImageWidth, watermarkRtcImageHeight, backgroundImageRtcImageUrl, backgroundImageRtcImageX, backgroundImageRtcImageY, backgroundImageRtcImageWidth, backgroundImageRtcImageHeight, audioSampleRate, audioBitrate, audioChannels, audioCodecProfile);
            }

            bool createAVideoDeviceManager()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->createAVideoDeviceManager();
            }

            int releaseAVideoDeviceManager()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->releaseAVideoDeviceManager();
            }

            int startVideoDeviceTest(view_t hwnd)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->startVideoDeviceTest(hwnd);
            }

            int stopVideoDeviceTest()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->stopVideoDeviceTest();
            }

            int getVideoDeviceCollectionCount()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->getVideoDeviceCollectionCount();
            }

            int getCurrentVideoDevice(char deviceId[LENGTH_MAX])
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->getCurrentVideoDevice(deviceId);
            }

            int getVideoDeviceCollectionDevice(int index, char *deviceName, char *deviceId)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->getVideoDeviceCollectionDevice(index, deviceName, deviceId);
            }

            int setVideoDeviceCollectionDevice(const char *deviceId)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setVideoDeviceCollectionDevice(deviceId);
            }

            int setRenderMode(int renderMode)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setRenderMode(renderMode);
            }

            int updateVideoRawData(void *data, unsigned int uid)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->updateVideoRawData(data, uid);
            }

            void addUserVideoInfo(unsigned int _userId, unsigned int _textureId)
            {
                CAgoraSDKObject::getCAgoraSDKInstance()->addUserVideoInfo(_userId, _textureId);
            }
            
            void removeUserVideoInfo(unsigned int _userId)
            {
                CAgoraSDKObject::getCAgoraSDKInstance()->removeUserVideoInfo(_userId);
            }

            // audio recording device manager
            bool creatAAudioRecordingDeviceManager()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->creatAAudioRecordingDeviceManager();
            }

            int releaseAAudioRecordingDeviceManager()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->releaseAAudioRecordingDeviceManager();
            }

            int getAudioRecordingDeviceCount()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->getAudioRecordingDeviceCount();
            }

            int getAudioRecordingDevice(int index, char *audioRecordingDeviceName, char *audioRecordingDeviceId)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->getAudioRecordingDevice(index, audioRecordingDeviceName, audioRecordingDeviceId);
            }

            int setAudioRecordingDevice(const char *deviceId)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setAudioRecordingDevice(deviceId);
            }

            int setAudioRecordingDeviceVolume(int volume)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setAudioRecordingDeviceVolume(volume);
            }

            int getAudioRecordingDeviceVolume()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->getAudioRecordingDeviceVolume();
            }

            int setAudioRecordingDeviceMute(bool mute)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setAudioRecordingDeviceMute(mute);
            }

            bool isAudioRecordingDeviceMute()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->isAudioRecordingDeviceMute();
            }

			int getCurrentRecordingDevice(char deviceId[LENGTH_MAX])
			{
				return CAgoraSDKObject::getCAgoraSDKInstance()->getCurrentRecordingDevice(deviceId);
			}
	
			int getCurrentRecordingDeviceInfo(char deviceName[LENGTH_MAX], char deviceId[LENGTH_MAX])
			{
				return CAgoraSDKObject::getCAgoraSDKInstance()->getCurrentRecordingDeviceInfo(deviceName, deviceId);
			}
            //audio playback device manager
            bool creatAAudioPlaybackDeviceManager()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->creatAAudioPlaybackDeviceManager();
            }

            int releaseAAudioPlaybackDeviceManager()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->releaseAAudioPlaybackDeviceManager();
            }

            int getAudioPlaybackDeviceCount()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->getAudioPlaybackDeviceCount();
            }

            int getAudioPlaybackDevice(int index, char *deviceName, char *deviceId)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->getAudioPlaybackDevice(index, deviceName, deviceId);
            }

            int setAudioPlaybackDevice(const char *deviceId)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setAudioPlaybackDevice(deviceId);
            }

            int setAudioPlaybackDeviceVolume(int volume)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setAudioPlaybackDeviceVolume(volume);
            }

            int getAudioPlaybackDeviceVolume()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->getAudioPlaybackDeviceVolume();
            }

            int setAudioPlaybackDeviceMute(bool mute)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setAudioPlaybackDeviceMute(mute);
            }

            bool isAudioPlaybackDeviceMute()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->isAudioPlaybackDeviceMute();
            }

            int startAudioPlaybackDeviceTest(const char *testAudioFilePath)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->startAudioPlaybackDeviceTest(testAudioFilePath);
            }

            int stopAudioPlaybackDeviceTest()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->stopAudioPlaybackDeviceTest();
            }

            int startAudioRecordingDeviceTest(int indicationInterval)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->startAudioRecordingDeviceTest(indicationInterval);
            }

            int stopAudioRecordingDeviceTest()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->stopAudioRecordingDeviceTest();
            }
			
			int getCurrentPlaybackDevice(char deviceId[LENGTH_MAX])
			{
				return CAgoraSDKObject::getCAgoraSDKInstance()->getCurrentPlaybackDevice(deviceId);
			}
	
			int getCurrentPlaybackDeviceInfo(char deviceName[LENGTH_MAX], char deviceId[LENGTH_MAX])
			{
				return CAgoraSDKObject::getCAgoraSDKInstance()->getCurrentPlaybackDeviceInfo(deviceName, deviceId);
			}

            int enableVideoObserver()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->enableVideoObserver();
            }

            int disableVideoObserver()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->disableVideoObserver();
            }

            int registerVideoRawDataObserver()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->registeVideoRawDataObserver();
            }

            int unRegisterVideoRawDataObserver()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->unRegisteVideoRawDataObserver();
            }

            int registerAudioRawDataObserver()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->registeAudioRawDataObserver();
            }

            int unRegisterAudioRawDataObserver()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->unRegisteAudioRawDataObserver();
            }

            int getAudioMixingPlayoutVolume()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->getAudioMixingPlayoutVolume();
            }

            int getAudioMixingPublishVolume()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->getAudioMixingPublishVolume();
            }

            int setLocalVoiceChanger(int voiceChanger)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setLocalVoiceChanger(voiceChanger);
            }

            int setLocalVoiceReverbPreset(int audioReverbPreset)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setLocalVoiceReverbPreset(audioReverbPreset);
            }

            int setLocalVoicePitch(double pitch)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setLocalVoicePitch(pitch);
            }

            int setLocalVoiceEqualization(int bandFrequency, int bandGain)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setLocalVoiceEqualization(bandFrequency, bandGain);
            }

            int setLocalVoiceReverb(int reverbKey, int value)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setLocalVoiceReverb(reverbKey, value); 
            }

            int enableSoundPositionIndication(bool enabled)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->enableSoundPositionIndication(enabled);
            }

            int setCameraCapturerConfiguration(int cameraCaptureConfiguration, int cameraDirection)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setCameraCapturerConfiguration(cameraCaptureConfiguration, cameraDirection);
            }

            int setRemoteUserPriority(uid_t uid, int userPriority)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setRemoteUserPriority(uid, userPriority);
            }

            int setLogFileSize(unsigned int fileSizeInKBytes)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setLogFileSize(fileSizeInKBytes);
            }

            int setExternalAudioSink(bool enabled, int sampleRate, int channels)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setExternalAudioSink(enabled, sampleRate, channels);
            }

            int registerLocalUserAccount(const char* appId, const char* userAccount)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->registerLocalUserAccount(appId, userAccount);
            }
            
            int joinChannelWithUserAccount(const char* token, const char* channelId, const char* userAccount)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->joinChannelWithUserAccount(token, channelId, userAccount);
            }
        
            int getUserInfoByUserAccount(const char *userAccount)
            {
                UserInfo info;
                int ret = CAgoraSDKObject::getCAgoraSDKInstance()->getUserInfoByUserAccount(userAccount, &info);
                if (ret != 0)
                {
                    return ret;
                }
                else
                {
                    return (int)info.uid;
                }
            }

            int startScreenCaptureByDisplayId(unsigned int displayId, int x, int y, int width, int height, int screenCaptureVideoDimenWidth, int screenCaptureVideoDimenHeight, int screenCaptureFrameRate, int screenCaptureBitrate, bool screenCaptureCaptureMouseCursor)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->startScreenCaptureByDisplayId(displayId, x, y, width, height, screenCaptureVideoDimenWidth, screenCaptureVideoDimenHeight, screenCaptureFrameRate, screenCaptureBitrate, screenCaptureCaptureMouseCursor);
            }

            int startScreenCaptureByScreenRect(int screenRectX, int screenRectY, int screenRectWidth, int screenRectHeight, int regionRectX, int regionRectY, int regionRectWidth, int regionRectHeight, int screenCaptureVideoDimenWidth, int screenCaptureVideoDimenHeight, int screenCaptureFrameRate, int screenCaptureBitrate, bool screenCaptureCaptureMouseCursor)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->startScreenCaptureByScreenRect(screenRectX, screenRectY, screenRectWidth, screenRectHeight, regionRectX, regionRectY, regionRectWidth, regionRectHeight, screenCaptureVideoDimenWidth, screenCaptureVideoDimenHeight, screenCaptureFrameRate, screenCaptureBitrate, screenCaptureCaptureMouseCursor);
            }

            int setScreenCaptureContentHint(int videoContentHint)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setScreenCaptureContentHint(videoContentHint);
            }

            int updateScreenCaptureParameters(int screenCaptureVideoDimenWidth, int screenCaptureVideoDimenHeight, int screenCaptureFrameRate, int screenCaptureBitrate, bool screenCaptureCaptureMouseCursor)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->updateScreenCaptureParameters(screenCaptureVideoDimenWidth, screenCaptureVideoDimenHeight, screenCaptureFrameRate, screenCaptureBitrate, screenCaptureCaptureMouseCursor);
            }

            int updateScreenCaptureRegion(int x, int y, int width, int height)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->updateScreenCaptureRegion(x, y, width, height);
            }

            int stopScreenCapture()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->stopScreenCapture();
            }
         
            char* getUserInfoByUid(uid_t uid)
            {
                UserInfo info;
                int ret = CAgoraSDKObject::getCAgoraSDKInstance()->getUserInfoByUid(uid, &info);
                std::string account = info.userAccount;
                return strdup(account.data());
            }

            int setBeautyEffectOptions(bool enabled, int lighteningContrastLevel, float lighteningLevel, float smoothnessLevel, float rednessLevel)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setBeautyEffectOptions(enabled, lighteningContrastLevel, lighteningLevel, smoothnessLevel, rednessLevel);
            }

            int addInjectStreamUrl(const char *url, int width, int height, int videoGop, int videoFramerate, int videoBitrate, int audioSampleRate, int audioBitrate, int audioChannels)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->addInjectStreamUrl(url, width, height, videoGop, videoFramerate, videoBitrate, audioSampleRate, audioBitrate, audioChannels);
            }

            int removeInjectStreamUrl(const char* url)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->removeInjectStreamUrl(url);
            }

            int enableLoopbackRecording(bool enabled, const char *deviceName)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->enableLoopbackRecording(enabled, deviceName);
            }

            int setAudioSessionOperationRestriction(int restriction)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setAudioSessionOperationRestriction(restriction);
            }

            int switchChannel(const char* token, const char* channelId)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->switchChannel(token, channelId);
            }

            int startChannelMediaRelay(const char* srcChannelName, const char* srcToken , uid_t srcUid, const char* destChannelName, const char* destToken, uid_t destUid, int destCount)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->startChannelMediaRelay(srcChannelName, srcToken, srcUid, destChannelName, destToken, destUid, destCount);
            }

            int updateChannelMediaRelay(const char* srcChannelName, const char* srcToken , uid_t srcUid, const char* destChannelName, const char* destToken, uid_t destUid, int destCount)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->updateChannelMediaRelay(srcChannelName, srcToken, srcUid, destChannelName, destToken, destUid, destCount);
            }

            int stopChannelMediaRelay()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->stopChannelMediaRelay();
            }

            int registerPacketObserver()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->registerPacketObserver();
            }

            int unRegisterPacketObserver()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->unRegisterPacketObserver();
            }

            int registerMediaMetadataObserver(int metaDataType)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->registerMediaMetadataObserver(metaDataType);
            }

            int unRegisterMediaMetadataObserver()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->unRegisterMediaMetadataObserver();
            }

            int setMirrorApplied(bool wheatherApply)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setMirrorApplied(wheatherApply);
            }

            int pullAudioFrame_(void *audioBuffer, int type, int samples, int bytesPerSample, int channels, int samplesPerSec, long long renderTimeMs, int avsync_type)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->pullAudioFrame(audioBuffer, type, samples, bytesPerSample, channels, samplesPerSec, renderTimeMs, avsync_type);
            }

            int setInEarMonitoringVolume(int volume)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setInEarMonitoringVolume(volume);
            }

            int startScreenCaptureByWindowId(int windowId, int regionRectX, int regionRectY, int regionRectWidth, int regionRectHeight,  int screenCaptureVideoDimenWidth, int screenCaptureVideoDimenHeight, int screenCaptureFrameRate, int screenCaptureBitrate, bool screenCaptureCaptureMouseCursor)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->startScreenCaptureByWindowId(windowId, regionRectX, regionRectY, regionRectWidth, regionRectHeight, screenCaptureVideoDimenWidth, screenCaptureVideoDimenHeight, screenCaptureFrameRate, screenCaptureBitrate, screenCaptureCaptureMouseCursor);
            }

			int setTextureCapture()
			{
				return CAgoraSDKObject::getCAgoraSDKInstance()->setTextureCapture();
			}

			bool enableHardWareEncoder()
			{
				return CAgoraSDKObject::getCAgoraSDKInstance()->enableHardWareEncoder(1) == 0;
			}

            int setDefaultEngineSettings()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setDefaultEngineSettings();
            }

            int adjustUserPlaybackSignalVolume(unsigned int uid, int volume)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->adjustUserPlaybackSignalVolume(uid, volume);
            }

            int setAudioMixingPitch(int pitch)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setAudioMixingPitch(pitch);
            }

            void *createChannel(const char *channelId)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->createChannel(channelId);
            }
      
            int ReleaseChannel(void *channel)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->releaseChannel(channel);
            }

            int joinChannel2(void *channel, const char* token,
                                const char* info,
                                uid_t uid,
                                bool autoSubscribeAudio,
                                bool autoSubscribeVideo)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->joinChannel(channel, token, info, uid, autoSubscribeAudio, autoSubscribeVideo);
            }

            int joinChannelWithUserAccount2(void *channel, const char* token,
                                                const char* userAccount,
                                                bool autoSubscribeAudio,
                                                bool autoSubscribeVideo)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->joinChannelWithUserAccount(channel, token, userAccount, autoSubscribeAudio, autoSubscribeVideo);
            }
        
            int leaveChannel2(void *channel)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->leaveChannel(channel);
            }
        
            int publish(void *channel)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->publish(channel);
            }
        
            int unpublish(void *channel)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->unpublish(channel);
            }
        
            const char *channelId(void *channel)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->channelId(channel);
            }
        
            char *getCallId2(void *channel)
            {
                std::string sCallId = CAgoraSDKObject::getCAgoraSDKInstance()->getCallId(channel);
                return strdup(sCallId.data());
            }

            int renewToken2(void *channel, const char* token)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->renewToken(channel, token);
            }
        
            int setEncryptionSecret2(void *channel, const char* secret)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setEncryptionSecret(channel, secret);
            }
            
            int setEncryptionMode2(void *channel, const char* encryptionMode)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setEncryptionMode(channel, encryptionMode);
            }
            
            // virtual int registerPacketObserver(void *channel, IPacketObserver* observer);
            
            // virtual int registerMediaMetadataObserver(void *channel, IMetadataObserver *observer, IMetadataObserver::METADATA_TYPE type);
            
            int setClientRole2(void *channel, int role)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setClientRole(channel, role);
            }
            
            int setRemoteUserPriority2(void *channel, uid_t uid, int userPriority)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setRemoteUserPriority(channel, uid, userPriority);
            }

            int setRemoteVoicePosition2(void *channel, uid_t uid, double pan, double gain)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setRemoteVoicePosition(channel, uid, pan, gain);
            }

            int setRemoteRenderMode2(void *channel, uid_t userId, int renderMode, int mirrorMode)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setRemoteRenderMode(channel, userId, renderMode, mirrorMode);
            }

            int setDefaultMuteAllRemoteAudioStreams2(void *channel, bool mute)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setDefaultMuteAllRemoteAudioStreams(channel, mute);
            }
            
            int setDefaultMuteAllRemoteVideoStreams2(void *channel, bool mute)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setDefaultMuteAllRemoteVideoStreams(channel, mute);
            }
            
            int muteAllRemoteAudioStreams2(void *channel, bool mute)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->muteAllRemoteAudioStreams(channel, mute);
            }

            int muteRemoteAudioStream2(void *channel, uid_t userId, bool mute)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->muteRemoteAudioStream(channel, userId, mute);
            }
            
            int muteAllRemoteVideoStreams2(void *channel, bool mute)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->muteAllRemoteVideoStreams(channel, mute);
            }
            
            int muteRemoteVideoStream2(void *channel, uid_t userId, bool mute)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->muteRemoteVideoStream(channel, userId, mute);
            }
            
            int setRemoteVideoStreamType2(void *channel, uid_t userId, int streamType)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setRemoteVideoStreamType(channel, userId, streamType);
            }
            
            int setRemoteDefaultVideoStreamType2(void *channel, int streamType)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setRemoteDefaultVideoStreamType(channel, streamType);
            }

            int createDataStream2(void *channel, bool reliable, bool ordered)
            {
                int streamId = 0;
                int ret = 0;
                ret = CAgoraSDKObject::getCAgoraSDKInstance()->createDataStream(channel ,&streamId, reliable, ordered);
                if (ret == 0)
                {
                    ret = streamId;
                }
                else
                {

                }
                return ret;
            }
            
            int sendStreamMessage2(void *channel, int streamId, const char* data, size_t length)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->sendStreamMessage(channel, streamId, data, length);
            }
            
            int addPublishStreamUrl2(void *channel, const char *url, bool transcodingEnabled)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->addPublishStreamUrl(channel, url, transcodingEnabled);
            }
            
            int removePublishStreamUrl2(void *channel, const char *url)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->removePublishStreamUrl(channel, url);
            }
            
            int setLiveTranscoding2(void *channel, int width, int height, int videoBitrate, int videoFramerate, bool lowLatency, int videoGroup, int video_codec_profile, unsigned int backgroundColor, unsigned int userCount, const char *transcodingUserInfo, const char *transcodingExtraInfo, const char *metaData, const char *watermarkRtcImageUrl, int watermarkRtcImageX, int watermarkRtcImageY, int watermarkRtcImageWidth, int watermarkRtcImageHeight, const char *backgroundImageRtcImageUrl, int backgroundImageRtcImageX, int backgroundImageRtcImageY, int backgroundImageRtcImageWidth, int backgroundImageRtcImageHeight, int audioSampleRate, int audioBitrate, int audioChannels, int audioCodecProfile)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setLiveTranscoding(channel, width, height, videoBitrate, videoFramerate, lowLatency, videoGroup, video_codec_profile, backgroundColor, userCount, transcodingUserInfo, transcodingExtraInfo, metaData, watermarkRtcImageUrl, watermarkRtcImageX, watermarkRtcImageY, watermarkRtcImageWidth, watermarkRtcImageHeight, backgroundImageRtcImageUrl, backgroundImageRtcImageX, backgroundImageRtcImageY, backgroundImageRtcImageWidth, backgroundImageRtcImageHeight, audioSampleRate, audioBitrate, audioChannels, audioCodecProfile);
            }
            
            int addInjectStreamUrl2(void *channel, const char* url, int width, int height, int videoGop, int videoFramerate, int videoBitrate, int audioSampleRate, int audioBitrate, int audioChannels)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->addInjectStreamUrl(channel, url, width, height, videoGop, videoFramerate, videoBitrate, audioSampleRate, audioBitrate, audioChannels);
            }
            
            int removeInjectStreamUrl2(void *channel, const char* url)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->removeInjectStreamUrl(channel, url);
            }
            
            int startChannelMediaRelay2(void *channel, const char *srcChannelName, const char *srcToken , uid_t srcUid, const char *destChannelName, const char *destToken, uid_t destUid, int destCount)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->startChannelMediaRelay(channel, srcChannelName, srcToken , srcUid, destChannelName, destToken, destUid, destCount);
            }
            
            int updateChannelMediaRelay2(void *channel, const char *srcChannelName, const char *srcToken , uid_t srcUid, const char *destChannelName, const char *destToken, uid_t destUid, int destCount)
            {                                                       
                return CAgoraSDKObject::getCAgoraSDKInstance()->updateChannelMediaRelay(channel, srcChannelName, srcToken , srcUid, destChannelName, destToken, destUid, destCount);
            }
            
            int stopChannelMediaRelay2(void *channel)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->stopChannelMediaRelay(channel);
            }
            
            int getConnectionState2(void *channel)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->getConnectionState(channel);
            }
            // 3.0.0
            int adjustUserPlaybackSignalVolume2(void *channel, unsigned int uid, int volume)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->adjustUserPlaybackSignalVolume(channel, uid, volume);
            }

            int setMultiChannelWant(bool multiChannelWant)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->setMultiChannelWant(multiChannelWant);
            }

            bool getMultiChannelWanted()
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->getMultiChannelWanted();
            }

            void addUserVideoInfo2(const char *channelId, unsigned int _userId, unsigned int _textureId)
            {
                CAgoraSDKObject::getCAgoraSDKInstance()->addUserVideoInfo(channelId, _userId, _textureId);
            }
        
            void removeUserVideoInfo2(const char *channelId, unsigned int _userId)
            {
                CAgoraSDKObject::getCAgoraSDKInstance()->removeUserVideoInfo(channelId, _userId);
            }
        
            int updateVideoRawData2(void *data, const char *channelId, unsigned int uid)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->updateVideoRawData(data, channelId, uid);
            }

            int enableFaceDetection(bool enable)
            {
                return CAgoraSDKObject::getCAgoraSDKInstance()->enableFaceDetection(enable);
            }

        #if defined(WRAPPER_ANDROID)
            jint JNI_OnLoad(JavaVM *vm, void *)
            {
                JNIEnv *env;
                vm->GetEnv((void **)&env, JNI_VERSION_1_6);
                jclass rtcEngineImpClass = env->FindClass("io/agora/rtc/internal/RtcEngineImpl");
                jmethodID methodId = env->GetStaticMethodID(rtcEngineImpClass, "loadNativeLibrary", "()V");
                env->CallStaticVoidMethod(rtcEngineImpClass, methodId);
                PRINTF("JNI_OnLoad");
                return (JNI_VERSION_1_6);
            }
        #endif
        }       
    }
}
