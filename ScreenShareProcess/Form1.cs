﻿using agora_gaming_rtc;
using IPC;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ScreenShareProcess
{
    public partial class Form1 : Form
    {
        private IPC.IPCChannel _ipc;

        private string PROCESS_ID = "sub";

        public string appId = [PLACE HOLDER];
        public string channelName;
        private uint uid = 10000;
        private IRtcEngine re_;
        private bool isShareByRect;
        private ScreenInfo screenInfo;

        public Form1()
        {
            InitializeComponent();
            _ipc = new IPC.IPCChannel(this, PROCESS_ID);
            _ipc.OnMessage += OnMessage;
            initAgoraMedia();
        }

        private int OnMessage(IWin32Window receiver, string message)
        {
            IPC.PushMessage pushMessage = JsonConvert.DeserializeObject<IPC.PushMessage>(message);
            switch (pushMessage.messageType)
            {
                case IPC.MessageType.CLOSE_APP:
                    re_.LeaveChannel();
                    this.Close();
                    break;
                case IPC.MessageType.SHARE_BASE_INFO:
                    configureBaseInfo(pushMessage.messageBody);
                    break;
                case IPC.MessageType.START_SHARE_BY_RECT:
                    startShareByRect(pushMessage.messageBody);
                    break;
                case IPC.MessageType.START_SHARE_BY_WINDOW:
                    startShareByWindowId(pushMessage.messageBody);
                    break;
                case IPC.MessageType.STOP_SHARE:
                    stopShare();
                    break;
                default:
                    break;
            }
            return 1;
        }

        private void stopShare()
        {
            re_.StopScreenCapture();
            re_.LeaveChannel();
        }

        private void startShareByWindowId(string messageBody)
        {
            isShareByRect = false;
            screenInfo = JsonConvert.DeserializeObject<ScreenInfo>(messageBody);
            int ret = re_.JoinChannel(channelName, "", uid);
        }

        private void handleScreenShare()
        {
            re_.StartScreenCaptureByDisplayId(screenInfo.displayId, convert(screenInfo.regionRectangle), convert(screenInfo.screenCaptureParameters));
        }

        private void startShareByRect(string messageBody)
        {
            isShareByRect = true;
            screenInfo = JsonConvert.DeserializeObject<ScreenInfo>(messageBody);
            int ret = re_.JoinChannel(channelName, "", uid);
        }

        private agora_gaming_rtc.Rectangle convert(IPC.Rectangle orig)
        {
            return new agora_gaming_rtc.Rectangle()
            {
                x = orig.x,
                y = orig.y,
                width = orig.width,
                height = orig.height,
            };
        }

        private agora_gaming_rtc.ScreenCaptureParameters convert(IPC.ScreenCaptureParameters orig)
        {
            return new agora_gaming_rtc.ScreenCaptureParameters()
            {
                bitrate = orig.bitrate,
                frameRate = orig.frameRate,
                captureMouseCursor = orig.captureMouseCursor,
                dimensions = new agora_gaming_rtc.VideoDimensions()
                {
                    width = orig.dimensions.width, 
                    height = orig.dimensions.height,
                }
            };
        }

        private void initAgoraMedia()
        {
            re_ = IRtcEngine.GetEngine(appId);
            re_.SetChannelProfile(CHANNEL_PROFILE.CHANNEL_PROFILE_LIVE_BROADCASTING);
            re_.SetClientRole(CLIENT_ROLE_TYPE.CLIENT_ROLE_BROADCASTER);
            re_.EnableVideo();
            re_.SetVideoProfile(VIDEO_PROFILE_TYPE.VIDEO_PROFILE_LANDSCAPE_720P_6, false);
            re_.DisableAudio();
            re_.DisableLastmileTest();
            re_.MuteAllRemoteAudioStreams(true);
            re_.MuteAllRemoteVideoStreams(true);
            re_.MuteLocalAudioStream(true);
            //re_.EnableLocalVideo(false);
            re_.SetLogFile("screenshare.log");
            re_.SetLogFilter(LOG_FILTER.INFO);
            re_.SetParameters("{\"che.video.h264.hwenc\":1}");
            //re_.SetParameters("{\"che.video.enc_auto_adjust\":0}");
            re_.OnJoinChannelSuccess = JoinChannelSuccessHandler;
        }

        private void JoinChannelSuccessHandler(string channelName, uint uid, int elapsed)
        {
            handleScreenShare();
        }

        private void configureBaseInfo(string messageBody)
        {
            BaseInfo info = JsonConvert.DeserializeObject<BaseInfo>(messageBody);
            channelName = info.channelName;
        }

        protected override void SetVisibleCore(bool value)
        {
            base.SetVisibleCore(value);
        }
        private void Form1_Load(object sender, EventArgs e)
        {
        }
    }
}
