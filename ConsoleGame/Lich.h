#pragma once

#include "Commander.h"

class Lich : public Commander {
public:
    Lich();
    std::string getType() const override;
    void onSupport(Unit& friendlyTarget) override;

};