#include "al/camera/CameraPoser.h"
#include "al/collision/KCPrism.h"
#include "al/collision/KCollisionServer.h"
#include "al/execute/ExecuteTableHolder.h"
#include "al/pose/ActorPoseKeeper.h"
#include "al/util.hpp"
#include "game/Actors/GrowPlantSeed.h"
#include "game/Actors/Fastener.h"
#include <sead/math/seadVector.h>
#include "game/Layouts/CommonVerticalList.h"
#include "types.h"
#include "al/effect/EffectSystem.h"
#include "al/effect/EffectUserInfo.h"
#include "al/effect/EffectInfo.h"
#include "game/SceneObjs/CapManHeroDemoDirector.h"
#include "game/GameData/GameDataFile.h"
#include "game/Player/PlayerConst.h"

#include <cstdint>
#include "smo/common.h"
#include "smo/server.h"
#include "smo/input.h"
#include "smo/tas.h"
#include "smo/ui.h"
#include "smo/util.h"
#include "smo/rtti.hpp"
#include <str.h>
#include <cxxabi.h>
#include <typeinfo>

const char* stageNames[] = {"CapWorldHomeStage", "WaterfallWorldHomeStage", "SandWorldHomeStage", "LakeWorldHomeStage", "ForestWorldHomeStage", "CloudWorldHomeStage", "ClashWorldHomeStage", "CityWorldHomeStage",
                            "SnowWorldHomeStage", "SeaWorldHomeStage", "LavaWorldHomeStage", "BossRaidWorldHomeStage", "SkyWorldHomeStage", "MoonWorldHomeStage", "PeachWorldHomeStage", "Special1WorldHomeStage", "Special2WorldHomeStage", "MoonWorldBasementStage", "MoonWorldKoopa1Stage", "MoonWorldKoopa2Stage", "AnimalChaseExStage", "BikeSteelExStage", "BikeSteelNoCapExStage", "BullRunExStage", "ByugoPuzzleExStage", "CapAppearExStage", "CapAppearLavaLiftExStage", "CapRotatePackunExStage", "CapWorldTowerStage", "CityPeopleRoadStage", "CityWorldFactoryStage", "CityWorldMainTowerStage", "CityWorldSandSlotStage", "CityWorldShop01Stage", "ClashWorldShopStage", "CloudExStage", "Cube2DExStage", "DemoBossRaidAttackStage", "DemoChangeWorldBossRaidAttackStage", "DemoChangeWorldFindKoopaShipStage", "DemoChangeWorldStage", "DemoCrashHomeFallStage", "DemoCrashHomeStage", "DemoEndingStage", "DemoHackFirstStage", "DemoHackKoopaStage", "DemoLavaWorldScenario1EndStage", "DemoMeetCapNpcSubStage", "DemoOpeningStage", "DemoStartWorldWaterfallStage", "DemoTakeOffKoopaForMoonStage", "DemoWorldMoveBackwardArriveStage", "DemoWorldMoveBackwardStage", "DemoWorldMoveForwardArriveStage", "DemoWorldMoveForwardFirstStage", "DemoWorldMoveForwardStage", "DemoWorldMoveMoonBackwardStage", "DemoWorldMoveMoonForwardFirstStage", "DemoWorldMoveMoonForwardStage", "DemoWorldWarpHoleStage", "DonsukeExStage", "DotHardExStage", "DotTowerExStage", "ElectricWireExStage", "FastenerExStage", "FogMountainExStage", "ForestWorldBonusStage", "ForestWorldBossStage", "ForestWorldCloudBonusExStage", "ForestWorldTowerStage", "ForestWorldWaterExStage", "ForestWorldWoodsCostumeStage", "ForestWorldWoodsStage", "ForestWorldWoodsTreasureStage", "ForkExStage", "FrogPoisonExStage", "FrogSearchExStage", "FukuwaraiKuriboStage", "FukuwaraiMarioStage", "GabuzouClockExStage", "Galaxy2DExStage", "GotogotonExStage", "HomeShipInsideStage", "IceWalkerExStage", "IceWaterBlockExStage", "IceWaterDashExStage", "ImomuPoisonExStage", "JangoExStage", "JizoSwitchExStage", "KaronWingTowerStage", "KillerRailCollisionExStage", "KillerRoadExStage", "KillerRoadNoCapExStage", "LakeWorldShopStage", "LavaWorldBubbleLaneExStage", "LavaWorldClockExStage", "LavaWorldCostumeStage", "LavaWorldExcavationExStage", "LavaWorldFenceLiftExStage", "LavaWorldShopStage", "LavaWorldTreasureStage", "LavaWorldUpDownExStage", "LavaWorldUpDownYoshiExStage", "Lift2DExStage", "MeganeLiftExStage", "MoonAthleticExStage", "MoonWorldCaptureParadeStage", "MoonWorldShopRoom", "MoonWorldSphinxRoom", "MoonWorldWeddingRoom2Stage", "MoonWorldWeddingRoomStage", "Note2D3DRoomExStage", "PackunPoisonExStage", "PackunPoisonNoCapExStage", "PeachWorldCastleStage", "PeachWorldCostumeStage", "PeachWorldPictureBossForestStage", "PeachWorldPictureBossKnuckleStage", "PeachWorldPictureBossMagmaStage", "PeachWorldPictureBossRaidStage", "PeachWorldPictureGiantWanderBossStage", "PeachWorldPictureMofumofuStage", "PeachWorldShopStage", "PoisonWaveExStage", "PoleGrabCeilExStage", "PoleKillerExStage", "PushBlockExStage", "RadioControlExStage", "RailCollisionExStage", "ReflectBombExStage", "RevengeBossKnuckleStage", "RevengeBossMagmaStage", "RevengeBossRaidStage", "RevengeForestBossStage", "RevengeGiantWanderBossStage", "RevengeMofumofuStage", "RocketFlowerExStage", "RollingExStage", "SandWorldCostumeStage", "SandWorldKillerExStage", "SandWorldMeganeExStage", "SandWorldPressExStage", "SandWorldPyramid000Stage", "SandWorldPyramid001Stage", "SandWorldRotateExStage", "SandWorldSecretStage", "SandWorldShopStage", "SandWorldSlotStage", "SandWorldSphinxExStage", "SandWorldUnderground000Stage", "SandWorldUnderground001Stage", "SandWorldVibrationStage", "SeaWorldCostumeStage", "SeaWorldSecretStage", "SeaWorldSneakingManStage", "SeaWorldUtsuboCaveStage", "SeaWorldVibrationStage", "SenobiTowerExStage", "SenobiTowerYoshiExStage", "ShootingCityExStage", "ShootingCityYoshiExStage", "ShootingElevatorExStage", "SkyWorldCloudBonusExStage", "SkyWorldCostumeStage", "SkyWorldShopStage", "SkyWorldTreasureStage", "SnowWorldCloudBonusExStage", "SnowWorldCostumeStage", "SnowWorldLobby000Stage", "SnowWorldLobby001Stage", "SnowWorldLobbyExStage", "SnowWorldRace000Stage", "SnowWorldRace001Stage", "SnowWorldRaceExStage", "SnowWorldRaceHardExStage", "SnowWorldRaceTutorialStage", "SnowWorldShopStage", "SnowWorldTownStage", "Special1WorldTowerBombTailStage", "Special1WorldTowerCapThrowerStage", "Special1WorldTowerFireBlowerStage", "Special1WorldTowerStackerStage", "Special2WorldCloudStage", "Special2WorldKoopaStage", "Special2WorldLavaStage", "StaffRollMoonRockDemo", "SwingSteelExStage", "Theater2DExStage", "TogezoRotateExStage", "TrampolineWallCatchExStage", "TrexBikeExStage", "TrexPoppunExStage", "TsukkunClimbExStage", "TsukkunRotateExStage", "WanwanClashExStage", "WaterTubeExStage", "WaterValleyExStage", "WindBlowExStage", "WorldStage", "YoshiCloudExStage"};
