#ifndef Define_H
#define Define_H
#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12

#define PRIORITY_HEAL 101
#define PRIORITY_IMMEDIATELY 100
#define PRIORITY_BUFF 3
#define PRIORITY_DEBUFF 2
#define PRIORITY_ACTTACK 0
#define PRIORITY_ACTION -1

#define ST_HP_PERCENT "Hp%"
#define ST_FLAT_HP "Flat_Hp"
#define ST_ATK_PERCENT "Atk%"
#define ST_FLAT_ATK "Flat_Atk"
#define ST_DEF_PERCENT "Def%"
#define ST_FLAT_DEF "Flat_Def"
#define ST_DMG_PERCENT "Dmg%"
#define ST_CRIT_RATE "Crit_rate"
#define ST_CRIT_DAM "Crit_dam"
#define ST_BREAK_EFFECT "Break_effect"
#define ST_DEF_SHRED "Def_shred"
#define ST_RESPEN "Respen"
#define ST_VUL "Vul"
#define ST_RES "Res"
#define ST_EHR "Ehr"
#define ST_EnergyRecharge "Energy_recharge"
#define ST_TRUE "True_Damage"
#define ST_FLAT_SPD "Flat-Speed"
#define ST_SPD_PERCENT "Speed%"
#define ST_TOTAL_TRUE "True_Damage_From_Total"
#define ST_HEALING_OUT "outGoingHeal"
#define ST_HEALING_IN "inComingHeal"
#define ST_SHEILD "SheildBonus"

#define AT_TEMP "Temporary"
#define AT_NONE "None"
#define AT_BASIC_ATK "Basic_Attack"
#define AT_SKILL "Skill"
#define AT_ULT "Ultimate"
#define AT_Fua "Fua"

#define TYPE_STD "Standard"
#define ALLYTYPE_BACKUP "Backup"

using std::cout;
using std::setprecision;
using std::fixed;
using std::vector;
using std::string;
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
class Action_value_stats;
class Unit;
class SubUnit;
class Ally;
class Enemy;
typedef unordered_map<string,double> Common_stats; 
typedef unordered_map<string,Common_stats> Common_stats_type; 
typedef unordered_map<string,Common_stats_type> Common_stats_each_element;
//Action_Data
class Heal_data;
class HealRatio;
class PointerWithValue;
class Ratio_data;
class Hit_spilt;
class ActionData;
//Trigger_Function
class TriggerFunc;
class TriggerByYourSelf_Func;
class TriggerByAction_Func;
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
//StatsSet
Ally* SetAllyBasicStats(double BaseSpeed,double Max_Energy,double Ult_cost,int Eidolon,string Element_type,string Path,string Name,string UnitType);
void SetMemoStats(Ally* ptr, double Hp_ratio, double Speed_ratio, std::string Element_type, std::string Name, std::string Side);
void SetCountdownStats(Ally* ptr, std::string Name);
void SetSummonStats(Ally* ptr, double BaseSpeed, std::string Name);

/*------Combat------*/

//Energy
void Increase_energy(Ally* ptr, double Energy);
void Increase_energy(SubUnit *ptr, double Energy);
void Increase_energy(Ally* ptr, double Energy_percent, double Flat_energy);
void Increase_energy(SubUnit *ptr, double Energy_percent, double Flat_energy);
bool ultUseCheck(Ally* ptr);
void allUltimateCheck();

//Action_value
bool compareActionValueStats(Action_value_stats* a, Action_value_stats* b);
void Update_Max_atv(Action_value_stats* ptr);
void atv_reset(Action_value_stats* ptr);
void All_atv_reset();
void Action_forward(Action_value_stats* ptr, double fwd);
void All_Action_forward(double fwd);
void Speed_Buff(Action_value_stats* ptr, double spd_percent, double flat_spd);
void Find_turn();
void Atv_fix(double Atv_reduce);

//Buff_Speed
void Speed_Buff_All_Ally(double spd_percent, double flat_spd);
void Speed_Buff_All_Ally(double spd_percent, double flat_spd, std::string Buff_name);
void Speed_Buff_All_Ally_Exclude_Buffer(double spd_percent, double flat_spd, std::string Buffer);
void Speed_Buff_All_Ally_Exclude_Buffer(double spd_percent, double flat_spd, std::string Buffer, std::string Buff_name);

