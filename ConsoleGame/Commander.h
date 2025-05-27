#pragma once
#include "Unit.h"

class Commander : public Unit {
public:
    virtual void useAbility() = 0;
    virtual ~Commander() {}
};
