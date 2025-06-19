#include "Wizard.h"
#include "Config.h" 
#include <iostream>

Wizard::Wizard()
    : Unit("Wizard", 325, 35, 200, 3, ArmorType::Leather) {
    cost = Config::GetUnitCost("Wizard");
}


std::string Wizard::getType() const {
    return "Wizard";
}

void Wizard::onAttack(Unit& enemyTarget) {
    if (mana >= 200) {
        mana -= 200;
        enemyTarget.takeDamage(attackPower*2);
        std::cout << "\nWizard attacks " << enemyTarget.getName() << " for " << attackPower * 2 * getArmorMultiplier() << " damage.\n";
    }
}