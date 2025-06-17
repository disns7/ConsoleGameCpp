#include "Game.h"
#include <iostream>

Game::Game(): 
    player1(),                         
    botPlayer(),                      
    botArmyBuilder(botPlayer),        
    armyBuilder(),                    
    menu(),                            
    isRunning(true)                  
{
    
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
            armyBuilder.pickAliveCommanders(player1);
            botArmyBuilder.pickDeadCommanders();
            botArmyBuilder.buildArmy();
            isRunning = false;
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


void Game::startBattle(){
}

void Game::showResults(){
}
