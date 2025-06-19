#include "Battle.h"
#include <iostream>
#include <string>
#include <vector>

void Battle::startBattle(Player& player, Player& botPlayer)
{
	std::cout << "\n\n----BATTLE BEGINS----\n\n";
    
    while (!deadCheck(player) && !deadCheck(botPlayer)) {

        //bot selected commanders basic attack
        basicAttackCommanders(botPlayer, player);

        //bot selected units basic attack
        basicAttackUnits(botPlayer, player);

        //-----------------------------------------------------------//
        
        //player selected commanders attack
        basicAttackCommanders(player, botPlayer);

        //player selected units basic attack
        basicAttackUnits(player, botPlayer);

        //player selected commanders onSuppert actions
        onSupportCommanders(player);

        //player selected units onSupport actions
        onSupportUnits(player);

        //special abilities from player units
        specialAbbilityUnits(player, botPlayer);

        //special abilities player commanders
        specialAbbilityCommanders(player, botPlayer);

        //-----------------------------------------------------------//

        //bot selected commanders onSuppert actions
        onSupportCommanders(botPlayer);

        //bot selected units onSupport actions
        onSupportUnits(botPlayer);

        //special abilities from bot units
        specialAbbilityUnits(player, botPlayer);
 
        //spec ability from bot commanders
        specialAbbilityCommanders(botPlayer, player);

        // adds mana to all units each rotation
        addManaToAll(player, botPlayer);
	}

    botPlayer.getArmy().clearTempUnits();
    player.getArmy().clearTempUnits();

    if (deadCheck(player)) {
        std::cout << "Bot wins a point!\n";
        botPlayer.addPoint();
    }
    else {
        std::cout << "Player wins a point!\n";
        player.addPoint();
    }
}

void Battle::basicAttackCommanders(Player& attPlayer, Player& defPlayer)
{
    for (Commander* botCommander : attPlayer.getArmy().getSelectedCommanders()) {
        if (botCommander->isDead()) continue;

        for (Unit* targetUnit : defPlayer.getArmy().getSelectedUnits()) {
            if (!targetUnit->isDead()) {
                botCommander->attack(*targetUnit);
            }
        }

        for (Commander* targetCommander : defPlayer.getArmy().getSelectedCommanders()) {
            if (!targetCommander->isDead()) {
                botCommander->attack(*targetCommander);
            }
        }
    }
}

void Battle::basicAttackUnits(Player& attPlayer, Player& defPlayer)
{
    for (Unit* attackerUnit : attPlayer.getArmy().getSelectedUnits()) {
        if (attackerUnit->isDead()) continue;

        for (Unit* targetUnit : defPlayer.getArmy().getSelectedUnits()) {
            if (!targetUnit->isDead()) {
                attackerUnit->attack(*targetUnit);
            }
        }

        for (Commander* targetCommander : defPlayer.getArmy().getSelectedCommanders()) {
            if (!targetCommander->isDead()) {
                attackerUnit->attack(*targetCommander);
            }
        }
    }
}

void Battle::specialAbbilityCommanders(Player& allyPlayer, Player& enemyPlayer)
{
    std::vector<Unit*> supporters = allyPlayer.getArmy().getSelectedUnits();

    for (Commander* botCommander : allyPlayer.getArmy().getSelectedCommanders()) {
        botCommander->useAbility(allyPlayer, enemyPlayer);
    }
}

void Battle::specialAbbilityUnits(Player& allyPlayer, Player& enemyPlayer)
{
    std::vector<Unit*> supporters = allyPlayer.getArmy().getSelectedUnits();

    for (Unit* supporter : supporters) {
        supporter->specialAbility(allyPlayer, enemyPlayer);
    }
}

void Battle::onSupportCommanders(Player& allyPlayer)
{
    for (Unit* supporter : allyPlayer.getArmy().getSelectedCommanders()) {
        if (supporter->isDead()) continue;

        for (Commander* targetCommander : allyPlayer.getArmy().getSelectedCommanders()) {
            if (targetCommander != supporter) {
                supporter->onSupport(*targetCommander);
               
            }
        }

        for (Unit* targetUnit : allyPlayer.getArmy().getSelectedUnits()) {
            if (targetUnit != supporter) {
                supporter->onSupport(*targetUnit);
            }
        }
    }
}

void Battle::onSupportUnits(Player& allyPlayer)
{
    for (Unit* supporter : allyPlayer.getArmy().getSelectedUnits()) {
        if (supporter->isDead()) continue;

        for (Commander* targetCommander : allyPlayer.getArmy().getSelectedCommanders()) {
            if (targetCommander != supporter && !targetCommander->isDead()) {
                supporter->onSupport(*targetCommander);
            }
        }

        for (Unit* targetUnit : allyPlayer.getArmy().getSelectedUnits()) {
            if (targetUnit != supporter && !targetUnit->isDead()) {
                supporter->onSupport(*targetUnit);
            }
        }

    }
}

void Battle::addManaToAll(Player& player, Player& botPlayer)
{
    for (Unit* targetUnit : player.getArmy().getSelectedUnits()) {
        if (!targetUnit->isDead()) {
            targetUnit->addMana(Config::BONUS_MANA_PER_HIT);
        }
    }
    for (Commander* targetUnit : player.getArmy().getSelectedCommanders()) {
        if (!targetUnit->isDead()) {
            targetUnit->addMana(Config::BONUS_MANA_PER_HIT);
        }
    }
    for (Unit* targetUnit : botPlayer.getArmy().getSelectedUnits()) {
        if (!targetUnit->isDead()) {
            targetUnit->addMana(Config::BONUS_MANA_PER_HIT);
        }
    }
    for (Commander* targetUnit : player.getArmy().getSelectedCommanders()) {
        if (!targetUnit->isDead()) {
            targetUnit->addMana(Config::BONUS_MANA_PER_HIT);
        }
    }
}

bool Battle::deadCheck(Player& player)
{
    for (Unit* unit : player.getArmy().getSelectedUnits()) {
        if (!unit->isDead()) {
            return false; 
        }
    }
    for (Commander* commander : player.getArmy().getSelectedCommanders()) {
        if (!commander->isDead()) {
            return false;
        }
    }
    return true;  
}

