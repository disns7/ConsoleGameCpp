#include "Necromancer.h"
#include "Config.h"  
#include<iostream>
#include "Skeleton.h"
#include "Player.h"


Necromancer::Necromancer()
    : Unit("Necromancer", 300, 4, 200, 4, ArmorType::Leather) {
    cost = Config::GetUnitCost("Necromancer");
}


std::string Necromancer::getType() const {
    return "Necromancer";
}

void Necromancer::specialAbility(Player& allyPlayer, Player& enemyPlayer) {
    std::cout << "Got in the special ability\n";
    if (mana == 200) {
        std::cout << "Has 200 mana\n";

        int deadCount = 0;
        for (Unit* targetUnit : enemyPlayer.getArmy().getSelectedUnits()) {
            if (targetUnit->isDead()) {
                deadCount++;
                std::cout << "One dead found\n";

            }
        }
        if (deadCount >= 3) {
            for (int i = 0; i < 3; ++i) {
                auto skeleton = std::make_unique<Skeleton>();
                allyPlayer.getArmy().addTemporaryUnit(std::move(skeleton));
                std::cout << "Created";
            }
            mana -= 200;
            std::cout << "A necromancer summoned 3 skeletons !\n";
        }
        
    }
}