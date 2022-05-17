#pragma once

#include "game/Player/PlayerCapActionHistory.h"

class PlayerActorHakoniwa;

class PlayerInput {
    public:
        bool isTriggerRollingRestartSwing() const;

        PlayerActorHakoniwa* mPlayer;
        IUsePlayerCollision* mPlayerCollider;

};
