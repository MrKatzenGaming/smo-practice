#pragma once

class PlayerDamageKeeper
{
public:
    void activatePreventDamage();
    void dead();
    void damage(int level);
    void damageForce(int level);
};
