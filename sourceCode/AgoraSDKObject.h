#ifndef AGORA_WRAPPER_SDK_Object
#define AGORA_WRAPPER_SDK_Object
#include "CWrapperRtcEngineEventHandler.h"
#include "videoRender/VideoRender.h"
#include "videoRender/UnityVideoFrameObserver.h"
#include "deviceManager/AgoraAudioRecordingDeviceManager.h"
#include "deviceManager/AgoraAudioPlaybackDeviceManager.h"
#include "deviceManager/AgoraVideoDeviceManager.h"
#include "rawDataControl/AudioRawDataControl.h"
#include "rawDataControl/VideoRawDataControl.h"
#include "observer/PacketObserver.h"
#include "observer/MetaDataObserver.h"
#include "ChannelEventHandler.h"
#include <string.h>
#include <iterator>

namespace agora
{
  namespace unity
  {
    class CAgoraSDKObject
    {
    private:
      CAgoraSDKObject();
      static CAgoraSDKObject *cAgoraSDKObjectInstance;
      IRtcEngine *irtcEngine = nullptr;
      CWrapperRtcEngineEventHandler *cWrapperRtcEngineEventHandler = nullptr;
      UnityVideoFrameObserver *_unityVideoFrameObserver = nullptr;
      VideoRender *_videoRender;
      AAudioDeviceManager *audioDeviceManager = nullptr;
      AVideoDeviceManager *videoDeviceManager = nullptr;
      AudioRawDataControl *audioRawDataControl = nullptr;
      VideoRawDataControl *videoRawDataControl = nullptr;
      PacketObserver *packetObserver = nullptr;
      MetaDataObserver *metaDataObserver = nullptr;
      IAudioFrameObserver::AudioFrame audioFrame;
      std::map<IChannel*, ChannelEventHandler*> channelInfo;
      const char *TAG = "AgoraSDKObject";

