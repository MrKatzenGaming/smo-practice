#pragma once

#include "al/LiveActor/LiveActor.h"
#include "al/nerve/NerveStateBase.h"
#include "al/sensor/SensorMsg.h"
#include "sead/math/seadVector.h"

class KillerStateHack : public al::ActorStateBase {

};

class Killer : public al::LiveActor {
public:
    unsigned char padding[0x8];
    KillerStateHack* mStateHack;
    int iVar1;
    float mAliveCount;
    int iVar2;
    sead::Vector3f vVar1;
    float fVar1;
    bool bVar1;
    bool bVar2;
    bool bVar3;
    bool bVar4;
    bool bVar5;
    bool bVar6;
    int iVar3;
};
