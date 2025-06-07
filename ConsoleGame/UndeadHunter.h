#pragma once

#include "Commander.h"

class UndeadHunter : public Commander {
public:
    UndeadHunter();
    std::string getType() const override;
    void onAttack(Unit& enemyTarget) override;

};