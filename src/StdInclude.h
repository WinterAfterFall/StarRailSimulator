#ifndef StdInclude_H
#define StdInclude_H
#include<bits/stdc++.h>
#define endl '\n'

#pragma region priority

#define PRIORITY_First 1000
#define PRIORITY_HEAL 101
#define PRIORITY_IMMEDIATELY 100
#define PRIORITY_BUFF 3
#define PRIORITY_DEBUFF 2
#define PRIORITY_ACTTACK 0
#define PRIORITY_ACTION -1
#define PRIORITY_Last -1000

#pragma endregion
#pragma region StatsType

// #define Stats::HP_P "Hp%"
// #define Stats::FLAT_HP "Flat_Hp"
// #define Stats::ATK_P "Atk%"
// #define Stats::FLAT_ATK "Flat_Atk"
// #define Stats::DEF_P "Def%"
// #define Stats::FLAT_DEF "Flat_Def"
// #define Stats::DMG "Dmg%"
// #define Stats::CR "Crit_rate"
// #define Stats::CD "Crit_dam"
// #define Stats::BE "Break_effect"
// #define Stats::DEF_SHRED "Def_shred"
// #define Stats::RESPEN "Respen"
// #define Stats::VUL "Vul"
// #define Stats::RES "Res"
// #define Stats::EHR "Ehr"
// #define Stats::ER "Energy_recharge"
// #define Stats::HEALING_OUT "outGoingHeal"
// #define Stats::HEALING_IN "inComingHeal"
// #define Stats::SHEILD "SheildBonus"
// #define Stats::FLAT_SPD "Flat_Speed"
// #define Stats::SPD_P "Speed%"
// #define Stats::BREAK_EFF "Weakness_Break_Efficiency"
// #define Stats::TOUGH_REDUCE "Toughness_reduction"

#pragma endregion

#pragma region ActionType

// #define AType::TEMP "Temporary"
// #define AType::None "None"
// #define AType::BA "Basic_Attack"
// #define AType::SKILL "Skill"
// #define AType::Ult "Ultimate"
// #define AType::Fua "Fua"
// #define AType::Summon Side::Summon
// #define AType::Dot "Dot"
// #define AType::Break "Break_dmg"
// #define AType::SPB "Super_break"
// #define AType::Addtional "Additional"
// #define AType::Technique "Technique"
// #define AType::Freeze "Freeze"
// #define AType::Entanglement "Entanglement"

#pragma endregion
#pragma region TargetType

#define TT_SINGLE "Single_target"
#define TT_BLAST "Blast"
#define TT_AOE "Aoe"
#define TT_BOUNCE "Bounce"

#pragma endregion
#pragma region Type

#define TYPE_STD "Standard"
#define ALLYTYPE_BACKUP "Backup"

#pragma endregion


using std::cout;
using std::setprecision;
using std::fixed;
using std::vector;
using std::string;
using std::map;
using std::unordered_map;
using std::queue;
using std::set;
using std::priority_queue;
using std::pair;
using std::function;
using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::make_shared;
using std::setw;
using std::left;
using std::right;

#endif