    public:
      ~CAgoraSDKObject();
      static CAgoraSDKObject *getCAgoraSDKInstance();
      static void releaseCAgoraSDKInstance();
      static CAgoraSDKObject *getCAgoraSDKObject();
      CWrapperRtcEngineEventHandler *getCWrapperRtcEngineEventHandler();
      AudioRawDataControl *getAudioRawDataControl();
      VideoRawDataControl *getVideoRawDataControl();
      IRtcEngine *getIRtcEngine();
      virtual bool createEngine(const char *appId);
      virtual bool createEngine2(const char *appId, unsigned int areaCode);
      virtual void deleteEngine();
      virtual const char *getSdkVersion();
      virtual int joinChannel(const char *channelKey, const char *channelName, const char *info, uid_t uid);
      virtual int renewToken(const char *token);
      virtual int leaveChannel();
      virtual int enableLastmileTest();
      virtual int disableLastmileTest();
      virtual int startLastmileProbeTest(bool probeUplink, bool probeDownlink, unsigned int expectedUplinkBitrate, unsigned int expectedDownlinkBitrate);
      virtual int stopLastmileProbeTest();
      virtual int configPublisher(int width, int height, int framerate,	int bitrate, int defaultLayout, int lifecycle, bool owner, int injectStreamWidth, int injectStreamHeight, const char *injectStreamUrl, const char *publishUrl, const char *rawStreamUrl, const char *extraInfo);
      virtual int addVideoWatermark(const char *url, int x, int y, int width, int height);
      virtual int addVideoWatermark(const char* watermarkUrl, bool visibleInPreview, int positionInLandscapeX, int positionInLandscapeY, int positionInLandscapeWidth, int positionInLandscapeHeight, int positionInPortraitX, int positionInPortraitY, int positionInPortraitWidth, int positionInPortraitHeight);
      virtual int clearVideoWatermarks();
      virtual int enableVideo();
      virtual int disableVideo();
      virtual int enableLocalVideo(bool enabled);
      virtual int startPreview();
      virtual int stopPreview();
      virtual int enableAudio();
      virtual int enableLocalAudio(bool enabled);
      virtual int disableAudio();
      virtual int setParameters(const char *options);
      virtual char *getParameter(const char *parameter, const char *args);
      virtual std::string getCallId();
      virtual int rate(const char *callId, int rating, const char *desc);
      virtual int complain(const char *callId, const char *desc);
      virtual int setEnableSpeakerphone(int enabled);
      virtual bool isSpeakerphoneEnabled();
      virtual int setDefaultAudioRouteToSpeakerphone(bool defaultToSpeaker);
      virtual int setSpeakerphoneVolume(int volume);
      virtual int enableAudioVolumeIndication(int interval, int smooth, bool report_vad);
      virtual int startAudioRecording(const char *filePath, int quality);
      virtual int startAudioRecording(const char* filePath, int sampleRate, int quality);
      virtual int stopAudioRecording();
      virtual int startAudioMixing(const char *filePath, bool loopBack, bool replace, int cycle);
      virtual int stopAudioMixing();
      virtual int pauseAudioMixing();
      virtual int resumeAudioMixing();
      virtual int adjustAudioMixingVolume(int volume);
      virtual int getAudioMixingDuration();
      virtual int getAudioMixingCurrentPosition();
      virtual int setAudioMixingPosition(int pos);
      virtual int startEchoTest();
      virtual int startEchoTest(int intervalInSeconds);
      virtual int stopEchoTest();
      virtual int muteLocalAudioStream(bool muted);
      virtual int muteAllRemoteAudioStreams(bool muted);
      virtual int muteRemoteAudioStream(uid_t uid, bool muted);
      virtual int switchCamera();
      virtual int setVideoProfile(int profile, bool swapWidthAndHeight);
      virtual int muteLocalVideoStream(bool muted);
      virtual int muteAllRemoteVideoStreams(bool muted);
      virtual int muteRemoteVideoStream(uid_t uid, bool muted);
      virtual int setLogFile(const char *filePath);
      virtual int setLogFilter(unsigned int filter);
      virtual int setChannelProfile(int profile);
      virtual int setClientRole(int role);
      virtual int enableDualStreamMode(bool enabled);
      virtual int setEncryptionMode(const char *encryptionMode);
      virtual int setEncryptionSecret(const char *secret);
      virtual int setRemoteVideoStreamType(uid_t uid, int streamType);
      virtual int startRecordingService(const char *recordingKey);
      virtual int stopRecordingService(const char *recordingKey);
      virtual int refreshRecordingServiceStatus();
      virtual int createDataStream(int *streamId, bool reliable, bool ordered);
      virtual int sendStreamMessage(int streamId, const char *data, size_t length);
      virtual int setRecordingAudioFrameParametersWithSampleRate(int sampleRate, int channel, int mode, int samplesPerCall);
      virtual int setPlaybackAudioFrameParametersWithSampleRate(int sampleRate, int channel, int mode, int samplesPerCall);
      virtual int setMixedAudioFrameParameters(int sampleRate, int samplesPerCall);
      virtual int adjustRecordingSignalVolume(int volume);
      virtual int adjustPlaybackSignalVolume(int volume);
      virtual int setHighQualityAudioParametersWithFullband(int fullband, int stereo, int fullBitrate);
      virtual int enableInEarMonitoring(bool enabled);
      virtual int enableWebSdkInteroperability(bool enabled);
      virtual int setVideoQualityParameters(bool preferFrameRateOverImageQuality);
      virtual int setRemoteVoicePosition(uid_t uid, double pan, double gain);
      virtual int setVoiceOnlyMode(bool enabled);
      virtual int setPlaybackDeviceVolume(int volume);
      virtual int getEffectsVolume();
      virtual int setEffectsVolume(int volume);
      virtual int playEffect(int soundId, const char *filePath, int loopCount, double pitch, double pan, int gain, bool publish = false);
      virtual int stopEffect(int soundId);
      virtual int stopAllEffects();
      virtual int preloadEffect(int soundId, char *filePath);
      virtual int unloadEffect(int soundId);
      virtual int pauseEffect(int soundId);
      virtual int pauseAllEffects();
      virtual int resumeEffect(int soundId);
      virtual int resumeAllEffects();
      virtual int setDefaultMuteAllRemoteAudioStreams(bool mute);
      virtual int setDefaultMuteAllRemoteVideoStreams(bool mute);
      virtual int getConnectionState();
      virtual int setAudioProfile(int audioProfile, int scenario);
      virtual int setVideoEncoderConfiguration(int width, int height, int frameRate, int minFrameRate, int bitrate, int minBitrate, int orientationMode, int degradationPreference, int videoMirrorMode);
      virtual int adjustAudioMixingPlayoutVolume(int volume);
      virtual int adjustAudioMixingPublishVolume(int volume);
      virtual int setVolumeOfEffect(int soundId, int volume);
      virtual int setRecordingAudioFrameParameters(int sampleRate, int channel, int mode, int samplesPerCall);
      virtual int setPlaybackAudioFrameParameters(int sampleRate, int channel, int mode, int samplesPerCall);
      virtual int setLocalPublishFallbackOption(int option);
      virtual int setRemoteSubscribeFallbackOption(int option);
      virtual int setRemoteDefaultVideoStreamType(int remoteVideoStreamType);
      virtual int addPublishStreamUrl(const char *url, bool transcodingEnabled);
      virtual int removePublishStreamUrl(const char *url);
      virtual const char *getErrorDescription(int code);
      virtual int setLiveTranscoding(int width, int height, int videoBitrate, int videoFramerate, bool lowLatency, int videoGroup, int video_codec_profile, unsigned int backgroundColor, unsigned int userCount, const char *transcodingUserInfo, const char *transcodingExtraInfo, const char *metaData, const char *watermarkRtcImageUrl, int watermarkRtcImageX, int watermarkRtcImageY, int watermarkRtcImageWidth, int watermarkRtcImageHeight, const char *backgroundImageRtcImageUrl, int backgroundImageRtcImageX, int backgroundImageRtcImageY, int backgroundImageRtcImageWidth, int backgroundImageRtcImageHeight, int audioSampleRate, int audioBitrate, int audioChannels, int audioCodecProfile);
      virtual int pushVideoFrame(int type, int format, void *videoBuffer, int stride, int height, int cropLeft, int cropTop, int cropRight, int cropBottom, int rotation, long timestamp);
      virtual int setExternalVideoSource(bool enable, bool useTexture);
      virtual int setExternalAudioSource(bool enabled, int sampleRate, int channels);
      virtual int pushAudioFrame(int mediaSourceType, int audioFrameType, int samples, int bytesPerSample, int channels, int samplesPerSec, void *buffer, int64_t renderTimeMs, int avsync_type, bool wrap);
      virtual int pushAudioFrame(int audioFrameType, int samples, int bytesPerSample, int channels, int samplesPerSec, void *buffer, int64_t renderTimeMs, int avsync_type);
      // video device manager
      virtual bool createAVideoDeviceManager();
      virtual int releaseAVideoDeviceManager();
      virtual int startVideoDeviceTest(void *hwnd);
      virtual int stopVideoDeviceTest();
      virtual int getVideoDeviceCollectionCount();
      virtual int getVideoDeviceCollectionDevice(int index, char *deviceName, char *deviceId);
      virtual int getCurrentVideoDevice(char deviceId[LENGTH_MAX]);
      virtual int setVideoDeviceCollectionDevice(const char *deviceId);
      // audio recording device manager
      virtual bool creatAAudioRecordingDeviceManager();
      virtual int releaseAAudioRecordingDeviceManager();
      virtual int getAudioRecordingDeviceCount();
      virtual int getAudioRecordingDevice(int index, char *auduioRecordingDeviceName, char *auduioRecordingDeviceId);
      virtual int setAudioRecordingDevice(const char *deviceId);
      virtual int setAudioRecordingDeviceVolume(int volume);
      virtual int getAudioRecordingDeviceVolume();
      virtual int setAudioRecordingDeviceMute(bool mute);
      virtual bool isAudioRecordingDeviceMute();
      virtual int startAudioRecordingDeviceTest(int indicationInterval);
      virtual int stopAudioRecordingDeviceTest();
      virtual int getCurrentRecordingDevice(char deviceId[LENGTH_MAX]);
      virtual int getCurrentRecordingDeviceInfo(char deviceName[LENGTH_MAX], char deviceId[LENGTH_MAX]);
      //audio playback device manager
      virtual bool creatAAudioPlaybackDeviceManager();
      virtual int releaseAAudioPlaybackDeviceManager();
      virtual int getAudioPlaybackDeviceCount();
      virtual int getAudioPlaybackDevice(int index, char *deviceName, char *deviceId);
      virtual int setAudioPlaybackDevice(const char *deviceId);
      virtual int setAudioPlaybackDeviceVolume(int volume);
      virtual int getAudioPlaybackDeviceVolume();
      virtual int setAudioPlaybackDeviceMute(bool mute);
      virtual bool isAudioPlaybackDeviceMute();
      virtual int startAudioPlaybackDeviceTest(const char *testAudioFilePath);
      virtual int stopAudioPlaybackDeviceTest();
  	  virtual int getCurrentPlaybackDevice(char deviceId[LENGTH_MAX]);
	    virtual int getCurrentPlaybackDeviceInfo(char deviceName[LENGTH_MAX], char deviceId[LENGTH_MAX]);

