#pragma once
#include "Unit.h"

class Ghoul : public Unit {
public:
    Ghoul();
    std::string getType() const override;
};
