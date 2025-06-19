#pragma once

#include "Commander.h"

class LordOfTerror : public Commander {
public:
    LordOfTerror();
    std::string getType() const override;
    void useAbility(Player& allyPlayer, Player& enemyPlayer) override;

};