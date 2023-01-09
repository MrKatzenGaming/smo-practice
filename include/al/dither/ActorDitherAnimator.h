#pragma once

#include "al/dither/DitherAnimator.h"

namespace al {
class LiveActor;
class Resource;

class ActorDitherAnimator : public al::DitherAnimator {
public:
    static al::ActorDitherAnimator* tryCreate(al::LiveActor*, al::Resource const*, const char*);
};
}
