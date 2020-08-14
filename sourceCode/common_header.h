#ifndef WRAPPER_COMMON_HEADER
#define WRAPPER_COMMON_HEADER
#define WRAPPER_WINDOWS
#define LENGTH_MAX 255
#define NOT_INIT_ENGINE -7
#define NOT_SUPPORT_API -4
#define NOT_INIT_ENGINE_CHAR "-7"
#if defined(WRAPPER_ANDROID)
#include <android/log.h>
#include "../../include/AgoraBase.h"
#include "../../include/IAgoraMediaEngine.h"
#include "../../include/IAgoraRtcEngine.h"
#include "../../include/IAgoraService.h"
#include "../../include/IAgoraRtcEngine2.h"
#include "../../include/IAgoraRtcChannel.h"
#include <jni.h>
#include <mutex>
#include <list>
#include <map>
#include <string>
#include <sys/time.h>
#include <unistd.h>
#define PRINTF(...) __android_log_print(ANDROID_LOG_INFO, "Agora_zt", __VA_ARGS__)
#else
#if defined(WRAPPER_WINDOWS)
#define AGORARTC_EXPORT
#include "../native_sdk/include/AgoraBase.h"
#include "../native_sdk/include/IAgoraMediaEngine.h"
#include "../native_sdk/include/IAgoraRtcEngine.h"
#include "../native_sdk/include/IAgoraService.h"
#include "../native_sdk/include/IAgoraRtcEngine2.h"
#include "../native_sdk/include/IAgoraRtcChannel.h"
#include <mutex>
#include <list>
#include <map>
#include <string>
#pragma warning(disable : 4800)
#pragma warning(disable : 4172)
#pragma warning(disable : 4018)
#pragma warning(disable : 4996)
#pragma error(disable : 2057)
#pragma error(disable : 2466)
#pragma error(disable : 2133)
#pragma comment(lib, "agora_rtc_sdk.lib")

#else
#if defined(WRAPPER_IOS)
#include "../../../include/AgoraBase.h"
#include "../../../include/IAgoraMediaEngine.h"
#include "../../../include/IAgoraRtcEngine.h"
#include "../../../include/IAgoraService.h"
#include "../../../include/IAgoraRtcEngine2.h"
#include "../../../include/IAgoraRtcChannel.h"
#import <Foundation/Foundation.h>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <OpenGLES/ES2/gl.h>
#include <mutex>
#include <list>
#include <map>
#include <string>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#define PRINTF printf
#else
#if defined(WRAPPER_MAC)
#include "../../../../include/AgoraBase.h"
#include "../../../../include/IAgoraMediaEngine.h"
#include "../../../../include/IAgoraRtcEngine.h"
#include "../../../../include/IAgoraService.h"
#include "../../../../include/IAgoraRtcEngine2.h"
#include "../../../../include/IAgoraRtcChannel.h"
#include <stdio.h>
#include <memory.h>
#include <string>
#include <mutex>
#include <list>
#include <map>
#include <string>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#define PRINTF printf
#endif
#endif
#endif
#endif

namespace agora
{
    namespace unity
    {
		using namespace agora::rtc;
		using namespace agora::media;

