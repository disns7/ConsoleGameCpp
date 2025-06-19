#include "Healer.h"
#include "Config.h"
#include <iostream>

Healer::Healer()
    : Unit("Healer", 290, 2, 200, 6, ArmorType::Medium) {
    cost = Config::GetUnitCost("Healer");
}


std::string Healer::getType() const {
    return "Healer";
}

void Healer::onSupport(Unit& friendlyTarget) {
    if (mana >= 100 && !friendlyTarget.isDead() && friendlyTarget.getHP() < friendlyTarget.getMaxHP()-50) {     
         friendlyTarget.heal(100);
         std::cout << "Healer healed 100HP to " << friendlyTarget.getName() << "\n";
         mana -= 100;
    }
}
