using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using agora_gaming_rtc;
using System.IO;
using System.Drawing.Imaging;
using System.Diagnostics;
using IPC;
using Newtonsoft.Json;

namespace rtcCSharpWrapperDemo
{

    struct RemoteVoideoInfo
    {
        public uint uid;
        public int width;
        public int height;
        public int elapsed;
        public Form1 this_;
    };

    public partial class Form1 : Form
    {
        private IPCChannel _ipc;
        private static string MAIN_PROCESS = "main";
        private static string SUB_PROCESS = "sub";

        public class VideoFrameRawHandlerParam
        {
            public int width;
            public int height;
            public byte[] yBuffer;
            public byte[] rgbFrame;
            public int rotation;
            public Bitmap bm;
            public uint userId;
        };

        public static IRtcEngine re_;
        static SynchronizationContext main_thread_sync_context_;
        static Form1 the_form;
        private Dictionary<uint, IntPtr> remote_video_map_;
        private bool channel_join_success_;
        private bool is_sharing_;
        private static Process process;
        private static string APP_ID = [PLACE HOLDER];

        public static VideoFrameRawHandlerParam curUIUsingVideoFrameRawHandlerParam_;
        public static List<VideoFrameRawHandlerParam> usingVideoFrameRawHandlerParam_;
        public static List<VideoFrameRawHandlerParam> unUseVideoFrameRawHandlerParam_;
        public static Mutex mutexVideoFrameRawHandlerParam_;

        public Form1()
        {
            InitializeComponent();
            _ipc = new IPCChannel(this, MAIN_PROCESS);
            channel_join_success_ = false;
            is_sharing_ = false;
            remote_video_map_ = new Dictionary<uint, IntPtr>();
            the_form = this;
            main_thread_sync_context_ = new WindowsFormsSynchronizationContext();

            re_ = IRtcEngine.GetEngine(APP_ID);
            re_.SetChannelProfile(CHANNEL_PROFILE.CHANNEL_PROFILE_LIVE_BROADCASTING);
            re_.SetClientRole(CLIENT_ROLE_TYPE.CLIENT_ROLE_BROADCASTER);
            re_.OnJoinChannelSuccess = JoinChannelSuccessHandler;
            re_.OnLeaveChannel = LeaveChannelHandler;
            re_.OnError = SDKErrorHandler;
            re_.OnFirstRemoteVideoDecoded = OnFirstRemoteVideoDecodedHandlerThread;
            re_.OnUserOffline = UserOfflineHandler;
            re_.OnUserJoined = UserJoinedHandler;
            re_.OnRemoteVideoStats = OnRemoteVideoStatsHandler;
            CreateShareProcess();
        }

        private void CreateShareProcess()
        {
            if(process == null)
            {
                process = new Process();
                process.StartInfo.FileName = "ScreenShareProcess.exe";
                process.Start();
            }
            else if (process.HasExited)
            {
                process.Start();
            }
        }

        ~Form1()
        {
            System.Diagnostics.Trace.WriteLine("Form1's destructor is called.");
        }

        [DllImport("user32.dll", EntryPoint = "GetDesktopWindow", CharSet = CharSet.Auto, SetLastError = true)]
        static extern IntPtr GetDesktopWindow();
        
        private void Button1_Click(object sender, EventArgs e)
        {
            String channel_name = textBox1.Text;
            if (channel_name.Length == 0)
            {
                MessageBox.Show("Channel name can't be empty！");
                return;
            }
            if (checkBox1.Checked)
            {
                re_.SetChannelProfile(CHANNEL_PROFILE.CHANNEL_PROFILE_LIVE_BROADCASTING);
                re_.SetClientRole(CLIENT_ROLE_TYPE.CLIENT_ROLE_BROADCASTER);
            }
            else
            {
                re_.SetChannelProfile(CHANNEL_PROFILE.CHANNEL_PROFILE_LIVE_BROADCASTING);
                re_.SetClientRole(CLIENT_ROLE_TYPE.CLIENT_ROLE_AUDIENCE);
            }
            re_.EnableVideo();
            agora_gaming_rtc.VideoDimensions videoDimensions = new agora_gaming_rtc.VideoDimensions();
            videoDimensions.width = 560;
            videoDimensions.height = 315;
            VideoEncoderConfiguration videoEncoderConfiguration = new VideoEncoderConfiguration();
            videoEncoderConfiguration.dimensions = videoDimensions;
            videoEncoderConfiguration.frameRate = FRAME_RATE.FRAME_RATE_FPS_30;
            re_.SetVideoEncoderConfiguration(videoEncoderConfiguration);
            int h_wnd = panel1.Handle.ToInt32();
            VideoCanvas localVideo = new VideoCanvas();
            localVideo.hwnd = h_wnd;
            localVideo.renderMode = RENDER_MODE_TYPE.RENDER_MODE_FIT;

            re_.SetupLocalVideo(localVideo, 0, new IntPtr());
            re_.JoinChannel(channel_name, "", 0);
        }

