#pragma once

#include "CameraPoseUpdater.h"
#include "al/iuse/IUseExecutor.h"

namespace al
{
class CameraDirector : public al::IUseExecutor {
    public:
        void startSnapShotMode(bool);
        al::CameraPoseUpdater *getPoseUpdater(void);
        float getSceneFovyDegree(void) const;

        unsigned char padding[0x30-0x02];
        float sceneFovyDegree;
        // 0xBC float farClipDistance
        // 0xB8 float nearClipDistance
};
};
