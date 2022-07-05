#pragma once

#include <sead/filedevice/seadFileDevice.h>
#include <sead/thread/seadCriticalSection.h>


namespace al {
class FileLoaderThread;
class ArchiveHolder;
class SoundItemHolder;

class FileLoader {
public:
    al::FileLoaderThread* mLoaderThread;
    al::ArchiveHolder* mArchiveHolder;
    al::SoundItemHolder* mSoundItemHolder;
    bool bVar1;
    sead::FileDevice* mFileDevice;
    sead::CriticalSection mCriticalSection;
};
}
