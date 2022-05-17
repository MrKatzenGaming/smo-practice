#pragma once

#include "al/nerve/Nerve.h"
#include "al/iuse/IUseNerve.h"

namespace al
{
    class NerveStateCtrl;

    class NerveKeeper
    {
    public:
        NerveKeeper(al::IUseNerve *, const al::Nerve *, int);

        void update();

        void tryChangeNerve();
        void setNerve(const al::Nerve *);
        const al::Nerve* getCurrentNerve() const;

        al::IUseNerve* mParent;
        const al::Nerve* _8;
        const al::Nerve* mNerve;
        int mStep;
        int _1C;
        al::NerveStateCtrl* mStateCtrl;
        unsigned long _28;
    };
};
