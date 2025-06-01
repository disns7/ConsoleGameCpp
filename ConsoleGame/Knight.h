#pragma once
#include "Unit.h"

class Knight : public Unit {
public:
    Knight();
    std::string getType() const override;
};
