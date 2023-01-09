#pragma once

namespace nn::g3d {
class SkeletonObj;
class ShapeObj;
class MaterialObj;

class ModelObj {
public:
    unsigned char gap[0x30];
    unsigned short field_0x30;
    unsigned short uVar1;
    SkeletonObj* mSkeletonObj;
    ShapeObj* mShapeObj;
    MaterialObj* mMaterialObj;
    unsigned char gap1[0x40];
};
}
