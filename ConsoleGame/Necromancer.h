#pragma once
#include "Unit.h"

class Necromancer : public Unit {
public:
    Necromancer();
    std::string getType() const override;

};
