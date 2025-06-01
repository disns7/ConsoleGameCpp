#include "Player.h"
#include <stdexcept>


void Player::spendGold(int amount){
	if (amount > gold) throw std::runtime_error("Not enough gold!");
	gold -= amount;
}

Army& Player::getArmy() {
	return army;
}

int Player::getGold() const{
	return gold;
}

void Player::addGold(int amount) {
	gold += amount;
}