#include "Game.h"
#include "ArmyBuilderUI.h"
#include <iostream>

Game::Game(){
}

Game::~Game(){
}

void Game::run() {
    isRunning = true;
    while (isRunning) {
        int choice = menu.displayMainMenu();
        switch (choice)
        {
        case 1:
            armyBuilder.pickUnits(player1);
            break;

        case 2:
            break;

        case 3:
            menu.displayInstructions();
            break;

        case 4:
            std::cout << "Thanks for playing!";
            isRunning = false;
            break;

        default:
            std::cout << "Wrong number, try again.\n\n";
            break;
        }
    }
}


void Game::buildArmies(){
}

void Game::startBattle(){
}

void Game::showResults(){
}
