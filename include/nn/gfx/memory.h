/**
 * @file memory.h
 * @brief GFX Memory Pool.
 */

#pragma once

#include <nvn/nvn_types.h>

namespace nn {
namespace gfx {
// todo: finish me!
template<typename T>
class TMemoryPool { };

template <typename T>
class MemoryPoolImpl {
public:
    NVNmemoryPool* mMemoryPoolPtr;
    void* uVar1;
    NVNmemoryPool mMemoryPool;
    bool bVar1;
    int8_t iVar1;
    void* uVar2;
};
}
}
