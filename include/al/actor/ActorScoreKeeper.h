#pragma once

#include "al/byaml/ByamlIter.h"

namespace al {
class ActorScoreInfo {
public:
    const char* mFactorName;
    const char* mCategoryName;
};

class ActorScoreKeeper {
public:
    void init(al::ByamlIter const&);

    al::ActorScoreInfo** mScores;
    int mScoreCount;
};
}
