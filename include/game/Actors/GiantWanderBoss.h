#pragma once

#include "al/LiveActor/LiveActor.h"
#include "al/LiveActor/LiveActorGroup.h"
#include "al/iuse/ISceneObj.h"
#include "game/Interfaces/IUseDemoSkip.h"
#include "game/Interfaces/IUsePlayerCollision.h"
#include "game/Actors/Shine.h"
#include "sead/math/seadMatrix.h"
#include "sead/math/seadQuat.h"
#include "sead/math/seadVector.h"

namespace al {
class CameraTicket;
class WaterSurfaceFinder;
class WipeSimple;
class CameraSubTargetBase;
class SimpleLayoutAppearWaitEnd;
class ActorSensorController;
}
class GiantWanderBossStateOnGlass;
class GiantWanderBossStateAttack;
class GiantWanderBossStateEscapeCancel;
class RumbleCalculatorCosMultLinear;
class GiantWanderBossBullet;
class GiantWanderBossMine;
class GiantWanderBossRailHolder;
class GiantWanderBossRailMove;
class GiantWanderBossPreBattleBgmController;
class GiantWanderBossBattleBgmController;
class WaterSurfaceShadow;
class WaterLauncherCork;
class KoopaShip;
class JointSpringControllerHolder;
class GiantWanderBossLifeUpItemHolder;
class CollisionShapeKeeper;
class GiantWanderBossFootEffect;

class GiantWanderBoss : public al::LiveActor, public al::ISceneObj, public IUsePlayerCollision, public IUseDemoSkip {
public:
    GiantWanderBossStateOnGlass* mStateOnGlass;
    GiantWanderBossStateAttack* mStateAttack;
    GiantWanderBossStateEscapeCancel* mStateEscapeCancel;
    Shine* mShine;
    int mLevel;
    int iVar1;
    RumbleCalculatorCosMultLinear* mRumbleCalculator;
    float fVar1;
    al::LiveActorGroup* mBullets;
    al::LiveActorGroup* mMines;
    GiantWanderBossBullet* mCurBullet;
    GiantWanderBossMine* mCurMine;
    float fVar2;
    int iVar2;
    al::CameraTicket* uVar1;
    al::CameraTicket* uVar2;
    sead::Vector3f mPlayerTransAfterDemoBattleStart;
    sead::Quatf mPlayerQuatAfterDemoBattleStart;
    sead::Vector3f mPlayerTransAfterDemoBattleEnd;
    sead::Quatf mPlayerQuatAfterDemoBattleEnd;
    sead::Matrix34f mVar1;
    GiantWanderBossRailHolder* mRailHolder;
    GiantWanderBossRailMove* mRailMove;
    float fVar3;
    GiantWanderBossPreBattleBgmController* mPreBattleBgmController;
    GiantWanderBossBattleBgmController* mBattleBgmController;
    al::WaterSurfaceFinder* mWaterSurfaceFinder;
    WaterSurfaceShadow* mWaterSurfaceShadow;
    al::LiveActor* uVar3;
    al::LiveActorGroup* uVar4; // hosui group
    al::LiveActorGroup* uVar5; // resurrection hosui group
    al::LiveActorGroup* mHipDropSwitches;
    al::LiveActorGroup* mCorks;
    bool mSwitchesHit[4];
    WaterLauncherCork* mWaterLauncherCork;
    al::CameraTicket** uVar6;
    al::CameraTicket** uVar7;
    al::CameraTicket* uVar8;
    al::WipeSimple* mFadeWhite;
    int iVar3;
    al::CameraSubTargetBase* mCameraSubTarget;
    void* uVar9;
    sead::Vector3f vVar1;
    bool bVar1;
    KoopaShip* mKoopaShip;
    int iVar4;
    int iVar5;
    JointSpringControllerHolder* mJointSpringControllerHolder;
    al::SimpleLayoutAppearWaitEnd* mStartScenario;
    int iVar6;
    sead::Vector3f mDemoPos;
    sead::Quatf mDemoQuat;
    al::CameraTicket* uVar10;
    sead::Vector3f vVar2;
    sead::Vector3f vVar3;
    al::LiveActorGroup* uVar11; // fountain demo
    al::LiveActorGroup* mDemoEffects;
    void* uVar12;
    GiantWanderBossLifeUpItemHolder* mLifeUpItemHolder;
    al::ActorSensorController* mActorSensorController;
    sead::Vector3f vVar4;
    sead::Quatf qVar4;
    bool bVar2;
    int iVar7;
    float fVar4;
    float fVar5;
    bool bVar3;
    int iVar8;
    IUsePlayerCollision* mPlayerCollider;
    CollisionShapeKeeper* mCollisionShapeKeeper;
    sead::Matrix34f* mVar2;
    bool bVar4;
    GiantWanderBossFootEffect** mFootEffects;
    bool bVar5;
    sead::Matrix34f mVar3;
    bool bVar6;
    bool mIsMagmaOn;
};
