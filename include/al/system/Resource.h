#pragma once

#include <sead/filedevice/seadArchiveFileDevice.h>
#include <sead/prim/seadSafeString.h>
#include <sead/heap/seadHeap.h>
#include <nn/g3d/g3d_ResFile.h>

namespace al {
class ActorInitResourceData;

class Resource {
public:
    const char* getArchiveName() const;

    sead::ArchiveRes* mArchiveRes;
    sead::ArchiveFileDevice* mArchiveFileDevice;
    sead::FixedSafeString<128> mArchiveName;
    sead::Heap* mHeap;
    al::ActorInitResourceData* mActorInitResourceData;
    nn::g3d::ResFile* mResFile;
};
}
