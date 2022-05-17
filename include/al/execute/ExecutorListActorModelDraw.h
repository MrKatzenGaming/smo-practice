#pragma once

#include "al/execute/ExecutorActor.h"
#include "al/execute/ExecutorListBase.h"
#include <sead/container/seadPtrArray.h>

namespace al {
class ExecutorListActorModelDrawBase : public al::ExecutorListBase {
public:
    sead::PtrArray<al::ExecutorActorDraw> mActors;
};
}
