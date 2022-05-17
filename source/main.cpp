#include "al/input/JoyPadAccelPoseAnalyzer.h"
#include "al/nerve/Nerve.h"
#include "al/rail/RailRider.h"
#include "al/util.hpp"
#include "fl/input.h"
#include "fl/tas.h"
#include "game/Layouts/MapLayout.h"
#include "game/Player/PlayerHitPointData.h"
#include "game/Player/PlayerJointControl.h"
#include "rs/util.hpp"
#include "sead/math/seadVector.h"
#include <fl/ui.h>
#include <fl/server.h>
#include <nn/init.h>
#include <mem.h>

void stageSceneControlHook() {
    __asm ("MOV X19, X0");

    StageScene* stageScene;
    __asm ("MOV %[result], X0" : [result] "=r" (stageScene));
    
    fl::PracticeUI::instance().update(*stageScene);

    __asm ("MOV X0, %[input]" : [input] "=r" (stageScene));
}

void stageSceneKillHook() {
    fl::PracticeUI& ui = fl::PracticeUI::instance();
    ui.renderer.curArea = nullptr;
    ui.renderer.curAreaGroup = nullptr;
    ui.renderer.nearestEdgePoint = sead::Vector3f::zero;

    ui.actorIndex = 0;
    ui.areaGroupIndex = 0;
    ui.areaIndex = 0;
    
    __asm("MOV X0, X19");
}

// void storeActorInitInfo() {
//     __asm ("STR X1, [X19, #0x4C0]");
//     __asm ("MOV X0, X19");
// }

// void stageSceneCtorHook() {
//     __asm ("STR XZR, [X19, #0x4C0]");
//     __asm ("STR XZR, [X19, #0x4B8]");
// }

void setGotShineVar(GameDataHolderWriter writer, const ShineInfo* shineInfo)
{
    fl::PracticeUI& ui = fl::PracticeUI::instance();
    if (!ui.options.shineRefresh)
        writer.mPlayingFile->setGotShine(shineInfo);
}

void setPlayerJointUpdate(PlayerJointControlKeeper* keeper)
{
    fl::PracticeUI& ui = fl::PracticeUI::instance();
    // if (!ui.options.gravityChanged)
        keeper->update();
}

int fgetPadAccelerationDeviceNum(int port)
{
    return fl::TasHolder::instance().isRunning ? 2 : al::getPadAccelerationDeviceNum(port);
}

bool isGotShineVar(GameDataHolderAccessor accessor, const ShineInfo* shineInfo)
{
    return fl::PracticeUI::instance().options.gotShineRefresh ? false : accessor.mPlayingFile->isGotShine(shineInfo);
}

bool isEnableCheckpointWarpVar(MapLayout* layout)
{
    return fl::PracticeUI::instance().options.alwaysWarp ? true : layout->isEnableCheckpointWarp();
}

bool isEnableSaveVar(StageScene* stageScene)
{
    return fl::PracticeUI::instance().options.disableAutoSave ? false : stageScene->isEnableSave();
}

bool isDefeatKoopaLv1Var(StageScene* stageScene)
{
    return fl::PracticeUI::instance().options.skipBowser ? true : stageScene->isDefeatKoopaLv1();
}

bool isTriggerRollingRestartSwingVar(PlayerInput* playerInput)
{
    return fl::PracticeUI::instance().options.buttonMotionRoll ? true : playerInput->isTriggerRollingRestartSwing();
}

void setLoadDataSelectingCurrentVar()
{
    __asm ("LDR W20, [X8, #0x3C]");

    GameDataHolder* holder;
    __asm ("MOV %[result], X0" : [result] "=r" (holder));

    s32 fileId = fl::PracticeUI::instance().options.loadCurrentFile ? 5 : holder->getPlayingFileId();

    __asm ("MOV X0, %[input]" : [input] "=r" (fileId));
}

void setLoadDataSelectingConfirmVar()
{
    if (fl::PracticeUI::instance().options.loadFileConfirm)
        __asm ("ADD X9, X8, #0x78");
    else
        __asm ("ADD X9, X8, #0x70");
}

