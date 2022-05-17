#pragma once

#include "al/sensor/HitSensor.h"
#include "PlayerInput.h"
#include "PlayerState.h"

class EquipmentInfo;
class IPlayerModelChanger;
class PlayerModelHolder;

class PlayerEquipmentUser {
public:
    PlayerEquipmentUser(const PlayerInput* input, const PlayerModelHolder* model_holder,
                        const IPlayerModelChanger* model_changer);

    void startEquip(al::HitSensor* equipment_sensor, al::HitSensor* source_sensor,
                    const EquipmentInfo* info);
    void cancelEquip();
    void endEquip();
    void noticeDamage();

private:
    al::HitSensor* mSourceSensor = nullptr;
    al::HitSensor* mEquipmentSensor = nullptr;
    const EquipmentInfo* mEquipmentInfo = nullptr;
    const PlayerInput* mPlayerInput;
    const PlayerModelHolder* mPlayerModelHolder;
    const IPlayerModelChanger* mPlayerModelChanger;
    PlayerStateRolling* mPlayerStateRolling = nullptr;
};
