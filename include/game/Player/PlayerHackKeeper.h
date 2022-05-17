#pragma once

#include "al/LiveActor/LiveActor.h"

class PlayerHackKeeper {
public:
    char padding[0x68];
    al::LiveActor* mCurrentHackActor;
};
