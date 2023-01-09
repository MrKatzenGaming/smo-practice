#pragma once

#include "al/gfx/GraphicsQualityController.h"
#include "al/system/Resource.h"

#include <agl/DrawContext.h>
#include <agl/utl/aglParameter.h>
#include <agl/utl/aglParameterIO.h>
#include <agl/utl/aglParameterObj.h>
#include <nn/g3d/ViewVolume.h>
#include <sead/container/seadPtrArray.h>
#include <sead/gfx/seadCamera.h>

namespace al {
class BloomDirector;
class CubeMapDirector;
class DirectionalLightKeeper;
class GraphicsAreaDirector;
class GraphicsPresetDirector;
class DemoGraphicsController;
class RadialBlurDirector;
class PrePassLightKeeper;
class ShaderEnvTextureKeeper;
class ShadowDirector;
class DepthOfFieldDrawer;
class ShaderMirrorDirector;
class GraphicsParamRequesterImpl;
class FlareFilterDirector;
class GodRayDirector;
class FogDirector;
class OccludedEffectDirector;
class LightStreakDirector;
class HdrCompose;
class SSIIKeeper;
class PrimitiveOcclusion;
class OceanWave;
class RandomTextureKeeper;
class WorldAODirector;
class PointSpriteCursorHolder;
class MaterialLightDirector;
class MaterialCategoryKeeper;
class SkyDirector;
class ShaderHolder;
class OcclusionCullingJudge;
class VignettingDrawer;
class CameraBlurController;
class ThunderRenderKeeper;
class StarrySky;
class NoiseTextureKeeper;
class CloudRenderKeeper;
class GpuMemAllocator;
class FootPrintTextureKeeper;
class ProgramTextureKeeper;
class RippleTextureKeeper;
class ViewRenderer;
class SubCameraRenderer;
class TemporalInterlace;
class PeripheryRendering;
class PostProcessingFilter;
class GBufferArray;
class Projection;
class FilterAA;
class AtmosScatter;
class AtmosScatterDrawer;
class GraphicsParamFilePath;
class UniformBlock;
class AreaObjDirector;
class ExecuteDirector;
class EffectSystem;
class SceneCameraInfo;
class VastGridMeshDirector;
class FullScreenTriangle;
class ReducedBufferRenderer;
class ModelOcclusionCullingDirector;
class ModelLodAllCtrl;
class ModelShaderHolder;
class PrepassTriangleCulling;
class ApplicationMessageReceiver;

class GraphicsInitArg {
public:
    int iVar1;
    bool mIsUsingCubeMapAtmosScatter;
    int mDisplayWidth;
    int mDisplayHeight;
    int iVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    unsigned char gap1[0x18];
    float fVar1;
    agl::DrawContext* mDrawContext;
};

class GraphicsSystemInfo {
public:
    unsigned char gap1[0x20];
    al::GraphicsInitArg mGraphicsInitArg;
    al::BloomDirector* mBloomDirector;
    al::CubeMapDirector* mCubeMapDirector;
    al::DirectionalLightKeeper* mDirectionalLightKeeper;
    al::GraphicsAreaDirector* mGraphicsAreaDirector;
    al::GraphicsPresetDirector* mGraphicsPresetDirector;
    al::DemoGraphicsController* mDemoGraphicsController;
    al::RadialBlurDirector* mRadialBlurDirector;
    al::PrePassLightKeeper* mPrePassLightKeeper;
    al::ShaderEnvTextureKeeper* mShaderEnvTextureKeeper;
    al::ShadowDirector* mShadowDirector;
    al::DepthOfFieldDrawer* mDepthOfFieldDrawer;
    al::GraphicsQualityController* mGraphicsQualityController;
    al::ShaderMirrorDirector* mShaderMirrorDirector;
    al::GraphicsParamRequesterImpl* mRequesterSSAO;
    al::GraphicsParamRequesterImpl* mRequesterColorCorrection;
    al::FlareFilterDirector* mFlareFilterDirector;
    al::GodRayDirector* mGodRayDirector;
    al::FogDirector* mFogDirector;
    al::OccludedEffectDirector* mOccludedEffectDirector;
    al::LightStreakDirector* mLightStreakDirector;
    al::HdrCompose* mHdrCompose;
    al::SSIIKeeper* mSSIIKeeper;
    al::PrimitiveOcclusion* mPrimitiveOcclusion;
    nn::g3d::ViewVolume mViewVolume;
    unsigned char gap2[0x8];
    al::OceanWave* mOceanWave;
    al::RandomTextureKeeper* mRandomTextureKeeper;
    al::WorldAODirector* mWorldAODirector;
    al::PointSpriteCursorHolder* mPointSpriteCursorHolder;
    al::MaterialLightDirector* mMaterialLightDirector;
    al::MaterialCategoryKeeper* mMaterialCategoryKeeper;
    al::SkyDirector* mSkyDirector;
    al::ShaderHolder* mShaderHolder;
    al::OcclusionCullingJudge* mOcclusionCullingJudge;
    al::VignettingDrawer* mVignettingDrawer;
    al::CameraBlurController* mCameraBlurController;
    al::ThunderRenderKeeper* mThunderRenderKeeper;
    al::StarrySky* mStarrySky;
    al::NoiseTextureKeeper* mNoiseTextureKeeper;
    al::CloudRenderKeeper* mCloudRenderKeeper;
    al::GpuMemAllocator* mGpuMemAllocator;
    al::FootPrintTextureKeeper* mFootPrintTextureKeeper;
    al::ProgramTextureKeeper* mProgramTextureKeeper;
    al::RippleTextureKeeper* mRippleTextureKeeper;
    sead::PtrArrayImpl* arr1;
    al::ViewRenderer* mViewRenderer;
    al::SubCameraRenderer* mSubCameraRenderer;
    al::TemporalInterlace* mTemporalInterlace;
    al::PeripheryRendering* mPeripheryRendering;
    al::PostProcessingFilter* mPostProcessingFilter;
    al::GBufferArray* mGBufferArray;
    sead::Camera* mDrawEnvCamera;
    al::Projection* mDrawEnvProjection;
    int iVar1;
    int iVar2;
    al::FilterAA* mFilterAA;
    al::AtmosScatter* mAtmosScatter;
    al::AtmosScatterDrawer* mAtmosScatterDrawer;
    al::GraphicsParamFilePath* mFilePathaglgfx;
    agl::utl::IParameterIO mGraphicsSystemParam;
    agl::utl::IParameterObj uVar1;
    agl::utl::Parameter<int> mAreaFindMode;
    agl::utl::Parameter<int> mAtmosScatterType;
    agl::utl::Parameter<bool> mIsUsingUpdateAtmosCubeMap;
    agl::utl::Parameter<bool> mIsUsingOceanWave;
    agl::utl::Parameter<int> mOccGroupNum;
    agl::utl::IParameterIO mProjectParam;
    agl::utl::IParameterObj uVar2;
    agl::utl::Parameter<bool> mIsUsingTemporal;
    agl::utl::Parameter<bool> mIsUsingPeriphery;
    agl::utl::Parameter<bool> mIsUsingStarrySky;
    agl::utl::Parameter<float> mCubeMapIntensityPower;
    agl::utl::Parameter<float> mCubeMapIntensityRange;
    agl::utl::Parameter<float> mLineLightAntiArtifact;
    agl::utl::Parameter<float> mMinRoughnessGGX;
    agl::utl::Parameter<float> mSphereLightDiffuseAdd;
    agl::utl::Parameter<float> mSpecularScale;
    agl::utl::Parameter<float> mLightUnitScale;
    agl::utl::Parameter<float> mLightColorScale;
    al::UniformBlock* uVar3;
    al::Resource* mStageResource;
    al::AreaObjDirector* mAreaObjDirector;
    al::ExecuteDirector* mExecuteDirector;
    al::EffectSystem* mEffectSystem;
    al::SceneCameraInfo* mSceneCameraInfo;
    unsigned char gap3[0x8];
    sead::ListNode mPartsGraphics;
    int mPartsGraphicsCount;
    al::VastGridMeshDirector* mVastGridMeshDirector;
    al::FullScreenTriangle* mFullScreenTriangle;
    unsigned char gap4[0x8];
    al::ReducedBufferRenderer* mReducedBufferRenderer;
    al::ModelOcclusionCullingDirector* mModelOcclusionCullingDirector;
    al::ModelLodAllCtrl* mModelLodAllCtrl;
    al::ModelShaderHolder* mModelShaderHolder;
    al::PrepassTriangleCulling* mPrepassTriangleCulling;
    unsigned char gap5[0x8];
    al::ApplicationMessageReceiver* mApplicationMessageReceiver;
    unsigned char gap6[0x8];
};
}
