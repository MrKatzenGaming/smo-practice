#pragma once

#include "al/async/AsyncFunctorThread.h"
#include <sead/prim/seadSafeString.h>

namespace al {
class SaveDataSequenceBase {};
class SaveDataSequenceInitDir : public SaveDataSequenceBase {};
class SaveDataSequenceFormat : public SaveDataSequenceBase {};
class SaveDataSequenceRead : public SaveDataSequenceBase {};
class SaveDataSequenceWrite : public SaveDataSequenceBase {};

class SaveDataDirector {
public:
    al::SaveDataSequenceBase* mCurrentSequence;
    al::SaveDataSequenceInitDir* mSequenceInitDir;
    al::SaveDataSequenceFormat* mSequenceFormat;
    al::SaveDataSequenceRead* mSequenceRead;
    al::SaveDataSequenceWrite* mSequenceWrite;
    bool mIsCheckSaveData;
    bool bVar1;
    unsigned char padding[0x6];
    int iVar1;
    unsigned char* uVar1;
    sead::FixedSafeString<64> sVar1;
    al::AsyncFunctorThread* mSaveDataThread;
    int mResult;
};
}
