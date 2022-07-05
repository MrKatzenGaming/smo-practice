#pragma once

#include "al/scene/Scene.h"
#include "game/GameData/GameDataHolder.h"
#include "game/Interfaces/IJudge.h"
#include "game/Player/PlayerActorHakoniwa.h"
#include <sead/math/seadVector.h>
#include "al/iuse/IUseSceneObjHolder.h"

namespace al {
    class LiveActor;
    class SensorMsg;
}

namespace rs {
    uint32_t getStageShineAnimFrame(const al::LiveActor *, const char *);

    al::LiveActor* getPlayerActor(const al::Scene *);
    bool isTriggerSnapShotMode(al::IUseSceneObjHolder const*);
    bool isTriggerAmiiboMode(al::IUseSceneObjHolder const*);

    bool isInChangeStageArea(al::LiveActor const*, sead::Vector3f const *);

    bool isInvalidChangeStage(al::LiveActor const *);

    bool isMsgCapTouchWall(al::SensorMsg const *);

    bool isJudge(IJudge const *);

    void buyCap(al::IUseSceneObjHolder const *, char const*);

    int getActiveQuestNum(al::IUseSceneObjHolder const *);
    int getActiveQuestNo(al::IUseSceneObjHolder const *);
    const char *getActiveQuestLabel(al::IUseSceneObjHolder const *);
    void requestShowHtmlViewer(al::IUseSceneObjHolder const *);

    int calcGetShineNumTimerAthletic(GameDataHolder const *);

}
