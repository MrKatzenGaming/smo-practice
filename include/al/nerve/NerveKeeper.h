#pragma once

#include "al/nerve/Nerve.h"
#include "al/iuse/IUseNerve.h"

namespace al {
class NerveStateCtrl;
class NerveActionCtrl;

class NerveKeeper {
public:
    NerveKeeper(al::IUseNerve *, const al::Nerve *, int);

    void update();

    void tryChangeNerve();
    void setNerve(const al::Nerve *);
    const al::Nerve* getCurrentNerve() const;

    al::IUseNerve* mParent;
    const al::Nerve* mLastNerve;
    const al::Nerve* mNerve;
    int mStep;
    al::NerveStateCtrl* mStateCtrl;
    al::NerveActionCtrl* mActionCtrl;
};
};
