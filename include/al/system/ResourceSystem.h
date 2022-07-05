#pragma once

#include "al/byaml/ByamlIter.h"

namespace al {
class ResourceSystem {
public:
    unsigned char padding[0xa8];
    al::ByamlIter* mResourceCategoryTable;
    const char* mCurrentCategory;
    unsigned char padding1[0x10];
};
}
