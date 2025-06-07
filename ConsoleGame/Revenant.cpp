#include "Revenant.h"
#include "Config.h"  

Revenant::Revenant()
    : Unit("Revenant", 600, 15, 0, 0, ArmorType::Unarmored) {
    cost = Config::GetUnitCost("Revenant");
}


std::string Revenant::getType() const {
    return "Revenant";
}