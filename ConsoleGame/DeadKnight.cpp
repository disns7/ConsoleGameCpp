#include "DeadKnight.h"
#include <iostream>

DeadKnight::DeadKnight()
    : Commander("DeadKnight", 2500, 150, 1000, 15, ArmorType::Heavy) {
    cost = 0;
}

std::string DeadKnight::getType() const {
    return "DeadKnight";
}

void DeadKnight::onSupport(Unit& friendlyTarget) {
    if (mana >= 400 && !friendlyTarget.isDead() && friendlyTarget.getHP() < friendlyTarget.getMaxHP() - 150) {
        friendlyTarget.heal(250);
        std::cout << "Healer healed 100HP to " << friendlyTarget.getName() << "\n";
        mana -= 400;
    }
}