using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IPC
{
    public class PushMessage
    {
        public MessageType messageType { get; set; }
        public string messageBody { get; set; }
    }

    public enum MessageType
    {
        SHARE_BASE_INFO = 0,
        START_SHARE_BY_WINDOW = 1,
        START_SHARE_BY_RECT = 2,
        UPDATE_SHARE = 3,
        STOP_SHARE = 4,
        CLOSE_APP = 5,
        START_SHARE_BY_GPU = 6,
    }

    public class BaseInfo
    {
        public string appId { get; set; }
        public string channelName { get; set; }
        public uint uid { get; set; }
    }

    public class ScreenInfo
    {
        public int windowId { get; set; }
        public Rectangle screenRectangle { get; set; }
        public Rectangle regionRectangle { get; set; }
        public ScreenCaptureParameters screenCaptureParameters { get; set; }
    }

    public struct Rectangle
    {
        /** The horizontal offset from the top-left corner.
        */
        public int x;
        /** The vertical offset from the top-left corner.
        */
        public int y;
        /** The width of the region.
        */
        public int width;
        /** The height of the region.
        */
        public int height;
    };

    public struct VideoDimensions
    {
        /** Width (pixels) of the video. */
        public int width;
        /** Height (pixels) of the video. */
        public int height;
    };

    /** Screen sharing encoding parameters.
*/
    public struct ScreenCaptureParameters
    {
        /** The maximum encoding dimensions of the shared region in terms of width &times; height.
         * 
         * The default value is 1920 &times; 1080 pixels, that is, 2073600 pixels. Agora uses the value of this parameter to calculate the charges.
         * 
         * If the aspect ratio is different between the encoding dimensions and screen dimensions, Agora applies the following algorithms for encoding. Suppose the encoding dimensions are 1920 x 1080:
         * - If the value of the screen dimensions is lower than that of the encoding dimensions, for example, 1000 &times; 1000, the SDK uses 1000 &times; 1000 for encoding.
         * - If the value of the screen dimensions is higher than that of the encoding dimensions, for example, 2000 &times; 1500, the SDK uses the maximum value under 1920 &times; 1080 with the aspect ratio of the screen dimension (4:3) for encoding, that is, 1440 &times; 1080.
         */
        public VideoDimensions dimensions;
        /** The frame rate (fps) of the shared region.
         * 
         * The default value is 5. We do not recommend setting this to a value greater than 15.
         */
        public int frameRate;
        /** The bitrate (Kbps) of the shared region.
         * 
         * The default value is 0 (the SDK works out a bitrate according to the dimensions of the current screen).
         */
        public int bitrate;
        /** Sets whether or not to capture the mouse for screen sharing:
         * - true: (Default) Capture the mouse.
         * - false: Do not capture the mouse.
         */
        public bool captureMouseCursor;
    };
}
