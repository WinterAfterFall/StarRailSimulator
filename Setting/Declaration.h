#ifndef Define_H
#define Define_H
#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12

#define PRIORITY_IMMEDIATELY 100
#define PRIORITY_BUFF 3
#define PRIORITY_DEBUFF 2
#define PRIORITY_ACTTACK 0
#define PRIORITY_ACTION -1

#define TYPE_TEMP "Temporary"


using std::cout ;
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



/*------Unit------*/
//Stats
class Func_class;
class Action_value_stats;
class Unit;
class Sub_Unit;
class Ally;
class Enemy;
typedef unordered_map<string,double> Common_stats; 
typedef unordered_map<string,Common_stats> Common_stats_type; 
typedef unordered_map<string,Common_stats_type> Common_stats_each_element;
//Action_Data
class Heal_data;
class Heal_data::HealRatio;
class PointerWithValue;
class Ratio_data;
class Hit_spilt;
class Combat_data;
//Trigger_Function
class TriggerFunc;
class TriggerByYourSelf_Func;
class TriggerByAction_Func;
class TriggerByStats;
class TriggerBySomeAlly_Func;
class TriggerHealing;
class TriggerChangeHP;
class TriggerByEnemyHit;
class TriggerDot_Func;
class TriggerEnergy_Increase_Func;
class TriggerSkill_point_func;
class TriggerHit_Count_func;
//StatsSet
void SetBaseStats(Sub_Unit* ptr, double BaseHp, double BaseAtk, double BaseDef);
void SetBasicStats(Ally* ptr, double BaseSpeed, double Max_Energy, double Ult_cost, int Eidolon, std::string Element_type, std::string Path, int num, std::string Name, std::string Side);
void SetMemoStats(Ally* ptr, double Hp_ratio, double Speed_ratio, std::string Element_type, std::string Name, std::string Side);
void SetCountdownStats(Ally* ptr, std::string Name);
void SetSummonStats(Ally* ptr, double BaseSpeed, std::string Name);

/*------Combat------*/

//Energy
void Increase_energy(Ally* ptr, double Energy);
void Increase_energy(Ally* ptr, double Energy_percent, double Flat_energy);
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
void Buff_single_target(Sub_Unit *ptr, string stats_type, string Attack_type, double Value);
void Buff_single_target(Sub_Unit *ptr, string stats_type, string Attack_type, string Element, double Value);

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

void Stack_Buff_single_target(Sub_Unit *ptr, string stats_type, string Attack_type, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);
void Stack_Buff_single_target(Sub_Unit *ptr, string stats_type, string Attack_type, string Element, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);

void Stack_Buff_single_with_all_memo(Ally *ptr, string stats_type, string Attack_type, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);
void Stack_Buff_single_with_all_memo(Ally *ptr, string stats_type, string Attack_type, string Element, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);

void Stack_Buff_All_Ally(string stats_type, string Attack_type, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);
void Stack_Buff_All_Ally(string stats_type, string Attack_type, string Element, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);



//Buff.h
Sub_Unit* isSubUnitCheck();
Enemy* isEnemyCheck();
Sub_Unit* isSubUnitCheck(Action_value_stats *ptr);
Enemy* isEnemyCheck(Action_value_stats *ptr);

Sub_Unit* chooseSubUnitBuff(Sub_Unit* ptr);
Ally* chooseCharacterBuff(Sub_Unit* ptr);
Enemy* chooseEnemyTarget(Sub_Unit* ptr);
void StatsAdjust(Sub_Unit *ptr,string statsType);
void AtkAdjust(Sub_Unit *ptr);
void HpAdjust(Sub_Unit *ptr);
void DefAdjust(Sub_Unit *ptr);
void Extend_Buff_single_target(Sub_Unit* ptr, std::string Buff_name, int Turn_extend);
void Extend_Buff_single_with_all_memo(Ally* ptr, std::string Buff_name, int Turn_extend);
void Extend_Buff_All_Ally(std::string Buff_name, int Turn_extend);
void Extend_Buff_All_Ally_Excluding_Buffer(std::string Buff_name, int Turn_extend, std::string Buffer_name);

void Extend_Debuff_single_target(Enemy* ptr, std::string Debuff_name, int Turn_extend);
void Extend_Debuff_All_Enemy(std::string Debuff_name, int Turn_extend);

bool Buff_end(Sub_Unit* ptr, std::string Buff_name);
bool Debuff_end(Enemy* ptr, std::string Debuff_name);
bool Buff_check(Sub_Unit* ptr, std::string Buff_name);
bool Debuff_check(Enemy* ptr, std::string Debuff_name);

