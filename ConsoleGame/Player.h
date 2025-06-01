#pragma once
#include "Army.h"
#include "Config.h"

class Player {

private:
    int gold = Config::STARTING_GOLD;
    Army army;

public:
    Player() = default;

    Army& getArmy();

    std::string getName() const;
    int getGold() const;
    void spendGold(int amount);
    void addGold(int amount);
};
