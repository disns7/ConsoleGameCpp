#include "Config.h"
#include <cstring>

const std::unordered_map<string, int> Config::UNIT_COSTS = {
    {"Paladin", 150},
    {"Knight", 100},
    {"Archer", 75},
    {"Necromancer", 150},
    {"Lich", 120},
    {"Zombie", 50}
};