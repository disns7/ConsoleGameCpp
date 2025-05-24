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
    std::cout << "INSTRUCTIONS\n";
    std::cout << "\n";

}