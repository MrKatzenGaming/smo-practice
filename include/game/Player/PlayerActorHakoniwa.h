#pragma once
/**
 * @file PlayerActorBase.h
 * @brief Main Class for the PlayerActor (Mario)
 * Player Pose: TQGMSV
*  Vtable loc: 1D780C0
*/

#include "PlayerActorBase.h"
#include "al/sensor/HitSensor.h"
#include "al/actor/ActorDimensionKeeper.h"
#include "game/Interfaces/IUseDimension.h"
#include "PlayerInput.h"
#include "PlayerTrigger.h"
#include "PlayerAnimator.h"
#include "HackCap.h"
#include "PlayerModelKeeper.h"
#include "PlayerRecoverySafetyPoint.h"
#include "PlayerDamageKeeper.h"
#include "PlayerHackKeeper.h"
#include "PlayerJudge.h"
#include "PlayerState.h"
#include "PlayerEquipmentUser.h"
#include "PlayerConst.h"
#include "PlayerWallActionHistory.h"
#include "PlayerCapActionHistory.h"
#include "PlayerCounter.h"
#include "PlayerStainControl.h"
#include "game/Player/PlayerCollider.h"
#include "game/Player/PlayerCarryKeeper.h"
#include "game/WorldEndBorderKeeper.h"
#include "types.h"

#define PACTORSIZE sizeof(PlayerActorBase)

namespace al {
class WaterSurfaceFinder;
class FootPrintHolder;
}
class PlayerPuppet;
class PlayerDemoActionFlag;
class PlayerCapManHeroEyesControl;
class PlayerContinuousJump;
class PlayerContinuousLongJump;
class PlayerBindKeeper;
class PlayerFormSensorCollisionArranger;
class PlayerJumpMessageRequest;
class PlayerSandSinkAffect;
class PlayerSpinCapAttack;
class PlayerActionDiveInWater;
class PlayerEffect;
class PlayerEyeSensorHitHolder;
class PlayerPushReceiver;
class PlayerHitPush;
class PlayerJointControlKeeper;
class PlayerPainPartsKeeper;
class PlayerRippleGenerator;
class PlayerSeparateCapFlag;
class PlayerWetControl;
class GaugeAir;
class WaterSurfaceShadow;
class PlayerSeCtrl;
class ActorStateSandGeyser;
class HackCapJudgePreInputHoveringJump;
class HackCapJudgePreInputSeparateThrow;
class HackCapJudgePreInputSeparateJump;
class PlayerInfo;


