#include "Zombie.h"
#include "Config.h"  

Zombie::Zombie()
    : Unit("Zombie", 250, 15, 0, 0, ArmorType::Unarmored) {
    cost = Config::GetUnitCost("Zombie");
}

std::string Zombie::getType() const {
    return "Zombie";
}
