#include "CWrapperRtcEngineEventHandler.h"

namespace agora {
    namespace unity {

        #define CHECKWHEATHERINITENGINEEVENT()                         \
            if (engineEvent == NULL) \
            {                                                          \
                return;                                                \
            }

        CWrapperRtcEngineEventHandler::CWrapperRtcEngineEventHandler()
        {
            engineEvent = new EngineEvent();
        }

        CWrapperRtcEngineEventHandler::~CWrapperRtcEngineEventHandler()
        {
            if (engineEvent)
            {
                engineEvent->reset();
                delete engineEvent;
                engineEvent = NULL;
            }
        }

        void CWrapperRtcEngineEventHandler::initEventOnEngineCallback (FUNC_OnJoinChannelSuccess onJoinChannelSuccess, 
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
            engineEvent->onJoinChannelSuccess = onJoinChannelSuccess;
            engineEvent->onReJoinChannelSuccess = onReJoinChannelSuccess;
            engineEvent->onConnectionLost = onConnectionLost;
            engineEvent->onLeaveChannel = onLeaveChannel;
            engineEvent->onConnectionInterrupted = onConnectionInterrupted;
            engineEvent->onRequestToken = onRequestToken;
            engineEvent->onUserJoined = onUserJoined;
            engineEvent->onUserOffline = onUserOffline;
            engineEvent->onAudioVolumeIndication = onAudioVolumeIndication;
            engineEvent->onUserMuteAudio = onUserMuteAudio;
            engineEvent->onSDKWarning = onSDKWarning;
            engineEvent->onSDKError = onSDKError;
            engineEvent->onRtcStats = onRtcStats;
            engineEvent->onAudioMixingFinished = onAudioMixingFinished;
            engineEvent->onAudioRouteChanged = onAudioRouteChanged;
            engineEvent->onFirstRemoteVideoDecoded = onFirstRemoteVideoDecoded;
            engineEvent->onVideoSizeChanged = onVideoSizeChanged;
            engineEvent->onClientRoleChanged = onClientRoleChanged;
            engineEvent->onUserMuteVideo = onUserMuteVideo;
            engineEvent->onMicrophoneEnabled = onMicrophoneEnabled;
            engineEvent->onApiCallExecuted = onApiCallExecuted;
            engineEvent->onFirstLocalAudioFrame = onFirstLocalAudioFrame;
            engineEvent->onFirstRemoteAudioFrame = onFirstRemoteAudioFrame;
            engineEvent->onLastmileQuality = onLastmileQuality;
            engineEvent->onAudioQuality = onAudioQuality;
            engineEvent->onStreamInjectedStatus = onStreamInjectedStatus;
            engineEvent->onStreamUnpublished = onStreamUnpublished;
            engineEvent->onStreamPublished = onStreamPublished;
            engineEvent->onStreamMessageError = onStreamMessageError;
            engineEvent->onStreamMessage = onStreamMessage;
            engineEvent->onConnectionBanned = onConnectionBanned;
            engineEvent->onVideoStopped = onVideoStopped;
            engineEvent->onTokenPrivilegeWillExpire = onTokenPrivilegeWillExpire;
            engineEvent->onNetworkQuality = onNetworkQuality;
            engineEvent->onLocalVideoStats = onLocalVideoStats;
            engineEvent->onRemoteVideoStats = onRemoteVideoStats;
            engineEvent->onRemoteAudioStats = onRemoteAudioStats;
            engineEvent->onFirstLocalVideoFrame = onFirstLocalVideoFrame;
            engineEvent->onFirstRemoteVideoFrame = onFirstRemoteVideoFrame;
            engineEvent->onUserEnableVideo = onUserEnableVideo;
            engineEvent->onAudioDeviceStateChanged = onAudioDeviceStateChanged;
            engineEvent->onCameraReady = onCameraReady;
            engineEvent->onCameraFocusAreaChanged = onCameraFocusAreaChanged;
            engineEvent->onCameraExposureAreaChanged = onCameraExposureAreaChanged;
            engineEvent->onRemoteAudioMixingBegin = onRemoteAudioMixingBegin;
            engineEvent->onRemoteAudioMixingEnd = onRemoteAudioMixingEnd;
            engineEvent->onAudioEffectFinished = onAudioEffectFinished;
            engineEvent->onVideoDeviceStateChanged = onVideoDeviceStateChanged;
            engineEvent->onRemoteVideoStateChanged = onRemoteVideoStateChanged;
            engineEvent->onUserEnableLocalVideo = onUserEnableLocalVideo;
            engineEvent->onLocalPublishFallbackToAudioOnly = onLocalPublishFallbackToAudioOnly;
            engineEvent->onRemoteSubscribeFallbackToAudioOnly = onRemoteSubscribeFallbackToAudioOnly;
            engineEvent->onConnectionStateChanged = onConnectionStateChanged;
            engineEvent->onRemoteVideoTransportStats = onRemoteVideoTransportStats;
            engineEvent->onRemoteAudioTransportStats = onRemoteAudioTransportStats;
            engineEvent->onTranscodingUpdated = onTranscodingUpdated;
            engineEvent->onAudioDeviceVolumeChanged = onAudioDeviceVolumeChanged;
            engineEvent->onActiveSpeaker = onActiveSpeaker;
            engineEvent->onMediaEngineStartCallSuccess = onMediaEngineStartCallSuccess;
            engineEvent->onMediaEngineLoadSuccess = onMediaEngineLoadSuccess;
            engineEvent->onAudioMixingStateChanged = onAudioMixingStateChanged;
            engineEvent->onFirstRemoteAudioDecoded = onFirstRemoteAudioDecoded;
            engineEvent->onLocalVideoStateChanged = onLocalVideoStateChanged;
            engineEvent->onRtmpStreamingStateChanged = onRtmpStreamingStateChanged;
            engineEvent->onNetworkTypeChanged = onNetworkTypeChanged;
            engineEvent->onLastmileProbeResult = onLastmileProbeResult;
            engineEvent->onLocalUserRegistered = onLocalUserRegistered;
            engineEvent->onUserInfoUpdated = onUserInfoUpdated;
            engineEvent->onLocalAudioStateChanged = onLocalAudioStateChanged;
            engineEvent->onRemoteAudioStateChanged = onRemoteAudioStateChanged;
            engineEvent->onLocalAudioStats = onLocalAudioStats;
            engineEvent->onChannelMediaRelayStateChanged = onChannelMediaRelayStateChanged;
            engineEvent->onChannelMediaRelayEvent = onChannelMediaRelayEvent;
            engineEvent->onFacePositionChanged = onFacePositionChanged;
        }
 
