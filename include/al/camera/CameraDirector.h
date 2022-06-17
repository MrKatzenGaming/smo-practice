#pragma once

#include "CameraPoseUpdater.h"
#include "al/hio/HioNode.h"
#include "al/iuse/IUseExecutor.h"
#include "al/camera/CameraAngleVerticalRequester.h"

namespace al {
class SceneCameraInfo;
class SceneCameraCtrl;
class CameraPoserFactory;
class CameraPoserSceneInfo;
class CameraTicketHolder;
class SpecialCameraHolder;
class CameraTargetCollideInfoHolder;
class CameraTargetHolder;
class CameraInputHolder;
class CameraStartParamCtrl;
class CameraStopJudge;
class CameraParamTransfer;
class CameraResourceHolder;
class CameraFlagCtrl;
class CameraInSwitchOnAreaDirector;

class CameraDirector : public al::HioNode, public al::IUseExecutor {
public:
    void startSnapShotMode(bool);
    al::CameraPoseUpdater* getPoseUpdater(int) const;
    float getSceneFovyDegree(void) const;

    int mPoseUpdaterCount;
    al::SceneCameraInfo* mSceneCameraInfo;
    al::SceneCameraCtrl* mSceneCameraCtrl;
    al::CameraPoseUpdater** mPoseUpdaters;
    al::CameraPoserFactory* mPoserFactory;
    al::CameraPoserSceneInfo* mPoserSceneInfo;
    al::CameraTicketHolder* mTicketHolder;
    al::SpecialCameraHolder* mSpecialCameraHolder;
    al::CameraTargetCollideInfoHolder* mTargetCollideInfoHolder;
    al::CameraTargetHolder* mTargetHolder;
    al::CameraInputHolder* mInputHolder;
    al::CameraAngleVerticalRequester* mAngleVerticalRequester;
    al::CameraStartParamCtrl* mStartParamCtrl;
    al::CameraStopJudge* mStopJudge;
    al::CameraParamTransfer* mParamTransfer;
    al::CameraResourceHolder* mResourceHolder;
    al::CameraFlagCtrl* mFlagCtrl;
    void* gap1;
    al::CameraInSwitchOnAreaDirector* mInSwitchOnAreaDirector;
    void* gap2;
};
};
