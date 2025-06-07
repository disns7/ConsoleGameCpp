#pragma once
#include "Commander.h"

class BladeDancer : public Commander {
    public:
        BladeDancer();
        std::string getType() const override;

};