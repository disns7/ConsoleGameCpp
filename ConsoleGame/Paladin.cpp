#include "Paladin.h"
#include <iostream>

Paladin::Paladin()
    : Commander("Paladin", 5000, 250, 3000, 20, ArmorType::Heavy) {
    cost = 0;
}

std::string Paladin::getType() const {
    return "Paladin";
}

void Paladin::onSupport(Unit& friendlyTarget) {

    if (friendlyTarget.isDead() && mana >=500.0 ) {
        friendlyTarget.revive(friendlyTarget.getMaxHP());
        std::cout << "Paladin revived a " << friendlyTarget.getName() << "\n";
        mana -= 500;
    }
}