      virtual int enableVideoObserver();
      virtual int disableVideoObserver();
      virtual int setMultiChannelWant(bool multiChannelWant);
      virtual bool getMultiChannelWanted();
      virtual int registeVideoRawDataObserver();
      virtual int unRegisteVideoRawDataObserver();
      virtual int setMirrorApplied(bool wheatherApply);
      virtual int addVideoFrameObserver(IVideoFrameObserver *_videoFrameObserver);
      virtual int removeVideoFrameObserver(IVideoFrameObserver *_videoFrameObserver);
      virtual bool checkWheatherInVideoObserverList(IVideoFrameObserver *_videoFrameObserver);
      virtual int registeAudioRawDataObserver();
      virtual int unRegisteAudioRawDataObserver();
      virtual int addAudioFrameObserver(IAudioFrameObserver *_audioFrameObserver);
      virtual int removeAudioFrameObserver(IAudioFrameObserver *_audioFrameObserver);
      virtual bool checkWheatherInAudioObserverList(IAudioFrameObserver *_audioFrameObserver);
      virtual int generateNativeTexture();
      virtual int updateTexture(int texId, unsigned char *data, unsigned int uid);
      virtual void deleteTexture(int tex);
      virtual void setVideoRender(VideoRender *videoRender);
      virtual void removeVideoRender();
      virtual void startRenderVideo(int eventID);
      virtual void addUserVideoInfo(unsigned int uid, unsigned int _textureId);
      virtual void removeUserVideoInfo(unsigned int uid);
      virtual int updateVideoRawData(void *data, unsigned int uid);
      virtual int setRenderMode(int renderMode);
      virtual int getAudioMixingPlayoutVolume();
      virtual int getAudioMixingPublishVolume();
      virtual int setLocalVoiceChanger(int voiceChanger);
      virtual int setLocalVoiceReverbPreset(int reverbPreset);
      virtual int setLocalVoicePitch(double pitch);
      virtual int setLocalVoiceEqualization(int bandFrequency, int bandGain);
      virtual int setLocalVoiceReverb(int reverbKey, int value);
      virtual int enableSoundPositionIndication(bool enabled);
      virtual int setCameraCapturerConfiguration(int preference, int cameraDirection);
      virtual int setRemoteUserPriority(uid_t uid, int userPriority);
      virtual int setLogFileSize(unsigned int fileSizeInKBytes);
      virtual int setExternalAudioSink(bool enabled, int sampleRate, int channels);
      virtual int joinChannelWithUserAccount(const char *token, const char *channelId, const char *userAccount);
      virtual int getUserInfoByUserAccount(const char *userAccount, UserInfo *userInfo);
      virtual int getUserInfoByUid(uid_t uid, UserInfo *userInfo);
      virtual int registerLocalUserAccount(const char *appId, const char *userAccount);
      virtual int setBeautyEffectOptions(bool enabled, int lighteningContrastLevel, float lighteningLevel, float smoothnessLevel, float rednessLevel);
      virtual int setInEarMonitoringVolume(int volume);
      virtual int startScreenCaptureByDisplayId(unsigned int displayId, int x, int y, int width, int height, int screenCaptureVideoDimenWidth, int screenCaptureVideoDimenHeight, int screenCaptureFrameRate, int screenCaptureBitrate, bool screenCaptureCaptureMouseCursor);
      virtual int startScreenCaptureByScreenRect(int screenRectX, int screenRectY, int screenRectWidth, int screenRectHeight, int regionRectX, int regionRectY, int regionRectWidth, int regionRectHeight, int screenCaptureVideoDimenWidth, int screenCaptureVideoDimenHeight, int screenCaptureFrameRate, int screenCaptureBitrate, bool screenCaptureCaptureMouseCursor);
      virtual int startScreenCaptureByWindowId(int windowId, int regionRectX, int regionRectY, int regionRectWidth, int regionRectHeight,  int screenCaptureVideoDimenWidth, int screenCaptureVideoDimenHeight, int screenCaptureFrameRate, int screenCaptureBitrate, bool screenCaptureCaptureMouseCursor);
	  virtual int startWindowsShareByExePath(int width, int height, int captureFreq, int bitrate, const char* exe_path, unsigned int uid);
	  virtual int startProcessShare(int width, int height, int captureFreq, int bitrate);
	  virtual void setLogFileFromPath(const char* filePath);
	  virtual int stopScreenCaptureEx();
	  virtual int setTextureCapture();
	  virtual int enableHardWareEncoder(int encoderID);
      virtual int setScreenCaptureContentHint(int videoContentHint);
      virtual int updateScreenCaptureParameters(int screenCaptureVideoDimenWidth, int screenCaptureVideoDimenHeight, int screenCaptureFrameRate, int screenCaptureBitrate, bool screenCaptureCaptureMouseCursor);
      virtual int updateScreenCaptureRegion(int x, int y, int width, int height);
      virtual int stopScreenCapture();
      virtual int addInjectStreamUrl(const char *url, int width, int height, int videoGop, int videoFramerate, int videoBitrate, int audioSampleRate, int audioBitrate, int audioChannels);
      virtual int removeInjectStreamUrl(const char *url);
      virtual int enableLoopbackRecording(bool enabled, const char *deviceName);
      virtual int setAudioSessionOperationRestriction(int restriction);
      virtual int switchChannel(const char *token, const char *channelId);
      virtual int startChannelMediaRelay(const char *srcChannelName, const char *srcToken , uid_t srcUid, const char *destChannelName, const char *destToken, uid_t destUid, int destCount);
      virtual int updateChannelMediaRelay(const char *srcChannelName, const char *srcToken , uid_t srcUid, const char *destChannelName, const char *destToken, uid_t destUid, int destCount);
      virtual int stopChannelMediaRelay();
      virtual PacketObserver *getPacketObserver();
      virtual int registerPacketObserver();
      virtual int unRegisterPacketObserver();
      // virtual int sendAudioPacket(unsigned char *buffer, unsigned int size);
      // virtual int sendVideoPacket(unsigned char *buffer, unsigned int size);
      virtual int setDefaultEngineSettings();
      virtual int sendMetadata(unsigned int uid, unsigned int size, unsigned char *buffer, long long timeStamps);
      virtual MetaDataObserver *getMetaDataObserver();
      virtual int registerMediaMetadataObserver(int metaDataType);
      virtual int unRegisterMediaMetadataObserver();
      virtual int pullAudioFrame(void *audioBuffer, int type, int samples, int bytesPerSample, int channels, int samplesPerSec, long long renderTimeMs, int avsync_type);
      virtual int setupLocalVideo(int hwnd, int renderMode, uid_t uid, void *priv);
      virtual int setupRemoteVideo(int hwnd, int renderMode, uid_t uid, void *priv);
      virtual int setLocalRenderMode(int renderMode);
      virtual int setRemoteRenderMode(uid_t userId, int renderMode);
      virtual int setLocalVideoMirrorMode(int mirrorMode);
      virtual void setAppType();
      virtual void unRegisterAllObserver();
      virtual int adjustUserPlaybackSignalVolume(uid_t userId, int volume);

      
      //multi channel
      virtual void *createChannel(const char *channelId);
      virtual void setChannelEventHandler(void *channel);
      virtual ChannelEventHandler *getChannelEventHandler(void *channel);
      virtual int releaseChannel(void *channel);
      virtual void releaseAllChannel();
      virtual int joinChannel(void *channel, const char* token,
                              const char* info,
                              uid_t uid,
                              bool autoSubscribeAudio,
                              bool autoSubscribeVideo);
      virtual int joinChannelWithUserAccount(void *channel, const char* token,
                                            const char* userAccount,
                                            bool autoSubscribeAudio,
                                            bool autoSubscribeVideo);
      virtual int leaveChannel(void *channel);
      virtual int publish(void *channel);
      virtual int unpublish(void *channel);
      virtual const char *channelId(void *channel);
      virtual std::string getCallId(void *channel);
      virtual int renewToken(void *channel, const char* token);
      virtual int setEncryptionSecret(void *channel, const char* secret);
      virtual int setEncryptionMode(void *channel, const char* encryptionMode);
      virtual int setClientRole(void *channel, int role);
      virtual int setRemoteUserPriority(void *channel, uid_t uid, int userPriority);
      virtual int setRemoteVoicePosition(void *channel, uid_t uid, double pan, double gain);
      virtual int setRemoteRenderMode(void *channel, uid_t userId, int renderMode, int mirrorMode);
      virtual int setDefaultMuteAllRemoteAudioStreams(void *channel, bool mute);
      virtual int setDefaultMuteAllRemoteVideoStreams(void *channel, bool mute);
      virtual int muteAllRemoteAudioStreams(void *channel, bool mute);
      virtual int adjustUserPlaybackSignalVolume(void *channel, uid_t userId, int volume);
      virtual int muteRemoteAudioStream(void *channel, uid_t userId, bool mute);
      virtual int muteAllRemoteVideoStreams(void *channel, bool mute);
      virtual int muteRemoteVideoStream(void *channel, uid_t userId, bool mute);
      virtual int setRemoteVideoStreamType(void *channel, uid_t userId, int streamType);
      virtual int setRemoteDefaultVideoStreamType(void *channel, int streamType);
      virtual int createDataStream(void *channel, int* streamId, bool reliable, bool ordered);
      virtual int sendStreamMessage(void *channel, int streamId, const char* data, size_t length);
      virtual int addPublishStreamUrl(void *channel, const char *url, bool transcodingEnabled);
      virtual int removePublishStreamUrl(void *channel, const char *url);
      virtual int setLiveTranscoding(void *channel, int width, int height, int videoBitrate, int videoFramerate, bool lowLatency, int videoGroup, int video_codec_profile, unsigned int backgroundColor, unsigned int userCount, const char *transcodingUserInfo, const char *transcodingExtraInfo, const char *metaData, const char *watermarkRtcImageUrl, int watermarkRtcImageX, int watermarkRtcImageY, int watermarkRtcImageWidth, int watermarkRtcImageHeight, const char *backgroundImageRtcImageUrl, int backgroundImageRtcImageX, int backgroundImageRtcImageY, int backgroundImageRtcImageWidth, int backgroundImageRtcImageHeight, int audioSampleRate, int audioBitrate, int audioChannels, int audioCodecProfile);
      virtual int addInjectStreamUrl(void *channel, const char* url, int width, int height, int videoGop, int videoFramerate, int videoBitrate, int audioSampleRate, int audioBitrate, int audioChannels);
      virtual int removeInjectStreamUrl(void *channel, const char* url);
      virtual int startChannelMediaRelay(void *channel, const char *srcChannelName, const char *srcToken , uid_t srcUid, const char *destChannelName, const char *destToken, uid_t destUid, int destCount);
      virtual int updateChannelMediaRelay(void *channel, const char *srcChannelName, const char *srcToken , uid_t srcUid, const char *destChannelName, const char *destToken, uid_t destUid, int destCount);
      virtual int stopChannelMediaRelay(void *channel);
      virtual int getConnectionState(void *channel);
      virtual void addUserVideoInfo(const char *channelId, unsigned int _userId, unsigned int _textureId);
      virtual void removeUserVideoInfo(const char *channelId, unsigned int _userId);
      virtual int updateVideoRawData(void *data, const char *channelId, unsigned int uid);
      virtual int enableFaceDetection(bool enable);
      virtual int setAudioMixingPitch(int pitch);
    };
  }
}
#endif