#ifndef VIDEO_RENDER_FACTORY_WRAPPER
#define VIDEO_RENDER_FACTORY_WRAPPER
#include "RenderInterface.h"

namespace agora {
    namespace unity {      
        class VideoRenderFactory
        {
        public:
            VideoRenderFactory();
            ~VideoRenderFactory();
            RenderInterface* getVideoRender(int renderType);
        };
    }
}
#endif