#include "ArmyBuilderUI.h"
#include <iostream>



void ArmyBuilder::pickCommanders(Army& army){
	std::cout << " You have to pick 5 commanders that will serve you in battle.\n";
    bool isRunning = true;
    while (isRunning) {
        int choice = commanderPicker(army);
        switch (choice)
        {
        case 1:
            //army.addUnit(std::make_unique<Archer>());            
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            army.printArmy();
            isRunning = false;
            break;

        default:
            std::cout << "Invalid choice, try again.\n\n";
            break;
        }
    }
}

void ArmyBuilder::pickUnits(Player& player){
    std::cout << "\nYou have to pick 10 units that will serve you in battle.\n";
    bool isRunning = true;
    while (isRunning) {
        int choice = unitPicker(player);
        switch (choice)
        {
        case 1:
            tryAddUnit<Knight>(player, "Knight");
            break;

        case 2:
            tryAddUnit<Archer>(player, "Archer");           
            break;

        case 3:
            tryAddUnit<Infantry>(player, "Infantry");
            break;


        case 4:
            tryAddUnit<Healer>(player, "Healer");
            break;


        default:

            std::cout << "Invalid choice, try again.\n\n";
            break;
        }
    }
}


int ArmyBuilder::unitPicker(Player& player)
{
    size_t com = player.getArmy().getUnitsLeftToAdd();
    std::cout << com << " units left to pick\n";
    std::cout << player.getGold() << " gold available.\n\n";
    std::cout << "\n=== PICK UNITS FOR YOUR ARMY ===\n\n";
    std::cout << com << "commanders left to pick\n";
    std::cout << "1. Knight - " << Config::GetUnitCost("Knight") << "gold.\n";
    std::cout << "2. Archer - " << Config::GetUnitCost("Archer") << "gold.\n";
    std::cout << "3. Infantry - " << Config::GetUnitCost("Infantry") << "gold.\n";
    std::cout << "4. Healer - " << Config::GetUnitCost("Healer") << "gold.\n";
    int choice;
    std::cin >> choice;
    std::cout << "\n";
    return choice;
}

int ArmyBuilder::commanderPicker(Army& army){

    size_t com = army.getCommandersLeftToAdd();
    std::cout << com << " commanders left to pick\n";
    std::cout << "\n=== PICK COMMANDERS FOR YOUR ARMY ===\n";
    std::cout << com << "commanders left to pick\n";
    std::cout << "1. Undead Hunter\n";
    std::cout << "2. Blade Dancer\n";
    std::cout << "3. Paladin\n";
    std::cout << "4. Exit\n";
    int choice;
    std::cin >> choice;
    std::cout << "\n";
    return choice;
}
