#ifndef ALLY_H
#define ALLY_H
#include <bits/stdc++.h>
#include "SubUnit.h"
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
class DamageSrc {
    public:
        Enemy* src;
        Enemy* recv;
    
        // เปรียบเทียบตาม recv->getNum()
        bool operator<(const DamageSrc& other) const;
    };
class DamageRecord{
    public:
    double total;
    unordered_map<string,double> type;
};
class DamageAvgRecord{
    public:
    double lastNote = 0;
    vector<double> avgDmgInstance;
    double currentDmgRecord = 0;
    double maxDmgRecord = -1e9;
};

class Ally{
public:
    #pragma region attribute
    #pragma region status
    double Max_energy;
    double Current_energy = 0; /**/
    double Ult_cost;
    double Energy_recharge = 100; /**/
    int Eidolon;
    #pragma endregion
    #pragma region Build
    Func_class Char;
    Func_class Light_cone;
    Func_class Relic;
    Func_class Planar;
    #pragma endregion
    
    #pragma region DmgRecord
    //record total damage
    double maxTotalDmg = -1e9;
    double currentTotalDmg = 0;

    //record damage type
    map<DamageSrc,DamageRecord> currentRealTimeDmg;
    map<DamageSrc,DamageRecord> currentNonRealTimeDmg;
    map<DamageSrc,DamageRecord> maxRealTimeDmg;
    map<DamageSrc,DamageRecord> maxNonRealTimeDmg;

    //record Average damage
    vector<DamageAvgRecord> AvgDmgRecord; //ตามจำนวน Enemy

    #pragma endregion
    
    #pragma region CalCheck

    bool checkDamage = 0;
    bool checkDamageFormula = 0;
    bool checkHeal = 0;
    bool checkHealFormula = 0;
    bool checkHealReceive = 0;
    bool checkHealReceiveFormula = 0;
    bool checkHpChange = 0;
    bool checkHpChangeFormula = 0;

    #pragma endregion
    //Temp
    unordered_map<string,double> Adjust;

    vector<pair<Stats,int>> Substats;//*
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


    vector<Path> path ;//*
    //*
    vector<unique_ptr<Unit>> Summon_ptr;  //
    vector<unique_ptr<SubUnit>> Sub_Unit_ptr;  // 
    vector<unique_ptr<Unit>> Countdown_ptr;  // 

    int Technique = 1;
    //Ult condition
    vector<function<bool()>> ultCondition;
    
    
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
    
    #pragma endregion
    #pragma region constructor
    Ally() {  // Call Unit constructor to initialize Atv_stats and set ptrToChar
        Sub_Unit_ptr.resize(1);
        Sub_Unit_ptr[0] = make_unique<SubUnit>();
        Sub_Unit_ptr[0]->ptrToChar = this;
          // Using unique_ptr for stats
    }

    ~Ally() {}
    #pragma endregion
    
    bool isAllyHaveSummon(){
        if(this->Summon_ptr.size()!=0||this->Sub_Unit_ptr.size()>1)return true;
        return false;
    }
    
    #pragma region set_methods

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
    void setTargetAlly(int num){
        this->getSubUnit()->setDefaultAllyTargetNum(num);
    }
    void setTargetSubUnit(int num){
        this->getSubUnit()->setDefaultSubUnitTargetNum(num);
    }
    void setTargetBuff(int ally,int subUnit){
        this->getSubUnit()->setDefaultTargetNum(ally,subUnit);
    }

    #pragma endregion

    #pragma region get_methods
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
    int getNum(){
        return this->Sub_Unit_ptr[0]->Atv_stats->num;
    }
    SubUnit* getSubUnit(){
        return this->Sub_Unit_ptr[0].get();
    }
    SubUnit* getSubUnit(int num){
        return this->Sub_Unit_ptr[num].get();
    }
    
    #pragma endregion

    #pragma region checkMethod

    bool isSameAlly(SubUnit *ptr){
        if(ptr->ptrToChar->getSubUnit()->isSameUnit(this->getSubUnit()))return true;
        return false;
    }
    bool isSameAlly(Ally *ptr){
        if(ptr->getSubUnit()->isSameUnit(this->getSubUnit()))return true;
        return false;
    }
    #pragma endregion

    

    /*--------------------Declaration--------------------*/
    void SetAllyBaseStats(double BaseHp,double BaseAtk,double BaseDef);
    /*-----------------Combat-----------------*/
    //BuffStats.h
    void extendBuffTime(string Buff_name,int Turn_extend);
    void buffAlly(vector<BuffClass> buffSet);
    void buffAlly(vector<BuffElementClass> buffSet);
    void buffAlly(vector<BuffClass> buffSet,string Buff_name,int extend);
    void buffAlly(vector<BuffElementClass> buffSet,string Buff_name,int extend);

    //StackBuff.h
    void buffResetStack(vector<BuffClass> buffSet,string Stack_Name);
    void buffResetStack(vector<BuffElementClass> buffSet,string Stack_Name);
    
    void buffStackAlly(vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name);
    void buffStackAlly(vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name,int extend);
    void buffStackAlly(vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name);
    void buffStackAlly(vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Nam,int extend);

    //Energy.h
    void addUltCondition(function<bool()> condition);

    //TargetChoose.h
    void updateTargetingSubUnits(int newTargetNum);

    //Requirement Stats
    // Main Stats
    void setRelicMainStats(Stats Body, Stats Boot, Stats Orb, Stats Rope);
    void setBody(Stats stats);
    void setBoot(Stats stats);
    void setOrb(Stats stats);
    void setRope(Stats stats);
    function<void(Ally *ptr)> RelicPairSet(PairSetType stats);
    function<void(Ally *ptr)> RelicMainStatsSet(Stats stats);

    // Set Requirements
    void setSpeed(double speed);
    void newSpeedRequire(double amount);
    void newEhrRequire(double amount);

    // Set Substats
    #pragma region SetSubdstats
    void setTotalSubstats(int Value);
    void pushSubstats(Stats StatsType);
    void changeTotalSubStats(int amount);
    void SpeedRequirment();
    void EhrRequirment();
    #pragma endregion

    #pragma region FormulaCheck

    void enableCheckDamage();
    void enableCheckDamageFormula();
    void enableCheckHeal();
    void enableCheckHealFormula();
    void enableCheckHealReceive();
    void enableCheckHealReceiveFormula();
    void enableCheckHpChange();
    void enableCheckHpChangeFormula();
    #pragma endregion
};

#endif