#pragma once

namespace al {
class LiveActor;
class ActionAnimCtrl;
class NerveActionCtrl;
class ActionFlagCtrl;
class ActionEffectCtrl;
class ActionSeCtrl;
class ActionBgmCtrl;
class ActionPadAndCameraCtrl;
class ActionScreenEffectCtrl;

class ActorActionKeeper {
public:
    void startAction(const char*);

    al::LiveActor* mActor;
    const char* sVar1;
    bool mIsAction;
    al::ActionAnimCtrl* mAnimCtrl;
    al::NerveActionCtrl* mNerveCtrl;
    al::ActionFlagCtrl* mFlagCtrl;
    al::ActionEffectCtrl* mEffectCtrl;
    al::ActionSeCtrl* mSeCtrl;
    al::ActionBgmCtrl* mBgmCtrl;
    al::ActionPadAndCameraCtrl* mPadAndCameraCtrl;
    al::ActionScreenEffectCtrl* mScreenEffectCtrl;
};
}
