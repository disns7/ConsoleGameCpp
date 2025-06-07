#include "Dibuk.h"
#include "Config.h"  

Dibuk::Dibuk()
    : Unit("Dibuk", 250, 15, 300, 0, ArmorType::Unarmored) {
    cost = Config::GetUnitCost("Dibuk");
}


std::string Dibuk::getType() const {
    return "Dibuk";
}

void Dibuk::onAttack(Unit& enemyTarget) {
    if (mana >= 150) {
        mana -= 150;
        enemyTarget.takeDamage(hp*0.30);
        hp *= 0.8;
    }
}