#pragma once
#include <iostream>
#include "Config.h"
#include "Army.h"
#include "Unit.h"
#include "Player.h"

#include "Archer.h"
#include "Infantry.h"
#include "Knight.h"
#include "Healer.h"


class ArmyBuilder {

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

	void pickCommanders(Army& army);
	void pickUnits(Player& player);


	int unitPicker(Player& player);
	int commanderPicker(Army& army);

};


