#ifndef I_AGORA_UNITY_INTERFACE
#define I_AGORA_UNITY_INTERFACE
#include "AgoraSDKObject.h"
#include <string.h>
#ifdef WIN32
#include "facade_screen_capture.h"
#endif

using namespace std;

namespace agora {
    namespace unity {
        const char *TAG = "I_AGORA_UNITY_INTERFACE";
		std::unique_ptr <FacadeScreenCapture> m_facadeScreenCapture;
        AGORA_API bool createEngine(const char *appId);
        AGORA_API bool createEngine2(const char *appId, unsigned int areaCode);
        AGORA_API bool deleteEngine();
        AGORA_API const char *getSdkVersion();
        AGORA_API int joinChannel(const char *channelKey, const char *channelName, const char *info, unsigned int uid);
        AGORA_API int renewToken(const char *token);
        AGORA_API int leaveChannel();
        AGORA_API int enableLastmileTest();
        AGORA_API int disableLastmileTest();
        AGORA_API int startLastmileProbeTest(bool probeUplink, bool probeDownlink, unsigned int expectedUplinkBitrate, unsigned int expectedDownlinkBitrate);
        AGORA_API int stopLastmileProbeTest();
        AGORA_API int enableVideo();
        AGORA_API int disableVideo();
        AGORA_API int enableLocalVideo(bool enabled);
        AGORA_API int setupLocalVideo(int hwnd, int renderMode, uid_t uid, void* priv);
        AGORA_API int setupRemoteVideo(int hwnd, int renderMode, uid_t uid, void* priv);
        AGORA_API int setLocalRenderMode(int renderMode);
        AGORA_API int setRemoteRenderMode(uid_t userId, int renderMode);
        AGORA_API int setLocalVideoMirrorMode(int mirrorMode);
        AGORA_API int startPreview();
        AGORA_API int stopPreview();
        AGORA_API int enableAudio();
        AGORA_API int enableLocalAudio(bool enabled);
        AGORA_API int disableAudio();
        AGORA_API int setParameters(const char *options);
        AGORA_API char *getParameter(const char *parameter, const char *args);
        AGORA_API char *getCallId();
        AGORA_API int rate(const char *callId, int rating, const char *desc);
        AGORA_API int complain(const char *callId, const char *desc);
        AGORA_API int setEnableSpeakerphone(int enabled);
        AGORA_API bool isSpeakerphoneEnabled();
        AGORA_API int setDefaultAudioRoutetoSpeakerphone(bool defaultToSpeaker);
        AGORA_API int setSpeakerphoneVolume(int volume);
        AGORA_API int enableAudioVolumeIndication(int interval, int smooth, bool report_vad);
        AGORA_API int startAudioRecording(const char *filePath, int quality);
        AGORA_API int startAudioRecording2(const char* filePath, int sampleRate, int quality);
        AGORA_API int stopAudioRecording();
        AGORA_API int startAudioMixing(const char *filePath, bool loopBack, bool replace, int cycle);
        AGORA_API int stopAudioMixing();
        AGORA_API int pauseAudioMixing();
        AGORA_API int resumeAudioMixing();
        AGORA_API int adjustAudioMixingVolume(int volume);
        AGORA_API int getAudioMixingDuration();
        AGORA_API int getAudioMixingCurrentPosition();
        AGORA_API int setAudioMixingPosition(int pos);
        AGORA_API int startEchoTest();
        AGORA_API int startEchoTest2(int intervalInSeconds);
        AGORA_API int stopEchoTest();
        AGORA_API int muteLocalAudioStream(bool muted);
        AGORA_API int muteAllRemoteAudioStreams(bool muted);
        AGORA_API int muteRemoteAudioStream(unsigned int uid, bool muted);
        AGORA_API int switchCamera();
        AGORA_API int setVideoProfile(int profile, bool swapWidthAndHeight);
        AGORA_API int muteLocalVideoStream(bool muted);
        AGORA_API int muteAllRemoteVideoStreams(bool muted);
        AGORA_API int muteRemoteVideoStream(unsigned int uid, bool muted);
        AGORA_API int setLogFile(const char *filePath);
        AGORA_API int setLogFilter(unsigned int filter);
        AGORA_API int setChannelProfile(int profile);
        AGORA_API int setClientRole(int role);
        AGORA_API int enableDualStreamMode(bool enabled);
        AGORA_API int setEncryptionMode(const char *encryptionMode);
        AGORA_API int setEncryptionSecret(const char *secret);
        AGORA_API int setRemoteVideoStreamType(unsigned int uid, int streamType);
        AGORA_API int startRecordingService(const char *recordingKey);
        AGORA_API int stopRecordingService(const char *recordingKey);
        AGORA_API int refreshRecordingServiceStatus();
        AGORA_API int createDataStream(bool reliable, bool ordered);
        AGORA_API int sendStreamMessage(int streamId, const char *data, size_t length);
        AGORA_API int setRecordingAudioFrameParametersWithSampleRate(int sampleRate, int channel, int mode, int samplesPerCall);
        AGORA_API int setPlaybackAudioFrameParametersWithSampleRate(int sampleRate, int channel, int mode, int samplesPerCall);
        AGORA_API int setMixedAudioFrameParameters(int sampleRate, int samplesPerCall);
        AGORA_API int adjustRecordingSignalVolume(int volume);
        AGORA_API int adjustPlaybackSignalVolume(int volume);
        AGORA_API int setHighQualityAudioParametersWithFullband(int fullband, int stereo, int fullBitrate);
        AGORA_API int enableInEarMonitoring(bool enabled);
        AGORA_API int enableWebSdkInteroperability(bool enabled);
        AGORA_API int setVideoQualityParameters(bool preferFrameRateOverImageQuality);
        AGORA_API int setRemoteVoicePosition(uid_t uid, double pan, double gain);
        AGORA_API int setVoiceOnlyMode(bool enabled);
        AGORA_API int setPlaybackDeviceVolume(int volume);
        AGORA_API int getEffectsVolume();
        AGORA_API int setEffectsVolume(int volume);
        AGORA_API int playEffect(int soundId, const char *filePath, int loopCount, double pitch, double pan, int gain, bool publish = false);
        AGORA_API int stopEffect(int soundId);
        AGORA_API int stopAllEffects();
        AGORA_API int preloadEffect(int soundId, char *filePath);
        AGORA_API int unloadEffect(int soundId);
        AGORA_API int pauseEffect(int soundId);
        AGORA_API int pauseAllEffects();
        AGORA_API int resumeEffect(int soundId);
        AGORA_API int resumeAllEffects();
        AGORA_API void freeObject(void *obj);
        AGORA_API int setDefaultMuteAllRemoteAudioStreams(bool mute);
        AGORA_API int setDefaultMuteAllRemoteVideoStreams(bool mute);
        AGORA_API int pushVideoFrame(int type, int format, void* videoBuffer, int stride, int height, int cropLeft, int cropTop, int cropRight, int cropBottom, int rotation, int64_t timestamp);
        AGORA_API int setExternalVideoSource(bool enable, bool useTexture);
        AGORA_API int setExternalAudioSource(bool enabled, int sampleRate, int channels);
        AGORA_API int pushAudioFrame_(int audioFrameType, int samples, int bytesPerSample, int channels, int samplesPerSec, void* buffer, int64_t renderTimeMs, int avsync_type);
        AGORA_API int pushAudioFrame2_(int mediaSourceType, int audioFrameType, int samples, int bytesPerSample, int channels, int samplesPerSec, void *buffer, int64_t renderTimeMs, int avsync_type, bool wrap);
        AGORA_API int getConnectionState();
        AGORA_API int setAudioProfile(int audioProfile, int scenario);
        AGORA_API int setVideoEncoderConfiguration(int width, int height, int frameRate, int minFrameRate, int bitrate, int minBitrate, int orientationMode, int degradationPreference, int videoMirrorMode);
        AGORA_API int adjustAudioMixingPlayoutVolume(int volume);
        AGORA_API int adjustAudioMixingPublishVolume(int volume);
        AGORA_API int setVolumeOfEffect(int soundId, int volume);
        AGORA_API int setRecordingAudioFrameParameters(int sampleRate, int channel, int mode, int samplesPerCall);
        AGORA_API int setPlaybackAudioFrameParameters(int sampleRate, int channel, int mode, int samplesPerCall);
        AGORA_API int setMixedAudioFrameParameters(int sampleRate, int samplesPerCall);
        AGORA_API int setLocalPublishFallbackOption(int option);
        AGORA_API int setRemoteSubscribeFallbackOption(int option);
        AGORA_API int setRemoteDefaultVideoStreamType(int remoteVideoStreamType);
        AGORA_API int addPublishStreamUrl(const char *url, bool transcodingEnabled);
        AGORA_API int removePublishStreamUrl(const char *url);
        AGORA_API int configPublisher(int width, int height, int framerate,	int bitrate, int defaultLayout, int lifecycle, bool owner, int injectStreamWidth, int injectStreamHeight, const char* injectStreamUrl, const char* publishUrl, const char* rawStreamUrl, const char* extraInfo);
        AGORA_API const char *getErrorDescription(int code);
        AGORA_API int setLiveTranscoding(int width, int height, int videoBitrate, int videoFramerate, bool lowLatency, int videoGroup, int video_codec_profile, unsigned int backgroundColor, unsigned int userCount, const char *transcodingUserInfo, const char *transcodingExtraInfo, const char *metaData, const char *watermarkRtcImageUrl, int watermarkRtcImageX, int watermarkRtcImageY, int watermarkRtcImageWidth, int watermarkRtcImageHeight, const char *backgroundImageRtcImageUrl, int backgroundImageRtcImageX, int backgroundImageRtcImageY, int backgroundImageRtcImageWidth, int backgroundImageRtcImageHeight, int audioSampleRate, int audioBitrate, int audioChannels, int audioCodecProfile);
        AGORA_API int setLocalVoiceChanger(int voiceChanger);
        AGORA_API int setLocalVoiceReverbPreset(int audioReverbPreset);
        AGORA_API int setLocalVoicePitch(double pitch);
        AGORA_API int setLocalVoiceEqualization(int bandFrequency, int bandGain);
        AGORA_API int setLocalVoiceReverb(int reverbKey, int value);
        AGORA_API int enableSoundPositionIndication(bool enabled);
        AGORA_API int setCameraCapturerConfiguration(int cameraCaptureConfiguration, int cameraDirection);
        AGORA_API int setRemoteUserPriority(uid_t uid, int userPriority);
        AGORA_API int setLogFileSize(unsigned int fileSizeInKBytes);
        AGORA_API int setExternalAudioSink(bool enabled, int sampleRate, int channels);
        AGORA_API int addVideoWatermark(const char* url, int x, int y, int width, int height);
        AGORA_API int addVideoWatermark2(const char* watermarkUrl, bool visibleInPreview, int positionInLandscapeX, int positionInLandscapeY, int positionInLandscapeWidth, int positionInLandscapeHeight, int positionInPortraitX, int positionInPortraitY, int positionInPortraitWidth, int positionInPortraitHeight);
        AGORA_API int clearVideoWatermarks();
        AGORA_API int registerLocalUserAccount(const char* appId, const char* userAccount);
        AGORA_API int joinChannelWithUserAccount(const char* token, const char* channelId, const char* userAccount);
        AGORA_API int getUserInfoByUserAccount(const char *userAccount);
        AGORA_API char* getUserInfoByUid(uid_t uid);
        AGORA_API int setBeautyEffectOptions(bool enabled, int lighteningContrastLevel, float lighteningLevel, float smoothnessLevel, float rednessLevel);
        AGORA_API int setMirrorApplied(bool wheatherApply);
        //video render api
        AGORA_API int registerVideoRawDataObserver();
        AGORA_API int unRegisterVideoRawDataObserver();
        AGORA_API int registerAudioRawDataObserver();
        AGORA_API int unRegisterAudioRawDataObserver();
        AGORA_API int enableVideoObserver();
        AGORA_API int disableVideoObserver();
        AGORA_API int generateNativeTexture();
        AGORA_API int updateTexture(int texId, unsigned char *data, unsigned int uid);
        AGORA_API void deleteTexture(int tex);
        AGORA_API int setRenderMode(int renderMode);
        AGORA_API int updateVideoRawData(void *data, unsigned int uid);   
        AGORA_API void addUserVideoInfo(unsigned int _userId, unsigned int _textureId);
        AGORA_API void removeUserVideoInfo(unsigned int _userId);
        //video device manager
        AGORA_API bool createAVideoDeviceManager();
        AGORA_API int releaseAVideoDeviceManager();
        AGORA_API int startVideoDeviceTest(view_t hwnd);
        AGORA_API int stopVideoDeviceTest();
        AGORA_API int getVideoDeviceCollectionCount();
        AGORA_API int getVideoDeviceCollectionDevice(int index, char *deviceName, char *deviceId);
        AGORA_API int getCurrentVideoDevice(char deviceId[LENGTH_MAX]);
        AGORA_API int setVideoDeviceCollectionDevice(const char *deviceId);
        // audio recording device manager
        AGORA_API bool creatAAudioRecordingDeviceManager();
        AGORA_API int releaseAAudioRecordingDeviceManager();
        AGORA_API int getAudioRecordingDeviceCount();
        AGORA_API int getAudioRecordingDevice(int index, char *audioRecordingDeviceName, char *audioRecordingDeviceId);
        AGORA_API int setAudioRecordingDevice(const char *deviceId);
        AGORA_API int setAudioRecordingDeviceVolume(int volume);
        AGORA_API int getAudioRecordingDeviceVolume();
        AGORA_API int setAudioRecordingDeviceMute(bool mute);
        AGORA_API bool isAudioRecordingDeviceMute();
        AGORA_API int startAudioRecordingDeviceTest(int indicationInterval);
        AGORA_API int stopAudioRecordingDeviceTest();
		AGORA_API int getCurrentRecordingDevice(char deviceId[LENGTH_MAX]);
		AGORA_API int getCurrentRecordingDeviceInfo(char deviceName[LENGTH_MAX], char deviceId[LENGTH_MAX]);
        AGORA_API int setInEarMonitoringVolume(int volume);
        AGORA_API int startScreenCaptureByWindowId(int windowId, int regionRectX, int regionRectY, int regionRectWidth, int regionRectHeight,  int screenCaptureVideoDimenWidth, int screenCaptureVideoDimenHeight, int screenCaptureFrameRate, int screenCaptureBitrate, bool screenCaptureCaptureMouseCursor);
        AGORA_API int startScreenCaptureByDisplayId(unsigned int displayId, int x, int y, int width, int height, int screenCaptureVideoDimenWidth, int screenCaptureVideoDimenHeight, int screenCaptureFrameRate, int screenCaptureBitrate, bool screenCaptureCaptureMouseCursor);
        AGORA_API int startScreenCaptureByScreenRect(int screenRectX, int screenRectY, int screenRectWidth, int screenRectHeight, int regionRectX, int regionRectY, int regionRectWidth, int regionRectHeight, int screenCaptureVideoDimenWidth, int screenCaptureVideoDimenHeight, int screenCaptureFrameRate, int screenCaptureBitrate, bool screenCaptureCaptureMouseCursor);
        AGORA_API int setScreenCaptureContentHint(int videoContentHint);
        AGORA_API int updateScreenCaptureParameters(int screenCaptureVideoDimenWidth, int screenCaptureVideoDimenHeight, int screenCaptureFrameRate, int screenCaptureBitrate, bool screenCaptureCaptureMouseCursor);
        AGORA_API int updateScreenCaptureRegion(int x, int y, int width, int height);
		AGORA_API void prepareGameShare();
		AGORA_API void prepareGame(const char *exe_path);
		AGORA_API int startWindowsShareByExePath(int width, int height, int captureFreq, int bitrate, const char *exe_path, unsigned int uid);
		AGORA_API int startProcessSharedFromVideo(int width, int height, int captureFreq, int bitrate);
		AGORA_API int startProcessSharedFromAudio();
		AGORA_API int stopProcessSharedFromAudio();
		AGORA_API void setLogFileFromPath(const char* filePath);
		AGORA_API int stopScreenCaptureEx();
		AGORA_API int setTextureCapture();
		AGORA_API bool enableHardWareEncoder();
        AGORA_API int stopScreenCapture();
        AGORA_API int enableLoopbackRecording(bool enabled, const char *deviceName);
        AGORA_API int setAudioSessionOperationRestriction(int restriction);
        //audio playback device manager
        AGORA_API bool creatAAudioPlaybackDeviceManager();
        AGORA_API int releaseAAudioPlaybackDeviceManager();
        AGORA_API int getAudioPlaybackDeviceCount();
        AGORA_API int getAudioPlaybackDevice(int index, char* deviceName, char* deviceId);
        AGORA_API int setAudioPlaybackDevice(const char *deviceId);
        AGORA_API int setAudioPlaybackDeviceVolume(int volume);
        AGORA_API int getAudioPlaybackDeviceVolume();
        AGORA_API int setAudioPlaybackDeviceMute(bool mute);
        AGORA_API bool isAudioPlaybackDeviceMute();
        AGORA_API int startAudioPlaybackDeviceTest(const char* testAudioFilePath);
        AGORA_API int stopAudioPlaybackDeviceTest();
		AGORA_API int getCurrentPlaybackDevice(char deviceId[LENGTH_MAX]);
		AGORA_API int getCurrentPlaybackDeviceInfo(char deviceName[LENGTH_MAX], char deviceId[LENGTH_MAX]);

