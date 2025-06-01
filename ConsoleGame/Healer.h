#pragma once
#include "Unit.h"

class Healer : public Unit {

public:
    Healer();
    void heal();
    std::string getType() const override;
};