
#pragma once
#include "Player.h"
#include "Menu.h"
#include "ArmyBuilderUI.h"
#include "BotArmyBuilder.h"


class Game {
private:
    Player player1;
    Player botPlayer;
    BotArmyBuilder botArmyBuilder;  
    ArmyBuilder armyBuilder;
    Menu menu;
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
