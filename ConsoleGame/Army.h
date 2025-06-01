#pragma once
#include <vector>
#include <memory>
#include "Unit.h"
#include "Commander.h"

class Army {
private:
    std::vector<std::unique_ptr<Unit>> units;
    std::vector<std::unique_ptr<Commander>> commanders;

    template<typename unit>
    void removeAt(std::vector<std::unique_ptr<unit>>& vec, size_t index);
public:
    Army() = default;

    void addUnit(std::unique_ptr<Unit> unit);
    void addCommander(std::unique_ptr<Commander> commander);

    void removeUnit(size_t index);
    void removeCommander(size_t index);

    void printArmy() const;

    size_t getUnitCount() const;
    size_t getCommanderCount() const;
};
