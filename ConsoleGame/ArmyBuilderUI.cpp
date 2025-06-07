#include "ArmyBuilderUI.h"
#include <iostream>


void ArmyBuilder::pickAliveCommanders(Player& player){
	std::cout << " You have to pick 5 commanders that will serve you in battle.\n";
    bool isRunning = true;
    while (isRunning) {
        int choice = aliveCommanderPicker(player.getArmy());
        switch (choice){

        case 1:
            armyTemplate.tryAddCommander<BladeDancer>(player, "BladeDancer");
            break;

        case 2:
            armyTemplate.tryAddCommander<UndeadHunter>(player, "UndeadHunter");
            break;

        case 3:
            armyTemplate.tryAddCommander<Paladin>(player, "Paladin");
            break;

        case 4:
            player.getArmy().printArmy();
            break;

        case 5:
            //isRunning = false;
            break;

        default:
            std::cout << "Invalid choice, try again.\n\n";
            break;
        }
    }
}

void ArmyBuilder::pickAliveUnits(Player& player){
    std::cout << "\nYou have to pick 10 units that will serve you in battle.\n";
    bool isRunning = true;
    while (isRunning) {
        int choice = aliveUnitPicker(player);
        switch (choice)
        {
        case 1:
            armyTemplate.tryAddUnit<Knight>(player, "Knight");
            break;

        case 2:
            armyTemplate.tryAddUnit<Archer>(player, "Archer");
            break;

        case 3:
            armyTemplate.tryAddUnit<Infantry>(player, "Infantry");
            break;

        case 4:
            armyTemplate.tryAddUnit<Healer>(player, "Healer");
            break;

        case 5:
            armyTemplate.tryAddUnit<Wizard>(player, "Wizard");
            break;

        case 6:
            player.getArmy().printArmy();
            break;

        case 7:
            isRunning = false;
            pickAliveCommanders(player);
            break;

        case 8: {
            Army& army = player.getArmy();

            const auto& selectedUnits = army.getUnits();
            Unit& target = *selectedUnits[0];

            for (const auto& unit : selectedUnits) {
                if (!unit->isDead()) {
                    unit->attack(target);
                    unit->onSupport(target);
                    unit->addMana(75);
                }
            }
            player.getArmy().printArmy();
        }
              break;

        default:

            std::cout << "Invalid choice, try again.\n\n";
            break;
        }
    }
}


int ArmyBuilder::aliveUnitPicker(Player& player)
{
    size_t com = player.getArmy().getUnitsLeftToAdd();
    std::cout << com << " units left to pick\n";
    std::cout << player.getGold() << " gold available.\n\n";
    std::cout << "\n=== PICK UNITS FOR YOUR ARMY ===\n\n";
    std::cout << "1. Knight - " << Config::GetUnitCost("Knight") << "gold.\n";
    std::cout << "2. Archer - " << Config::GetUnitCost("Archer") << "gold.\n";
    std::cout << "3. Infantry - " << Config::GetUnitCost("Infantry") << "gold.\n";
    std::cout << "4. Healer - " << Config::GetUnitCost("Healer") << "gold.\n";
    std::cout << "5. Wizard - " << Config::GetUnitCost("Wizard") << "gold.\n";
    std::cout << "6. Show current army. \n";
    std::cout << "7. Go to picking commanders. \n";

    int choice;
    std::cin >> choice;
    std::cout << "\n";
    return choice;
}

int ArmyBuilder::aliveCommanderPicker(Army& army){

    size_t com = army.getCommandersLeftToAdd();
    std::cout << com << " commanders left to pick\n";
    std::cout << "\n=== PICK COMMANDERS FOR YOUR ARMY ===\n";
    std::cout << com << "commanders left to pick\n";
    std::cout << "1. Blade Dancer\n";
    std::cout << "2. Undead Hunter\n";
    std::cout << "3. Paladin\n";
    std::cout << "4. Show current army\n";
    std::cout << "5. Exit\n";
    int choice;
    std::cin >> choice;
    std::cout << "\n";
    return choice;
}
