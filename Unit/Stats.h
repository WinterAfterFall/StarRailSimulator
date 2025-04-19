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
    string Type;
    int priority = 0;
    string Char_Name;
    string Unit_Name;//ชื่อเจ้าของเทิร์น

    Unit* ptr_to_unit = nullptr; //* // This will be set to point back to the unit (Ally or Enemy)

    bool isSameCharName(string name){
        if(this->Char_Name == name)return true;
        return false;
    }
    bool isSameUnitName(string name){
        if(this->Unit_Name == name)return true;
        return false;
    }
    bool isSameUnit(SubUnit *ptr);
    SubUnit* canCastToSubUnit();
    Enemy* canCastToEnemy();

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
    int getNum(){
        return this->Atv_stats->Unit_num;
    }
    SubUnit* canCastToSubUnit();
    Enemy* canCastToEnemy();
    
    virtual ~Unit() {}  // Virtual destructor to ensure proper cleanup of derived classes
};

// Common stats for all units
// Common stats for elements



// Ally stats
class SubUnit : public Unit {
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
    unordered_map<string,SubUnit*> buffSubUnitTarget;
    unordered_map<string,Ally*> buffAllyTarget;

    vector<function<bool()>> changeTargetCondition;
    vector<function<bool()>> changeTargetImmediatelyCondtion;

    
    vector<string> Element_type ;//*
    
    double tauntBase = 0;
    double taunt = 0;
    double tauntMtpr = 1;
    //string Target_Buff = "Ally";
    int defaultAllyTargetNum = Main_dps_num;
    int defaultSubUnitTargetNum = 0;
    int currentAllyTargetNum = Main_dps_num;
    int currentSubUnitTargetNum = 0;
    int Enemy_target_num = Main_Enemy_num;
    Ally* ptr_to_unit = nullptr;
    //temp 
    // Constructor now calls the base class constructor to initialize Atv_stats and set ptr_to_unit
    SubUnit() : Unit() {
          // Call Unit constructor to initialize Atv_stats and set ptr_to_unit  // Using unique_ptr for stats
    }

    void tauntMtprChange(int value){
        tauntMtpr += value;
        totalTaunt -= taunt;
        taunt = tauntBase * tauntMtpr/100.0;
        totalTaunt += taunt;
    }
    double calHitChance(){
        return (taunt/totalTaunt*100.0);
    }

    ~SubUnit() {}
    bool isSameChar(SubUnit *ptr){
        if(this->Atv_stats->Char_Name== ptr->Atv_stats->Char_Name)return true;
        return false;
    
    }
    bool isSameUnit(SubUnit *ptr){
        if(this->Atv_stats->Unit_Name == ptr->Atv_stats->Unit_Name)return true;
        return false;

    
    }
    
    bool isSameCharName(string name){
        if(this->Atv_stats->Char_Name == name)return true;
        return false;
    }
    bool isSameUnitName(string name){
        if(this->Atv_stats->Unit_Name == name)return true;
        return false;
    }
    //get
    void setStack(string buffName, int value) {
        this->Stack[buffName] = value;
    }
    void setBuffNote(string buffName, double value) {
        this->Buff_note[buffName] = value;
    }
    void setBuffCountdown(string buffName, int value) {
        this->Buff_countdown[buffName] = value;
    }
    void setBuffCheck(string buffName, bool value) {
        this->Buff_check[buffName] = value;
    }
    void setBuffSubUnitTarget(string buffName, SubUnit* target) {
        this->buffSubUnitTarget[buffName] = target;
    }
    void setBuffAllyTarget(string buffName, Ally* target) {
        this->buffAllyTarget[buffName] = target;
    }

    //set
    int getStack(string buffName) {
        return this->Stack[buffName];
    }
    double getBuffNote(string buffName) {
        return this->Buff_note[buffName];
    }
    int getBuffCountdown(string buffName) {
        return this->Buff_countdown[buffName];
    }
    bool getBuffCheck(string buffName) {
        return this->Buff_check[buffName];
    }
    SubUnit* getBuffSubUnitTarget(string buffName) {
        return this->buffSubUnitTarget[buffName];
    }
    Ally* getBuffAllyTarget(string buffName) {
        return this->buffAllyTarget[buffName];
    }

    
    /*--------------------Declaration--------------------*/
    /*-----------------Combat-----------------*/
    //ChangeHP
    void Death();

    //TargetChoose.h
    void addTargetChangeCondition(function<bool()> condition);
    void addTargetChangeConditionImmediately(function<bool()> condition);
    void updateTargetingSubUnits(int newTargetNum);

    /*-----------------Print-----------------*/
    //PrintStats.h
    void printAtkStats();
    void printHpStats();
    void printCritStats();
    //Combat.h
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
    //total Damage
    double totalRealTimeDamage =  0;
    vector<double> totalAvgToughnessDamage ;
    double totalDamage = 0;
    
    unordered_map<string,double> damageAvgNote;
    unordered_map<string,double> damageRealTimeNote;

