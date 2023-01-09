#pragma once

#include "al/rail/BezierCurve.h"
#include "al/rail/LinearCurve.h"
#include <sead/math/seadVector.h>

namespace al {
class RailPart {
public:
    RailPart();
    void init(sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&, sead::Vector3f const&);

    void calcPos(sead::Vector3f*, float) const;
    void calcVelocity(sead::Vector3f*, float) const;
    void calcDir(sead::Vector3f*, float) const;
    void calcStartPos(sead::Vector3f*) const;
    void calcEndPos(sead::Vector3f*) const;
    float calcLength(float, float, int) const;
    float calcCurveParam(float) const;
    float calcNearestParam(sead::Vector3f const&, float) const;
    void calcNearestPos(sead::Vector3f*, sead::Vector3f const&, float);
    float calcNearestLength(float*, sead::Vector3f const&, float, float) const;
    float getPartLength() const;

    al::BezierCurve* mBezierCurve;
    al::LinearCurve* mLinearCurve;
    float fVar1;
};
}
