#pragma once

#include "al/iuse/ISceneObj.h"
#include "al/iuse/IUseSceneObjHolder.h"
namespace sead {
    class LogicalFrameBuffer;
    class LookAtCamera;
    class Projection;
}

#include <sead/math/seadVector.h>
#include <sead/prim/seadSafeString.h>
#include <sead/heap/seadHeap.h>
#include <sead/gfx/seadContext.h>
#include <sead/math/seadQuat.h>

#include "al/area/AreaObj.h"
#include "al/area/AreaObjGroup.h"
#include "al/audio/AudioKeeper.h"
#include "al/camera/CameraTargetBase.h"
#include "al/camera/Projection.h"
#include "al/effect/EffectUserInfo.h"
#include "al/layout/IUseLayout.h"
#include "al/layout/LayoutActor.h"
#include "al/layout/LayoutKit.h"
#include "al/PlayerHolder/PlayerHolder.h"
#include "al/sensor/SensorMsg.h"
#include "al/scene/Scene.h"
#include "al/stage/StageInfo.h"

#include "game/Player/PlayerActorHakoniwa.h"

#include <agl/DrawContext.h>

#include <nn/ui2d/Texture.h>

#include "types.h"

template<class T>
al::LiveActor* createActorFunction(const char* name);

namespace al {
    class ActorInitInfo;

    // General Input functions

    bool isPadTriggerA(int port);
    bool isPadTriggerB(int port);
    bool isPadTriggerX(int port);
    bool isPadTriggerY(int port);
    bool isPadTriggerPressLeftStick(int port);
    bool isPadTriggerPressRightStick(int port);
    bool isPadTriggerZL(int port);
    bool isPadTriggerZR(int port);
    bool isPadTriggerL(int port);
    bool isPadTriggerR(int port);
    bool isPadTriggerPlus(int port);
    bool isPadTriggerMinus(int port);
    bool isPadTriggerDown(int port);
    bool isPadTriggerUp(int port);
    bool isPadTriggerLeft(int port);
    bool isPadTriggerRight(int port);
    bool isPadHoldA(int port);
    bool isPadHoldB(int port);
    bool isPadHoldX(int port);
    bool isPadHoldY(int port);
    bool isPadHoldPressLeftStick(int port);
    bool isPadHoldPressRightStick(int port);
    bool isPadHoldZL(int port);
    bool isPadHoldZR(int port);
    bool isPadHoldL(int port);
    bool isPadHoldR(int port);
    bool isPadHoldPlus(int port);
    bool isPadHoldMinus(int port);
    bool isPadHoldDown(int port);
    bool isPadHoldUp(int port);
    bool isPadHoldLeft(int port);
    bool isPadHoldRight(int port);
    bool isPadReleaseA(int port);
    bool isPadReleaseB(int port);
    bool isPadReleaseX(int port);
    bool isPadReleaseY(int port);
    bool isPadReleasePressLeftStick(int port);
    bool isPadReleasePressRightStick(int port);
    bool isPadReleaseZL(int port);
    bool isPadReleaseZR(int port);
    bool isPadReleaseL(int port);
    bool isPadReleaseR(int port);
    bool isPadReleasePlus(int port);
    bool isPadReleaseMinus(int port);
    bool isPadReleaseDown(int port);
    bool isPadReleaseUp(int port);
    bool isPadReleaseLeft(int port);
    bool isPadReleaseRight(int port);

    sead::Vector2f* getLeftStick(int);
    sead::Vector2f* getRightStick(int);

    // getters
    
    sead::Vector3f* getTrans(al::LiveActor const*);
    sead::Vector3f* getTransPtr(al::LiveActor*);

    sead::Vector3f* getGravity(al::LiveActor const*);

    sead::Vector3f* getUp(al::LiveActor const*);
    sead::Vector3f* getUpPtr(al::LiveActor*);
    
    sead::Vector3f* getVelocity(al::LiveActor const*);
    sead::Quatf* getQuat(al::LiveActor const*);

    sead::Vector3f* getFront(al::LiveActor const*);

    sead::Vector3f* getCameraUp(al::IUseCamera const*, int);

    sead::Vector3f* getScale(al::LiveActor const*);
    sead::Vector3f* getScalePtr(al::LiveActor*);

    sead::Matrix34f* getJointMtxPtr(al::LiveActor const*, const char*);