    vector<double> averageDamageInstance;
    double Average_Damage = 0;
    double Last_note = 0;

    //Max Damage
    double maxDamage = -1e9;
    unordered_map<string,double> maxDamageAvgNote;
    unordered_map<string,double> maxDamageRealTimeNote;
    double Max_Average_Damage = -1e9;
    
    //Temp
    unordered_map<string,double> Adjust;

    vector<pair<string,int>> Substats;//*
    vector<int> Max_damage_Substats;//*
    bool Reroll_check=1;
    bool Stop_reroll=1;
    int Total_substats = 20;
    int currentTotalSubstats;

    int SeparateRatio = 20;
    int spiltPoint = 1;
    int Current_sub_choose =0;
    unordered_map<int,double> Damage_data;
    unordered_map<string,pair<double,int>> StatsType_Compare;
    pair<double,double> StatsType_Compare_MAX_MIN;

    unordered_map<string,pair<double,int>> TotalSubstats_Compare;
    pair<double,double> TotalSubstats_Compare_MAX_MIN;


    vector<string> Path ;//*
    //*
    vector<unique_ptr<Unit>> Summon_ptr;  //
    vector<unique_ptr<SubUnit>> Sub_Unit_ptr;  // 
    vector<unique_ptr<Unit>> Countdown_ptr;  // 

    int Technique = 1;
    //Ult condition
    vector<function<bool()>> ultCondition;
    vector<function<bool()>> ultImmediatelyUseCondtion;
    
    
    bool Print =0;
    bool Wait_Other_Buff = 0;
    function<void(Ally *ptr)> Body;
    function<void(Ally *ptr)> Boot;
    function<void(Ally *ptr)> Orb;
    function<void(Ally *ptr)> Rope;

    double SpeedRequire = 0;
    double ApplyBaseChance = 0;
    double ExtraEhr = 0;
    double ExtraSpeed = 0;
    
    // Constructor now calls the base class constructor to initialize Atv_stats and set ptr_to_unit
    Ally() {  // Call Unit constructor to initialize Atv_stats and set ptr_to_unit
        Sub_Unit_ptr.resize(1);
        Sub_Unit_ptr[0] = make_unique<SubUnit>();
        Sub_Unit_ptr[0]->ptr_to_unit = this;
          // Using unique_ptr for stats
    }

    ~Ally() {}
    int getNum(){
        return this->Sub_Unit_ptr[0]->Atv_stats->Unit_num;
    }

    void setRelicMainStats(string Body,string Boot,string Orb,string Rope){
        this->Body = RelicMainStatsSet(Body);
        this->Boot = RelicMainStatsSet(Boot);
        this->Orb  = RelicMainStatsSet(Orb);
        this->Rope = RelicMainStatsSet(Rope);
    }
    function<void(Ally *ptr)> RelicPairSet(string stats);
    function<void(Ally *ptr)> RelicMainStatsSet(string stats);

    void setTotalSubstats(int Value){
        this->Total_substats=Value;
        this->currentTotalSubstats=Value;
        this->SeparateRatio=Value;
        this->Substats[0].second = Value;
        this->Max_damage_Substats.resize(this->Substats.size());
    }
    void pushSubstats(string StatsType){
        this->Substats.push_back({StatsType,0});
    }
    void decreaseTotalSubStats(int amount){
        amount = (this->Total_substats>=amount) ? amount : this->Total_substats;
        this->Total_substats-=amount;
        this->currentTotalSubstats-=amount;
        this->SeparateRatio-=amount;
        this->Substats[0].second -=amount;
    }
    bool isAllyHaveSummon(){
        if(this->Summon_ptr.size()!=0||this->Sub_Unit_ptr.size()>1)return true;
        return false;
    }
    SubUnit* getSubUnit(){
        return this->Sub_Unit_ptr[0].get();
    }
    SubUnit* getSubUnit(int num){
        return this->Sub_Unit_ptr[num].get();
    }
    //set
    void setStack(string buffName, int value) {
        this->Sub_Unit_ptr[0]->Stack[buffName] = value;
    }
    void setBuffNote(string buffName, double value) {
        this->Sub_Unit_ptr[0]->Buff_note[buffName] = value;
    }
    void setBuffCountdown(string buffName, int value) {
        this->Sub_Unit_ptr[0]->Buff_countdown[buffName] = value;
    }
    void setBuffCheck(string buffName, bool value) {
        this->Sub_Unit_ptr[0]->Buff_check[buffName] = value;
    }
    void setBuffSubUnitTarget(string buffName, SubUnit* target) {
        this->Sub_Unit_ptr[0]->buffSubUnitTarget[buffName] = target;
    }
    void setBuffAllyTarget(string buffName, Ally* target) {
        this->Sub_Unit_ptr[0]->buffAllyTarget[buffName] = target;
    }
    void setAdjust(string adjustName, double value) {
        this->Adjust[adjustName] = value;
    }
    void setSpeedRequire(double value){
        this->SpeedRequire = value;
    }
    void setApplyBaseChance(double value){
        this->ApplyBaseChance = value;
    }

