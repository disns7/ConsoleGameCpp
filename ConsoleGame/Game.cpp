#include "Game.h"
#include <iostream>
#include <fstream>

#include <sstream>


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
            isRunning = false;
            armyBuilder.pickAliveCommanders(player1);
            botArmyBuilder.pickDeadCommanders();
            botArmyBuilder.buildArmy();
            startBattle();
            break;

        case 2:
            isRunning = false;
            loadGame();
            betweenBattlesMenu();
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
    botArmyBuilder.buildArmy();

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
            saveGame();
            break;

        case 3:
            botPlayer.getArmy().printArmy();
            botPlayer.getArmy().printSelectedArmy();
            player1.getArmy().printArmy();
            player1.getArmy().printSelectedArmy();

            break;
        case 4:
            isRunning = false;
            reset();

        case 5:
            std::cout << "Thanks for playing!";
            isRunning = false;
            break;

        default:
            std::cout << "Wrong number, try again.\n\n";
            break;
        }
    }
}

void Game::reset() {
    player1.getArmy().clearCommanders();
    player1.getArmy().clearUnits();
    botPlayer.getArmy().clearCommanders();
    botPlayer.getArmy().clearUnits();

    player1.setGold(Config::STARTING_GOLD);
    botPlayer.setGold(Config::STARTING_GOLD);

    player1.setPoints(0);
    botPlayer.setPoints(0);
    start();
}


void Game::saveGame() 
{
    std::string filename;
    std::cout << "Enter filename to save: ";
    std::cin >> filename;

    player1.saveToFile(filename + "_p1.txt");
    botPlayer.saveToFile(filename + "_bot.txt");

    std::cout << "Game saved successfully!\n";
}

void Game::loadGame() 
{
    std::string filename;
    std::cout << "Enter filename to load: ";
    std::cin >> filename;

    player1.loadFromFile(filename + "_p1.txt");
    botPlayer.loadFromFile(filename + "_bot.txt");

    std::cout << "Game loaded successfully!\n";
}


void Game::showResults(){
    player1.getArmy().printArmy();
    botPlayer.getArmy().printArmy();
    menu.displayEndGame(player1, botPlayer);
}
