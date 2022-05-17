/**
 * @file Pane.h
 * @brief Base UI panel.
 */

#pragma once

#include "types.h"
#include "sead/runtime.h"

namespace nn
{
    namespace ui2d
    {
        class AnimTransform;
        class Layout;

        class Pane
        {
        public:
            Pane();
            Pane(nn::ui2d::Pane const &);

            virtual ~Pane();

            virtual sead::RuntimeTypeInfo::Interface* GetRuntimeTypeInfo() const;
            virtual s32 GetVertexColor(s32);
            virtual u8 GetColorElement(s32);
            virtual void SetColorElement(u32, u8);
            virtual u8 GetVertexColorElement(s32);
            virtual void SetVertexColorElement(u32, u8);
            virtual u32 GetMaterialCount() const;
            virtual u64* GetMaterial(s32) const;

            virtual void BindAnimation(nn::ui2d::AnimTransform *, bool, bool);
            virtual void UnbindAnimation(nn::ui2d::AnimTransform *, bool);

            void Initialize();
            void SetName(char const *);
            void SetUserData(char const *);
            void AppendChild(nn::ui2d::Pane *);
            void PrependChild(nn::ui2d::Pane *);
            void InsertChild(nn::ui2d::Pane *, nn::ui2d::Pane *);
            void RemoveChild(nn::ui2d::Pane *);
            void GetVertexPos() const;

            nn::ui2d::Pane* mParent;
            u64 _10;
            u64 _18;
            u64 _20;
            u64 _28;
            u32 mPositionX;
            u32 mPositionY;
            u32 mPositionZ;
            u32 mRotationX;
            u32 mRotationY;
            u32 mRotationZ;
            u32 mScaleX;
            u32 mScaleY;
            u32 mSizeX;
            u32 mSizeY;
            u8 mFlags; // 0x58 (pane + 0x8)
            u8 mAlpha;
            u8 mAlphaInfluence;
            u8 mOriginFlags;
            u32 _5C;
            u64 _60;
            u64 _68;
            u128 _70;
            u128 _80;
            u128 _90;
            u64 _A0;
            u64 _A8;
            void* mAnimExtUserData;
            char[0x18] mPanelName;
            u8 _D0;
            char [8] mUserData;
            u8 _D9;
            u16 _DA;
            u32 _DC;
        };
    };
};
