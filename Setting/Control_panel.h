#ifndef Control_H
#define Control_H
#include "Declaration.h"
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12

int sp=3,Max_sp = 5,Total_wave=1;//1450
double Wave[3]={1100,450,450}; //1368.01 1442.83
bool Avg_damage_Mode = 1;
bool SuperBreak__Mode = 0;
int Main_dps_num = 1;
int Driver_num = 0;
int HealerNum = 0;
string Sp_status ="Positive"; //Positive Negative       
int Main_Enemy_num = 1;
int Adjacent_Enemy_num[2] = {2,3};
int Other_Enemy_num[2] = {4,5}; 

bool Print_Atv = 0;
int Formula_check_mode = 0;
int Normal_Damage_Formula_check_mode = 0, Normal_Damage_check_mode =0;
int Additional_Damage_Formula_check_mode = 0, Additional_Damage_check_mode =0;

int SuperBreak_Formula_check_mode = 0;
int Break_Formula_check_mode =0;

int Total_ally = 0;
int Total_enemy = 0;
int Force_break = 1;

string Driver_Type = "Double_turn"; //Swap_pull Always_pull Double_turn None
vector<unique_ptr<Ally>> Ally_unit(1);
vector<unique_ptr<Enemy>> Enemy_unit(1);
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
unordered_map<std::string, double> tauntValueEachPath = {
    {"Abundance", 100},
    {"Preservation", 150},
    {"Hunt", 75},
    {"Erudition", 75},
    {"Destruction", 125},
    {"Harmony", 100},
    {"Nihility", 100},
    {"Remembrance", 100}
};
    
ActionValueStats* turn = nullptr;
queue<shared_ptr<ActionData>> Action_bar;

double Level_multiplier = 3767.5533;
double Current_atv =0;
double totalTaunt = 0;

bool Ult_After_Turn = 0;
bool After_Turn_Check = 0;
bool actionBarUse = 0;
bool AdjustCheck = 0;
bool Turn_Skip=0;
string Territory = AT_NONE;
int healCount;
int decreaseHPCount;
bool bestBounce = 0;;


int Sp_Safety = 1;
int Turn_priority = 0;
double Enemy_effect_res =40;

string rerollSubstatsMode = "Standard"; //Standard AllCombination AllPossible
function<bool(Ally *ptr)> rerollFunction;

//-------- Trigger Function --------//
vector<TriggerByYourSelf_Func> Reset_List;
vector<TriggerByYourSelf_Func> Setup_Memo_List;
vector<TriggerByYourSelf_Func> When_Combat_List;
vector<TriggerByYourSelf_Func> Tune_stats_List;
vector<TriggerByYourSelf_Func> Start_game_List;
vector<TriggerByYourSelf_Func> Start_wave_List;
vector<TriggerByYourSelf_Func> Before_turn_List;
vector<TriggerByYourSelf_Func> After_turn_List;
vector<TriggerByYourSelf_Func> Ultimate_List;

vector<TriggerByAction_Func> BeforeAction_List;
vector<TriggerByAction_Func> AfterAction_List;
vector<TriggerByAllyAction_Func> AllyActionList;
vector<TriggerByAllyAttackAction_Func> Before_attack_List;
vector<TriggerByAllyAttackAction_Func> After_attack_List;
vector<TriggerByAllyAttackAction_Func> When_attack_List;
vector<TriggerByAllyAttackAction_Func> Hit_Count_List;
vector<TriggerByAllyBuffAction_Func> Buff_List;

vector<TriggerByStats> Stats_Adjust_List;
vector<TriggerHealing> Healing_List;
vector<TriggerDecreaseHP> HPDecrease_List;
vector<TriggerAllyDeath> AllyDeath_List;

vector<TriggerBySomeAlly_Func> Toughness_break_List;
vector<TriggerBySomeAlly_Func> Apply_debuff_List;
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

#endif