void setRepeatCapBounceVar()
{
    if (fl::PracticeUI::instance().options.repeatCapBounce)
        __asm ("MOV W8, #1");
    else
        __asm ("LDRB W8, [X8, #0x38]");
}

void setRepeatRainbowSpinVar()
{
    if (fl::PracticeUI::instance().options.repeatRainbowSpin)
        __asm ("MOV W8, #1");
    else
        __asm ("LDRB W8, [X8, #0x39]");
}

void setWallJumpCapBounceVar()
{
    if (fl::PracticeUI::instance().options.wallJumpCapBounce)
        __asm ("MOV W8, WZR");
    else
        __asm ("LDRB W8, [X8]");
}

void setDamageVar(PlayerHitPointData* hitPointData) {
    fl::PracticeUI& ui = fl::PracticeUI::instance();
    if (!ui.options.noDamageLife)
        hitPointData->damage();
}

int findUnlockShineNumVar(GameDataHolder* holder, bool* param_1, int param_2) {
    fl::PracticeUI& ui = fl::PracticeUI::instance();
    if (ui.options.disableShineNumUnlock) {
        return 0;
    }
    return holder->findUnlockShineNum(param_1, param_2);
}

void nerveKeeperUpdateVar() {
    // __asm ("LDR W8, [X18, #0x18]");
    al::NerveKeeper* nerveKeeper;
    __asm ("MOV %[result], X19" : [result] "=r" (nerveKeeper));

    nerveKeeper->mStep++;

    __asm ("MOV X19, %[input]" : [input] "=r" (nerveKeeper));
}

bool isTriggerSnapShotModeVar(const al::IUseSceneObjHolder* objHolder)
{
    return (inputEnabled && showMenu) || fl::TasHolder::instance().isRunning ? false : rs::isTriggerSnapShotMode(objHolder);
}

bool isTriggerAmiiboModeVar(const al::IUseSceneObjHolder* objHolder)
{
    return inputEnabled && showMenu ? false : rs::isTriggerAmiiboMode(objHolder);
}

bool fisModeDiverOrJungleGymRom()
{
    return fl::PracticeUI::instance().modes.isModeDiverOrJungleGymRom;
}

bool fisModeDiverRom()
{
    return fl::PracticeUI::instance().modes.isModeDiverRom;
}

bool fisModeJungleGymRom()
{
    return fl::PracticeUI::instance().modes.isModeJungleGymRom;
}

bool fisModeE3LiveRom()
{
    return fl::PracticeUI::instance().modes.isModeE3LiveRom;
}

bool fisModeE3MovieRom()
{
    return fl::PracticeUI::instance().modes.isModeE3MovieRom;
}

bool fisModeEpdMovieRom()
{
    return fl::PracticeUI::instance().modes.isModeEpdMovieRom;
}

bool fisPadTriggerLMotion(int port)
{
    return fl::TasHolder::instance().isRunning ? false : al::isPadTriggerL(port);
}

