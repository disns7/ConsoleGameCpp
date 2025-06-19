#pragma once
#include "Unit.h"
#include "Config.h"



class Commander : public Unit {
public:
    Commander(const std::string& name, double hp, int attack, int mana,
    int armorValue, ArmorType armorType);
    virtual void useAbility(Player& allyPlayer, Player& enemyPlayer) {};
};