    float* getScaleX(al::LiveActor const*);
    float* getScaleY(al::LiveActor const*);
    float* getScaleZ(al::LiveActor const*);

    al::PlayerHolder* getScenePlayerHolder(al::Scene const*);
    PlayerActorHakoniwa* getPlayerActor(al::LiveActor const*, int);
    PlayerActorHakoniwa* tryGetPlayerActor(al::PlayerHolder const*, int);

    int getMainControllerPort();
    int getPadAccelerationDeviceNum(int);

    sead::Heap* getCurrentHeap(void);

    al::Projection* getProjection(al::IUseCamera const*, int);

    int getSubActorNum(al::LiveActor const*);

    al::LiveActor* getSubActor(al::LiveActor const*, int);

    int getLodModelCount(al::LiveActor const*);

    int getPlayerControllerPort(int);

    const char* getActionName(al::LiveActor const*);

    const char* getActionFrame(al::LiveActor const*);

    ISceneObj* getSceneObj(al::IUseSceneObjHolder const*, int);

    // setters

    void setTransY(al::LiveActor *, float);

    void setTrans(al::LiveActor *, sead::Vector3f const&);
    void setGravity(al::LiveActor const*, sead::Vector3f const&);

    void setScaleAll(al::LiveActor *, float);

    void setFront(al::LiveActor *, sead::Vector3f const&);

    void setQuat(al::LiveActor *, sead::Quatf const&);
    void setRotate(al::LiveActor*, sead::Vector3f const&);

    void setScale(al::LiveActor*, sead::Vector3f const&);

    void updatePoseQuat(al::LiveActor*, sead::Quatf const&); // 0x0066d880
    void setVelocityZero(al::LiveActor*); // 0x006654b0
    void setEffectParticleScale(al::IUseEffectKeeper* actor, const char* effectName, float scale);

    void setFixedModelFlag(al::LiveActor*);
    void setIgnoreUpdateDrawClipping(al::LiveActor*, bool);

    void setClippingInfo(al::LiveActor*, float, sead::Vector3f const*);
    void setClippingObb(al::LiveActor*, sead::BoundBox3f const&);
    void setClippingNearDistance(al::LiveActor*, float);


    // layout stuff

    void setPaneTexture(al::IUseLayout *, const char*, nn::ui2d::TextureInfo const*);

    //void setPaneString(al::IUseLayout* layout, const char* paneName, char16_t const*, ushort);

    void setPaneStringFormat(al::IUseLayout* layout, const char* paneName, const char* format,...);

    void setPaneLocalTrans(al::IUseLayout* layout, const char* paneName, sead::Vector3f const&);
    void setPaneLocalTrans(al::IUseLayout* layout, const char* paneName, sead::Vector2f const&);
    void setPaneLocalSize(al::IUseLayout* layout, const char* paneName, sead::Vector2f const&);
    void setPaneLocalScale(al::IUseLayout* layout, const char* paneName, sead::Vector2f const&);
    void setPaneLocalRotate(al::IUseLayout* layout, const char* paneName, sead::Vector3f const&);

    void calcLayoutPosFromWorldPos(sead::Vector3f *, IUseCamera const*, sead::Vector3f const&);

    sead::Vector2f getPaneLocalTrans(al::IUseLayout* layout, const char* paneName);
    sead::Vector2f getPaneLocalSize(al::IUseLayout* layout, const char* paneName);
    sead::Vector2f getPaneLocalScale(al::IUseLayout* layout, const char* paneName);
    sead::Vector2f getPaneLocalRotate(al::IUseLayout* layout, const char* paneName);

    bool killLayoutIfActive(al::LayoutActor*);

    bool isHidePane(al::IUseLayout const* lyt, const char* paneName);

    void showPane(al::IUseLayout* lyt, const char* paneName);
    void hidePane(al::IUseLayout* lyt, const char* paneName);

    // camera stuff

    void setCameraTarget(al::IUseCamera *, al::CameraTargetBase*);

    // calc functions

    f32 calcSpeed(al::LiveActor const*);
    f32 calcSpeedH(al::LiveActor const*);
    f32 calcSpeedV(al::LiveActor const*);

    f32 calcDistance(al::LiveActor const*, al::LiveActor const*); // calculates distance between two actors

