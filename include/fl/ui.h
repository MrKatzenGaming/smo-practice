#pragma once

#include "al/LiveActor/LiveActor.h"
#include "al/LiveActor/LiveActorGroup.h"
#include "al/actor/ActorInitInfo.h"
#include "al/actor/Placement.h"
#include "al/area/AreaObj.h"
#include "al/area/AreaObjDirector.h"
#include "al/area/AreaShape.h"
#include "al/nerve/Nerve.h"
#include "al/scene/Scene.h"
#include "al/LiveActor/LiveActorKit.h"
#include "al/util.hpp"
#include "debugMenu.hpp"
#include "game/Actors/JugemFishing.h"
#include "game/Actors/Killer.h"
#include "game/Actors/KuriboHack.h"
#include "game/Actors/GiantWanderBoss.h"
#include "game/GameData/GameDataFile.h"
#include "game/GameData/GameDataFunction.h"
#include "game/Player/PlayerConst.h"
#include "game/Player/PlayerState.h"
#include "game/WorldEndBorderKeeper.h"
#include "rs/util.hpp"
#include "sead/prim/seadSafeString.h"
#include "debugMenu.hpp"
#include <game/Player/PlayerActorHakoniwa.h>
#include <game/StageScene/StageScene.h>
#include <sead/math/seadQuat.h>
#include <sead/math/seadVector.h>

#define NUMSAVES 16
#define MAXDEPTH 16

namespace fl {

struct SaveState {
    bool mSaved = false;
    sead::Vector3f mTrans = { 0, 0, 0 };
    sead::Quatf mQuat = { 0, 0, 0, 0 };
};

class PracticeUI {
private:
    SaveState savestates[NUMSAVES];
    s8 savestateIndex = 0;
    bool noclipping = false;
    s8 reloadStageForPos = -1;
    sead::Vector3f reloadStageTrans = { 0, 0, 0 };
    sead::Quatf reloadStageQuat = { 0, 0, 0, 0 };
    StageScene* stageScene = nullptr;
    float moonJumpVel = 50.0f;
    char* demangleBuffer = static_cast<char*>(malloc(64));
    size_t demangledSize;
    int cxaStatus;
    al::LiveActor* currentHack;
    int heldDirFrames = 0;

    bool hideShineCounter = false;
    bool nextFrameNoLeftInput = false;
    bool nextFrameNoRightInput = false;

    void savePosition(PlayerActorHakoniwa& player, s8 idx);
    void loadPosition(PlayerActorHakoniwa& player, s8 idx);
    void toggleNoclip(PlayerActorHakoniwa& player);

public:
    static inline PracticeUI& instance() {static PracticeUI ui; return ui;}
    void update(StageScene& stageScene);
    void menu(sead::TextWriter& p);

    inline StageScene* getStageScene() {return stageScene;}

    struct {
        bool teleportEnabled = true;
        bool noclipEnabled = true;
        bool shineRefresh = false;
        bool gotShineRefresh = false;
        bool alwaysWarp = false;
        bool disableAutoSave = false;
        bool skipBowser = false;
        bool buttonMotionRoll = false;
        bool moonJump = false;
        bool loadCurrentFile = false;
        bool loadFileConfirm = false;
        bool repeatCapBounce = false;
        bool repeatRainbowSpin = false;
        bool wallJumpCapBounce = false;
        bool disableCameraVertical = false;
        bool disableCameraStop = false;
        bool noDamageLife = false;
        bool disableTriggerL = true;
        bool lockHack = false;
        bool disableShineNumUnlock = false;
    } options;

    struct {
        bool showPlayer = false;
        bool showAxis = false;
        bool showArea = true;
        bool showAreaPoint = true;
        bool showAreaGroup = false;
        bool showHitInfoFloor = false;
        bool showHitInfoWall = false;
        bool showHitInfoCeil = false;
        bool showHitInfoArray = false;
        al::AreaObjGroup* curAreaGroup = nullptr;
        al::AreaObj* curArea = nullptr;
        sead::Vector3f nearestEdgePoint;
        sead::Vector3f actorTrans = sead::Vector3f::zero;
    } renderer;

    struct {
        bool isModeDiverOrJungleGymRom = false;
        bool isModeDiverRom = false;
        bool isModeE3LiveRom = false;
        bool isModeE3MovieRom = false;
        bool isModeEpdMovieRom = false;
        bool isModeJungleGymRom = false;
    } modes;

    enum Page : u8
    {
        Menu, About,
        Options, OptionsMvmt, OptionsMoon, OptionsSave, OptionsCamera,
        OptionsTeleport, OptionsTeleportSettings, OptionsRenderer,
        Stage, Misc,
        Info, InfoMoon, InfoHack,
        Tas, Modes, Debug,
        Test, TestWallAction, TestCapActionHistory,
        TestLiveActorKit, TestObjectList, TestAreaList, TestExecute,
        TestGameDataFile, TestTalkatoo, TestOther, TestLoadingZones
    };

    Page curPage = Menu;
    s8 curLine = 0;
    s32 actorIndex = 0;
    s32 areaGroupIndex = 0;
    s32 areaIndex = 0;
    s32 dataShineIdx = 0;
    s8 executeTableDrawIdx = 0;
    s32 executeListIdx = 0;
    s32 executeItemIdx = 0;
    s32 itemIdx = 0;
    u8 wallAction = 0;
    s8 poleClimb = 0;
    int talkatooIndex = 0;
    int curWorldId = 0;
    int curScenarioNo = 1;
    s8 changeStageNum = 0;
    s8 curDepth = 0;
    s8 cursorHistory[MAXDEPTH] = { 0 };
    bool movingPage = false;
};

}
