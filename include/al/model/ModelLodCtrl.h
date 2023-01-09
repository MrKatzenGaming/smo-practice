#pragma once

#include "al/byaml/ByamlIter.h"
#include "al/iuse/IUseCamera.h"
#include <sead/container/seadPtrArray.h>
#include <sead/math/seadBoundBox.h>
#include <sead/math/seadMatrix.h>
#include <sead/math/seadVector.h>

namespace al {
class DistanceLevelParam;
class GraphicsQualityInfo;

class ModelLodCtrl : public al::IUseCamera {
public:
    ModelLodCtrl(al::IUseCamera*, sead::Vector3f const*, sead::Matrix34f const*, sead::Vector3f const*, sead::BoundBox3f const&, int);

    virtual CameraDirector* getCameraDirector() const override;
    void init(al::ByamlIter const&);

    sead::Vector3f* vVar1;
    sead::Matrix34f* mVar1;
    sead::Vector3f* vVar2;
    unsigned char gap[0x18];
    al::DistanceLevelParam* mModelLod;
    al::DistanceLevelParam* mShadowLod;
    al::DistanceLevelParam* mMaterialLod;
    int mShadowLodOffset;
    int iVar1;
    int mJudgeType;
    int iVar2;
    bool mIsSetShadowLod;
    bool bVar1;
    bool bVar2;
    bool mIsEnableMaterialLod;
};

class ModelLodAllCtrl {
public:
    ModelLodAllCtrl(al::GraphicsQualityInfo const*);
    void endInit();
    void registerLodCtrl(al::ModelLodCtrl*);
    void update();
    void updateLodAll();

    bool bVar1;
    bool bVar2;
    sead::PtrArray<al::ModelLodCtrl> mModelLodCtrls;
    al::GraphicsQualityInfo* mGraphicsQualityInfo;
    float fVar1;
};
}
