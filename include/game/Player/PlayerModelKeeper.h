#pragma once

#include "al/LiveActor/LiveActor.h"
#include "game/Interfaces/IUseDimension.h"
#include "game/Player/PlayerEquipmentUser.h"

class PlayerModelKeeper {
    public:

};

class PlayerCostumeInfo;
class PlayerPainPartsKeeper;

class PlayerModelChangerHakoniwa {
public:
    unsigned char padding1[0x10];
    bool mIsChange;
    bool mIs2DModel;
    al::LiveActor* mActor1;
    PlayerModelHolder* mModelHolder;
    PlayerPainPartsKeeper* mPainPartsKeeper;
    PlayerCostumeInfo* mCostumeInfo;
    IUseDimension* mDimensionKeeper;
    bool bVar1;
    bool mIsShownModel;
    bool bVar2;
    bool mIsShownShadowMask;
};
