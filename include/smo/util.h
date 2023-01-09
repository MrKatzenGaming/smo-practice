#pragma once

#include "al/collision/CollisionParts.h"
#include "al/collision/KCollisionServer.h"
#include "al/collision/KCPrism.h"
#include "al/collision/Triangle.h"
#include <sead/math/seadQuat.h>
#include <sead/math/seadVector.h>

#define RAD(deg) (deg * (M_PI / 180))
#define DEG(rad) (rad * (180 / M_PI))

namespace smo {
    sead::Vector3f QuatToEuler(sead::Quatf* quat);
    void* memset(void* dest, int val, size_t len);
    void* memcpy(void* dest, const void* src, size_t len);
    void fillTri(al::Triangle* tri, al::CollisionParts const& collisionParts, al::KCPrismData const* prismData, al::KCPrismHeader const* prismHeader);
}
