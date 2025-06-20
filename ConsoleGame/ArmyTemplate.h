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
        catch (const std::exception&) {
            //std::cout << "\nFailed to add " << unitName  << '\n';
        }
    }

    template <typename T>
    void tryAddCommander(Player& player, const std::string& commanderName) {
        try {
            player.getArmy().addCommander(std::make_unique<T>());
        }
        catch (const std::exception&) {
            //std::cout << "\nFailed to add " << commanderName  << '\n';
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

    }

    template <typename T>
    bool trySelectUnit(Player& player, const std::string& unitName) {
        auto& allUnits = player.getArmy().getUnits();
        auto& selectedUnits = player.getArmy().getSelectedUnits();

        for (const auto& unitPtr : allUnits) {
            T* casted = dynamic_cast<T*>(unitPtr.get());
            if (!casted)
                continue;

            if (std::find(selectedUnits.begin(), selectedUnits.end(), unitPtr.get()) != selectedUnits.end())
                continue;

            selectedUnits.push_back(unitPtr.get());
           // std::cout << "\nSelected 1 " << unitName << " unit.\n";
            return true;
        }

        //std::cout << "\nNo available " << unitName << " units to select.\n";
        return false;
    }


    template <typename T>
    bool tryAddSelectedCommander(Player& player, const std::string& commanderName) {
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
            //std::cout << "\nAdded " << commanderName << " to the selected commanders.\n";
            return true;  
        }
        //std::cout << "\nNo available commanders of type " << commanderName << " to select.\n";
        return false;
    }

};