#pragma once
#include <string>

enum class ArmorType {
    Unarmored,
    Leather,
    Medium,
    Heavy
};

class Unit {
protected:
    std::string name;
    double hp;
    int attackPower;
    int cost;
    int armorValue;
    int mana;
    ArmorType armorType;

    const double getArmorMultiplier() const;

public:
    Unit(const std::string& name, int hp, int attack, int mana,
        int armorValue, ArmorType armorType);
    virtual ~Unit() = default;

    const void attack(Unit& target);
    void takeDamage(int amount);
    bool isDead() const;

    const std::string getName() const;
    const double getHP() const;
    const int getCost() const;
    const ArmorType getArmorType() const;
    const int getArmorValue() const;
    const void unitInfo();

    virtual std::string getType() const = 0;
};
