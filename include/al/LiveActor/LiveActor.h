#pragma once

#include "al/actor/ActorInitInfo.h"
#include "al/area/AreaObjDirector.h"
#include "al/audio/AudioKeeper.h"
#include "al/camera/CameraDirector.h"
#include "al/collision/CollisionDirector.h"
#include "al/effect/EffectKeeper.h"
#include "al/hio/HioNode.h"
#include "al/model/ModelKeeper.h"
#include "al/nerve/Nerve.h"
#include "al/pose/ActorPoseKeeper.h"
#include "al/rail/RailKeeper.h"
#include "al/iuse/IUseAudioKeeper.h"
#include "al/iuse/IUseCamera.h"
#include "al/iuse/IUseNerve.h"
#include "al/iuse/IUseRail.h"
#include "al/iuse/IUseSceneObjHolder.h"
#include "al/scene/SceneObjHolder.h"
#include "al/screen/ScreenPointKeeper.h"
#include "al/sensor/HitSensorKeeper.h"
#include "al/sensor/HitSensor.h"
#include "al/switch/StageSwitchKeeper.h"
#include "LiveActorFlag.h"

// vtable for LiveActor: 1C4EB58


namespace al {
    class ActorPoseKeeperBase;
    class ActorExecuteInfo;
    class ActorActionKeeper;
    class ActorItemKeeper;
    class ActorScoreKeeper;
    class Collider;
    class CollisionParts;
    class ShadowKeeper;
    class ActorPrePassLightKeeper;
    class ActorOcclusionKeeper;
    class SubActorKeeper;
    class ActorParamHolder;
    class ActorSceneInfo;

    class HitSensor;
    class SensorMsg;
    class ScreenPointer;
    class ScreenPointTarget;
    class LiveActor : public al::IUseNerve, public al::IUseEffectKeeper, public al::IUseAudioKeeper, public al::IUseStageSwitch, public al::IUseSceneObjHolder, public al::IUseAreaObj, public al::IUseCamera, public al::IUseCollision, public al::IUseRail, public al::IUseHioNode {
    public:
        LiveActor(const char *);

        virtual NerveKeeper* getNerveKeeper() const override;
        virtual void init(const ActorInitInfo&);
        virtual void initAfterPlacement();
        virtual void appear();
        virtual void makeActorAlive();
        virtual void kill();
        virtual void makeActorDead();
        virtual void movement();
        virtual void calcAnim();
        virtual void draw() const;
        virtual void startClipped();
        virtual void endClipped();
        virtual void attackSensor(HitSensor*, HitSensor*);
        virtual bool receiveMsg(const SensorMsg*, HitSensor*, HitSensor*);  // NOTE: return type unknown
        virtual bool receiveMsgScreenPoint(const SensorMsg*, ScreenPointer*,
                                       ScreenPointTarget*);  // NOTE: return type unknown
        virtual const char* getName() const override;
        virtual void* getBaseMtx() const;  // NOTE: return type unknown
        virtual EffectKeeper* getEffectKeeper() const override;
        virtual AudioKeeper* getAudioKeeper() const override;
        virtual StageSwitchKeeper* getStageSwitchKeeper() const override;
        virtual RailRider* getRailRider() const override;
        virtual SceneObjHolder* getSceneObjHolder() const override;
        virtual CollisionDirector* getCollisionDirector() const override;
        virtual AreaObjDirector* getAreaObjDirector() const override;
        virtual CameraDirector* getCameraDirector() const override;
        virtual void initStageSwitchKeeper() override;
        virtual void control();
        virtual void updateCollider();
        
        const char* mName;
        al::ActorPoseKeeperBase* mPoseKeeper;
        al::ActorExecuteInfo* mLayoutExecuteInfo;
        al::ActorActionKeeper* mActionKeeper;
        al::ActorItemKeeper* mItemKeeper;
        al::ActorScoreKeeper* mScoreKeeper;
        al::Collider* mCollider;
        al::CollisionParts* mCollisionParts;
        al::ModelKeeper* mModelKeeper;
        al::NerveKeeper* mNerveKeeper;
        al::HitSensorKeeper* mHitSensorKeeper;
        al::ScreenPointKeeper* mScreenPointKeeper;
        al::EffectKeeper* mEffectKeeper;
        al::AudioKeeper* mAudioKeeper;
        void* gap_1;
        al::StageSwitchKeeper* mStageSwitchKeeper;
        al::RailKeeper* mRailKeeper;
        al::ShadowKeeper* mShadowKeeper;
        al::ActorPrePassLightKeeper* mPrePassLightKeeper;
        al::ActorOcclusionKeeper* mOcclusionKeeper;
        al::SubActorKeeper* mSubActorKeeper;
        al::ActorParamHolder* mParamHolder;
        al::ActorSceneInfo* mSceneInfo;
        al::LiveActorFlag* mLiveActorFlag;
    };
};
