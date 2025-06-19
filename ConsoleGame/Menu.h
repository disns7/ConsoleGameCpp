#pragma once
#include "Player.h"

class Menu {

public:
	int displayMainMenu();
	//bool chooseFaction();
	void displaySaveMenu(const Player& player);
	void displayLoadMenu(Player& player);

	int displayBetweenBattlesMenu();

	void displayInstructions();

	void displaySelectionInstructions(Player& player);

	void displayEndGame(Player& player, Player& botPlayer);
};