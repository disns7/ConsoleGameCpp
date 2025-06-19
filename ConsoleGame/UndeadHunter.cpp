#include "UndeadHunter.h"
#include "Player.h"
#include <iostream>

UndeadHunter::UndeadHunter()
    : Commander("UndeadHunter", 2000,  75, 1500, 17, ArmorType::Heavy) {
    cost = 0;
}

std::string UndeadHunter::getType() const {
    return "UndeadHunter";
}


void UndeadHunter::useAbility(Player& allyPlayer, Player& enemyPlayer) 
{
    if (mana>=1000) {
        for (Commander* targetUnit : enemyPlayer.getArmy().getSelectedCommanders()) {
            if (!targetUnit->isDead() && mana>=1500) {
                targetUnit->takeDamage(targetUnit->getMaxHP()*targetUnit->getMaxHP());
                std::cout << "UndeadHunter has demolished a " << targetUnit->getName() << "\n";
                mana -= 1500;
            }
        }
    }
}

