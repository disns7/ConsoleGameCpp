#pragma once
#include <string>

class Player;

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
    double maxHP;
    int attackPower;
    int cost = 0;
    int armorValue;
    int mana;
    int maxMana;
    ArmorType armorType;

    const double getArmorMultiplier() const;

public:
    Unit(const std::string& name, double hp, int attack, int mana,
        int armorValue, ArmorType armorType);
    virtual ~Unit() = default;

    const void attack(Unit& target);
    void takeDamage(double amount);
    void heal(double amount);
    void addMana(int amount);
    void revive(double amount);

    virtual void onAttack(Unit& enemyTarget) {};
    virtual void onSupport(Unit& friendlyTarget) {};
    virtual void specialAbility(Player& allyPlayer, Player& enemyPLayer) {};

    const int getMana() const;
    const double getMaxHP() const;
    bool isDead() const;
    const std::string getName() const;
    const double getHP() const;
    const int getCost() const;
    const ArmorType getArmorType() const;
    const int getArmorValue() const;

    void setHp(double HP);
    void setMana(int mana);
    void setArmorValue(int armorValue);

    const void unitInfo();

    virtual std::string getType() const = 0;
};
