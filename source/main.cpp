#include "al/dither/ActorDitherAnimator.h"
#include "al/dither/FarDistanceDitherAnimator.h"
#include "al/camera/CameraPoserFix.h"
#include "al/gfx/GraphicsSystemInfo.h"
#include "al/input/JoyPadAccelPoseAnalyzer.h"
#include "al/model/ModelMaterialCategory.h"
#include "al/model/ModelOcclusionQuery.h"
#include "al/nerve/Nerve.h"
#include "al/pose/ActorPoseKeeper.h"
#include "al/rail/RailRider.h"
#include "al/string/StringTmp.h"
#include "al/util.hpp"
#include "game/Actors/Megane.h"
#include "game/Layouts/MapLayout.h"
#include "game/Player/PlayerHitPointData.h"
#include "game/Player/PlayerJointControl.h"
#include "rs/util.hpp"
#include <sead/math/seadVector.h>
#include <cstring>
#include "smo/input.h"
#include "smo/server.h"
#include "smo/tas.h"
#include "smo/ui.h"
#include <nn/init.h>
#include <mem.h>

void stageSceneControlHook() {
    __asm ("MOV X19, X0");

    StageScene* stageScene;
    __asm ("MOV %[result], X0" : [result] "=r" (stageScene));
    
    smo::PracticeUI::instance().update(*stageScene);

    __asm ("MOV X0, %[input]" : [input] "=r" (stageScene));
}

void stageSceneKillHook() {
    smo::PracticeUI& ui = smo::PracticeUI::instance();
    ui.kill();
    
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
    smo::PracticeUI& ui = smo::PracticeUI::instance();
    if (!ui.options.shineRefresh)
        writer.mPlayingFile->setGotShine(shineInfo);
}

void setPlayerJointUpdate(PlayerJointControlKeeper* keeper)
{
    smo::PracticeUI& ui = smo::PracticeUI::instance();
    // if (!ui.options.gravityChanged)
        keeper->update();
}


void executeTableHolderDrawCtor(al::ExecuteTableHolderDraw* table) {
    table->debug_Enabled = true;
    // __asm("STR X23, [X0, #0x88]");
    // memset(&table->mListAll, 0, 0x68);
    __asm("ADD X0, X0, #0x18");
}

void executeTableHolderDrawExecute(al::ExecuteTableHolderDraw* table) {
    if (table->arr1.size() <= 0 || !table->debug_Enabled) return;
    int idx = 0;
    while (idx < table->arr1.size()) {
        table->arr1[idx]->executeList();
        idx++;
    }
}

void shineListLayoutListHook(ShineListLayout* lyt) {
    if (al::isFirstStep(lyt))
        al::startAction(lyt, "Wait", nullptr);
    
    if (lyt->mRollParts->isJustChangeRoll()) {
        lyt->mWorldIdx = lyt->mRollParts->iVar1;
        lyt->updateWorldInfo();
    }

    lyt->mTopIndices[lyt->getSelectedWorldId()] = lyt->mVerticalList->mTopIdx;
    lyt->mCursorIndices[lyt->getSelectedWorldId()] = lyt->mVerticalList->mCursorIdx;

    int input = lyt->mInput;
    if (input < 3) {
        
    }


}

int fgetPadAccelerationDeviceNum(int port) {
    return smo::TasHolder::instance().isRunning ? 2 : al::getPadAccelerationDeviceNum(port);
}

bool isGotShineVar(GameDataHolderAccessor accessor, const ShineInfo* shineInfo) {
    return smo::PracticeUI::instance().options.gotShineRefresh ? false : accessor.mPlayingFile->isGotShine(shineInfo);
}

bool isEnableCheckpointWarpVar(MapLayout* layout) {
    return smo::PracticeUI::instance().options.alwaysWarp ? true : layout->isEnableCheckpointWarp();
}

bool isEnableSaveVar(StageScene* stageScene) {
    return smo::PracticeUI::instance().options.disableAutoSave ? false : stageScene->isEnableSave();
}

bool isDefeatKoopaLv1Var(StageScene* stageScene) {
    return smo::PracticeUI::instance().options.skipBowser ? true : stageScene->isDefeatKoopaLv1();
}

bool isTriggerRollingRestartSwingVar(PlayerInput* playerInput) {
    return smo::PracticeUI::instance().options.buttonMotionRoll ? true : playerInput->isTriggerRollingRestartSwing();
}

void setLoadDataSelectingCurrentVar() {
    __asm ("LDR W20, [X8, #0x3C]");

    GameDataHolder* holder;
    __asm ("MOV %[result], X0" : [result] "=r" (holder));

    s32 fileId = smo::PracticeUI::instance().options.loadCurrentFile ? 5 : holder->getPlayingFileId();

    __asm ("MOV X0, %[input]" : [input] "=r" (fileId));
}

void setLoadDataSelectingConfirmVar() {
    if (smo::PracticeUI::instance().options.loadFileConfirm)
        __asm ("ADD X9, X8, #0x78");
    else
        __asm ("ADD X9, X8, #0x70");
}

void setRepeatCapBounceVar() {
    if (smo::PracticeUI::instance().options.repeatCapBounce)
        __asm ("MOV W8, #1");
    else
        __asm ("LDRB W8, [X8, #0x38]");
}

