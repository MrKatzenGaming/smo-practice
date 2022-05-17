#pragma once

#include "al/PlayerHolder/PlayerHolder.h"
#include "al/area/AreaObjGroup.h"
#include "al/camera/CameraDirector.h"
#include "al/iuse/IUseAreaObj.h"
#include "al/iuse/IUseStageSwitch.h"
#include "al/area/AreaObjDirector.h"
#include "al/switch/StageSwitchKeeper.h"

#include <sead/container/seadPtrArray.h>
#include <sead/math/seadVector.h>

namespace al {

class SwitchAreaTargetInfo {
public:
    sead::Vector3f* vVar1;
    int iVar1;
    int iVar2;
    sead::Vector3f* vVar2;
    int iVar3;
    int iVar4;
    sead::Vector3f* vVar3;
    int iVar5;
};

class SwitchOnAreaGroup {
public:
    virtual bool isExternalCondition() const;

    al::AreaObjGroup* mGroup;
};

class SwitchKeepOnAreaGroup {
public:
    virtual void selectTargetPosArray(bool*, sead::Vector3f**, int*, al::AreaObj const*, al::SwitchAreaTargetInfo const*);
    virtual bool isExternalCondition() const;

    al::AreaObjGroup* mGroup;
    al::IUseStageSwitch* mUsers;
    int mAreaCount;
    int mUserCount;
};

class SwitchAreaDirector : public al::IUseAreaObj {
public:
    al::AreaObjDirector* mAreaObjDirector;
    PlayerHolder* mPlayerHolder;
    al::CameraDirector* mCameraDirector;
    SwitchAreaTargetInfo* mSwitchAreaTargetInfo;
    sead::PtrArray<SwitchOnAreaGroup> mSwitchOnAreaGroups;
    sead::PtrArray<SwitchKeepOnAreaGroup> mSwitchKeepOnAreaGroups;
    bool bVar1;
};

}