constexpr const char* stageNameDescriptions[17][15] = {
    {"first visit, spawn airborne", "plot complete", "post-game", "moon rock", "Luigi's Balloon World", "Koopa Freerunning", "trailer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"},
    {"first visit", "plot complete", "post-game", "moon rock", "Koopa Freerunning", "Luigi's Balloon World", "post-game, copy", "trailer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"},
    {"first visit", "night", "plot complete", "post-game", "moon rock", "Luigi's Balloon World", "Koopa Freerunning", "E3 demo", "trailer", "night, E3 demonstration", "crashes", "crashes", "crashes", "crashes", "crashes"},
    {"first visit", "plot complete", "post-game", "moon rock", "Koopa Freerunning", "Luigi's Balloon World", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"},
    {"first visit", "night", "plot complete", "post-game", "moon rock", "Luigi's Balloon World", "Koopa Freerunning", "first visit, copy", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"},
    {"first visit", "plot complete", "post-game", "moon rock", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"},
    {"first visit", "plot complete", "post-game", "moon rock", "Luigi's Balloon World", "Koopa Freerunning", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"},
    {"night", "day", "festival", "plot complete", "post-game", "Luigi's Balloon World", "festival, revisit", "moon rock", "Koopa Freerunning", "morning metro", "festival, 8-bit", "morning, missing wire", "day, trailer", "festival, trailer", "night, copy"},
    {"first visit", "plot complete", "post-game", "moon rock", "Luigi's Balloon World", "Koopa Freerunning", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"},
    {"first visit", "plot complete", "post-game", "moon rock", "Koopa Freerunning", "Luigi's Balloon World", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"},
    {"first visit", "evening", "plot complete", "Koopa Freerunning", "incomplete", "incomplete", "post-game", "moon rock", "Luigi's Balloon World", "bruncheon", "common layer", "common layer", "common layer", "common layer", "common layer"},
    {"first visit", "plot complete", "post-game", "moon rock", "crashes", "crashes", "crashes", "crashes", "crashes", "crashes", "crashes", "crashes", "crashes", "crashes", "crashes"},
    {"first visit", "plot complete", "post-game", "moon rock", "Luigi's Balloon World", "Koopa Freerunning", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layere"},
    {"first visit", "post-game", "moon rock", "Luigi's Balloon World", "Koopa Freerunning", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"},
    {"rushroom", "first visit", "post-game", "Koopa Freerunning", "Luigi's Balloon World", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"},
    {"first visit", "post-game", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"},
    {"first visit", "post-game", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer", "common layer"} };

const char* executeTableDrawNames[] = {"3D (culling)", "3D (depth shadow)", "3D (depth shadow player)", "3D (static depth shadow)", "3D (world AO)", "3D (ocean depth)", "3D (sky)", "3D (opaque Z prepass)", "3D (deferred terrain)", "3D (no reflection on the deferred)", "3D (deferred character)", "3D (deferred different space)", "3D (deferred player)", "3D (deferred middle view)", "3D (deferred translucent)", "3D (depth clear player)", "3D (forward distant view)", "3D (forward player)", "3D (forward)", "3D (indirect)", "3D (forward after indirect)", "3D (distant view after indirect)", "3D (indirect after fog)", "3D (distant view after fog)", "3D (after fog)", "3D (chroma key Z prepass)", "3D (chroma key player)", "3D (chroma key character)", "2D back (main screen)", "2D base (main screen)", "2D effect (main screen)", "2D over (main screen)", "2D (demo screen)", "post effect mask", "actor drawing (original render target)", "actor drawing (project specific)", "model drawing buffer update", "3D (world map deferred)", "3D (world map forward)", "2D (world map drawing)", "2D (moon get drawing)", "2D (snapshot)", "2D (for shooting)", "2D (miss)"};


bool KassuEditSpeed = false;
float KassuEditSpeedValue = 14.0f;
float KassuEditJumpSpeedValue = 24.0f;

#define printf(FORMAT, ...) p.printf(FORMAT, ##__VA_ARGS__)


#define NUM_STAGES 200
#define WALL_ACTIONS 4
#define OTHER_PAGES 16
#define HELD_THRESHOLD 20

#define CURSOR(LINE) charCursor = curLine == LINE ? ">" : " "
#define TITLE(NAME) printf(NAME "%s\n", inputEnabled ? "" : " [Menu disabled]")
#define TITLE_FMT(NAME, FMT...) printf(NAME "%s\n", FMT, inputEnabled ? "" : " [Menu disabled]")

#define CHANGE_PAGE(NAME, PAGE, LINE) CURSOR(LINE);\
                                      printf("%s" NAME "\n", charCursor);\
                                      if (inputEnabled && !movingPage && curLine == LINE && !nextFrameNoRightInput && triggerRight) {movingPage = true; curPage = PAGE; cursorHistory[curDepth++] = curLine; curLine = 0;}

#define BACK_PAGE(PAGE, LINE) CURSOR(LINE);\
                              printf("%sBack\n", charCursor);\
                              if (inputEnabled && !movingPage && curLine == LINE && ((!nextFrameNoRightInput && triggerRight) || (!nextFrameNoLeftInput && triggerLeft))) {movingPage = true; curPage = PAGE; curLine = cursorHistory[--curDepth];}

// Sets max amount of lines for a page
#define MAX_LINE(LINE) if (curLine >= LINE) curLine = 0;\
                       else if (curLine < 0) curLine = LINE - 1

#define TOGGLES(BOOL, LINE) CURSOR(LINE);\
                            if (inputEnabled && !movingPage && !nextFrameNoLeftInput && !nextFrameNoRightInput && curLine == LINE && (triggerLeft || triggerRight)) BOOL = !BOOL;


#define TOGGLE(NAME, BOOL, LINE) TOGGLES(BOOL, LINE);\
                                 printf("%s" NAME ": %s\n", charCursor, BOOL ? "Enabled" : "Disabled")

#define TRIGGER(NAME, LINE, ACTION) CURSOR(LINE);\
                                    printf("%s" NAME "\n", charCursor);\
                                    if (inputEnabled && !movingPage && curLine == LINE && !nextFrameNoRightInput && triggerRight) {ACTION;}

#define TRIGGER_FMT(NAME, LINE, ACTION, FMT...) CURSOR(LINE);\
                                             printf("%s" NAME "\n", charCursor, FMT);\
                                             if (inputEnabled && !movingPage && curLine == LINE && !nextFrameNoRightInput && triggerRight) {ACTION;}

#define INDEX(INCDIR, DECDIR, VAR, MIN, MAX, LINE) CURSOR(LINE);                                                                     \
                                                   if (inputEnabled && !movingPage && curLine == LINE) {                             \
                                                       if ((held##INCDIR && heldDirFrames > HELD_THRESHOLD) || trigger##INCDIR) VAR++; \
                                                       if ((held##DECDIR && heldDirFrames > HELD_THRESHOLD) || trigger##DECDIR) VAR--; \
                                                   }                                                                                 \
                                                   if (VAR < MIN) VAR = MAX;                                                         \
                                                   if (VAR > MAX) VAR = MIN

#define INDEXRL(VAR, MIN, MAX, LINE) INDEX(Right, Left, VAR, MIN, MAX, LINE)
#define INDEXUD(VAR, MIN, MAX, LINE) INDEX(Up, Down, VAR, MIN, MAX, LINE)
#define INDEXDU(VAR, MIN, MAX, LINE) INDEX(Down, Up, VAR, MIN, MAX, LINE)

// set SVAR to SVAL whenever VAR is changed
#define INDEXS(INCDIR, DECDIR, VAR, SVAR, SVAL, MIN, MAX, LINE) CURSOR(LINE);                                                                 \
                                                                if (inputEnabled && !movingPage && curLine == LINE) {                         \
                                                                    if ((held##INCDIR && heldDirFrames > HELD_THRESHOLD) || trigger##INCDIR) {  \
                                                                        VAR++;                                                                \
                                                                        SVAR = SVAL;                                                          \
                                                                    }                                                                         \
                                                                    if ((held##DECDIR && heldDirFrames > HELD_THRESHOLD) || trigger##DECDIR) {  \
                                                                        VAR--;                                                                \
                                                                        SVAR = SVAL;                                                          \
                                                                    }                                                                         \
                                                                }                                                                             \
                                                                if (VAR < MIN-1) VAR = MAX;                                                   \
                                                                if (VAR > MAX) VAR = MIN

#define INDEXSRL(VAR, SVAR, SVAL, MIN, MAX, LINE) INDEXS(Right, Left, VAR, SVAR, SVAL, MIN, MAX, LINE)
#define INDEXZ(INCDIR, DECDIR, VAR, ZVAR, MIN, MAX, LINE) INDEXS(INCDIR, DECDIR, VAR, ZVAR, 0, MIN, MAX, LINE)
#define INDEXZRL(VAR, ZVAR, MIN, MAX, LINE) INDEXZ(Right, Left, VAR, ZVAR, MIN, MAX, LINE)

#define DEMANGLE(MANGLED) abi::__cxa_demangle(MANGLED, demangleBuffer, &demangledSize, &cxaStatus)

#define ACTOR_NAME(NAME, ACTOR) RTTI_WRAP(actorWrap, ACTOR);                          \
                                const char* mangledName = actorWrap->GetRtti()->name; \
                                char* NAME = DEMANGLE(mangledName)

#define PRINT_NERVE(ACTOR) al::NerveKeeper* nerveKeeper = ACTOR->getNerveKeeper();            \
                     if (nerveKeeper) {                                                 \
                         int nerveStep = nerveKeeper->mStep;                            \
                         al::Nerve* nerve = (al::Nerve*)nerveKeeper->getCurrentNerve(); \
                         if (nerve) {                                                   \
                             RTTI_WRAP(nerveWrap, nerve);                               \
                             char mangledNerveName[64] = "_Z";                          \
                             strcat(mangledNerveName, nerveWrap->GetRtti()->name);      \
                             char* nerveName = DEMANGLE(mangledNerveName);              \
                             printf(" Nerve Name: %s\n", nerveName);                    \
                             printf(" Nerve Step: %d\n", nerveStep);                    \
                         } else {                                                       \
                             printf(" Nerve Name: N/A\n");                              \
                         }                                                              \
                     } else {                                                           \
                         printf(" Nerve Name: N/A\n");                                  \
                         printf(" Nerve Step: N/A\n");                                  \
                     }


void smo::PracticeUI::savePosition(PlayerActorHakoniwa& player, s8 idx) {
    savestates[idx].mTrans = *al::getTrans(&player);
    savestates[idx].mQuat = *al::getQuat(&player);
    savestates[idx].mSaved = true;
}

void smo::PracticeUI::loadPositionPlayer(PlayerActorHakoniwa& player, s8 idx) {
    al::LiveActor* move = &player;
    al::LiveActor* hack = player.mHackKeeper->mCurrentHackActor;

    if (hack) {
        al::offCollide(hack);
        al::setTrans(hack, savestates[idx].mTrans);
        al::setVelocityZero(hack);
        al::onCollide(hack);
    } else {
        al::offCollide(move);
        player.startDemoPuppetable();
        player.mStainControl->clearStain();
        al::setTrans(move, savestates[idx].mTrans);
        al::updatePoseQuat(move, savestates[idx].mQuat);
        al::setVelocityZero(move);
        player.endDemoPuppetable();
        al::onCollide(move);
    }
}

void smo::PracticeUI::loadPosition(al::LiveActor* actor, s8 idx) {
    al::offCollide(actor);
    al::setTrans(actor, savestates[idx].mTrans);
    al::updatePoseQuat(actor, savestates[idx].mQuat);
    al::setVelocityZero(actor);
    al::onCollide(actor);
}

void smo::PracticeUI::toggleNoclip(PlayerActorHakoniwa& player) {
    al::LiveActor* move = &player;
    al::LiveActor* hack = player.mHackKeeper->mCurrentHackActor;

    if (hack) move = hack;

    if (!noclipping)
    {
        al::offCollide(move);
        noclipping = true;
    }
    else
    {
        al::onCollide(move);
        noclipping = false;
    }
}

void smo::PracticeUI::kill() {
    renderer.curArea = nullptr;
    renderer.curAreaGroup = nullptr;
    renderer.nearestEdgePoint = sead::Vector3f::zero;

    currentActor = nullptr;
    actorIndex = 0;
    areaGroupIndex = 0;
    areaIndex = 0;
}
void smo::PracticeUI::update(StageScene& stageScene) {
    this->stageScene = &stageScene;
    isInGame = true;

    al::PlayerHolder* playerHolder = al::getScenePlayerHolder(&stageScene);
    bool isExistPlayer = playerHolder->getPlayerNum() != 0;
    al::LiveActor* playerActor = playerHolder->tryGetPlayer(0);

    PlayerActorHakoniwa* player;
    if (isExistPlayer) {
        player = static_cast<PlayerActorHakoniwa*>(playerActor);
    }

    bool holdL = al::isPadHoldL(CONTROLLER_AUTO);
    bool triggerLeft = al::isPadTriggerLeft(CONTROLLER_AUTO);
    bool triggerRight = al::isPadTriggerRight(CONTROLLER_AUTO);

    smo::TasHolder::instance().update();

    if (holdL && triggerRight) {
        inputEnabled = !inputEnabled;
        nextFrameNoRightInput = true;
        return;
    }
    else if (al::isPadTriggerPressLeftStick(CONTROLLER_AUTO)) {
        showMenu = !showMenu;
        nextFrameNoLeftInput = true;
    }


    if (hideShineCounter)
        al::hidePane(stageScene.mStageSceneLayout->mShineCounter, "TxtShine");
    else
        al::showPane(stageScene.mStageSceneLayout->mShineCounter, "TxtShine");


    if (!isExistPlayer) return;

    if (!showMenu || (!inputEnabled && !holdL))
    {
        if (options.teleportEnabled && options.teleportKeysEnabled)
        {
            if (triggerLeft)
                savePosition(*player, savestateIndex);

            if (triggerRight && savestates[savestateIndex].mSaved)
                loadPositionPlayer(*player, savestateIndex);
        }
        
        if (options.noclipEnabled)
        {
            if (al::isPadTriggerUp(CONTROLLER_AUTO))
                toggleNoclip(*player);
        }
    }
    if(KassuEditSpeed) {
        if(isExistPlayer) {
            player->mPlayerConst->mNormalMaxSpeed = KassuEditSpeedValue;
            player->mPlayerConst->mJumpBaseSpeedMax = KassuEditJumpSpeedValue;
        }
    } else if (isExistPlayer) { player->mPlayerConst->mNormalMaxSpeed = 14.0f; player->mPlayerConst->mJumpBaseSpeedMax = 24.0f;}

    if (reloadStageForPos != -1)
    {
        reloadStageForPos++;
        if (reloadStageForPos == 11)
        {
            player->startDemoPuppetable();
            al::setTrans(player, reloadStageTrans);
            al::updatePoseQuat(player, reloadStageQuat);
            player->endDemoPuppetable();
            reloadStageForPos = -1;
        }
    }

    if (options.moonJump) {
        al::LiveActor* move = player;
        al::LiveActor* hack = player->mHackKeeper->mCurrentHackActor;

        if (hack) move = hack;

        sead::Vector3f* moveVel = al::getVelocity(move);
        if (al::isPadHoldA(CONTROLLER_AUTO) || al::isPadHoldB(CONTROLLER_AUTO)) {
            al::setVelocity(move, { moveVel->x, moonJumpVel, moveVel->z });
        }
    }
}

void smo::PracticeUI::menu(sead::TextWriter& p) {
    if (!stageScene) return;
    
    if (showMenu) {
        const char* charCursor = " ";

        al::PlayerHolder* playerHolder = al::getScenePlayerHolder(stageScene);
        bool isExistPlayer = playerHolder->getPlayerNum() != 0;
        al::LiveActor* playerActor = playerHolder->tryGetPlayer(0);

        PlayerActorHakoniwa* player;
        HackCap* cappy;
        if (isExistPlayer) {
            player = static_cast<PlayerActorHakoniwa*>(playerActor);
            cappy = player->mHackCap;
        }

        bool triggerUp = al::isPadTriggerUp(CONTROLLER_AUTO);
        bool triggerDown = al::isPadTriggerDown(CONTROLLER_AUTO);
        bool triggerLeft = al::isPadTriggerLeft(CONTROLLER_AUTO);
        bool triggerRight = al::isPadTriggerRight(CONTROLLER_AUTO);
        bool heldUp = al::isPadHoldUp(CONTROLLER_AUTO);
        bool heldDown = al::isPadHoldDown(CONTROLLER_AUTO);
        bool heldLeft = al::isPadHoldLeft(CONTROLLER_AUTO);
        bool heldRight = al::isPadHoldRight(CONTROLLER_AUTO);

        if (inputEnabled) {
            if (heldDown || heldUp || heldLeft || heldRight) heldDirFrames++;
            else heldDirFrames = 0;

            if ((heldDown && heldDirFrames > HELD_THRESHOLD) || triggerDown) curLine++;
            if ((heldUp && heldDirFrames > HELD_THRESHOLD) || triggerUp) curLine--;
        }

        switch (curPage) {
            case Menu: {
                MAX_LINE(11); // fix
                TITLE("Welcome to the Practice Mod!");
                CHANGE_PAGE("About", About, 0)
                CHANGE_PAGE("Options", Options, 1);
                CHANGE_PAGE("Stages", Stage, 2);
                CHANGE_PAGE("Miscellaneous", Misc, 3);
                CHANGE_PAGE("Info", Info, 4);
                CHANGE_PAGE("TAS", Tas, 5);
                CHANGE_PAGE("Modes", Modes, 6);
                CHANGE_PAGE("Debug", Debug, 7);
                CHANGE_PAGE("Testing", Test, 8);
                CHANGE_PAGE("Loading Zones", TestLoadingZones, 9);
                CHANGE_PAGE("Kassu", Kassu, 10);
                break;
            }


            case Kassu: {
                TITLE("Kassu");
                MAX_LINE(10);
                BACK_PAGE(Menu, 0);

                CHANGE_PAGE("Teleport", OptionsKassuTeleport, 1);
                CHANGE_PAGE("Moon Jump", OptionsKassuMoonJump, 2);

                TOGGLE("Infinite Cap Bounces", options.repeatCapBounce, 3);
                TOGGLE("Cap Bounce After Wall Jump", options.wallJumpCapBounce, 4);
                TRIGGER("Kill Mario", 5, { if (isExistPlayer) player->mDamageKeeper->dead(); });
                TRIGGER("Damage Mario", 6, {
                    if (isExistPlayer) {
                        bool tmpDamage = options.noDamageLife;
                        options.noDamageLife = false;
                        player->mDamageKeeper->damageForce(1);
                        options.noDamageLife = tmpDamage;
                    }
                    });
                TRIGGER("Life Up Heart", 7, stageScene->mDataHolder->mPlayingFile->getPlayerHitPointData()->getMaxUpItem());
                CHANGE_PAGE("Coins", KassuCoins, 8);
                CHANGE_PAGE("Speed" , KassuSpeed, 9);
                break;
            }
            case KassuSpeed:{
                TITLE("Kassu: Speed");
                MAX_LINE(11);
                BACK_PAGE(Kassu, 0);
                CURSOR(1);

                if (KassuEditSpeed){
                    if (inputEnabled && !movingPage && curLine == 1) {
                        if (!nextFrameNoLeftInput && triggerLeft) {KassuEditSpeedValue -= 1.0f; KassuEditJumpSpeedValue -= 1.0f;}
                        else if (!nextFrameNoRightInput && triggerRight) {KassuEditSpeedValue += 1.0f; KassuEditJumpSpeedValue += 1.0f;}
                    }
                }
                printf("%sActual current Speed: %.1f\n", charCursor,  player->mPlayerConst->getNormalMaxSpeed());
                printf("%sActual current Jump Speed: %.1f\n", charCursor,  player->mPlayerConst->getJumpBaseSpeedMax());
                TOGGLE("Edit Speed", KassuEditSpeed, 2);
                TRIGGER("Set to 50", 3, KassuEditSpeedValue = 50.0f; KassuEditJumpSpeedValue = 50.0f;);
                TRIGGER("Set to 100", 4, KassuEditSpeedValue = 100.0f; KassuEditJumpSpeedValue = 100.0f;);
                TRIGGER("Set to 150", 5, KassuEditSpeedValue = 150.0f; KassuEditJumpSpeedValue = 150.0f;);
                TRIGGER("Set to 200", 6, KassuEditSpeedValue = 200.0f; KassuEditJumpSpeedValue = 200.0f;);
                TRIGGER("Set to 250", 7, KassuEditSpeedValue = 250.0f; KassuEditJumpSpeedValue = 250.0f;); 
                TRIGGER("Set to 300", 8, KassuEditSpeedValue = 300.0f; KassuEditJumpSpeedValue = 300.0f;);
                TRIGGER("Set to 350", 9, KassuEditSpeedValue = 350.0f; KassuEditJumpSpeedValue = 350.0f;);
                TRIGGER("Set to 400", 10, KassuEditSpeedValue = 400.0f; KassuEditJumpSpeedValue = 400.0f;);
                printf(" Edited current Speed: %.1f\n", KassuEditSpeedValue);
                printf(" Edited current Jump Speed: %.1f\n", KassuEditJumpSpeedValue);
                break;
            }
            case OptionsKassuMoonJump: {
                TITLE("Kassu: Moon Jump");
                MAX_LINE(10);
                BACK_PAGE(Kassu, 0);
                TOGGLE("Moon Jump", options.moonJump, 1);
                
                CURSOR(2);
                if (inputEnabled && !movingPage && curLine == 2) {
                    if (!nextFrameNoLeftInput && triggerLeft) moonJumpVel -= 1.0f;
                    else if (!nextFrameNoRightInput && triggerRight) moonJumpVel += 1.0f;
                }
                printf("%sVelocity: %.1f\n", charCursor, moonJumpVel);
                TRIGGER("Reset", 3, moonJumpVel = 0.0f);
                TRIGGER("Set to 50", 4, moonJumpVel = 50.0f);
                TRIGGER("Set to 100", 5, moonJumpVel = 100.0f);
                TRIGGER("Set to 200", 6, moonJumpVel = 200.0f);
                TRIGGER("Set to 300", 7, moonJumpVel = 300.0f);
                TRIGGER("Set to 400", 8, moonJumpVel = 400.0f);
                TRIGGER("Set to 500", 9, moonJumpVel = 500.0f);           
                break;
            }
            case KassuCoins: {
                TITLE("Kassu: Coins");
                MAX_LINE(9);
                BACK_PAGE(Kassu, 0);
                TRIGGER("Add 1 coin", 1, stageScene->mDataHolder->mPlayingFile->addCoin(1););
                TRIGGER("Add 10 coins", 2, stageScene->mDataHolder->mPlayingFile->addCoin(10););
                TRIGGER("Add 100 coins", 3, stageScene->mDataHolder->mPlayingFile->addCoin(100););
                TRIGGER("Add 1000 coins", 4, stageScene->mDataHolder->mPlayingFile->addCoin(1000););
                TRIGGER("Remove 1 coin", 5, stageScene->mDataHolder->mPlayingFile->addCoin(-1););
                TRIGGER("Remove 10 coins", 6, stageScene->mDataHolder->mPlayingFile->addCoin(-10););
                TRIGGER("Remove 100 coins", 7, stageScene->mDataHolder->mPlayingFile->addCoin(-100););
                TRIGGER("Remove 1000 coins", 8, stageScene->mDataHolder->mPlayingFile->addCoin(-1000););

                break;
            }
            case About: {
                TITLE("About");
                MAX_LINE(1);
                BACK_PAGE(Menu, 0);
                printf(" Made by Fruityloops#8500 and contributors\n");
                printf(" Big thanks to CraftyBoss, bryce_____ and Mars2030!\n");
                printf("\n");
                printf(" Practice Mod Version: %s\n", PRACTICE_VERSTR);
                break;
            }
            case Options: {
                TITLE("Options");
                MAX_LINE(10);
                BACK_PAGE(Menu, 0);

                CHANGE_PAGE("Movement", OptionsMvmt, 1);
                CHANGE_PAGE("Saving", OptionsSave, 2);
                CHANGE_PAGE("Renderer", OptionsRenderer, 3);
                TOGGLE("Disable Losing Health", options.noDamageLife, 4);
                TOGGLE("Always Enable Warps", options.alwaysWarp, 5);
                TOGGLE("Cloud Kingdom Bowser Skip", options.skipBowser, 6);
                TOGGLE("Disable L Press", options.disableTriggerL, 7);
                TOGGLE("Disable Moon Requirement", options.disableShineNumUnlock, 8);
                TOGGLE("Enable Moe-Eye Vision", options.showOddSpace, 9);
                
                break;
            }
            case OptionsMvmt: {
                    TITLE("Options: Movement");
                    MAX_LINE(8);
                    BACK_PAGE(Options, 0);

                    CHANGE_PAGE("Teleport", OptionsTeleport, 1);
                    TOGGLE("Noclip", options.noclipEnabled, 2);
                    CHANGE_PAGE("Moon Jump", OptionsMoon, 3);
                    TOGGLE("X/Y Motion Rolls", options.buttonMotionRoll, 4);
                    TOGGLE("Infinite Cap Bounces", options.repeatCapBounce, 5);
                    TOGGLE("Infinite Rainbow Spins", options.repeatRainbowSpin, 6);
                    TOGGLE("Cap Bounce After Wall Jump", options.wallJumpCapBounce, 7);

                break;
            }
            case OptionsTeleport: {
                TITLE("Options: Teleport");
                MAX_LINE(7);
                BACK_PAGE(OptionsMvmt, 0);

                TOGGLE("Teleport", options.teleportEnabled, 1);
                TOGGLE("Teleport Hotkeys", options.teleportKeysEnabled, 2);

                CURSOR(3);
                if (inputEnabled && !movingPage && curLine == 3) {
                    if (!nextFrameNoLeftInput && triggerLeft) savestateIndex--;
                    else if (!nextFrameNoRightInput && triggerRight) savestateIndex++;
                }
                if (savestateIndex < 0) savestateIndex = NUMSAVES - 1;
                if (savestateIndex >= NUMSAVES) savestateIndex = 0;

                printf("%sTeleport Index: %d/%d%s\n", charCursor, savestateIndex + 1, NUMSAVES, savestates[savestateIndex].mSaved ? "" : " (unsaved)");
                TRIGGER("Save Position", 4, { if (isExistPlayer) savePosition(*player, savestateIndex); });
                TRIGGER("Load Position", 5, { if (isExistPlayer) loadPositionPlayer(*player, savestateIndex); });

                TRIGGER("tmp load", 6, {
                    if (isExistPlayer) {
                        al::offCollide(player);
                        al::setQuat(player, {0.8225067, 0.0, -0.5686121, 0.0});
                        al::setTrans(player, {2573.247, 3022.991, 3529.164});
                        al::setVelocity(player, {6483.206, -35.0, 17163.543});
                        al::onCollide(player);
                        player->getNerveKeeper()->mStep = 275254;
                    }
                });

                sead::Vector3f curPos = savestates[savestateIndex].mTrans;
                sead::Quatf curQuat = savestates[savestateIndex].mQuat;
                printf(" Position: (X: %.3f Y: %.3f Z: %.3f)\n", curPos.x, curPos.y, curPos.z);
                printf(" Rotation: (W: %.3f X: %.3f Y: %.3f Z: %.3f)\n", curQuat.w, curQuat.x, curQuat.y, curQuat.z);


                break;
            }
            case OptionsKassuTeleport: {
                TITLE("Kassu: Teleport");
                MAX_LINE(7);
                BACK_PAGE(Kassu, 0);

                TOGGLE("Teleport", options.teleportEnabled, 1);
                TOGGLE("Teleport Hotkeys", options.teleportKeysEnabled, 2);

                CURSOR(3);
                if (inputEnabled && !movingPage && curLine == 3) {
                    if (!nextFrameNoLeftInput && triggerLeft) savestateIndex--;
                    else if (!nextFrameNoRightInput && triggerRight) savestateIndex++;
                }
                if (savestateIndex < 0) savestateIndex = NUMSAVES - 1;
                if (savestateIndex >= NUMSAVES) savestateIndex = 0;

                printf("%sTeleport Index: %d/%d%s\n", charCursor, savestateIndex + 1, NUMSAVES, savestates[savestateIndex].mSaved ? "" : " (unsaved)");
                TRIGGER("Save Position", 4, { if (isExistPlayer) savePosition(*player, savestateIndex); });
                TRIGGER("Load Position", 5, { if (isExistPlayer) loadPositionPlayer(*player, savestateIndex); });

                TRIGGER("tmp load", 6, {
                    if (isExistPlayer) {
                        al::offCollide(player);
                        al::setQuat(player, {0.8225067, 0.0, -0.5686121, 0.0});
                        al::setTrans(player, {2573.247, 3022.991, 3529.164});
                        al::setVelocity(player, {6483.206, -35.0, 17163.543});
                        al::onCollide(player);
                        player->getNerveKeeper()->mStep = 275254;
                    }
                });

                sead::Vector3f curPos = savestates[savestateIndex].mTrans;
                sead::Quatf curQuat = savestates[savestateIndex].mQuat;
                printf(" Position: (X: %.3f Y: %.3f Z: %.3f)\n", curPos.x, curPos.y, curPos.z);
                printf(" Rotation: (W: %.3f X: %.3f Y: %.3f Z: %.3f)\n", curQuat.w, curQuat.x, curQuat.y, curQuat.z);


                break;
            }
            case OptionsTeleportSettings: {


                break;
            }
            case OptionsMoon: {
                TITLE("Options: Moon Jump");
                MAX_LINE(3);
                BACK_PAGE(OptionsMvmt, 0);

                TOGGLE("Moon Jump", options.moonJump, 1);
                CURSOR(2);
                if (inputEnabled && !movingPage && curLine == 2) {
                    if (!nextFrameNoLeftInput && triggerLeft) moonJumpVel -= 1.0f;
                    else if (!nextFrameNoRightInput && triggerRight) moonJumpVel += 1.0f;
                }
                printf("%sVelocity: %.1f\n", charCursor, moonJumpVel);
                

                break;
            }
            case OptionsSave: {
                TITLE("Options: Saving");
                MAX_LINE(6);
                BACK_PAGE(Options, 0);

                TOGGLE("Disable Saving Moons", options.shineRefresh, 1);
                TOGGLE("Reactivate Moons", options.gotShineRefresh, 2);
                TOGGLE("Disable Autosaving", options.disableAutoSave, 3);
                TOGGLE("Allow Loading Current File", options.loadCurrentFile, 4);
                TOGGLE("Disable Load File Confirmation", options.loadFileConfirm, 5);

                break;
            }
            case OptionsRenderer: {
                TITLE("Options: Renderer");
                MAX_LINE(11);
                BACK_PAGE(Options, 0);

                TOGGLE("Show Mario's position", renderer.showPlayer, 1);
                TOGGLE("Show origin", renderer.showAxis, 2);
                TOGGLE("Show current AreaObj", renderer.showArea, 3);
                TOGGLE("Show closest area point", renderer.showAreaPoint, 4);
                TOGGLE("Show current AreaObjGroup", renderer.showAreaGroup, 5);
                TOGGLE("Show floor HitInfo", renderer.showHitInfoFloor, 6);
                TOGGLE("Show wall HitInfo", renderer.showHitInfoWall, 7);
                TOGGLE("Show ceiling HitInfo", renderer.showHitInfoCeil, 8);
                TOGGLE("Show HitInfo array", renderer.showHitInfoArray, 9);
                TOGGLE("Show CRC position", renderer.showCRC, 10);

                break;
            }
            case Stage: {
                static s32 currentStage = 0;
                static s8 currentScenario = 0;

                TITLE("Stages");
                MAX_LINE(4);
                BACK_PAGE(Menu, 0);

                INDEXRL(currentStage, 0, NUM_STAGES - 1, 1);
                printf("%sStage: %s\n", charCursor, stageNames[currentStage]);

                INDEXRL(currentScenario, 0, 15, 2);
                if (currentScenario != 0) {
                    if (currentStage < 17) {
                        const char* description = stageNameDescriptions[currentStage][currentScenario - 1];
                        printf("%sScenario: %d (%s)\n", charCursor, currentScenario, description);
                    }
                }
                else printf("%sScenario: Don't change\n", charCursor);

                TRIGGER("Go", 3, {
                    ChangeStageInfo info = ChangeStageInfo(stageScene->mDataHolder, "start", stageNames[currentStage], false, currentScenario ?: -1, {0});
                    stageScene->mDataHolder->changeNextStage(&info, 0);
                    curLine = 0;
                });

                break;
            }
            case Misc: {
                TITLE("Miscellaneous");
                MAX_LINE(11);
                BACK_PAGE(Menu, 0);

                TRIGGER("Kill Mario", 1, { if (isExistPlayer) player->mDamageKeeper->dead(); });
                TRIGGER("Damage Mario", 2, {
                    if (isExistPlayer) {
                        bool tmpDamage = options.noDamageLife;
                        options.noDamageLife = false;
                        player->mDamageKeeper->damageForce(1);
                        options.noDamageLife = tmpDamage;
                    }
                });
                TRIGGER("Life Up Heart", 3, stageScene->mDataHolder->mPlayingFile->getPlayerHitPointData()->getMaxUpItem());
                TRIGGER("Heal Mario", 4, stageScene->mDataHolder->mPlayingFile->getPlayerHitPointData()->recover());
                TRIGGER("Remove Cappy", 5, GameDataFunction::disableCapByPlacement(cappy));
                TRIGGER("Invincibility Star", 6, { if (isExistPlayer) player->mDamageKeeper->activatePreventDamage(); });
                TRIGGER("Add 1000 coins", 7,  stageScene->mDataHolder->mPlayingFile->addCoin(1000););
                
                static u8 gravity = 0;

                CURSOR(8);

                const char* gravityString = nullptr;

                if (gravity == 0) gravityString = "Down";
                else if (gravity == 1) gravityString = "Up";
                else if (gravity == 2) gravityString = "North";
                else if (gravity == 3) gravityString = "South";
                else if (gravity == 4) gravityString = "East";
                else if (gravity == 5) gravityString = "West";
                
                bool gravityChangedFrame = false;

                printf("%sGravity: %s\n", charCursor, gravityString);
                if (curLine == 8 && inputEnabled && !movingPage && !nextFrameNoLeftInput && triggerLeft) {gravity--; gravityChangedFrame = true;}
                else if (curLine == 8 && inputEnabled && !movingPage && !nextFrameNoRightInput && triggerRight) {gravity++; gravityChangedFrame = true;}
                if (gravity == 255) gravity = 5;
                else if (gravity > 5) gravity = 0;

                if (gravityChangedFrame && isExistPlayer)
                {
                    if (gravity == 0) {
                        al::setGravity(player, {0, -1, 0});
                    }
                    else {
                        if (gravity == 1) al::setGravity(player, {0, 1, 0});
                        else if (gravity == 2) al::setGravity(player, {1, 0, 0});
                        else if (gravity == 3) al::setGravity(player, {-1, 0, 0});
                        else if (gravity == 4) al::setGravity(player, {0, 0, 1});
                        else if (gravity == 5) al::setGravity(player, {0, 0, -1});
                    }
                }

                TRIGGER("Reload Sceen", 9, {
                    reloadStageForPos = 0;
                    if (isExistPlayer) {
                        reloadStageTrans = *al::getTrans(player);
                        reloadStageQuat = *al::getQuat(player);
                    }
                    ChangeStageInfo info = ChangeStageInfo(stageScene->mDataHolder, "start", stageScene->mDataHolder->getCurrentStageName(), false, CURRENT_SCENARIO, {0});
                    stageScene->mDataHolder->changeNextStage(&info, 0);
                });
                TRIGGER("Previous scene", 10, {
                    stageScene->mDataHolder->returnPrevStage();
                    });

                break;
            }
            case Info: {
                TITLE("Info");
                BACK_PAGE(Menu, 0);
                CHANGE_PAGE("Moon Info", InfoMoon, 1);
                CHANGE_PAGE("Capture Info", InfoHack, 2);
                CHANGE_PAGE("Cappy Info", InfoCappy, 3);

                if (!isExistPlayer) {
                    MAX_LINE(4);
                    printf(" No player actor!\n");
                    break;
                }

                MAX_LINE(5);

                TOGGLE("Quaternion Rotation", quatRot, 4);

                sead::Vector3f* playerTrans = al::getTrans(player);
                sead::Vector3f* playerVel = al::getVelocity(player);
                sead::Quatf* playerQuat = al::getQuat(player);
                sead::Vector3f playerEulerAngles = smo::QuatToEuler(playerQuat);
                sead::Vector3f playerRot = sead::Vector3f(DEG(playerEulerAngles.x),DEG(playerEulerAngles.y),DEG(playerEulerAngles.z));
                sead::Vector3f* playerRecoveryPoint = player->mRecoverPoint->getSafetyPoint();
                const char* anim = player->mAnimator->mCurrentAnim;
                float hSpeed = al::calcSpeedH(player), vSpeed = al::calcSpeedV(player), speed = al::calcSpeed(player);

                static sead::Vector3f prevPlayerVel = { 0.0f, 0.0f, 0.0f };
                sead::Vector3f playerVelDelta = *playerVel - prevPlayerVel;

                printf(" Player Pos: (X: %.3f Y: %.3f Z: %.3f)\n", playerTrans->x, playerTrans->y, playerTrans->z);
                printf(" Player Vel: (X: %.3f Y: %.3f Z: %.3f)\n", playerVel->x, playerVel->y, playerVel->z);
                printf(" Player Vel Delta: (X: %.3f Y: %.3f Z: %.3f)\n", playerVelDelta.x, playerVelDelta.y, playerVelDelta.z);
                prevPlayerVel = *playerVel;
                printf(" Player Speed: (H: %.3f V: %.3f S: %.3f)\n", hSpeed, vSpeed, speed);
                if (quatRot)
                    printf(" Player Rot: (W: %.3f X: %.6f Y: %.3f Z: %.6f)\n", playerQuat->w, playerQuat->x, playerQuat->y, playerQuat->z);
                else
                    printf(" Player Rot: (X: %.3f Y: %.3f Z: %.3f)\n", playerRot.x, playerRot.y, playerRot.z);
                printf(" Bubble Pos: (X: %.3f Y: %.3f Z: %.3f)\n", playerRecoveryPoint->x, playerRecoveryPoint->y, playerRecoveryPoint->z);
                printf(" Current Animation: %s (%.0f/%.0f)\n", anim, player->mAnimator->getAnimFrame() - 1.0f, player->mAnimator->getAnimFrameMax());
                PRINT_NERVE(player);

                break;
            }
            case InfoMoon: {
                TITLE("Moon Info");
                MAX_LINE(2);
                BACK_PAGE(Info, 0);

                TOGGLE("Hide Original Moon Counter", hideShineCounter, 1);

                s32 currShine = GameDataFunction::getCurrentShineNum(*stageScene->mDataHolder);
                s32 totalShine = GameDataFunction::getTotalShineNum(*stageScene->mDataHolder, -1);
                s32 unlockShine = GameDataFunction::findUnlockShineNumByWorldId(0, *stageScene->mDataHolder, GameDataFunction::getCurrentWorldId(*stageScene->mDataHolder));
                printf(" Current Moons: %d\n", currShine);
                printf(" Total Moons: %d\n", totalShine);
                printf(" Required Moons: %d", unlockShine);
                break;
            }
            case InfoHack: {
                TITLE("Capture Info");
                BACK_PAGE(Info, 0);

                if (!isExistPlayer) {
                    MAX_LINE(1);
                    printf(" No player actor!\n");
                    break;
                }

                TOGGLE("Lock Current Capture", options.lockHack, 1);

                if (!options.lockHack)
                    currentHack = player->mHackKeeper->mCurrentHackActor;

                TRIGGER("Load position", 2, loadPosition(currentHack, savestateIndex));

                if (currentHack) {
                    ACTOR_NAME(currentHackName, currentHack);
                    printf(" Capture Name: %s\n", currentHackName);

                    sead::Vector3f* hackTrans = al::getTrans(currentHack);
                    sead::Vector3f* hackVel = al::getVelocity(currentHack);
                    float hSpeed = al::calcSpeedH(currentHack), vSpeed = al::calcSpeedV(currentHack), speed = al::calcSpeed(currentHack);

                    printf(" Capture Pos: (X: %.3f Y: %.3f Z: %.3f)\n", hackTrans->x, hackTrans->y, hackTrans->z);
                    printf(" Capture Vel: (X: %.3f Y: %.3f Z: %.3f)\n", hackVel->x, hackVel->y, hackVel->z);
                    printf(" Capture Speed: (H: %.3f V: %.3f S: %.3f)\n", hSpeed, vSpeed, speed);
                    printf(" Current Action: %s\n", al::getActionName(currentHack));

                    if (al::isEqualString(currentHackName, "Killer")) {
                        MAX_LINE(3);
                        static float prevAliveCount = 0.0f;
                        Killer* currentHackKiller = static_cast<Killer*>(currentHack);
                        printf(" Alive Counter: %f\n", currentHackKiller->mAliveCount);
                        printf(" Alive Counter Delta: %f\n", prevAliveCount - currentHackKiller->mAliveCount);
                        prevAliveCount = currentHackKiller->mAliveCount;
                        printf(" Capture Cooldown: %d\n", currentHackKiller->mHackCooldown);
                        printf(" Facing: (X: %.3f Y: %.3f Z: %.3f)\n", currentHackKiller->mFacing.x, currentHackKiller->mFacing.y, currentHackKiller->mFacing.z);
                        printf(" Turning Speed: %f\n", currentHackKiller->mTurnVel);
                        printf(" %d %d %d\n", currentHackKiller->bVar1, currentHackKiller->bVar2, currentHackKiller->mIsMagnum);
                        printf(" %d %d %d\n", currentHackKiller->bVar4, currentHackKiller->bVar5, currentHackKiller->bVar6);
                    }
                    else if (al::isEqualString(currentHackName, "JugemFishing")) {
                        MAX_LINE(3);
                        JugemFishing* currentHackJugem = static_cast<JugemFishing*>(currentHack);
                        printf(" %.3f %.3f\n", currentHackJugem->mFloatOffsetCtrl->fVar1, currentHackJugem->mFloatOffsetCtrl->fVar2);

                    }
                    else if (al::isEqualString(currentHackName, "KuriboHack")) {
                        MAX_LINE(3);
                        KuriboHack* currentHackKuribo = static_cast<KuriboHack*>(currentHack);
                        printf(" IsGold: %s\n", currentHackKuribo->mIsGold ? "True" : "False");
                        printf(" %d %d %d %d\n", currentHackKuribo->iVar1, currentHackKuribo->iVar2, currentHackKuribo->iVar3, currentHackKuribo->iVar4);
                        printf(" %d %d %d %d\n", currentHackKuribo->iVar5, currentHackKuribo->iVar6, currentHackKuribo->iVar7, currentHackKuribo->iVar8);
                        printf(" %d %.3f %.3f\n", currentHackKuribo->iVar9, currentHackKuribo->fVar1, currentHackKuribo->fVar2);
                        printf(" %d %d %d %d\n", currentHackKuribo->bVar1, currentHackKuribo->bVar2, currentHackKuribo->bVar3, currentHackKuribo->bVar4);
                        printf(" (X: %.3f Y: %.3f Z: %.3f)\n", currentHackKuribo->vVar1.x, currentHackKuribo->vVar1.y, currentHackKuribo->vVar1.z);
                        printf(" (X: %.3f Y: %.3f Z: %.3f)\n", currentHackKuribo->vVar2.x, currentHackKuribo->vVar2.y, currentHackKuribo->vVar2.z);
                        printf(" JointName: %s\n", currentHackKuribo->mJointName);
                    }
                    else if (al::isEqualString(currentHackName, "Fastener")) {
                        MAX_LINE(4);
                        Fastener* currentHackFastener = static_cast<Fastener*>(currentHack);
                        uintptr_t start = (uintptr_t)currentHackFastener;

                        sead::PtrArray<FastenerRailKeeper> arr = currentHackFastener->mRailKeeperArray;
                        static int railKeeperIdx = 0;
                        INDEXRL(railKeeperIdx, 0, arr.size()-1, 3);
                        printf("%sRailKeeper: %d/%d (%d)\n", charCursor, railKeeperIdx+1, arr.size(), arr.capacity());
                        FastenerRailKeeper* keeper = arr[railKeeperIdx];
                        printf(" offset: 0x%x\n", (uintptr_t)keeper - start);
                        ACTOR_NAME(keeperName, keeper);
                        printf(" name: %s\n", keeperName);
                    }
                }
                else {
                    MAX_LINE(3);
                    printf(" Capture Name: Not captured\n");
                }
                break;
            }
            case InfoCappy: {
                TITLE("Cappy Info");
                BACK_PAGE(Info, 0);

                if (!isExistPlayer) {
                    MAX_LINE(1);
                    printf(" No player actor!\n");
                    break;
                }
                MAX_LINE(2);

                TOGGLE("Quaternion Rotation", quatRot, 1);

                sead::Vector3f* cappyPosition = al::getTrans(cappy);
                sead::Vector3f* cappyVel = al::getVelocity(cappy);
                sead::Quatf* cappyQuat = al::getQuat(cappy);
                sead::Vector3f cappyEulerAngles = smo::QuatToEuler(cappyQuat);
                sead::Vector3f cappyRot = sead::Vector3f(DEG(cappyEulerAngles.x),DEG(cappyEulerAngles.y),DEG(cappyEulerAngles.z));

                printf(" Cappy Pos: (X: %.3f Y: %.3f Z: %.3f)\n", cappyPosition->x, cappyPosition->y, cappyPosition->z);
                printf(" Cappy Vel: (X: %.3f Y: %.3f Z: %.3f)\n", cappyVel->x, cappyVel->y, cappyVel->z);
                if (quatRot) {
                    printf(" Cappy Rot: (W: %.3f X: %.3f Y: %.3f Z: %.3f)\n", cappyQuat->w, cappyQuat->x, cappyQuat->y, cappyQuat->z);
                } else {
                    printf(" Cappy Rot: (X: %.3f Y: %.3f Z: %.3f)\n", cappyRot.x, cappyRot.y, cappyRot.z);
                }

                break;
            }
            case Tas: {
                TITLE("TAS");
                MAX_LINE(4);
                BACK_PAGE(Menu, 0);

                TRIGGER("Connect to server", 1, {
                    smo::Server::instance().connect("127.0.0.1", 7902);
                });
                TOGGLE("Old Motion Mod", smo::TasHolder::instance().oldMotion, 2);

                smo::TasHolder& h = smo::TasHolder::instance();

                if (h.isRunning)  {TRIGGER("Stop Script", 3, h.stop());}
                else { TRIGGER("Start Script", 3, {
                    if (h.frames) h.start();
                });
                }

                printf("\n");

                if (h.scriptName)
                    printf(" Script: %s (%lu frames)\n", h.scriptName, h.frameCount);

                if (h.isRunning)
                    printf(" TAS Running %lu/%lu\n", h.curFrame, h.frameCount);
                sead::Vector2f& left = *fgetLeftStick(CONTROLLER_AUTO);
                sead::Vector2f& right = *fgetRightStick(CONTROLLER_AUTO);
                printf(" Left Stick: (X: %.5f Y: %.5f)\n", left.x, left.y);
                printf(" Right Stick: (X: %.5f Y: %.5f)\n", right.x, right.y);
                printf(" Buttons:\n");
                // -1 = CONTROLLER_AUTO
                printf(" %s %s %s %s %s %s %s %s\n", fisPadHoldA(-1) ? "A" : " ", fisPadHoldB(-1) ? "B" : " ", fisPadHoldX(-1) ? "X" : " ", fisPadHoldY(-1) ? "Y" : " ", fisPadHoldL(-1) ? "L" : " ", fisPadHoldR(-1) ? "R" : " ", fisPadHoldZL(-1) ? "ZL" : "  ", fisPadHoldZR(-1) ? "ZR" : "  ");
                printf(" %s %s %s %s %s %s %s %s\n", fisPadHoldPlus(-1) ? "+" : " ", fisPadHoldMinus(-1) ? "-" : " ", fisPadHoldPressLeftStick(-1) ? "LS" : "  ", fisPadHoldPressRightStick(-1) ? "RS" : "  ", fisPadHoldUp(-1) ? "DUP" : "   ", fisPadHoldRight(-1) ? "DRIGHT" : "      ", fisPadHoldDown(-1) ? "DDOWN" : "     ", fisPadHoldLeft(-1) ? "DLEFT" : "     ");
                
                break;
            }
            case Modes: {
                TITLE("Modes");
                MAX_LINE(7);
                BACK_PAGE(Menu, 0);

                TOGGLE("isModeDiverOrJungleGymRom", modes.isModeDiverOrJungleGymRom, 1);
                TOGGLE("isModeDiverRom", modes.isModeDiverRom, 2);
                TOGGLE("isModeJungleGymRom", modes.isModeJungleGymRom, 3);
                TOGGLE("isModeE3LiveRom", modes.isModeE3LiveRom, 4);
                TOGGLE("isModeE3MovieRom", modes.isModeE3MovieRom, 5);
                TOGGLE("isModeEpdMovieRom", modes.isModeEpdMovieRom, 6);

                break;
            }
            case Debug: {
                TITLE("Debug");
                MAX_LINE(1);
                BACK_PAGE(Menu, 0);

                printf(" Current Scenario: %d\n", GameDataFunction::getWorldScenarioNo(*stageScene->mDataHolder, GameDataFunction::getCurrentWorldId(*stageScene->mDataHolder)));
                printf(" Current World ID: %d\n", GameDataFunction::getCurrentWorldId(*stageScene->mDataHolder));
                printf(" Current Stage Name: %s\n", GameDataFunction::getCurrentStageName(*stageScene->mDataHolder));
                printf(" Language: %s\n", stageScene->mDataHolder->getLanguage());
                break;
            }
            case Test: {
                TITLE("Testing");
                MAX_LINE(7);
                BACK_PAGE(Menu, 0);

                CHANGE_PAGE("Wall Actions", TestWallAction, 1);
                CHANGE_PAGE("Cap Action History", TestCapActionHistory, 2);
                CHANGE_PAGE("LiveActorKit", TestLiveActorKit, 3);
                CHANGE_PAGE("GameDataHolder", TestGameDataHolder, 4);
                CHANGE_PAGE("Other", TestOther, 5);
                CHANGE_PAGE("Talkatoo", TestTalkatoo, 6);
                // printf(" NfpDirector: %p\n", stageScene->mNfpDirector);
                // printf(" ActorInitInfo: %p\n", stageScene->mActorInitInfo);
                // printf(" Group: %s\n", stageScene->mActorInitInfo->mGroup1->mGroupName);
                // printf(" StageScene: %x\n", sizeof(*stageScene));

                break;
            }
            case TestWallAction: {
                TITLE("Wall Actions");
                BACK_PAGE(Test, 0);

                if (!isExistPlayer) {
                    MAX_LINE(1);
                    printf(" No player actor!\n");
                    break;
                }

                MAX_LINE(2);

                CURSOR(1);
                if (inputEnabled && !movingPage && curLine == 1) {
                    if (!nextFrameNoLeftInput && triggerLeft)
                        wallAction--;
                    if (!nextFrameNoRightInput && triggerRight)
                        wallAction++;
                }

                if (wallAction < 0) wallAction = WALL_ACTIONS - 1;
                if (wallAction >= WALL_ACTIONS) wallAction = 0;

                switch (wallAction) {
                case 0: {
                    printf("%sPlayerWallActionHistory\n", charCursor);

                    PlayerWallActionHistory* wallActionHistory = player->mWallActionHistory;
                    printf(" Has Jumped: %s\n", wallActionHistory->mHasJumped ? "True" : "False");
                    printf(" Has Left Wall: %s\n", wallActionHistory->mHasLeft ? "True" : "False");
                    printf(" Wall Jump Pos (X: %.3f Y: %.3f Z: %.3f)\n", wallActionHistory->mWallJumpPos.x, wallActionHistory->mWallJumpPos.y, wallActionHistory->mWallJumpPos.z);
                    printf(" Wall Jump Normal (X: %.3f Y: %.3f Z: %.3f)\n", wallActionHistory->mWallJumpNormal.x, wallActionHistory->mWallJumpNormal.y, wallActionHistory->mWallJumpNormal.z);
                    printf(" Wall Leave Pos: (X: %.3f Y: %.3f Z: %.3f)\n", wallActionHistory->mWallLeavePos.x, wallActionHistory->mWallLeavePos.y, wallActionHistory->mWallLeavePos.z);
                    printf(" Wall Leave Normal: (X: %.3f Y: %.3f Z: %.3f)\n", wallActionHistory->mWallLeaveNormal.x, wallActionHistory->mWallLeaveNormal.y, wallActionHistory->mWallLeaveNormal.z);

                    break;
                }
                case 1: {
                    printf("%sPlayerJudgeWallKeep\n", charCursor);

                    bool bVar1 = player->mJudgeWallKeep->bVar1;
                    printf(" Judge: %s\n", bVar1 ? "True" : "False");

                    float groundHeight = player->mColliderHakoniwa->mGroundHeight;
                    // float lowlimit = player->mConst->getWallHeightLowLimit();
                    printf(" Above Ground: %s\n", player->mColliderHakoniwa->mIsAboveGround ? "True" : "False");
                    printf(" Ground Height: %.3f\n", groundHeight);

                    break;
                }
                case 2: {
                    printf("%sPlayerJudgeWallCatch\n", charCursor);

                    PlayerJudgeWallCatch* judge = player->mJudgeWallCatch;
                    bool bVar = judge->bVar1;
                    printf(" Judge: %s\n", bVar ? "True" : "False");

                    sead::Vector3f vVar = judge->vVar1;
                    printf(" vVar1: (X: %.3f Y: %.3f Z: %.3f)\n", vVar.x, vVar.y, vVar.z);
                    vVar = judge->vVar2;
                    printf(" vVar2: (X: %.3f Y: %.3f Z: %.3f)\n", vVar.x, vVar.y, vVar.z);
                    vVar = judge->vVar3;
                    printf(" vVar3: (X: %.3f Y: %.3f Z: %.3f)\n", vVar.x, vVar.y, vVar.z);

                    bVar = judge->mPlayerTrigger->mActionTrigger & 1 << 30;
                    printf(" Trigger: %s\n", bVar ? "True" : "False");

                    int iVar = judge->mCounterForceRun->iVar1;
                    printf(" CounterForceRun: %d\n", iVar);

                    float fVar1 = judge->mPlayerConst->getWallKeepDegree();
                    float fVar2 = judge->mPlayerConst->getWallCatchDegree();
                    printf(" Wall{Keep, Catch}Degree: %.3f, %.3f\n", fVar1, fVar2);
                    fVar1 = judge->mPlayerConst->getWallCatchHeightEdgeTop();
                    fVar2 = judge->mPlayerConst->getWallCatchHeightBottom();
                    printf(" WallCatchHeight{EdgeTop, Bottom}: %.3f, %.3f\n", fVar1, fVar2);
                    fVar1 = judge->mPlayerConst->getCollisionRadius();
                    fVar2 = judge->mPlayerConst->getCollisionRadiusStand();
                    printf(" Collision{, Radius}: %.3f, %.3f\n", fVar1, fVar2);

                    break;
                }
                case 3: {
                    printf("%sPlayerStateWallAir\n", charCursor);

                    break;
                }
                default: {
                    wallAction = 0;
                    break;
                }
                }

                static_assert(WALL_ACTIONS == 4, "wrong number of wall actions");

                break;
            }
            case TestCapActionHistory: {
                TITLE("Cap Action History");
                MAX_LINE(1);
                BACK_PAGE(Test, 0);

                if (!isExistPlayer) {
                    printf(" No player actor!\n");
                    break;
                }

                PlayerCapActionHistory* capActionHistory = player->mCapActionHistory;
                PlayerCounterAfterCapCatch* counterCapCatch = capActionHistory->mCounterCapCatch;
                printf(" Limit Height: %d\n", capActionHistory->mLimitHeight);
                printf(" Pos (X: %.3f Y: %.3f Z: %.3f)\n", capActionHistory->mCapThrowPos.x, capActionHistory->mCapThrowPos.y, capActionHistory->mCapThrowPos.z);
                printf(" Cap Bounce: %d\n", capActionHistory->mCapJump);
                printf(" Rainbow Spin: %d\n", capActionHistory->mRainbowSpin);
                printf(" Cap Catch: %d\n", counterCapCatch->mCapCatch);
                // printf(" Is Cap Catch: %d\n", counterCapCatch->isCapCatch());

                break;
            }
            case TestLiveActorKit: {
                TITLE("LiveActorKit");
                MAX_LINE(6);
                BACK_PAGE(Test, 0);

                CHANGE_PAGE("ObjectList", TestObjectList, 1);
                CHANGE_PAGE("AreaList", TestAreaList, 2);
                CHANGE_PAGE("ExecuteDirector", TestExecute, 3);
                CHANGE_PAGE("NatureDirector", TestNatureDirector, 4);
                CHANGE_PAGE("CollisionDirector", TestCollisionDirector, 5)

                break;
            }
            case TestObjectList: {
                TITLE("ObjectList");
                MAX_LINE(4);
                BACK_PAGE(TestLiveActorKit, 0);

                al::LiveActorKit* liveActorKit = stageScene->mLiveActorKit;
                al::LiveActorGroup* actorGroup = liveActorKit->mAllActors;
                sead::PtrArray<al::LiveActor> allActors = actorGroup->mActors;
                // al::ActorInitInfo* actorInitInfo = stageScene->mActorInitInfo;
                // al::PlacementId* placementId;

                INDEXRL(actorIndex, 0, allActors.capacity() - 1, 1);
                printf("%sActor Index: %d/%d\n", charCursor, actorIndex + 1, allActors.capacity());

                currentActor = allActors[actorIndex];

                TRIGGER("Load position", 2, loadPosition(currentActor, savestateIndex));
                TOGGLE("Show HitSensors", renderer.showHitSensors, 3);

                ACTOR_NAME(currentActorName, currentActor);
                printf(" Actor Name: %s\n", currentActorName);

                if (currentActor->mModelKeeper) {
                    if (currentActor->mModelKeeper->mName) {
                        printf(" Model Name: %s\n", currentActor->mModelKeeper->mName);
                    }
                } else {
                    printf(" Model Name: N/A\n");
                }

                if (currentActor->mPoseKeeper) {
                    sead::Vector3f actorPos = currentActor->mPoseKeeper->mTrans;
                    printf(" Position: (X: %.3f Y: %.3f Z: %.3f)\n", actorPos.x, actorPos.y, actorPos.z);
                } else {
                    printf(" Position: N/A\n");
                }

                PRINT_NERVE(currentActor);
                
                printf("\n");

                printf(" Group Name: %s\n", actorGroup->mName);
                printf(" Alive Actors: %d/%d\n", actorGroup->calcAliveActorNum(), allActors.capacity());
                printf(" Max Actors: %d\n", allActors.size());

                break;
            }
            case TestAreaList: {
                TITLE("AreaList");
                BACK_PAGE(TestLiveActorKit, 0);

                al::LiveActorKit* liveActorKit = stageScene->mLiveActorKit;
                al::AreaObjDirector* areaObjDirector = liveActorKit->mAreaObjDirector;
                int groupCount = areaObjDirector->mAreaGroupCount;

                INDEXSRL(areaGroupIndex, areaIndex, 0, 0, groupCount - 1, 1);
                printf("%sGroup Index: %d/%d\n", charCursor, areaGroupIndex + 1, groupCount);

                renderer.curAreaGroup = areaObjDirector->mAreaGroups[areaGroupIndex];

                if (!renderer.curAreaGroup) {
                    MAX_LINE(2);
                    printf(" invalid group pointer");
                    break;
                }
                MAX_LINE(3);
                int areaCount = renderer.curAreaGroup->mAreaCount;

                CURSOR(2);
                if (areaCount == 0) {
                    printf("%sArea Index: N/A\n", charCursor);
                    printf(" Group: %s (0)\n", renderer.curAreaGroup->mGroupName);
                    break;
                }
                printf("%sArea Index: %d/%d\n", charCursor, areaIndex + 1, areaCount);
                if (inputEnabled && !movingPage && curLine == 2) {
                    if ((heldLeft && heldDirFrames > HELD_THRESHOLD) || triggerLeft) areaIndex--;
                    if ((heldRight && heldDirFrames > HELD_THRESHOLD) || triggerRight) areaIndex++;
                }
                if (areaIndex < 0) areaIndex = areaCount - 1;
                if (areaIndex >= areaCount) areaIndex = 0;

                printf(" Group: %s (%d)\n", renderer.curAreaGroup->mGroupName, renderer.curAreaGroup->mBufferSize);

                renderer.curArea = renderer.curAreaGroup->mAreas[areaIndex];
                al::AreaShape* areaShape = renderer.curArea->mAreaShape;
                sead::Vector3f areaTrans;
                areaShape->calcTrans(&areaTrans);
                sead::Vector3f areaScale = areaShape->mScale;
                
                const char* shapeType;
                al::tryGetAreaObjStringArg(&shapeType, renderer.curArea, "ModelName");

                printf(" Area Shape: %s\n", shapeType);
                printf(" Area Pos: (X: %.3f Y: %.3f Z: %.3f)\n", areaTrans.x, areaTrans.y, areaTrans.z);
                printf(" Area Scale: (X: %.3f Y: %.3f Z: %.3f)\n", areaScale.x, areaScale.y, areaScale.z);
                // printf(" Obj ID: %s\n", renderer.curArea->mPlacementInfo->mPlacementIter)

                if (!isExistPlayer) break;

                sead::Vector3f* playerTrans = al::getTrans(player);
                bool isInArea = renderer.curArea->isInVolume(*playerTrans);
                float distToEdge = sead::norm2(*playerTrans - renderer.nearestEdgePoint);

                printf("\n");
                printf(" Is in Area: %s\n", isInArea ? "True" : "False");
                printf(" Distance to Area: %.3f\n", isInArea ? 0.0 : distToEdge);
                printf(" Edge: (X: %.3f Y: %.3f Z: %.3f)\n", renderer.nearestEdgePoint.x, renderer.nearestEdgePoint.y, renderer.nearestEdgePoint.z);

                break;
            }
            case TestExecute: {
                TITLE("ExecuteDirector");
                MAX_LINE(6);
                BACK_PAGE(TestLiveActorKit, 0);

                CHANGE_PAGE("ExecuteTableHolderDraw", TestExecuteDraw, 1);

                al::ExecuteDirector* director = stageScene->mLiveActorKit->mExecuteDirector;
                sead::PtrArray<al::ExecuteTableHolderDraw> arrTable = director->mTableDraw;
                int arrSize = arrTable.size();

                INDEXRL(executeTableDrawIdx, 0, arrSize - 1, 2);
                printf("%sTableDraw Index: %d/%d\n", charCursor, executeTableDrawIdx + 1, arrSize);

                al::ExecuteTableHolderDraw* tableDraw = arrTable[executeTableDrawIdx];
                printf(" Name: %s\n", tableDraw->mName);
                sead::PtrArray<al::ExecutorListActorModelDrawBase> listActorModel = tableDraw->mListActorModel;
                arrSize = listActorModel.capacity();

                INDEXRL(executeListIdx, 0, arrSize - 1, 3);
                printf("%sExecutorList Index: %d/%d (%d)\n", charCursor, executeListIdx + 1, arrSize, listActorModel.size());

                al::ExecutorListActorModelDrawBase* executorList = listActorModel[executeListIdx];
                if (!executorList) {
                    // renderer.actorTrans = sead::Vector3f::zero;
                    break;
                }
                sead::PtrArray<al::ExecutorActorDraw> executorActors = executorList->mActors;
                arrSize = listActorModel.capacity();


                INDEXRL(executeItemIdx, 0, arrSize - 1, 4);
                printf("%sExecutorActor Index: %d/%d (%d)\n", charCursor, executeItemIdx + 1, arrSize, executorActors.size());

                al::ExecutorActorExecuteBase* executorActor = executorActors[executeItemIdx];
                if (!executorActor) {
                    // renderer.actorTrans = sead::Vector3f::zero;
                    break;
                }
                printf(" ExecuteActor Name: %s\n", executorActor->mName);
                sead::PtrArray<al::LiveActor> actors = executorActor->mActors;
                arrSize = actors.capacity();

                INDEXRL(itemIdx, 0, arrSize - 1, 5);
                al::LiveActor* actor = actors[itemIdx];
                printf( "Actor: %p\n", actor);
                // renderer.actorTrans = *al::getTrans(actor);

                // printf(" Actor Pos: (X: %.3f Y: %.3f Z: %.3f)\n", renderer.actorTrans.x, renderer.actorTrans.y, renderer.actorTrans.z);

                break;
            }
            case TestExecuteDraw: {
                TITLE("ExecuteTableHolderDraw");
                MAX_LINE(14);
                BACK_PAGE(TestExecute, 0);

                static bool isJapanese = true;
                static int drawTablePage = 0;
                sead::PtrArray<al::ExecuteTableHolderDraw> drawTables = stageScene->mLiveActorKit->mExecuteDirector->mTableDraw;

                TOGGLES(isJapanese, 1);
                printf("%sLanguage: %s\n", charCursor, isJapanese ? "Japanese" : "English");

                INDEXRL(drawTablePage, 0, 3, 2);
                printf("%sShowing %d-%d out of 44\n", charCursor, drawTablePage*11+1, (drawTablePage+1)*11);

                for (int i = 0; i < 11; ++i) {
                    int idx = drawTablePage*11 + i;
                    al::ExecuteTableHolderDraw* drawTable = drawTables[idx];
                    TOGGLES(drawTable->debug_Enabled, 3+i);
                    const char* name = isJapanese ? drawTable->mName : executeTableDrawNames[idx];
                    printf("%s%s%s\n", charCursor, drawTable->debug_Enabled ? "On  " : "Off ", name);
                }

                break;
            }
            case TestNatureDirector: {
                TITLE("NatureDirector");
                MAX_LINE(1);
                BACK_PAGE(TestLiveActorKit, 0);

                al::NatureDirector* director = stageScene->mLiveActorKit->mNatureDirector;
                // void* gap = director->gap;
                al::FluidSurfaceHolder* surfaceHolder = director->mSurfaceHolder;

                sead::Vector3f& playerTrans = *al::getTrans(player);

                printf(" In Water: %s\n", surfaceHolder->calcIsInFluid(playerTrans, "Water") ? "True" : "False");

                break;
            }
            case TestCollisionDirector: {
                TITLE("CollisionDirector");
                MAX_LINE(3);
                BACK_PAGE(TestLiveActorKit, 0);

                PlayerCollider* collider = player->mColliderHakoniwa->mCollider;
                al::Triangle floorTri = collider->mHitFloor->mTri;
                al::CollisionParts* collisionParts = floorTri.mCollisionParts;

                al::KCollisionServer* collisionServer = collisionParts->mKCollisionServer;
                sead::PtrArray<al::KCPrismHeader> prismHeaders = collisionServer->mPrismHeaders;
                void* kcl = collisionServer->gap1;

                static int prismHeaderIdx = 0;
                INDEXRL(prismHeaderIdx, 0, prismHeaders.capacity() - 1, 1);
                printf("%sModel: %d/%d\n", charCursor, prismHeaderIdx+1, prismHeaders.capacity());
                al::KCPrismHeader* prismHeader = prismHeaders[prismHeaderIdx];

                unsigned int triCount = collisionServer->getTriangleNum(prismHeader);
                static unsigned int triIdx = 0;
                INDEXRL(triIdx, 0, triCount - 1, 2);
                printf("%sTriangle: %d/%d\n", charCursor, triIdx+1, triCount);
                al::KCPrismData* prismData = (al::KCPrismData*)((long)&prismHeader->mPositionsOffset + prismHeader->mTrianglesOffset + triIdx * 0x14);

                
                fillTri(&renderer.kclTri, *collisionParts, prismData, prismHeader);
                al::Triangle tri = renderer.kclTri;

                printf(" A: (X: %.3f Y: %.3f Z: %.3f)\n", tri.mVerts[0].x, tri.mVerts[0].y, tri.mVerts[0].z);
                printf(" B: (X: %.3f Y: %.3f Z: %.3f)\n", tri.mVerts[1].x, tri.mVerts[1].y, tri.mVerts[1].z);
                printf(" C: (X: %.3f Y: %.3f Z: %.3f)\n", tri.mVerts[2].x, tri.mVerts[2].y, tri.mVerts[2].z);


//                 for (int triIdx = 0; triIdx < triCount; triIdx++);
// 
//                 ACTOR_NAME(actorName, hostActor);
// 
//                 printf(" Host Actor: %s\n", actorName);
//                 printf(" length: %f\n", prismData->mLength);
//                 printf(" position: %u\n", prismData->mPosIndex);
//                 printf(" face normal: %u\n", prismData->mFaceNormalIndex);
//                 printf(" edge normals: %u, %u, %u\n", prismData->mEdgeNormalIndex[0], prismData->mEdgeNormalIndex[1], prismData->mEdgeNormalIndex[2]);
//                 printf(" collision flags: %x\n", prismData->mCollisionFlags);
//                 printf(" tri index: %u\n", prismData->mTriIndex);

                break;
            }
            case TestGameDataHolder: {
                TITLE("GameDataHolder");
                MAX_LINE(2);
                BACK_PAGE(Test, 0);

                CHANGE_PAGE("GameDataFile", TestGameDataFile, 1);

                GameDataHolder* dataHolder = stageScene->mDataHolder;

                break;
            }
            case TestGameDataFile: {
                TITLE("GameDataFile");
                MAX_LINE(2);
                BACK_PAGE(TestGameDataHolder, 0);

                CHANGE_PAGE("Shine List", TestGameDataShine, 1);

                GameDataFile* curFile = stageScene->mDataHolder->mPlayingFile;

                printf(" File Index: %d/5\n", stageScene->mDataHolder->mPlayingFileId + 1);

                break;
            }
            case TestGameDataShine: {
                TITLE("GameDataShine");
                MAX_LINE(4);
                BACK_PAGE(TestGameDataFile, 0);
                
                GameDataFile* curFile = stageScene->mDataHolder->mPlayingFile;
                GameDataFile::HintInfo (*shineList)[1024] = curFile->mShineList;

                INDEXRL(dataShineIdx, 0, 1023, 1);
                printf("%sShine Index: %d/1024\n", charCursor, dataShineIdx+1);
                GameDataFile::HintInfo curShine = (*shineList)[dataShineIdx];

                TRIGGER("Go to position", 2, {
                    if (isExistPlayer) {
                        al::offCollide(player);
                        player->startDemoPuppetable();
                        player->mStainControl->clearStain();
                        al::setTrans(player, curShine.mTrans);
                        al::setVelocityZero(player);
                        player->endDemoPuppetable();
                        al::onCollide(player);
                        al::setTrans(player, curShine.mTrans);
                    }
                });
                TRIGGER_FMT("Go to stage %s", 3, {
                    ChangeStageInfo info = ChangeStageInfo(stageScene->mDataHolder, "start", curShine.mStageName.cstr(), false, -1, {0});
                    stageScene->mDataHolder->changeNextStage(&info, 0);
                }, al::isEqualString(curShine.mStageName.cstr(), curFile->mStageNameCurrent.cstr()) ? "" : "!!!!!");

                printf(" World ID: %d\n", curShine.mWorldId);
                printf(" Is Got: %d\n", curShine.mIsGet);
                printf(" Stage Name: %s\n", curShine.mStageName.cstr());
                printf(" Object ID: %s\n", curShine.mObjId.cstr() ?: "N/A");
                printf(" Achievement: %s\n", curShine.mOptionalId.cstr());
                printf(" Pos: (X: %.3f Y: %.3f Z: %.3f)\n", curShine.mTrans.x, curShine.mTrans.y, curShine.mTrans.z);
                printf(" Hint Trans: (X: %.3f Y: %.3f Z: %.3f)\n", curShine.mHintTrans.x, curShine.mHintTrans.y, curShine.mHintTrans.z);
                printf(" Unique ID: %d\n", curShine.mUniqueId);
                printf(" Object Name: %s\n", curShine.mObjectName.cstr());

                // printf(" %s\n", curShine.sVar3.cstr());

                break;              
            }
            case TestOther: {
                BACK_PAGE(Test, 0);

                if (!isExistPlayer) {
                    MAX_LINE(1);
                    printf(" No player actor!\n");
                    break;
                }

                INDEXRL(otherPageIdx, 0, OTHER_PAGES - 1, 1);

                switch (otherPageIdx) {
                case 0: {
                    MAX_LINE(2);
                    printf("%sPlayerStatePoleClimb\n", charCursor);

                    PlayerStatePoleClimb* statePoleClimb = player->mStatePoleClimb;
                    printf("%s\n", statePoleClimb->mMaterialName);
                    printf("%.3f\n", statePoleClimb->fVar1);
                    printf("%.3f\n", statePoleClimb->fVar2);
                    printf("%.3f\n", statePoleClimb->fVar3);
                    printf("(X: %.3f Y: %.3f)\n", statePoleClimb->mPoleMoveInput.x, statePoleClimb->mPoleMoveInput.y);
                    printf("%d\n", statePoleClimb->mClimbType);
                    printf("%d\n", statePoleClimb->mClimbDelay);
                    printf("%d\n", statePoleClimb->mClimbDownKeepTime);
                    printf("(X: %.3f Y: %.3f)\n", statePoleClimb->mStickMoveRaw.x, statePoleClimb->mStickMoveRaw.y);
                    printf("(X: %.3f Y: %.3f)\n", statePoleClimb->mLeftStickInit.x, statePoleClimb->mLeftStickInit.y);
                    printf("%d %d %d\n", statePoleClimb->mHasJustTurned, statePoleClimb->mIsInputReverse, statePoleClimb->bVar3);
                    printf("%d\n", statePoleClimb->mJudgePreInputPoleClimbSwing->mSwingDelay);

                    break;
                }
                case 1: {
                    MAX_LINE(2);
                    printf("%sPlayerJudgePoleClimb\n", charCursor);

                    PlayerJudgePoleClimb* judgePoleClimb = player->mJudgePoleClimb;
                    printf("%s\n", judgePoleClimb->mMaterialName);
                    printf("(X: %.3f Y: %.3f Z: %.3f)\n", judgePoleClimb->vVar1.x, judgePoleClimb->vVar1.y, judgePoleClimb->vVar1.z);
                    printf("(X: %.3f Y: %.3f Z: %.3f)\n", judgePoleClimb->vVar2.x, judgePoleClimb->vVar2.y, judgePoleClimb->vVar2.z);
                    printf("(X: %.3f Y: %.3f Z: %.3f)\n", judgePoleClimb->vVar3.x, judgePoleClimb->vVar3.y, judgePoleClimb->vVar3.z);
                    printf("%.3f\n", judgePoleClimb->fVar1);
                    printf("%.3f\n", judgePoleClimb->fVar2);
                    printf("%d\n", judgePoleClimb->mIsClimbing);

                    break;
                }
                case 2: {
                    MAX_LINE(2);
                    printf("%sPlayerStainControl\n", charCursor);

                    PlayerStainControl* stainControl = player->mStainControl;
                    printf("%d\n", stainControl->iVar1);
                    printf("%d\n", stainControl->iVar2);
                    printf("%d\n", stainControl->iVar3);
                    printf("%d\n", stainControl->iVar4);
                    printf("%d\n", stainControl->iVar5);
                    printf("%d\n", stainControl->iVar6);
                    printf("%d %d %d %d %d %d\n", stainControl->bVar1, stainControl->bVar2, stainControl->bVar3, stainControl->bVar4, stainControl->bVar5, stainControl->bVar6);
                    printf("%.3f\n", stainControl->fVar1);
                    printf("%.3f\n", stainControl->fVar2);
                    printf("%.3f\n", stainControl->fVar3);
                    printf("%.3f\n", stainControl->fVar4);
                    printf("%.3f\n", stainControl->fVar5);
                    printf("StainType: %d\n", stainControl->mStainType);

                    break;
                }
                case 3: {
                    MAX_LINE(2);
                    printf("%sWorldEndBorderKeeper\n", charCursor);

                    break;

                    WorldEndBorderKeeper* border = player->mWorldEndBorderKeeper;

                    if (border) {
                        printf(" Player Pos: (X: %.3f Y: %.3f Z: %.3f)\n", border->mPlayerTrans.x, border->mPlayerTrans.y, border->mPlayerTrans.z);
                        printf(" Player Vel: (X: %.3f Y: %.3f Z: %.3f)\n", border->mPlayerVel.x, border->mPlayerVel.y, border->mPlayerVel.z);
                        printf(" Closest Point inside Border:\n");
                        printf("     (X: %.3f Y: %.3f Z: %.3f)\n", border->mBorderPoint.x, border->mBorderPoint.y, border->mBorderPoint.z);
                        printf(" Pull Vel: (X: %.3f Y: %.3f Z: %.3f)\n", border->mPullVel.x, border->mPullVel.y, border->mPullVel.z);
                        printf(" Oscillation Frame: %.3f\n", border->mOscillateFrame);
                        printf(" Distance into Border: %.3f\n", border->mDistIntoBorder);
                        printf(" Is Airborne: %s\n", border->mIsAirborne ? "True" : "False");

                        al::AreaObj* area = border->uVar1;

                        printf(" Area Name: %s\n", area->mName);
                        printf(" Area Priority: %d\n", area->mPriority);

                        al::AreaShape* areaShape = area->mAreaShape;
                        ACTOR_NAME(areaName, areaShape);
                        printf(" Area Shape: %s\n", areaName);

                        sead::Vector3f areaTrans;
                        areaShape->calcTrans(&areaTrans);
                        printf(" Area Pos: (X: %.3f Y: %.3f Z: %.3f)\n", areaTrans.x, areaTrans.y, areaTrans.z);
                        sead::Vector3f areaScale = areaShape->mScale;
                        printf(" Area Scale: (X: %.3f Y: %.3f Z: %.3f)\n", areaScale.x, areaScale.y, areaScale.z);
                    } else {
                        printf(" No world border!\n");
                    }

                    // printf(" %s\n", stageScene->mDataHolder->field_0x98); // uchar*

                    break;
                }
                case 4: {
                    MAX_LINE(2);
                    printf("%sWaterSurfaceFinder\n", charCursor);

                    al::WaterSurfaceFinder* surfaceFinder = player->mWaterSurfaceFinder;
                    // PlayerStateSwim* stateSwim = player->mStateSwim;

                    printf(" Is Near Surface: %s\n", surfaceFinder->mIsNearSurface ? "True" : "False");
                    printf(" Distance below Surface: %.3f\n", surfaceFinder->mDistBelowSurface);
                    printf(" Surface: (X: %.3f Y: %.3f Z: %.3f)\n", surfaceFinder->mSurfacePoint.x, surfaceFinder->mSurfacePoint.y, surfaceFinder->mSurfacePoint.z);
                    printf(" vVar2: (X: %.3f Y: %.3f Z: %.3f)\n", surfaceFinder->vVar2.x, surfaceFinder->vVar2.y, surfaceFinder->vVar2.z);
                    printf(" vVar3: (X: %.3f Y: %.3f Z: %.3f)\n", surfaceFinder->vVar3.x, surfaceFinder->vVar3.y, surfaceFinder->vVar3.z);

                    break;
                }
                case 5: {
                    MAX_LINE(3);
                    printf("%sPlayerJudgeInWater\n", charCursor);

                    static int judgeInWaterIdx = 0;

                    INDEXRL(judgeInWaterIdx, 0, 3, 2);
                    printf("%sIndex: %d/4\n", charCursor, judgeInWaterIdx + 1);

                    PlayerJudgeInWater* judgeInWaters[5] = {player->mJudgeInWater1, player->mJudgeInWater2, player->mJudgeInWater3, player->mJudgeInWater4};
                    PlayerJudgeInWater* judgeInWater = judgeInWaters[judgeInWaterIdx];

                    printf(" bVar1: %s\n", judgeInWater->bVar1 ? "True" : "False");
                    printf(" bVar2: %s\n", judgeInWater->bVar2 ? "True" : "False");
                    printf(" bVar3: %s\n", judgeInWater->bVar3 ? "True" : "False");

                    printf(" Judge: %s", judgeInWater->judge() ? "True" : "False");

                    break;
                }
                case 6: {
                    MAX_LINE(3);
                    TITLE_FMT("%sCameraPoser", charCursor);

                    static int snapShotIdx = 0;

                    INDEXRL(snapShotIdx, 0, 0, 2);
                    printf("%sPage: %d/1\n", charCursor, snapShotIdx + 1);

                    al::CameraPoser* curPoser;
                    al::CameraDirector* director = stageScene->getCameraDirector();
                    if (director) {
                        al::CameraPoseUpdater* updater = director->getPoseUpdater(0);
                        if (updater && updater->mTicket)
                            curPoser = updater->mTicket->mPoser;
                    }

                    if (curPoser) {
                        printf(" Name: %s\n", curPoser->getName());
                        printf(" Pos: (X: %.3f Y: %.3f Z: %.3f)\n", curPoser->mPosition.x, curPoser->mPosition.y, curPoser->mPosition.z);
                        printf(" Target: (X: %.3f Y: %.3f Z: %.3f)\n", curPoser->mTargetTrans.x, curPoser->mTargetTrans.y, curPoser->mTargetTrans.z);
                        printf(" FOV: %.3f\n", curPoser->mFovyDegree);
                        
                        al::SnapShotCameraCtrl* snapShotCamera = curPoser->mSnapShotCameraCtrl;
                        if (snapShotCamera) {
                            printf(" %.3f %.3f\n", snapShotCamera->fVar1, snapShotCamera->fVar2);
                            printf(" %.3f %.3f\n", snapShotCamera->fVar3, snapShotCamera->mMaxZoomOutFovyDegree);
                            printf(" %.3f %.3f\n", snapShotCamera->mRollDegree, snapShotCamera->mRollTarget);
                            printf(" %x\n", snapShotCamera->uVar2);
                            printf(" %d %d %d %d\n", snapShotCamera->mIsValidLookAtOffset, snapShotCamera->mIsValidZoomFovy, snapShotCamera->mIsValidRoll, snapShotCamera->bVar1);
                            printf(" %d %.3f %.3f\n", snapShotCamera->mParam->bVar, snapShotCamera->mParam->fVar1, snapShotCamera->mParam->fVar2);
                        }
                    }

                    break;
                }
                case 7: {
                    TITLE_FMT("%sPlayerCarryKeeper", charCursor);
                    
                    TOGGLE("Lock Current Item", options.lockCarry, 2);

                    PlayerCarryKeeper* carryKeeper = player->mCarryKeeper;

                    static int seedStateWaitIdx = 0;

                    if (!carryKeeper) break;


                    if (!options.lockCarry)
                        currentCarry = carryKeeper->mSensorHeld;
                    
                    if (!currentCarry) {
                        printf(" N/A\n");
                        break;
                    }

                    al::LiveActor* actor = currentCarry->mHost;
                    if (!actor) break;

                    ACTOR_NAME(currentActorName, actor);
                    printf(" Actor Name: %s\n", currentActorName);

                    if (al::isEqualString(currentActorName, "GrowPlantSeed")) {
                        MAX_LINE(4);
                        INDEXRL(seedStateWaitIdx, 0, 1, 3);
                        printf("%sStateWait: %d/2\n", charCursor, seedStateWaitIdx + 1);

                        GrowPlantSeed* nut = static_cast<GrowPlantSeed*>(actor);
                        GrowSeedStateWait* stateWaits[2] = { nut->mStateWait, nut->mStateWaitWater };
                        GrowSeedStateWait* stateWait = stateWaits[seedStateWaitIdx];

                        PRINT_NERVE(nut);
                        printf(" %d %d %d %d %d %d %d\n", nut->bVar1, nut->bVar2, nut->bVar3, nut->bVar4, nut->bVar5, nut->bVar6, nut->bVar7);
                        printf(" %d %d %d %d\n", nut->iVar1, nut->iVar2, nut->iVar3, nut->iVar4);
                        printf(" Is Save: %s\n", nut->mIsSave ? "True" : "False");

                        if (!stateWait) {
                            printf(" StateWait: N/A\n");
                            break;
                        }

                        printf(" %d %d %d\n", stateWait->bVar1, stateWait->bVar2, stateWait->bVar3);
                        printf(" %d\n", stateWait->iVar1);


                    } else {
                        MAX_LINE(3);
                    }
                    break;
                }
                case 8: {
                    TITLE_FMT("%sApplication", charCursor);
                    MAX_LINE(3);


                    

                    break;
                }
                case 9: {
                    TITLE_FMT("%sSensors", charCursor);
                    MAX_LINE(3);

                    sead::PtrArray<al::HitSensor> sensors = player->mHitSensorKeeper->mSensors;
                    static int sensorIdx = 0;

                    if (sensors.capacity() <= 0) break;

                    INDEXRL(sensorIdx, 0, sensors.capacity()-1, 2);
                    printf("%sIndex: %d/%d\n", charCursor, sensorIdx+1, sensors.capacity());
                    al::HitSensor* curSensor = sensors[sensorIdx];

                    printf(" %p\n", curSensor);

                    if (!curSensor) break;

                    printf(" name: %s\n", curSensor->mName);
                    printf(" type: %u\n", curSensor->mType);
                    printf(" radius: %.3f\n", curSensor->mRadius);
                    printf(" (X: %.3f Y: %.3f Z: %.3f)\n", curSensor->vVar1.x, curSensor->vVar1.y, curSensor->vVar1.z);
                    printf(" (X: %.3f Y: %.3f Z: %.3f)\n", curSensor->mFollowPos->x, curSensor->mFollowPos->y, curSensor->mFollowPos->z);
                    
                    break;
                }
                case 10: {
                    TITLE_FMT("%sPlayerActionAirMoveControl", charCursor);
                    MAX_LINE(3);

                    PlayerActionAirMoveControl* airMoveControl = player->mStateJump->mActionAirMoveControl;
                    static int airMoveIdx = 0;

                    INDEXRL(airMoveIdx, 0, 1, 2);
                    printf("%sPage %d/2\n", charCursor, airMoveIdx+1);

                    if (airMoveIdx == 0) {
                        printf(" %d %d %d %d\n", airMoveControl->bVar1, airMoveControl->bVar2, airMoveControl->bVar3, airMoveControl->bVar4);
                        printf(" %d %d %d %d\n", airMoveControl->bVar5, airMoveControl->bVar6, airMoveControl->bVar7, airMoveControl->bVar8);
                        printf(" %d\n", airMoveControl->iVar1);
                        printf(" %d\n", airMoveControl->iVar2);
                        printf(" extend frame: %d\n", airMoveControl->mExtendFrame);
                        printf(" %.3f\n", airMoveControl->fVar1);
                        printf(" %.3f\n", airMoveControl->fVar2);
                        printf(" %.3f\n", airMoveControl->fVar3);
                        printf(" %.3f\n", airMoveControl->fVar4);
                        printf(" %.3f\n", airMoveControl->fVar5);
                        printf(" %.3f\n", airMoveControl->mFallSpeedMax);
                    }
                    else if (airMoveIdx == 1) {
                        printf(" (X: %.3f Y: %.3f Z: %.3f)\n", airMoveControl->vVar1.x, airMoveControl->vVar1.y, airMoveControl->vVar1.z);
                        printf(" (X: %.3f Y: %.3f Z: %.3f)\n", airMoveControl->vVar2.x, airMoveControl->vVar2.y, airMoveControl->vVar2.z);
                        printf(" (X: %.3f Y: %.3f Z: %.3f)\n", airMoveControl->vVar3.x, airMoveControl->vVar3.y, airMoveControl->vVar3.z);
                        printf(" (X: %.3f Y: %.3f Z: %.3f)\n", airMoveControl->vVar4.x, airMoveControl->vVar4.y, airMoveControl->vVar4.z);
                    }


                    break;
                }
                case 11: {
                    TITLE_FMT("%sEffectSystem", charCursor);
                    MAX_LINE(2);

                    al::EffectSystem* effectSystem = stageScene->mLiveActorKit->mEffectSystem;
                    al::EffectSystemInfo effectSysInfo = effectSystem->mEffectSystemInfo;
                    al::EffectUserInfo* userInfo = alEffectFunction::tryFindEffectUser(&effectSysInfo, "CoinCollect");

                    al::EffectInfo* effectInfo = userInfo->mEffectInfo;
                    printf(" %d\n", effectInfo->mResourceCount);

                    break;
                }
                case 12: {
                    TITLE_FMT("%sShineListLayout", charCursor);
                    MAX_LINE(2);

                    ShineListLayout* lyt = stageScene->mStateCollectionList->mShineList;
                    CommonVerticalList* verticalList = lyt->mVerticalList;

                    printf("%d %d %d\n", lyt->mWorldIdx, lyt->mWorldCount, lyt->iVar3);
                    printf("%d %d %d\n", lyt->mCursorIdx, lyt->iVar5, lyt->iVar6);
                    printf("%d %d\n", lyt->bVar1, lyt->bVar2);
                    printf("%d %d %d\n", verticalList->iVar1, verticalList->mCursorIdx, verticalList->mTopIdx);
                    printf("%d %d %d\n", verticalList->mPrevCursorIdx, verticalList->mPrevTopIdx, verticalList->mDelayFrame);
                    printf("%d %d %d\n", verticalList->iVar7, verticalList->iVar8, verticalList->mItemCount);
                    printf("%d %d %d\n", verticalList->bVar1, verticalList->bVar2, verticalList->bVar3);
                    printf("%.3f %.3f %.3f\n", verticalList->fVar1, verticalList->fVar2, verticalList->fVar3);

                    break;
                }
                case 13: {
                    TITLE_FMT("%sHackCap", charCursor);
                    MAX_LINE(2);

                    printf("%p\n", cappy->gap3);
                    printf("%p\n", cappy->mCapTargetInfo);

                    break;
                }
                case 14: {
                    TITLE_FMT("%sCapManHeroDemoDirector", charCursor);
                    MAX_LINE(2);

                    CapManHeroDemoDirector* demoDirector = static_cast<CapManHeroDemoDirector*>(al::getSceneObj(stageScene, 3));
                    if (!demoDirector) break;

                    printf(" mTalkDemoCurrent: %p\n", demoDirector->mTalkDemoCurrent);
                    printf(" mTalkDemoFirstMoonGet: %p\n", demoDirector->mTalkDemoFirstMoonGet);
                    printf(" mTalkDemoStageStart: %p\n", demoDirector->mTalkDemoStageStart);
                    printf(" mTalkDemoMoonRock: %p\n", demoDirector->mTalkDemoMoonRock);

                    break;
                }
                case 15: {
                    TITLE_FMT("%sPrimitiveDrawer shapes", charCursor);
                    MAX_LINE(5);


                    TOGGLE("Cube", testDrawCube, 2);
                    TOGGLE("Cylinder", testDrawCylinder, 3);
                    TOGGLE("Sphere", testDrawSphere, 4);

                    break;
                }
                default: {
                    otherPageIdx = 0;
                    break;
                }
                }

                break;
            }
            case TestTalkatoo: {
                TITLE("Talkatoo");
                MAX_LINE(4);
                BACK_PAGE(Test, 0);

                GameDataFile* curFile = stageScene->mDataHolder->mPlayingFile;

                int shinesTable[0x400];
                int shinesCount;

                INDEXSRL(curWorldId, curScenarioNo, 1, 0, 15, 1);
                printf("%sWorld Id: %d\n", charCursor, curWorldId);
                int moonRockScenario = stageScene->mDataHolder->mWorldList->getMoonRockScenarioNo(curWorldId);

                INDEXRL(curScenarioNo, 1, moonRockScenario, 2);
                printf("%sScenario: %d/%d\n", charCursor, curScenarioNo, moonRockScenario);

                int tempScenarioNo = curFile->mScenarioNo[curWorldId];
                curFile->mScenarioNo[curWorldId] = curScenarioNo;

                curFile->calcShineIndexTableNameUnlockable(shinesTable, &shinesCount, curWorldId);

                INDEXRL(talkatooIndex, 0, shinesCount - 1, 3);

                if (shinesCount == 0) {
                    printf("%sNo moons available\n", charCursor);
                    curFile->mScenarioNo[curWorldId] = tempScenarioNo;
                    break;
                }

                printf("%sIndex: %d/%d\n", charCursor, talkatooIndex+1, shinesCount);

                const char16_t* shineName = GameDataFunction::tryFindShineMessage(stageScene->mStateCollectionList->mShineList, curWorldId, shinesTable[talkatooIndex]);

                if (shineName) {
                    printf(" ");
                    printf(shineName);
                    printf("\r\n");
                }

                curFile->mScenarioNo[curWorldId] = tempScenarioNo;




                break;
            }
            case TestLoadingZones: {
                TITLE("Loading Zones");
                MAX_LINE(2);
                BACK_PAGE(Menu, 0);


                INDEXRL(changeStageNum, 0, 1, 1);
                printf("%sChangeStageInfo: %d/2\n", charCursor, changeStageNum+1);

                ChangeStageInfo* lz;
                if (changeStageNum == 0)
                    lz = stageScene->mDataHolder->mPlayingFile->uVar4;
                else if (changeStageNum == 1)
                    lz = stageScene->mDataHolder->mPlayingFile->uVar5;

                printf(" Stage: %s\n", lz->mChangeStageName.mBuffer);
                printf(" Entrance: %s\n", lz->mChangeStageId.mBuffer);
                printf(" ObjId: %s\n", lz->mObjId.mBuffer);
                printf(" Wipe Type: %s\n", lz->mWipeType.mBuffer);
                printf(" Scenario: %d\n", lz->mScenario);
                printf(" Hint Priority: %d\n", lz->mHintPriority);
                printf(" unknown bool: %s\n", lz->mUnkBool ? "True" : "False");

                break;
            }
            default: {
                curPage = Menu;
                break;
            }
        }
    }

    movingPage = false;
    nextFrameNoLeftInput = false;
    nextFrameNoRightInput = false;
}
