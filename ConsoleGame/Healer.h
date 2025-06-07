#pragma once
#include "Unit.h"

class Healer : public Unit {
public:
    Healer();

    std::string getType() const override;

    void onSupport(Unit& friendlyTarget) override; 
};
