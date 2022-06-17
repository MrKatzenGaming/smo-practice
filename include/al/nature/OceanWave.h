#pragma once

#include "al/effect/EffectKeeper.h"
#include "al/execute/ExecuteDirector.h"
#include "al/hio/HioNode.h"
#include "al/iuse/IUseFluidSurface.h"
#include "al/nature/FluidSimulateWave.h"
#include "al/nature/PartsGraphics.h"

#include <agl/DrawContext.h>
#include <agl/shader/ShaderProgram.h>

namespace al {
class GraphicsSystemInfo;
class OrthoDepthTexture;
class ApertureMesh;
class UniformBlock;
class FogParam;
class YFogParam;

class OceanWaveTexture {

};

class OceanWave : public al::PartsGraphics, public al::IUseFluidSurface, public al::HioNode {
public:
    al::GraphicsSystemInfo* mGraphicsSystemInfo;
    al::OceanWaveTexture* mWaveTexture;
    al::FluidSimulateWave* mFluidSimulateWave;
    al::OrthoDepthTexture* tex1;
    al::OrthoDepthTexture* tex2;
    al::OrthoDepthTexture* tex3;
    al::OrthoDepthTexture* tex4;
    al::ExecuteDirector* mExecuteDirector;
    agl::DrawContext* mDrawContext;
    al::ApertureMesh* mApertureMesh;
    int iVar1;
    int iVar2;
    int iVar3;
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    float fVar5;
    al::UniformBlock* uVar1;
    int iVar4;
    float fVar6;
    float fVar7;
    float fVar8;
    float fVar9;
    float fVar10;
    float fVar11;
    float fVar12;
    float fVar13;
    float fVar14;
    float fVar15;
    float fVar16;
    float fVar17;
    float fVar18;
    float fVar19;
    float fVar20;
    float fVar21;
    float fVar22;
    float fVar23;
    float fVar24;
    float fVar25;
    float fVar26;
    float fVar27;
    float fVar28;
    float fVar29;
    float fVar30;
    bool bVar1;
    bool bVar2;
    float fVar31;
    float fVar32;
    float fVar33;
    float fVar34;
    float fVar35;
    float fVar36;
    float fVar37;
    float fVar38;
    float fVar39;
    float fVar40;
    bool bVar3;
    al::EffectKeeper* mEffectKeeper;
    const char* sVar1;
    float fVar41;
    float fVar42;
    float fVar43;
    bool bVar4;
    float fVar44;
    float fVar45;
    float fVar46;
    float fVar47;
    float fVar48;
    float fVar49;
    float fVar50;
    float fVar51;
    float fVar52;
    float fVar53;
    al::FogParam* uVar2;
    al::YFogParam* uVar3;
    float fVar54;
    float fVar55;
    unsigned char gap1[0xc];
    float fVar56;
    float fVar57;
    float fVar58;
    float fVar59;
    bool bVar5;
    float fVar60;
    float fVar61;
    bool bVar6;
    float fVar62;
    float fVar63;
    float fVar64;
    float fVar65;
    float fVar66;
    float fVar67;
    float fVar68;
    bool bVar7;
    int iVar5;
    float fVar69;
    float fVar70;
    float fVar71;
    float fVar72;
    float fVar73;
    float fVar74;
    float fVar75;
    float fVar76;
    float fVar77;
    float fVar78;
    float fVar79;
    float fVar80;
    float fVar81;
    float fVar82;
    float fVar83;
    float fVar84;
    unsigned char gap2[0xc];
    float fVar85;
    float fVar86;
    float fVar87;
    float fVar88;
    float fVar89;
    float fVar90;
    float fVar91;
    float fVar92;
    float fVar93;
    bool bVar8;
    float fVar94;
    float fVar95;
    float fVar96;
    float fVar97;
    float fVar98;
    float fVar99;
    float fVar100;
    float fVar101;
    bool bVar9;
    bool bVar10;
    bool bVar11;
    unsigned char gap3[0x8];
    float fVar102;
    float fVar103;
    bool bVar12;
    bool bVar13;
    bool bVar14;
    bool bVar15;
    bool bVar16;
    int iVar6;
    bool bVar17;
    bool bVar18;
    bool bVar19;
    agl::ShaderProgram* mShaderRenderOcean;
    agl::ShaderProgram* mShaderRenderCloudSea;
    float fVar104;
    float fVar105;
    char* mTypeName; // "Water"
    bool bVar20;
};
}