        void CWrapperRtcEngineEventHandler::onJoinChannelSuccess(const char *channel, uid_t userId, int elapsed)
        {
            if (engineEvent->onJoinChannelSuccess == NULL)
                return;

            engineEvent->onJoinChannelSuccess(channel, userId, elapsed);
        }

        void CWrapperRtcEngineEventHandler::onLeaveChannel(const RtcStats &stats)
        {
            if (engineEvent->onLeaveChannel == NULL)
                return;

            engineEvent->onLeaveChannel(stats.duration, stats.txBytes, stats.rxBytes, stats.txAudioBytes, stats.txVideoBytes, stats.rxAudioBytes, stats.rxVideoBytes, stats.txKBitRate, stats.rxKBitRate, stats.rxAudioKBitRate, stats.txAudioKBitRate, stats.rxVideoKBitRate, stats.txVideoKBitRate, stats.lastmileDelay, stats.txPacketLossRate, stats.rxPacketLossRate, stats.userCount, stats.cpuAppUsage, stats.cpuTotalUsage, stats.gatewayRtt, stats.memoryAppUsageRatio, stats.memoryTotalUsageRatio, stats.memoryAppUsageInKbytes);
        }

        void CWrapperRtcEngineEventHandler::onRejoinChannelSuccess(const char *channel, uid_t userId, int elapsed)
        {
            if (engineEvent->onReJoinChannelSuccess == NULL)
                return;

            engineEvent->onReJoinChannelSuccess(channel, userId, elapsed);
        }

