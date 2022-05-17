#pragma once

#include "al/hio/HioNode.h"

namespace al {
class ExecutorListBase : public al::HioNode {
public:
    virtual ~ExecutorListBase();
    virtual void executeList() const;
    virtual bool isActive() const;

    const char* mName;
};
}
