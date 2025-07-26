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

#define ST_HP_P "Hp%"
#define ST_FLAT_HP "Flat_Hp"
#define ST_ATK_P "Atk%"
#define ST_FLAT_ATK "Flat_Atk"
#define ST_DEF_P "Def%"
#define ST_FLAT_DEF "Flat_Def"
#define ST_DMG "Dmg%"
#define ST_CR "Crit_rate"
#define ST_CD "Crit_dam"
#define ST_BE "Break_effect"
#define ST_DEF_SHRED "Def_shred"
#define ST_RESPEN "Respen"
#define ST_VUL "Vul"
#define ST_RES "Res"
#define ST_EHR "Ehr"
#define ST_EnergyRecharge "Energy_recharge"
#define ST_HEALING_OUT "outGoingHeal"
#define ST_HEALING_IN "inComingHeal"
#define ST_SHEILD "SheildBonus"
#define ST_FLAT_SPD "Flat-Speed"
#define ST_SPD_P "Speed%"
#define ST_BREAK_EFF "Weakness_Break_Efficiency"
#define ST_TOUGH_REDUCE "Toughness_reduction"

#pragma endregion

#pragma region ActionType

// #define AType::TEMP "Temporary"
// #define AType::None "None"
// #define AType::BA "Basic_Attack"
// #define AType::SKILL "Skill"
// #define AType::Ult "Ultimate"
// #define AType::Fua "Fua"
// #define AType::Summon "Summon"
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