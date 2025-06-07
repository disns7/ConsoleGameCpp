#pragma once
#include "Player.h"
#include "ArmyTemplate.h"

#include "DeadKnight.h"
#include "Lich.h"
#include "LordOfTerror.h"

#include "Skeleton.h"
#include "Ghost.h"
#include "Ghoul.h"
#include "Zombie.h"
#include "Revenant.h"
#include "Dibuk.h"
#include "Necromancer.h"

#include <random>

class BotArmyBuilder {
private:
    Player& botPlayer;
    ArmyTemplate armyTemplate;
    std::mt19937 rng;

    void pickDeadUnits();
    void pickDeadCommanders();

public:
    BotArmyBuilder(Player& player);
    void buildArmy();
};
