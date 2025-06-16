#include "Skeleton.h"
#include "Config.h"  

Skeleton::Skeleton()
    : Unit("Skeleton", 500, 5, 0, 8, ArmorType::Medium) {
    cost = Config::GetUnitCost("Skeleton");
}

std::string Skeleton::getType() const {
    return "Skeleton";
}