        void CWrapperRtcEngineEventHandler::onUserJoined(uid_t userId, int elapsed)
        {
            if (engineEvent->onUserJoined == NULL)
                return;

            engineEvent->onUserJoined(userId, elapsed);
        }

        void CWrapperRtcEngineEventHandler::onClientRoleChanged(CLIENT_ROLE_TYPE oldRole, CLIENT_ROLE_TYPE newRole)
        {
            if (engineEvent->onClientRoleChanged == NULL)
                return;

            engineEvent->onClientRoleChanged((int)oldRole, (int)newRole);
        }

        void CWrapperRtcEngineEventHandler::onUserOffline(uid_t userId, USER_OFFLINE_REASON_TYPE reason)
        {
            if (engineEvent->onUserOffline == NULL)
                return;

            engineEvent->onUserOffline(userId, reason);
        }

        void CWrapperRtcEngineEventHandler::onUserMuteAudio(uid_t userId, bool muted)
        {
            if (engineEvent->onUserMuteAudio == NULL)
                return;

            engineEvent->onUserMuteAudio(userId, muted);
        }

        void CWrapperRtcEngineEventHandler::onFirstRemoteVideoDecoded(uid_t userId, int width, int height, int elapsed)
        {
            if (engineEvent->onFirstRemoteVideoDecoded == NULL)
                return;

            engineEvent->onFirstRemoteVideoDecoded(userId, width, height, elapsed);
        }

        void CWrapperRtcEngineEventHandler::onUserMuteVideo(uid_t userId, bool muted)
        {
            if (engineEvent->onUserMuteVideo == NULL)
                return;

            engineEvent->onUserMuteVideo(userId, muted);
        }

        void CWrapperRtcEngineEventHandler::onAudioRoutingChanged(int routing)
        {
            if (engineEvent->onAudioRouteChanged == NULL)
                return;

            engineEvent->onAudioRouteChanged(routing);
        }

        void CWrapperRtcEngineEventHandler::onConnectionLost()
        {
            if (engineEvent->onConnectionLost == NULL)
                return;

            engineEvent->onConnectionLost();
        }

        void CWrapperRtcEngineEventHandler::onRequestToken()
        {
            if (engineEvent->onRequestToken == NULL)
                return;

            engineEvent->onRequestToken();
        }

        void CWrapperRtcEngineEventHandler::onAudioVolumeIndication(const AudioVolumeInfo *speakers, unsigned int speakerNumber,
                                                                    int totalVolume)
        {
            if (engineEvent->onAudioVolumeIndication == NULL)
                return;

            char szMsg[LENGTH_MAX] = {};
            std::string strPostMsg = "";
            for (int i = 0; i < speakerNumber; i++)
            {
                AudioVolumeInfo *pAVI = (AudioVolumeInfo *)(speakers + i);
                sprintf(szMsg, "%s\t%d\t%d\t%d\t%s", strPostMsg.data(), pAVI->uid, pAVI->volume, pAVI->vad, pAVI->channelId);
                strPostMsg = szMsg;
            }
            sprintf(szMsg, "%s", strPostMsg.data());
            engineEvent->onAudioVolumeIndication(szMsg, speakerNumber, totalVolume);
        }

        void CWrapperRtcEngineEventHandler::onWarning(int warn, const char *msg)
        {
            if (engineEvent->onSDKWarning == NULL)
                return;

            engineEvent->onSDKWarning(warn, msg);
        }

