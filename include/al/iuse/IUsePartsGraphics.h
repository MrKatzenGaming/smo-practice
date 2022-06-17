#pragma once

namespace al {
class GraphicsCopyInfo;
class GraphicsComputeInfo;
class GraphicsRenderInfo;
class GraphicsUpdateInfo;
class GraphicsCalcGpuInfo;
class RenderVariables;

class IUsePartsGraphics {
public:
    virtual void finalize() = 0;
    virtual void endInit() = 0;
    virtual void doCommandBufferCopy(al::GraphicsCopyInfo const*) const = 0;
    virtual void doComputeShader(al::GraphicsComputeInfo const*) const = 0;
    virtual void drawSystem(al::GraphicsRenderInfo const*) const = 0;
    virtual void update(al::GraphicsUpdateInfo const&) = 0;
    virtual void calcGpu(al::GraphicsCalcGpuInfo const&) = 0;
    virtual void drawGBufferAfterSky(al::GraphicsRenderInfo const&) const = 0;
    virtual void drawForward(al::GraphicsRenderInfo const&, al::RenderVariables const&) const = 0;
    virtual void drawDeferred(al::GraphicsRenderInfo const&) const = 0;
    virtual void drawLdr(al::GraphicsRenderInfo const&) const = 0;
    virtual void drawIndirect(al::GraphicsRenderInfo const&, al::RenderVariables const&) const = 0;
    virtual void drawCubemap(al::GraphicsRenderInfo const&) const = 0;
    virtual const char* getName() const = 0;
};
}