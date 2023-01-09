#pragma once

#include "al/actor/Placement.h"
#include "al/iuse/IUseRail.h"
#include "al/rail/RailRider.h"


namespace al {
class RailKeeper : public al::IUseRail {
public:
    RailKeeper(al::PlacementInfo const&);
    al::RailRider* getRailRider() const;

    al::RailRider* mRailRider;
};
};
