#pragma once

#include "al/actor/Placement.h"
#include "sead/prim/seadSafeString.h"

class GameDataHolder;
class ChangeStageInfo {
public:
    struct SubScenarioType
    {
        u32 type;
    };
    ChangeStageInfo(const GameDataHolder*, const al::PlacementInfo&);
    ChangeStageInfo(const GameDataHolder*, const al::PlacementInfo&, const char* entranceName, const char* stageName, bool, int scenario, ChangeStageInfo::SubScenarioType);
    ChangeStageInfo(const GameDataHolder*, const char* entranceName, const char* stageName, bool, int scenario, ChangeStageInfo::SubScenarioType);

    void copy(const ChangeStageInfo&);
    s32 findScenarioNoByList(const GameDataHolder*); // return type(?)
    void init();
    void init(const al::PlacementInfo&, const GameDataHolder*);
    bool isSubScenarioTypeLifeRecover() const;
    bool isSubScenarioTypeResetMiniGame() const;
    void setWipeType(const char* type);

    sead::FixedSafeString<128> mChangeStageId;
    sead::FixedSafeString<128> mChangeStageName;
    sead::FixedSafeString<128> mObjId;
    bool mUnkBool;
    s32 mScenario;
    SubScenarioType mSubScenarioType;
    sead::FixedSafeString<128> mWipeType;
    int mHintPriority;
};

