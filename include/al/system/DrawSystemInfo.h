#pragma once

//#include <agl/DrawContext.h>
#include <agl/RenderBuffer.h>

namespace agl {
    struct DrawContext;
}

namespace al {
class DrawSystemInfo {
public:
    agl::RenderBuffer *mFirstRenderBuffer;
    agl::RenderBuffer *mSecondRenderBuffer;
    bool unkBool;
    agl::DrawContext *mDrawContext;
};
}
