#pragma once

namespace al {
class ByamlWriter;
class ByamlIter;

class ByamlSave {
public:
    virtual void write(al::ByamlWriter*) = 0;
    virtual void read(al::ByamlIter const&) = 0;
};
}
