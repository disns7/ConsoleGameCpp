#include "Paladin.h"

Paladin::Paladin()
    : Commander("Paladin", 5000, 250, 3000, 20, ArmorType::Heavy) {
    cost = 0;
}

std::string Paladin::getType() const {
    return "Paladin";
}

void Paladin::onSupport(Unit& friendlyTarget) {
    //heal/revive
}