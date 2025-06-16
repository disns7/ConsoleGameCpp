#pragma once
#include <vector>
#include <memory>
#include "Unit.h"
#include "Commander.h"
#include "Config.h"

class Army {
private:
    std::vector<std::unique_ptr<Unit>> units;
    std::vector<std::unique_ptr<Commander>> commanders;

    std::vector<Unit*> selectedUnits;
    std::vector<Commander*> selectedCommanders;

    size_t unitsLeftToAdd = Config::MAX_NORMAL_UNITS;
    size_t commandersLeftToAdd = Config::MAX_COMMANDER_UNITS;

    template<typename unit>
    void removeAt(std::vector<std::unique_ptr<unit>>& vec, size_t index);

public:

    void addUnit(std::unique_ptr<Unit> unit);
    void addCommander(std::unique_ptr<Commander> commander);

    void removeUnit(size_t index);
    void removeCommander(size_t index);

    void addToSelectedUnits(Unit* unit);
    void removeFromSelectedUnits(size_t index);

     std::vector<Unit*>& getSelectedUnits();
     std::vector<Commander*>& getSelectedCommanders();
     std::vector<std::unique_ptr<Unit>>& getUnits() ;
     std::vector<std::unique_ptr<Commander>>& getCommanders();

    size_t getUnitCount() const;
    size_t getCommanderCount() const;
    size_t getUnitsLeftToAdd() const;
    size_t getCommandersLeftToAdd() const;

    void printArmy() const;
    void printSelectedArmy() const;



};
