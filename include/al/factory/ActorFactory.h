#pragma once

#include "al/factory/Factory.h"

namespace al {
template <class T>
al::LiveActor* createActorFunction(const char *name);

class LiveActor;

typedef al::LiveActor* (*createActor)(const char* name);

class ActorFactory : public al::Factory<createActor> {
public:
    ActorFactory(const char *name) {
        this->mName = name;
        this->mTable = nullptr;
        this->mCount = 0;
    };
};
}
