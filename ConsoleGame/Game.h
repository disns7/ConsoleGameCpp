
#pragma once
#include "Player.h"
#include "Menu.h"
#include "ArmyBuilder.h"


class Game {
private:
    //Player* player1;
    //Player* player2;

    Menu menu;
    ArmyBuilder armyBuilder;
    bool isRunning;


public:

    Game();
    ~Game();

    void run();                    
    void buildArmies();             
    void startBattle();             
    void showResults();             
    void reset();                   
};
