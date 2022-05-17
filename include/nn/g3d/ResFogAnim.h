#pragma once

#include "types.h"

namespace nn
{
    namespace g3d
    {
        class ResFogAnim
        {
        public:
            char mMagic[4];
            u16 mFlags;
            u16 mPad;
            s32 mNumFrames;
            u8 mNumCurves;
            u8 mIdxDistanceAttnFunc;
            u16 mNumUserData;
            u32 mSizeBaked;
            u64 mNameOffset;
            u64 mFuncNameOffset;
            
        };
    };
};
