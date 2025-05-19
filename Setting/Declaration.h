#ifndef Define_H
#define Define_H
#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12

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
#define ST_SPD "Speed"
#define ST_FLAT_SPD "Flat-Speed"
#define ST_SPD_P "Speed%"
#define ST_BREAK_EFF "Weakness_Break_Efficiency"
#define ST_TOUGH_REDUCE "Toughness_reduction"

#pragma endregion
#pragma region ElemnetType

#define ET_FIRE "Fire"
#define ET_ICE "Ice"
#define ET_LN "Lightning"
#define ET_WIND "Wind"
#define ET_QT "Quantum"
#define ET_IMG "Imaginary"
#define ET_PHY "Physical"

#pragma endregion
#pragma region ActionType

#define AT_TEMP "Temporary"
#define AT_NONE "None"
#define AT_BA "Basic_Attack"
#define AT_SKILL "Skill"
#define AT_ULT "Ultimate"
#define AT_FUA "Fua"
#define AT_SUMMON "Summon"
#define AT_DOT "Dot"
#define AT_BREAK "Break_dmg"
#define AT_SPB "Super_break"

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



/*------Unit------*/
//Stats
class Func_class;
class BuffClass;
class BuffElementClass;
class ActionValueStats;
class Unit;
class SubUnit;
class Ally;
class Enemy;
typedef unordered_map<string,double> Common_stats; 
typedef unordered_map<string,Common_stats> Common_stats_type; 
typedef unordered_map<string,Common_stats_type> Common_stats_each_element;
//Action_Data
class HealRatio;
class PointerWithValue;
class Ratio_data;
class Hit_spilt;
class ActionData;
class AllyActionData;
class EnemyActionData;
//Trigger_Function
class TriggerFunc;
class TriggerByYourSelf_Func;
class TriggerByAction_Func;
class TriggerByAllyAction_Func;
class TriggerByStats;
class TriggerAllyDeath;
class TriggerBySomeAlly_Func;
class TriggerHealing;
class TriggerDecreaseHP;
class TriggerByEnemyHit;
class TriggerDot_Func;
class TriggerEnergy_Increase_Func;
class TriggerSkill_point_func;
class TriggerHit_Count_func;
class TriggerAfterDealDamage;
#pragma region StatsSet
Ally* SetAllyBasicStats(double BaseSpeed,double Max_Energy,double Ult_cost,int Eidolon,string Element_type,string Path,string Name,string UnitType);
void SetMemoStats(Ally *ptr,double Hp_ratio,double Speed_ratio,string Element_type,string Name,string UnitType);
void SetCountdownStats(Ally* ptr, std::string Name);
void SetSummonStats(Ally* ptr, double BaseSpeed, std::string Name);
#pragma endregion

#pragma region Combat

#pragma region Energy
void Increase_energy(Ally* ptr, double Energy);
void Increase_energy(SubUnit *ptr, double Energy);
void Increase_energy(Ally* ptr, double Energy_percent, double Flat_energy);
void Increase_energy(SubUnit *ptr, double Energy_percent, double Flat_energy);
bool ultUseCheck(Ally* ptr);
void allUltimateCheck();
#pragma endregion

#pragma region Action_value
bool compareActionValueStats(ActionValueStats* a, ActionValueStats* b);
void Update_Max_atv(ActionValueStats* ptr);
void resetTurn(ActionValueStats* ptr);
void All_atv_reset();
void Action_forward(ActionValueStats* ptr, double fwd);
void All_Action_forward(double fwd);
void Find_turn();
void Atv_fix(double Atv_reduce);
#pragma endregion

#pragma region Buff_Stats
void extendBuffTimeAllAlly(string Buff_name, int Turn_extend);
void extendBuffTimeExcludingBuffer(string Buff_name, int Turn_extend, string Buffer_name);
void extendBuffTimeExcludingBuffer(string Buff_name, int Turn_extend, SubUnit* Buffer);