//Buff_Stats.h
void Buff_single_target(SubUnit *ptr, string stats_type, string Attack_type, double Value);
void Buff_single_target(SubUnit *ptr, string stats_type, string Attack_type, string Element, double Value);

void Buff_single_with_all_memo(Ally *ptr, string stats_type, string Attack_type, double Value);
void Buff_single_with_all_memo(Ally *ptr, string stats_type, string Attack_type, string Element, double Value);

void Buff_single_with_all_memo_each(Ally *ptr, string stats_type, string Attack_type, double Value, string Buff_name);
void Buff_single_with_all_memo_each(Ally *ptr, string stats_type, string Attack_type, string Element, double Value, string Buff_name);

void Buff_All_Ally(string stats_type, string Attack_type, double Value);
void Buff_All_Ally(string stats_type, string Attack_type, string Element, double Value);

void Buff_All_Ally_Each_Ally(string stats_type, string Attack_type, double Value, string Buff_name);
void Buff_All_Ally_Each_Ally(string stats_type, string Attack_type, string Element, double Value, string Buff_name);

void Buff_All_Ally_Excluding_Buffer(string stats_type, string Attack_type, double Value, string Buffer_name);
void Buff_All_Ally_Excluding_Buffer(string stats_type, string Attack_type, string Element, double Value, string Buffer_name);

void Buff_All_Ally_Each_Ally_Excluding_Buffer(string stats_type, string Attack_type, double Value, string Buff_name, string Buffer_name);
void Buff_All_Ally_Each_Ally_Excluding_Buffer(string stats_type, string Attack_type, string Element, double Value, string Buff_name, string Buffer_name);

void Stack_Buff_single_target(SubUnit *ptr, string stats_type, string Attack_type, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);
void Stack_Buff_single_target(SubUnit *ptr, string stats_type, string Attack_type, string Element, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);

void Stack_Buff_single_with_all_memo(Ally *ptr, string stats_type, string Attack_type, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);
void Stack_Buff_single_with_all_memo(Ally *ptr, string stats_type, string Attack_type, string Element, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);

void Stack_Buff_All_Ally(string stats_type, string Attack_type, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);
void Stack_Buff_All_Ally(string stats_type, string Attack_type, string Element, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);

void Stack_Buff_All_Ally_Excluding_Buffer(string stats_type, string Attack_type, string Element, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);
void Stack_Buff_All_Ally_Excluding_Buffer(string stats_type, string Attack_type, string Element, string Buffer_name, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);


//Buff.h

SubUnit* chooseSubUnitBuff(SubUnit* ptr);
Ally* chooseCharacterBuff(SubUnit* ptr);
Enemy* chooseEnemyTarget(SubUnit* ptr);
void StatsAdjust(SubUnit *ptr,string ST);
void AtkAdjust(SubUnit *ptr);
void HpAdjust(SubUnit *ptr);
void DefAdjust(SubUnit *ptr);
void Extend_Buff_single_target(SubUnit* ptr, std::string Buff_name, int Turn_extend);
void Extend_Buff_single_with_all_memo(Ally* ptr, std::string Buff_name, int Turn_extend);
void Extend_Buff_All_Ally(std::string Buff_name, int Turn_extend);
void Extend_Buff_All_Ally_Excluding_Buffer(std::string Buff_name, int Turn_extend, std::string Buffer_name);

void Extend_Debuff_single_target(Enemy* ptr, std::string Debuff_name, int Turn_extend);
void Extend_Debuff_All_Enemy(std::string Debuff_name, int Turn_extend);

bool Buff_end(SubUnit* ptr, std::string Buff_name);
bool Debuff_end(Enemy* ptr, std::string Debuff_name);
bool Buff_check(SubUnit* ptr, std::string Buff_name);
bool Debuff_check(Enemy* ptr, std::string Debuff_name);

//Debuff_Stats
void debuffAllEnemyApplyVer(SubUnit *ptr, string stats_type, string Attack_type, double Value, string Debuff_Name);
void debuffAllEnemyApplyVer(SubUnit *ptr, string stats_type, string Attack_type, string Element, double Value, string Debuff_Name);
void debuffAllEnemyMarkVer(SubUnit *ptr, string stats_type, string Attack_type, double Value, string Debuff_Name);
void debuffAllEnemyMarkVer(SubUnit *ptr, string stats_type, string Attack_type, string Element, double Value, string Debuff_Name);
void debuffAllEnemyStack(SubUnit *ptr, string stats_type, string Attack_type, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);
void debuffAllEnemyStack(SubUnit *ptr, string stats_type, string Attack_type, string Element, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);


