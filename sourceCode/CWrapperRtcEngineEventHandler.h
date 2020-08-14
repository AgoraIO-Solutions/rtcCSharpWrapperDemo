#ifndef CWRAPPER_RTC_ENGINE_EVENT_HANDLER
#define CWRAPPER_RTC_ENGINE_EVENT_HANDLER
#include <string>
#include "common_header.h"
#define LENGTH_MAX 255


namespace agora
{
  namespace unity
  {
    class EngineEvent
    {
    public:
      FUNC_OnJoinChannelSuccess onJoinChannelSuccess = NULL;
      FUNC_OnReJoinChannelSuccess onReJoinChannelSuccess = NULL;
      FUNC_OnLeaveChannel onLeaveChannel = NULL;
      FUNC_OnConnectionLost onConnectionLost = NULL;
      FUNC_OnConnectionInterrupted onConnectionInterrupted = NULL;
      FUNC_OnRequestToken onRequestToken = NULL;
      FUNC_OnUserJoined onUserJoined = NULL;
      FUNC_OnUserOffline onUserOffline = NULL;
      FUNC_OnAudioVolumeIndication onAudioVolumeIndication = NULL;
      FUNC_OnUserMuteAudio onUserMuteAudio = NULL;
      FUNC_OnSDKWarning onSDKWarning = NULL;
      FUNC_OnSDKError onSDKError = NULL;
      FUNC_OnRtcStats onRtcStats = NULL;
      FUNC_OnAudioMixingFinished onAudioMixingFinished = NULL;
      FUNC_OnAudioRouteChanged onAudioRouteChanged = NULL;
      FUNC_OnFirstRemoteVideoDecoded onFirstRemoteVideoDecoded = NULL;
      FUNC_OnVideoSizeChanged onVideoSizeChanged = NULL;
      FUNC_OnClientRoleChanged onClientRoleChanged = NULL;
      FUNC_OnUserMuteVideo onUserMuteVideo = NULL;
      FUNC_OnMicrophoneEnabled onMicrophoneEnabled = NULL;
      FUNC_OnApiExecuted onApiCallExecuted = NULL;
      FUNC_OnFirstLocalAudioFrame onFirstLocalAudioFrame = NULL;
      FUNC_OnFirstRemoteAudioFrame onFirstRemoteAudioFrame = NULL;
      FUNC_OnLastmileQuality onLastmileQuality = NULL;
      FUNC_OnAudioQuality onAudioQuality = NULL;
      FUNC_OnStreamInjectedStatus onStreamInjectedStatus = NULL;
      FUNC_OnStreamUnpublished onStreamUnpublished = NULL;
      FUNC_OnStreamPublished onStreamPublished = NULL;
      FUNC_OnStreamMessageError onStreamMessageError = NULL;
      FUNC_OnStreamMessage onStreamMessage = NULL;
      FUNC_OnConnectionBanned onConnectionBanned = NULL;
      FUNC_OnRemoteVideoTransportStats onRemoteVideoTransportStats = NULL;
      FUNC_OnRemoteAudioTransportStats onRemoteAudioTransportStats = NULL;
      FUNC_OnTranscodingUpdated onTranscodingUpdated = NULL;
      FUNC_OnAudioDeviceVolumeChanged onAudioDeviceVolumeChanged = NULL;
      FUNC_OnActiveSpeaker onActiveSpeaker = NULL;
      FUNC_OnMediaEngineStartCallSuccess onMediaEngineStartCallSuccess = NULL;
      FUNC_OnMediaEngineLoadSuccess onMediaEngineLoadSuccess = NULL;
      FUNC_OnConnectionStateChanged onConnectionStateChanged = NULL;
      FUNC_OnRemoteSubscribeFallbackToAudioOnly onRemoteSubscribeFallbackToAudioOnly = NULL;
      FUNC_OnLocalPublishFallbackToAudioOnly onLocalPublishFallbackToAudioOnly = NULL;
      FUNC_OnUserEnableLocalVideo onUserEnableLocalVideo = NULL;
      FUNC_OnRemoteVideoStateChanged onRemoteVideoStateChanged = NULL;
      FUNC_OnVideoDeviceStateChanged onVideoDeviceStateChanged = NULL;
      FUNC_OnAudioEffectFinished onAudioEffectFinished = NULL;
      FUNC_OnRemoteAudioMixingEnd onRemoteAudioMixingEnd = NULL;
      FUNC_OnRemoteAudioMixingBegin onRemoteAudioMixingBegin = NULL;
      FUNC_OnCameraExposureAreaChanged onCameraExposureAreaChanged = NULL;
      FUNC_OnCameraFocusAreaChanged onCameraFocusAreaChanged = NULL;
      FUNC_OnCameraReady onCameraReady = NULL;
      FUNC_OnAudioDeviceStateChanged onAudioDeviceStateChanged = NULL;
      FUNC_OnUserEnableVideo onUserEnableVideo = NULL;
      FUNC_OnFirstRemoteVideoFrame onFirstRemoteVideoFrame = NULL;
      FUNC_OnFirstLocalVideoFrame onFirstLocalVideoFrame = NULL;
      FUNC_OnRemoteAudioStats onRemoteAudioStats = NULL;
      FUNC_OnRemoteVideoStats onRemoteVideoStats = NULL;
      FUNC_OnLocalVideoStats onLocalVideoStats = NULL;
      FUNC_OnNetworkQuality onNetworkQuality = NULL;
      FUNC_OnTokenPrivilegeWillExpire onTokenPrivilegeWillExpire = NULL;
      FUNC_OnVideoStopped onVideoStopped = NULL;
      FUNC_OnAudioMixingStateChanged onAudioMixingStateChanged = NULL;
      FUNC_OnFirstRemoteAudioDecoded onFirstRemoteAudioDecoded = NULL;
      FUNC_OnLocalVideoStateChanged onLocalVideoStateChanged = NULL;
      FUNC_OnNetworkTypeChanged onNetworkTypeChanged = NULL;
      FUNC_OnRtmpStreamingStateChanged onRtmpStreamingStateChanged = NULL;
      FUNC_OnLastmileProbeResult onLastmileProbeResult = NULL;
      FUNC_OnLocalUserRegistered onLocalUserRegistered = NULL;
      FUNC_OnUserInfoUpdated onUserInfoUpdated = NULL;
      FUNC_OnLocalAudioStateChanged onLocalAudioStateChanged = NULL;
      FUNC_OnRemoteAudioStateChanged onRemoteAudioStateChanged = NULL;
      FUNC_OnLocalAudioStats onLocalAudioStats = NULL;
      FUNC_OnChannelMediaRelayStateChanged onChannelMediaRelayStateChanged = NULL;
      FUNC_OnChannelMediaRelayEvent onChannelMediaRelayEvent = NULL;
      FUNC_OnFacePositionChanged onFacePositionChanged = NULL;

