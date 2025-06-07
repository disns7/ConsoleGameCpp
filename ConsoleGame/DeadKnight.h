#pragma once

#include "Commander.h"

class DeadKnight : public Commander {
public:
    DeadKnight();
    std::string getType() const override;
    void onSupport(Unit& friendlyTarget) override;

};