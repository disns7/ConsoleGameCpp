#pragma once

#include "Commander.h"

class Paladin : public Commander {
public:
    Paladin();
    std::string getType() const override;
    void onSupport(Unit& friendlyTarget) override;

};