#pragma once

#include "Commander.h"

class LordOfTerror : public Commander {
public:
    LordOfTerror();
    std::string getType() const override;
    void onSupport(Unit& friendlyTarget) override;

};