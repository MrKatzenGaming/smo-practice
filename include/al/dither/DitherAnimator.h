#pragma once

#include "al/nerve/NerveExecutor.h"

namespace al {
class DitherAnimator : public al::NerveExecutor {
public:
    virtual void update() = 0;
    virtual void show();
    virtual bool isValidNearClip() const;
};
}
