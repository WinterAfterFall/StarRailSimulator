#include "include.h"

enum class AType {
    TEMP,
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
    Freeze,
    Burn,
    Shock,
    Bleed,
    WindShear,
    ERROR,
};
enum class UnitStatus{
    Alive,
    Death,
    AtvFreeze, // สถานะตอนอัลติโรบิ้น คือหยุดนิ่ง atv ไม่ขยับแต่ action ได้
    Retire //สถานะของอัลติไพน่อน ถูกลบจากสนามแต่พวก atv ยังเคลื่อนปกติ
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
    ER,
    HEALING_OUT,
    HEALING_IN,
    SHEILD,
    FLAT_SPD,
    SPD_P,
    BREAK_EFF,
    TOUGH_REDUCE,
    SPB_inc,
    Mitigration
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
enum class BreakSEType{
            Bleed,
            Burn,
            Shock,
            WindShear,
            Freeze,
            Entanglement,
            Imprisonment
};

enum class Path{
    Destruction,
    Hunt,
    Erudition,
    Harmony,
    Nihility,
    Preservation,
    Abundance,
    Remembrance
};
enum class Side{
    Ally,
    Enemy,
    Memosprite,
    Summon,
    Countdown,
};
enum class UnitType{
    Standard,
    Backup
};
enum class EnemyType{
    Main,
    Adjacent,
    Other
};
namespace std {
    template <>
    struct hash<AType> {
        std::size_t operator()(AType c) const noexcept {
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
    template <>
    struct hash<Path> {
        std::size_t operator()(Path sz) const noexcept {
            return static_cast<std::size_t>(sz);
        }
    };
}
typedef unordered_map<Stats,double> Common_stats;
typedef unordered_map<Stats,unordered_map<AType,double>> Common_stats_type; 
typedef unordered_map<Stats, unordered_map<ElementType,unordered_map<AType,double>>> Common_stats_each_element;