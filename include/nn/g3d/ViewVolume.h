#pragma once

namespace nn::g3d {
struct Aabb {
    unsigned char gap1[0x8];
    unsigned long lVar1;
    unsigned char gap2[0x8];
    unsigned long lVar2;
};

struct Plane {
    unsigned char gap1[0x8];
    long lVar1;
    float fVar1;
    unsigned char gap2[0xc];
};

class ViewVolume {
public:
    nn::g3d::Aabb mAabb;
    nn::g3d::Plane mPlanes[6];
    int iVar1;
    int iVar2;
};
}
