#pragma once

#include "al/layout/IUseLayout.h"
#include "al/hio/HioNode.h"
#include "al/iuse/IUseNerve.h"
#include "al/iuse/IUseExecutor.h"
#include "al/iuse/IUseCamera.h"
#include "al/camera/CameraDirector.h"
#include "al/audio/AudioKeeper.h"
#include "al/effect/EffectKeeper.h"
#include "al/iuse/IUseAudioKeeper.h"
#include "al/iuse/IUseSceneObjHolder.h"
#include "al/iuse/IUseMessageSystem.h"
#include <sead/prim/seadSafeString.h>

namespace al {
class LayoutActionKeeper;
class LayoutKeeper;
class LayoutTextPaneAnimator;
class LayoutExecuteInfo;
class HitReactionKeeper;
class LayoutSceneInfo;
class LayoutPartsActorKeeper;

class IUseLayoutAction {
public:
    virtual al::LayoutActionKeeper* getLayoutActionKeeper() const = 0;
};

class LayoutActor : public al::IUseHioNode, public al::IUseNerve, public al::IUseLayout, public al::IUseLayoutAction, public al::IUseMessageSystem, public al::IUseCamera, public al::IUseAudioKeeper, public al::IUseEffectKeeper, public al::IUseSceneObjHolder {
public:
    sead::FixedSafeString<128> mName;
    al::NerveKeeper* mNerveKeeper;
    al::LayoutKeeper* mLayoutKeeper;
    al::LayoutActionKeeper* mLayoutActionKeeper;
    al::LayoutTextPaneAnimator* mTextPaneAnimator;
    al::EffectKeeper* mEffectKeeper;
    al::AudioKeeper* mAudioKeeper;
    al::LayoutExecuteInfo* mExecuteInfo;
    al::HitReactionKeeper* mHitReactionKeeper;
    al::LayoutSceneInfo* mSceneInfo;
    al::LayoutPartsActorKeeper* mPartsActorKeeper;
    bool mIsAlive;
};
}
