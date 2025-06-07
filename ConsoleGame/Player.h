#pragma once
#include "Army.h"
#include "Config.h"


class Player {

protected:
    int gold = Config::STARTING_GOLD;
    Army army;
    int points;

public:
    Player() = default;

    Army& getArmy();

    int getGold() const;
    void spendGold(int amount);
    void addGold(int amount);
};
