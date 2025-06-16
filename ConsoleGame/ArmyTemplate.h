#pragma once
#include "Player.h"
#include <iostream>       
#include <stdexcept>

class ArmyTemplate {

public:
    template <typename T>
    void tryAddUnit(Player& player, const std::string& unitName) {
        int cost = Config::GetUnitCost(unitName);
        try {
            player.spendGold(cost);
            player.getArmy().addUnit(std::make_unique<T>());
        }
        catch (const std::runtime_error& e) {
            std::cout << "\nFailed to add " << unitName << ": " << e.what() << '\n';
        }
    }

    template <typename T>
    void tryAddCommander(Player& player, const std::string& commanderName) {
        try {
            player.getArmy().addCommander(std::make_unique<T>());
        }
        catch (const std::runtime_error& e) {
            std::cout << "\nFailed to add " << commanderName << ": " << e.what() << '\n';
        }
    }

    template <typename T>
    void trySelectUnits(Player& player, int countToAdd) {
        

        int addedCount = 0;

        for (const auto& unitPtr : player.getArmy().getUnits()) {
            if (addedCount >= countToAdd)
                break;

            T* casted = dynamic_cast<T*>(unitPtr.get());
            if (!casted)
                continue;

            if (std::find(player.getArmy().getSelectedUnits().begin(), player.getArmy().getSelectedUnits().end(), unitPtr.get()) != player.getArmy().getSelectedUnits().end())
                continue;

            player.getArmy().getSelectedUnits().push_back(unitPtr.get());
            addedCount++;
        }

        if (addedCount == 0) {
            std::cout << "\nNo available units of requested type to select.\n";
        }
        else if (addedCount < countToAdd) {
            std::cout << "\nOnly " << addedCount << " units of requested type were available and selected.\n";
        }
        else {
            std::cout << "\nSuccessfully selected " << addedCount << " units.\n";
        }
    }

    template <typename T>
    void tryAddSelectedCommander(Player& player, const std::string& commanderName) {
        auto& allCommanders = player.getArmy().getCommanders();          
        auto& selectedCommanders = player.getArmy().getSelectedCommanders();  

        for (const auto& commanderSmartPtr : allCommanders) {
            Commander* commanderPtr = commanderSmartPtr.get();  

            T* casted = dynamic_cast<T*>(commanderPtr);
            if (!casted)
                continue;

            if (std::find(selectedCommanders.begin(), selectedCommanders.end(), commanderPtr) != selectedCommanders.end())
                continue;

            selectedCommanders.push_back(commanderPtr);
            std::cout << "\nAdded " << commanderName << " to the selected commanders.\n";
            return;  
        }

        std::cout << "\nNo available commanders of type " << commanderName << " to select.\n";
    }

};