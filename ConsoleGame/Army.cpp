#include "Army.h"
#include <iostream>

template<typename unit>
void Army::removeAt(std::vector<std::unique_ptr<unit>>& vec, size_t index) {
    if (index < vec.size()) {
        vec.erase(vec.begin() + index);
    }
    else {
    }
}

void Army::addUnit(std::unique_ptr<Unit> unit) {
    if (unitsLeftToAdd > 0) {
        units.push_back(std::move(unit));
        unitsLeftToAdd--;
    }
    else {
        std::cout << "Your list of units is already full\n";
    }
}

void Army::addCommander(std::unique_ptr<Commander> commander) {
    if (commandersLeftToAdd > 0) {
        commanders.push_back(std::move(commander));
        commandersLeftToAdd--;
    }
    else {
        std::cout << "Your list of commanders is already full\n";
    }
}

void Army::removeUnit(size_t index) {
    removeAt(units, index);
    ++unitsLeftToAdd;
}

void Army::removeCommander(size_t index) {
    removeAt(commanders, index);
}

void Army::addToSelectedUnits(Unit* unit) {
    selectedUnits.push_back(unit);
}

void Army::removeFromSelectedUnits(size_t index) {
    if (index < selectedUnits.size()) {
        selectedUnits.erase(selectedUnits.begin() + index);
    }
}

 std::vector<std::unique_ptr<Unit>>& Army::getUnits() 
{
    return units;
}

 std::vector<std::unique_ptr<Commander>>& Army::getCommanders()
 {
     return commanders;
 }

 std::vector<Unit*>& Army::getSelectedUnits()  {
    return selectedUnits;
}

 std::vector<Commander*>& Army::getSelectedCommanders()
 {
     return selectedCommanders;
 }

size_t Army::getUnitCount() const {
    return units.size();
}

size_t Army::getCommanderCount() const {
    return commanders.size();
}

size_t Army::getUnitsLeftToAdd() const
{
    return unitsLeftToAdd;
}

size_t Army::getCommandersLeftToAdd() const
{
    return commandersLeftToAdd;
}

void Army::printArmy() const {
    std::cout << "\n--- Units ---\n";
    for (const auto& unit : units) {
        unit->unitInfo(); 
    }

    std::cout << "\n--- Commanders ---\n";
    for (const auto& commander : commanders) {
        commander->unitInfo(); 
    }
    std::cout << "\n\n";
}

void Army::printSelectedArmy() const
{
    std::cout << "\n--- Selected Units ---\n";
    for (const auto& unit : selectedUnits) {
        unit->unitInfo();
    }

    std::cout << "\n--- Selected Commanders ---\n";
    for (const auto& commander : selectedCommanders) {
        commander->unitInfo();
    }
    std::cout << "\n\n";
}
