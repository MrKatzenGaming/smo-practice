#pragma once

#include <sead/prim/seadSafeString.h>

namespace sead {
class INamable
{
public:
    INamable() = default;
    explicit INamable(const SafeString& name) : mINamableName(name) {}

    const SafeString& getName() const { return mINamableName; }
    void setName(const SafeString& name) { mINamableName = name; }

private:
    SafeString mINamableName = "";
};

}  // namespace sead