      void reset ()
      {
        onJoinChannelSuccess = NULL;
        onReJoinChannelSuccess = NULL;
        onLeaveChannel = NULL;
        onConnectionLost = NULL;
        onConnectionInterrupted = NULL;
        onRequestToken = NULL;
        onUserJoined = NULL;
        onUserOffline = NULL;
        onAudioVolumeIndication = NULL;
        onUserMuteAudio = NULL;
        onSDKWarning = NULL;
        onSDKError = NULL;
        onRtcStats = NULL;
        onAudioMixingFinished = NULL;
        onAudioRouteChanged = NULL;
        onFirstRemoteVideoDecoded = NULL;
        onVideoSizeChanged = NULL;
        onClientRoleChanged = NULL;
        onUserMuteVideo = NULL;
        onMicrophoneEnabled = NULL;
        onApiCallExecuted = NULL;
        onFirstLocalAudioFrame = NULL;
        onFirstRemoteAudioFrame = NULL;
        onLastmileQuality = NULL;
        onAudioQuality = NULL;
        onStreamInjectedStatus = NULL;
        onStreamUnpublished = NULL;
        onStreamPublished = NULL;
        onStreamMessageError = NULL;
        onStreamMessage = NULL;
        onConnectionBanned = NULL;
        onRemoteVideoTransportStats = NULL;
        onRemoteAudioTransportStats = NULL;
        onTranscodingUpdated = NULL;
        onAudioDeviceVolumeChanged = NULL;
        onActiveSpeaker = NULL;
        onMediaEngineStartCallSuccess = NULL;
        onMediaEngineLoadSuccess = NULL;
        onConnectionStateChanged = NULL;
        onRemoteSubscribeFallbackToAudioOnly = NULL;
        onLocalPublishFallbackToAudioOnly = NULL;
        onUserEnableLocalVideo = NULL;
        onRemoteVideoStateChanged = NULL;
        onVideoDeviceStateChanged = NULL;
        onAudioEffectFinished = NULL;
        onRemoteAudioMixingEnd = NULL;
        onRemoteAudioMixingBegin = NULL;
        onCameraExposureAreaChanged = NULL;
        onCameraFocusAreaChanged = NULL;
        onCameraReady = NULL;
        onAudioDeviceStateChanged = NULL;
        onUserEnableVideo = NULL;
        onFirstRemoteVideoFrame = NULL;
        onFirstLocalVideoFrame = NULL;
        onRemoteAudioStats = NULL;
        onRemoteVideoStats = NULL;
        onLocalVideoStats = NULL;
        onNetworkQuality = NULL;
        onTokenPrivilegeWillExpire = NULL;
        onVideoStopped = NULL;
        onAudioMixingStateChanged = NULL;
        onFirstRemoteAudioDecoded = NULL;
        onLocalVideoStateChanged = NULL;
        onNetworkTypeChanged = NULL;
        onRtmpStreamingStateChanged = NULL;
        onLastmileProbeResult = NULL;
        onLocalUserRegistered = NULL;
        onUserInfoUpdated = NULL;
        onLocalAudioStateChanged = NULL;
        onRemoteAudioStateChanged = NULL;
        onLocalAudioStats = NULL;
        onChannelMediaRelayStateChanged = NULL;
        onChannelMediaRelayEvent = NULL; 
        onFacePositionChanged = NULL;
      }
    };

