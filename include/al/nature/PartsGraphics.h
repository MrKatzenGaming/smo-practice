#pragma once

#include "al/iuse/IUsePartsGraphics.h"
#include <sead/container/seadListImpl.h>

namespace al {
class PartsGraphics : public al::IUsePartsGraphics {
public:
    sead::ListNode uVar1;
    al::PartsGraphics* uVar2;
    unsigned char gap1[0x8];
};
}