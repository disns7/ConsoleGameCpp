#include "Archer.h"
#include "Config.h"  

Archer::Archer()
    : Unit("Archer", 535, 10, 0, 3, ArmorType::Medium) {
    cost = Config::GetUnitCost("Archer");
}