void setRepeatRainbowSpinVar() {
    if (smo::PracticeUI::instance().options.repeatRainbowSpin)
        __asm ("MOV W8, #1");
    else
        __asm ("LDRB W8, [X8, #0x39]");
}

void setWallJumpCapBounceVar() {
    if (smo::PracticeUI::instance().options.wallJumpCapBounce)
        __asm ("MOV W8, WZR");
    else
        __asm ("LDRB W8, [X8]");
}

void setDamageVar(PlayerHitPointData* hitPointData) {
    smo::PracticeUI& ui = smo::PracticeUI::instance();
    if (!ui.options.noDamageLife)
        hitPointData->damage();
}

int findUnlockShineNumVar(GameDataHolder* holder, bool* param_1, int param_2) {
    smo::PracticeUI& ui = smo::PracticeUI::instance();
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

bool setPlayerEnableToSeeOddSpaceVar(al::LiveActor const* actor) {
    smo::PracticeUI& ui = smo::PracticeUI::instance();
    if (ui.options.showOddSpace)
        return true;
    
    PlayerActorHakoniwa* player = al::getPlayerActor(actor, 0);
    PlayerHackKeeper* hackKeeper = player->getPlayerHackKeeper();
    if (!hackKeeper || !al::isEqualString(hackKeeper->getCurrentHackName(), "Megane"))
        return false;
    
    Megane* megane = static_cast<Megane*>(hackKeeper->mCurrentHackActor);
    return megane->isWearingGlasses();
}

bool isTriggerSnapShotModeVar(const al::IUseSceneObjHolder* objHolder) {
    return (inputEnabled && showMenu) || smo::TasHolder::instance().isRunning ? false : rs::isTriggerSnapShotMode(objHolder);
}

bool isTriggerAmiiboModeVar(const al::IUseSceneObjHolder* objHolder) {
    return inputEnabled && showMenu ? false : rs::isTriggerAmiiboMode(objHolder);
}

bool fisModeDiverOrJungleGymRom() {
    return smo::PracticeUI::instance().modes.isModeDiverOrJungleGymRom;
}

bool fisModeDiverRom() {
    return smo::PracticeUI::instance().modes.isModeDiverRom;
}

bool fisModeJungleGymRom() {
    return smo::PracticeUI::instance().modes.isModeJungleGymRom;
}

bool fisModeE3LiveRom() {
    return smo::PracticeUI::instance().modes.isModeE3LiveRom;
}

bool fisModeE3MovieRom() {
    return smo::PracticeUI::instance().modes.isModeE3MovieRom;
}

bool fisModeEpdMovieRom() {
    return smo::PracticeUI::instance().modes.isModeEpdMovieRom;
}

bool fisPadTriggerLMotion(int port) {
    return smo::TasHolder::instance().isRunning ? false : al::isPadTriggerL(port);
}

void motionUpdate(al::JoyPadAccelPoseAnalyzer* dis) {
    if (!smo::TasHolder::instance().isRunning) {dis->update(); return;}
    smo::TasHolder& h = smo::TasHolder::instance();
    int controllerPort;
    if (dis->mControllerPort < 0)
        controllerPort = al::getMainControllerPort();
    else controllerPort = al::getPlayerControllerPort(dis->mControllerPort);
    dis->mAccelDeviceNum = al::getPadAccelerationDeviceNum(controllerPort);

    if (fisPadTriggerL(controllerPort)) {
        if (h.oldMotion) {
            dis->mSwingLeft = false;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelRightAccel = {0.0f, 1.0f};
            dis->mAccelRightVel = {0.0f, 1.0f};
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
        else if (fisPadTriggerUp(controllerPort)) {
            dis->mSwingLeft = false;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelRightAccel = {0.0f, 1.0f};
            dis->mAccelRightVel = {0.0f, 1.0f};
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
        else if (fisPadTriggerDown(controllerPort)) {
            dis->mSwingLeft = false;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelRightAccel = {0.0f, -1.0f};
            dis->mAccelRightVel = {0.0f, -1.0f};
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
        else if (fisPadTriggerLeft(controllerPort)) {
            dis->mSwingRight = false;
            dis->mSwingLeft = true;
            dis->mSwingAny = true;
            dis->mAccelLeftAccel = {-1.0f, 0.0f};
            dis->mAccelLeftVel = {-1.0f, 0.0f};
            dis->mHistoryLeft.hist0 = 1.4f;
            dis->mHistoryLeft.hist1 = -0.5f;
        }
        else if (fisPadTriggerRight(controllerPort)) {
            dis->mSwingRight = true;
            dis->mSwingLeft = false;
            dis->mSwingAny = true;
            dis->mAccelRightAccel = {1.0f, 0.0f};
            dis->mAccelRightVel = {1.0f, 0.0f};
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
        else {
            dis->mSwingLeft = false;
            dis->mSwingRight = true;
            dis->mSwingAny = true;
            dis->mAccelRightAccel = {0.0f, 1.0f};
            dis->mAccelRightVel = {0.0f, 1.0f};
            dis->mHistoryRight.hist0 = 1.4f;
            dis->mHistoryRight.hist1 = -0.5f;
        }
    }
    else {
        if (fisPadTriggerUp(controllerPort)) {
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
        else if (fisPadTriggerLeft(controllerPort)) {
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
        else if (fisPadTriggerRight(controllerPort)) {
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
        else if (fisPadTriggerDown(controllerPort)) {
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
        else {
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
