/**
 * @file ResFile.h
 * @brief Resource file for models.
 */

#pragma once

#include "types.h"
#include <nn/gfx/api.h>
#include <nn/gfx/device.h>
#include <nn/gfx/memory.h>
#include <nn/util.h>

namespace nn {
namespace g3d {
class ResModel;
class ResMaterialAnim;
class ResShapeAnim;
class ResSceneAnim;
typedef void* TextureRef;

class ResFile : public nn::util::BinaryFileHeader {
public:
    static bool IsValid(void const *modelSrc);
    void Relocate();
    void Unrelocate();
    static nn::g3d::ResFile* ResCast(void *);
    s32 BindTexture(nn::g3d::TextureRef (*ref)(char const *, void *), void *);
    void ReleaseTexture();
    void Setup(nn::gfx::TDevice<nn::gfx::ApiVariation<nn::gfx::ApiType<4>, nn::gfx::ApiVersion<8>>> *);
    void Setup(nn::gfx::TDevice<nn::gfx::ApiVariation<nn::gfx::ApiType<4>,nn::gfx::ApiVersion<8>>> *, nn::gfx::TMemoryPool<nn::gfx::ApiVariation<nn::gfx::ApiType<4>, nn::gfx::ApiVersion<8>>> *, s64, u64);
    void Cleanup(nn::gfx::TDevice<nn::gfx::ApiVariation<nn::gfx::ApiType<4>, nn::gfx::ApiVersion<8>>> *);
    void Reset();

    u64 mFileNameLength;
    nn::g3d::ResModel* mModels;
    u64 mModelDictOffset;
    u64 mSkeleAnimOffset;
    u64 mSkeleAnimDictOffset;
    nn::g3d::ResMaterialAnim* mMatAnims;
    u64 mMatAnimsDictOffset;
    u64 mBoneVisiOffset;
    u64 mBoneVisiDictOffset;
    nn::g3d::ResShapeAnim* mShapeAnims;
    u64 mShapeAnimDictOffset;
    nn::g3d::ResSceneAnim* mSceneAnims;
    u64 mSceneAnimDictOffset;
    u64 mMemoryPool;
    u64 mBufferSection;
    u64 mEmbeddedFilesOffset;
    u64 mEmbeddedFilesDictOffset;
    u64 mPadding;
    u64 mStrTableOffset;
    u32 mStrTableSize;
    u16 mModelCount;
    u16 mSkeleAnimCount;
    u16 mMatAnimCount;
    u16 mBoneAnimCount;
    u16 mShapeAnimCount;
    u16 mSceneAnimCount;
    u16 mExternalFileCount;
    u8 mPad[0x6];
};
}
}
