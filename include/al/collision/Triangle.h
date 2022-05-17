#pragma once

#include "al/collision/CollisionParts.h"
#include "al/collision/KCPrism.h"
#include <sead/math/seadVector.h>

namespace al {

class Triangle {
public:
    al::CollisionParts* mCollisionParts;
    al::KCPrismData* mKCPrismData;
    al::KCPrismHeader* mKCPrismHeader;
    sead::Vector3f mFaceNormal;
    sead::Vector3f mEdgeNormals[3];
    sead::Vector3f mVerts[3];

};

}
