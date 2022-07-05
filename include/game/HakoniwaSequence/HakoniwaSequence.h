#pragma once

#include "types.h"

#include "al/scene/Scene.h"
#include "al/audio/AudioDirector.h"
#include "al/layout/LayoutKit.h"
#include "al/layout/LayoutInitInfo.h"
#include "al/sequence/Sequence.h"
#include "al/sequence/SequenceInitInfo.h"
#include "al/gamepad/util.h"

#include "game/StageScene/StageScene.h"
#include "game/WorldList/WorldResourceLoader.h"
#include "game/GameData/GameDataHolderAccessor.h"

#include "HakoniwaStateDeleteScene.h"
#include "HakoniwaStateDemoOpening.h"
#include "HakoniwaStateDemoEnding.h"
#include "HakoniwaStateDemoWorldWarp.h"
#include "HakoniwaStateSimpleDemo.h"
#include "HakoniwaStateBootLoadData.h"

namespace al {
    class WipeHolder;
    class ScreenCaptureExecutor;
    class BootLayout;
} // namespace al

class HakoniwaSequence : public al::Sequence {
    public:

        HakoniwaSequence(const char *);
        bool isDisposable(void);
        void updatePadSystem(void);
        void destroySceneHeap(bool);
        void init(al::SequenceInitInfo const &);
        void initSystem(void);
        void update(void);
        bool isEnableSave(void);
        void drawMain(void);
        al::Scene *getCurrentScene(void) const;

        al::Scene *mScene;
        GameDataHolder *mGameDataHolder;
        al::GamePadSystem *mGamepadSys;
        HakoniwaStateDemoOpening *mDemoOpening;
        HakoniwaStateDemoEnding *mDemoEnding;
        HakoniwaStateDemoWorldWarp *mDemoWorldWarp;
        HakoniwaStateSimpleDemo *mSimpleDemo;
        HakoniwaStateBootLoadData *mBootLoadData;
        HakoniwaStateDeleteScene *mDeleteScene;
        al::LayoutKit *mLytKit;

};
