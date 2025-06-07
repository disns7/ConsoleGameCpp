#include "BladeDancer.h"

BladeDancer::BladeDancer()
    : Commander("BladeDancer", 4000, 300, 0, 25, ArmorType::Medium) {
    cost = 0;
}

std::string BladeDancer::getType() const {
    return "BladeDancer";
}