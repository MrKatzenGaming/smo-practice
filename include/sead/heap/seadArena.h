#pragma once

#include <sead/basis/seadTypes.h>

namespace sead {
class Arena {
public:
    Arena();
    ~Arena();

    u8* initialize(size_t size);

    u8* mStart;
    size_t mSize;
    bool mInitWithStartAddress;
};
}  // namespace sead
