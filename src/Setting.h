#ifndef SETTING_H
#define SETTING_H
#include"Declaration/Function/Library.h"

int sp=3,Max_sp = 5,Total_wave=1;//1450
double Wave[3]={1100,450,450}; //1368.01 1442.83
bool Avg_damage_Mode = 1;
bool SuperBreak__Mode = 0;
int Main_dps_num = 1;
int Driver_num = 0;
int HealerNum = 0;
SPMode spMode = SPMode::Positive; //Positive Negative       
int Main_Enemy_num = 1;
int Adjacent_Enemy_num[2] = {2,3};
int Other_Enemy_num[2] = {4,5}; 

bool Print_Atv = 0;

int Total_ally = 0;
int Total_enemy = 0;
int Force_break = 0;

DriverType driverType  = DriverType::None;
vector<unique_ptr<CharUnit>> charUnit(1);
vector<unique_ptr<Enemy>> enemyUnit(1);
vector<CharUnit*> charList;
vector<AllyUnit*> allyList;
vector<Enemy*> enemyList;
vector<ActionValueStats*> atvList;

unordered_map<ElementType, double> Enemy_res = {
        {ElementType::Fire, 0.0},
        {ElementType::Ice, 0.0},
        {ElementType::Quantum, 0.0},
        {ElementType::Wind, 0.0},
        {ElementType::Lightning, 0.0},
        {ElementType::Physical, 0.0},
        {ElementType::Imaginary, 0.0}
};
unordered_map<ElementType, bool> Enemy_weak = {
        {ElementType::Fire, 1},
        {ElementType::Ice, 1},
        {ElementType::Quantum, 1},
        {ElementType::Wind, 1},
        {ElementType::Lightning, 1},
        {ElementType::Physical, 1},
        {ElementType::Imaginary, 1}
};
unordered_map<Path, double> tauntValueEachPath = {
    {Path::Abundance, 100},
    {Path::Preservation, 150},
    {Path::Hunt, 75},
    {Path::Erudition, 75},
    {Path::Destruction, 125},
    {Path::Harmony, 100},
    {Path::Nihility, 100},
    {Path::Remembrance, 100}
};
    
ActionValueStats* turn = nullptr;
queue<shared_ptr<ActionData>> Action_bar;

double Level_multiplier = 3767.5533;
double Current_atv =0;
double totalTaunt = 0;

PhaseStatus phaseStatus = PhaseStatus::None;
bool actionBarUse = 0;
bool AdjustCheck = 0;
bool Turn_Skip=0;
string Territory = "None";
int healCount;
int decreaseHPCount;
bool bestBounce = 0;;


int Sp_Safety = 1;
int Turn_priority = 0;
double Enemy_effect_res =40;

SubstatsRerollMode rerollSubstatsMode = SubstatsRerollMode::Standard; 
function<bool(CharUnit *ptr)> rerollFunction;

//-------- Trigger Function --------//
vector<TriggerByYourSelf_Func> Setup_List;
vector<TriggerByYourSelf_Func> Reset_List;
vector<TriggerByYourSelf_Func> WhenOnField_List;
vector<TriggerByYourSelf_Func> Tune_stats_List;
vector<TriggerByYourSelf_Func> Start_game_List;
vector<TriggerByYourSelf_Func> Start_wave_List;
vector<TriggerByYourSelf_Func> Before_turn_List;
vector<TriggerByYourSelf_Func> After_turn_List;
vector<TriggerByYourSelf_Func> Ultimate_List;
vector<TriggerByAlly_Func> WhenUseUlt_List;

vector<TriggerByAction_Func> BeforeAction_List;
vector<TriggerByAction_Func> AfterAction_List;
vector<TriggerByAllyAction_Func> AllyActionList;
vector<TriggerByAllyAttackAction_Func> BeforeAttackAction_List;
vector<TriggerByAllyAttackAction_Func> AfterAttackActionList;
vector<TriggerByAllyAttackAction_Func> BeforeAttack_List;
vector<TriggerByAllyAttackAction_Func> AfterAttack_List;
vector<TriggerByAllyAttackAction_Func> BeforeAttackPerHit_List;
vector<TriggerByAllyAttackAction_Func> AfterAttackPerHit_List;
vector<TriggerByAllyAttackAction_Func> When_attack_List;
vector<TriggerByAllyBuffAction_Func> Buff_List;

vector<TriggerByStats> Stats_Adjust_List;
vector<TriggerHealing> Healing_List;
vector<TriggerDecreaseHP> HPDecrease_List;
vector<TriggerAllyDeath> AllyDeath_List;

vector<TriggerBySomeAlly_Func> Toughness_break_List;
vector<TriggerBySomeAlly_Func> BeforeApplyDebuff;
vector<TriggerBySomeAlly_Func> AfterApplyDebuff;
vector<TriggerBySomeAlly_Func> Enemy_Death_List;

vector<TriggerByEnemyHit> Enemy_hit_List;
vector<TriggerDot_Func> Dot_List;
vector<TriggerEnergy_Increase_Func> When_Energy_Increase_List;
vector<TriggerSkill_point_func> Skill_point_List;
vector<TriggerAfterDealDamage> AfterDealingDamage_List;


string toString(ElementType type){
        switch(type) {
                case ElementType::Fire: return "Fire";
                case ElementType::Ice: return "Ice";
                case ElementType::Lightning: return "Lightning";
                case ElementType::Wind: return "Wind";
                case ElementType::Quantum: return "Quantum";
                case ElementType::Imaginary: return "Imaginary";
                case ElementType::Physical: return "Physical";
                default: return "";
        }
}
string toString(Stats type){
        switch(type) {
                case Stats::HP_P: return "HP%";
                case Stats::FLAT_HP: return "Flat HP";
                case Stats::ATK_P: return "ATK%";
                case Stats::FLAT_ATK: return "Flat ATK";
                case Stats::DEF_P: return "DEF%";
                case Stats::FLAT_DEF: return "Flat DEF";
                case Stats::DMG: return "DMG%";
                case Stats::CR: return "Crit rate";
                case Stats::CD: return "Crit dam";
                case Stats::BE: return "BE";
                case Stats::DEF_SHRED: return "DEF Shred";
                case Stats::RESPEN: return "Respen";
                case Stats::VUL: return "Vul";
                case Stats::RES: return "Res";
                case Stats::EHR: return "Ehr";
                case Stats::ER: return "ER";
                case Stats::HEALING_OUT: return "Healing out";
                case Stats::HEALING_IN: return "Healing in";
                case Stats::SHEILD: return "Sheild";
                case Stats::FLAT_SPD: return "Flat Spd";
                case Stats::SPD_P: return "Spd%";
                case Stats::BREAK_EFF: return "Break Effeciency";
                case Stats::TOUGH_REDUCE: return "Toughness Reduce";
                default: return "";
        }
}

#endif
