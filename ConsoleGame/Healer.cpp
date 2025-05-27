#include "Healer.h"
#include "Config.h"  

Healer::Healer()
    : Unit("Healer", 290, 2, 200, 0, ArmorType::Unarmored) {
    cost = Config::GetUnitCost("Healer");
}

void Healer::heal() {

}