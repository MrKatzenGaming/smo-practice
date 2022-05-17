/**
 * @file ShaderProgram.h
 * @brief Defines a general shader program to compile raw shaders with macros.
 */

#pragma once

#include "agl/DisplayList.h"
#include "sead/heap.h"
#include "sead/string.h"
#include "Shader.h"

namespace agl
{
    class ShaderProgram
    {
    public:

        class VariationBuffer
        {
        public:
            void initialize(s32, sead::Heap *);
            void createMacro(s32, sead::SafeString const &, sead::SafeString const &, s32, sead::Heap *);
            void setMacroValue(s32, s32, sead::SafeString const &);
            void create(sead::Heap *);
        };

        ShaderProgram();

        virtual ~ShaderProgram();

        void cleanUp();
        void destroyLocationBuffers();
        void initializeVariation(sead::SafeString const &, s32, sead::Heap *);
        void createVariationMacro(s32, sead::SafeString const &, sead::SafeString const &, s32, sead::Heap *);
        void setVariationMacroValue(s32, s32, sead::SafeString const &);
        void createVariation(sead::Heap *);

        u64* _8;
        agl::DisplayList mShaderDisplayList;
        u32 _278;
        u32 _27C;
        u64 _280;
        u32 _288;
        u32 _28C;
        u64 _290;
        u32 _298;
        u32 _29C;
        u64 _2A0;
        u32 _2A8;
        u32 _2AC;
        u64 _2B0;
        u32 _2B8;
        u32 _2BC;
        u64 _2C0;
        u32 _2C8;
        u32 _2CC;
        u64 _2D0;
        agl::VertexShader mVertexShader;
        agl::FragmentShader mFragmentShader;
        agl::GeometryShader mGeometryShader;
        agl::ComputeShader mComputeShader;
        u8 _358[0x418-0x358]; // todo; what is here?
        u64 _418;
        u32 _420;
    };
};
