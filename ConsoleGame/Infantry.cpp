#include "Infantry.h"
#include "Config.h"  

Infantry::Infantry()
    : Unit("Infantry", 420, 7, 0, 8, ArmorType::Medium) {
    cost = Config::GetUnitCost("Infantry");
}

std::string Infantry::getType() const {
    return "Infantry";
}