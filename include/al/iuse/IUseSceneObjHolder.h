#pragma once

#include "al/scene/SceneObjHolder.h"

namespace al {

class IUseSceneObjHolder {
public:
    virtual al::SceneObjHolder* getSceneObjHolder() const = 0;
    static const char* sSceneObjName;
};

}