        void CWrapperRtcEngineEventHandler::onError(int err, const char *msg)
        {
            if (engineEvent->onSDKError == NULL)
                return;

            engineEvent->onSDKError(err, msg);
        }
        //
        void CWrapperRtcEngineEventHandler::onRtcStats(const RtcStats &stats)
        {
            if (engineEvent->onRtcStats == NULL)
                return;

            engineEvent->onRtcStats(stats.duration, stats.txBytes, stats.rxBytes, stats.txAudioBytes, stats.txVideoBytes, stats.rxAudioBytes, stats.rxVideoBytes, stats.txKBitRate, stats.rxKBitRate, stats.rxAudioKBitRate, stats.txAudioKBitRate, stats.rxVideoKBitRate, stats.txVideoKBitRate, stats.lastmileDelay, stats.txPacketLossRate, stats.rxPacketLossRate, stats.userCount, stats.cpuAppUsage, stats.cpuTotalUsage , stats.gatewayRtt, stats.memoryAppUsageRatio, stats.memoryTotalUsageRatio, stats.memoryAppUsageInKbytes);
        }
        //
        void CWrapperRtcEngineEventHandler::onAudioMixingFinished()
        {
            if (engineEvent->onAudioMixingFinished == NULL)
                return;

            engineEvent->onAudioMixingFinished();
        }

        void CWrapperRtcEngineEventHandler::onVideoSizeChanged(uid_t userId, int width, int height, int rotation)
        {
            if (engineEvent->onVideoSizeChanged == NULL)
                return;

            engineEvent->onVideoSizeChanged(userId, width, height, rotation);
        }

        void CWrapperRtcEngineEventHandler::onConnectionInterrupted()
        {
            if (engineEvent->onConnectionInterrupted == NULL)
                return;

            engineEvent->onConnectionInterrupted();
        }

        void CWrapperRtcEngineEventHandler::onMicrophoneEnabled(bool enabled)
        {
            if (engineEvent->onMicrophoneEnabled == NULL)
                return;

            engineEvent->onMicrophoneEnabled(enabled);
        }

        void CWrapperRtcEngineEventHandler::onFirstRemoteAudioFrame(uid_t userId, int elapsed)
        {
            if (engineEvent->onFirstRemoteAudioFrame == NULL)
                return;

            engineEvent->onFirstRemoteAudioFrame(userId, elapsed);
        }

        void CWrapperRtcEngineEventHandler::onFirstLocalAudioFrame(int elapsed)
        {
            if (engineEvent->onFirstLocalAudioFrame == NULL)
                return;

            engineEvent->onFirstLocalAudioFrame(elapsed);
        }

        void CWrapperRtcEngineEventHandler::onApiCallExecuted(int err, const char *api, const char *result)
        {
            if (engineEvent->onApiCallExecuted == NULL)
                return;

            engineEvent->onApiCallExecuted(err, api, result);
        }

        void CWrapperRtcEngineEventHandler::onLastmileQuality(int quality)
        {
            if (engineEvent->onLastmileQuality == NULL)
                return;

            engineEvent->onLastmileQuality(quality);
        }

        void CWrapperRtcEngineEventHandler::onLastmileProbeResult(const LastmileProbeResult& result)
        {
            if (engineEvent->onLastmileProbeResult == NULL)
                return;

            engineEvent->onLastmileProbeResult((int)result.state, (unsigned int)result.uplinkReport.packetLossRate, (unsigned int)result.uplinkReport.jitter, (unsigned int)result.uplinkReport.availableBandwidth, (unsigned int)result.downlinkReport.packetLossRate, (unsigned int)result.downlinkReport.jitter, (unsigned int)result.downlinkReport.availableBandwidth, result.rtt);
        }

        void CWrapperRtcEngineEventHandler::onAudioQuality(uid_t userId, int quality, unsigned short delay, unsigned short lost)
        {
            if (engineEvent->onAudioQuality == NULL)
                return;

            engineEvent->onAudioQuality(userId, quality, delay, lost);
        }

