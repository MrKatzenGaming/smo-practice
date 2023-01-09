#pragma once

#include "al/LiveActor/LiveActor.h"
#include "game/Actors/BreedaChainList.h"
#include "game/Actors/BreedaWanwan.h"

namespace al {
class WipeSimple;
class SaveObjInfo;
class JointAimInfo;
}

class Shine;
class CapManHeroBase;
class BossStateTalkDemo;
class BreedaSkirtJointController;
class BreedaSkirtHemJointController;
class JointSpringControllerHolder;
class BarrierField;

class Breeda : public al::LiveActor {
public:
    al::CameraTicket* mDemoAnimCamera;
    al::CameraTicket* mTowerCameraWithSave;
    al::WipeSimple* mFadeBlack;
    al::SaveObjInfo* mSaveObjInfo;
    BreedaWanwan* mBreedaWanwan;
    al::LiveActor* uVar1;
    CapManHeroBase* mDemoCapManHero;
    BreedaChainList* mChainList;
    Shine* mShine;
    al::JointAimInfo* mJointAimInfo;
    BossStateTalkDemo* mStateTalkDemo;
    sead::Quatf qVar1;
    sead::Vector3f vVar1;
    BreedaSkirtJointController* mSkirtJointController;
    BreedaSkirtHemJointController** mSkirtHemJointController;
    JointSpringControllerHolder* mJointSpringControllerHolder;
    sead::Vector3f vVar2;
    sead::Quatf mBattleStartDemoAfterPlayerQuat;
    sead::Vector3f mBattleStartDemoAfterPlayerPos;
    sead::Quatf mBattleEndDemoAfterPlayerQuat;
    sead::Vector3f mBattleEndDemoAfterPlayerPos;
    sead::Vector3f mBreedaHandPos;
    sead::Vector3f mThrowEndPos;
    sead::Vector3f mWanwanTrans;
    int iVar1;
    int iVar2;
    int iVar3;
    BarrierField* mBarrierField;
};
