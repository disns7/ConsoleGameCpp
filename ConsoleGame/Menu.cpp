#include <iostream>
#include "Menu.h"


int Menu::displayMainMenu() {

        std::cout << "=== Main Menu ===\n";
        std::cout << "1. New Game\n";
        std::cout << "2. Load Game\n";
        std::cout << "3. Display Instructions\n";
        std::cout << "4. Exit\n";
        int choice;
        std::cin >> choice;
        std::cout << "\n";
        return choice;
}


void Menu::displaySaveMenu(const Player& player){

}

void Menu::displayLoadMenu(Player& player){

}

void Menu::displayBattleResults(const Player& winner, const Player& loser){
}

void Menu::displayInstructions() {
    std::cout << "\n----INSTRUCTIONS----\n";
    std::cout << "The game is played by the principle best of 5 duels (first to 3 points).\n";
    std::cout << "Each round gives one point to the winner.\n";
    std::cout << "A duel is won when the selected enemy units have no hp left.\n";
    std::cout << "When you press New Game:\n";
    std::cout << "You have to pick the units and commanders that you will take into battle.\n";
    std::cout << "Your bot opponent will pick his units automatically\n";
    std::cout << "Before each round you will have to select commanders to take into battle.\n";
    std::cout << "You will also be given the chance to add more units to ur regular army every round.\n";
    std::cout << "\n";

}

void Menu::displaySelectionInstructions(Player& player)
{
    std::cout << "\nTo select commanders for the upcoming battle type 'SELECT BOSS <boss name>'. \n";
    std::cout << "To select units type 'SELECT <unit name> <unit count>'\n";
    std::cout << "To advance to the next stage of battle, once you have selected the units type 'START'\n";
    std::cout << "Type show to see both your selected army for battler and your whole army.\n";
    std::cout << "\n";

}
