#ifndef AGORA_CHANNEL_EVENT_HANDLER_H
#define AGORA_CHANNEL_EVENT_HANDLER_H

#include "common_header.h"

namespace agora 
{
    namespace unity 
    {

        class ChannelEngineEvent 
        {
        public:
            FUNC_OnChannelWarning onWarning = NULL;
            FUNC_OnChannelError onError = NULL;
            FUNC_OnChannelJoinChannelSuccess onJoinChannelSuccess = NULL;
            FUNC_OnChannelReJoinChannelSuccess  onRejoinChannelSuccess = NULL;
            FUNC_OnChannelLeaveChannel onLeaveChannel = NULL;
            FUNC_OnChannelClientRoleChanged onClientRoleChanged = NULL;
            FUNC_OnChannelUserJoined onUserJoined = NULL;
            FUNC_OnChannelUserOffLine onUserOffLine = NULL;
            FUNC_OnChannelConnectionLost onConnectionLost = NULL;
            FUNC_OnChannelRequestToken onRequestToken = NULL;
            FUNC_OnChannelTokenPrivilegeWillExpire onTokenPrivilegeWillExpire = NULL;
            FUNC_OnChannelRtcStats onRtcStats = NULL;
            FUNC_OnChannelNetworkQuality onNetworkQuality = NULL;
            FUNC_OnChannelRemoteVideoStats onRemoteVideoStats = NULL;
            FUNC_OnChannelRemoteAudioStats onRemoteAudioStats = NULL;
            FUNC_OnChannelRemoteAudioStateChanged onRemoteAudioStateChanged = NULL;
            FUNC_OnChannelActiveSpeaker onActiveSpeaker = NULL;           
            FUNC_OnChannelVideoSizeChanged onVideoSizeChanged = NULL;
            FUNC_OnChannelRemoteVideoStateChanged onRemoteVideoStateChanged = NULL;
            FUNC_OnChannelStreamMessage onStreamMessage = NULL;
            FUNC_OnChannelStreamMessageError onStreamMessageError = NULL;
            FUNC_OnChannelMediaRelayStateChanged2 onMediaRelayStateChanged = NULL;
            FUNC_OnChannelMediaRelayEvent2 onMediaRelayEvent = NULL;
            FUNC_OnChannelRtmpStreamingStateChanged onRtmpStreamingStateChanged = NULL;
            FUNC_OnChannelTranscodingUpdated onTranscodingUpdated = NULL;
            FUNC_OnChannelStreamInjectedStatus onStreamInjectedStatus = NULL;
            FUNC_OnChannelRemoteSubscribeFallbackToAudioOnly onRemoteSubscribeFallbackToAudioOnly = NULL;
            FUNC_OnChannelConnectionStateChanged onConnectionStateChanged = NULL;
            FUNC_OnChannelLocalPublishFallbackToAudioOnly onLocalPublishFallbackToAudioOnly = NULL;

            void reset() 
            {
                onWarning = NULL;
                onError = NULL;
                onJoinChannelSuccess = NULL;
                onRejoinChannelSuccess = NULL;
                onLeaveChannel = NULL;
                onClientRoleChanged = NULL;
                onUserJoined = NULL;
                onUserOffLine = NULL;
                onConnectionLost = NULL;
                onRequestToken = NULL;
                onTokenPrivilegeWillExpire = NULL;
                onRtcStats = NULL;
                onNetworkQuality = NULL;
                onRemoteVideoStats = NULL;
                onRemoteAudioStats = NULL;
                onRemoteAudioStateChanged = NULL;
                onActiveSpeaker = NULL;           
                onVideoSizeChanged = NULL;
                onRemoteVideoStateChanged = NULL;
                onStreamMessage = NULL;
                onStreamMessageError = NULL;
                onMediaRelayStateChanged = NULL;
                onMediaRelayEvent = NULL;
                onRtmpStreamingStateChanged = NULL;
                onTranscodingUpdated = NULL;
                onStreamInjectedStatus = NULL;
                onRemoteSubscribeFallbackToAudioOnly = NULL;
                onConnectionStateChanged = NULL;
                onLocalPublishFallbackToAudioOnly = NULL;
            }
        };

