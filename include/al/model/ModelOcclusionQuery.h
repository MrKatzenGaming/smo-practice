#pragma once

namespace al {
class LiveActor;
class Resource;

class ModelOcclusionQuery {
public:
    static ModelOcclusionQuery* tryCreate(al::LiveActor*, al::Resource*, const char*);
};
}