        void CWrapperRtcEngineEventHandler::onRemoteVideoTransportStats(
            uid_t uid, unsigned short delay, unsigned short lost,
            unsigned short rxKBitRate)
        {
            if (engineEvent->onRemoteVideoTransportStats == NULL)
                return;

            engineEvent->onRemoteVideoTransportStats(uid, delay, lost, rxKBitRate);
        }

        void CWrapperRtcEngineEventHandler::onRemoteAudioTransportStats(
            uid_t uid, unsigned short delay, unsigned short lost,
            unsigned short rxKBitRate)
        {
            if (engineEvent->onRemoteAudioTransportStats == NULL)
                return;

            engineEvent->onRemoteAudioTransportStats(uid, delay, lost, rxKBitRate);
        }

        void CWrapperRtcEngineEventHandler::onStreamInjectedStatus(const char *url, uid_t userId, int status)
        {
            if (engineEvent->onStreamInjectedStatus == NULL)
                return;

            engineEvent->onStreamInjectedStatus(url, userId, status);
        }

        void CWrapperRtcEngineEventHandler::onTranscodingUpdated()
        {
            if (engineEvent->onTranscodingUpdated == NULL)
                return;

            engineEvent->onTranscodingUpdated();
        }

        void CWrapperRtcEngineEventHandler::onStreamUnpublished(const char *url)
        {
            if (engineEvent->onStreamUnpublished == NULL)
                return;

            engineEvent->onStreamUnpublished(url);
        }

        void CWrapperRtcEngineEventHandler::onStreamPublished(const char *url, int error)
        {
            if (engineEvent->onStreamPublished == NULL)
                return;

            engineEvent->onStreamPublished(url, error);
        }

        void CWrapperRtcEngineEventHandler::onAudioDeviceVolumeChanged(MEDIA_DEVICE_TYPE deviceType, int volume, bool muted)
        {
            if (engineEvent->onAudioDeviceVolumeChanged == NULL)
                return;

            engineEvent->onAudioDeviceVolumeChanged((int)deviceType, volume, muted);
        }

        void CWrapperRtcEngineEventHandler::onActiveSpeaker(uid_t userId)
        {
            if (engineEvent->onActiveSpeaker == NULL)
                return;

            engineEvent->onActiveSpeaker(userId);
        }

        void CWrapperRtcEngineEventHandler::onMediaEngineStartCallSuccess()
        {
            if (engineEvent->onMediaEngineStartCallSuccess == NULL)
                return;

            engineEvent->onMediaEngineStartCallSuccess();
        }

        void CWrapperRtcEngineEventHandler::onMediaEngineLoadSuccess()
        {
            if (engineEvent->onMediaEngineLoadSuccess == NULL)
                return;

            engineEvent->onMediaEngineLoadSuccess();
        }

        void CWrapperRtcEngineEventHandler::onStreamMessageError(uid_t userId, int streamId, int code, int missed, int cached)
        {
            if (engineEvent->onStreamMessageError == NULL)
                return;

            engineEvent->onStreamMessageError(userId, streamId, code, missed, cached);
        }

        void CWrapperRtcEngineEventHandler::onStreamMessage(uid_t userId, int streamId, const char *data, size_t length)
        {
            if (engineEvent->onStreamMessage == NULL)
                return;

            engineEvent->onStreamMessage(userId, streamId, data, length);
        }

        void CWrapperRtcEngineEventHandler::onConnectionBanned()
        {
            if (engineEvent->onConnectionBanned == NULL)
                return;

            engineEvent->onConnectionBanned();
        }

        void CWrapperRtcEngineEventHandler::onVideoStopped()
        {
            if (engineEvent->onVideoStopped == NULL)
                return;

            engineEvent->onVideoStopped();
        }

