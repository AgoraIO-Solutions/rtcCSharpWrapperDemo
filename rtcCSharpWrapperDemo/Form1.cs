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

        public static VideoFrameRawHandlerParam curUIUsingVideoFrameRawHandlerParam_;
        public static List<VideoFrameRawHandlerParam> usingVideoFrameRawHandlerParam_;
        public static List<VideoFrameRawHandlerParam> unUseVideoFrameRawHandlerParam_;
        public static Mutex mutexVideoFrameRawHandlerParam_;

        public Form1()
        {
            InitializeComponent();
            channel_join_success_ = false;
            remote_video_map_ = new Dictionary<uint, IntPtr>();
            the_form = this;
            main_thread_sync_context_ = new WindowsFormsSynchronizationContext();

            re_ = IRtcEngine.GetEngine("");
            re_.SetChannelProfile(CHANNEL_PROFILE.CHANNEL_PROFILE_COMMUNICATION);
            re_.SetClientRole(CLIENT_ROLE_TYPE.CLIENT_ROLE_BROADCASTER);
            re_.OnJoinChannelSuccess = JoinChannelSuccessHandler;
            re_.OnRtcStats = stats =>
            {

            };
            re_.OnLeaveChannel = LeaveChannelHandler;
            re_.OnError = SDKErrorHandler;
            re_.OnFirstRemoteVideoDecoded = OnFirstRemoteVideoDecodedHandlerThread;
            re_.OnUserOffline = UserOfflineHandler;
            re_.OnUserJoined = UserJoinedHandler;
            re_.OnRemoteVideoStats = OnRemoteVideoStatsHandler;
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

            re_.EnableVideo();
            int h_wnd = panel1.Handle.ToInt32();
            VideoCanvas localVideo = new VideoCanvas();
            localVideo.hwnd = h_wnd;
            localVideo.renderMode = RENDER_MODE_TYPE.RENDER_MODE_FIT;
            re_.SetupLocalVideo(localVideo, 0, new IntPtr());

            if (checkBox2.Checked)
            {
                /*
                 * raw data feature disabled for now by xianing, will enable it when sepcial sdk released for HP.
                // local video frame raw data handler, the raw data format is YUV420
                re_.onCaptureVideoFrame = OnCaptureVideoFrameRawHandler;
                // For remote video frame raw data handler, use onRenderVideoFrameRaw.
                re_.onRenderVideoFrame = OnRenderVideoFrameRawHandler;

                // Init video frame buffer list for thread changing.
                mutexVideoFrameRawHandlerParam_ = new Mutex();
                usingVideoFrameRawHandlerParam_ = new List<VideoFrameRawHandlerParam>();
                unUseVideoFrameRawHandlerParam_ = new List<VideoFrameRawHandlerParam>();
                */
            }

            re_.JoinChannel(channel_name, "", 0);
        }

        public void OnRemoteVideoStatsHandler(RemoteVideoStats stats)
        {
            main_thread_sync_context_.Post(
                new SendOrPostCallback(OnRemoteVideoStatsHandlerUI), stats);
        }

        public void OnRemoteVideoStatsHandlerUI(object state)
        {
            label3.Text = String.Format("receivedFrameRate: {0}\n", ((RemoteVideoStats)state).receivedBitrate);
        }

        public void OnFirstRemoteVideoDecodedHandler(uint uid, int width, int height, int elapsed)
        {
            // On first callback of video decode, we should set the remote hwnd for display according to uid.
            richTextBox1.Text += String.Format("OnFirstRemoteVideoDecodedHandler uid: {0}\n", uid);
            if (!remote_video_map_.ContainsKey(uid))
            {
                int wnd1 = 1, wnd2 = 1;
                foreach (var pair in remote_video_map_)
                {
                    if (wnd1 == 1 && panel2.Handle == pair.Value)
                    {
                        wnd1 = 0;
                    }
                    if (wnd2 == 1 && panel3.Handle == pair.Value)
                    {
                        wnd2 = 0;
                    }
                }
                if (wnd1 == 1)
                {
                    int h_wnd = panel2.Handle.ToInt32();
                    remote_video_map_.Add(uid, panel2.Handle);

                    VideoCanvas remoteVideo = new VideoCanvas();
                    remoteVideo.hwnd = h_wnd;
                    remoteVideo.renderMode = RENDER_MODE_TYPE.RENDER_MODE_FIT;
                    re_.SetupRemoteVideo(remoteVideo, uid, new IntPtr());
                }
                else if (wnd2 == 1)
                {
                    int h_wnd = panel3.Handle.ToInt32();
                    remote_video_map_.Add(uid, panel3.Handle);
                    VideoCanvas remoteVideo = new VideoCanvas();
                    remoteVideo.hwnd = h_wnd;
                    remoteVideo.renderMode = RENDER_MODE_TYPE.RENDER_MODE_FIT;
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
            //richTextBox1.Text += String.Format("get remote uid {0} video frame.", uid);
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

            //IntPtr desktop_wnd = GetDesktopWindow();
            //int desktop_width = Screen.PrimaryScreen.Bounds.Width;
            //int desktop_height = Screen.PrimaryScreen.Bounds.Height;
            int ret = re_.MuteRemoteAudioStream(10000, true);
            richTextBox1.Text += String.Format("MuteRemoteAudioStream return: {0}\n", ret);
            ret = re_.MuteRemoteVideoStream(10000, true);
            richTextBox1.Text += String.Format("MuteRemoteVideoStream return: {0}\n", ret);
            VideoDimensions videoDimensions = new VideoDimensions();
            videoDimensions.height = 720;
            videoDimensions.width = 1280;
            ScreenCaptureParameters screenCaptureParameters = new ScreenCaptureParameters();
            screenCaptureParameters.bitrate = 4000 * 1000;
            screenCaptureParameters.frameRate = 30;
            screenCaptureParameters.captureMouseCursor = true;
            screenCaptureParameters.dimensions = videoDimensions;
            agora_gaming_rtc.Rectangle rectangle = new agora_gaming_rtc.Rectangle();
            rectangle.height = 720;
            rectangle.width = 1280;
            rectangle.x = 0;
            rectangle.y = 0;
            re_.StartScreenCaptureByScreenRect(rectangle, rectangle, screenCaptureParameters);
            //re_.startWindowsShareByExePath(1280, 720, 30, 4000 * 1000, "D:\\WeGame\\英雄联盟\\TCLS\\Client.exe", 0);
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


        public void OnCaptureVideoFrameRawHandlerUI()
        {
            if (IsDisposed)
                return;

            // Pick a item in list to show.
            VideoFrameRawHandlerParam sel_vfrp;

            mutexVideoFrameRawHandlerParam_.WaitOne();
            if (usingVideoFrameRawHandlerParam_.Count == 0)
            {
                mutexVideoFrameRawHandlerParam_.ReleaseMutex();
                return; // full
            }

            sel_vfrp = usingVideoFrameRawHandlerParam_[0];
            usingVideoFrameRawHandlerParam_.RemoveAt(0);
            mutexVideoFrameRawHandlerParam_.ReleaseMutex();

            // Set bitmap to ui contorl
            if (sel_vfrp.bm != null)
                this.pictureBox1.Image = sel_vfrp.bm;

            mutexVideoFrameRawHandlerParam_.WaitOne();
            // add last ui show item to unUsed list
            if (curUIUsingVideoFrameRawHandlerParam_ != null)
                unUseVideoFrameRawHandlerParam_.Add(curUIUsingVideoFrameRawHandlerParam_);
            mutexVideoFrameRawHandlerParam_.ReleaseMutex();
            curUIUsingVideoFrameRawHandlerParam_ = sel_vfrp;
        }
        

        public static void OnCaptureVideoFrameRawHandler(int width, int height, byte[] yBuffer, int rotation)
        {
            // we pick a un used VideoFrameRawHandlerParam item, convert yuv data to rgb frame, and init it's bitmap obj.
            VideoFrameRawHandlerParam sel_vfrp;

            mutexVideoFrameRawHandlerParam_.WaitOne();
            if (unUseVideoFrameRawHandlerParam_.Count == 0)
            {
                if (usingVideoFrameRawHandlerParam_.Count > 20)
                {
                    mutexVideoFrameRawHandlerParam_.ReleaseMutex();
                    return; // full
                }
                sel_vfrp = new VideoFrameRawHandlerParam();
                sel_vfrp.width = 0;
                sel_vfrp.userId = 0;
            } else
            {
                sel_vfrp = unUseVideoFrameRawHandlerParam_[0];
                unUseVideoFrameRawHandlerParam_.RemoveAt(0);
            }
            mutexVideoFrameRawHandlerParam_.ReleaseMutex();

            if (sel_vfrp.width != width 
                || sel_vfrp.height != height)
            {
                sel_vfrp.width = width;
                sel_vfrp.height = height;
                sel_vfrp.yBuffer = new byte[yBuffer.Length];
                Array.Copy(yBuffer, sel_vfrp.yBuffer, yBuffer.Length);
                sel_vfrp.rotation = rotation;
                sel_vfrp.rgbFrame = new byte[width * height * 4];
                sel_vfrp.bm = new Bitmap(width, height);
            } else
            {
                Array.Copy(yBuffer, sel_vfrp.yBuffer, yBuffer.Length);
                sel_vfrp.rotation = rotation;
            }

            ConvertYUV2RGB(sel_vfrp.bm, sel_vfrp.yBuffer,
            sel_vfrp.rgbFrame, width, height);

            mutexVideoFrameRawHandlerParam_.WaitOne();
            usingVideoFrameRawHandlerParam_.Add(sel_vfrp);
            mutexVideoFrameRawHandlerParam_.ReleaseMutex();

            // Send to main thread for display
            main_thread_sync_context_.Post(
                new SendOrPostCallback((object state) =>
                {
                    the_form.OnCaptureVideoFrameRawHandlerUI();
                }), null);
        }

        public void OnRenderVideoFrameRawHandlerUI()
        {
            if (IsDisposed)
                return;

            // Pick a item in list to show.
            VideoFrameRawHandlerParam sel_vfrp;

            mutexVideoFrameRawHandlerParam_.WaitOne();
            if (usingVideoFrameRawHandlerParam_.Count == 0)
            {
                mutexVideoFrameRawHandlerParam_.ReleaseMutex();
                return; // full
            }

            sel_vfrp = usingVideoFrameRawHandlerParam_[0];
            usingVideoFrameRawHandlerParam_.RemoveAt(0);
            mutexVideoFrameRawHandlerParam_.ReleaseMutex();

            // Set bitmap to ui contorl
            if (sel_vfrp.bm != null)
            {// Find Which picbox to show

                IntPtr targPicbox = new IntPtr();
                foreach (var pair in remote_video_map_)
                {
                    if (sel_vfrp.userId == pair.Key)
                        targPicbox = pair.Value;
                }
                if (panel3.Handle == targPicbox)
                {
                    pictureBox3.Image = sel_vfrp.bm;
                }
                else
                {
                    pictureBox2.Image = sel_vfrp.bm;
                }
            }

            mutexVideoFrameRawHandlerParam_.WaitOne();
            // add last ui show item to unUsed list
            if (curUIUsingVideoFrameRawHandlerParam_ != null)
                unUseVideoFrameRawHandlerParam_.Add(curUIUsingVideoFrameRawHandlerParam_);
            mutexVideoFrameRawHandlerParam_.ReleaseMutex();
            curUIUsingVideoFrameRawHandlerParam_ = sel_vfrp;
        }

        public static void OnRenderVideoFrameRawHandler(uint userId, int width, int height, byte[] yBuffer, int rotation)
        {
            // we pick a un used VideoFrameRawHandlerParam item, convert yuv data to rgb frame, and init it's bitmap obj.
            VideoFrameRawHandlerParam sel_vfrp;

            mutexVideoFrameRawHandlerParam_.WaitOne();
            if (unUseVideoFrameRawHandlerParam_.Count == 0)
            {
                if (usingVideoFrameRawHandlerParam_.Count > 20)
                {
                    mutexVideoFrameRawHandlerParam_.ReleaseMutex();
                    return; // full
                }
                sel_vfrp = new VideoFrameRawHandlerParam();
                sel_vfrp.width = 0;
                sel_vfrp.userId = 0;
            }
            else
            {
                sel_vfrp = unUseVideoFrameRawHandlerParam_[0];
                unUseVideoFrameRawHandlerParam_.RemoveAt(0);
            }
            mutexVideoFrameRawHandlerParam_.ReleaseMutex();

            if (sel_vfrp.width != width
                || sel_vfrp.height != height)
            {
                sel_vfrp.width = width;
                sel_vfrp.height = height;
                sel_vfrp.yBuffer = new byte[yBuffer.Length];
                Array.Copy(yBuffer, sel_vfrp.yBuffer, yBuffer.Length);
                sel_vfrp.rotation = rotation;
                sel_vfrp.rgbFrame = new byte[width * height * 4];
                sel_vfrp.bm = new Bitmap(width, height);
            }
            else
            {
                Array.Copy(yBuffer, sel_vfrp.yBuffer, yBuffer.Length);
                sel_vfrp.rotation = rotation;
            }

            sel_vfrp.userId = userId;
            ConvertYUV2RGB(sel_vfrp.bm, sel_vfrp.yBuffer,
            sel_vfrp.rgbFrame, width, height);

            mutexVideoFrameRawHandlerParam_.WaitOne();
            usingVideoFrameRawHandlerParam_.Add(sel_vfrp);
            mutexVideoFrameRawHandlerParam_.ReleaseMutex();

            // Send to main thread for display
            main_thread_sync_context_.Post(
                new SendOrPostCallback((object state) =>
                {
                    the_form.OnRenderVideoFrameRawHandlerUI();
                }), null);
        }

        static double[,] YUV2RGB_CONVERT_MATRIX = new double[3, 3] { { 1, 0, 1.4022 }, { 1, -0.3456, -0.7145 }, { 1, 1.771, 0 } };
        static void ConvertYUV2RGB(Bitmap bm, byte[] yuvFrame, byte[] rgbFrame, int width, int height)
        {
            int uIndex = width * height;
            int vIndex = uIndex + ((width * height) >> 2);
            int gIndex = width * height;
            int bIndex = gIndex * 2;

            int temp = 0;
            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    // R分量
                    temp = (int)(yuvFrame[y * width + x] + (yuvFrame[vIndex + (y / 2) * (width / 2) + x / 2] - 128) * YUV2RGB_CONVERT_MATRIX[0, 2]);
                    rgbFrame[y * width + x] = (byte)(temp < 0 ? 0 : (temp > 255 ? 255 : temp));
                    // G分量
                    temp = (int)(yuvFrame[y * width + x] + (yuvFrame[uIndex + (y / 2) * (width / 2) + x / 2] - 128) * YUV2RGB_CONVERT_MATRIX[1, 1] + (yuvFrame[vIndex + (y / 2) * (width / 2) + x / 2] - 128) * YUV2RGB_CONVERT_MATRIX[1, 2]);
                    rgbFrame[gIndex + y * width + x] = (byte)(temp < 0 ? 0 : (temp > 255 ? 255 : temp));
                    // B分量
                    temp = (int)(yuvFrame[y * width + x] + (yuvFrame[uIndex + (y / 2) * (width / 2) + x / 2] - 128) * YUV2RGB_CONVERT_MATRIX[2, 1]);
                    rgbFrame[bIndex + y * width + x] = (byte)(temp < 0 ? 0 : (temp > 255 ? 255 : temp));
                    Color c = Color.FromArgb(rgbFrame[y * width + x], rgbFrame[gIndex + y * width + x], rgbFrame[bIndex + y * width + x]);
                    bm.SetPixel(x, y, c);
                }
            }
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
            re_.LeaveChannel(); int a = 0;
        }

        private void button4_Click(object sender, EventArgs e)
        {
        }
    }
}
