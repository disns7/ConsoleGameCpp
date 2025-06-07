#pragma once
#include "Player.h"
#include <iostream>       
#include <stdexcept>

class ArmyTemplate {

public:
    template <typename T>
    void tryAddUnit(Player& player, const std::string& unitName) {
        int cost = Config::GetUnitCost(unitName);
        try {
            player.spendGold(cost);
            player.getArmy().addUnit(std::make_unique<T>());
        }
        catch (const std::runtime_error& e) {
            std::cout << "Failed to add " << unitName << ": " << e.what() << '\n';
        }
    }

    template <typename T>
    void tryAddCommander(Player& player, const std::string& commanderName) {
        try {
            player.getArmy().addCommander(std::make_unique<T>());
        }
        catch (const std::runtime_error& e) {
            std::cout << "Failed to add " << commanderName << ": " << e.what() << '\n';
        }
    }

};