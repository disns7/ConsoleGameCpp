#pragma once
#include "Unit.h"

class Ghost : public Unit {
public:
    Ghost();
    std::string getType() const override;
    void onSupport(Unit& friendlyTarget) override;

};
