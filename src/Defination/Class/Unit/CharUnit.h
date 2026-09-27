#ifndef CHAR_UNIT_H
#define CHAR_UNIT_H
#include <bits/stdc++.h>
#include "Memosprite.h"

class FuncClass{
    public:
    string name;
    function<void(CharUnit *ptr)> printFunc;
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
    double maxEnergy;
    double currentEnergy = 0; /**/
    double ultCost;
    double energyRecharge = 100; /**/
    int eidolon;
    #pragma endregion
    #pragma region Build
    FuncClass charSetup;
    FuncClass lightCone;
    FuncClass Relic;
    FuncClass Planar;
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
    vector<DamageAvgRecord> avgDmgRecord; //ตามจำนวน Enemy

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
    bool checkDmgFormulaMM = 0;
    bool checkDmgFormulaPL = 0;
    bool checkDmgFormulaElation = 0;

    bool checkHeal = 0;
    bool checkHealFormula = 0;
    bool checkHealReceive = 0;
    bool checkHealReceiveFormula = 0;
    bool checkHpChange = 0;
    bool checkHpChangeFormula = 0;


    #pragma endregion
    //Temp
    unordered_map<string,double> adjust;

    #pragma region Substats Reroll
    vector<pair<Stats,int>> substats;//* จำนวน roll ที่ลงแต่ละ substat — setStats แปลงเป็นค่าจริง
    vector<int> bestSubstats;          // ชุด roll ที่ดาเมจสูงสุดที่วัดได้ — changeMaxDamage เป็นคนเขียน
    int totalSubstats = 25;

    // สถานะของ standardReroll (Substats_Reset.h)
    bool rerollActive = 1;             // 1 = ยังค้นหาอยู่ · 0 = จบแล้ว หรือถูกปิดด้วย CharCmd::setRerollCheck
    int rerollTargetIndex = 1;         // ช่องที่กำลังเติม roll · เริ่ม 1 เพราะช่อง 0 คือคลังที่ถือ roll ทั้งหมดตอนเริ่ม
    int rerollSourceIndex = -1;        // ช่องที่กำลังดึง roll ออก ไล่ 0..target-1 · -1 = ยังไม่เริ่ม sweep
    bool rerollImproved = 0;           // sweep นี้มีชุดทดลองที่ทำลายสถิติดาเมจไหม
    vector<int> rerollSweepBase;       // จุดตั้งต้นของ sweep — ทุกชุดทดลองแตกออกจากตรงนี้
    #pragma endregion

    Path path;//*
    //*
    vector<unique_ptr<TimerATV>> summonList;  //
    unique_ptr<Memosprite> memosprite;  // 
    vector<unique_ptr<TimerATV>> countdownList;  // 

    int technique = 1;
    //Ult condition
    vector<function<bool()>> ultCondition;
    
    
    bool print =1;
    function<void(CharUnit *ptr)> body;
    function<void(CharUnit *ptr)> boot;
    function<void(CharUnit *ptr)> orb;
    function<void(CharUnit *ptr)> rope;

    double speedRequire = 0;
    double extraSpeed = 0;
    double atkRequire = 0;
    double extraAtk = 0;
    double hpRequire = 0;
    double extraHp = 0;
    double defRequire = 0;
    double extraDef = 0;

    double applyBaseChance = 0;
    double ehrRequire = 0;
    double extraEhr = 0;
    
    #pragma endregion
    #pragma region constructor
    CharUnit() {  // Call Unit constructor to initialize atvStats and set owner
          // Using unique_ptr for stats
          owner = this;
    }

    ~CharUnit() {}
    #pragma endregion
    
    bool isAllyHaveSummon(){
        if(this->summonList.size()!=0||this->memosprite)return true;
        return false;
    }
    
    #pragma region set_methods

    void setStack(string buffName, int value) {
        this->stack[buffName] = value;
    }
    void setBuffNote(string buffName, double value) {
        this->buffNote[buffName] = value;
    }
    void setBuffCountdown(string buffName, int value) {
        this->buffEnd[buffName] = value;
    }
    void setBuffCheck(string buffName, bool value) {
        this->buffCheck[buffName] = value;
    }
    void setBuffSubUnitTarget(string buffName, AllyUnit* target) {
        this->buffSubUnitTarget[buffName] = target;
    }
    void setBuffAllyTarget(string buffName, CharUnit* target) {
        this->buffAllyTarget[buffName] = target;
    }
    void setAdjust(string adjustName, double value) {
        this->adjust[adjustName] = value;
    }
    void setSpeedRequire(double value){
        this->speedRequire = value;
    }
    void setAtkRequire(double value){
        this->atkRequire = value;
    }
    void setHpRequire(double value){
        this->hpRequire = value;
    }
    void setDefRequire(double value){
        this->defRequire = value;
    }
    void setApplyBaseChance(double value){
        this->applyBaseChance = value;
    }
    void setEhrRequire(double value){
        this->ehrRequire = value;
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
        return this->stack[buffName];
    }
    double getBuffNote(string buffName) {
        return this->buffNote[buffName];
    }
    int getBuffCountdown(string buffName) {
        return this->buffEnd[buffName];
    }
    bool getBuffCheck(string buffName) {
        return this->buffCheck[buffName];
    }
    AllyUnit* getBuffSubUnitTarget(string buffName) {
        return this->buffSubUnitTarget[buffName];
    }
    CharUnit* getBuffAllyTarget(string buffName) {
        return this->buffAllyTarget[buffName];
    }
    double getAdjust(string adjustName) {
        return this->adjust[adjustName];
    }
    int getNum(){
        return this->atvStats->num;
    }
    AllyUnit* getMemosprite(){
        return this->memosprite.get();
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
    void setAllyBaseStats(double baseHp,double baseAtk,double baseDef);
    /*-----------------Combat-----------------*/


    //Energy.h
    void addUltCondition(function<bool()> condition);

    //TargetChoose.h
    void updateTargetingSubUnits(int newTargetNum);

    //Requirement Stats
    // Main Stats
    void setRelicMainStats(Stats body, Stats boot, Stats orb, Stats rope);
    void setBody(Stats stats);
    void setBoot(Stats stats);
    void setOrb(Stats stats);
    void setRope(Stats stats);
    function<void(CharUnit *ptr)> relicPairSet(PairSetType stats);
    function<void(CharUnit *ptr)> relicMainStatsSet(Stats stats);

    // Set Requirements
    void setSpeed(double speed);
    void newSpeedRequire(double amount);
    void newApplyBaseChanceRequire(double amount);
    void newEhrRequire(double amount);

    // Set Substats
    #pragma region SetSubdstats
    void setTotalSubstats(int value);
    void pushSubstats(Stats statsType);
    int changeTotalSubStats(int amount);
    void atkRequirment();
    void hpRequirment();
    void defRequirment();
    void speedRequirment();
    void ehrRequirment();
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

    bool canCheckDmgformulaPL();
    bool canCheckDmgformulaMM();
    bool canCheckDmgformulaElation();



    #pragma endregion

};
#endif