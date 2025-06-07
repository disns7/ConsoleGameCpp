#include "UndeadHunter.h"

UndeadHunter::UndeadHunter()
    : Commander("UndeadHunter", 2000,  75, 1500, 17, ArmorType::Heavy) {
    cost = 0;
}

std::string UndeadHunter::getType() const {
    return "UndeadHunter";
}

void UndeadHunter::onAttack(Unit& enemyTarget) {
    // unishtojawa enemy commander ako ima takuw za 1000 mana
}