    f32 calcDistance(al::LiveActor const*, sead::Vector3f const&); // calculates distance between an actor and a position in the world

    void calcFrontDir(sead::Vector3f* result, al::LiveActor const* actor);

    void calcModelBoundingBox(sead::BoundBox3f*, al::LiveActor const*);
    float calcModelBoundingSphereRadius(al::LiveActor const*);

    void rotateVectorQuat(sead::Vector3f*, sead::Quatf const&);

    // velocity stuff

    void addVelocity(al::LiveActor *,sead::Vector3f const&);

    void setVelocity(al::LiveActor *,sead::Vector3f const&);

    void scaleVelocityExceptDirection(al::LiveActor *,sead::Vector3f const&, float);

    void addVelocityToGravity(al::LiveActor *, float);

    // animation stuff

    const char* getPlayingSklAnimName(al::LiveActor const* actor, int index);

    bool tryStartSklAnimIfNotPlaying(al::LiveActor* actor, const char* animName);
    
    bool tryStartSklAnimIfExist(al::LiveActor* actor, const char* animName);

    // byml stuff

    bool tryGetActorInitFileIter(al::ByamlIter*, al::Resource const*, const char*, const char*);

    bool tryGetByamlF32(float *, al::ByamlIter const&, const char*);
    bool tryGetByamlV3f(sead::Vector3f*, al::ByamlIter const&);
    bool tryGetByamlBox3f(sead::BoundBox3f*, al::ByamlIter const&, const char*);

    f32 findActorParamF32(al::LiveActor const*, const char*);
    s32 findActorParamS32(al::LiveActor const*, const char*);

    bool tryGetByamlKeyBoolOrFalse(al::ByamlIter const&, const char*);

    bool tryGetByamlScale(sead::Vector3f*, al::ByamlIter const&, const char*);

    bool tryGetArg(bool*, al::ActorInitInfo const&, const char*);

    // nerve stuff

    bool isLessStep(al::IUseNerve const*,int); // checks if the current nerve has been activated for a certain amount of frames(?)

    bool isFirstStep(al::IUseNerve const*);

    bool isNerve(al::IUseNerve const*, al::Nerve const*);

    void setNerve(al::IUseNerve *,al::Nerve const*);

    void resetNerveActionForInit(al::LiveActor*);

    // effect stuff

    void emitEffect(al::IUseEffectKeeper* effectKeeper, const char* effectName, sead::Vector3f const* effectPosition);
    
    bool tryEmitEffect(al::IUseEffectKeeper* effectKeeper, const char* effectName, sead::Vector3f const* effectPosition);

    void tryDeleteEffect(al::IUseEffectKeeper* effectKeeper, const char* effectName);

    // sensor stuff

    // enum SensorType {
    //     Unknown, // 0
    //     Player, // 1
    //     PlayerAttack, // 2
    //     PlayerFoot // 3
    // };
    
    void addHitSensor(al::LiveActor* actor, al::ActorInitInfo const& initInfo, const char* sensorName, unsigned int typeEnum, float radius, unsigned short maxCount, sead::Vector3f const& position);

    bool isMsgPlayerTrampleReflect(al::SensorMsg const*);

    bool isSensorPlayerAttack(al::HitSensor const* targetSensor);

    bool sendMsgPlayerHipDropKnockDown(al::HitSensor* target, al::HitSensor* source);

    void setHitSensorJointMtx(al::LiveActor*, const char*, const char*);

    al::HitSensor* getHitSensor(al::LiveActor const*, const char*);

    sead::Vector3f& getSensorPos(al::HitSensor const*);
    float getSensorRadius(al::HitSensor const*);
    bool isSensorValid(al::HitSensor const*);

    // audio

    void tryPauseBgmIfLowPriority(al::IUseAudioKeeper const* keeper, const char* audioName, int unk);    

    // player stuff

    void tryGetPlacementInfoAndCount(al::PlacementInfo *, int *, al::StageInfo const*, const char*);

    void getClassName(const char** namePtr, al::ActorInitInfo const& info);

    void getDisplayName(const char** namePtr, al::ActorInitInfo const& info);

    // stage switch stuff

    // misc

    al::AreaObjGroup* tryFindAreaObjGroup(al::IUseAreaObj const*, const char* areaName);

    sead::DrawContext* getSceneDrawContext(al::Scene const*); // these two things are all thats needed to setup text writer in the right context

