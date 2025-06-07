#pragma once
#include "Unit.h"

class Wizard : public Unit {
public:
    Wizard();
    std::string getType() const override;
    void onAttack(Unit& enemyTarget) override;

};