//Debuff_Stats
void Debuff_single_target(Enemy* ptr, string stats_type, string Attack_type, double Value);
void Debuff_single_target(Enemy* ptr, string stats_type, string Attack_type, string Element, double Value);

void Debuff_All_Enemy_Apply_ver(Sub_Unit* ptr, string stats_type, string Attack_type, double Value, string Debuff_Name);
void Debuff_All_Enemy_Apply_ver(Sub_Unit* ptr, string stats_type, string Attack_type, string Element, double Value, string Debuff_Name);

void Stack_Debuff_single_target(Enemy* ptr, string stats_type, string Attack_type, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);
void Stack_Debuff_single_target(Enemy* ptr, string stats_type, string Attack_type, string Element, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);

void Stack_Debuff_All_Enemy(Sub_Unit* ptr, string stats_type, string Attack_type, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);
void Stack_Debuff_All_Enemy(Sub_Unit* ptr, string stats_type, string Attack_type, string Element, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);


//Combat
void Take_action();
void Deal_damage();
void Attack(Combat_data& data_);
void Heal(Heal_data* Healptr);
void Skill_point(Sub_Unit *ptr,int p);
void Apply_debuff(Sub_Unit *ptr,Enemy* target);
void Superbreak_trigger(Combat_data& data_, double Superbreak_ratio);
void Dot_trigger(double Dot_ratio, Enemy* target, std::string Dot_type);
void Toughness_break(Combat_data &data_, Enemy* target);

//ChangeHP.h

void Healing(Heal_data* Healptr);
void IncreaseCurrentHP(Sub_Unit *ptr,double Value);
void IncreaseHP(Sub_Unit *Healer,Sub_Unit *target,double Value);
void DecreaseCurrentHP(Sub_Unit *ptr,double Value);
void DecreaseHP(Sub_Unit *target,double Value,double percentFromTotalHP,double percentFromCurrentHP);

/*------Calculate------*/

//Calculate_damage
void Cal_Damage(Combat_data& data_, Enemy* target, Ratio_data Skill_mtpr);
void Cal_Toughness_reduction(Combat_data& data_, Enemy* target, double Toughness_reduce);
void Cal_Break_damage(Combat_data& data_, Enemy* target, double& Constant);
void Cal_Freeze_damage(Combat_data& data_, Enemy* target);
void Cal_Dot_damage(Combat_data& data_, Enemy* target, double Dot_ratio);
void Cal_Dot_Toughness_break_damage(Combat_data& data_, Enemy* target, double Dot_ratio);
void Cal_Superbreak_damage(Combat_data& data_, Enemy* target, double Superbreak_ratio);
void Cal_Additional_damage(Combat_data& data_, Enemy* target, Ratio_data Skill_mtpr);
double Cal_TotalPercentToughnessBrokenTime(Enemy* target, double Total_atv);
double Cal_Total_Toughness_Reduce(Combat_data& data_, Enemy* target, double Base_Toughness_reduce);
void Cal_ToughnessMultiplierAverage();

//Calculate_Stats
double calculateAtkOnStats(Sub_Unit* ptr);
double calculateHpOnStats(Sub_Unit* ptr);
double calculateDefOnStats(Sub_Unit* ptr);
double calculateSpeedOnStats(Sub_Unit* ptr);
double calculateCritrateOnStats(Sub_Unit* ptr);
double calculateCritdamOnStats(Sub_Unit* ptr);
double calculateBreakEffectOnStats(Sub_Unit* ptr);
double calculateHPLost(Sub_Unit *ptr);

double calculateAtkForBuff(Sub_Unit* ptr, double ratio);
double calculateHpForBuff(Sub_Unit* ptr, double ratio);
double calculateDefForBuff(Sub_Unit* ptr, double ratio);
double calculateSpeedForBuff(Sub_Unit* ptr, double ratio);
double calculateCritrateForBuff(Sub_Unit* ptr, double ratio);
double calculateCritdamForBuff(Sub_Unit* ptr, double ratio);
double calculateBreakEffectForBuff(Sub_Unit* ptr, double ratio);

