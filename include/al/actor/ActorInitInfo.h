#pragma once

#include "al/LiveActor/LiveActorGroup.h"
#include "al/actor/Placement.h"
#include "al/area/AreaObjDirector.h"
#include "al/camera/CameraDirector.h"
#include "al/collision/CollisionDirector.h"
#include "al/gamepad/util.h"
#include "al/layout/LayoutInitInfo.h"
#include "game/GameData/GameDataHolderBase.h"
#include "al/scene/SceneObjHolder.h"
#include "al/effect/EffectSystemInfo.h"

namespace al {
class ClippingDirector;
class DemoDirector;
class GravityHolder;
class ItemDirectorBase;
class NatureDirector;
class PadRumbleDirector;
class PlayerHolder;
class SceneStopCtrl;
class SceneMsgCtrl;
class SceneCoverCtrl;
class ShadowDirector;
class ModelGroup;
class GraphicsSystemInfo;
class ModelDrawBufferCounter;
class ActorFactory;
class ActorResourceHolder;
class AudioDirector;
class ExecuteDirector;
class HitSensorDirector;
class StageSwitchDirector;
class ScreenPointDirector;

class ActorInitInfo {
public:
    LiveActorGroup* mGroup1;
    PlacementInfo* mPlacementInfo;
    LayoutInitInfo* mLayoutInitInfo;
    AreaObjDirector* mAreaObjDirector;
    CameraDirector* mCameraDirector;
    ClippingDirector* mClippingDirector;
    CollisionDirector* mCollisionDirector;
    DemoDirector* mDemoDirector;
    GameDataHolderBase* mGameDataHolder;
    GravityHolder* mGravityHolder;
    ItemDirectorBase* mItemDirector;
    NatureDirector* mNatureDirector;
    GamePadSystem* mGamePadSystem;
    PadRumbleDirector* mPadRumbleDirector;
    PlayerHolder* mPlayerHolder;
    SceneObjHolder* mSceneObjHolder;
    SceneStopCtrl* mSceneStopCtrl;
    SceneMsgCtrl* mSceneMsgCtrl;
    SceneCoverCtrl* mSceneCoverCtrl;
    ShadowDirector* mShadowDirector;
    ModelGroup* mModelGroup;
    GraphicsSystemInfo* mGraphicsSystemInfo;
    ModelDrawBufferCounter* mModelDrawBufferCounter;
    LiveActorGroup* mGroup2;
    ActorFactory* mActorFactory;
    ActorResourceHolder* mActorResourceHolder;
    AudioDirector* mAudioDirector;
    EffectSystemInfo* mEffectSystemInfo;
    ExecuteDirector* mExecuteDirector;
    HitSensorDirector* mHitSensorDirector;
    StageSwitchDirector* mStageSwitchDirector;
    ScreenPointDirector* mScreenPointDirector;

};
};
