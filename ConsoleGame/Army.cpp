#include "Army.h"

bool Army::addNormalUnit(Unit* unit) {
    if (normalCount < Config::MAX_NORMAL_UNITS) {
        normalUnits[normalCount++] = unit;
        return true;
    }
    return false;
}

bool Army::addCommander(Commander* commander) {
    if (commanderCount < Config::MAX_COMMANDER_UNITS) {
        commanders[commanderCount++] = commander;
        return true;
    }
    return false;
}

void Army::attackAll() {
    for (int i = 0; i < normalCount; ++i) {
        if (normalUnits[i]) normalUnits[i]->attack();
    }
    for (int i = 0; i < commanderCount; ++i) {
        if (commanders[i]) commanders[i]->attack();
    }
}

void Army::useCommanderAbilities() {
    for (int i = 0; i < commanderCount; ++i) {
        if (commanders[i]) commanders[i]->useAbility();
    }
}

Army::~Army() {
    for (int i = 0; i < normalCount; ++i) {
        delete normalUnits[i];
    }
    for (int i = 0; i < commanderCount; ++i) {
        delete commanders[i];
    }
}
