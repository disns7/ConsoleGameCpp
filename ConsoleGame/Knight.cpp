#include "Knight.h"
#include "Config.h"  

Knight::Knight()
    : Unit("Knight", 835, 45, 0, 10, ArmorType::Heavy) {
    cost = Config::GetUnitCost("Knight");
}
