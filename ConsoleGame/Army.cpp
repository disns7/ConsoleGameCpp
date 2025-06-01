#include "Army.h"
#include <iostream>

void Army::addUnit(std::unique_ptr<Unit> unit) {
    units.push_back(std::move(unit));
}

void Army::addCommander(std::unique_ptr<Commander> commander) {
    commanders.push_back(std::move(commander));
}

template<typename unit>
void Army::removeAt(std::vector<std::unique_ptr<unit>>& vec, size_t index) {
    if (index < vec.size()) {
        vec.erase(vec.begin() + index);
        std::cout << "Removed element at index " << index << "\n";
    }
    else {
        std::cout << "Invalid index: " << index << "\n";
    }
}

void Army::removeUnit(size_t index) {
    removeAt(units, index);
}

void Army::removeCommander(size_t index) {
    removeAt(commanders, index);
}

void Army::printArmy() const {
    std::cout << "--- Units ---\n";
    for (const auto& unit : units) {
        unit->unitInfo(); 
    }

    std::cout << "--- Commanders ---\n";
    for (const auto& commander : commanders) {
        commander->unitInfo(); 
    }
}

size_t Army::getUnitCount() const {
    return units.size();
}

size_t Army::getCommanderCount() const {
    return commanders.size();
}
