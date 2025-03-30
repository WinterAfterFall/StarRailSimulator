#ifndef STATS_H
#define STATS_H
#include <bits/stdc++.h>
#include "../Setting/Control_panel.h"
using namespace std;
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12



class Func_class{
    public:
    string Name;
    function<void(Ally *ptr)> Print_Func;
};
// Action value stats for a unit (atv)
class Action_value_stats {
public:
    double Base_speed = 0.01;//*
    double Flat_Speed = 0;
    double Speed_percent = 0;
    double atv ;//*
    double Max_atv;//*
    int turn_cnt = 0;
    int Unit_num = 0;//*
    string Side;//Memosprite Ally Summon
    int priority = 0;
    string Char_Name;
    string Unit_Name;//ชื่อเจ้าของเทิร์น

    Unit* ptr_to_unit = nullptr; //* // This will be set to point back to the unit (Ally or Enemy)

    bool isSameAlly(string name){
        if(this->Char_Name == name)return true;
        return false;
    }
    bool isSameUnit(string name){
        if(this->Unit_Name == name)return true;
        return false;
    }

};
// Base Unit class
class Unit {
public:
    unique_ptr<Action_value_stats> Atv_stats;  // Moved Atv_stats here to be shared by both Ally and Enemy
    function<void()> Turn_func ;
    Common_stats_each_element Stats_each_element;//Ice Quantum
    Common_stats_type Stats_type;// Atk% Flat_Atk Def% Dmg% Crit_rate Crit_dam Def_shred Respen Vul Break_effect Weakness_Break_Efficiency HealingBonus 
    // Constructor to initialize Atv_stats and set ptr_to_unit to 'this'
    Unit() {
        Atv_stats = make_unique<Action_value_stats>();  // Create Atv_stats in Unit
        Atv_stats->ptr_to_unit = this;  // Set ptr_to_unit to this object (Unit, Ally, or Enemy)
    }
       
    //double Mitigation = 0;
    
    
    virtual ~Unit() {}  // Virtual destructor to ensure proper cleanup of derived classes
};

// Common stats for all units
// Common stats for elements



// Ally stats
class Sub_Unit : public Unit {
public:
    double Unit_Speed_Ratio = 0;
    double Unit_Hp_Ratio = 0 ;
    double Base_atk;//*
    double Base_hp;//*
    double Base_def;//*

    double totalATK;
    double totalHP;
    double totalDEF;

    double currentHP;
    double currentSheild;
    
    unordered_map<string,int> Stack;
    unordered_map<string,double> Buff_note;
    unordered_map<string,int> Buff_countdown;
    unordered_map<string,bool> Buff_check;
    unordered_map<string,Sub_Unit*> buffTarget;
    unordered_map<string,double> damageAvgNote;
    unordered_map<string,double> damageRealTimeNote;

    //Max Damage
    unordered_map<string,double> maxDamageAvgNote;
    unordered_map<string,double> maxDamageRealTimeNote;

    
    vector<string> Element_type ;//*
    
    //string Target_Buff = "Ally";
    int allyTargetNum = Main_dps_num;
    int Sub_Unit_num = 0;
    int Enemy_target_num = Main_Enemy_num;
    Ally* ptr_to_unit = nullptr;
    //temp 
    // Constructor now calls the base class constructor to initialize Atv_stats and set ptr_to_unit
    Sub_Unit() : Unit() {
          // Call Unit constructor to initialize Atv_stats and set ptr_to_unit  // Using unique_ptr for stats
    }

    ~Sub_Unit() {}
    bool isSameAlly(Sub_Unit *ptr){
        if(this->Atv_stats->Char_Name== ptr->Atv_stats->Char_Name)return true;
        return false;
    
    }
    bool isSameUnit(Sub_Unit *ptr){
        if(this->Atv_stats->Unit_Name == ptr->Atv_stats->Unit_Name)return true;
        return false;

    
    }
    bool isSameAlly(string name){
        if(this->Atv_stats->Char_Name == name)return true;
        return false;
    }
    bool isSameUnit(string name){
        if(this->Atv_stats->Unit_Name == name)return true;
        return false;
    }
    void setBuffCheck(string buffName,bool Bool){
        this->Buff_check[buffName]=Bool;
    }
};
// Enemy stats
// Ally class, derived from Unit
class Ally{
public:


    double Max_energy = -1;//*
    double Current_energy = -1;
    double Energy_recharge = 100;
    double Ult_cost = -1;//*
    Func_class Char;//*
    Func_class Light_cone;//*
    Func_class Relic;//*
    Func_class Planar;//*
    int Eidolon;//*

