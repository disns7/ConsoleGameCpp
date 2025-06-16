#include "Healer.h"
#include "Config.h"  

Healer::Healer()
    : Unit("Healer", 290, 2, 200, 0, ArmorType::Unarmored) {
    cost = Config::GetUnitCost("Healer");
}


std::string Healer::getType() const {
    return "Healer";
}

void Healer::onSupport(Unit& friendlyTarget) {
    if (mana >= 100 && !friendlyTarget.isDead()) {     
         friendlyTarget.heal(100);
         mana -= 100;
    }
}
