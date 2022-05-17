#pragma once

#include "al/execute/ExecutorListBase.h"
#include "al/execute/ExecutorListActor.h"
#include "al/execute/ExecutorListActorModelDraw.h"
#include "al/execute/ExecutorListFunctor.h"
#include "al/execute/ExecutorListIUseExecutor.h"
#include "al/execute/ExecutorListLayout.h"
#include "al/hio/HioNode.h"
#include <sead/container/seadPtrArray.h>

namespace al {

class ExecuteTableHolderUpdate : public al::HioNode {
public:

};

class ExecuteTableHolderDraw : public al::HioNode {
public:
    virtual ~ExecuteTableHolderDraw();

    const char* mName;
    sead::PtrArray<void> arr1;
    sead::PtrArray<al::ExecutorListBase> mListAll;
    sead::PtrArray<al::ExecutorListActorExecuteBase> mListActor;            // useless? some entries have 8 buffer size but no items
    sead::PtrArray<al::ExecutorListActorModelDrawBase> mListActorModel;     // more useful lol
    sead::PtrArray<al::ExecutorListLayoutDrawBase> mListLayout;
    sead::PtrArray<al::ExecutorListIUseExecutorBase> mListUser;
    sead::PtrArray<al::ExecutorListFunctor> mListFunctor;
};

}
