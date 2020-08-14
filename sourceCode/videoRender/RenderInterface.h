#ifndef RENDER_INTERFACE_WRAPPER
#define RENDER_INTERFACE_WRAPPER
#include "UserVideoFrameData.h"

namespace agora {
    namespace unity {
        class RenderInterface
        {
        public:
            virtual void startRenderVideo(UserVideoFrameData* videoframeData);
            virtual unsigned int createTexture();
            virtual void deleteTexture(unsigned int textureId);
            virtual int updateVideoRawData(void *data,  UserVideoFrameData* _userVideoFrameData);
        };
    }
}
#endif