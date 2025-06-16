#include "ArmyBuilderUI.h"
#include <iostream>
#include <string>
#include "Helper.h"


void ArmyBuilder::pickAliveCommanders(Player& player){
	std::cout << "\nYou have to pick up to 5 commanders that will serve you in battle.\n";
    bool isRunning = true;
    while (isRunning) {
        int choice = aliveCommanderPicker(player.getArmy().getCommandersLeftToAdd());
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
            pickAliveUnits(player);
            isRunning = false;
            break;

        default:
            std::cout << "Invalid choice, try again.\n\n";
            break;
        }
    }
}

void ArmyBuilder::pickAliveUnits(Player& player){
    std::cout << "\nYou have to pick up to 10 units that will serve you in battle.\n";
    bool isRunning = true;
    while (isRunning) {
        int choice = aliveUnitPicker(player.getArmy().getUnitsLeftToAdd(), player.getGold());
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
            selectAliveArmy(player);
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


int ArmyBuilder::aliveUnitPicker(size_t unitsLeftToAdd, int playerGold)
{
    std::cout << unitsLeftToAdd << " Units left to pick\n";
    std::cout << playerGold << " Gold available.\n\n";
    std::cout << "\n=== PICK UNITS FOR YOUR ARMY ===\n\n";
    std::cout << "1. Knight - " << Config::GetUnitCost("Knight") << "gold.\n";
    std::cout << "2. Archer - " << Config::GetUnitCost("Archer") << "gold.\n";
    std::cout << "3. Infantry - " << Config::GetUnitCost("Infantry") << "gold.\n";
    std::cout << "4. Healer - " << Config::GetUnitCost("Healer") << "gold.\n";
    std::cout << "5. Wizard - " << Config::GetUnitCost("Wizard") << "gold.\n";
    std::cout << "6. Show current army. \n";
    std::cout << "7. Go to army selection. \n";

    int choice;
    std::cin >> choice;
    std::cout << "\n";
    return choice;
}

int ArmyBuilder::aliveCommanderPicker(size_t commandersLeftToAdd){

    std::cout << commandersLeftToAdd << " Commanders left to pick\n";
    std::cout << "\n=== PICK COMMANDERS FOR YOUR ARMY ===\n";
    std::cout << "1. BladeDancer\n";
    std::cout << "2. UndeadHunter\n";
    std::cout << "3. Paladin\n";
    std::cout << "4. Show current army\n";
    std::cout << "5. Go to picking units\n";
    int choice;
    std::cin >> choice;
    std::cout << "\n";
    return choice;
}

void ArmyBuilder::selectAliveArmy(Player& player)
{
    std::string command;
    bool isStarting = false;

    menu.displaySelectionInstructions(player);
    std::cin.ignore(1000, '\n');

    while (!isStarting) {
        std::getline(std::cin, command);
        command = StringHelper::toLower(command);

        std::vector<std::string> words = StringHelper::splitWords(command);

        if (words.empty()) {
            std::cout << "Empty input. Try again.\n";
            continue;
        }

        if (words[0] == "select") {
            if (words.size() >= 3 && words[1] == "boss") {

                std::string commanderName = words[2];

                if (Config::IsValidCommander(commanderName)) {
                    Config::CommanderType type = Config::GetCommanderType(commanderName);
                    switch (type) {

                    case Config::PaladinType:
                        armyTemplate.tryAddSelectedCommander<Paladin>(player, commanderName);
                        break;

                    case Config::BladeDancerType:
                        std::cout << "asdasd";
                        armyTemplate.tryAddSelectedCommander<BladeDancer>(player, commanderName);
                        break;

                    case Config::UndeadHunterType:
                        armyTemplate.tryAddSelectedCommander<UndeadHunter>(player, commanderName);
                        break;

                    default:
                        std::cout << "Unknown commander type: " << commanderName << "\n";
                        break;
                    }
                    player.getArmy().printSelectedArmy();
                }


            }
            else if (words.size() >= 3) {

                std::string unitName = words[1];
                std::string countStr = words[2];

                int unitCount = std::atoi(countStr.c_str());

                if (unitCount <= 0) {
                    std::cout << "Invalid unit count: " << countStr << "\n";
                    continue;
                }
                unitName = StringHelper::capitalizeOnlyFirst(unitName);

                if (Config::IsValidUnit(unitName)) {
                    Config::UnitType unitType = Config::GetUnitType(unitName);

                    switch (unitType) {
                    case Config::InfantryType:
                        armyTemplate.trySelectUnits<Infantry>(player, unitCount);
                        break;

                    case Config::ArcherType:
                        armyTemplate.trySelectUnits<Archer>(player, unitCount);
                        break;

                    case Config::KnightType:
                        armyTemplate.trySelectUnits<Knight>(player, unitCount);
                        break;

                    case Config::HealerType:
                        armyTemplate.trySelectUnits<Healer>(player, unitCount);
                        break;

                    case Config::WizardType:
                        armyTemplate.trySelectUnits<Wizard>(player, unitCount);
                        break;

                    default:
                        std::cout << "Unknown unit type: " << unitName << "\n";
                        break;
                    }

                    player.getArmy().printSelectedArmy();


                }
            }
            else {
                std::cout << "Incomplete SELECT command.\n";
            }
        }
        else if (words.size() == 1 && words[0] == "start") {
            isStarting = true;
        }
        else {
            std::cout << "Incorrect input, try again.\n";
        }
    }
}