        AGORA_API int getAudioMixingPlayoutVolume();
        AGORA_API int getAudioMixingPublishVolume();
        AGORA_API int addInjectStreamUrl(const char *url, int width, int height, int videoGop, int videoFramerate, int videoBitrate, int audioSampleRate, int audioBitrate, int audioChannels);
        AGORA_API int removeInjectStreamUrl(const char* url);
        AGORA_API int switchChannel(const char* token, const char* channelId);
        AGORA_API int startChannelMediaRelay(const char* srcChannelName, const char* srcToken , uid_t srcUid, const char* destChannelName, const char* destToken, uid_t destUid, int destCount);
        AGORA_API int updateChannelMediaRelay(const char* srcChannelName, const char* srcToken , uid_t srcUid, const char* destChannelName, const char* destToken, uid_t destUid, int destCount);
        AGORA_API int stopChannelMediaRelay();
        AGORA_API int pullAudioFrame_(void *audioBuffer, int type, int samples, int bytesPerSample, int channels, int samplesPerSec, long long renderTimeMs, int avsync_type);
        //packet observer
        AGORA_API int registerPacketObserver();
        AGORA_API int unRegisterPacketObserver();
        // AGORA_API int sendAudioPacket(unsigned char* buffer, unsigned int size);
        // AGORA_API int sendVideoPacket(unsigned char* buffer, unsigned int size);
        AGORA_API int sendMetadata(unsigned int uid, unsigned int size, unsigned char *buffer, long long timeStamps);
        AGORA_API int registerMediaMetadataObserver(int metaDataType);
        AGORA_API int unRegisterMediaMetadataObserver();
        AGORA_API int setDefaultEngineSettings();
        AGORA_API int adjustUserPlaybackSignalVolume(unsigned int uid, int volume); 
        AGORA_API int setAudioMixingPitch(int pitch);
        //user account manager
        //--------------Callback start------------------
        AGORA_API void initEventOnEngineCallback(FUNC_OnJoinChannelSuccess onJoinChannelSuccess, 
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

         AGORA_API void initChannelEventCallback(void *channel, FUNC_OnChannelWarning onWarning,
        //AGORA_API void initChannelEventCallback(FUNC_OnChannelWarning onWarning,
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

        AGORA_API void initEventOnCaptureVideoFrame(FUNC_OnCaptureVideoFrame onCaptureVideoFrame);
        AGORA_API void initEventOnRenderVideoFrame(FUNC_OnRenderVideoFrame onRenderVideoFrame);
        AGORA_API void initEventOnRecordAudioFrame(FUNC_OnRecordAudioFrame onRecordAudioFrame);
        AGORA_API void initEventOnPlaybackAudioFrame(FUNC_OnPlaybackAudioFrame onPlaybackAudioFrame);
        AGORA_API void initEventOnMixedAudioFrame(FUNC_OnMixedAudioFrame onMixedAudioFrame);
        AGORA_API void initEventOnPlaybackAudioFrameBeforeMixing(FUNC_OnPlaybackAudioFrameBeforeMixing onPlaybackAudioFrameBeforeMixing);
        AGORA_API void initEventOnPullAudioFrame(FUNC_OnPullAudioFrame onPullAudioFrame);
        AGORA_API void initEventOnPacketCallback(FUNC_OnReceiveAudioPacket onReceiveAudioPacket, FUNC_OnReceiveVideoPacket onReceiveVideoPacket, FUNC_OnSendAudioPacket onSendAudioPacket, FUNC_OnSendVideoPacket onSendVideoPacket);
        AGORA_API void initEventOnMetaDataCallback(FUNC_OnMetadataReceived onMetadataReceived, FUNC_OnReadyToSendMetadata onReadyToSendMetadata, FUNC_OnGetMaxMetadataSize onGetMaxMetadataSize);

        // multiChannel

        AGORA_API void *createChannel(const char *channelId);
      
        AGORA_API int ReleaseChannel(void *channel);

        AGORA_API int joinChannel2(void *channel, const char* token,
                                const char* info,
                                uid_t uid,
                                bool autoSubscribeAudio,
                                bool autoSubscribeVideo);

        AGORA_API int joinChannelWithUserAccount2(void *channel, const char* token,
                                                const char* userAccount,
                                                bool autoSubscribeAudio,
                                                bool autoSubscribeVideo);
        
        AGORA_API int leaveChannel2(void *channel);
        
        AGORA_API int publish(void *channel);
        
        AGORA_API int unpublish(void *channel);
        
        AGORA_API const char *channelId(void *channel);
        
        AGORA_API char *getCallId2(void *channel);

        AGORA_API int renewToken2(void *channel, const char* token);
        
        AGORA_API int setEncryptionSecret2(void *channel, const char* secret);
        
        AGORA_API int setEncryptionMode2(void *channel, const char* encryptionMode);
        
        // virtual int registerPacketObserver(void *channel, IPacketObserver* observer);
        
        // virtual int registerMediaMetadataObserver(void *channel, IMetadataObserver *observer, IMetadataObserver::METADATA_TYPE type);
        
        AGORA_API int setClientRole2(void *channel, int role);
        
        AGORA_API int setRemoteUserPriority2(void *channel, uid_t uid, int userPriority);

        AGORA_API int setRemoteVoicePosition2(void *channel, uid_t uid, double pan, double gain);

        AGORA_API int setRemoteRenderMode2(void *channel, uid_t userId, int renderMode, int mirrorMode);

        AGORA_API int setDefaultMuteAllRemoteAudioStreams2(void *channel, bool mute);
        
        AGORA_API int setDefaultMuteAllRemoteVideoStreams2(void *channel, bool mute);
        
        AGORA_API int muteAllRemoteAudioStreams2(void *channel, bool mute);

        AGORA_API int adjustUserPlaybackSignalVolume2(void *channel, uid_t userId, int volume);

        AGORA_API int muteRemoteAudioStream2(void *channel, uid_t userId, bool mute);
        
        AGORA_API int muteAllRemoteVideoStreams2(void *channel, bool mute);
        
        AGORA_API int muteRemoteVideoStream2(void *channel, uid_t userId, bool mute);
        
        AGORA_API int setRemoteVideoStreamType2(void *channel, uid_t userId, int streamType);
        
        AGORA_API int setRemoteDefaultVideoStreamType2(void *channel, int streamType);

        AGORA_API int createDataStream2(void *channel, bool reliable, bool ordered);
        
        AGORA_API int sendStreamMessage2(void *channel, int streamId, const char* data, size_t length);
        
        AGORA_API int addPublishStreamUrl2(void *channel, const char *url, bool transcodingEnabled);
        
        AGORA_API int removePublishStreamUrl2(void *channel, const char *url);
        
        AGORA_API int setLiveTranscoding2(void *channel, int width, int height, int videoBitrate, int videoFramerate, bool lowLatency, int videoGroup, int video_codec_profile, unsigned int backgroundColor, unsigned int userCount, const char *trancodingUserInfo, const char *transcodingExtraInfo, const char *metaData, const char *watermarkRtcImageUrl, int watermarkRtcImageX, int watermarkRtcImageY, int watermarkRtcImageWidth, int watermarkRtcImageHeight, const char *backgroundImageRtcImageUrl, int backgroundImageRtcImageX, int backgroundImageRtcImageY, int backgroundImageRtcImageWidth, int backgroundImageRtcImageHeight, int audioSampleRate, int audioBitrate, int audioChannels, int audioCodecProfile);
        
        AGORA_API int addInjectStreamUrl2(void *channel, const char* url, int width, int height, int videoGop, int videoFramerate, int videoBitrate, int audioSampleRate, int audioBitrate, int audioChannels);
        
        AGORA_API int removeInjectStreamUrl2(void *channel, const char* url);
        
        AGORA_API int startChannelMediaRelay2(void *channel, const char *srcChannelName, const char *srcToken , uid_t srcUid, const char *destChannelName, const char *destToken, uid_t destUid, int destCount);
                                            
        AGORA_API int updateChannelMediaRelay2(void *channel, const char *srcChannelName, const char *srcToken , uid_t srcUid, const char *destChannelName, const char *destToken, uid_t destUid, int destCount);
        
        AGORA_API int stopChannelMediaRelay2(void *channel);
        
        AGORA_API int getConnectionState2(void *channel);

        AGORA_API int setMultiChannelWant(bool multiChannelWant);

        AGORA_API bool getMultiChannelWanted();
        
        AGORA_API void addUserVideoInfo2(const char *channelId, unsigned int _userId, unsigned int _textureId);
        
        AGORA_API void removeUserVideoInfo2(const char *channelId, unsigned int _userId);
        
        AGORA_API int updateVideoRawData2(void *data, const char *channelId, unsigned int uid);
        //--------------Callback end------------------

        AGORA_API int enableFaceDetection(bool enable);
        #if defined(WRAPPER_ANDROID)
        extern "C" jint JNI_OnLoad(JavaVM *vm, void *);
        #endif    
    }
}
#endif
