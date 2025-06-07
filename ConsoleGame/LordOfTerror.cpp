#include "LordOfTerror.h"

LordOfTerror::LordOfTerror()
    : Commander("LordOfTerror", 3000, 200, 2000, 20, ArmorType::Heavy) {
    cost = 0;
}

std::string LordOfTerror::getType() const {
    return "LordOfTerror";
}

void LordOfTerror::onSupport(Unit& friendlyTarget) {
    //da spawnwa necro za 400 mana i ghoul za 500
}