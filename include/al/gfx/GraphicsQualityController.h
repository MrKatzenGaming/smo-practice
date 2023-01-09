#pragma once

#include "al/nerve/NerveExecutor.h"

namespace al {
class GraphicsQualityInfo;
class GraphicsSystemInfo;
class SceneCameraInfo;
class GpuPerfAreaController;

class GraphicsQualityController : public al::NerveExecutor {
public:
    bool bVar1;
    al::GraphicsQualityInfo* mGraphicsQualityInfo;
    al::GraphicsSystemInfo* mGraphicsSystemInfo;
    al::SceneCameraInfo* mSceneCameraInfo;
    al::GpuPerfAreaController* mGpuPerfAreaController;
};
}
