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

#include "ArmyTemplate.h"

class ArmyBuilder {

    ArmyTemplate armyTemplate;

public:

	void pickAliveCommanders(Player& player);
	void pickAliveUnits(Player& player);


	int aliveUnitPicker(Player& player);
	int aliveCommanderPicker(Army& army);

};


