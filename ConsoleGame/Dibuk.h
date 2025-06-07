#pragma once
#include "Unit.h"

class Dibuk : public Unit {
public:
    Dibuk();
    std::string getType() const override;
    void onAttack(Unit& enemyTarget) override;

};
