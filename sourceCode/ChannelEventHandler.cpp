#include "ChannelEventHandler.h"

namespace agora {
    namespace unity {

            ChannelEventHandler::ChannelEventHandler(const char* channelId) 
            {
                _channelId = (char *)channelId;
                _engineEvent = new ChannelEngineEvent(); 
            }

            ChannelEventHandler::~ChannelEventHandler() 
            {
                if (_engineEvent) {
                    _engineEvent->reset();
                    delete _engineEvent;
                    _engineEvent = NULL;
                }
            }

            void ChannelEventHandler::initChannelEventCallback(FUNC_OnChannelWarning onWarning,
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
                _engineEvent->onWarning = onWarning;
                _engineEvent->onError = onError;
                _engineEvent->onJoinChannelSuccess = onJoinChannelSuccess;
                _engineEvent->onRejoinChannelSuccess = onRejoinChannelSuccess;
                _engineEvent->onLeaveChannel = onLeaveChannel;
                _engineEvent->onClientRoleChanged = onClientRoleChanged;
                _engineEvent->onUserJoined = onUserJoined;
                _engineEvent->onUserOffLine = onUserOffline;
                _engineEvent->onConnectionLost = onConnectionLost;
                _engineEvent->onRequestToken = onRequestToken;
                _engineEvent->onTokenPrivilegeWillExpire = onTokenPrivilegeWillExpire;
                _engineEvent->onRtcStats = onRtcStats;
                _engineEvent->onNetworkQuality = onNetworkQuality;
                _engineEvent->onRemoteVideoStats = onRemoteVideoStats;
                _engineEvent->onRemoteAudioStats = onRemoteAudioStats;
                _engineEvent->onRemoteAudioStateChanged = onRemoteAudioStateChanged;
                _engineEvent->onActiveSpeaker = onActiveSpeaker;
                _engineEvent->onVideoSizeChanged = onVideoSizeChanged;
                _engineEvent->onRemoteVideoStateChanged = onRemoteVideoStateChanged;
                _engineEvent->onStreamMessage = onStreamMessage;
                _engineEvent->onStreamMessageError = onStreamMessageError;
                _engineEvent->onMediaRelayStateChanged = onMediaRelayStateChanged;
                _engineEvent->onMediaRelayEvent = onMediaRelayEvent;
                _engineEvent->onRtmpStreamingStateChanged = onRtmpStreamingStateChanged;
                _engineEvent->onTranscodingUpdated = onTranscodingUpdated;
                _engineEvent->onStreamInjectedStatus = onStreamInjectedStatus;
                _engineEvent->onRemoteSubscribeFallbackToAudioOnly = onRemoteSubscribeFallbackToAudioOnly;
                _engineEvent->onConnectionStateChanged = onConnectionStateChanged;
                _engineEvent->onLocalPublishFallbackToAudioOnly = onLocalPublishFallbackToAudioOnly;
            }

            void ChannelEventHandler::onChannelWarning(IChannel *rtcChannel, int warn, const char* msg) 
            {
                if (_engineEvent)
                    _engineEvent->onWarning(_channelId.data(), warn, msg);
            }
            
            void ChannelEventHandler::onChannelError(IChannel *rtcChannel, int err, const char* msg) 
            {
                if (_engineEvent)
                    _engineEvent->onError(_channelId.data(), err, msg);
            }
            
            void ChannelEventHandler::onJoinChannelSuccess(IChannel *rtcChannel, uid_t uid, int elapsed) 
            {
                if (_engineEvent)
                    _engineEvent->onJoinChannelSuccess(_channelId.data(), uid, elapsed);
            }
            
            void ChannelEventHandler::onRejoinChannelSuccess(IChannel *rtcChannel, uid_t uid, int elapsed) 
            {
                if (_engineEvent)
                    _engineEvent->onRejoinChannelSuccess(_channelId.data(), uid, elapsed);
            }
               
            void ChannelEventHandler::onLeaveChannel(IChannel *rtcChannel, const RtcStats& stats) 
            {
                if (_engineEvent)
                    _engineEvent->onLeaveChannel(_channelId.data(), stats.duration, stats.txBytes, stats.rxBytes, stats.txAudioBytes, stats.txVideoBytes, stats.rxAudioBytes, stats.rxVideoBytes, stats.txKBitRate, stats.rxKBitRate, stats.rxAudioKBitRate, stats.txAudioKBitRate, stats.rxVideoKBitRate, stats.txVideoKBitRate, stats.lastmileDelay, stats.txPacketLossRate, stats.rxPacketLossRate, stats.userCount, stats.cpuAppUsage, stats.cpuTotalUsage, stats.gatewayRtt, stats.memoryAppUsageRatio, stats.memoryTotalUsageRatio, stats.memoryAppUsageInKbytes);
            }
            
