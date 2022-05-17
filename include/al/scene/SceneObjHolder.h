#pragma once

#include "al/iuse/ISceneObj.h"

namespace al {
class SceneObjHolder {
public:
    SceneObjHolder(ISceneObj* (*createFunc)(int idx), int count);

    ISceneObj* create(int idx);
    ISceneObj* getObj(int idx) const;
    bool isExist(int idx) const;
    void setSceneObj(ISceneObj* obj, int idx);
    ISceneObj* tryGetObj(int idx) const;

    ISceneObj* (*createFunc)(int idx);
    ISceneObj** mSceneObjs;
    int mCount; // value = 0x4a / 74
};
}


// SceneObjHolder->mSceneObjs entries

/*
 * 0x0  - AmiiboNpcDirector
 * 0x1  - BgmAnimeSyncDirector
 * 0x2  - BirdPlayerGlideCtrl
 * 0x3  - CapManHeroDemoDirector
 * 0x4  - CapMessageDirector
 * 0x5  - CapMessageMoonNotifier
 * 0x6  - CheckpointFlagWatcher
 * 0x7  - CoinCollectHolder
 * 0x8  - CoinCollectWatcher
 * 0x9  - CollectBgmPlayer
 * 0xa  - al::DataStoreDirector
 * 0xb  - EchoEmitterHolder
 * 0xc  - ElectricWireCameraTicketHolder
 * 0xd  - EventDemoCtrl
 * 0xe  - UNUSED
 * 0xf  - al::FootPrintServer
 * 0x10 - al::FriendsProfileDownloader
 * 0x11 - FukankunZoomObjHolder
 * 0x12 - GameDataHolder
 * 0x13 - UNUSED
 * 0x14 - GiantWanderBoss
 * 0x15 - GrowPlantDirector
 * 0x16 - GuidePosInfoHolder
 * 0x17 - HintPhotoLayoutHolder
 * 0x18 - HosuiTrailKeeper
 * 0x19 - HosuiWaterBallHolder
 * 0x1a - HtmlViewerRequester
 * 0x1b - InformationWindowDirector
 * 0x1c - UNUSED
 * 0x1d - KidsModeLayoutAccessor
 * 0x1e - KoopaStopHackCtrl
 * 0x1f - KoopaShipDemoRequester
 * 0x20 - al::LayoutTextureRenderer
 * 0x21 - LifeUpItemGenerateWatcher
 * 0x22 - LoginLotteryDirector
 * 0x23 - MapLayout
 * 0x24 - MoviePlayer
 * 0x25 - UNUSED
 * 0x26 - NpcEventCtrlInfo
 * 0x27 - PaintObjHolder
 * 0x28 - UNUSED
 * 0x29 - PeachOnKoopaAnimRequester
 * 0x2a - PlayerStartInfoHolder
 * 0x2b - PlayerHackStartTexKeeper
 * 0x2c - QuestInfoHolder
 * 0x2d - ProjectRaceCheckPointHolder
 * 0x2e - RaceManRace
 * 0x2f - RaceWatcher
 * 0x30 - RadiConRaceWatcher
 * 0x31 - RandomItemSelector
 * 0x32 - al::RankingDirector
 * 0x33 - RankingNameHolder
 * 0x34 - ReactionObjectActionIndexHolder
 * 0x35 - RhyhtmInfoWatcher
 * 0x36 - RocketFlowerEquipWatcher
 * 0x37 - RouteGuideDirector
 * 0x38 - SceneEventNotifier
 * 0x39 - SessionMusicianManager
 * 0x3a - ShineChipWatcherHolder
 * 0x3b - SphinxQuizRouteKillExecutor
 * 0x3c - al::StageSyncCounter
 * 0x3d - UNUSED, but seems like it was meant to be al::registSupportFreezeSyncGroup (based on ClockMapParts::init + 0x6c)
 * 0x3e - TalkNpcParamHolder
 * 0x3f - TalkNpcSceneEventSwitcher
 * 0x40 - TestStageTimeDirector
 * 0x41 - TimeBalloonDirector
 * 0x42 - UNUSED
 * 0x43 - al::TrafficAreaDirector
 * 0x44 - TrafficRailWatcher
 * 0x45 - TRexScrollBreakMapPartsBreakJudge
 * 0x46 - TsukkunTraceHolder
 * 0x47 - WipeHolderRequester
 * 0x48 - YoshiFruitWatcher
 * 0x49 - HelpAmiiboDirector
 */