void buffAllAlly(vector<BuffClass> buffSet);
void buffAllAlly(vector<BuffElementClass> buffSet);
void buffAllAlly(vector<BuffClass> buffSet, string Buff_name, int extend);
void buffAllAlly(vector<BuffElementClass> buffSet, string Buff_name, int extend);
#pragma endregion

#pragma region BuffStack
void buffStackAllAlly(vector<BuffClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name);
void buffStackAllAlly(vector<BuffClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name, int extend);
void buffStackAllAlly(vector<BuffElementClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name);
void buffStackAllAlly(vector<BuffElementClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name, int extend);

void buffResetStackAllAlly(vector<BuffClass> buffSet, string Stack_Name);
void buffResetStackAllAlly(vector<BuffElementClass> buffSet, string Stack_Name);
#pragma endregion

#pragma region AdjustStats
void StatsAdjust(SubUnit *ptr,string ST);
void AtkAdjust(SubUnit *ptr);
void HpAdjust(SubUnit *ptr);
void DefAdjust(SubUnit *ptr);
#pragma endregion

#pragma region Debuff_Stats
void extendDebuffAll(string Debuff_name, int Turn_extend);

void debuffAllEnemy(vector<BuffClass> debuffSet);
void debuffAllEnemy(vector<BuffElementClass> debuffSet);

void debuffAllEnemyApply(vector<BuffClass> debuffSet, SubUnit* ptr, string Debuff_Name);
void debuffAllEnemyApply(vector<BuffElementClass> debuffSet, SubUnit* ptr, string Debuff_Name);
void debuffAllEnemyApply(vector<BuffClass> debuffSet, SubUnit* ptr, string Debuff_Name, int extend);
void debuffAllEnemyApply(vector<BuffElementClass> debuffSet, SubUnit* ptr, string Debuff_Name, int extend);

void debuffAllEnemyMark(vector<BuffClass> debuffSet, SubUnit* ptr, string Debuff_Name);
void debuffAllEnemyMark(vector<BuffElementClass> debuffSet, SubUnit* ptr, string Debuff_Name);
void debuffAllEnemyMark(vector<BuffClass> debuffSet, SubUnit* ptr, string Debuff_Name, int extend);
void debuffAllEnemyMark(vector<BuffElementClass> debuffSet, SubUnit* ptr, string Debuff_Name, int extend);
#pragma endregion

#pragma region DebuffStack
void debuffStackAll(vector<BuffClass> debuffSet, SubUnit* ptr, int Stack_increase, int Stack_limit, string Stack_Name);
void debuffStackAll(vector<BuffElementClass> debuffSet, SubUnit* ptr, int Stack_increase, int Stack_limit, string Stack_Name);
void debuffStackAll(vector<BuffClass> debuffSet, SubUnit* ptr, int Stack_increase, int Stack_limit, string Stack_Name, int extend);
void debuffStackAll(vector<BuffElementClass> debuffSet, SubUnit* ptr, int Stack_increase, int Stack_limit, string Stack_Name, int extend);
#pragma endregion

#pragma region CombatActions
void Take_action();
void Deal_damage();
void Attack(shared_ptr<AllyActionData> &data_);
void Skill_point(SubUnit *ptr,int p);
void Superbreak_trigger(shared_ptr<AllyActionData> &data_, double Superbreak_ratio);
void Dot_trigger(double Dot_ratio, Enemy* target, std::string Dot_type);
void Toughness_break(shared_ptr<AllyActionData> &data_, Enemy* target);
#pragma endregion

