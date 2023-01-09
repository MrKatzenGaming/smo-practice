#include "smo/tas.h"
#include <mem.h>

void smo::TasHolder::update()
{
    if (!isRunning)
    {
        if (startPending)
        {
            isRunning = true;
            curFrame = 0;
            startPending = false;
        }
        return;
    }
    if (curFrame + 1 >= frameCount) stop();
    curFrame++;
}

void smo::TasHolder::start()
{
    isRunning = true;
}

void smo::TasHolder::stop()
{
    curFrame = 0;
    isRunning = false;
}

void smo::TasHolder::setScriptName(char* name)
{
    if (scriptName) dealloc(scriptName);
    scriptName = name;
}
