#include "BotArmyBuilder.h"

#include <iostream>

BotArmyBuilder::BotArmyBuilder(Player& player)
    : botPlayer(player), rng(std::random_device{}()) {
}

void BotArmyBuilder::buildArmy() {
    pickDeadUnits();
    std::cout << "Bot Army building complete.\n";
    selectDeadArmy();

}

void BotArmyBuilder::pickDeadUnits() {
    std::uniform_int_distribution<int> unitDist(1, 6); 

    while (botPlayer.getArmy().getUnitsLeftToAdd() > 0) {
        int gold = botPlayer.getGold();
        int choice = unitDist(rng);
        switch (choice) {
        case 1:
            if (gold >= Config::GetUnitCost("Skeleton"))
                armyTemplate.tryAddUnit<Skeleton>(botPlayer, "Skeleton");
            break;
        case 2:
            if (gold >= Config::GetUnitCost("Ghost"))
                armyTemplate.tryAddUnit<Ghost>(botPlayer, "Ghost");
            break;
        case 3:
            if (gold >= Config::GetUnitCost("Ghoul"))
                armyTemplate.tryAddUnit<Ghoul>(botPlayer, "Ghoul");
            break;
        case 4:
            if (gold >= Config::GetUnitCost("Revenant"))
                armyTemplate.tryAddUnit<Revenant>(botPlayer, "Revenant");
            break;
        case 5:
            if (gold >= Config::GetUnitCost("Dibuk"))
                armyTemplate.tryAddUnit<Dibuk>(botPlayer, "Dibuk");
            break;
        case 6:
            if (gold >= Config::GetUnitCost("Necromancer"))
                armyTemplate.tryAddUnit<Necromancer>(botPlayer, "Necromancer");
            break;
        }

        if (gold < Config::GetUnitCost("Skeleton") &&
            gold < Config::GetUnitCost("Ghost") &&
            gold < Config::GetUnitCost("Ghoul") &&
            gold < Config::GetUnitCost("Revenant") &&
            gold < Config::GetUnitCost("Dibuk")&&
            gold < Config::GetUnitCost("Necromancer")) {
            break;
        }
    }
}

void BotArmyBuilder::pickDeadCommanders() {
    std::uniform_int_distribution<int> commanderDist(1, 2); 

    while (botPlayer.getArmy().getCommandersLeftToAdd() > 0) {
        int choice = commanderDist(rng);
        switch (choice) {
        case 1:
            armyTemplate.tryAddCommander<LordOfTerror>(botPlayer, "LordOfTerror");
            break;
        case 2:
            armyTemplate.tryAddCommander<Lich>(botPlayer, "Lich");
            break;

        }
    }
}

void BotArmyBuilder::selectDeadArmy() {
    auto& army = botPlayer.getArmy();

    int totalCmdrs = static_cast<int>(army.getCommanders().size());
    std::uniform_int_distribution<int> commanderCountDist(2, totalCmdrs);
    int commandersToSelect = commanderCountDist(rng);

    int selectedCmdrs = 0;
    while (selectedCmdrs < commandersToSelect) {
        std::uniform_int_distribution<int> commanderTypeDist(1, 2);
        int type = commanderTypeDist(rng);

        switch (type) {
        case 1:
            armyTemplate.tryAddSelectedCommander<LordOfTerror>(botPlayer, "LordOfTerror");
            break;
        case 2:
            armyTemplate.tryAddSelectedCommander<Lich>(botPlayer, "Lich");
            break;
        }
        selectedCmdrs++;
    }

    int totalUnits = static_cast<int>(army.getUnits().size());
    std::uniform_int_distribution<int> unitCountDist(3, totalUnits);
    int unitsToSelect = unitCountDist(rng);
    //int unitsToSelect = 0;

    bool success = false;

    int selectedUnits = 0;
    while (selectedUnits < unitsToSelect) {
        std::uniform_int_distribution<int> unitTypeDist(1, 6);  
        int type = unitTypeDist(rng);

        switch (type) {
        case 1:
            success = armyTemplate.trySelectUnit<Skeleton>(botPlayer, "Skeleton");
            break;
        case 2:
            success = armyTemplate.trySelectUnit<Ghost>(botPlayer, "Ghost");
            break;
        case 3:
            success = armyTemplate.trySelectUnit<Ghoul>(botPlayer, "Ghoul");
            break;
        case 4:
            success = armyTemplate.trySelectUnit<Revenant>(botPlayer, "Revenant");
            break;
        case 5:
            success = armyTemplate.trySelectUnit<Dibuk>(botPlayer, "Dibuk");
            break;
        case 6:
            success = armyTemplate.trySelectUnit<Necromancer>(botPlayer, "Necromancer");
            break;
        }
        if (success) {
            selectedUnits++;
            success = false;
        }
    }
}