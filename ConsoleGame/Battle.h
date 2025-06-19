#pragma once
#include "Player.h"

class Battle {
private:

public:
	void startBattle(Player& player, Player& botPlayer);

	void basicAttackCommanders(Player& attPlayer, Player& defPlayer);
	void basicAttackUnits(Player& attPlayer, Player& defPlayer);

	void specialAbbilityCommanders(Player& allyPlayer, Player& enemyPlayer);
	void specialAbbilityUnits( Player& allyPlayer,Player& enemyPlayer);

	void onSupportCommanders(Player& allyPlayer);
	void onSupportUnits(Player& allyPlayer);

	void addManaToAll(Player& player, Player& botPlayer);

	bool deadCheck(Player& player);

	void afterBattle(Player& player, Player& botPlayer);

};