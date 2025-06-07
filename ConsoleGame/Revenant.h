#pragma once
#include "Unit.h"

class Revenant : public Unit {
public:
    Revenant();
    std::string getType() const override;

};
