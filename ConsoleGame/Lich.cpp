#include "Lich.h"

Lich::Lich()
    : Commander("Lich", 1500, 100, 1000, 15, ArmorType::Heavy) {
    cost = 0;
}

std::string Lich::getType() const {
    return "Lich";
}

void Lich::onSupport(Unit& friendlyTarget) {
    //wuzdiga murtwi undead unity za 750 mana
}