		#if defined WRAPPER_WINDOWS
		typedef void(__stdcall *FUNC_OnJoinChannelSuccess)(const char *, uid_t uid, int elapsed);
		typedef void(__stdcall *FUNC_OnReJoinChannelSuccess)(const char *, uid_t uid, int elapsed);
		typedef void(__stdcall *FUNC_OnConnectionLost)();
		typedef void(__stdcall *FUNC_OnConnectionInterrupted)();
		typedef void(__stdcall *FUNC_OnLeaveChannel)(unsigned int duration, unsigned int txBytes, unsigned int rxBytes, unsigned int txAudioBytes, unsigned int txVideoBytes, unsigned int rxAudioBytes, unsigned int rxVideoBytes, unsigned short txKBitRate, unsigned short rxKBitRate, unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate, unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate, unsigned short lastmileDelay, unsigned short txPacketLossRate, unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage, double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio, double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
		typedef void(__stdcall *FUNC_OnRequestToken)();
		typedef void(__stdcall *FUNC_OnUserJoined)(uid_t uid, int elapsed);
		typedef void(__stdcall *FUNC_OnUserOffline)(uid_t uid, int offLineReason);
		typedef void(__stdcall *FUNC_OnAudioVolumeIndication)(const char *volumeInfo, int speakerNumber, int totalVolume);
		typedef void(__stdcall *FUNC_OnUserMuteAudio)(uid_t uid, bool muted);
		typedef void(__stdcall *FUNC_OnSDKWarning)(int warn, const char *msg);
		typedef void(__stdcall *FUNC_OnSDKError)(int error, const char *msg);
		typedef void(__stdcall *FUNC_OnRtcStats)( unsigned int duration, unsigned int txBytes, unsigned int rxBytes, unsigned int txAudioBytes, unsigned int txVideoBytes, unsigned int rxAudioBytes, unsigned int rxVideoBytes, unsigned short txKBitRate, unsigned short rxKBitRate, unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate, unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate, unsigned short lastmileDelay, unsigned short txPacketLossRate, unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage, double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio, double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
		typedef void(__stdcall *FUNC_OnAudioMixingFinished)();
		typedef void(__stdcall *FUNC_OnAudioRouteChanged)(int route);
		typedef void(__stdcall *FUNC_OnFirstRemoteVideoDecoded)(uid_t uid, int width, int height, int elapsed);
		typedef void(__stdcall *FUNC_OnVideoSizeChanged)(uid_t uid, int width, int height, int elapsed);
		typedef void(__stdcall *FUNC_OnClientRoleChanged)(int oldRole, int newRole);
		typedef void(__stdcall *FUNC_OnUserMuteVideo)(uid_t uid, bool muted);
		typedef void(__stdcall *FUNC_OnMicrophoneEnabled)(bool isEnabled);
		typedef void(__stdcall *FUNC_OnApiExecuted)(int err, const char *api, const char *result);
		typedef void(__stdcall *FUNC_OnFirstLocalAudioFrame)(int elapsed);
		typedef void(__stdcall *FUNC_OnFirstRemoteAudioFrame)(uid_t userId, int elapsed);
		typedef void(__stdcall *FUNC_OnLastmileQuality)(int quality);
		typedef void(__stdcall *FUNC_OnAudioQuality)(uid_t userId, int quality, unsigned short delay, unsigned short lost);
		typedef void(__stdcall *FUNC_OnStreamInjectedStatus)(const char *url, uid_t userId, int status);
		typedef void(__stdcall *FUNC_OnStreamUnpublished)(const char *url);
		typedef void(__stdcall *FUNC_OnStreamPublished)(const char *url, int error);
		typedef void(__stdcall *FUNC_OnStreamMessageError)(uid_t userId, int streamId, int code, int missed, int cached);
		typedef void(__stdcall *FUNC_OnStreamMessage)(uid_t userId, int streamId, const char *data, size_t length);
		typedef void(__stdcall *FUNC_OnConnectionBanned)();
		typedef void(__stdcall *FUNC_OnRemoteVideoTransportStats)(uid_t uid, unsigned short delay, unsigned short lost, unsigned short rxKBitRate);
		typedef void(__stdcall *FUNC_OnRemoteAudioTransportStats)(uid_t uid, unsigned short delay, unsigned short lost, unsigned short rxKBitRate);
		typedef void(__stdcall *FUNC_OnTranscodingUpdated)();
		typedef void(__stdcall *FUNC_OnAudioDeviceVolumeChanged)(int deviceType, int volume, bool muted);
		typedef void(__stdcall *FUNC_OnActiveSpeaker)(uid_t userId);
		typedef void(__stdcall *FUNC_OnMediaEngineStartCallSuccess)();
		typedef void(__stdcall *FUNC_OnMediaEngineLoadSuccess)();
		typedef void(__stdcall *FUNC_OnVideoStopped)();
		typedef void(__stdcall *FUNC_OnTokenPrivilegeWillExpire)(const char* token);
		typedef void(__stdcall *FUNC_OnNetworkQuality)(uid_t uid, int txQuality, int rxQuality);
		typedef void(__stdcall *FUNC_OnLocalVideoStats)(int sentBitrate, int sentFrameRate, int encoderOutputFrameRate, int rendererOutputFrameRate, int targetBitrate, int targetFrameRate, int qualityAdaptIndication, int encodedBitrate, int encodedFrameWidth, int encodedFrameHeight, int encodedFrameCount, int codecType);
		typedef void(__stdcall *FUNC_OnRemoteVideoStats)(uid_t uid, int delay, int width, int height, int receivedBitrate, int decoderOutputFrameRate, int rendererOutputFrameRate, int packetLossRate, int rxStreamType, int totalFrozenTime, int frozenRate, int totalActiveTime);
		typedef void(__stdcall *FUNC_OnRemoteAudioStats)(uid_t uid, int quality, int networkTransportDelay, int jitterBufferDelay, int audioLossRate, int numChannels, int receivedSampleRate, int receivedBitrate, int totalFrozenTime, int frozenRate, int totalActiveTime);
		typedef void(__stdcall *FUNC_OnLocalAudioStats)(int numChannels, int sentSampleRate, int sentBitrate);
		typedef void(__stdcall *FUNC_OnFirstLocalVideoFrame)(int width, int height, int elapsed);
		typedef void(__stdcall *FUNC_OnFirstRemoteVideoFrame)(uid_t uid, int width, int height, int elapsed);
		typedef void(__stdcall *FUNC_OnUserEnableVideo)(uid_t uid, bool enabled);
		typedef void(__stdcall *FUNC_OnAudioDeviceStateChanged)(const char* deviceId, int deviceType, int deviceState);
		typedef void(__stdcall *FUNC_OnCameraReady)();
		typedef void(__stdcall *FUNC_OnCameraFocusAreaChanged)(int x, int y, int width, int height);
		typedef void(__stdcall *FUNC_OnCameraExposureAreaChanged)(int x, int y, int width, int height);
		typedef void(__stdcall *FUNC_OnRemoteAudioMixingBegin)();
		typedef void(__stdcall *FUNC_OnRemoteAudioMixingEnd)();
		typedef void(__stdcall *FUNC_OnAudioEffectFinished)(int soundId);
		typedef void(__stdcall *FUNC_OnVideoDeviceStateChanged)(const char* deviceId, int deviceType, int deviceState);
		typedef void(__stdcall *FUNC_OnRemoteVideoStateChanged)(uid_t uid, int state, int reason, int elapsed);
		typedef void(__stdcall *FUNC_OnUserEnableLocalVideo)(uid_t uid, bool enabled);
		typedef void(__stdcall *FUNC_OnLocalPublishFallbackToAudioOnly)(bool isFallbackOrRecover);
		typedef void(__stdcall *FUNC_OnRemoteSubscribeFallbackToAudioOnly)(uid_t uid, bool isFallbackOrRecover);
		typedef void(__stdcall *FUNC_OnConnectionStateChanged)(int state, int reason);
		typedef void(__stdcall *FUNC_OnLocalUserRegistered)(uid_t uid, char* userAccount);
		typedef void(__stdcall *FUNC_OnUserInfoUpdated)(uid_t uid, uid_t userId, char* userAccount);
		typedef void(__stdcall *FUNC_OnLocalAudioStateChanged)(int state, int error);
		typedef void(__stdcall *FUNC_OnRemoteAudioStateChanged)(uid_t uid, int state, int reason, int elapsed);
		typedef void(__stdcall *FUNC_OnStreamInjectedStatus)(const char* url, uid_t uid, int status);
		typedef void(__stdcall *FUNC_OnChannelMediaRelayStateChanged)(int state, int code);
		typedef void(__stdcall *FUNC_OnChannelMediaRelayEvent)(int code);

		// raw data callback
		typedef void(__stdcall *FUNC_OnCaptureVideoFrame)(int videoFrameType, int width, int height, int yStride, void* yBuffer, int rotation, int64_t renderTimeMs);
		typedef void(__stdcall *FUNC_OnRenderVideoFrame)(unsigned int uid, int videoFrameType, int width, int height, int yStride, void* yBuffer, int rotation, int64_t renderTimeMs);
		typedef void(__stdcall *FUNC_OnRecordAudioFrame)(int type, int samples, int bytesPerSample, int channels, int samplesPerSec, void* buffer, int64_t renderTimeMs, int avsync_type);
		typedef void(__stdcall *FUNC_OnPlaybackAudioFrame)(int type, int samples, int bytesPerSample, int channels, int samplesPerSec, void* buffer, int64_t renderTimeMs, int avsync_type);
		typedef void(__stdcall *FUNC_OnPullAudioFrame)(int type, int samples, int bytesPerSample, int channels, int samplesPerSec, void* buffer, int64_t renderTimeMs, int avsync_type);
		typedef void(__stdcall *FUNC_OnMixedAudioFrame)(int type, int samples, int bytesPerSample, int channels, int samplesPerSec, void* buffer, int64_t renderTimeMs, int avsync_type);
		typedef void(__stdcall *FUNC_OnPlaybackAudioFrameBeforeMixing)(unsigned int uid, int type, int samples, int bytesPerSample, int channels, int samplesPerSec, void* buffer, int64_t renderTimeMs, int avsync_type);
		typedef void(__stdcall *FUNC_OnAudioMixingStateChanged)(int audioMixingStateType, int audioMixingErrorType);
		typedef void(__stdcall *FUNC_OnFirstRemoteAudioDecoded)(uid_t uid, int elapsed);
		typedef void(__stdcall *FUNC_OnLocalVideoStateChanged)(int localVideoState, int error);
		typedef void(__stdcall *FUNC_OnRtmpStreamingStateChanged)(const char *url, int state, int errCode);
		typedef void(__stdcall *FUNC_OnNetworkTypeChanged)(int networkType);
		typedef void(__stdcall *FUNC_OnLastmileProbeResult)(int state, unsigned int upLinkPacketLossRate, unsigned int upLinkjitter, unsigned int upLinkAvailableBandwidth, unsigned int downLinkPacketLossRate, unsigned int downLinkJitter, unsigned int downLinkAvailableBandwidth, unsigned int rtt);	
		typedef bool(__stdcall *FUNC_OnSendAudioPacket)(const unsigned char *buffer, void *size);
		typedef bool(__stdcall *FUNC_OnSendVideoPacket)(const unsigned char *buffer, void *size);
		typedef bool(__stdcall *FUNC_OnReceiveAudioPacket)(const unsigned char *buffer, void *size);
		typedef bool(__stdcall *FUNC_OnReceiveVideoPacket)(const unsigned char *buffer, void *size);		
		typedef bool(__stdcall *FUNC_OnReadyToSendMetadata)();
		typedef void(__stdcall *FUNC_OnMetadataReceived)(unsigned int uid, unsigned int size, unsigned char *buffer, long long timeStampMs);
		typedef int(__stdcall *FUNC_OnGetMaxMetadataSize)();
		typedef void(__stdcall *FUNC_OnChannelWarning)(const char* channelId, int warn, const char* msg);
		typedef void(__stdcall *FUNC_OnChannelError)(const char* channelId, int err, const char* msg);
		typedef void(__stdcall *FUNC_OnChannelJoinChannelSuccess)(const char* channelId, uid_t uid, int elapsed);
		typedef void(__stdcall *FUNC_OnChannelReJoinChannelSuccess)(const char* channelId, uid_t uid, int elapsed);
		typedef void(__stdcall *FUNC_OnChannelLeaveChannel)(const char* channelId, unsigned int duration, unsigned int txBytes, unsigned int rxBytes, unsigned int txAudioBytes, unsigned int txVideoBytes, unsigned int rxAudioBytes, unsigned int rxVideoBytes, unsigned short txKBitRate, unsigned short rxKBitRate, unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate, unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate, unsigned short lastmileDelay, unsigned short txPacketLossRate, unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage, double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio, double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
		typedef void(__stdcall *FUNC_OnChannelClientRoleChanged)(const char* channelId, int oldRole, int newRole);
		typedef void(__stdcall *FUNC_OnChannelUserJoined)(const char* channelId, uid_t uid, int elapsed);
        typedef void(__stdcall *FUNC_OnChannelUserOffLine)(const char* channelId, uid_t uid, int reason);
        typedef void(__stdcall *FUNC_OnChannelConnectionLost)(const char* channelId);
        typedef void(__stdcall *FUNC_OnChannelRequestToken)(const char* channelId);
		typedef void(__stdcall *FUNC_OnChannelTokenPrivilegeWillExpire)(const char* channelId, const char* token);
        typedef void(__stdcall *FUNC_OnChannelRtcStats)(const char* channelId, unsigned int duration, unsigned int txBytes, unsigned int rxBytes, unsigned int txAudioBytes, unsigned int txVideoBytes, unsigned int rxAudioBytes, unsigned int rxVideoBytes, unsigned short txKBitRate, unsigned short rxKBitRate, unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate, unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate, unsigned short lastmileDelay, unsigned short txPacketLossRate, unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage, double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio, double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
		typedef void(__stdcall *FUNC_OnChannelNetworkQuality)(const char* channelId, uid_t uid, int txQuality, int rxQuality);
        typedef void(__stdcall *FUNC_OnChannelRemoteVideoStats)(const char* channelId, uid_t uid, int delay, int width, int height, int receivedBitrate, int decoderOutputFrameRate, int rendererOutputFrameRate, int packetLossRate, int rxStreamType, int totalFrozenTime, int frozenRate, int totalActiveTime);
        typedef void(__stdcall *FUNC_OnChannelRemoteAudioStats)(const char* channelId, uid_t uid, int quality, int networkTransportDelay, int jitterBufferDelay, int audioLossRate, int numChannels, int receivedSampleRate, int receivedBitrate, int totalFrozenTime, int frozenRate, int totalActiveTime);		
		typedef void(__stdcall *FUNC_OnChannelRemoteAudioStateChanged)(const char* channelId, uid_t uid, int state, int reason, int elapsed);
		typedef void(__stdcall *FUNC_OnChannelActiveSpeaker)(const char* channelId, uid_t uid);            
		typedef void(__stdcall *FUNC_OnChannelVideoSizeChanged)(const char* channelId, uid_t uid, int width, int height, int rotation);
		typedef void(__stdcall *FUNC_OnChannelRemoteVideoStateChanged)(const char* channelId, uid_t uid, int state, int reason, int elapsed);
		typedef void(__stdcall *FUNC_OnChannelStreamMessage)(const char* channelId, uid_t uid, int streamId, const char* data, size_t length);
		typedef void(__stdcall *FUNC_OnChannelStreamMessageError)(const char* channelId, uid_t uid, int streamId, int code, int missed, int cached);
		typedef void(__stdcall *FUNC_OnChannelMediaRelayStateChanged2)(const char* channelId, int state, int code);
		typedef void(__stdcall *FUNC_OnChannelMediaRelayEvent2)(const char* channelId, int code);
		typedef void(__stdcall *FUNC_OnChannelRtmpStreamingStateChanged)(const char* channelId, const char *url, int state, int errCode);
		typedef void(__stdcall *FUNC_OnChannelTranscodingUpdated)(const char* channelId);
		typedef void(__stdcall *FUNC_OnChannelStreamInjectedStatus)(const char* channelId, const char* url, uid_t uid, int status);
		typedef void(__stdcall *FUNC_OnChannelRemoteSubscribeFallbackToAudioOnly)(const char* channelId, uid_t uid, bool isFallbackOrRecover);
		typedef void(__stdcall *FUNC_OnChannelConnectionStateChanged)(const char* channelId, int state, int reason);
		typedef void(__stdcall *FUNC_OnFacePositionChanged)(int imageWidth, int imageHeight, int x, int y, int width, int height, int vecDistance, int numFaces);
		typedef void(__stdcall *FUNC_OnChannelLocalPublishFallbackToAudioOnly)(const char* channelId, bool isFallbackOrRecover);
		#else
		typedef void(*FUNC_OnJoinChannelSuccess)(const char *, uid_t uid, int elapsed);
		typedef void(*FUNC_OnReJoinChannelSuccess)(const char *, uid_t uid, int elapsed);
		typedef void(*FUNC_OnConnectionLost)();
		typedef void(*FUNC_OnConnectionInterrupted)();
		typedef void(*FUNC_OnLeaveChannel)(unsigned int duration, unsigned int txBytes, unsigned int rxBytes, unsigned int txAudioBytes, unsigned int txVideoBytes, unsigned int rxAudioBytes, unsigned int rxVideoBytes, unsigned short txKBitRate, unsigned short rxKBitRate, unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate, unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate, unsigned short lastmileDelay, unsigned short txPacketLossRate, unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage, double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio, double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
		typedef void(*FUNC_OnRequestToken)();
		typedef void(*FUNC_OnUserJoined)(uid_t uid, int elapsed);
		typedef void(*FUNC_OnUserOffline)(uid_t uid, int offLineReason);
		typedef void(*FUNC_OnAudioVolumeIndication)(const char *volumeInfo, int speakerNumber, int totalVolume);
		typedef void(*FUNC_OnUserMuteAudio)(uid_t uid, bool muted);
		typedef void(*FUNC_OnSDKWarning)(int warn, const char *msg);
		typedef void(*FUNC_OnSDKError)(int error, const char *msg);
		typedef void(*FUNC_OnRtcStats)(unsigned int duration, unsigned int txBytes, unsigned int rxBytes, unsigned int txAudioBytes, unsigned int txVideoBytes, unsigned int rxAudioBytes, unsigned int rxVideoBytes, unsigned short txKBitRate, unsigned short rxKBitRate, unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate, unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate, unsigned short lastmileDelay, unsigned short txPacketLossRate, unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage, double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio, double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
		typedef void(*FUNC_OnAudioMixingFinished)();
		typedef void(*FUNC_OnAudioRouteChanged)(int route);
		typedef void(*FUNC_OnFirstRemoteVideoDecoded)(uid_t uid, int width, int height, int elapsed);
		typedef void(*FUNC_OnVideoSizeChanged)(uid_t uid, int width, int height, int elapsed);
		typedef void(*FUNC_OnClientRoleChanged)(int oldRole, int newRole);
		typedef void(*FUNC_OnUserMuteVideo)(uid_t uid, bool muted);
		typedef void(*FUNC_OnMicrophoneEnabled)(bool isEnabled);
		typedef void(*FUNC_OnApiExecuted)(int err, const char *api, const char *result);
		typedef void(*FUNC_OnFirstLocalAudioFrame)(int elapsed);
		typedef void(*FUNC_OnFirstRemoteAudioFrame)(uid_t userId, int elapsed);
		typedef void(*FUNC_OnLastmileQuality)(int quality);
		typedef void(*FUNC_OnAudioQuality)(uid_t userId, int quality, unsigned short delay, unsigned short lost);
		typedef void(*FUNC_OnStreamInjectedStatus)(const char *url, uid_t userId, int status);
		typedef void(*FUNC_OnStreamUnpublished)(const char *url);
		typedef void(*FUNC_OnStreamPublished)(const char *url, int error);
		typedef void(*FUNC_OnStreamMessageError)(uid_t userId, int streamId, int code, int missed, int cached);
		typedef void(*FUNC_OnStreamMessage)(uid_t userId, int streamId, const char *data, size_t length);
		typedef void(*FUNC_OnConnectionBanned)();
		typedef void(*FUNC_OnRemoteVideoTransportStats)(uid_t uid, unsigned short delay, unsigned short lost, unsigned short rxKBitRate);
		typedef void(*FUNC_OnRemoteAudioTransportStats)(uid_t uid, unsigned short delay, unsigned short lost, unsigned short rxKBitRate);
		typedef void(*FUNC_OnTranscodingUpdated)();
		typedef void(*FUNC_OnAudioDeviceVolumeChanged)(int deviceType, int volume, bool muted);
		typedef void(*FUNC_OnActiveSpeaker)(uid_t userId);
		typedef void(*FUNC_OnMediaEngineStartCallSuccess)();
		typedef void(*FUNC_OnMediaEngineLoadSuccess)();
		typedef void(*FUNC_OnVideoStopped)();
		typedef void(*FUNC_OnTokenPrivilegeWillExpire)(const char* token);
		typedef void(*FUNC_OnNetworkQuality)(uid_t uid, int txQuality, int rxQuality);
		typedef void(*FUNC_OnLocalVideoStats)(int sentBitrate, int sentFrameRate, int encoderOutputFrameRate, int rendererOutputFrameRate, int targetBitrate, int targetFrameRate, int qualityAdaptIndication, int encodedBitrate, int encodedFrameWidth, int encodedFrameHeight, int encodedFrameCount, int codecType);
		typedef void(*FUNC_OnRemoteVideoStats)(uid_t uid, int delay, int width, int height, int receivedBitrate, int decoderOutputFrameRate, int rendererOutputFrameRate, int packetLossRate, int rxStreamType, int totalFrozenTime, int frozenRate, int totalActiveTime);
		typedef void(*FUNC_OnRemoteAudioStats)(uid_t uid, int quality, int networkTransportDelay, int jitterBufferDelay, int audioLossRate, int numChannels, int receivedSampleRate, int receivedBitrate, int totalFrozenTime, int frozenRate, int totalActiveTime);	
		typedef void(*FUNC_OnLocalAudioStats)(int numChannels, int sentSampleRate, int sentBitrate);
		typedef void(*FUNC_OnFirstLocalVideoFrame)(int width, int height, int elapsed);
		typedef void(*FUNC_OnFirstRemoteVideoFrame)(uid_t uid, int width, int height, int elapsed);
		typedef void(*FUNC_OnUserEnableVideo)(uid_t uid, bool enabled);
		typedef void(*FUNC_OnAudioDeviceStateChanged)(const char* deviceId, int deviceType, int deviceState);
		typedef void(*FUNC_OnCameraReady)();
		typedef void(*FUNC_OnCameraFocusAreaChanged)(int x, int y, int width, int height);
		typedef void(*FUNC_OnCameraExposureAreaChanged)(int x, int y, int width, int height);
		typedef void(*FUNC_OnRemoteAudioMixingBegin)();
		typedef void(*FUNC_OnRemoteAudioMixingEnd)();
		typedef void(*FUNC_OnAudioEffectFinished)(int soundId);
		typedef void(*FUNC_OnVideoDeviceStateChanged)(const char* deviceId, int deviceType, int deviceState);
		typedef void(*FUNC_OnRemoteVideoStateChanged)(uid_t uid, int state, int reason, int elapsed);
		typedef void(*FUNC_OnUserEnableLocalVideo)(uid_t uid, bool enabled);
		typedef void(*FUNC_OnLocalPublishFallbackToAudioOnly)(bool isFallbackOrRecover);
		typedef void(*FUNC_OnRemoteSubscribeFallbackToAudioOnly)(uid_t uid, bool isFallbackOrRecover);
		typedef void(*FUNC_OnConnectionStateChanged)(int state, int reason);
		typedef void(*FUNC_OnRtmpStreamingStateChanged)(const char *url, int state, int errCode);
		typedef void(*FUNC_OnLocalUserRegistered)(uid_t uid, char* userAccount);
		typedef void(*FUNC_OnUserInfoUpdated)(uid_t uid, uid_t userUid, char* userAccount);
		typedef void(*FUNC_OnLocalAudioStateChanged)(int state, int error);
		typedef void(*FUNC_OnRemoteAudioStateChanged)(uid_t uid, int state, int reason, int elapsed);
		typedef void(*FUNC_OnStreamInjectedStatus)(const char* url, uid_t uid, int status);
		typedef void(*FUNC_OnChannelMediaRelayStateChanged)(int state, int code);
		typedef void(*FUNC_OnChannelMediaRelayEvent)(int code);
		// raw data callback
		typedef void(*FUNC_OnCaptureVideoFrame)(int videoFrameType, int width, int height, int yStride, void* yBuffer, int rotation, int64_t renderTimeMs);
		typedef void(*FUNC_OnRenderVideoFrame)(unsigned int uid, int videoFrameType, int width, int height, int yStride, void* yBuffer, int rotation, int64_t renderTimeMs);
		typedef void(*FUNC_OnRecordAudioFrame)(int type, int samples, int bytesPerSample, int channels, int samplesPerSec, void* buffer, int64_t renderTimeMs, int avsync_type);
		typedef void(*FUNC_OnPlaybackAudioFrame)(int type, int samples, int bytesPerSample, int channels, int samplesPerSec, void* buffer, int64_t renderTimeMs, int avsync_type);
		typedef void(*FUNC_OnMixedAudioFrame)(int type, int samples, int bytesPerSample, int channels, int samplesPerSec, void* buffer, int64_t renderTimeMs, int avsync_type);
		typedef void(*FUNC_OnPlaybackAudioFrameBeforeMixing)(unsigned int uid, int type, int samples, int bytesPerSample, int channels, int samplesPerSec, void* buffer, int64_t renderTimeMs, int avsync_type);
		typedef void(*FUNC_OnPullAudioFrame)(int type, int samples, int bytesPerSample, int channels, int samplesPerSec, void* buffer, int64_t renderTimeMs, int avsync_type);
		typedef void(*FUNC_OnAudioMixingStateChanged)(int audioMixingStateType, int audioMixingErrorType);
		typedef void(*FUNC_OnFirstRemoteAudioDecoded)(uid_t uid, int elapsed);
		typedef void(*FUNC_OnLocalVideoStateChanged)(int localVideoState, int error);
		typedef void(*FUNC_OnNetworkTypeChanged)(int networkType);
		typedef void(*FUNC_OnLastmileProbeResult)(int state, unsigned int upLinkPacketLossRate, unsigned int upLinkjitter, unsigned int upLinkAvailableBandwidth, unsigned int downLinkPacketLossRate, unsigned int downLinkJitter, unsigned int downLinkAvailableBandwidth, unsigned int rtt);
		typedef bool(*FUNC_OnSendAudioPacket)(const unsigned char *buffer, void *size);
		typedef bool(*FUNC_OnSendVideoPacket)(const unsigned char *buffer, void *size);
		typedef bool(*FUNC_OnReceiveAudioPacket)(const unsigned char *buffer, void *size);
		typedef bool(*FUNC_OnReceiveVideoPacket)(const unsigned char *buffer, void *size);		
		typedef bool(*FUNC_OnReadyToSendMetadata)();
		typedef void(*FUNC_OnMetadataReceived)(unsigned int uid, unsigned int size, unsigned char *buffer, long long timeStampMs);
		typedef int(*FUNC_OnGetMaxMetadataSize)();
	
	
		typedef void(*FUNC_OnChannelWarning)(const char* channelId, int warn, const char* msg);
		typedef void(*FUNC_OnChannelError)(const char* channelId, int err, const char* msg);
		typedef void(*FUNC_OnChannelJoinChannelSuccess)(const char* channelId, uid_t uid, int elapsed);
		typedef void(*FUNC_OnChannelReJoinChannelSuccess)(const char* channelId, uid_t uid, int elapsed);
		typedef void(*FUNC_OnChannelLeaveChannel)(const char* channelId, unsigned int duration, unsigned int txBytes, unsigned int rxBytes, unsigned int txAudioBytes, unsigned int txVideoBytes, unsigned int rxAudioBytes, unsigned int rxVideoBytes, unsigned short txKBitRate, unsigned short rxKBitRate, unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate, unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate, unsigned short lastmileDelay, unsigned short txPacketLossRate, unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage, double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio, double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
		typedef void(*FUNC_OnChannelClientRoleChanged)(const char* channelId, int oldRole, int newRole);
		typedef void(*FUNC_OnChannelUserJoined)(const char* channelId, uid_t uid, int elapsed);
        typedef void(*FUNC_OnChannelUserOffLine)(const char* channelId, uid_t uid, int reason);
        typedef void(*FUNC_OnChannelConnectionLost)(const char* channelId);
        typedef void(*FUNC_OnChannelRequestToken)(const char* channelId);
		typedef void(*FUNC_OnChannelTokenPrivilegeWillExpire)(const char* channelId, const char* token);
        typedef void(*FUNC_OnChannelRtcStats)(const char* channelId, unsigned int duration, unsigned int txBytes, unsigned int rxBytes, unsigned int txAudioBytes, unsigned int txVideoBytes, unsigned int rxAudioBytes, unsigned int rxVideoBytes, unsigned short txKBitRate, unsigned short rxKBitRate, unsigned short rxAudioKBitRate, unsigned short txAudioKBitRate, unsigned short rxVideoKBitRate, unsigned short txVideoKBitRate, unsigned short lastmileDelay, unsigned short txPacketLossRate, unsigned short rxPacketLossRate, unsigned int userCount, double cpuAppUsage, double cpuTotalUsage, int gatewayRtt, double memoryAppUsageRatio, double memoryTotalUsageRatio, int memoryAppUsageInKbytes);
		typedef void(*FUNC_OnChannelNetworkQuality)(const char* channelId, uid_t uid, int txQuality, int rxQuality);
        typedef void(*FUNC_OnChannelRemoteVideoStats)(const char* channelId, uid_t uid, int delay, int width, int height, int receivedBitrate, int decoderOutputFrameRate, int rendererOutputFrameRate, int packetLossRate, int rxStreamType, int totalFrozenTime, int frozenRate, int totalActiveTime);
		typedef void(*FUNC_OnChannelRemoteAudioStats)(const char* channelId, uid_t uid, int quality, int networkTransportDelay, int jitterBufferDelay, int audioLossRate, int numChannels, int receivedSampleRate, int receivedBitrate, int totalFrozenTime, int frozenRate, int totalActiveTime);
		typedef void(*FUNC_OnChannelRemoteAudioStateChanged)(const char* channelId, uid_t uid, int state, int reason, int elapsed);
		typedef void(*FUNC_OnChannelActiveSpeaker)(const char* channelId, uid_t uid);            
		typedef void(*FUNC_OnChannelVideoSizeChanged)(const char* channelId, uid_t uid, int width, int height, int rotation);
		typedef void(*FUNC_OnChannelRemoteVideoStateChanged)(const char* channelId, uid_t uid, int state, int reason, int elapsed);
		typedef void(*FUNC_OnChannelStreamMessage)(const char* channelId, uid_t uid, int streamId, const char* data, size_t length);
		typedef void(*FUNC_OnChannelStreamMessageError)(const char* channelId, uid_t uid, int streamId, int code, int missed, int cached);
		typedef void(*FUNC_OnChannelMediaRelayStateChanged2)(const char* channelId, int state, int code);
		typedef void(*FUNC_OnChannelMediaRelayEvent2)(const char* channelId, int code);
		typedef void(*FUNC_OnChannelRtmpStreamingStateChanged)(const char* channelId, const char *url, int state, int errCode);
		typedef void(*FUNC_OnChannelTranscodingUpdated)(const char* channelId);
		typedef void(*FUNC_OnChannelStreamInjectedStatus)(const char* channelId, const char* url, uid_t uid, int status);
		typedef void(*FUNC_OnChannelRemoteSubscribeFallbackToAudioOnly)(const char* channelId, uid_t uid, bool isFallbackOrRecover);
		typedef void(*FUNC_OnChannelConnectionStateChanged)(const char* channelId, int state, int reason);
		typedef void(*FUNC_OnFacePositionChanged)(int imageWidth, int imageHeight, int x, int y, int width, int height, int vecDistance, int numFaces);
		typedef void(*FUNC_OnChannelLocalPublishFallbackToAudioOnly)(const char* channelId, bool isFallbackOrRecover);
		#endif
	}
}
#endif
