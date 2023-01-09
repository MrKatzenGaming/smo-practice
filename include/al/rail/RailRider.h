#pragma once

#include "al/rail/Rail.h"
#include <sead/math/seadVector.h>

namespace al {
class RailRider {
public:
    RailRider(al::Rail const*);
    void moveToRailStart();
    void move();
    void syncPosDir();
    void setCoord(float);
    void moveToRailPoint(int);
    void moveToRailEnd();
    void moveToBegin();
    void moveToGoal();
    void moveToNearestRail(sead::Vector3f const&);
    void reverse();
    void setMoveGoingStart();
    void setMoveGoingEnd();
    void setSpeed(float);
    void addSpeed(float);
    void scaleSpeed(float);
    bool isReachedGoal() const;
    bool isReachedRailEnd() const;
    bool isReachedRailStart() const;
    bool isReachedEdge() const;

    al::Rail* mRail;
    sead::Vector3f vVar1;
    sead::Vector3f vVar2;
    float fVar1;
    float mSpeed;
    bool mIsMoveGoingEnd;
};
}
