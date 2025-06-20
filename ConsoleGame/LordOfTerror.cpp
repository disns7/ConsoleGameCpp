#include "LordOfTerror.h"
#include<iostream>
#include "Ghoul.h"
#include "Necromancer.h"
#include "Player.h"

LordOfTerror::LordOfTerror()
    : Commander("LordOfTerror", 3000, 200, 2000, 20, ArmorType::Heavy) {
    cost = 0;
}

std::string LordOfTerror::getType() const {
    return "LordOfTerror";
}

void LordOfTerror::useAbility(Player& allyPlayer, Player& enemyPlayer)
{
    while (mana >= 400) {
        if (mana >= 500) {
            auto ghoul = std::make_unique<Ghoul>();
            allyPlayer.getArmy().addTemporaryUnit(std::move(ghoul));
            std::cout << "The Lord Of Terror has summoned a GHOUL!\n";
            mana -= 500;
        }
        auto necro = std::make_unique<Necromancer>();
        allyPlayer.getArmy().addTemporaryUnit(std::move(necro));
        std::cout << "The Lord Of Terror has summoned a NECROMANCER!\n";
        mana -= 400;
    }
}