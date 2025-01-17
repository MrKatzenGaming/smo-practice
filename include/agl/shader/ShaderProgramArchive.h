/**
 * @file ShaderProgramArchive.h
 * @brief Defines a class wrapper for SHARCB (Shader Binary) archives.
 */

#pragma once

#include <sead/heap/seadDisposer.h>
#include <sead/heap/seadHeap.h>
#include <sead/hostio/seadHostIONode.h>

namespace agl {
    class ResBinaryShaderArchive;
    class ResShaderArchive;
    class ResShaderProgram;
    class ResShaderSource;

    class ShaderProgramArchive : public sead::IDisposer, public sead::hostio::Node
    {
    public:
        ShaderProgramArchive();

        virtual ~ShaderProgramArchive();

        void destroy();
        void createWithOption(agl::ResBinaryShaderArchive, agl::ResShaderArchive, u32, sead::Heap *);
        void destroyResFile_();
        void initialize(agl::ShaderProgramArchive *, s32, agl::ResShaderProgram, sead::Heap *);
        void updateCompileInfo();
        void setUp();
        void setUp_(bool);

        u64 _20;
        agl::ResBinaryShaderArchive* mBinaryShaderArchive;
        agl::ResShaderArchive* mResShaderArchive;
    };
};
