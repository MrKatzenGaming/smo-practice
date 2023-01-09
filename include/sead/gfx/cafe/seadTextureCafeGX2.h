#pragma once

#include <cafe.h>

#include <sead/basis/seadTypes.h>
#include <sead/gfx/seadTexture.h>
#include <sead/prim/seadRuntimeTypeInfo.h>

namespace sead {
class TextureCafeGX2 : public Texture
{
    SEAD_RTTI_OVERRIDE(TextureCafeGX2, Texture)

public:
    TextureCafeGX2() {}
    virtual ~TextureCafeGX2() {}

    virtual u32 getWidth() const;
    virtual u32 getHeight() const;

    GX2Texture* mGX2Texture;
};

}  // namespace sead