        void CWrapperRtcEngineEventHandler::onTokenPrivilegeWillExpire(const char* token)
        {
            if (engineEvent->onTokenPrivilegeWillExpire == NULL)
                return;

            engineEvent->onTokenPrivilegeWillExpire(token);
        }

        void CWrapperRtcEngineEventHandler::onNetworkQuality(uid_t uid, int txQuality, int rxQuality)
        {
            if (engineEvent->onNetworkQuality == NULL)
                return;

            engineEvent->onNetworkQuality(uid, txQuality, rxQuality);
        }

        void CWrapperRtcEngineEventHandler::onLocalVideoStats(const LocalVideoStats& stats)
        {
            if (engineEvent->onLocalVideoStats == NULL)
                return;

            engineEvent->onLocalVideoStats(stats.sentBitrate, stats.sentFrameRate, stats.encoderOutputFrameRate, stats.rendererOutputFrameRate, stats.targetBitrate, stats.targetFrameRate, (int)stats.qualityAdaptIndication, stats.encodedBitrate, stats.encodedFrameWidth, stats.encodedFrameHeight, stats.encodedFrameCount, (int)stats.codecType);
        }

        void CWrapperRtcEngineEventHandler::onRemoteVideoStats(const RemoteVideoStats& stats)
        {
            if (engineEvent->onRemoteVideoStats == NULL)
                return;

            engineEvent->onRemoteVideoStats(stats.uid, stats.delay, stats.width, stats.height, stats.receivedBitrate, stats.decoderOutputFrameRate, stats.rendererOutputFrameRate, stats.packetLossRate, (int)stats.rxStreamType, stats.totalFrozenTime, stats.frozenRate, stats.totalActiveTime);
        }

        void CWrapperRtcEngineEventHandler::onRemoteAudioStats(const RemoteAudioStats& stats)
        {
            if (engineEvent->onRemoteAudioStats == NULL)
                return;

            engineEvent->onRemoteAudioStats(stats.uid, stats.quality, stats.networkTransportDelay, stats.jitterBufferDelay, stats.audioLossRate, stats.numChannels, stats.receivedSampleRate, stats.receivedBitrate, stats.totalFrozenTime, stats.frozenRate, stats.totalActiveTime);
        }

        void CWrapperRtcEngineEventHandler::onFirstLocalVideoFrame(int width, int height, int elapsed)
        {
            if (engineEvent->onFirstLocalVideoFrame == NULL)
                return;

            engineEvent->onFirstLocalVideoFrame(width, height, elapsed);
        }

        void CWrapperRtcEngineEventHandler::onFirstRemoteVideoFrame(uid_t uid, int width, int height, int elapsed)
        {
            if (engineEvent->onFirstRemoteVideoFrame == NULL)
                return;

            engineEvent->onFirstRemoteVideoFrame(uid, width, height, elapsed);
        }

        void CWrapperRtcEngineEventHandler::onUserEnableVideo(uid_t uid, bool enabled)
        {
            if (engineEvent->onUserEnableVideo == NULL)
                return;

            engineEvent->onUserEnableVideo(uid, enabled);
        }

        void CWrapperRtcEngineEventHandler::onAudioDeviceStateChanged(const char* deviceId, int deviceType, int deviceState)
        {
            if (engineEvent->onAudioDeviceStateChanged == NULL)
                return;

            engineEvent->onAudioDeviceStateChanged(deviceId, deviceType, deviceState);
        }

        void CWrapperRtcEngineEventHandler::onCameraReady()
        {
            if (engineEvent->onCameraReady == NULL)
                return;

            engineEvent->onCameraReady();
        }

        void CWrapperRtcEngineEventHandler::onCameraFocusAreaChanged(int x, int y, int width, int height)
        {
            if (engineEvent->onCameraFocusAreaChanged == NULL)
                return;

            engineEvent->onCameraFocusAreaChanged(x, y, width, height);
        }

