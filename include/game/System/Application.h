#pragma once

#include "al/gfx/DrawSystemInfo.h"
#include "al/system/AccountHolder.h"
#include "al/system/SystemKit.h"
#include "al/system/GameFrameworkNx.h"
#include <sead/heap/seadDisposer.h>

class Application : public sead::IDisposer {
public:
    static const Application* sInstance;

    al::SystemKit* mSystemKit;
    al::GameFrameworkNx *mFramework;
    al::DrawSystemInfo* mDrawSystemInfo;
    al::AccountHolder* mAccountHolder;
};
// const Application *Application::sInstance;