    //get
    int getStack(string buffName) {
        return this->Sub_Unit_ptr[0]->Stack[buffName];
    }
    double getBuffNote(string buffName) {
        return this->Sub_Unit_ptr[0]->Buff_note[buffName];
    }
    int getBuffCountdown(string buffName) {
        return this->Sub_Unit_ptr[0]->Buff_countdown[buffName];
    }
    bool getBuffCheck(string buffName) {
        return this->Sub_Unit_ptr[0]->Buff_check[buffName];
    }
    SubUnit* getBuffSubUnitTarget(string buffName) {
        return this->Sub_Unit_ptr[0]->buffSubUnitTarget[buffName];
    }
    Ally* getBuffAllyTarget(string buffName) {
        return this->Sub_Unit_ptr[0]->buffAllyTarget[buffName];
    }
    double getAdjust(string adjustName) {
        return this->Adjust[adjustName];
    }


    /*--------------------Declaration--------------------*/
    void SetAllyBaseStats(double BaseHp,double BaseAtk,double BaseDef);
    /*-----------------Combat-----------------*/
    //Energy.h
    void addUltCondition(function<bool()> condition);
    void addUltImmediatelyUseCondition(function<bool()> condition);

    //TargetChoose.h
    void updateTargetingSubUnits(int newTargetNum);

    //Requirement Stats
    void SpeedRequirment();
    void newSpeedRequire(double amount);
    void EhrRequirment();
    void newEhrRequire(double amount);
    void ATKRequirment();
    void HPRequirment();
    void DEFRequirment();

};

// Enemy class, derived from Unit
class Enemy : public Unit {
public:
    
    //*
   
    int Total_debuff = 0;
    unordered_map<string,int> Debuff;
    unordered_map<string,double> DebuffNote;
    unordered_map<string,int> Stack;
    unordered_map<string,int> Debuff_time_count;

    vector<unordered_map<string,double>> damageAvgNote;
    vector<unordered_map<string,double>> damageRealTimeNote;

    //Max Damage
    vector<unordered_map<string,double>> maxDamageAvgNote;
    vector<unordered_map<string,double>> maxDamageRealTimeNote;

    double ATK = 718;
    double atkPercent = 0;
    double dmgPercent = 0;
    double Max_toughness; 
    double Current_toughness;
    bool Toughness_status = 1;
    double toughnessAvgMultiplier = 0;
    string Target_type = "";//*
    unordered_map<string,double> AttackCoolDown;
    int AoeCharge = 0;

    SubUnit *target = nullptr;

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
 
    //Constructor now calls the base class constructor to initialize Atv_stats and set ptr_to_unit
    Enemy() : Unit() {  // Call Unit constructor to initialize Atv_stats and set ptr_to_unit
    
    }

    ~Enemy() {}
    
    // Getters and Setters
    void setTotalDebuff(int value) {
        this->Total_debuff = value;
    }
    void setDebuff(string debuffName, int value) {
        this->Debuff[debuffName] = value;
    }
    void setDebuffNote(string debuffName, int value) {
        this->DebuffNote[debuffName] = value;
    }
    void setStack(string debuffName, int value) {
        this->Stack[debuffName] = value;
    }
    void setDebuffTimeCount(string debuffName, int value) {
        this->Debuff_time_count[debuffName] = value;
    }

    //getter
    int getTotalDebuff() {
        return this->Total_debuff;
    }
    int getDebuff(string debuffName) {
        return this->Debuff[debuffName];
    }
    int getDebuffNote(string debuffName) {
        return this->DebuffNote[debuffName];
    }
    int getStack(string debuffName) {
        return this->Stack[debuffName];
    }
    int getDebuffTimeCount(string debuffName) {
        return this->Debuff_time_count[debuffName];
    }
    
    //add
    void addTotalDebuff(int value) {
        this->Total_debuff += value;
    }
    void addStack(string debuffName,int value) {
        this->Stack[debuffName] += value;
    }


    //create
    void BaAttack(double SkillRatio,double energy);
    void AoeAttack(double SkillRatio,double energy);

    //debuff.h
    bool debuffApply(SubUnit *ptr, string debuffName);
    bool debuffMark(SubUnit *ptr, string debuffName);
    void debuffStack(SubUnit *ptr,string debuffName,int Stack_increase);
    bool debuffStack(SubUnit *ptr,string debuffName,int Stack_increase,int StackLimit);
    void debuffRemove(string debuffName);
    void debuffRemoveStack(string debuffName);

    void debuffSingleTarget(string stats_type, string Attack_type, double Value);
    void debuffSingleTarget(string stats_type, string Attack_type, string Element, double Value);

    void debuffStackSingleTarget(SubUnit *ptr,string stats_type, string Attack_type, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);
    void debuffStackSingleTarget(SubUnit *ptr,string stats_type, string Attack_type, string Element, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);



};  
//check if it is ally unit

#endif