class PlayerActorHakoniwa : public PlayerActorBase , public IUseDimension {
    public: 
        int *getPortNo(void) const;
        void startDemoMainShineGet();
        void endDemoMainShineGet();
        void startDemoPuppetable();
        void endDemoPuppetable();
        void startDemoShineGet();
        void tryActionStartSpinAttack();
        unsigned char padding_E8[0x128 - PACTORSIZE];
        PlayerInfo* mPlayerInfo;
        PlayerConst* mPlayerConst;
        PlayerInput* mPlayerInput;
        PlayerTrigger* mPlayerTrigger;
        HackCap* mHackCap;
        ActorDimensionKeeper* mActorDimensionKeeper;
        PlayerModelKeeper* mModelKeeper;
        PlayerModelChangerHakoniwa* mModelChangerHakoniwa;
        PlayerAnimator* mAnimator;
        PlayerColliderHakoniwa* mColliderHakoniwa;
        PlayerPuppet* mPuppet;
        PlayerJudgeInWater* mJudgeInWater;
        al::WaterSurfaceFinder* mWaterSurfaceFinder;
        void* gap1;
        PlayerDamageKeeper* mDamageKeeper;
        PlayerDemoActionFlag* mDemoActionFlag;
        PlayerCapActionHistory* mCapActionHistory;
        PlayerCapManHeroEyesControl* mCapManHeroEyesControl;
        PlayerContinuousJump* mContinuousJump;
        PlayerContinuousLongJump* mContinuousLongJump;
        PlayerCounterAfterUpperPunch* mCounterAfterUpperPunch;
        PlayerCounterForceRun* mCounterForceRun;
        PlayerCounterIceWater* mCounterIceWater;
        PlayerCounterQuickTurnJump* mCounterQuickTurnJump;
        PlayerWallActionHistory* mWallActionHistory;
        PlayerBindKeeper* mBindKeeper;
        PlayerCarryKeeper* mCarryKeeper;
        PlayerEquipmentUser* mEquipmentUser;
        PlayerHackKeeper* mHackKeeper;
        PlayerFormSensorCollisionArranger* mFormSensorCollisionArranger;
        PlayerJumpMessageRequest* mJumpMessageRequest;
        PlayerSandSinkAffect* mSandSinkAffect;
        PlayerSpinCapAttack* mSpinCapAttack;
        PlayerActionDiveInWater* mActionDiveInWater;
        PlayerEffect* mPlayerEffect;
        PlayerEyeSensorHitHolder* mEyeSensorHitHolder;
        PlayerPushReceiver* mPushReceiver;
        PlayerHitPush* mHitPush;
        void* gap2;
        PlayerJointControlKeeper* mJointControlKeeper;
        PlayerPainPartsKeeper* mPainPartsKeeper;
        PlayerRecoverySafetyPoint* mRecoverPoint;
        PlayerRippleGenerator* mRippleGenerator;
        PlayerSeparateCapFlag* mSeparateCapFlag;
        PlayerWetControl* mWetControl;
        PlayerStainControl* mStainControl;
        al::FootPrintHolder* mFootPrintHolder;
        GaugeAir* mGaugeAir;
        WaterSurfaceShadow* mWaterSurfaceShadow;
        WorldEndBorderKeeper* mWorldEndBorderKeeper;
        void* gap3;
        PlayerSeCtrl* mSeCtrl;
        al::HitSensor* mHitSensorBody;
        bool* mIsLongShadow;
        PlayerStateWait* mStateWait;
        PlayerStateSquat* mStateSquat;
        PlayerStateRunHakoniwa2D3D* mStateRunHakoniwa2D3D;
        PlayerStateSlope* mStateSlope;
        PlayerStateRolling* mStateRolling;
        PlayerStateSpinCap* mStateSpinCap;
        PlayerStateJump* mStateJump;
        PlayerStateCapCatchPop* mStateCapCatchPop;
        PlayerStateWallAir* mStateWallAir;
        void* gap4;
        PlayerStateGrabCeil* mStateGrabCeil;
        PlayerStatePoleClimb* mStatePoleClimb;
        PlayerStateHipDrop* mStateHipDrop;
        PlayerStateHeadSliding* mStateHeadSliding;
        PlayerStateLongJump* mStateLongJump;
        PlayerStateFallHakoniwa* mStateFallHakoniwa;
        PlayerStateSandSink* mStateSandSink;
        ActorStateSandGeyser* mStateSandGeyser;
        PlayerStateRise* mStateRise;
        PlayerStateSwim* mStateSwim;
        PlayerStateDamageLife* mStateDamageLife;
        PlayerStateDamageSwim* mStateDamageSwim;
        PlayerStateDamageFire* mStateDamageFire;
        PlayerStatePress* mStatePress;
        PlayerStateBind* mStateBind;
        PlayerStateHack* mStateHack;
        PlayerStateEndHack* mStateEndHack;
        PlayerStateCameraSubjective* mStateCameraSubjective;
        PlayerStateAbyss* mStateAbyss;
        PlayerJudgeAirForceCount* mJudgeAirForceCount;
        PlayerJudgeCameraSubjective* mJudgeCameraSubjective;
        PlayerJudgeCapCatchPop* mJudgeCapCatchPop;
        PlayerJudgeDeadWipeStart* mJudgeDeadWipeStart;
        PlayerJudgeDirectRolling* mJudgeDirectRolling;
        void* gap5;
        PlayerJudgeForceLand* mJudgeForceLand;
        PlayerJudgeForceSlopeSlide* mJudgeForceSlopeSlide;
        PlayerJudgeForceRolling* mJudgeForceRolling;
        PlayerJudgeGrabCeil* mJudgeGrabCeil;
        PlayerJudgeInWater* mJudgeInWater1;
        PlayerJudgeInWater* mJudgeInWater2;
        PlayerJudgeInWater* mJudgeInWater3;
        PlayerJudgeInWater* mJudgeInWater4;
        PlayerJudgeInvalidateInputFall* mJudgeInvalidateInputFall;
        PlayerJudgeLongFall* mJudgeLongFall;
        PlayerJudgeOutInWater* mJudgeOutInWater;
        PlayerJudgeRecoveryLifeFast* mJudgeRecoveryLifeFast;
        PlayerJudgeSandSink* mJudgeSandSink;
        PlayerJudgeSpeedCheckFall* mJudgeSpeedCheckFall;
        PlayerJudgeStartHipDrop* mJudgeStartHipDrop;
        PlayerJudgeStartRise* mJudgeStartRise;
        PlayerJudgeStartRolling* mJudgeStartRolling;
        PlayerJudgeStartRun* mJudgeStartRun;
        PlayerJudgeStartSquat* mJudgeStartSquat;
        PlayerJudgeStartWaterSurfaceRun* mJudgeStartWaterSurfaceRun;
        PlayerJudgeSlopeSlide* mJudgeSlopeSlide;
        PlayerJudgePoleClimb* mJudgePoleClimb;
        PlayerJudgePreInputJump* mJudgePreInputJump;
        PlayerJudgePreInputCapThrow* mJudgePreInputCapThrow;
        PlayerJudgePreInputHackAction* mJudgePreInputHackAction;
        HackCapJudgePreInputHoveringJump* mHackCapJudgePreInputHoveringJump;
        HackCapJudgePreInputSeparateThrow* mHackCapJudgePreInputSeparateThrow;
        HackCapJudgePreInputSeparateJump* mHackCapJudgePreInputSeparateJump;
        PlayerJudgeWallCatch* mJudgeWallCatch;
        PlayerJudgeWallCatchInputDir* mJudgeWallCatchInputDir;
        PlayerJudgeWallHitDown* mJudgeWallHitDown;
        PlayerJudgeWallHitDownForceRun* mJudgeWallHitDownForceRun;
        PlayerJudgeWallHitDownRolling* mJudgeWallHitDownRolling;
        PlayerJudgeWallKeep* mJudgeWallKeep;

};
