#pragma once

#include "al/iuse/IUseAreaObj.h"
#include "al/area/AreaObjGroup.h"

namespace al {
class AreaObjFactory;
class AreaObjMtxConnecterHolder;

class AreaObjDirector {
public:
    AreaObjGroup* getAreaObjGroup(const char*) const;

    AreaObjFactory* mFactory;
    AreaObjMtxConnecterHolder* mMtxConnecterHolder;
    AreaObjGroup** mAreaGroups;
    int mAreaGroupCount;
};

}
