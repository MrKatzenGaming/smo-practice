#pragma once

#include "al/LiveActor/LiveActor.h"
#include "sead/container/seadPtrArray.h"

class GhostPlayer;
class GoalMark;

class RaceManGoal : public al::LiveActor {
public:
    sead::PtrArray<GhostPlayer> mGhostPlayers;
    unsigned char gap[0x28];
    int mPlayerRankResult;
    GoalMark* mGoalMark;
    sead::PtrArrayImpl arr1;
    sead::PtrArrayImpl arr2;
    sead::Vector3f vVar1;
    float fVar1;
    float mHeightOffset;
};