        public void OnRemoteVideoStatsHandler(RemoteVideoStats stats)
        {
            if(stats.uid == 10000)
                main_thread_sync_context_.Post(
                    new SendOrPostCallback(OnRemoteVideoStatsHandlerUI), stats);
        }

        public void OnRemoteVideoStatsHandlerUI(object state)
        {
            RemoteVideoStats stat = (RemoteVideoStats) state;
            label3.Text = String.Format("received sharing on bitrate: {0} {1}x{2} fps {3}\n", stat.receivedBitrate, stat.width, stat.height, stat.decoderOutputFrameRate);
        }

        public void OnFirstRemoteVideoDecodedHandler(uint uid, int width, int height, int elapsed)
        {
            // On first callback of video decode, we should set the remote hwnd for display according to uid.
            richTextBox1.Text += String.Format("OnFirstRemoteVideoDecodedHandler uid: {0}\n", uid);
            if(uid == 10000)
            {
                VideoCanvas remoteVideo = new VideoCanvas();
                remoteVideo.hwnd = pictureBox1.Handle.ToInt32();
                remoteVideo.renderMode = RENDER_MODE_TYPE.RENDER_MODE_FIT;
                re_.SetupRemoteVideo(remoteVideo, uid, new IntPtr());
            }
            else if (!remote_video_map_.ContainsKey(uid))
            {
                int wnd1 = 1, wnd2 = 1, wnd3 = 1, wnd4 = 1;
                foreach (var pair in remote_video_map_)
                {
                    if (wnd1 == 1 && panel2.Handle != pair.Value)
                    {
                        wnd1 = 0;
                    }
                    if (wnd4 == 1 && panel5.Handle != pair.Value)
                    {
                        wnd4 = 0;
                    }
                }
                if (wnd1 == 1)
                {
                    int h_wnd = panel2.Handle.ToInt32();
                    remote_video_map_.Add(uid, panel2.Handle);

                    VideoCanvas remoteVideo = new VideoCanvas();
                    remoteVideo.hwnd = h_wnd;
                    remoteVideo.renderMode = RENDER_MODE_TYPE.RENDER_MODE_HIDDEN;
                    re_.SetupRemoteVideo(remoteVideo, uid, new IntPtr());
                }
                else if (wnd4 == 1)
                {
                    int h_wnd = panel5.Handle.ToInt32();
                    remote_video_map_.Add(uid, panel5.Handle);
                    VideoCanvas remoteVideo = new VideoCanvas();
                    remoteVideo.hwnd = h_wnd;
                    remoteVideo.renderMode = RENDER_MODE_TYPE.RENDER_MODE_HIDDEN;
                    re_.SetupRemoteVideo(remoteVideo, uid, new IntPtr());
                }

            }
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            re_.StopScreenCapture();
            re_.LeaveChannel();
        }

        public static void SDKErrorHandlerUI(object state)
        {
            Form1 this_ = (Form1)state;
            this_.label3.Text = "Join channel failed!";
        }

        public static void SDKErrorHandler(int error, string msg)
        {
            main_thread_sync_context_.Post(
                new SendOrPostCallback(SDKErrorHandlerUI), the_form);
        }

        public static void JoinChannelSuccessHandlerUI(object state)
        {
            Form1 this_ = (Form1)state;
            this_.channel_join_success_ = true;
            this_.label3.Text = "Join channel success!";
        }

        public static void JoinChannelSuccessHandler(string channelName, uint uid, int elapsed)
        {
            BaseInfo info = new BaseInfo()
            {
                appId = "123",
                channelName = channelName,
                uid = uid + 1,
            };
            string jsonData = JsonConvert.SerializeObject(info);
            PushMessage message = new PushMessage()
            {
                messageType = MessageType.SHARE_BASE_INFO,
                messageBody = jsonData,
            };
            IPCChannel.SendMessage(ipcName: SUB_PROCESS, command: JsonConvert.SerializeObject(message));
            main_thread_sync_context_.Post(
                new SendOrPostCallback(JoinChannelSuccessHandlerUI), the_form);
        }

        public static void LeaveChannelHandlerUI(object state)
        {
            Form1 this_ = (Form1)state;
            this_.remote_video_map_.Clear();
            this_.channel_join_success_ = false;
            this_.label3.Text = "Leave channel success!";
        }

        public static void LeaveChannelHandler(RtcStats stats)
        {
            main_thread_sync_context_.Post(
                new SendOrPostCallback(LeaveChannelHandlerUI), the_form);
        }

        public static void OnFirstRemoteVideoDecodedHandlerUI(object state)
        {
            RemoteVoideoInfo rvi = (RemoteVoideoInfo)state;
            rvi.this_.OnFirstRemoteVideoDecodedHandler(rvi.uid, rvi.width, rvi.height, rvi.elapsed);
        }

        public static void OnFirstRemoteVideoDecodedHandlerThread(uint uid, int width, int height, int elapsed)
        {
            RemoteVoideoInfo rvi = new RemoteVoideoInfo();
            rvi.this_ = the_form;
            rvi.uid = uid;
            rvi.width = width;
            rvi.height = height;
            rvi.elapsed = elapsed;
            main_thread_sync_context_.Post(
                new SendOrPostCallback(OnFirstRemoteVideoDecodedHandlerUI), rvi);
        }