void motionUpdate(al::JoyPadAccelPoseAnalyzer* dis)
{
    if (!fl::TasHolder::instance().isRunning) {dis->update(); return;}
    fl::TasHolder& h = fl::TasHolder::instance();
    int controllerPort;
    if (dis->mControllerPort < 0)
        controllerPort = al::getMainControllerPort();
    else controllerPort = al::getPlayerControllerPort(dis->mControllerPort);
    dis->mAccelDeviceNum = al::getPadAccelerationDeviceNum(controllerPort);

    if (fisPadTriggerL(controllerPort))
    {
        if (h.oldMotion)
        {
            dis->mSwingLeft = false;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelRightAccel = {0.0f, 1.0f};
            dis->mAccelRightVel = {0.0f, 1.0f};
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
        else if (fisPadTriggerUp(controllerPort))
        {
            dis->mSwingLeft = false;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelRightAccel = {0.0f, 1.0f};
            dis->mAccelRightVel = {0.0f, 1.0f};
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
        else if (fisPadTriggerDown(controllerPort))
        {
            dis->mSwingLeft = false;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelRightAccel = {0.0f, -1.0f};
            dis->mAccelRightVel = {0.0f, -1.0f};
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
        else if (fisPadTriggerLeft(controllerPort))
        {
            dis->mSwingRight = false;
            dis->mSwingLeft = true;
            dis->mSwingAny = true;
            dis->mAccelLeftAccel = {-1.0f, 0.0f};
            dis->mAccelLeftVel = {-1.0f, 0.0f};
            dis->mHistoryLeft.hist0 = 1.4f;
            dis->mHistoryLeft.hist1 = -0.5f;
        }
        else if (fisPadTriggerRight(controllerPort))
        {
            dis->mSwingRight = true;
            dis->mSwingLeft = false;
            dis->mSwingAny = true;
            dis->mAccelRightAccel = {1.0f, 0.0f};
            dis->mAccelRightVel = {1.0f, 0.0f};
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
        else
        {
            dis->mSwingLeft = false;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelRightAccel = {0.0f, 1.0f};
            dis->mAccelRightVel = {0.0f, 1.0f};
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
    }
    else
    {
        if (fisPadTriggerUp(controllerPort))
        {
            dis->mSwingLeft = true;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelCombinedVel = {0.0f, 1.0f};
            dis->mAccelLeftAccel = {0.0f, 1.0f};
            dis->mAccelRightAccel = {0.0f, 1.0f};
            dis->mAccelLeftVel = {0.0f, 1.0f};
            dis->mAccelRightVel = {0.0f, 1.0f};
            dis->mHistoryLeft.hist0 = 1.4f;
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryLeft.hist1 = -0.5f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
        else if (fisPadTriggerLeft(controllerPort))
        {
            dis->mSwingLeft = true;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelCombinedVel = {-1.0f, 0.0f};
            dis->mAccelLeftAccel = {-1.0f, 0.0f};
            dis->mAccelRightAccel = {-1.0f, 0.0f};
            dis->mAccelLeftVel = {-1.0f, 0.0f};
            dis->mAccelRightVel = {-1.0f, 0.0f};
            dis->mHistoryLeft.hist0 = 1.4f;
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryLeft.hist1 = -0.5f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
        else if (fisPadTriggerRight(controllerPort))
        {
            dis->mSwingLeft = true;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelCombinedVel = {1.0f, 0.0f};
            dis->mAccelLeftAccel = {1.0f, 0.0f};
            dis->mAccelRightAccel = {1.0f, 0.0f};
            dis->mAccelLeftVel = {1.0f, 0.0f};
            dis->mAccelRightVel = {1.0f, 0.0f};
            dis->mHistoryLeft.hist0 = 1.4f;
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryLeft.hist1 = -0.5f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
        else if (fisPadTriggerDown(controllerPort))
        {
            dis->mSwingLeft = true;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelCombinedVel = {0.0f, -1.0f};
            dis->mAccelLeftAccel = {0.0f, -1.0f};
            dis->mAccelRightAccel = {0.0f, -1.0f};
            dis->mAccelLeftVel = {0.0f, -1.0f};
            dis->mAccelRightVel = {0.0f, -1.0f};
            dis->mHistoryLeft.hist0 = 1.4f;
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryLeft.hist1 = -0.5f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
        else
        {
            dis->mSwingLeft = false;
            dis->mSwingRight = false;
            dis->mSwingAny = false;
            dis->mAccelCombinedVel = {0.0f, 0.0f};
            dis->mAccelLeftAccel = {0.0f, 0.0f};
            dis->mAccelRightAccel = {0.0f, 0.0f};
            dis->mAccelLeftVel = {0.0f, 0.0f};
            dis->mAccelRightVel = {0.0f, 0.0f};
            dis->mHistoryLeft.hist0 = 0.0f;
            dis->mHistoryRight.hist0 = 0.0f;
            dis->mHistoryLeft.hist1 = 0.0f;
            dis->mHistoryRight.hist1 = 0.0f;
        }
    }
}
