#include "Ghost.h"
#include "Config.h"  

Ghost::Ghost()
    : Unit("Ghost", 290,  2, 200, 0, ArmorType::Unarmored) {
    cost = Config::GetUnitCost("Ghost");
}


std::string Ghost::getType() const {
    return "Ghost";
}

void Ghost::onSupport(Unit& friendlyTarget) {

}