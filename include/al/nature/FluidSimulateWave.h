#pragma once

namespace agl {
class TextureSampler;
}

#include "al/hio/HioNode.h"
#include "al/nature/PartsGraphics.h"

#include <agl/TextureData.h>
#include <agl/shader/ShaderProgramArchive.h>
#include <sead/gfx/seadContext.h>
#include <sead/math/seadVector.h>
#include <sead/math/seadQuat.h>
#include <sead/prim/seadSafeString.h>

namespace al {
class PointSpriteCursor;
class UniformBlock;
class GraphicsSystemInfo;

class FluidSimulateWave : public al::PartsGraphics, public al::HioNode {
public:
    int iVar1;
    sead::FixedSafeString<256> mName;
    al::PointSpriteCursor* cursor1;
    al::PointSpriteCursor* cursor2;
    agl::ShaderProgramArchive* mShaderFluidSimulateWave;
    agl::ShaderProgramArchive* mShaderHeightMapToNormal;
    agl::ShaderProgramArchive* mShaderPointSprite2D;
    sead::GraphicsContextMRT mGraphicsContextMRT;
    agl::TextureData* tex1;
    agl::TextureData* tex2;
    agl::TextureData* tex3;
    agl::TextureData* tex4;
    agl::TextureData* mDisplacementMap;
    agl::TextureData* tex6;
    agl::TextureData* tex7;
    agl::TextureData* tex8;
    agl::TextureSampler* sampler1;
    agl::TextureSampler* sampler2;
    agl::TextureSampler* sampler3;
    agl::TextureSampler* sampler4;
    agl::TextureSampler* sampler5;
    agl::TextureSampler* sampler6;
    al::UniformBlock* block1;
    al::UniformBlock* block2;
    al::UniformBlock* block3;
    al::GraphicsSystemInfo* mGraphicsSystemInfo;
    int iVar2;
    int iVar3;
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    float fVar5;
    float fVar6;
    float fVar7;
    float fVar8;
    float fVar9;
    sead::Vector3f vVar1;
    sead::Vector3f vVar2;
    float fVar10;
    float fVar11;
    sead::Vector3f vVar3;
    sead::Quatf qVar1;
    float fVar12;
    float fVar13;
    float fVar14;
    bool bVar1;
    bool bVar2;
    bool bVar3;
    bool bVar4;
    bool bVar5;
    bool bVar6;
    unsigned int uVar1;
    int iVar4;
    bool bVar7;
    bool bVar8;
    float fVar15;
    bool bVar9;
    int iVar5;
    float fVar16;
    sead::Vector3f vVar4;
    sead::Vector3f vVar5;
    float fVar17;
    int iVar6;
    float fVar18;
    bool bVar10;
    int iVar7;


};

}