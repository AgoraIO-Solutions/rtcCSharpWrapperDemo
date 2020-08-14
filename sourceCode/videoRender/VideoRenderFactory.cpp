#include "VideoRenderFactory.h"

namespace agora {
    namespace unity {
        VideoRenderFactory::VideoRenderFactory()
        {}

        VideoRenderFactory::~VideoRenderFactory()
        {

        }

        RenderInterface* VideoRenderFactory::getVideoRender(int renderType)
        {
            // switch (renderType)
            // {
            //     case kUnityGfxRendererD3D11:
            //         return nullptr;
            //         break;
                
            //     case kUnityGfxRendererD3D12:
            //         return nullptr;
            //         break;

            //     case kUnityGfxRendererMetal:
            //         return nullptr;
            //         break;

            //     // case kUnityGfxRendererGXM:
            //     //     break;

            //     case kUnityGfxRendererOpenGLCore:
            //         return nullptr;
            //         break;

            //     case kUnityGfxRendererOpenGLES20:   
            //         return new OpenGLES2Render();
            //         break;

            //     case kUnityGfxRendererOpenGLES30:
            //         return new OpenGLES3Render();
            //         break;

            //     case kUnityGfxRendererVulkan:
            //         return nullptr;
            //         break;
            //     default:
            //         return nullptr;
            //         break;
            // }
            return NULL;

        }    
    }
}
