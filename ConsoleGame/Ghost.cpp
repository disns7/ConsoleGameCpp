#include "Ghost.h"
#include "Config.h"  
#include <iostream>

Ghost::Ghost()
    : Unit("Ghost", 1,  0, 0, 0, ArmorType::Unarmored) {
    cost = Config::GetUnitCost("Ghost");
}


std::string Ghost::getType() const {
    return "Ghost";
}

void Ghost::onSupport(Unit& friendlyTarget) {
    if (friendlyTarget.getHP() < friendlyTarget.getMaxHP()-250){
        friendlyTarget.heal(300);
        std::cout << "\nA ghost gave his life to heal a " << friendlyTarget.getName() << "\n";
        this->takeDamage(2);
    }
}