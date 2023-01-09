#pragma once

#include <agl/RenderBuffer.h>
#include <nn/mem.h>
#include <nn/os.h>
#include <nn/vi.h>
#include <nvn/nvn_types.h>
#include <sead/basis/seadTypes.h>
#include <sead/framework/seadFramework.h>
#include <sead/framework/seadTaskMgr.h>
#include <sead/gfx/seadFrameBuffer.h>
#include <sead/heap/seadHeap.h>
#include <sead/hostio/seadHostIOMgr.h>
#include <sead/math/seadVector.h>
#include <sead/prim/seadRuntimeTypeInfo.h>
#include <sead/prim/seadSafeString.h>
#include <sead/thread/seadDelegateThread.h>
#include <sead/thread/seadThread.h>
#include <sead/time/seadTickSpan.h>

namespace sead {
class GameFramework : public sead::Framework {
    SEAD_RTTI_OVERRIDE(GameFramework, Framework)

public:
    GameFramework();
    virtual ~GameFramework();

    virtual void createSystemTasks(TaskBase*, const CreateSystemTaskArg&) override;
    virtual void quitRun_(Heap*) override;
    virtual void createControllerMgr(TaskBase*);
    virtual void createHostIOMgr(TaskBase*, HostIOMgr::Parameter*, Heap*);
    virtual void createProcessMeter(TaskBase*);
    virtual void createSeadMenuMgr(TaskBase*);
    virtual void createInfLoopChecker(TaskBase*, TickSpan const&, int);
    virtual void createCuckooClock(TaskBase*);
    virtual float calcFps() = 0;
    virtual void saveScreenShot(SafeString const&);
    virtual bool isScreenShotBusy() const;
    virtual void waitStartDisplayLoop_();
    virtual void initHostIO_();

    unsigned int uVar1;
    sead::SafeString sVar1;
    sead::SafeString sVar2;
    sead::SafeString sVar3;
    sead::TaskMgr* mTaskMgr;
    unsigned char gap1[0x8];
    void (*toggleLockFrameDrawContext)(bool);
};


class GameFrameworkNx : public sead::GameFramework {
    SEAD_RTTI_OVERRIDE(GameFrameworkNx, Framework)

public:
    struct CreateArg;

    GameFrameworkNx(sead::GameFrameworkNx::CreateArg const&);
    virtual ~GameFrameworkNx();

    virtual FrameBuffer* getMethodFrameBuffer(s32) const override;
    virtual LogicalFrameBuffer* getMethodLogicalFrameBuffer(s32) const override;
    virtual void initRun_(Heap*) override;
    virtual void runImpl_() override;
    virtual MethodTreeMgr* createMethodTreeMgr_(Heap*) override;
    virtual float calcFps() override;
    virtual void setCaption(SafeString const&);
    virtual void mainLoop_();
    virtual void procFrame_();
    virtual void procDraw_();
    virtual void procCalc_();
    virtual void present_();
    virtual void swapBuffer_();
    virtual void clearFrameBuffers_(int);
    virtual void waitForGpuDone_();
    virtual void setGpuTimeStamp_();

    void initializeGraphicsSystem(Heap*, Vector2f const&);
    void* getAcquiredDisplayBufferTexture() const;  // return type?
    unsigned long getGraphicsDevToolsAllocatorTotalFreeSize() const;
    void setVBlankWaitInterval(unsigned int);
    void outOfMemoryCallback_(NVNcommandBuffer*, NVNcommandBufferMemoryEvent, unsigned long, void*);
    void presentAsync_(Thread*, long);
    void requestChangeUseGPU(bool);
    void waitVsyncEvent_();

    int mVBlankWaitInterval;
    unsigned char padding[0x10];
    unsigned int uVar1;
    unsigned int uVar2;
    bool bVar1;
    bool mIsTripleBuffer;
    bool bVar2;
    bool bVar3;
    unsigned char padding1[0x8];
    int iVar1;
    unsigned int uVar3;
    unsigned int uVar4;
    int mComputeMemorySize;
    int mCommandMemorySize;
    int mControlMemorySize;
    unsigned int mDebugLevel;
    ulong mFrameDuration;
    ulong mPrevFrameTick;
    agl::RenderBuffer* mMethodFrameBuffer;
    LogicalFrameBuffer mMethodLogicalFrameBuffer;
    void* pvVar1;
    DisplayBufferNvn* mDisplayBufferNvn;
    void* pvVar2;
    void* pvVar3;
    NVNmemoryPool* uVar5;
    void* mCommandBufferControl;
    NVNcommandBuffer* mNVNcommandBuffer;
    NVNbuffer* uVar6;
    NVNcounterData* uVar7;
    NVNmemoryPool* mShaderScratchMemory;
    unsigned int uVar8;
    nn::mem::StandardAllocator* mGraphicsDevToolsAllocator;
    void* pvVar4;
    void* pvVar5;
    NVNqueue* mNVNqueue;
    agl::RenderBuffer* mCurRenderBuffer;
    nn::vi::Display* mDisplay;
    nn::vi::Layer* mLayer;
    DelegateThread* mPresentationThread;
    void* pvVar6;
    SafeString sVar1;
    void* pvVar7;
    nn::os::SystemEventType mVsyncEvent;
    unsigned char padding2[0x18];
    bool bVar4;
    bool bVar5;
    bool bVar6;
    u8 uVar9;


};
} // namespace sead
