#ifndef ACTION_VALUE_STATS_H
#define ACTION_VALUE_STATS_H
#include <bits/stdc++.h>
#include "../include.h"




// Action value stats for a unit (atv)
class ActionValueStats {
public:
    double baseSpeed = -1;
    double flatSpeed = 0;
    double speedPercent = 0;
    double atv = 1e6 ;
    double maxAtv = 1e6;
    int turnCnt = 0;
    int num = 0;
    Side side;//AllyUnit Ally Summon
    UnitType type;
    int priority = 0;
    // string UnitName;
    string name;//ชื่อเจ้าของเทิร์น
    bool extraTurn = false;
    Unit* charptr = nullptr; //* // This will be set to point back to the unit (Ally or Enemy)
        ActionValueStats(){
        }
        ActionValueStats(const string& unitName){
            name = unitName;
        }
        ActionValueStats(const string& unitName,double speed){
            name = unitName;
            baseSpeed = speed;
        }

#pragma region Get Method
    double getBaseSpeed(){
        return baseSpeed;
    }
    double getFlatSpeed(){
        return flatSpeed;
    }
    double getSpeedPercent(){
        return speedPercent;
    }
    double getATV(){
        return atv;
    }
    double getMaxATV(){
        return maxAtv;
    }
    int getTurnCnt(){
        return turnCnt;
    }
    int getUnitNum(){
        return num;
    }
    Side getSide(){
        return side;
    }
    UnitType getType(){
        return type;
    }
    int getPriority(){
        return priority;
    }
    string getUnitName(){
        return name;
    }
    Unit* getPtrToChar(){
        return charptr;
    }
#pragma endregion

#pragma region Set Method
    void setBaseSpeed(double baseSpeed){
        this->baseSpeed = baseSpeed;
    }
    void setFlatSpeed(double flatSpeed) {
        this->flatSpeed = flatSpeed;
    }
    void setSpeedPercent(double speedPercent) {
        this->speedPercent = speedPercent;
    }
    void setATV(double atv) {
        this->atv = atv;
    }
    void setMaxATV(double maxAtv) {
        this->maxAtv = maxAtv;
    }
    void setTurnCnt(int turnCnt) {
        this->turnCnt = turnCnt;
    }
    void setUnitNum(int unitNum) {
        this->num = unitNum;
    }
    void setSide(Side side) {
        this->side = side;
    }
    void setType(UnitType type) {
        this->type = type;
    }
    void setPriority(int priority) {
        this->priority = priority;
    }
    void setName(string unitName) {
        this->name = unitName;
    }
#pragma endregion

#pragma region Check Method
    bool isSameName(const string& name) {
        return this->name == name;
    }
    bool isSameNum(int num) {
        return this->num == num;
    }
    bool isSameUnit(Unit* ptr);
    bool isSameNum(Unit* ptr);
#pragma endregion
    AllyUnit* canCastToAllyUnit();
    Enemy* canCastToEnemy();
#pragma region SpeedCombat Function
    void speedBuff(double spdPercent ,double flatSpd);
    void resetATV();
    void resetATV(double baseSpeed);
#pragma endregion

    // Turn/field state: forwarded to charptr for real units, overridden by TimerATV
    virtual bool isAlive();
    virtual bool isAtvChangeAble();
    virtual void runTurn();
    virtual ~ActionValueStats(){}
};

class BuffClass{
    public:
    Stats statsType;
    AType actionType;
    double value;
};
class BuffElementClass{
    public:
    Stats statsType;
    ElementType element;
    AType actionType;
    double value;
};

// ATV-only turn owner (summon / countdown) : no stats, no buffs — only a timer with its own turn
class TimerATV : public ActionValueStats {
public:
    function<void()> turnFunc;
    UnitStatus status = UnitStatus::ALIVE;

    using ActionValueStats::speedBuff;
    void speedBuff(BuffClass buffSet){
        if(buffSet.statsType==Stats::FLAT_SPD)this->speedBuff(0,buffSet.value);
        else this->speedBuff(buffSet.value,0);
    }
    bool isAlive() override { return status == UnitStatus::ALIVE; }
    bool isDeath(){ return status == UnitStatus::DEATH; }
    bool isAtvChangeAble() override {
        return !(status == UnitStatus::DEATH||status == UnitStatus::ATV_FREEZE||status == UnitStatus::RETIRE);
    }
    void runTurn() override { turnFunc(); }
    void summon(){
        this->status = UnitStatus::ALIVE;
        this->resetATV();
    }
    void death(){
        this->status = UnitStatus::DEATH;
    }
};

#endif