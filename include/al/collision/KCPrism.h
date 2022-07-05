#pragma once

#include <sead/math/seadVector.h>

typedef unsigned short ushort;
typedef unsigned int uint;

namespace al {
class KCPrismData { // triangle
public:
    float mLength;
    ushort mPosIndex;
    ushort mFaceNormalIndex;
    ushort mEdgeNormalIndex[3];
    ushort mCollisionType;
    uint mTriIndex;
};

class KCPrismHeader { // model
public:
    uint mPositionsOffset;
    uint mNormalsOffset;
    uint mTrianglesOffset;
    uint mOctreeOffset;
    float mThickness;
    sead::Vector3f mOctreeOrigin;
    uint mXMask;
    uint mYMask;
    uint mZMask;
    uint mCoordShift;
    uint mYShift;
    uint mZShift;
    float mHitboxRadiusCap;
};

}
