#pragma once

#include <sead/container/seadStrTreeMap.h>
#include <sead/heap/seadExpHeap.h>
#include <sead/heap/seadFrameHeap.h>
#include <sead/heap/seadHeap.h>
#include <sead/heap/seadHeapMgr.h>


namespace al {
class MemorySystem {
public:
    sead::ExpHeap* mStationedHeap;
    sead::ExpHeap* mSequenceHeap;
    sead::FrameHeap* mSceneResourceHeap;
    sead::FrameHeap* mSceneHeap;
    sead::Heap* mPlayerHeap;
    sead::FrameHeap* mCourseSelectResourceHeap;
    sead::FrameHeap* mCourseSelectHeap;
    sead::ExpHeap* mWorldResourceHeap;
    sead::StrTreeMap<32, sead::Heap*> mNamedHeaps;
    unsigned char gap[0x8];
    bool bVar1; // allows use of SystemData/MemorySystem.szs/HeapSizeDefine.byml
    sead::Delegate1<al::MemorySystem, sead::HeapMgr::AllocFailedCallbackArg const*> mDelegate;
};
}
