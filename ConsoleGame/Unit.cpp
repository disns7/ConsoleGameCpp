#include "Unit.h"
#include "Config.h"
#include <iostream>
#include "Player.h"


Unit::Unit(const std::string& name, double hp, int attack, int mana, int armorValue, ArmorType armorType)
    : name(name), hp(hp), maxHP(hp), attackPower(attack), mana(mana), maxMana(mana), armorValue(armorValue) , armorType(armorType), cost(Config::GetUnitCost(name)) {
}

const void Unit::attack(Unit& target) {
    if (!isDead()) {
        std::cout << name << " attacks " << target.getName() << " for " << attackPower << " damage!\n";
        target.takeDamage(attackPower);
        onAttack(target);
    }
}

void Unit::takeDamage(int amount) {
    if (armorValue > 0) {
        hp = hp - (amount* getArmorMultiplier());
        armorValue--;
    } else {
        hp -= amount;
    }
    if (hp < 0) hp = 0;
}

void Unit::heal(int amount) {
    if (isDead()) return; 
    hp += amount;
    if (hp > maxHP) hp = maxHP;
}

void Unit::addMana(int amount)
{
    if (isDead()) return;
    mana += amount;    
    if (mana > maxMana) mana = maxMana;
}

const double Unit::getMaxHP() const
{
    return maxHP;
}

bool Unit::isDead() const {
    return hp <= 0;
}

const std::string Unit::getName() const {
    return name;
}


const double Unit::getHP() const {
    return hp;
}

const int Unit::getCost() const {
    return cost;
}

const ArmorType Unit::getArmorType() const{
    return armorType;
}

const int Unit::getArmorValue() const{
    return armorValue;
}

const void Unit::unitInfo(){
    std::cout << name << " - " << hp << " hp | " << mana << " mana | " << armorValue << " armor value.\n";
}

const double Unit::getArmorMultiplier() const {
    switch (armorType) {
    case ArmorType::Unarmored: return 1;
    case ArmorType::Leather:   return 0.75;
    case ArmorType::Medium:    return 0.5;
    case ArmorType::Heavy:     return 0.25;
    default: return 1.0;
    }
}

