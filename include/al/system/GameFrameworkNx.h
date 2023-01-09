#pragma once

#include "al/debug/GpuPerf.h"
#include "al/hio/HioNode.h"
#include <agl/DisplayList.h>
#include <agl/DrawContext.h>
#include <agl/RenderBuffer.h>
#include <agl/RenderTargetColor.h>
#include <sead/framework/seadFramework.h>
#include <sead/framework/seadGameFramework.h>
#include <sead/prim/seadRuntimeTypeInfo.h>
#include <sead/thread/seadEvent.h>

namespace al {
class GameFrameworkNx : public sead::GameFrameworkNx, public al::HioNode {
    SEAD_RTTI_OVERRIDE(GameFrameworkNx, sead::Framework)

public:
    GameFrameworkNx(sead::GameFrameworkNx::CreateArg const&);
    virtual ~GameFrameworkNx();

    virtual void createControllerMgr(sead::TaskBase*) override;
    virtual void createHostIOMgr(sead::TaskBase*, sead::HostIOMgr::Parameter*, sead::Heap*) override;
    virtual void createInfLoopChecker(sead::TaskBase*, sead::TickSpan const&, int) override;
    virtual void procFrame_() override;
    virtual void procDraw_() override;
    virtual void present_() override;

    void initAgl(sead::Heap*, int, int, int, int, int, int);


    agl::DrawContext *mDrawContext;
    agl::RenderBuffer *mFirstRenderBuffer;
    agl::RenderTargetColor* mFirstBufferColor;
    agl::RenderBuffer *mSecondRenderBuffer;
    agl::RenderTargetColor* mSecondBufferColor;
    agl::DisplayList* uVar1;
    agl::DisplayList* uVar2;
    al::GpuPerf *mGpuPerf;
    unsigned char padding_268[0x18];
    bool bVar1;
    bool bVar2;
    sead::Event* mEvent;
};
} // namespace al
 