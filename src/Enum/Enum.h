#include "include.h"

enum class ActionType {
    TEMPORARY,
    None,
    BA,
    SKILL,
    Ult,
    Fua,
    Summon,
    Dot,
    Break,
    SPB,
    Addtional,
    Technique,
    Entanglement,
    Freeze
};
enum class UnitStatus{
    Alive,
    Death,
    Retire
};

#pragma region ElementType
enum class ElementType {
    Fire,
    Ice,
    Lightning,
    Wind,
    Quantum,
    Imaginary,
    Physical
};
#pragma endregion

enum class Stats {
    HP_P,
    FLAT_HP,
    ATK_P,
    FLAT_ATK,
    DEF_P,
    FLAT_DEF,
    DMG,
    CR,
    CD,
    BE,
    DEF_SHRED,
    RESPEN,
    VUL,
    RES,
    EHR,
    EnergyRecharge,
    HEALING_OUT,
    HEALING_IN,
    SHEILD,
    SPD,
    FLAT_SPD,
    SPD_P,
    BREAK_EFF,
    TOUGH_REDUCE
};
enum class DotType {
    Shock,
    Bleed,
    Burn,
    WindShear,
    General
};

#pragma region SrcType
enum class DmgSrcType {
    ATK,
    HP,
    DEF,
    CONST
};
enum class HealSrcType {
    ATK,
    HP,
    DEF,
    TOTAL_HP,
    LOST_HP,
    CONST
};
#pragma endregion
enum BreakSEType{
            Bleed,
            Burn,
            Shock,
            WindShear,
            Freeze,
            Entanglement,
            Imprisonment
};
namespace std {
    template <>
    struct hash<ActionType> {
        std::size_t operator()(ActionType c) const noexcept {
            return static_cast<std::size_t>(c);
        }
    };

    template <>
    struct hash<ElementType> {
        std::size_t operator()(ElementType s) const noexcept {
            return static_cast<std::size_t>(s);
        }
    };

    template <>
    struct hash<Stats> {
        std::size_t operator()(Stats sz) const noexcept {
            return static_cast<std::size_t>(sz);
        }
    };
}
typedef unordered_map<string,double> Common_stats;
typedef unordered_map<string,unordered_map<string,double>> Common_stats_type; 
typedef unordered_map<string, unordered_map<ElementType,unordered_map<string,double>>> Common_stats_each_element;