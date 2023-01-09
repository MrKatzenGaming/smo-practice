#pragma once

#include <sead/math/seadVector.h>

class PlayerJumpMessageRequest {
public:
    int mType;
    float fVar1;
    int iVar1;
    sead::Vector3f vVar1;
    sead::Vector3f vVar2;
    bool bVar1;
    bool bVar2;
};
