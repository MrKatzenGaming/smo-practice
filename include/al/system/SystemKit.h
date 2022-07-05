#pragma once

#include "al/system/MemorySystem.h"
#include "al/system/FileLoader.h"
#include "al/system/ResourceSystem.h"
#include "al/system/SaveDataDirector.h"

namespace al {
class SystemKit {
public:
    al::MemorySystem* mMemorySystem;
    al::FileLoader* mFileLoader;
    al::ResourceSystem* mResourceSystem;
    al::SaveDataDirector* mSaveDataDirector;
};
}
