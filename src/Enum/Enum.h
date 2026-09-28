#include "include.h"

enum class AType {
    TEMP,
    NONE,
    TALENT,
    BA,
    SKILL,
    ULT,
    FUA,
    SUMMON,
    DOT,
    BREAK,
    SPB,
    ELATION_DMG,
    ELATION_SKILL,
    ADDTIONAL,
    TECHNIQUE,
    ENTANGLEMENT,
    FREEZE,
    BURN,
    SHOCK,
    BLEED,
    WIND_SHEAR,
    ERROR,
};
enum class UnitStatus{
    ALIVE,
    DEATH,
    ATV_FREEZE, // ใช้ตอนอัลติ Phainon : atv หยุดนิ่ง + ไม่ได้เทิร์นจาก findTurn (act ได้ทาง extraTurn) · ยังอยู่ในสนาม เป็นเป้าได้
    RETIRE     // ใช้ตอนอัลติ Phainon : ถูกลบจากสนาม (ไม่ targetable / ไม่ exist) + atv หยุดนิ่งเช่นกัน
};

#pragma region ElementType
enum class ElementType {
    FIRE,
    ICE,
    LIGHTNING,
    WIND,
    QUANTUM,
    IMAGINARY,
    PHYSICAL
};
#pragma endregion

enum class Stats {
    TEST_1,
    TEST_2,
    TEST_3,
    TEST_4,
    TEST_5,
    TEST_6,
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
    SPB_INC,
    MTPR_INC,
    MITIGRATION,
    ELATION,
    CERTIFIED_BANGER,
    MERRYMAKE,
    DMG_REDUCE, // incoming-DMG formula: enemy = its outgoing DMG −x% · ally = DMG taken −x%
    ATK_REDUCE, // incoming-DMG formula: enemy ATK −x%
    BLOCK,      // ally: x% of each incoming hit can be blocked by the team Repellency pool (decreaseBlock)
};
enum class DotType {
    SHOCK,
    BLEED,
    BURN,
    WIND_SHEAR,
    GENERAL
};

#pragma region SrcType
enum class DmgSrcType {
    ATK,
    HP,
    DEF,
    CONST,
    ELATION,
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
            BLEED,
            BURN,
            SHOCK,
            WIND_SHEAR,
            FREEZE,
            ENTANGLEMENT,
            IMPRISONMENT
};

enum class Path{
    DESTRUCTION,
    HUNT,
    ERUDITION,
    HARMONY,
    NIHILITY,
    PRESERVATION,
    ABUNDANCE,
    REMEMBRANCE,
    ELATION,
};
enum class Side{
    ALLY,
    ENEMY,
    MEMOSPRITE,
    SUMMON,
    COUNTDOWN,
};
enum class UnitType{
    STANDARD,
    BACKUP,
    OUT_OF_BOUNDS
};  
enum class EnemyType{
    MAIN,
    ADJACENT,
    OTHER
};
enum class TraceType{
    SINGLE,
    BLAST,
    AOE,
    BOUNCE
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
typedef unordered_map<Stats,double> CommonStats;
typedef unordered_map<Stats,unordered_map<AType,double>> CommonStatsType; 
typedef unordered_map<Stats, unordered_map<ElementType,unordered_map<AType,double>>> CommonStatsEachElement;