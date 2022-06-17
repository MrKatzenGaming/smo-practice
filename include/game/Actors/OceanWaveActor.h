#pragma once

#include "al/nature/OceanWave.h"
#include "al/LiveActor/LiveActor.h"

#include <sead/math/seadMatrix.h>
#include <sead/container/seadPtrArray.h>

class OceanWaveActor : public al::LiveActor {
public:
    al::OceanWave* mOceanWave;
    int mConfigPreset;
    sead::Matrix34f mVar1;
    char* sVar1;
    float fVar1;
    bool bVar1;
    unsigned char gap1[0x10];
    sead::PtrArrayImpl arr1;
    unsigned char gap2[0x10];
    sead::PtrArrayImpl arr2;
};