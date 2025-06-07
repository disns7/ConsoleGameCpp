#include "Ghoul.h"
#include "Config.h"  

Ghoul::Ghoul()
    : Unit("Ghoul", 400,  12, 0, 6, ArmorType::Heavy) {
    cost = Config::GetUnitCost("Ghoul");
}

std::string Ghoul::getType() const {
    return "Ghoul";
}
