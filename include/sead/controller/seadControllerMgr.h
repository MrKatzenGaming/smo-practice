#pragma once

#include <sead/container/seadOffsetList.h>
#include <sead/container/seadPtrArray.h>
#include <sead/controller/seadController.h>
#include <sead/framework/seadCalculateTask.h>
#include <sead/framework/seadTaskMgr.h>
#include <sead/framework/seadTaskParameter.h>
#include <sead/heap/seadDisposer.h>
#include <sead/prim/seadRuntimeTypeInfo.h>

namespace sead {

class ControlDevice;
class Controller;
class ControllerAddon;

class ControllerMgr : public CalculateTask
{
    SEAD_TASK_SINGLETON(ControllerMgr)
    SEAD_RTTI_OVERRIDE(ControllerMgr, CalculateTask)

private:
    class ConstructArg : public TaskConstructArg
    {
    public:
        ConstructArg() : TaskConstructArg(), mHeapArray() { heap_array = &mHeapArray; }

    private:
        HeapArray mHeapArray;
    };

public:
    struct Parameter : public TaskParameter
    {
        SEAD_RTTI_OVERRIDE(Parameter, TaskParameter)

    public:
        s32 controllerMax;
        IDelegate1<ControllerMgr*>* proc;
    };

public:
    ControllerMgr();
    explicit ControllerMgr(const TaskConstructArg& arg);
    ~ControllerMgr() override;

    void prepare() override;
    void calc() override;

    void initialize(s32 controller_max, Heap* heap);
    void finalize();

    void initializeDefault(Heap* heap);
    void finalizeDefault();

    // TODO: Add/remove devices & controllers

    Controller* getControllerByOrder(ControllerDefine::ControllerId id, s32 index) const;
    ControlDevice* getControlDevice(ControllerDefine::DeviceId id) const;
    ControllerAddon* getControllerAddon(s32 index, ControllerDefine::AddonId id) const;
    ControllerAddon* getControllerAddonByOrder(s32 controller_index,
                                               ControllerDefine::AddonId addon_id,
                                               int addon_index) const;

    template <typename T>
    T getControllerByOrderAs(s32 index) const;
    template <typename T>
    T getControlDeviceAs() const;
    template <typename T>
    T getControllerAddonAs(s32 index) const;

    s32 findControllerPort(const Controller* controller) const;

    DelegateThread* getFramework() const;

    Controller* getController(int port) { return mControllers[port]; }

private:
    OffsetList<ControlDevice> mDevices;
    PtrArray<Controller> mControllers;
};
}