        void CWrapperRtcEngineEventHandler::onCameraExposureAreaChanged(int x, int y, int width, int height)
        {
            if (engineEvent->onCameraExposureAreaChanged == NULL)
                return;

            engineEvent->onCameraExposureAreaChanged(x, y, width, height);
        }

        void CWrapperRtcEngineEventHandler::onRemoteAudioMixingBegin()
        {
            if (engineEvent->onRemoteAudioMixingBegin == NULL)
                return;

            engineEvent->onRemoteAudioMixingBegin();
        }

        void CWrapperRtcEngineEventHandler::onRemoteAudioMixingEnd()
        {
            if (engineEvent->onRemoteAudioMixingEnd == NULL)
                return;

            engineEvent->onRemoteAudioMixingEnd();
        }

        void CWrapperRtcEngineEventHandler::onAudioEffectFinished(int soundId)
        {
            if (engineEvent->onAudioEffectFinished == NULL)
                return;

            engineEvent->onAudioEffectFinished(soundId);
        }

        void CWrapperRtcEngineEventHandler::onVideoDeviceStateChanged(const char* deviceId, int deviceType, int deviceState)
        {
            if (engineEvent->onVideoDeviceStateChanged == NULL)
                return;

            engineEvent->onVideoDeviceStateChanged(deviceId, deviceType, deviceState);
        }

        void CWrapperRtcEngineEventHandler::onRemoteVideoStateChanged(uid_t uid, REMOTE_VIDEO_STATE state, REMOTE_VIDEO_STATE_REASON reason, int elapsed)
        {
            if (engineEvent->onRemoteVideoStateChanged == NULL)
                return;

            engineEvent->onRemoteVideoStateChanged(uid, (int)state, (int)reason, elapsed);
        }

        void CWrapperRtcEngineEventHandler::onUserEnableLocalVideo(uid_t uid, bool enabled)
        {
            if (engineEvent->onUserEnableLocalVideo == NULL)
                return;

            engineEvent->onUserEnableLocalVideo(uid, enabled);
        }

        void CWrapperRtcEngineEventHandler::onLocalPublishFallbackToAudioOnly(bool isFallbackOrRecover)
        {
            if (engineEvent->onLocalPublishFallbackToAudioOnly == NULL)
                return;

            engineEvent->onLocalPublishFallbackToAudioOnly(isFallbackOrRecover);
        }

        void CWrapperRtcEngineEventHandler::onRemoteSubscribeFallbackToAudioOnly(uid_t uid, bool isFallbackOrRecover)
        {
            if (engineEvent->onRemoteSubscribeFallbackToAudioOnly == NULL)
                return;

            engineEvent->onRemoteSubscribeFallbackToAudioOnly (uid, isFallbackOrRecover);
        }

        void CWrapperRtcEngineEventHandler::onConnectionStateChanged(CONNECTION_STATE_TYPE state, CONNECTION_CHANGED_REASON_TYPE reason)
        {
            if (engineEvent->onConnectionStateChanged == NULL)
                return;

            engineEvent->onConnectionStateChanged((int)state, (int)reason);
        }

        void CWrapperRtcEngineEventHandler::onAudioMixingStateChanged(AUDIO_MIXING_STATE_TYPE state, AUDIO_MIXING_ERROR_TYPE errorCode)
        {
            if (engineEvent->onAudioMixingStateChanged == NULL)
                return;

            engineEvent->onAudioMixingStateChanged((int)state, (int)errorCode);
        }

        void CWrapperRtcEngineEventHandler::onFirstRemoteAudioDecoded(uid_t uid, int elapsed)
        {
            if (engineEvent->onFirstRemoteAudioDecoded == NULL)
                return;

            engineEvent->onFirstRemoteAudioDecoded(uid, elapsed);
        }

        void CWrapperRtcEngineEventHandler::onLocalVideoStateChanged(int localVideoState, int error)
        {
            if (engineEvent->onLocalVideoStateChanged == NULL)
                return;

            engineEvent->onLocalVideoStateChanged(localVideoState, error);
        }

