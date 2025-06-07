#pragma once
#include "Unit.h"

class Skeleton : public Unit {
public:
    Skeleton();
    std::string getType() const override;
};
