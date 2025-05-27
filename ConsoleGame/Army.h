#pragma once

#include "Unit.h"
#include "Commander.h"
#include "Config.h"

class Army {
private:
    Unit* normalUnits[Config::MAX_NORMAL_UNITS] = { nullptr };
    Commander* commanders[Config::MAX_COMMANDER_UNITS] = { nullptr };
    int normalCount = 0;
    int commanderCount = 0;

public:
    bool addNormalUnit(Unit* unit);
    bool addCommander(Commander* commander);
    void attackAll();
    void useCommanderAbilities();
    ~Army();
};