#pragma region ChangeHP
void RestoreHP(SubUnit *healer,HealRatio main,HealRatio adjacent,HealRatio other);
void RestoreHP(HealRatio Healptr,SubUnit *Healer,SubUnit *target);
void RestoreHP(HealRatio healRatio,SubUnit *Healer);
void RestoreHP(HealRatio healRatioMain,HealRatio healRatio,SubUnit *Healer,SubUnit *target);
void IncreaseCurrentHP(SubUnit *ptr,double Value);
void IncreaseHP(SubUnit *Healer,SubUnit *target,double Value);
void DecreaseCurrentHP(SubUnit *ptr,double Value);
void DecreaseHP(SubUnit *target,Unit *Trigger,double Value,double percentFromTotalHP,double percentFromCurrentHP);
void DecreaseHP(Unit *Trigger,double Value,double percentFromTotalHP,double percentFromCurrentHP);
void DecreaseHP(Unit *Trigger,vector<SubUnit*> target,double Value,double percentFromTotalHP,double percentFromCurrentHP);
void DecreaseHP(Unit *Trigger,string Name,double Value,double percentFromTotalHP,double percentFromCurrentHP);
#pragma endregion

#pragma region EnemyCombat
void EnemyHit(Enemy *Attacker,double energy);
void EnemyHit(Enemy *Attacker,vector<SubUnit*> target,double energy);
void DamageFormEnemy(Enemy *Attacker,vector<SubUnit*> target);
#pragma endregion

#pragma region ChooseChar
SubUnit* chooseSubUnitBuff(SubUnit* ptr);
Ally* chooseCharacterBuff(SubUnit* ptr);
Enemy* chooseEnemyTarget(SubUnit* ptr);
#pragma endregion

#pragma endregion

#pragma region Calculate

#pragma region Calculate_damage
void Cal_Damage(shared_ptr<AllyActionData> &data_, Enemy* target, Ratio_data Skill_mtpr);
void Cal_Toughness_reduction(shared_ptr<AllyActionData> &data_, Enemy* target, double Toughness_reduce);
void Cal_Break_damage(shared_ptr<AllyActionData> &data_, Enemy* target, double& Constant);
void Cal_Freeze_damage(shared_ptr<AllyActionData> &data_, Enemy* target);
void Cal_Dot_damage(shared_ptr<AllyActionData> &data_, Enemy* target, double Dot_ratio);
void Cal_Dot_Toughness_break_damage(shared_ptr<AllyActionData> &data_, Enemy* target, double Dot_ratio);
void Cal_Superbreak_damage(shared_ptr<AllyActionData> &data_, Enemy* target, double Superbreak_ratio);
void Cal_Additional_damage(shared_ptr<AllyActionData> &data_, Enemy* target, Ratio_data Skill_mtpr);
double Cal_Total_Toughness_Reduce(shared_ptr<AllyActionData> &data_, Enemy* target, double Base_Toughness_reduce);
#pragma endregion

#pragma region CalDmgReceive
double calculateDmgReceive(Enemy *Attacker,SubUnit *ptr,double ratio);
double calEnemyATK(Enemy *enemy);
double calEnemyDMG(Enemy *enemy);
double calAllyDefMultiplier(SubUnit *ptr);
#pragma endregion

#pragma region Calculate_Stats
double calculateAtkOnStats(SubUnit* ptr);
double calculateHpOnStats(SubUnit* ptr);
double calculateDefOnStats(SubUnit* ptr);
double calculateSpeedOnStats(SubUnit* ptr);
double calculateCritrateOnStats(SubUnit* ptr);
double calculateCritdamOnStats(SubUnit* ptr);
double calculateBreakEffectOnStats(SubUnit* ptr);
double calculateHPLost(SubUnit *ptr);

double calculateAtkForBuff(SubUnit* ptr, double ratio);
double calculateHpForBuff(SubUnit* ptr, double ratio);
double calculateDefForBuff(SubUnit* ptr, double ratio);
double calculateSpeedForBuff(SubUnit* ptr, double ratio);
double calculateCritrateForBuff(SubUnit* ptr, double ratio);
double calculateCritdamForBuff(SubUnit* ptr, double ratio);
double calculateBreakEffectForBuff(SubUnit* ptr, double ratio);
#pragma endregion

