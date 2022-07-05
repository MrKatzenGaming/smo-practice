#pragma once

#include "al/area/AreaObjDirector.h"
#include <sead/math/seadVector.h>

namespace al {
class CameraAngleVerticalRequester {
public:
    virtual AreaObjDirector getAreaObjDirector() const = 0;
    void update(sead::Vector3f const&);
};
}
