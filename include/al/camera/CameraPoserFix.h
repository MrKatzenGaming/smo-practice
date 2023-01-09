#pragma once

#include "al/camera/CameraPoser.h"

namespace al {
class CameraPoserFix : public al::CameraPoser {
public:
    sead::Vector3f mLookAtPos;
    float mDistance;
    float mAngleV;
    float mAngleH;
    bool mIsCalcNearestAtFromPreAt;
};
}
