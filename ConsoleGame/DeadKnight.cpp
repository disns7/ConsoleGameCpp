#include "DeadKnight.h"

DeadKnight::DeadKnight()
    : Commander("DeadKnight", 2500, 150, 1000, 15, ArmorType::Heavy) {
    cost = 0;
}

std::string DeadKnight::getType() const {
    return "DeadKnight";
}

void DeadKnight::onSupport(Unit& friendlyTarget) {
    //heal za 350 mana? 25% shans za spawn sled smurt na knight
}