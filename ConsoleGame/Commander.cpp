#include "Commander.h"

Commander::Commander(const std::string& name, double hp, int attack, 
    int mana, int armorValue, ArmorType armorType)
    : Unit(name, hp, attack, mana, armorValue, armorType) {
}
