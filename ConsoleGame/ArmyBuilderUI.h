#pragma once
#include <iostream>

#include "Paladin.h"
#include "BladeDancer.h"
#include "UndeadHunter.h"

#include "Archer.h"
#include "Infantry.h"
#include "Knight.h"
#include "Healer.h"
#include "Wizard.h"

#include "Menu.h"

#include "ArmyTemplate.h"

class ArmyBuilder {

    ArmyTemplate armyTemplate;
	Menu menu;

public:

	void pickAliveCommanders(Player& player);
	void pickAliveUnits(Player& player);

	int aliveUnitPicker(size_t unitsLeftToAdd, int playerGold);
	int aliveCommanderPicker(size_t commandersLeftToAdd);

	void selectAliveArmy(Player& player);
	void selectAliveUnits(Player& player, std::string unitName, int unitCount);
	void selectAliveCommanders(Player& player, std::string commanderName);

	void removeFromSelectedAliveUnits(Player& player);
};


