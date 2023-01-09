#pragma once

#include "al/hio/HioNode.h"
#include <sead/container/seadPtrArray.h>
#include <sead/container/seadStrTreeMap.h>
#include <sead/prim/seadSafeString.h>

namespace al {
class InitResourceDataAnim;
class InitResourceDataAction;
class Resource;

class ActorResource : public al::IUseHioNode {
public:
    virtual ~ActorResource();

    sead::FixedSafeString<128> mResourcePath;
    al::Resource* mBaseResource;
    al::Resource* uVar1;
    bool bVar1;
    al::InitResourceDataAnim* mInitDataAnim;
    al::InitResourceDataAction* mInitDataAction;
};

class ActorResourceHolder : public al::IUseHioNode {
public:
    virtual ~ActorResourceHolder();

    sead::StrTreeMap<128, al::ActorResource*> uVar1;
    sead::PtrArray<al::ActorResource> mResources;
    sead::PtrArray<al::ActorResource> mErasedResources;
};
}
