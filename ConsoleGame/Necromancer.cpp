#include "Necromancer.h"
#include "Config.h"  

Necromancer::Necromancer()
    : Unit("Necromancer", 300, 4, 200, 0, ArmorType::Unarmored) {
    cost = Config::GetUnitCost("Necromancer");
}


std::string Necromancer::getType() const {
    return "Necromancer";
}

