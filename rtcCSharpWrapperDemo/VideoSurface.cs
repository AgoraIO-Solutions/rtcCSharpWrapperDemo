using System.Collections;
using System.Collections.Generic;
using System;
using System.Runtime.InteropServices;

/* This example script demonstrates how to attach
 * video content to a 3D object (chenzhenyong@agora.io)
 * 
 * Agora engine outputs one local preview video and some
 * remote user video. User ID (int) is used to identify
 * these video streams. 0 is used for local preview video
 * stream, and other value stands for remote user video
 * stream.
 */

public class VideoSurface
{

    private System.IntPtr data = Marshal.AllocHGlobal(1920 * 1080 * 4);
    //private int defWidth = 0;
    //private int defHeight = 0;

    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        // process engine messages (TODO: put in some other place)
        agora_gaming_rtc.IRtcEngine engine = agora_gaming_rtc.IRtcEngine.QueryEngine();
        if (engine == null)
            return;

       
    }

    void OnDestroy()
    {
        Marshal.FreeHGlobal(data);
        // Debug.Log("OnDestroy");
    }

    // call this to render video stream from uid on this game object
    public void SetForUser(uint uid)
    {
        mUid = uid;
        // Debug.Log("Set uid " + uid + " for " + gameObject.name);
    }

    /*
     * if enable = true, the video will render. if enable = false, the video will stop render.
     */
    public void SetEnable(bool enable)
    {
        mEnable = enable;
    }

    // public delegate void SetTransformDelegate(uint uid, string objName, ref Transform transform);

    // public SetTransformDelegate mAdjustTransfrom = null;

    /*
     * uid = 0, it means yourself but not others, you can get others uid by Agora Engine CallBack onUserJoined.
     */
    private uint mUid = 0;

    /*
     *if disabled, then no rendering happens
     */
    private bool mEnable = true;
}
