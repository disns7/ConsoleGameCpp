#pragma once
#include <string>

class Config {
public:

    static constexpr int STARTING_GOLD = 2000;
    static constexpr int BONUS_GOLD_PER_DUEL = 1000;
    static constexpr int MAX_NORMAL_UNITS = 10;
    static constexpr int MAX_COMMANDER_UNITS = 5;
    

    static int GetUnitCost(const std::string& unitName) {
        if (unitName == "Infantry") return 250;
        if (unitName == "Archer") return 300;
        if (unitName == "Knight") return 700;
        if (unitName == "Healer") return 150;
        if (unitName == "Wizard") return 400;

        if (unitName == "Skeleton") return 100;
        if (unitName == "Ghoul") return 250;
        if (unitName == "Necromancer") return 400;
        if (unitName == "Zombie") return 300;
        if (unitName == "Dibbuk") return 300;
        if (unitName == "Revenant") return 300;
        if (unitName == "Ghost") return 500;
        return 99999; 
    }
};