    class CWrapperRtcEngineEventHandler : public IRtcEngineEventHandler
    {
    private:
      EngineEvent *engineEvent = nullptr;
      const char *TAG = "CWrapperRtcEngineEventHandler";

    public:
      CWrapperRtcEngineEventHandler();
      ~CWrapperRtcEngineEventHandler();

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
                                      FUNC_OnFacePositionChanged onFacePositionChanged);


      void onJoinChannelSuccess(const char *channel, uid_t userId, int elapsed);

      void onLeaveChannel(const RtcStats &stats);

      void onRejoinChannelSuccess(const char *channel, uid_t userId, int elapsed);

      void onUserJoined(uid_t userId, int elapsed);

      void onClientRoleChanged(CLIENT_ROLE_TYPE oldRole, CLIENT_ROLE_TYPE newRole);

      void onUserOffline(uid_t userId, USER_OFFLINE_REASON_TYPE reason);

      void onUserMuteAudio(uid_t userId, bool muted);

      void onFirstRemoteVideoDecoded(uid_t userId, int width, int height, int elapsed);

      void onUserMuteVideo(uid_t userId, bool muted);

      void onAudioRoutingChanged(int routing);

      void onConnectionLost();

      void onRequestToken();

      void onAudioVolumeIndication(const AudioVolumeInfo *speakers, unsigned int speakerNumber,
                                  int totalVolume);

      void onWarning(int warn, const char *msg);

      void onError(int err, const char *msg);
      //
      void onRtcStats(const RtcStats &stats);
      //
      void onAudioMixingFinished();

      void onVideoSizeChanged(uid_t userId, int width, int height, int rotation);

      void onConnectionInterrupted();

      void onMicrophoneEnabled(bool enabled);

      void onAudioQuality(uid_t userId, int quality, unsigned short delay, unsigned short lost);

      void onRemoteVideoTransportStats(uid_t uid, unsigned short delay, unsigned short lost, unsigned short rxKBitRate);
      
      void onRemoteAudioTransportStats(uid_t uid, unsigned short delay, unsigned short lost, unsigned short rxKBitRate);

      void onStreamInjectedStatus(const char *url, uid_t userId, int status);

