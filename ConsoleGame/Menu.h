#pragma once
#include "Player.h"

class Menu {

public:
	int displayMainMenu();
	//bool chooseFaction();
	void displaySaveMenu(const Player& player);
	void displayLoadMenu(Player& player);
	void displayBattleResults(const Player& winner, const Player& loser);
	void displayInstructions();

};