    sead::LogicalFrameBuffer* getSceneFrameBufferMain(al::Scene const*);

    bool isExistModel(al::LiveActor const*);
    bool isExistRail(al::ActorInitInfo const&, const char*);

    al::ActorResource* findOrCreateActorResource(al::ActorResourceHolder*, const char*, const char*);

    void initActorSceneInfo(al::LiveActor*, al::ActorInitInfo const&);
    void initActorSRT(al::LiveActor*, al::ActorInitInfo const&);
    void initActorModelKeeper(al::LiveActor*, al::ActorInitInfo const&, al::ActorResource const*, int);
    void initActorPrePassLightKeeper(al::LiveActor*, al::Resource const*, al::ActorInitInfo const&, const char*);
    void initActorCollisionWithResource(al::LiveActor*, al::Resource const*, sead::SafeString const&, al::HitSensor*, sead::Matrix34f const*, const char*);
    void initActorEffectKeeper(al::LiveActor*, al::ActorInitInfo const&, const char*);
    void initActorSeKeeper(al::LiveActor*, al::ActorInitInfo const&, const char*);
    void initActorBgmKeeper(al::LiveActor*, al::ActorInitInfo const&, const char*);
    void initStageSwitch(al::LiveActor*, al::ActorInitInfo const&);
    void initActorClipping(al::LiveActor*, al::ActorInitInfo const&);
    void initGroupClipping(al::LiveActor*, al::ActorInitInfo const&);
    void initActorOcclusionKeeper(al::LiveActor*, al::Resource const*, al::ActorInitInfo const&, const char*);
    void initDepthShadowMapCtrl(al::LiveActor*, al::Resource const*, al::ActorInitInfo const&, const char*);
    void initShadowMaskCtrl(al::LiveActor*, al::ActorInitInfo const&, al::ByamlIter const&, const char*);
    void initActorItemKeeper(al::LiveActor*, al::ActorInitInfo const&, al::ByamlIter const&);
    void initScreenPointKeeper(al::LiveActor*, al::Resource const*, al::ActorInitInfo const&, const char*);
    void initHitReactionKeeper(al::LiveActor*, al::Resource const*, const char*);
    void initActorParamHolder(al::LiveActor*, al::Resource const*, const char*);
    void initActorActionKeeper(al::LiveActor*, al::ActorResource const*, const char*, const char*);
    void initSubActorKeeper(al::LiveActor*, al::ActorInitInfo const&, const char*, int);

    void initExecutorUpdate(al::LiveActor*, al::ActorInitInfo const&, const char*);
    void initExecutorModelUpdate(al::LiveActor*, al::ActorInitInfo const&);
    void initExecutorDraw(al::LiveActor*, al::ActorInitInfo const&, const char*);

    void initPartialSklAnim(al::LiveActor*, int, int, int);

    void createUniqueShader(al::LiveActor*);

    int getLayoutDisplayWidth();
    int getLayoutDisplayHeight();

    void executeDraw(al::LayoutKit const*, const char*);

    bool isExistFile(sead::SafeString const& filePath);

    al::StageInfo* getStageInfoMap(al::Scene const*,int);

    void tryGetObjectName(const char**, al::ActorInitInfo const&);

    const char* getModelName(al::LiveActor const*);

    bool isVisAnimExist(const al::LiveActor *, const char*);

    bool isInAreaObj(al::LiveActor const*, const char*);

    al::AreaObj* tryFindAreaObj(al::LiveActor const*, const char*);

    bool calcNearestAreaObjEdgePos(sead::Vector3f*, al::AreaObj const*, sead::Vector3f const&);

    void tryGetAreaObjArg(int *, al::AreaObj const*, const char*);
    void tryGetAreaObjArg(float *, al::AreaObj const*, const char*);
    void tryGetAreaObjArg(bool *, al::AreaObj const*, const char*);

    void tryGetAreaObjStringArg(const char**, al::AreaObj const*, const char*);

    void offCollide(al::LiveActor*); // 0x0065d650
    void onCollide(al::LiveActor*); // 0x0065d630

    void startAction(al::LiveActor *, const char*);
    void startAction(al::IUseLayoutAction*, const char*, const char*);
    bool tryStartAction(al::LiveActor*, const char*);

    bool tryStartSe(al::IUseAudioKeeper const*, sead::SafeString const&);

