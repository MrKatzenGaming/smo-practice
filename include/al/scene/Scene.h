#pragma once

#include "al/audio/AudioDirector.h"
#include "al/audio/AudioKeeper.h"
#include "al/camera/CameraDirector.h"
#include "al/gfx/DrawSystemInfo.h"
#include "al/iuse/IUseAudioKeeper.h"
#include "al/iuse/IUseCamera.h"
#include "al/iuse/IUseSceneObjHolder.h"
#include "al/nerve/NerveExecutor.h"
#include "al/scene/SceneInitInfo.h"
#include "al/scene/SceneObjHolder.h"
#include "game/GameData/GameDataHolderAccessor.h"
#include <sead/prim/seadSafeString.h>

namespace al {
class LiveActorKit;
class StageResourceKeeper;
class LayoutKit;
class SceneStopCtrl;
class SceneMsgCtrl;
class SceneCoverCtrl;

class Scene : public al::NerveExecutor, public al::IUseAudioKeeper, public al::IUseCamera, public al::IUseSceneObjHolder {
public:
    Scene(const char *);

    virtual al::NerveKeeper* getNerveKeeper();
    virtual ~Scene();
    //virtual void init(const al::SceneInitInfo &);
    virtual void appear();
    virtual void kill();
    virtual void movement();
    virtual void control();
    virtual void drawMain();
    virtual void drawSub();
    virtual al::AudioKeeper* getAudioKeeper();
    virtual al::SceneObjHolder* getSceneObjHolder();
    virtual al::CameraDirector* getCameraDirector();
    
    bool mIsAlive;
    sead::FixedSafeString<64> mName;
    StageResourceKeeper* mStageResourceKeeper;
    LiveActorKit* mLiveActorKit;
    LayoutKit* mLayoutKit;
    SceneObjHolder* mSceneObjHolder;
    SceneStopCtrl* mSceneStopCtrl;
    SceneMsgCtrl* mSceneMsgCtrl;
    SceneCoverCtrl* mSceneCoverCtrl;
    AudioDirector* mAudioDirector;
    AudioKeeper* mAudioKeeper;
    DrawSystemInfo* mDrawSystemInfo;
};
};
