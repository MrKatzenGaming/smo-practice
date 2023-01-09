#pragma once

#include "al/gfx/DrawSystemInfo.h"
#include "al/iuse/IUseAudioKeeper.h"
#include "al/iuse/IUseSceneCreator.h"
#include "al/nerve/NerveExecutor.h"
#include "al/scene/Scene.h"
#include <sead/prim/seadSafeString.h>


namespace al {
class Sequence : public al::NerveExecutor, public al::IUseAudioKeeper, public al::IUseSceneCreator {
public:
    Sequence(const char *seqName);

    sead::FixedSafeString<64> mName;
    al::Scene* uVar1;
    al::Scene* mCurScene;
    al::SceneCreator* mSceneCreator;
    al::AudioDirector* mAudioDirector;
    al::AudioKeeper* mAudioKeeper;
    al::DrawSystemInfo* mDrawSystemInfo;
    bool bVar1;
};
}
