#pragma once
#include "Unit.h"

class Zombie : public Unit {
public:
    Zombie();
    std::string getType() const override;
};
