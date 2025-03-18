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

int Total_ally = 4;
int Total_enemy = 3;
int Force_break = 1;

string Driver_Type = "Double_turn"; //Swap_pull Always_pull Double_turn None
vector<unique_ptr<Ally>> Ally_unit(Total_ally+1);
vector<unique_ptr<Enemy>> Enemy_unit(Total_enemy+1);
unordered_map<std::string, double> Enemy_res = {
        {"Fire", 0.0},
        {"Ice", 0.0},
        {"Quantum", 0.0},
        {"Wind", 0.0},
        {"Lightning", 0.0},
        {"Physical", 0.0},
        {"Imaginary", 0.0}
    };
unordered_map<std::string, bool> Enemy_weak = {
         {"Fire", 0},
        {"Ice", 1},
        {"Quantum", 1},
        {"Wind", 1},
        {"Lightning", 1},
        {"Physical", 1},
        {"Imaginary", 1}
    };
Action_value_stats* turn = nullptr;

double Level_multiplier = 3767.5533;
double Current_atv =0;

bool Ult_After_Turn = 0;
bool After_Turn_Check = 0;
int Sp_Safety = 1;
bool Turn_Skip=0;
int Turn_priority = 0;
int ult_priority = 0;
double Enemy_effect_res =40;
bool Calculate_All_possible_mode =0;
int Robin_num = 0; 
int Aglaea_num = 0; 
double HP = 1200,ATK =476 ,DEF =397 ;
bool AdjustCheck = 0;
queue<Combat_data> Action_bar;
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

vector<TriggerByAction_Func> Before_attack_List;
vector<TriggerByAction_Func> After_attack_List;
vector<TriggerByAction_Func> When_attack_List;
vector<TriggerByAction_Func> Buff_List;

vector<TriggerByStats> Stats_Adjust_List;

vector<TriggerBySomeAlly_Func> Toughness_break_List;
vector<TriggerBySomeAlly_Func> Apply_debuff_List;
vector<TriggerBySomeAlly_Func> Enemy_Death_List;
vector<TriggerByEnemyHit> Enemy_hit_List;
vector<TriggerDot_Func> Dot_List;
vector<TriggerEnergy_Increase_Func> When_Energy_Increase_List;
vector<TriggerSkill_point_func> Skill_point_List;
vector<TriggerHit_Count_func> Hit_Count_List;

#endif