    vector<double> Normal_Damage;//*
    vector<double> Dot_damage;//*
    vector<double> Break_damage;//*
    vector<double> Superbreak_damage;//*
    vector<double> Max_Damage;//*
    vector<double> Max_Dot_damage;//*
    vector<double> Max_Break_damage;//*
    vector<double> Max_Superbreak_damage;//*

    vector<double> Average_damage_instance;
    double Average_Damage = 0;
    double Max_Average_Damage = 0;
    double Last_note = 0;

    double Total_damage;
    double Max = 0;
    vector<pair<string,int>> Substats;//*
    vector<int> Max_damage_Substats;//*
    bool Reroll_check=0;
    bool Stop_reroll=1;
    int Total_substats = 20;
    int Current_substats = Total_substats;

    int Separate_sub = 20;
    int Current_spilt = 0;
    int Current_sub_choose =0;
    unordered_map<int,double> Damage_data;
    unordered_map<string,pair<double,int>> StatsType_Compare;
    pair<double,double> StatsType_Compare_MAX_MIN;

    unordered_map<string,pair<double,int>> TotalSubstats_Compare;
    pair<double,double> TotalSubstats_Compare_MAX_MIN;


    vector<string> Path ;//*
    //*
    vector<unique_ptr<Unit>> Summon_ptr;  //
    vector<unique_ptr<Sub_Unit>> Sub_Unit_ptr;  // 
    vector<unique_ptr<Unit>> Countdown_ptr;  // 

    int Technique = 1;
    double Sub_effect_hit_rate_use = 0;
    double Sub_Speed_use = 0;
    vector<function<bool()>> ultCondition;

    bool Print =0;
    bool Wait_Other_Buff = 0;
    bool Er_Rope=0;
    bool Speed_Boot = 1;
    bool Element_Orb = 1;
    bool Body_CritDam = 0;
    double Speed_tune_value = 0;

    // Constructor now calls the base class constructor to initialize Atv_stats and set ptr_to_unit
    Ally() {  // Call Unit constructor to initialize Atv_stats and set ptr_to_unit
        Sub_Unit_ptr.resize(1);
        Sub_Unit_ptr[0] = make_unique<Sub_Unit>();
        Sub_Unit_ptr[0]->ptr_to_unit = this;
          // Using unique_ptr for stats
    }

    ~Ally() {}

    void SetRelic(bool Body_CritDam,bool Speed_Boot,bool Element_Orb,bool Er_Rope){
        this->Er_Rope = Er_Rope;
        this->Body_CritDam = Body_CritDam;
        this->Element_Orb = Element_Orb;
        this->Speed_Boot = Speed_Boot;
    }
    void setTotalSubstats(int Value,bool check){
        this->Total_substats=Value;
        this->Separate_sub=Value;
        this->Substats[0].second = Value;
        this->Reroll_check = check;
        this->Max_damage_Substats.resize(this->Substats.size());
    }
    void pushSubstats(string StatsType){
        this->Substats.push_back({StatsType,0});
    }
};

// Enemy class, derived from Unit
class Enemy : public Unit {
public:
    
      //*
   
    int Total_debuff = 0;
    unordered_map<string,int> Debuff;
    unordered_map<string,int> Debuff_time_count;

    double ATK = 718;
    double atkPercent = 0;
    double Energy_gen;
    double Max_toughness; 
    double Current_toughness;
    bool Toughness_status = 1;
    string Target_type = "";//*
    int attackCooldown = 3; 
    int attackStartAtTurn = 2;
    double skillRatio = 0;

    Sub_Unit *target = nullptr;

    int Bleed = 0,Bleeder = 0;
    int Burn = 0,Burner = 0;
    int Shock = 0,Shocker = 0;
    int Wind_shear = 0,Wind_shearer = 0;
    int  Wind_shear_stack = 0;
    int Freeze = 0;
    int Entanglement= 0,Entanglement_stack = 0;
    int Imprisonment = 0;
    unordered_map<string,bool> Weakness_type;
    
    double Total_toughness_broken_time =0;
    double when_toughness_broken;
 
    // Constructor now calls the base class constructor to initialize Atv_stats and set ptr_to_unit
    Enemy() : Unit() {  // Call Unit constructor to initialize Atv_stats and set ptr_to_unit
    
    }

    ~Enemy() {}
};
//check if it is ally unit

#endif