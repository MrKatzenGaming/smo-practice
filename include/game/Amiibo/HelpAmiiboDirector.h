#pragma once

#include "game/Amiibo/HelpAmiiboCoinCollect.h"

class HelpAmiiboDirector {
public:
    unsigned char gap1[0x60];
    HelpAmiiboCoinCollect* mHelpAmiiboCoinCollect;

    void appearCoinCollectEffect();
};