        void CWrapperRtcEngineEventHandler::onRtmpStreamingStateChanged(const char *url, RTMP_STREAM_PUBLISH_STATE state, RTMP_STREAM_PUBLISH_ERROR_TYPE errCode)
        {
            if (engineEvent->onRtmpStreamingStateChanged == NULL)
                return;

            engineEvent->onRtmpStreamingStateChanged(url, (int)state, (int)errCode);
        }

        void CWrapperRtcEngineEventHandler::onNetworkTypeChanged(NETWORK_TYPE type)
        {
            if (engineEvent->onNetworkTypeChanged == NULL)
                return;

            engineEvent->onNetworkTypeChanged((int)type);
        }

        void CWrapperRtcEngineEventHandler::onLocalUserRegistered(uid_t uid, const char* userAccount)
        {
            if (engineEvent->onLocalUserRegistered == NULL)
                return;

            engineEvent->onLocalUserRegistered(uid, (char *)userAccount);
        }

        void CWrapperRtcEngineEventHandler::onUserInfoUpdated(uid_t uid, const UserInfo& info)
        {
            if (engineEvent->onUserInfoUpdated == NULL)
                return;

            engineEvent->onUserInfoUpdated(uid, info.uid, (char *)info.userAccount);
        }

        void CWrapperRtcEngineEventHandler::onLocalAudioStateChanged(LOCAL_AUDIO_STREAM_STATE state, LOCAL_AUDIO_STREAM_ERROR error)
        {
            if (engineEvent->onLocalAudioStateChanged == NULL)
                return;

            engineEvent->onLocalAudioStateChanged((int)state, (int)error);
        }

        void CWrapperRtcEngineEventHandler::onRemoteAudioStateChanged(uid_t uid, REMOTE_AUDIO_STATE state, REMOTE_AUDIO_STATE_REASON reason, int elapsed)
        {
            if (engineEvent->onRemoteAudioStateChanged == NULL)
                return;

            engineEvent->onRemoteAudioStateChanged(uid, (int)state, (int)reason, elapsed);
        }

        void CWrapperRtcEngineEventHandler::onLocalAudioStats(const LocalAudioStats& stats)
        {
            if (engineEvent->onLocalAudioStats == NULL)
                return;

            engineEvent->onLocalAudioStats(stats.numChannels, stats.sentSampleRate, stats.sentBitrate);
        }

        void CWrapperRtcEngineEventHandler::onChannelMediaRelayStateChanged(CHANNEL_MEDIA_RELAY_STATE state,CHANNEL_MEDIA_RELAY_ERROR code)
        {
            if (engineEvent->onChannelMediaRelayStateChanged == NULL)
                return;

            engineEvent->onChannelMediaRelayStateChanged((int)state, (int)code);
        }

        void CWrapperRtcEngineEventHandler::onChannelMediaRelayEvent(CHANNEL_MEDIA_RELAY_EVENT code)
        {
            if (engineEvent->onChannelMediaRelayEvent == NULL)
                return;

            engineEvent->onChannelMediaRelayEvent((int)code);
        }

        void CWrapperRtcEngineEventHandler::onFacePositionChanged(int imageWidth, int imageHeight, Rectangle* vecRectangle, int* vecDistance, int numFaces)
        {
            if (engineEvent->onFacePositionChanged == NULL)
                return;

            if (vecRectangle == NULL || vecDistance == NULL || numFaces == 0) {
                engineEvent->onFacePositionChanged(imageWidth, imageHeight, 0, 0, 0, 0, 0, 0);
            } 
            else
            {
               engineEvent->onFacePositionChanged(imageWidth, imageHeight, vecRectangle->x, vecRectangle->y, vecRectangle->width, vecRectangle->height, *vecDistance, numFaces); 
            }  
        }
    }
}
