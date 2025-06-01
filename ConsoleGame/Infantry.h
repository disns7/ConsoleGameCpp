#pragma once
#include "Unit.h"

class Infantry : public Unit {
public:
    Infantry();
    std::string getType() const override;
};
