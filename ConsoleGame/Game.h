
#pragma once
#include "Player.h"
#include "Menu.h"
#include "ArmyBuilderUI.h"
#include "BotArmyBuilder.h"
#include "Battle.h"


class Game {
private:
    Player player1;
    Player botPlayer;
    BotArmyBuilder botArmyBuilder;  
    ArmyBuilder armyBuilder;
    Menu menu;
    Battle battle;
    bool isRunning;


public:

    Game();
    ~Game();

    void run();                    
    void startBattle();             
    void showResults();             
    void reset();                   
};
