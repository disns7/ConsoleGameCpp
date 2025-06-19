
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

    void start();                    
    void startBattle();

    void betweenBattlesMenu();
    void loadMenu();
    

    void showResults();

    void reset();                   
};
