/**
 * @file GameDataFunction.h
 * @brief Holds functions for getting / storage save data.
 */

#pragma once

#include "al/LiveActor/LiveActor.h"
#include "al/layout/LayoutActor.h"
#include "game/StageScene/ChangeStageInfo.h"
#include "GameDataHolderAccessor.h"
#include "GameDataHolderWriter.h"
#include "GameDataHolder.h"
#include "game/GameData/GameDataFile.h"

namespace GameDataFunction {
    // Gets the required number of moons required to leave a kingdom
    s32 findUnlockShineNumByWorldId(bool*, GameDataHolderAccessor, int);
    s32 getCurrentWorldId(GameDataHolderAccessor);
    s32 getCurrentShineNum(GameDataHolderAccessor);
    s32 getTotalShineNum(GameDataHolderAccessor, int);
    // gets prev save file's current world id
    s32 getPrevWorldId(GameDataHolderAccessor);
    // gets current save file's current world id
    // gets next save file's current world id
    s32 getNextWorldId(GameDataHolderAccessor);


    s32 calcNextScenarioNo(GameDataHolderAccessor);
    // gets total moons collected on a specified save file (-1 for current save)
    // gets the total amount of moons available in a kingdom
    s32 getWorldTotalShineNum(GameDataHolderAccessor, int); 
    // gets the current scenario No of the specified kingdom
    s32 getWorldScenarioNo(GameDataHolderAccessor, int);

    char* getCurrentStageName(GameDataHolderAccessor);

    char* getMainStageName(GameDataHolderAccessor, int);

    char* getNextStageName(GameDataHolderAccessor);

    // checks save file if shine is collected in kingdom index
    bool isGotShine(GameDataHolderAccessor, int, int);

    // checks save file if shine is collected by shine index only (0 through 725)
    bool isGotShine(GameDataHolderAccessor, int);

    bool isGotShine(GameDataHolderAccessor, ShineInfo const*);

    // checks if current stage is a main stage
    bool isMainStage(GameDataHolderAccessor);

    // Gets Index for X Kingdom
    s32 getWorldIndexWaterfall(void);
    s32 getWorldIndexMoon(void);

    // gets the current level of the Odyssey
    s32 getHomeLevel(GameDataHolderAccessor);

    // enables cappy if not enabled already
    void enableCap(GameDataHolderWriter);
    void disableCapByPlacement(al::LiveActor const*);
    void missAndRestartStage(GameDataHolderWriter);
    void recoveryPlayer(al::LiveActor* player);
    void getLifeMaxUpItem(al::LiveActor* player);

    // kills the player
    void killPlayer(GameDataHolderWriter);

    // upgrades the odyssey
    void upHomeLevel(GameDataHolderWriter);

    //unlocks a kingdom based off index
    void unlockWorld(GameDataHolderWriter, int);
    //sets the scenario of the specified kingdom
    void setMainScenarioNo(GameDataHolderWriter, int scenarioNo);

    // checks if odyssey is/needs a repair
    bool isRepairHome(GameDataHolderAccessor);
    void repairHome(GameDataHolderWriter);

    // checks if odyssey is crashed
    bool isCrashHome(GameDataHolderAccessor);
    void crashHome(GameDataHolderWriter);

    // checks if odyssey is activated 
    bool isActivateHome(GameDataHolderAccessor);
    void activateHome(GameDataHolderWriter);

    // checks if the odyssey has launched for the first time.
    bool isLaunchHome(GameDataHolderAccessor);
    void launchHome(GameDataHolderWriter);

    bool isHomeShipStage(GameDataHolder const *);

    // used during the event that enables the odyssey to be used (enables the globe for the odyssey)
    void talkCapNearHomeInWaterfall(al::LiveActor const*);

    void tryChangeNextStage(GameDataHolderWriter, ChangeStageInfo const*);
    GameDataFile* getGameDataFile(GameDataHolderWriter);
    void tryChangeNextStageWithStartRaceFlag(GameDataHolderWriter, ChangeStageInfo const*);
    void tryChangeNextStageWithDemoWorldWarp(GameDataHolderWriter, char const*);
    void changeNextStageWithCloset(GameDataHolderWriter);

    const char16_t* tryFindShineMessage(al::LayoutActor const*, int, int);
};
