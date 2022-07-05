#pragma once

#include "al/area/AreaObj.h"
namespace al {
class AreaObjGroup {
public:
    const char* mGroupName;
    al::AreaObj** mAreas;
    int mAreaCount;
    int mBufferSize;
};
}