#pragma region CalDamageNote
bool changeMaxDamage(Ally *ptr);
void Cal_AverageDamage(Ally *ptr,vector<Enemy*> enemyList);
double Cal_AvgToughnessMultiplier(Enemy* target, double Total_atv);
void Cal_DamageSummary();
void Cal_DamageNote(shared_ptr<AllyActionData> &data_,Enemy *src,Enemy *recv,double damage,double ratio,string name);
#pragma endregion

#pragma region CalHeal
double calculateHeal(HealRatio healRatio, SubUnit *Healer, SubUnit *target);
double calculateHealFromLostHP(SubUnit *target, double percent);
double calculateHealFromTotalHP(SubUnit *target, double percent);
#pragma endregion

#pragma region CalHealStats
double Cal_HealBonus_multiplier(SubUnit* Healer, SubUnit* target);
#pragma endregion

#pragma endregion

#pragma region Event

#pragma region EventFunctions
void allEventBeforeTurn();
void allEventAfterTurn();
void allEventBuff(shared_ptr<AllyActionData> &data_);
void allEventBeforeAttack(shared_ptr<AllyActionData> &data_);
void allEventAfterAttack(shared_ptr<AllyActionData> &data_);
void allEventWhenAttack(shared_ptr<AllyActionData> &data_);
void allEventBeforeAction(shared_ptr<ActionData> &data_);
void allEventAfterAction(shared_ptr<ActionData> &data_);
void allEventHeal(SubUnit *Healer,SubUnit *target,double Value);
void allEventChangeHP(Unit *Trigger,SubUnit *target,double Value);
void allEventWhenToughnessBreak(shared_ptr<AllyActionData> &data_, Enemy* target);
void allEventWhenEnemyHit(Enemy* Attacker,vector<SubUnit*> vec);
void allEventWhenEnergyIncrease(Ally* target, double Energy);
void allEventSkillPoint(SubUnit* ptr, int p);
void allEventAttackHitCount(shared_ptr<AllyActionData> &data_, int Hit_cnt, int Total_Hit_cnt);
void allEventAdjustStats(SubUnit *ptr,string ST);
void allEventApplyDebuff(SubUnit* ptr, Enemy* target);
void allEventWhenEnemyDeath(SubUnit* Killer, Enemy* target);
void allEventWhenAllyDeath(SubUnit *Target);
void allEventAfterDealingDamage(shared_ptr<AllyActionData> &data_, Enemy *src, double damage);
#pragma endregion

#pragma endregion

#pragma region Setup

#pragma region SetCombat
void Setup();
void Reset();
void Start_game();
void EndWave(double Total_atv);
void Start_wave(int WAVE);
#pragma endregion

#pragma region SetEnemy
Enemy* createNewEnemy(double speed,double Toughness,string type);
void SetupEnemy(double speed,double Toughness,pair<double,double> energy,pair<double,double> skillRatio,pair<int,int> attackCooldown,int action,string type);
#pragma endregion

#pragma region Stats_Reset
void Basic_reset();
void Memosprite_reset();
void Summon_reset();
void Countdown_reset();
#pragma endregion

#pragma region Substats_Reset
void Set_Stats(Ally* ptr);
bool Reroll_substats();
bool StandardReroll(Ally* ptr);
bool AllCombinationReroll(Ally* ptr);
bool AllPossibleReroll(Ally* ptr);
#pragma endregion

#pragma endregion

#pragma region Print
void printRoundResult();
void Print();
void Print_All_Substats();
void printSummaryResult();
#pragma endregion

#pragma region CharCmd
namespace CharCmd{
void Set_Technique(Ally *ptr,int tech);
void Timing_print(Ally *ptr);
bool Using_Skill(Ally *ptr);
void printUltStart(string name);
void printUltEnd(string name);
void printText(string text);
Ally* findAllyName(string name);
void Set_Tune_Speed(Ally *ptr,double value);
void Set_Reroll_check(Ally *ptr,bool Bool);
void Set_Other_buff(Ally *ptr,bool Bool);
}
#pragma endregion

#endif
