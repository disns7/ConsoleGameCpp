#include "Lich.h"
#include <iostream>


Lich::Lich()
    : Commander("Lich", 1500, 100, 1000, 15, ArmorType::Heavy) {
    cost = 0;
}

std::string Lich::getType() const {
    return "Lich";
}

void Lich::onSupport(Unit& friendlyTarget) {
    if (friendlyTarget.isDead() && mana >= 1000) {
        friendlyTarget.revive(friendlyTarget.getMaxHP());
        std::cout << "\nLich revived a " << friendlyTarget.getName() << "\n";
        mana -= 1000;
    }
}