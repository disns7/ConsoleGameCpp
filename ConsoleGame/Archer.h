#pragma once
#include "Unit.h"

class Archer : public Unit {
public:
    Archer();
    std::string getType() const override;
};