//Combat
void Take_action();
void Deal_damage();
void Attack(ActionData& data_);
void Heal(Heal_data& Healptr);
void Skill_point(SubUnit *ptr,int p);
void Superbreak_trigger(ActionData& data_, double Superbreak_ratio);
void Dot_trigger(double Dot_ratio, Enemy* target, std::string Dot_type);
void Toughness_break(ActionData &data_, Enemy* target);

//ChangeHP.h

void Healing(Heal_data& Healptr);
void Healing(HealRatio& Healptr,SubUnit *Healer,SubUnit *target);
void Healing(HealRatio& healRatio,SubUnit *Healer);
void Healing(HealRatio& healRatioMain,HealRatio& healRatio,SubUnit *Healer,SubUnit *target);
void IncreaseCurrentHP(SubUnit *ptr,double Value);
void IncreaseHP(SubUnit *Healer,SubUnit *target,double Value);
void DecreaseCurrentHP(SubUnit *ptr,double Value);
void DecreaseHP(SubUnit *target,Unit *Trigger,double Value,double percentFromTotalHP,double percentFromCurrentHP);
void DecreaseHP(Unit *Trigger,double Value,double percentFromTotalHP,double percentFromCurrentHP);
void DecreaseHP(Unit *Trigger,vector<SubUnit*> target,double Value,double percentFromTotalHP,double percentFromCurrentHP);
void DecreaseHP(Unit *Trigger,string Name,double Value,double percentFromTotalHP,double percentFromCurrentHP);
//EnemyCombat.h
void EnemyHit(Enemy *Attacker);
void EnemyHit(Enemy *Attacker,vector<SubUnit*> target);
void DamageFormEnemy(Enemy *Attacker,vector<SubUnit*> target);
/*------Calculate------*/

//Calculate_damage
void Cal_Damage(ActionData& data_, Enemy* target, Ratio_data Skill_mtpr);
void Cal_Toughness_reduction(ActionData& data_, Enemy* target, double Toughness_reduce);
void Cal_Break_damage(ActionData& data_, Enemy* target, double& Constant);
void Cal_Freeze_damage(ActionData& data_, Enemy* target);
void Cal_Dot_damage(ActionData& data_, Enemy* target, double Dot_ratio);
void Cal_Dot_Toughness_break_damage(ActionData& data_, Enemy* target, double Dot_ratio);
void Cal_Superbreak_damage(ActionData& data_, Enemy* target, double Superbreak_ratio);
void Cal_Additional_damage(ActionData& data_, Enemy* target, Ratio_data Skill_mtpr);
void Cal_TrueDamage(ActionData &data_,Enemy *target,double Damage);
double Cal_Total_Toughness_Reduce(ActionData& data_, Enemy* target, double Base_Toughness_reduce);


//CalDmgReceive.h
double calculateDmgReceive(Enemy *Attacker,SubUnit *ptr,double ratio);
double calEnemyATK(Enemy *enemy);
double calAllyDefMultiplier(SubUnit *ptr);
//Calculate_Stats
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

double Cal_Atk_multiplier(ActionData& data_, Enemy* target);
double Cal_Hp_multiplier(ActionData& data_, Enemy* target);
double Cal_Def_multiplier(ActionData& data_, Enemy* target);
double Cal_Bonus_dmg_multiplier(ActionData& data_, Enemy* target);
double Cal_Crit_multiplier(ActionData& data_, Enemy* target);
double Cal_Crit_rate_multiplier(ActionData& data_, Enemy* target);
double Cal_Crit_dam_multiplier(ActionData& data_, Enemy* target);
double Cal_Def_shred_multiplier(ActionData& data_, Enemy* target);
double Cal_Respen_multiplier(ActionData& data_, Enemy* target);
double Cal_Vul_multiplier(ActionData& data_, Enemy* target);
double Cal_BreakEffect_multiplier(ActionData& data_, Enemy* target);
double Cal_Toughness_multiplier(ActionData& data_, Enemy* target);
double Cal_Superbreak_DamageIncrease_multiplier(ActionData& data_, Enemy* target);
double Cal_Mitigation_multiplier(ActionData& data_, Enemy* target);
//CalRequireStats.h


