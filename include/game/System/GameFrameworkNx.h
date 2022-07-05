#pragma once

#include "al/debug/GpuPerf.h"
#include <agl/DrawContext.h>
#include <agl/RenderBuffer.h>
#include <sead/framework/seadGameFramework.h>
#include "al/hio/HioNode.h"

namespace al {
class GameFrameworkNx : public sead::GameFrameworkNx, public al::HioNode {
public:
    unsigned char padding_198[0x198];
    agl::RenderBuffer *mCurRenderBuffer;
    unsigned char padding_210[0x208 - 0x198];
    agl::DrawContext *mDrawContext;
    agl::RenderBuffer *mFirstRenderBuffer;
    void *unkPtr1;
    agl::RenderBuffer *mSecondRenderBuffer;
    unsigned char padding_248[0x18];
    al::GpuPerf *mGpuPerf;
    unsigned char padding_268[0x18];
    bool unkBool;
    bool unkBool2;
};
} // namespace al
 