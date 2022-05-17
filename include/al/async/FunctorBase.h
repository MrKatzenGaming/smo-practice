#pragma once

namespace al
{
class FunctorBase {
public:
    virtual void operator()(void) const {return;};
    virtual FunctorBase *clone(void) const {return {};};
    virtual ~FunctorBase() {return;};
};
} // namespace al
