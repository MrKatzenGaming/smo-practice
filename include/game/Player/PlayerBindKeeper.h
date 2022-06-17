#pragma once

#include "al/sensor/HitSensor.h"

class PlayerBindableSensorList;
class IUsePlayerPuppet;

class PlayerBindKeeper {
public:
    al::HitSensor* sensor1;
    al::HitSensor* sensor2;
    PlayerBindableSensorList* mBindableSensorList;
    IUsePlayerPuppet* mPlayerPuppet;
    int mInvalidTimer;
    bool bVar1;
};
