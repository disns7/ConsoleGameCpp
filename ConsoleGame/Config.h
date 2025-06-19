#pragma once
#include <string>

class Config {
public:

    static constexpr int STARTING_GOLD = 2000;
    static constexpr int BONUS_GOLD_PER_DUEL = 1000;
    static constexpr int MAX_NORMAL_UNITS = 10;
    static constexpr int MAX_COMMANDER_UNITS = 5;
    static constexpr int BONUS_MANA_PER_HIT = 75;


    
    static int GetUnitCost(const std::string& unitName) {
        if (unitName == "Infantry") return 250;
        if (unitName == "Archer") return 300;
        if (unitName == "Knight") return 700;
        if (unitName == "Healer") return 150;
        if (unitName == "Wizard") return 400;

        if (unitName == "Skeleton") return 100;
        if (unitName == "Ghoul") return 250;
        if (unitName == "Necromancer") return 400;
        if (unitName == "Zombie") return 300;
        if (unitName == "Dibbuk") return 300;
        if (unitName == "Revenant") return 300;
        if (unitName == "Ghost") return 500;
        return INT_MAX;
    }

    static bool IsValidUnit(const std::string& unitName) {
        return GetUnitCost(unitName) != INT_MAX;
    }
    static bool IsValidCommander(const std::string& name) {
        const int commanderCount = 3;
        const std::string validCommanders[commanderCount] = {
            "paladin",
            "bladedancer",
            "undeadhunter"
        };

        for (int i = 0; i < commanderCount; ++i) {
            if (name == validCommanders[i]) return true;
        }
            return false;
        }
    
    enum CommanderType {
        InvalidCommander = -1,
        PaladinType,
        BladeDancerType,
        UndeadHunterType
    };

    static CommanderType GetCommanderType(const std::string& name) {
        if (name == "paladin") return PaladinType;
        if (name == "bladedancer") return BladeDancerType;
        if (name == "undeadhunter") return UndeadHunterType;
        return InvalidCommander;
    }

    enum UnitType {
        InvalidUnit = -1,
        InfantryType,
        ArcherType,
        KnightType,
        HealerType,
        WizardType
    };

    static UnitType GetUnitType(const std::string& name) {
        if (name == "Infantry") return InfantryType;
        if (name == "Archer") return ArcherType;
        if (name == "Knight") return KnightType;
        if (name == "Healer") return HealerType;
        if (name == "Wizard") return WizardType;
        return InvalidUnit;
    }







};
