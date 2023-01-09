#pragma once

#include "al/layout/LayoutActor.h"

namespace al {
class SimpleLayoutAppearWaitEnd : public al::LayoutActor {
public:
    void appear() override;
    void end();
    bool isAppearOrWait() const;
    bool isWait() const;
    void startWait();

    int mPriority;
};
}
