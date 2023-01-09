#pragma once

#include "al/dither/DitherAnimator.h"

namespace al {
class LiveActor;
class Resource;

class FarDistanceDitherAnimator : public al::DitherAnimator {
public:
    static al::FarDistanceDitherAnimator* tryCreate(al::LiveActor*, al::Resource const*, const char*);
};
}