            void ChannelEventHandler::onClientRoleChanged(IChannel *rtcChannel, CLIENT_ROLE_TYPE oldRole, CLIENT_ROLE_TYPE newRole) 
            {
                if (_engineEvent)
                    _engineEvent->onClientRoleChanged(_channelId.data(), (int)oldRole, (int)newRole);
            }
            
            void ChannelEventHandler::onUserJoined(IChannel *rtcChannel, uid_t uid, int elapsed) 
            {
                if (_engineEvent)
                    _engineEvent->onUserJoined(_channelId.data(), uid, elapsed);
            }
            
            void ChannelEventHandler::onUserOffline(IChannel *rtcChannel, uid_t uid, USER_OFFLINE_REASON_TYPE reason) 
            {
                if (_engineEvent)
                    _engineEvent->onUserOffLine(_channelId.data(), uid, (int)reason);
            }
            
            void ChannelEventHandler::onConnectionLost(IChannel *rtcChannel) 
            {
                if (_engineEvent)
                    _engineEvent->onConnectionLost(_channelId.data());
            }
            
            void ChannelEventHandler::onRequestToken(IChannel *rtcChannel) 
            {
                if (_engineEvent)
                    _engineEvent->onRequestToken(_channelId.data());
            }
            
            void ChannelEventHandler::onTokenPrivilegeWillExpire(IChannel *rtcChannel, const char* token) 
            {
                if (_engineEvent)
                    _engineEvent->onTokenPrivilegeWillExpire(_channelId.data(), token);
            }
            
            void ChannelEventHandler::onRtcStats(IChannel *rtcChannel, const RtcStats& stats) 
            {
                if (_engineEvent)
                    _engineEvent->onRtcStats(_channelId.data(), stats.duration, stats.txBytes, stats.rxBytes, stats.txAudioBytes, stats.txVideoBytes, stats.rxAudioBytes, stats.rxVideoBytes, stats.txKBitRate, stats.rxKBitRate, stats.rxAudioKBitRate, stats.txAudioKBitRate, stats.rxVideoKBitRate, stats.txVideoKBitRate, stats.lastmileDelay, stats.txPacketLossRate, stats.rxPacketLossRate, stats.userCount, stats.cpuAppUsage, stats.cpuTotalUsage, stats.gatewayRtt, stats.memoryAppUsageRatio, stats.memoryTotalUsageRatio, stats.memoryAppUsageInKbytes);
            }
            
            void ChannelEventHandler::onNetworkQuality(IChannel *rtcChannel, uid_t uid, int txQuality, int rxQuality) 
            {
                if (_engineEvent)
                    _engineEvent->onNetworkQuality(_channelId.data(), uid, txQuality, rxQuality);
            }                                                                                                                                                                     int totalActiveTime;
            
            void ChannelEventHandler::onRemoteVideoStats(IChannel *rtcChannel, const RemoteVideoStats& stats) 
            {
                if (_engineEvent)
                    _engineEvent->onRemoteVideoStats(_channelId.data(), stats.uid, stats.delay, stats.width, stats.height, stats.receivedBitrate, stats.decoderOutputFrameRate, stats.rendererOutputFrameRate, stats.packetLossRate, (int)stats.rxStreamType, stats.totalFrozenTime, stats.frozenRate, stats.totalActiveTime);
            }
            
            void ChannelEventHandler::onRemoteAudioStats(IChannel *rtcChannel, const RemoteAudioStats& stats) 
            {
                if (_engineEvent)
                    _engineEvent->onRemoteAudioStats(_channelId.data(), stats.uid, stats.quality, stats.networkTransportDelay, stats.jitterBufferDelay, stats.audioLossRate, stats.numChannels, stats.receivedSampleRate, stats.receivedBitrate, stats.totalFrozenTime, stats.frozenRate, stats.totalActiveTime);
            }

