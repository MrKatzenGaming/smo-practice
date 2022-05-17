#pragma once
/**
 * @file HackCap.h
 * @brief Main Class for HackCap (Cappy)
* Vtable loc: 1D75520
*/

#include "al/LiveActor/LiveActor.h"
#include "game/Player/PlayerCapActionHistory.h"
#include "game/Player/PlayerInput.h"
#include "game/Player/PlayerWallActionHistory.h"
#include "sead/math/seadVector.h"
#include "types.h"

#define HACKSIZE sizeof(al::LiveActor)

namespace al {
class WaterSurfaceFinder;
class PadRumbleKeeper;
}
class IUsePlayerCollision;
class PlayerAreaChecker;
class PlayerSeparateCapFlag;
class IUsePlayerHeightCheck;
class PlayerWetControl;
class PlayerJointControlKeeper;
class PlayerColliderHackCap;
class HackCapTrigger;
class HackCapAboveGroundChecker;
class HackCapThrowParam;
class CapTargetInfo;
class PlayerEyeSensorHitHolder;

class HackCap : public al::LiveActor {
    public: 

        void calcReturnTargetPos(sead::Vector3f *);

        void hide(bool);
        void forcePutOn(void);

        void startPuppet();
        void setupThrowStart();

        bool isFlying(void) const;

        unsigned char padding_108[0x108 - HACKSIZE];
        al::LiveActor* mActorDisplayHat;
        al::LiveActor* mActorDepthShadow;
        al::LiveActor* mActorEyes;
        al::LiveActor* mActorThrownEyes;
        al::LiveActor* mPlayerActor;
        IUsePlayerCollision* mPlayerCollision;
        char* mCapModelName;
        PlayerAreaChecker* mJudgeInWater;
        PlayerSeparateCapFlag* mSeparateCapFlag;
        IUsePlayerHeightCheck* mPlayerHeightCheck;
        PlayerWetControl* mPlayerWetControl;
        PlayerJointControlKeeper* mPlayerJointControlKeeper;
        PlayerColliderHackCap* mPlayerColliderHackCap;
        al::WaterSurfaceFinder* mWaterSurfaceFinder;
        al::PadRumbleKeeper* mPadRumbleKeeper;
        PlayerWetControl* mHackCapWetControl;
        HackCapTrigger* mHackCapTrigger;
        void* gap1;
        HackCapAboveGroundChecker* mAboveGroundChecker;
        unsigned char gap2[0x40];
        sead::Vector3f mSensorTail1;
        sead::Vector3f mSensorTail2;
        sead::Vector3f mSensorTail3;
        sead::Vector3f mSensorTail4;
        sead::Vector3f mSensorTail5;
        HackCapThrowParam* mThrowParam;
        void* gap3;
        CapTargetInfo* mCapTargetInfo;
        unsigned char gap4[0x6a];
        bool bVar1;
        bool bVar2;
        bool bVar3;
        bool bVar4;
        bool bVar5;
        bool bVar6;
        bool bVar7;
        bool bVar8;
        PlayerWallActionHistory* mWallActionHistory;
        PlayerCapActionHistory* mCapActionHistory;
        PlayerInput* mPlayerInput;
        PlayerEyeSensorHitHolder* mPlayerEyeSensorHitHolder1;
        PlayerEyeSensorHitHolder* mPlayerEyeSensorHitHolder2;
        sead::Vector3f mPos1;
        sead::Vector3f mPos2;
        sead::Vector3f mPos3;
        sead::Vector3f mPos4;
        bool bVar9;
        bool bVar10;
        bool bVar11;
        void* strVar1;
        
};