        class ChannelEventHandler : public IChannelEventHandler 
        {
        private:
            std::string _channelId;
            ChannelEngineEvent *_engineEvent = NULL;
        public:
            ChannelEventHandler(const char *channelId);
            ~ChannelEventHandler();

            void initChannelEventCallback(FUNC_OnChannelWarning onWarning,
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
                                        FUNC_OnChannelLocalPublishFallbackToAudioOnly onLocalPublishFallbackToAudioOnly);
            
            virtual void onChannelWarning(IChannel *rtcChannel, int warn, const char* msg) override;
            
            virtual void onChannelError(IChannel *rtcChannel, int err, const char* msg) override;
            
            virtual void onJoinChannelSuccess(IChannel *rtcChannel, uid_t uid, int elapsed) override;
            
            virtual void onRejoinChannelSuccess(IChannel *rtcChannel, uid_t uid, int elapsed) override;

            virtual void onLeaveChannel(IChannel *rtcChannel, const RtcStats& stats) override;
            
            virtual void onClientRoleChanged(IChannel *rtcChannel, CLIENT_ROLE_TYPE oldRole, CLIENT_ROLE_TYPE newRole) override;
            
            virtual void onUserJoined(IChannel *rtcChannel, uid_t uid, int elapsed) override;
            
            virtual void onUserOffline(IChannel *rtcChannel, uid_t uid, USER_OFFLINE_REASON_TYPE reason) override;
            
            virtual void onConnectionLost(IChannel *rtcChannel) override;
            
            virtual void onRequestToken(IChannel *rtcChannel) override;
            
            virtual void onTokenPrivilegeWillExpire(IChannel *rtcChannel, const char* token) override;
            
            virtual void onRtcStats(IChannel *rtcChannel, const RtcStats& stats) override;
            
            virtual void onNetworkQuality(IChannel *rtcChannel, uid_t uid, int txQuality, int rxQuality) override;
            
            virtual void onRemoteVideoStats(IChannel *rtcChannel, const RemoteVideoStats& stats) override;
            
            virtual void onRemoteAudioStats(IChannel *rtcChannel, const RemoteAudioStats& stats) override;

            virtual void onRemoteAudioStateChanged(IChannel *rtcChannel, uid_t uid, REMOTE_AUDIO_STATE state, REMOTE_AUDIO_STATE_REASON reason, int elapsed) override;
            
            virtual void onActiveSpeaker(IChannel *rtcChannel, uid_t uid) override;
                
            virtual void onVideoSizeChanged(IChannel *rtcChannel, uid_t uid, int width, int height, int rotation) override;
            
            virtual void onRemoteVideoStateChanged(IChannel *rtcChannel, uid_t uid, REMOTE_VIDEO_STATE state, REMOTE_VIDEO_STATE_REASON reason, int elapsed) override;
            
            virtual void onStreamMessage(IChannel *rtcChannel, uid_t uid, int streamId, const char* data, size_t length) override;
            
            virtual void onStreamMessageError(IChannel *rtcChannel, uid_t uid, int streamId, int code, int missed, int cached) override;
            
            virtual void onChannelMediaRelayStateChanged(IChannel *rtcChannel, CHANNEL_MEDIA_RELAY_STATE state,CHANNEL_MEDIA_RELAY_ERROR code) override;
            
            virtual void onChannelMediaRelayEvent(IChannel *rtcChannel, CHANNEL_MEDIA_RELAY_EVENT code) override;

            virtual void onRtmpStreamingStateChanged(IChannel *rtcChannel, const char *url, RTMP_STREAM_PUBLISH_STATE state, RTMP_STREAM_PUBLISH_ERROR_TYPE errCode) override;
                
            virtual void onTranscodingUpdated(IChannel *rtcChannel) override;
            
            virtual void onStreamInjectedStatus(IChannel *rtcChannel, const char* url, uid_t uid, int status) override;
            
            virtual void onRemoteSubscribeFallbackToAudioOnly(IChannel *rtcChannel, uid_t uid, bool isFallbackOrRecover) override;
            
            virtual void onConnectionStateChanged(IChannel *rtcChannel,
                                                CONNECTION_STATE_TYPE state,
                                                CONNECTION_CHANGED_REASON_TYPE reason) override;

            virtual void onLocalPublishFallbackToAudioOnly(IChannel *rtcChannel, bool isFallbackOrRecover) override;
        };
    }
}
#endif