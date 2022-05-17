#pragma once

#include "al/PlayerHolder/PlayerHolder.h"
#include "al/area/AreaObjDirector.h"
#include "al/camera/CameraDirector.h"
#include "al/collision/CollisionDirector.h"
#include "al/execute/ExecuteDirector.h"
#include "al/hio/HioNode.h"
#include "game/System/GameSystemInfo.h"
#include "LiveActorGroup.h"


namespace al {

class ActorResourceHolder;
class GravityHolder;
class GraphicsSystemInfo;
class ModelDrawBufferUpdater;
class ExecuteAsyncExecutor;
class ModelDisplayListController;
class ClippingDirector;
class HitSensorDirector;
class ScreenPointDirector;
class ShadowDirector;
class StageSwitchDirector;
class SwitchAreaDirector;
class PadRumbleDirector;
class NatureDirector;
class ModelGroup;

class LiveActorKit : public al::HioNode { // 0xf8
public:
    unsigned char gap1[0x8];
    int iVar1;
    ActorResourceHolder* mActorResourceHolder;
    AreaObjDirector* mAreaObjDirector;
    ExecuteDirector* mExecuteDirector;
    GravityHolder* mGravityHolder;
    EffectSystem* mEffectSystem;
    GraphicsSystemInfo* mGraphicsSystemInfo;
    int* pIVar1;
    ModelDrawBufferUpdater* mModelDrawBufferUpdater;
    ExecuteAsyncExecutor* mExecuteAsyncExecutor1;
    ExecuteAsyncExecutor* mExecuteAsyncExecutor2;
    ModelDisplayListController* mModelDisplayListController;
    void* unk1;
    LiveActorGroup* mOriginalDrawingGroup;
    CameraDirector* mCameraDirector;
    ClippingDirector* mClippingDirector;
    CollisionDirector* mCollisionDirector;
    void* unk2;
    PlayerHolder* mPlayerHolder;
    HitSensorDirector* mHitSensorDirector;
    ScreenPointDirector* mScreenPointDirector;
    ShadowDirector* mShadowDirector;
    StageSwitchDirector* mStageSwitchDirector;
    SwitchAreaDirector* mSwitchAreaDirector;
    LiveActorGroup* mAllActors;
    void* unk3;
    void* unk4;
    PadRumbleDirector* mPadRumbleDirector;
    NatureDirector* mNatureDirector;
    ModelGroup* mModelGroup;
};
}