            void ChannelEventHandler::onRemoteAudioStateChanged(IChannel *rtcChannel, uid_t uid, REMOTE_AUDIO_STATE state, REMOTE_AUDIO_STATE_REASON reason, int elapsed)
            {
                if (_engineEvent)
                    _engineEvent->onRemoteAudioStateChanged(_channelId.data(), uid, (int)state, (int)reason, elapsed);
            }
            
            void ChannelEventHandler::onActiveSpeaker(IChannel *rtcChannel, uid_t uid) 
            {
                if (_engineEvent)
                    _engineEvent->onActiveSpeaker(_channelId.data(), uid);
            }
                
            void ChannelEventHandler::onVideoSizeChanged(IChannel *rtcChannel, uid_t uid, int width, int height, int rotation) 
            {
                if (_engineEvent)
                    _engineEvent->onVideoSizeChanged(_channelId.data(), uid, width, height, rotation);
            }
            
            void ChannelEventHandler::onRemoteVideoStateChanged(IChannel *rtcChannel, uid_t uid, REMOTE_VIDEO_STATE state, REMOTE_VIDEO_STATE_REASON reason, int elapsed) 
            {
                if (_engineEvent)
                    _engineEvent->onRemoteVideoStateChanged(_channelId.data(), uid, (int)state, (int)reason, elapsed);
            }
            
            void ChannelEventHandler::onStreamMessage(IChannel *rtcChannel, uid_t uid, int streamId, const char* data, size_t length) 
            {
                if (_engineEvent)
                    _engineEvent->onStreamMessage(_channelId.data(), uid, streamId, data, length);
            }
            
            void ChannelEventHandler::onStreamMessageError(IChannel *rtcChannel, uid_t uid, int streamId, int code, int missed, int cached) 
            {
                if (_engineEvent)
                    _engineEvent->onStreamMessageError(_channelId.data(), uid, streamId, code, missed, cached);
            }
            
            void ChannelEventHandler::onChannelMediaRelayStateChanged(IChannel *rtcChannel, CHANNEL_MEDIA_RELAY_STATE state, CHANNEL_MEDIA_RELAY_ERROR code) 
            {
                if (_engineEvent)
                    _engineEvent->onMediaRelayStateChanged(_channelId.data(), (int)state, (int)code);
            }
            
            void ChannelEventHandler::onChannelMediaRelayEvent(IChannel *rtcChannel, CHANNEL_MEDIA_RELAY_EVENT code) 
            {
                if (_engineEvent)
                    _engineEvent->onMediaRelayEvent(_channelId.data(), (int)code);
            }

            void ChannelEventHandler::onRtmpStreamingStateChanged(IChannel *rtcChannel, const char *url, RTMP_STREAM_PUBLISH_STATE state, RTMP_STREAM_PUBLISH_ERROR_TYPE errCode)
            {
                if (_engineEvent)
                    _engineEvent->onRtmpStreamingStateChanged(_channelId.data(), url, (int)state, (int)errCode);
            }
                
            void ChannelEventHandler::onTranscodingUpdated(IChannel *rtcChannel) 
            {
                if (_engineEvent)
                    _engineEvent->onTranscodingUpdated(_channelId.data());
            }
            
            void ChannelEventHandler::onStreamInjectedStatus(IChannel *rtcChannel, const char* url, uid_t uid, int status) 
            {
                if (_engineEvent)
                    _engineEvent->onStreamInjectedStatus(_channelId.data(), url, uid, status);
            }
            
            void ChannelEventHandler::onRemoteSubscribeFallbackToAudioOnly(IChannel *rtcChannel, uid_t uid, bool isFallbackOrRecover) 
            {
                if (_engineEvent)
                    _engineEvent->onRemoteSubscribeFallbackToAudioOnly(_channelId.data(), uid, isFallbackOrRecover);
            }
            
            void ChannelEventHandler::onConnectionStateChanged(IChannel *rtcChannel,
                                                CONNECTION_STATE_TYPE state,
                                                CONNECTION_CHANGED_REASON_TYPE reason) 
                                                {
                if (_engineEvent)
                    _engineEvent->onConnectionStateChanged(_channelId.data(), (int)state, (int)reason);
            }

            void ChannelEventHandler::onLocalPublishFallbackToAudioOnly(IChannel *rtcChannel, bool isFallbackOrRecover)
            {
                if (_engineEvent)
                    _engineEvent->onLocalPublishFallbackToAudioOnly(_channelId.data(), isFallbackOrRecover);
            }
    }
}