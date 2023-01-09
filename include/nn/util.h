#pragma once

#include "types.h"

namespace nn {
namespace util {
s32 SNPrintf(char* s, ulong n, const char* format, ...);
s32 VSNPrintf(char* s, ulong n, const char* format, va_list arg);

struct Unorm8x4 {
    u8 elements[0x4];
};

enum CharacterEncodingResult { Success, BadLength, InvalidFormat };

CharacterEncodingResult PickOutCharacterFromUtf8String(char*, char const** str);
CharacterEncodingResult ConvertCharacterUtf8ToUtf32(u32* dest, char const* src);
CharacterEncodingResult ConvertStringUtf16NativeToUtf8(char*, s32, u16 const*, s32);
CharacterEncodingResult ConvertStringUtf8ToUtf16Native(u16*, s32, char const*, s32);

class RelocationTable {
public:
    void Relocate();
    void Unrelocate();

    s32 mMagic;
    u32 mPosition;
    s32 mSectionCount;
};

class BinaryFileHeader {
public:
    bool IsValid(s64 packedSig, s32 majorVer, s32 minorVer, s32 microVer) const;
    bool IsRelocated() const;
    bool IsEndianReverse() const;
    nn::util::RelocationTable* GetRelocationTable();

    s32 mMagic;
    u32 mSig;
    u8 mVerMicro;
    u8 mVerMinor;
    u16 mVerMajor;
    u16 mBOM;
    u8 mAlignment;
    u8 mTargetAddrSize;
    u32 mFileNameOffset;
    u16 mFlag;
    u16 mFirstBlockOffs;
    u32 mRelocationTableOffs;
    u32 mSize;
};

template <s32 size, typename T>
struct BitFlagSet {};
}  // namespace util

void ReferSymbol(void const*);
}  // namespace nn
