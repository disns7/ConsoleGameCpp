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

void Game::start() {
    isRunning = true;
    while (isRunning) {
        int choice = menu.displayMainMenu();
        switch (choice)
        {
        case 1:
            armyBuilder.pickAliveCommanders(player1);
            botArmyBuilder.pickDeadCommanders();
            botArmyBuilder.buildArmy();
            botPlayer.getArmy().printArmy();
            startBattle();
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


void Game::startBattle()
{    
    battle.startBattle(player1, botPlayer);
    if (player1.getPoints()<=2 && botPlayer.getPoints()<=2) {
        betweenBattlesMenu();
    }
    else {
        showResults();
    }
}

void Game::betweenBattlesMenu()
{
    isRunning = true;
    std::cout << "\n\n Current score: \n";
    std::cout << "Player points: " << player1.getPoints() << "\n";
    std::cout << "Opponent points: " << botPlayer.getPoints() << "\n";
    std::cout << botPlayer.getGold();
    botArmyBuilder.buildArmy();
    botPlayer.getArmy().printArmy();

    while (isRunning) {
        int choice = menu.displayBetweenBattlesMenu();
        switch (choice)
        {
        case 1:

            armyBuilder.pickAliveUnits(player1);
            startBattle();
            isRunning = false;
            break;

        case 2:

            break;

        case 3:
            player1.getArmy().printArmy();
            player1.getArmy().printSelectedArmy();
            botPlayer.getArmy().printArmy();
            botPlayer.getArmy().printSelectedArmy();

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

void Game::loadMenu()
{
}

void Game::showResults(){
    player1.getArmy().printArmy();
    botPlayer.getArmy().printArmy();
    menu.displayEndGame(player1, botPlayer);
}
