#include "al/LiveActor/LiveActor.h"
#include "al/dither/ActorDitherAnimator.h"
#include "al/dither/FarDistanceDitherAnimator.h"
#include "al/gfx/GraphicsSystemInfo.h"
#include "al/model/ModelMaterialCategory.h"
#include "al/pose/ActorPoseKeeper.h"
#include "al/string/StringTmp.h"
#include "al/util.hpp"


namespace al {

static inline void __attribute__((always_inline)) initActorPose(al::LiveActor* actor, al::Resource const* resource, const char* suffix) {
    al::ByamlIter byamlIter = al::ByamlIter();
    if (!al::tryGetActorInitFileIter(&byamlIter, resource, "InitPose", suffix))
        return;
    
    const char* pose = nullptr;
    int poseIdx;
    if (!byamlIter.tryGetStringByKey(&pose, "Pose") || !pose)
        return;
    
    if (al::isEqualString("TRSV", pose))
        poseIdx = 0;
    else if (al::isEqualString("TRMSV", pose))
        poseIdx = 1;
    else if (al::isEqualString("TRGMSV", pose))
        poseIdx = 2;
    else if (al::isEqualString("TFSV", pose))
        poseIdx = 3;
    else if (al::isEqualString("TFUSV", pose))
        poseIdx = 4;
    else if (al::isEqualString("TFGSV", pose))
        poseIdx = 5;
    else if (al::isEqualString("TQSV", pose))
        poseIdx = 6;
    else if (al::isEqualString("TQGSV", pose))
        poseIdx = 7;
    else if (al::isEqualString("TQGMSV", pose))
        poseIdx = 8;
    else
        return;
        
    poseInits[poseIdx].createActorFunction(actor);
    if (al::isEqualString(pose, "TFUSV") && al::tryGetByamlKeyBoolOrFalse(byamlIter, "IsFrontUp"))
        static_cast<al::ActorPoseKeeperTFUSV*>(actor->mPoseKeeper)->mIsFrontUp = true;
}

static inline void __attribute__((always_inline)) initActorScale(al::LiveActor* actor, al::ActorInitInfo const& actorInitInfo, al::Resource const* resource, const char* suffix) {
    al::initActorSRT(actor, actorInitInfo);
    al::ByamlIter byamlIter = al::ByamlIter();
    if (!al::tryGetActorInitFileIter(&byamlIter, resource, "InitScale", suffix))
        return;

    sead::Vector3f scale = {1.0f, 1.0f, 1.0f};
    if (!al::tryGetByamlScale(&scale, byamlIter, "Scale"))
        return;

    sead::Vector3f* newScale = al::getScale(actor);
    scale.x *= newScale->x;
    scale.y *= newScale->y;
    scale.z *= newScale->z;
    al::setScale(actor, scale);
}

static inline al::ModelLodCtrl* __attribute__((always_inline)) initActorLod(al::LiveActor* actor, al::Resource const* resource, const char* suffix) {
    al::ByamlIter byamlIter = al::ByamlIter();
    if (!al::tryGetActorInitFileIter(&byamlIter, resource, "InitLod", suffix))
        return nullptr;
    
    int lodModelCount;
    sead::BoundBox3f modelBoundingBox = sead::BoundBox3f();
    if (al::isExistModel(actor)) {
        lodModelCount = al::getLodModelCount(actor);
        al::calcModelBoundingBox(&modelBoundingBox, actor);
    } else {
        lodModelCount = 5;
    }
    
    sead::Vector3f* transPtr = al::getTransPtr(actor);
    sead::Matrix34f* baseMtx = actor->getBaseMtx();
    sead::Vector3f* scalePtr = al::getScalePtr(actor);
    al::ModelLodCtrl* modelLodCtrl = new al::ModelLodCtrl(actor, transPtr, baseMtx, scalePtr, modelBoundingBox, lodModelCount);
    modelLodCtrl->init(byamlIter);

    return modelLodCtrl;
}

static inline void __attribute__((always_inline)) initActorModel(al::LiveActor* actor, al::ActorInitInfo const& actorInitInfo, al::Resource* resource, const char* suffix, al::ActorResource* actorResource) {
    al::ByamlIter byamlIter = al::ByamlIter();
    if (!al::tryGetActorInitFileIter(&byamlIter, resource, "InitModel", suffix))
        return;

    int blendAnimMax = 1;
    byamlIter.tryGetIntByKey(&blendAnimMax, "BlendAnimMax");
    al::initActorModelKeeper(actor, actorInitInfo, actorResource, blendAnimMax);

    const char* rootJointName = nullptr;
    byamlIter.tryGetStringByKey(&rootJointName, "DisplayRootJointName");
    if (rootJointName) {
        sead::Matrix34f* jointMtxPtr = al::getJointMtxPtr(actor, rootJointName);
        actor->mModelKeeper->setDisplayRootJointMtxPtr(jointMtxPtr);
    }

    bool isCreateUniqShader = false;
    byamlIter.tryGetBoolByKey(&isCreateUniqShader, "IsCreateUniqShader");
    if (isCreateUniqShader)
        al::createUniqueShader(actor);
    
    int partialAnimSlotNum = 0;
    int partialAnimGroupNum = 0;
    int partialAnimPartsListBufferSize = 0x10;
    byamlIter.tryGetIntByKey(&partialAnimSlotNum, "PartialAnimSlotNum");
    byamlIter.tryGetIntByKey(&partialAnimGroupNum, "PartialAnimGroupNum");
    byamlIter.tryGetIntByKey(&partialAnimPartsListBufferSize, "PartialAnimPartsListBufferSize");
    if (partialAnimGroupNum > 0)
        al::initPartialSklAnim(actor, partialAnimSlotNum, partialAnimGroupNum, partialAnimPartsListBufferSize);
    
    bool isFixedModel = false;
    byamlIter.tryGetBoolByKey(&isFixedModel, "IsFixedModel");
    if (isFixedModel)
        al::setFixedModelFlag(actor);
    
    bool isIgnoreUpdateOnDrawClipping = false;
    byamlIter.tryGetBoolByKey(&isIgnoreUpdateOnDrawClipping, "IsIgnoreUpdateOnDrawClipping");
    if (isIgnoreUpdateOnDrawClipping)
        al::setIgnoreUpdateDrawClipping(actor, true);

    al::ModelKeeper* modelKeeper = actor->mModelKeeper;
    al::ModelLodCtrl* modelLodCtrl = initActorLod(actor, resource, suffix);
    modelKeeper->setModelLodCtrl(modelLodCtrl);
    if (modelLodCtrl)
        actorInitInfo.mGraphicsSystemInfo->mModelLodAllCtrl->registerLodCtrl(modelLodCtrl);
    
    al::ModelMaterialCategory::tryCreate(modelKeeper->mModelCtrl, resource, suffix, actorInitInfo.mGraphicsSystemInfo->mMaterialCategoryKeeper);
    modelKeeper->mModelCtrl->mGraphicsQualityInfo = actorInitInfo.mGraphicsSystemInfo->mGraphicsQualityController->mGraphicsQualityInfo;

    al::ModelOcclusionQuery* occlusionQuery = al::ModelOcclusionQuery::tryCreate(actor, resource, suffix);
    modelKeeper->mModelCtrl->mOcclusionQuery = occlusionQuery;

    bool isCalcViewCore1 = false;
    byamlIter.tryGetBoolByKey(&isCalcViewCore1, "IsCalcViewCore1");
    if (isCalcViewCore1)
        modelKeeper->mModelCtrl->mCalcViewCore = 1;
    
    bool isCalcViewCore2 = false;
    byamlIter.tryGetBoolByKey(&isCalcViewCore2, "IsCalcViewCore2");
    if (isCalcViewCore2)
        modelKeeper->mModelCtrl->mCalcViewCore = 2;
}

static inline void __attribute__((always_inline)) initActorExecutorUpdate(al::LiveActor* actor, al::ActorInitInfo const& actorInitInfo, al::ByamlIter const& baseByamlIter) {
    al::ByamlIter updaterByamlIter = al::ByamlIter();
    if (!baseByamlIter.tryGetIterByKey(&updaterByamlIter, "Updater"))
        return;
    
    if (!updaterByamlIter.isTypeArray())
        return;
    
    al::ByamlIter byamlIter = al::ByamlIter();
    for (int i = 0; updaterByamlIter.tryGetIterByIndex(&byamlIter, i); ++i) {
        const char* categoryName;
        byamlIter.tryGetStringByKey(&categoryName, "CategoryName");
        al::initExecutorUpdate(actor, actorInitInfo, categoryName);
    }
}

static inline void __attribute__((always_inline)) initActorExecutorDraw(al::LiveActor* actor, al::ActorInitInfo const& actorInitInfo, al::ByamlIter const& baseByamlIter) {
    al::ByamlIter drawerByamlIter = al::ByamlIter();
    if (!baseByamlIter.tryGetIterByKey(&drawerByamlIter, "Drawer"))
        return;

    if (actor->mModelKeeper && actor->mModelKeeper->mModelCtrl->mModelObj->field_0x30)
        al::initExecutorModelUpdate(actor, actorInitInfo);
    
    if (!drawerByamlIter.isTypeArray())
        return;
    
    al::ByamlIter byamlIter = al::ByamlIter();
    for (int i = 0; drawerByamlIter.tryGetIterByIndex(&byamlIter, i); ++i) {
        const char* categoryName;
        byamlIter.tryGetStringByKey(&categoryName, "CategoryName");
        al::initExecutorDraw(actor, actorInitInfo, categoryName);
    }
}

static inline void __attribute__((always_inline)) initActorExecutor(al::LiveActor* actor, al::ActorInitInfo const& actorInitInfo, al::Resource const* resource, const char* suffix) {
    al::ByamlIter byamlIter = al::ByamlIter();

    if (al::tryGetActorInitFileIter(&byamlIter, resource, "InitExecutor", suffix)) {
        initActorExecutorUpdate(actor, actorInitInfo, byamlIter);
        initActorExecutorDraw(actor, actorInitInfo, byamlIter);
        return;
    }
    
    if (actor->mModelKeeper && actor->mModelKeeper->mModelCtrl->mModelObj->field_0x30)
        al::initExecutorModelUpdate(actor, actorInitInfo);
}

static inline void __attribute__((always_inline)) initActorSensor(al::LiveActor* actor, al::ActorInitInfo const& actorInitInfo, al::ByamlIter const& baseByamlIter, int idx) {
    al::ByamlIter byamlIter = al::ByamlIter();
    if (!baseByamlIter.tryGetIterByIndex(&byamlIter, idx))
        return;
    
    const char* name = nullptr;
    if (!byamlIter.tryGetStringByKey(&name, "Name"))
        return;
    
    const char* type = nullptr;
    if (!byamlIter.tryGetStringByKey(&type, "Type"))
        return;
    
    float radius = 0.0;
    byamlIter.tryGetFloatByKey(&radius, "Radius");

    int maxCount = 8;
    byamlIter.tryGetIntByKey(&maxCount, "MaxCount");

    sead::Vector3f pos = sead::Vector3f::zero;
    al::tryGetByamlV3f(&pos, byamlIter);

    unsigned int typeIdx = alSensorFunction::findSensorTypeByName(type);
    if (typeIdx == 15)
        maxCount = 0;

    al::addHitSensor(actor, actorInitInfo, name, typeIdx, radius, maxCount, pos);

    const char* joint = nullptr;
    byamlIter.tryGetStringByKey(&joint, "Joint");
    if (joint)
        al::setHitSensorJointMtx(actor, name, joint);
}

static inline void __attribute__((always_inline)) initActorSensors(al::LiveActor* actor, al::ActorInitInfo const& actorInitInfo, al::Resource const* resource, const char* suffix) {
    al::ByamlIter byamlIter = al::ByamlIter();
    if (!al::tryGetActorInitFileIter(&byamlIter, resource, "InitSensor", suffix))
        return;
    
    int sensorCount = byamlIter.getSize();
    if (sensorCount <= 0)
        return;
    
    actor->initHitSensor(sensorCount);

    for (int i = 0; i < sensorCount; ++i) {
        initActorSensor(actor, actorInitInfo, byamlIter, i);
    }
}

static inline void __attribute__((always_inline)) initActorCollision(al::LiveActor* actor, al::ActorInitInfo const& actorInitInfo, al::Resource const* resource, const char* suffix) {
    al::ByamlIter byamlIter = al::ByamlIter();
    if (!al::tryGetActorInitFileIter(&byamlIter, resource, "InitCollision", suffix))
        return;
    
    const char* name = nullptr;
    byamlIter.tryGetStringByKey(&name, "Name");

    // al::StringTmp<256>() something?

    if (!name)
        name = al::getBaseName(resource->getArchiveName());
    
    const char* sensorName = nullptr;
    al::HitSensor* sensor = nullptr;
    if (byamlIter.tryGetStringByKey(&sensorName, "Sensor"))
        sensor = al::getHitSensor(actor, sensorName);
    
    const char* jointName = nullptr;
    byamlIter.tryGetStringByKey(&jointName, "Joint");
    sead::Matrix34f* jointMtx = nullptr;
    if (jointName)
        jointMtx = al::getJointMtxPtr(actor, jointName);
    
    sead::SafeString nameSafeStr = sead::SafeString(name);
    al::initActorCollisionWithResource(actor, resource, nameSafeStr, sensor, jointMtx, suffix);
}

static inline void __attribute__((always_inline)) initActorCollider(al::LiveActor* actor, al::Resource const* resource, const char* suffix) {
    al::ByamlIter byamlIter = al::ByamlIter();
    if (!al::tryGetActorInitFileIter(&byamlIter, resource, "InitCollider", suffix))
        return;

    float radius = 0.0;
    byamlIter.tryGetFloatByKey(&radius, "Radius");

    unsigned int planeNum = 0;
    byamlIter.tryGetUIntByKey(&planeNum, "PlaneNum");

    sead::Vector3f pos = sead::Vector3f::zero;
    al::tryGetByamlV3f(&pos, byamlIter);

    actor->initCollider(radius, pos.y, planeNum);
}

static inline void __attribute__((always_inline)) initActorEffect(al::LiveActor* actor, al::ActorInitInfo const& actorInitInfo, al::Resource const* resource, const char* suffix) {
    al::ByamlIter byamlIter = al::ByamlIter();
    if (!al::tryGetActorInitFileIter(&byamlIter, resource, "InitEffect", suffix))
        return;

    const char* name = nullptr;
    if (byamlIter.tryGetStringByKey(&name, "Name"))
        al::initActorEffectKeeper(actor, actorInitInfo, name);
}

static inline void __attribute__((always_inline)) initActorSound(al::LiveActor* actor, al::ActorInitInfo const& actorInitInfo, al::Resource const* resource, const char* suffix) {
    al::ByamlIter byamlIter = al::ByamlIter();
    const char* seName = nullptr;
    const char* bgmName = nullptr;
    const char* key;
    const char* name;
    bool isExistSound = al::tryGetActorInitFileIter(&byamlIter, resource, "InitSound", suffix);
    if (isExistSound) {
        key = "Name";
        name = seName;
    } else {
        if (!al::tryGetActorInitFileIter(&byamlIter, resource, "InitAudio", suffix))
            return;

        byamlIter.tryGetStringByKey(&seName, "SeUserName");
        key = "BgmUserName";
        name = bgmName;
    }

    byamlIter.tryGetStringByKey(&name, key);

    if (seName)
        al::initActorSeKeeper(actor, actorInitInfo, seName);
    
    if (byamlIter.isExistKey("BgmUserName"))
        al::initActorBgmKeeper(actor, actorInitInfo, bgmName);
}

static inline void __attribute__((always_inline)) initActorClipping(al::LiveActor* actor, al::ActorInitInfo const& actorInitInfo, al::Resource const* resource, const char* suffix) {
    al::ByamlIter byamlIter = al::ByamlIter();
    if (!al::tryGetActorInitFileIter(&byamlIter, resource, "InitClipping", suffix))
        return;
    
    al::initActorClipping(actor, actorInitInfo);

    bool invalidate = false;
    byamlIter.tryGetBoolByKey(&invalidate, "Invalidate");
    if (invalidate)
        al::invalidateClipping(actor);
    
    float radius = 0.0;
    if (!byamlIter.tryGetFloatByKey(&radius, "Radius") && actor->mModelKeeper) {
        sead::Vector3f scale = *al::getScale(actor);
        if (scale.x <= 0.0) scale.x = -scale.x;
        if (scale.y <= 0.0) scale.y = -scale.y;
        if (scale.x <= scale.y) scale.x = scale.y;
        if (scale.z <= 0.0) scale.z = -scale.z;
        if (scale.x <= scale.z) scale.x = scale.z;

        radius = al::calcModelBoundingSphereRadius(actor) * scale.x;
    }
    al::setClippingInfo(actor, radius, nullptr);

    sead::BoundBox3f obb = sead::BoundBox3f();
    if (al::tryGetByamlBox3f(&obb, byamlIter, "Obb"))
        al::setClippingObb(actor, obb);
    
    float nearClipDistance = 0.0;
    if (byamlIter.tryGetFloatByKey(&nearClipDistance, "NearClipDistance"))
        al::setClippingNearDistance(actor, nearClipDistance);
    
    if (byamlIter.isExistKey("NoGroupClipping"))
        return;
    
    al::ByamlIter groupClippingByaml = al::ByamlIter();
    if (byamlIter.tryGetIterByKey(&groupClippingByaml, "GroupClipping"))
        al::initGroupClipping(actor, actorInitInfo);
}

static inline void __attribute__((always_inline)) initActorShadowMask(al::LiveActor* actor, al::ActorInitInfo const& actorInitInfo, al::Resource const* resource, const char* suffix) {
    bool usingDepthShadow = false;
    al::tryGetArg(&usingDepthShadow, actorInitInfo, "UsingDepthShadow");
    al::initDepthShadowMapCtrl(actor, resource, actorInitInfo, suffix);

    al::ByamlIter byamlIter = al::ByamlIter();
    if (!al::tryGetActorInitFileIter(&byamlIter, resource, "InitShadowMask", suffix))
        return;
    
    al::initShadowMaskCtrl(actor, actorInitInfo, byamlIter, "InitShadowMask");
    if (usingDepthShadow)
        al::invalidateShadowMaskIntensityAll(actor);
}

static inline void __attribute__((always_inline)) initActorFlag(al::LiveActor* actor, al::Resource const* resource, const char* suffix) {
    al::ByamlIter baseByamlIter = al::ByamlIter();
    if (!al::tryGetActorInitFileIter(&baseByamlIter, resource, "InitFlag", suffix))
        return;
    
    al::ByamlIter byamlIter = al::ByamlIter();
    if (baseByamlIter.tryGetIterByKey(&byamlIter, "MaterialCode"))
        al::validateMaterialCode(actor);
    
    if (baseByamlIter.tryGetIterByKey(&byamlIter, "UpdatePuddleMaterial"))
        al::validatePuddleMaterial(actor);
}

static inline void __attribute__((always_inline)) initActorItem(al::LiveActor* actor, al::ActorInitInfo const& actorInitInfo, al::Resource const* resource, const char* suffix) {
    al::ByamlIter byamlIter = al::ByamlIter();
    if (!al::tryGetActorInitFileIter(&byamlIter, resource, "InitItem", suffix))
        return;
    
    al::initActorItemKeeper(actor, actorInitInfo, byamlIter);
}

static inline void __attribute__((always_inline)) initActorScore(al::LiveActor* actor, al::Resource const* resource, const char* suffix) {
    al::ByamlIter byamlIter = al::ByamlIter();
    if (!al::tryGetActorInitFileIter(&byamlIter, resource, "InitScore", suffix))
        return;

    actor->initScoreKeeper();
    actor->mScoreKeeper->init(byamlIter);
}

static inline void __attribute__((always_inline)) initActorActionKeeper(al::LiveActor* actor, al::Resource const* resource, const char* suffix, al::ActorResource* actorResource) {
    const char* archiveName = actorResource->mBaseResource->getArchiveName();
    al::initActorActionKeeper(actor, actorResource, archiveName, suffix);
    
    if (!actor->mModelKeeper)
        return;
    
    bool isStartAction = al::tryStartAction(actor, archiveName);
    if (!isStartAction && actor->mActionKeeper)
        actor->mActionKeeper->startAction(archiveName);
    
    al::ModelKeeper* modelKeeper = actor->mModelKeeper;

    if (!modelKeeper)
        return;
    
    al::DitherAnimator* ditherAnimator = al::ActorDitherAnimator::tryCreate(actor, resource, suffix);
    if (!ditherAnimator)
        ditherAnimator = al::FarDistanceDitherAnimator::tryCreate(actor, resource, suffix);
    if (!ditherAnimator)
        return;
    
    modelKeeper->setDitherAnimator(ditherAnimator);
}

}

