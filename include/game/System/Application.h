#pragma once

#include "al/system/AccountHolder.h"
#include "al/system/SystemKit.h"
#include "game/System/GameFrameworkNx.h"
#include <sead/heap/seadDisposer.h>

class Application : public sead::IDisposer {
public:
    static const Application* sInstance;

    al::SystemKit* mSystemKit;
    al::GameFrameworkNx *mFramework;
    void* gap1;
    al::AccountHolder* mAccountHolder;
};
// const Application *Application::sInstance;
