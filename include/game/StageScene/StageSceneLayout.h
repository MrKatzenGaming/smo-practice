#pragma once

#include "al/PlayerHolder/PlayerHolder.h"
#include "al/nerve/NerveStateBase.h"
#include "game/Layouts/CoinCounter.h"
#include "game/Layouts/ShineCounter.h"
#include <types.h>

class CounterLifeCtrl;
class ShineChipLayoutParts;
class PlayGuideCamera;
class PlayGuideBgm;
class MapMini;
class GamePadPlayStyleInfo;
namespace al {
    class SimpleLayoutAppearWaitEnd;
}
;
class StageSceneLayout : public al::NerveStateBase {
    public:
        CoinCounter* mCoinCounter;
        CounterLifeCtrl* mCounterLifeCtrl;
        ShineCounter* mShineCounter;
        CoinCounter* mCoinCollectCounter;
        ShineChipLayoutParts* mShineChipLayoutParts;
        PlayGuideCamera* mPlayGuideCamera;
        PlayGuideBgm* mPlayGuideBgm;
        MapMini* mMapMini;
        al::PlayerHolder* mPlayerHolder;
        bool bVar1;
        al::SimpleLayoutAppearWaitEnd* mPlayGuideMenu;
        GamePadPlayStyleInfo* mGamePadPlayStyleInfo;
        al::LayoutActor* mKidsMode;
};
