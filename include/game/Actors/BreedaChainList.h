#pragma once

#include "al/LiveActor/LiveActor.h"
#include "game/Actors/BreedaChain.h"

class BreedaChainList : public al::LiveActor {
public:
    BreedaChain* getChain(int idx);

    BreedaChain** mChains;
    const char* sVar1;
    int mChainCount;
};
