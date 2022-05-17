#pragma once

#include "al/layout/LayoutActor.h"
#include <sead/prim/seadSafeString.h>
#include <sead/container/seadPtrArray.h>

class CommonVerticalList;
namespace al {
class SimpleLayoutAppearWaitEnd;
class RollParts;
}

class ShineListLayout : public al::LayoutActor {
public:
    CommonVerticalList* mCommonVerticalList;
    sead::WBufferedSafeString* uVar1;
    sead::WBufferedSafeString* uVar2;
    sead::WBufferedSafeString* uVar3;
    char* uVar4;
    sead::WBufferedSafeString* uVar5;
    sead::SafeString* uVar6;
    sead::SafeString* uVar7;
    char16_t** mWorldNames;
    sead::PtrArray<al::SimpleLayoutAppearWaitEnd> mShineListPos;
    sead::PtrArray<al::SimpleLayoutAppearWaitEnd> mShineListPosSelect;
    al::RollParts* mRollParts;
    al::SimpleLayoutAppearWaitEnd* mShineListAchieve;
    int mWorldTotalShineNum;
};
