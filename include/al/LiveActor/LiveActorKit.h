#pragma once

#include "al/PlayerHolder/PlayerHolder.h"
#include "al/area/AreaObjDirector.h"
#include "al/camera/CameraDirector.h"
#include "al/collision/CollisionDirector.h"
#include "al/execute/ExecuteDirector.h"
#include "al/execute/ExecuteAsyncExecutor.h"
#include "al/hio/HioNode.h"
#include "al/nature/NatureDirector.h"
#include "al/switch/SwitchAreaDirector.h"
#include "game/System/GameSystemInfo.h"
#include "LiveActorGroup.h"


namespace al {
class ActorResourceHolder;
class GravityHolder;
class GraphicsSystemInfo;
class ModelDrawBufferCounter;
class ModelDrawBufferUpdater;
class ModelDisplayListController;
class ClippingDirector;
class ItemDirectorBase;
class HitSensorDirector;
class ScreenPointDirector;
class ShadowDirector;
class StageSwitchDirector;
class ProjectDemoDirector;
class GamePadSystem;
class PadRumbleDirector;
class ModelGroup;

class LiveActorKit : public al::HioNode {
public:
    unsigned char gap1[0x8];
    int iVar1;
    ActorResourceHolder* mActorResourceHolder;
    AreaObjDirector* mAreaObjDirector;
    ExecuteDirector* mExecuteDirector;
    GravityHolder* mGravityHolder;
    EffectSystem* mEffectSystem;
    GraphicsSystemInfo* mGraphicsSystemInfo;
    ModelDrawBufferCounter* mModelDrawBufferCounter;
    ModelDrawBufferUpdater* mModelDrawBufferUpdater;
    ExecuteAsyncExecutor* mExecuteAsyncExecutor1;
    ExecuteAsyncExecutor* mExecuteAsyncExecutor2;
    ModelDisplayListController* mModelDisplayListController;
    void* unk1; // ExecuteSystemInitInfo
    LiveActorGroup* mOriginalDrawingGroup;
    CameraDirector* mCameraDirector;
    ClippingDirector* mClippingDirector;
    CollisionDirector* mCollisionDirector;
    ItemDirectorBase* mItemDirector;
    PlayerHolder* mPlayerHolder;
    HitSensorDirector* mHitSensorDirector;
    ScreenPointDirector* mScreenPointDirector;
    ShadowDirector* mShadowDirector;
    StageSwitchDirector* mStageSwitchDirector;
    SwitchAreaDirector* mSwitchAreaDirector;
    LiveActorGroup* mAllActors;
    ProjectDemoDirector* unk3;
    GamePadSystem* unk4;
    PadRumbleDirector* mPadRumbleDirector;
    NatureDirector* mNatureDirector;
    ModelGroup* mModelGroup;
};
}
