#pragma once

namespace al {

class ActorInitInfo;

class ISceneObj {
public:
    virtual const char* getSceneObjName() const;
    virtual ~ISceneObj();
    virtual void initAfterPlacementSceneObj(ActorInitInfo const&);
    virtual void initSceneObj();
};

}
