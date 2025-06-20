#include "Player.h"
#include <stdexcept>
#include <fstream>
#include <iostream>
#include "CommanderIncludes.h"
#include "Helper.h"

StringHelper helper;

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

void Player::setGold(int amount)
{
    this->gold = amount;
}

const int Player::getPoints() const
{
	return points;
}

void Player::addPoint()
{
	points += 1;
}

void Player::setPoints(int points)
{
    this->points = points;
}

void Player::saveToFile(const std::string& filename) const 
{
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Failed to open file for saving: " << filename << '\n';
        return;
    }

    out << gold << '\n';
    out << points << '\n';

    out << army.getCommanders().size() << '\n';

    for (const auto& commander : army.getCommanders()) {
        out << commander->getName() << '\n';
        out << commander->getHP() << '\n';
        out << commander->getMana() << '\n';
        out << commander->getArmorValue() << '\n';
    }

    out.close();
    std::cout << "Game saved to " << filename << "\n";
}

void Player::loadFromFile(const std::string& filename)
{
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Failed to open file for loading: " << filename << '\n';
        return;
    }

    in >> gold >> points;

    size_t commanderCount;
    in >> commanderCount;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    army.clearSelected();
    
    for (size_t i = 0; i < commanderCount; ++i) {
        std::string commanderName;
        std::getline(in, commanderName);
        commanderName = StringHelper::toLower(commanderName);

        Config::CommanderType type = Config::GetCommanderType(commanderName);
        switch (type) {

        case Config::PaladinType:
            army.addCommander(std::make_unique<Paladin>());
            break;

        case Config::BladeDancerType:
            army.addCommander(std::make_unique<BladeDancer>());
            break;

        case Config::UndeadHunterType:
            army.addCommander(std::make_unique<UndeadHunter>());
            break;

        case Config::LichType:
            army.addCommander(std::make_unique<Lich>());
            break;

        case Config::LordOfTerrorType:
            army.addCommander(std::make_unique<LordOfTerror>());
            break;
        }

        int hp, mana, armorVal;
        in >> hp >> mana >> armorVal;
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        auto& commanderVec = army.getCommanders();
        if (!commanderVec.empty()) {
            commanderVec.back()->setHp(hp);
            commanderVec.back()->setMana(mana);
            commanderVec.back()->setArmorValue(armorVal);
        }
    }
    std::cout << "Game loaded from " << filename << "\n";
}