    void startSe(al::IUseAudioKeeper const*, sead::SafeString const&);

    void startHitReaction(al::LiveActor const*, const char*);

    bool isInDeathArea(al::LiveActor const*);

    void calcCameraUpDir(sead::Vector3f *, al::IUseCamera const*, int);

    const unsigned char* tryGetBymlFromArcName(sead::SafeString const &, sead::SafeString const&);

    bool getArg(int *, const al::ActorInitInfo &, const char*);

    bool isActiveDemo(al::Scene const*);

    bool isEqualString(const char*, const char*);
    bool isEqualSubString(const char*, const char*);
    const char* getBaseName(const char*);

    bool isOnGround(al::LiveActor const*, unsigned int);

    bool isActiveDemo(al::Scene const*);

    bool isInWaterPos(al::LiveActor const*, sead::Vector3f const&);

    void invalidateClipping(al::LiveActor*);
    void invalidateShadowMaskIntensityAll(al::LiveActor*);

    void validateMaterialCode(al::LiveActor*);
    void validatePuddleMaterial(al::LiveActor*);

    // interpolation functions

    void lerpVec(sead::Vector3f* result, sead::Vector3f const& from, sead::Vector3f const& to, float rate);

    void slerpQuat(sead::Quatf* result, sead::Quatf const& from, sead::Quatf const& to, float rate);
    
    // dither anim stuff

    bool isExistDitherAnimator(al::LiveActor const*);

    void stopDitherAnimAutoCtrl(al::LiveActor*);
    void restartDitherAnimAutoCtrl(al::LiveActor*);

    void validateDitherAnim(al::LiveActor*);
    void invalidateDitherAnim(al::LiveActor*);

    float getDitherAnimNearClipStartDistance(al::LiveActor const*);
    float getDitherAnimNearClipEndDistance(al::LiveActor const*);

    void setDitherAnimSphereRadius(al::LiveActor *, float);
    void setDitherAnimBoundingBox(al::LiveActor *, sead::Vector3f const&);
    void setDitherAnimMaxAlpha(al::LiveActor *, float);
    void setDitherAnimClippingJudgeLocalOffset(al::LiveActor *, sead::Vector3f const&);
    void setDitherAnimClippingJudgeParam(al::LiveActor *, const char*);

    // random

    float getRandom();
    float getRandom(float);
    float getRandom(float,float);
    int getRandom(int);
    int getRandom(int,int);

    // other lol

    sead::LookAtCamera* getLookAtCamera(al::IUseCamera const*, int);
    sead::Projection* getProjectionSead(al::IUseCamera const*, int);

    al::AreaObjDirector* getSceneAreaObjDirector(al::Scene const*);
    sead::Vector3f getAreaObjScale(al::AreaObj const*);
    sead::Matrix34f getAreaObjBaseMtx(al::AreaObj const*);

    void makeMtxSRT(sead::Matrix34<float> *,al::LiveActor const*);
    void makeMtxRT(sead::Matrix34<float> *,al::LiveActor const*);
    void makeMtxR(sead::Matrix34<float> *,al::LiveActor const*);

    void normalize(sead::Vector3f*);
    float normalize(float, float, float);

    bool trySyncStageSwitchAppearAndKill(al::LiveActor*);

template <class T>
struct NameToCreator {
    const char* actorName; 
    T createActorFunction; 
};
}

namespace alCollisionUtil {
    al::LiveActor* getCollisionHitActor(al::HitInfo const*);
    al::HitSensor* getCollisionHitSensor(al::HitInfo const*);
    sead::Vector3f* getCollisionHitNormal(al::HitInfo const*);
    sead::Vector3f* getCollisionHitPos(al::HitInfo const*);
    al::CollisionParts* getCollisionHitParts(al::HitInfo const*);

    al::ICollisionPartsKeeper* getCollisionPartsKeeper(al::IUseCollision const*);

    bool getFirstPolyOnArrow(al::IUseCollision const*, sead::Vector3f*, al::Triangle*, sead::Vector3f const&, al::CollisionPartsFilterBase const*, al::TriangleFilterBase const*);
}

namespace alEffectFunction {
    al::EffectUserInfo* tryFindEffectUser(al::EffectSystemInfo const*, const char*);
}

namespace alSensorFunction {
    unsigned int findSensorTypeByName(const char*);
}
