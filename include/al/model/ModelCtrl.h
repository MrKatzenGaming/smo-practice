#pragma once

#include "al/dither/DitherAnimator.h"
#include "al/model/ModelLodCtrl.h"
#include "al/model/ModelOcclusionQuery.h"
#include <nn/gfx/api.h>
#include <nn/gfx/memory.h>
#include <nn/g3d/ModelObj.h>
#include <sead/math/seadMatrix.h>
#include <sead/math/seadVector.h>

namespace agl {
class UniformBlock;
}

namespace al {
class GpuMemAllocator;
class ModelShaderHolder;
class ModelMaterialCategory;
class ModelDisplayListHolder;
class ShadowDirector;
class PrepassTriangleCulling;
class Resource;
class ModelOcclusionCullingDirector;

class ModelCtrl {
public:
    nn::g3d::ModelObj* mModelObj;
    void* uVar1;
    GpuMemAllocator* mGpuMemAllocator;
    ModelShaderHolder* mShaderHolder;
    int iVar1;
    nn::gfx::MemoryPoolImpl<nn::gfx::ApiVariation<nn::gfx::ApiType<4>, nn::gfx::ApiVersion<8>>> mMemoryPool;
    void* uVar2;
    agl::UniformBlock** mUniformBlocks;
    int iVar2;
    int iVar3;
    bool mIsDirtyTexture;
    bool bVar1;
    bool bVar2;
    bool bVar3;
    bool bVar4;
    bool bVar5;
    bool bVar6;
    bool bVar7;
    bool bVar8;
    bool bVar9;
    al::GraphicsQualityInfo* mGraphicsQualityInfo;
    float mAlphaMask;
    sead::Vector2f mUvOffset;
    sead::Matrix44f mProjMtx0;
    sead::Matrix44f mProjMtx1;
    sead::Matrix44f mProjMtx2;
    sead::Matrix44f mProgProjMtx0;
    sead::Matrix44f mProgProjMtx1;
    sead::Matrix44f mProgProjMtx2;
    sead::Matrix44f mProgProjMtx3;
    float mProgConstant0;
    float mProgConstant1;
    float mProgConstant2;
    float mProgConstant3;
    float mProgConstant4;
    float mProgConstant5;
    float mProgConstant6;
    float mProgConstant7;
    float mNormalAxisXScale;
    al::ModelLodCtrl* mLodCtrl;
    void* uVar3;
    al::DitherAnimator* mDitherAnimator;
    al::ModelMaterialCategory* mMaterialCategory;
    al::ModelDisplayListHolder* mDisplayListHolder;
    bool bVar10;
    bool bVar11;
    al::ShadowDirector* mShadowDirector;
    al::PrepassTriangleCulling* mPrepassTriangleCulling;
    bool bVar12;
    bool bVar13;
    int mCalcViewCore;
    al::Resource* uVar4;
    al::Resource* uVar5;
    void* uVar6;
    sead::Matrix34f mVar1;
    sead::Vector3f vVar1;
    void* uVar7;
    sead::Matrix34f* pmVar1;
    sead::Matrix34f* pmVar2;
    sead::Matrix44f* pmVar3;
    sead::Matrix44f* pmVar4;
    al::ModelOcclusionQuery* mOcclusionQuery;
    al::ModelOcclusionCullingDirector* mOcclusionCullingDirector;
    void* uVar8;

};
}