      void onTranscodingUpdated();

      void onStreamUnpublished(const char *url);

      void onStreamPublished(const char *url, int error);

      void onAudioDeviceVolumeChanged(MEDIA_DEVICE_TYPE deviceType, int volume, bool muted);

      void onActiveSpeaker(uid_t userId);

      void onFirstRemoteAudioFrame(uid_t userId, int elapsed);

      void onFirstLocalAudioFrame(int elapsed);

      void onMediaEngineStartCallSuccess();

      void onMediaEngineLoadSuccess();

      void onStreamMessageError(uid_t userId, int streamId, int code, int missed, int cached);

      void onStreamMessage(uid_t userId, int streamId, const char *data, size_t length);

      void onConnectionBanned();

      void onLastmileQuality(int quality);

      void onVideoStopped();

      void onApiCallExecuted(int err, const char *api, const char *result);

      void onTokenPrivilegeWillExpire(const char* token);

      void onNetworkQuality(uid_t uid, int txQuality, int rxQuality);

      void onLocalVideoStats(const LocalVideoStats& stats);

      void onRemoteVideoStats(const RemoteVideoStats& stats);

      void onRemoteAudioStats(const RemoteAudioStats& stats);
      
      void onFirstLocalVideoFrame(int width, int height, int elapsed);

      void onFirstRemoteVideoFrame(uid_t uid, int width, int height, int elapsed);

      void onUserEnableVideo(uid_t uid, bool enabled);

      void onAudioDeviceStateChanged(const char* deviceId, int deviceType, int deviceState);

      void onCameraReady();

      void onCameraFocusAreaChanged(int x, int y, int width, int height);

      void onCameraExposureAreaChanged(int x, int y, int width, int height);

      void onRemoteAudioMixingBegin();

      void onRemoteAudioMixingEnd();

      void onAudioEffectFinished(int soundId);
    
      void onVideoDeviceStateChanged(const char* deviceId, int deviceType, int deviceState);

      void onRemoteVideoStateChanged(uid_t uid, REMOTE_VIDEO_STATE state, REMOTE_VIDEO_STATE_REASON reason, int elapsed);

      void onUserEnableLocalVideo(uid_t uid, bool enabled);
      
      void onLocalPublishFallbackToAudioOnly(bool isFallbackOrRecover);
    
      void onRemoteSubscribeFallbackToAudioOnly(uid_t uid, bool isFallbackOrRecover);

      void onConnectionStateChanged(CONNECTION_STATE_TYPE state, CONNECTION_CHANGED_REASON_TYPE reason);

      void onAudioMixingStateChanged(AUDIO_MIXING_STATE_TYPE state, AUDIO_MIXING_ERROR_TYPE errorCode);

      void onFirstRemoteAudioDecoded(uid_t uid, int elapsed);

      void onLocalVideoStateChanged(int localVideoState, int error);

      void onRtmpStreamingStateChanged(const char *url, RTMP_STREAM_PUBLISH_STATE state, RTMP_STREAM_PUBLISH_ERROR errCode);

      void onNetworkTypeChanged(NETWORK_TYPE type);

      void onLastmileProbeResult(const LastmileProbeResult& result);

      void onLocalUserRegistered(uid_t uid, const char* userAccount);

      void onUserInfoUpdated(uid_t uid, const UserInfo& info);

      void onLocalAudioStateChanged(LOCAL_AUDIO_STREAM_STATE state, LOCAL_AUDIO_STREAM_ERROR error);

      void onRemoteAudioStateChanged(uid_t uid, REMOTE_AUDIO_STATE state, REMOTE_AUDIO_STATE_REASON reason, int elapsed);

      void onLocalAudioStats(const LocalAudioStats& stats);

      void onChannelMediaRelayStateChanged(CHANNEL_MEDIA_RELAY_STATE state,CHANNEL_MEDIA_RELAY_ERROR code);

      void onChannelMediaRelayEvent(CHANNEL_MEDIA_RELAY_EVENT code);

      void onFacePositionChanged(int imageWidth, int imageHeight, Rectangle* vecRectangle, int* vecDistance, int numFaces);
    };
  }
}

#endif