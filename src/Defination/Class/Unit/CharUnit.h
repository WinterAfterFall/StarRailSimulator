#ifndef CHAR_UNIT_H
#define CHAR_UNIT_H
#include <bits/stdc++.h>
#include "Memosprite.h"

class Func_class{
    public:
    string Name;
    function<void(CharUnit *ptr)> Print_Func;
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

class CharUnit : public AllyUnit {
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
    bool checkDmgFormula = 0;
    bool checkDmgFormulaAll = 0;
    bool checkDmgFormulaHP = 0;
    bool checkDmgFormulaATK = 0;
    bool checkDmgFormulaDEF = 0;
    bool checkDmgFormulaConst = 0;
    bool checkDmgFormulaSrc = 0;
    bool checkDmgFormulaDmg = 0;
    bool checkDmgFormulaCrit = 0;
    bool checkDmgFormulaCritRate = 0;
    bool checkDmgFormulaCritDam = 0;
    bool checkDmgFormulaDefShred = 0;
    bool checkDmgFormulaRespen = 0;
    bool checkDmgFormulaVul = 0;
    bool checkDmgFormulaMtgt = 0;
    bool checkDmgFormulaMtprInc = 0;
    bool checkDmgFormulaBE = 0;
    bool checkDmgFormulaSpbInc = 0;
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
    vector<unique_ptr<Unit>> summonList;  //
    vector<unique_ptr<Memosprite>> memospriteList;  // 
    vector<unique_ptr<Unit>> countdownList;  // 

    int Technique = 1;
    //Ult condition
    vector<function<bool()>> ultCondition;
    
    
    bool Print =0;
    bool Wait_Other_Buff = 0;
    function<void(CharUnit *ptr)> Body;
    function<void(CharUnit *ptr)> Boot;
    function<void(CharUnit *ptr)> Orb;
    function<void(CharUnit *ptr)> Rope;

    double SpeedRequire = 0;
    double ApplyBaseChance = 0;
    double EhrRequire = 0;
    double ExtraEhr = 0;
    double ExtraSpeed = 0;
    
    #pragma endregion
    #pragma region constructor
    CharUnit() {  // Call Unit constructor to initialize Atv_stats and set owner
          // Using unique_ptr for stats
          owner = this;
    }

    ~CharUnit() {}
    #pragma endregion
    
    bool isAllyHaveSummon(){
        if(this->summonList.size()!=0||this->memospriteList.size()!=0)return true;
        return false;
    }
    
    #pragma region set_methods

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
    void setBuffSubUnitTarget(string buffName, AllyUnit* target) {
        this->buffSubUnitTarget[buffName] = target;
    }
    void setBuffAllyTarget(string buffName, CharUnit* target) {
        this->buffAllyTarget[buffName] = target;
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
    void setEhrRequire(double value){
        this->EhrRequire = value;
    }
    void setTargetAlly(int num){
        this->setDefaultAllyTargetNum(num);
    }
    void setTargetSubUnit(int num){
        this->setDefaultSubUnitTargetNum(num);
    }
    void setTargetBuff(int ally,int AllyUnit){
        this->setDefaultTargetNum(ally,AllyUnit);
    }

    #pragma endregion

    #pragma region get_methods
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
    AllyUnit* getBuffSubUnitTarget(string buffName) {
        return this->buffSubUnitTarget[buffName];
    }
    CharUnit* getBuffAllyTarget(string buffName) {
        return this->buffAllyTarget[buffName];
    }
    double getAdjust(string adjustName) {
        return this->Adjust[adjustName];
    }
    int getNum(){
        return this->Atv_stats->num;
    }
    AllyUnit* getMemosprite(){
        return this->memospriteList[0].get();
    }
    AllyUnit* getMemosprite(int num){
        return this->memospriteList[num].get();
    }
    
    #pragma endregion

    #pragma region checkMethod

    bool isSameOwner(AllyUnit *ptr){

        Memosprite* memo = dynamic_cast<Memosprite*>(ptr);
        if(memo){
            if(memo->owner->isSameName(this))return true;
            return false;
        }

        if(ptr->isSameName(this))return true;
        return false;
    }
    #pragma endregion

    

    /*--------------------Declaration--------------------*/
    void SetAllyBaseStats(double BaseHp,double BaseAtk,double BaseDef);
    /*-----------------Combat-----------------*/


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
    function<void(CharUnit *ptr)> RelicPairSet(PairSetType stats);
    function<void(CharUnit *ptr)> RelicMainStatsSet(Stats stats);

    // Set Requirements
    void setSpeed(double speed);
    void newSpeedRequire(double amount);
    void newApplyBaseChanceRequire(double amount);
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
    void enableCheckDamageFormula(DmgFormulaMode mode);
    void enableCheckHeal();
    void enableCheckHealFormula();
    void enableCheckHealReceive();
    void enableCheckHealReceiveFormula();
    void enableCheckHpChange();
    void enableCheckHpChangeFormula();

    bool canCheckDmgformula();
    bool canCheckDmgformulaMtpr();
    bool canCheckDmgformulaHP();
    bool canCheckDmgformulaATK();
    bool canCheckDmgformulaDEF();
    bool canCheckDmgformulaConst();
    
    bool canCheckDmgformulaCritRate();
    bool canCheckDmgformulaCritDam();

    bool canCheckDmgformulaDmg();
    bool canCheckDmgformulaDefShred();
    bool canCheckDmgformulaRespen();
    bool canCheckDmgformulaVul();
    bool canCheckDmgformulaMtgt();
    bool canCheckDmgformulaMtprInc();
    
    bool canCheckDmgformulaBE();
    bool canCheckDmgformulaSpbInc();


    #pragma endregion

};
#endif