void initActor(al::LiveActor* actor, al::ActorInitInfo const& actorInitInfo, sead::SafeString* category, sead::SafeString* actorName, const char* suffix) {
    al::StringTmp<256> resourcePath = al::StringTmp<256>("%s/%s", category->cstr(), actorName->cstr());
    al::ActorResource* actorResource = al::findOrCreateActorResource(actorInitInfo.mActorResourceHolder, resourcePath.cstr(), suffix);
    al::Resource* baseResource = actorResource->mBaseResource;

    al::ActorSceneInfo* sceneInfo = actor->getSceneInfo();
    if (!sceneInfo)
        al::initActorSceneInfo(actor, actorInitInfo);

    initActorPose(actor, baseResource, suffix);
    initActorScale(actor, actorInitInfo, baseResource, suffix);
    initActorModel(actor, actorInitInfo, baseResource, suffix, actorResource);
    al::initActorPrePassLightKeeper(actor, baseResource, actorInitInfo, suffix);
    initActorExecutor(actor, actorInitInfo, baseResource, suffix);
    initActorSensors(actor, actorInitInfo, baseResource, suffix);
    initActorCollision(actor, actorInitInfo, baseResource, suffix);
    initActorCollider(actor, baseResource, suffix);
    initActorEffect(actor, actorInitInfo, baseResource, suffix);
    initActorSound(actor, actorInitInfo, baseResource, suffix);

    if (al::isExistRail(actorInitInfo, "Rail"))
        actor->initRailKeeper(actorInitInfo, "Rail");
    
    al::initStageSwitch(actor, actorInitInfo);
    initActorClipping(actor, actorInitInfo, baseResource, suffix);
    al::initActorOcclusionKeeper(actor, baseResource, actorInitInfo, suffix);
    initActorShadowMask(actor, actorInitInfo, baseResource, suffix);
    initActorFlag(actor, baseResource, suffix);
    initActorItem(actor, actorInitInfo, baseResource, suffix);
    initActorScore(actor, baseResource, suffix);
    al::initScreenPointKeeper(actor, baseResource, actorInitInfo, suffix);
    al::initHitReactionKeeper(actor, baseResource, suffix);
    al::initActorParamHolder(actor, baseResource, suffix);
    initActorActionKeeper(actor, baseResource, suffix, actorResource);

    if (actor->getNerveKeeper() && actor->getNerveKeeper()->mActionCtrl)
        al::resetNerveActionForInit(actor);
    
    if (!actor->mSubActorKeeper)
        al::initSubActorKeeper(actor, actorInitInfo, suffix, 0);
}
