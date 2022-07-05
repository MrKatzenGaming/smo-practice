/**
 * @file ResSceneAnim.h
 * @brief Resource file for scene animations.
 */

#pragma once

#include "BindFuncTable.h"
#include "ResFogAnim.h"
#include "ResLightAnim.h"
#include "types.h"

namespace nn {
    namespace g3d
    {
        class ResSceneAnim
        {
        public:
            s32 Bind(nn::g3d::BindFuncTable const &);
            void Release();
            void Reset();

            char mMagic[4];
            s32 mBlockOffset;
            u64 mBlockSize;
            u64 mNameOffset;
            u64 mPathOffset;
            u64 mCameraAnimOffset;
            u64 mCameraAnimDictOffset;
            nn::g3d::ResLightAnim* mLightAnims;
            u64 mLightAnimDictOffset;
            nn::g3d::ResFogAnim* mFogAnims;
            u64 mFogAnimDictOffset;
            u64 mUserDataOffset;
            u64 mUserDataDictOffset;
            u16 mUserDataCount;
            u16 mCameraAnimCount;
            u16 mLightAnimCount;
            u16 mFogAnimCount;
        };
    };
};
