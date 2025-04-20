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
    //BuffStats.h
    void extendBuffTime(string Buff_name,int Turn_extend);
    void buffAlly(string stats_type, string Attack_type, double Value);
    void buffAlly(string stats_type, string Attack_type, string Element, double Value);
    void buffAlly(string stats_type, string Attack_type, double Value,string Buff_name);
    void buffAlly(string stats_type, string Attack_type, string Element, double Value,string Buff_name);
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

#endif