        private void Button3_Click(object sender, EventArgs e)
        {
            if (!channel_join_success_)
            {
                MessageBox.Show("Please join channel first！");
                return;
            }
            if(is_sharing_)
            {
                if (checkBox2.Checked)
                {
                    re_.stopScreenCaptureEx();
                }
                else
                {
                    stopShareDesktopEx();
                }
                button3.Text = "Start Sharing";
                this.is_sharing_ = false;
                return;
            }
            this.is_sharing_ = shareDesktopEx();
            if (this.is_sharing_)
            {
                button3.Text = "Stop Sharing";
            }
        }

        private bool shareGame()
        {
            if (textBox2.Text.Length == 0)
            {
                richTextBox1.Text += "Game Exe Path is empty!\n";
                return false;
            }
            // enable when using sdk embedded dual process
            if (true)
            {
                re_.setLogFileFromPath("gameRecord.log");
                int result = re_.startWindowsShareByExePath(1280, 720, 30, 1500 * 1000, textBox2.Text, 10000);
                return result == 0;
            }
            ScreenInfo screenInfo = new ScreenInfo()
            {
                isGame = checkBox2.Checked,
                gamePath = textBox2.Text,
                screenCaptureParameters = new IPC.ScreenCaptureParameters()
                {
                    frameRate = 30,
                    captureMouseCursor = false,
                    dimensions = new IPC.VideoDimensions()
                    {
                        width = 1280,
                        height = 720,
                    }
                }
            };
            PushMessage message = new PushMessage()
            {
                messageType = IPC.MessageType.START_GAME_SHARE,
                messageBody = JsonConvert.SerializeObject(screenInfo),
            };
            IPCChannel.SendMessage(ipcName: SUB_PROCESS, command: JsonConvert.SerializeObject(message));
            return true;
        }

        private bool shareDesktopEx()
        {
            if (checkBox2.Checked)
            {
                return shareGame();
            }
            ScreenInfo screenInfo = new ScreenInfo()
            {
                isGame = checkBox2.Checked,
                gamePath = textBox2.Text,
                windowId = (int)GetDesktopWindow(),
                regionRectangle = new IPC.Rectangle()
                {
                    x=0,
                    y=0,
                    width=1280,
                    height=720,
                },
                screenCaptureParameters = new IPC.ScreenCaptureParameters()
                {
                    frameRate = 30,
                    captureMouseCursor = false,
                    dimensions = new IPC.VideoDimensions()
                    {
                        width = 1280,
                        height = 720,
                    }
                }
            };
            PushMessage message = new PushMessage()
            {
                messageType = IPC.MessageType.START_SHARE_BY_WINDOW,
                messageBody = JsonConvert.SerializeObject(screenInfo),
            };
            IPCChannel.SendMessage(ipcName: SUB_PROCESS, command: JsonConvert.SerializeObject(message));
            return true;
        }

        private void stopShareDesktopEx()
        {
            PushMessage message = new PushMessage()
            {
                messageType = IPC.MessageType.STOP_SHARE
            };
            IPCChannel.SendMessage(ipcName: SUB_PROCESS, command: JsonConvert.SerializeObject(message));
        }

        public void UserOfflineHandlerUI(uint uid)
        {
            richTextBox1.Text += String.Format("UserOfflineHandlerUI: {0}\n", uid);
            if (remote_video_map_.ContainsKey(uid))
            {
                remote_video_map_.Remove(uid);
            }
        }
        public static void UserOfflineHandler(uint uid, USER_OFFLINE_REASON reason)
        {
            main_thread_sync_context_.Post(
                new SendOrPostCallback((object state) => {
                    the_form.UserOfflineHandlerUI((uint)state);
                }), uid);
        }

        public void UserJoinedHandlerUI(uint uid)
        {
            richTextBox1.Text += String.Format("UserJoinedHandlerUI: {0}\n", uid);
        }

        public void UserJoinedHandler(uint uid, int elapsed) {
            main_thread_sync_context_.Post(
               new SendOrPostCallback((object state) =>
               {
                   the_form.UserJoinedHandlerUI((uint)state);
               }), uid);
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked)
            {
                re_.SetChannelProfile(CHANNEL_PROFILE.CHANNEL_PROFILE_LIVE_BROADCASTING);
                re_.SetClientRole(CLIENT_ROLE_TYPE.CLIENT_ROLE_BROADCASTER);
            } else
            {
                re_.SetChannelProfile(CHANNEL_PROFILE.CHANNEL_PROFILE_LIVE_BROADCASTING);
                re_.SetClientRole(CLIENT_ROLE_TYPE.CLIENT_ROLE_AUDIENCE);
            }
            
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            re_.StopScreenCapture();
            re_.LeaveChannel();
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            PushMessage message = new PushMessage()
            {
                messageType = MessageType.CLOSE_APP,
                messageBody = null,
            };
            IPCChannel.SendMessage(ipcName: SUB_PROCESS, command: JsonConvert.SerializeObject(message));
        }
    }
}