double Cal_Atk_multiplier(Combat_data& data_, Enemy* target);
double Cal_Hp_multiplier(Combat_data& data_, Enemy* target);
double Cal_Def_multiplier(Combat_data& data_, Enemy* target);
double Cal_Bonus_dmg_multiplier(Combat_data& data_, Enemy* target);
double Cal_Crit_multiplier(Combat_data& data_, Enemy* target);
double Cal_Crit_rate_multiplier(Combat_data& data_, Enemy* target);
double Cal_Crit_dam_multiplier(Combat_data& data_, Enemy* target);
double Cal_Def_shred_multiplier(Combat_data& data_, Enemy* target);
double Cal_Respen_multiplier(Combat_data& data_, Enemy* target);
double Cal_Vul_multiplier(Combat_data& data_, Enemy* target);
double Cal_BreakEffect_multiplier(Combat_data& data_, Enemy* target);
double Cal_Toughness_multiplier(Combat_data& data_, Enemy* target);
double Cal_Superbreak_DamageIncrease_multiplier(Combat_data& data_, Enemy* target);
double Cal_Mitigation_multiplier(Combat_data& data_, Enemy* target);

void Cal_effect_hit_rate(Ally* ptr, double Base_chance);
void Cal_Speed_Needed(Ally* ptr, double Speed_Need);


//Calculate_Heal.h
double calculateHeal(Heal_data* Healptr ,Heal_data::HealRatio healRatio,Sub_Unit *target);
double calculateHealFromLostHP(Sub_Unit *target,double percent);
double calculateHealFromTotalHP(Sub_Unit *target,double percent);

//Calculate_Stats_Heal.h
double Cal_Atk_multiplier(Heal_data* ptr);
double Cal_Hp_multiplier(Heal_data* ptr);
double Cal_Def_multiplier(Heal_data* ptr);
double Cal_HealBonus_multiplier(Heal_data* ptr,Sub_Unit *target);

/*------Event------*/

//Event
void allEventBeforeTurn();
void allEventAfterTurn();
void allEventBuff(Combat_data& data_);
void allEventBeforeAttack(Combat_data& data_);
void allEventAfterAttack(Combat_data& data_);
void allEventWhenAttack(Combat_data& data_);
void allEventHeal(Heal_data* Healptr );
void allEventChangeHP(Sub_Unit *Healer,Sub_Unit *target,double Value);
void allEventWhenToughnessBreak(Combat_data& data_, Enemy* target);
void allEventWhenEnemyHit(Enemy* Attacker,vector<Sub_Unit*> vec);
void allEventWhenEnergyIncrease(Ally* target, double Energy);
void allEventSkillPoint(Sub_Unit* ptr, int p);
void allEventAttackHitCount(Combat_data& data_, int Hit_cnt, int Total_Hit_cnt);
void allEventAdjustStats(Sub_Unit *ptr,string statsType);
void allEventApplyDebuff(Sub_Unit* ptr, Enemy* target);
void allEventWhenEnemyDeath(Sub_Unit* Killer, Enemy* target);

/*------Event------*/

//SetCombat
void Setup();
void Reset();
void Start_game();
void EndWave(double Total_atv);
void Start_wave(int WAVE);

//SetEnemy
void Enemy_func(Unit* ptr);
void Setup_enemy(int num, double speed, double energy, double Toughness, std::string type);
void EnemyHit(Enemy *Attacker);
void EnemyHit(Enemy *Attacker,vector<Sub_Unit*> target);

//Stats_Reset
void Basic_reset();
void Memosprite_reset();
void Summon_reset();
void Countdown_reset();

//Substats_Reset
void Set_Stats(Ally* ptr);
bool Reroll_substats(Ally* ptr);
bool Permutation_Substats(Ally* ptr);

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
namespace Char_Command{
    void Set_Technique(Ally *ptr,int tech);
void Timing_print(Ally *ptr);
bool Using_Skill(Ally *ptr);
//bool Enemy_got_hit(Enemy *ptr,Combat_data &data_);
void Set_Substats(Ally *ptr,int sub);
void Set_Substats(Ally *ptr,int index,int sub);
void Switch_Substats(Ally *ptr,string temp1,string temp2);
void Switch_Substats_toFirst(Ally *ptr,string temp);
void Set_Target_Buff(Sub_Unit *ptr,int num,int subnum);
void Set_Target_Buff(Sub_Unit *ptr,int num);
void Set_Speed_Boot(Ally *ptr,bool Bool);
void Set_Er_Rope(Ally *ptr,bool Bool);
void Set_Body_Critdam(Ally *ptr,bool Bool);

void Set_Tune_Speed(Ally *ptr,double value);
void Set_Reroll_check(Ally *ptr,bool Bool);
void Set_Other_buff(Ally *ptr,bool Bool);
}

#endif
