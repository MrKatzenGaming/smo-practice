/**
 * @file ShaderCompileInfo.h
 * @brief Defines file devices and extensions.
 */

#pragma once

#include <sead/heap/seadHeap.h>
#include <sead/hostio/seadHostIONode.h>
#include <sead/container/seadPtrArray.h>
#include "Shader.h"
#include "types.h"

namespace agl {
    class ShaderCompileInfo : public sead::hostio::Node
    {
        // this value is used as an index to a table of version lists
        // on 1.2.0, located at 0x7101E80B30
        typedef s32 Target;

        ShaderCompileInfo();

        virtual ~ShaderCompileInfo();

        void destroy();
        void create(s32, s32 bufferSize, sead::Heap *);
        void clearVariation();
        void pushBackVariation(char const *, char const *);
        void calcCompileSource(agl::ShaderType, sead::BufferedSafeString *, agl::ShaderCompileInfo::Target, bool);
        sead::SafeString* getRegitserUniformBlockName(); // "RegisterUBO"

        u64 _8;
        char* mName;
        u64 _18;
        u64 _20;
        sead::PtrArrayImpl _28;
        sead::PtrArrayImpl _38;
        sead::PtrArrayImpl _48;
        sead::PtrArrayImpl _58;
    };
};
