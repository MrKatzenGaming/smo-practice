#pragma once

#include "al/LiveActor/LiveActor.h"

class CapTargetInfo;
class BreedaWanwanWanderState;
class EnemyStateSwoon;
class WanwanStateHack;
class JointSpringControllerHolder;

class BreedaWanwan : public al::LiveActor {
public:
    CapTargetInfo* mCapTargetInfo;
    BreedaWanwanWanderState* mStateWander;
    EnemyStateSwoon* mStateSwoon;
    WanwanStateHack* mStateHack;
    al::LiveActorGroup* mEnemyCap;
    JointSpringControllerHolder* mJointSpringControllerHolder;
    int iVar1;
    int mMaxCapCount;
    int mEnableCapCount;
    sead::Vector3f vVar1;
    sead::Vector3f vVar2;
    unsigned char gap1[0x8c];
    sead::Vector3f mBarrierFieldTrans;

};