//Calculate_Heal.h
double calculateHeal(Heal_data& Healptr ,HealRatio healRatio,SubUnit *target);
double calculateHeal(HealRatio healRatio,SubUnit *Healer,SubUnit *target);
double calculateHealFromLostHP(SubUnit *target,double percent);
double calculateHealFromTotalHP(SubUnit *target,double percent);

//Calculate_Stats_Heal.h
double Cal_Atk_multiplier(Heal_data& ptr);
double Cal_Hp_multiplier(Heal_data& ptr);
double Cal_Def_multiplier(Heal_data& ptr);
double Cal_HealBonus_multiplier(Heal_data& ptr,SubUnit *target);
double Cal_HealBonus_multiplier(SubUnit *Healer,SubUnit *target);

//CalDamageNote.h
bool changeMaxDamage(Ally *ptr);
void Cal_AverageDamage(Ally *ptr);
double Cal_AvgToughnessMultiplier(Enemy* target, double Total_atv);
void Cal_DamageSummary();
void Cal_DamageNote(ActionData &data_,Enemy *target,double damage);

/*------Event------*/

//Event
void allEventBeforeTurn();
void allEventAfterTurn();
void allEventBuff(ActionData& data_);
void allEventBeforeAttack(ActionData& data_);
void allEventAfterAttack(ActionData& data_);
void allEventWhenAttack(ActionData& data_);
void allEventHeal(SubUnit *Healer,SubUnit *target,double Value);
void allEventChangeHP(Unit *Trigger,SubUnit *target,double Value);
void allEventWhenToughnessBreak(ActionData& data_, Enemy* target);
void allEventWhenEnemyHit(Enemy* Attacker,vector<SubUnit*> vec);
void allEventWhenEnergyIncrease(Ally* target, double Energy);
void allEventSkillPoint(SubUnit* ptr, int p);
void allEventAttackHitCount(ActionData& data_, int Hit_cnt, int Total_Hit_cnt);
void allEventAdjustStats(SubUnit *ptr,string ST);
void allEventApplyDebuff(SubUnit* ptr, Enemy* target);
void allEventWhenEnemyDeath(SubUnit* Killer, Enemy* target);
void allEventWhenAllyDeath(SubUnit *Target);

/*------Event------*/

//SetCombat
void Setup();
void Reset();
void Start_game();
void EndWave(double Total_atv);
void Start_wave(int WAVE);

//SetEnemy
void Setup_enemy(double speed,double energy,double Toughness,double skillRatio,int attackCooldown,string type);


//Stats_Reset
void Basic_reset();
void Memosprite_reset();
void Summon_reset();
void Countdown_reset();

//Substats_Reset
void Set_Stats(Ally* ptr);
bool Reroll_substats();
bool StandardReroll(Ally* ptr);
bool AllCombinationReroll(Ally* ptr);
bool AllPossibleReroll(Ally* ptr);


/*  None 
    Basic_Attack
    Skill
    Ultimate 
    Dot 
    Fua 
    Summon 
    Break_dmg 
    Super_break 
*/
//char func
namespace CharCmd{
void Set_Technique(Ally *ptr,int tech);
void Timing_print(Ally *ptr);
bool Using_Skill(Ally *ptr);
//bool Enemy_got_hit(Enemy *ptr,Combat_data &data_);
void printUltStart(string name);
void printUltEnd(string name);
void Set_Substats(Ally *ptr,int sub);
void Set_Substats(Ally *ptr,int index,int sub);
void Switch_Substats(Ally *ptr,string temp1,string temp2);
void Switch_Substats_toFirst(Ally *ptr,string temp);
void Set_Target_Buff(SubUnit *ptr,int num,int subnum);
void Set_Target_Buff(SubUnit *ptr,int num);
void Set_Speed_Boot(Ally *ptr,bool Bool);
void Set_Er_Rope(Ally *ptr,bool Bool);
void Set_Body_Critdam(Ally *ptr,bool Bool);

void Set_Tune_Speed(Ally *ptr,double value);
void Set_Reroll_check(Ally *ptr,bool Bool);
void Set_Other_buff(Ally *ptr,bool Bool);
}

#endif
