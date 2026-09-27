#ifndef UNIT_H
#define UNIT_H
#include <bits/stdc++.h>
#include "ActionValueStats.h"




// Action value stats for a unit (atv)
class Unit {
public:
    unique_ptr<ActionValueStats> atvStats;  // Moved atvStats here to be shared by both Ally and Enemy
    function<void()> turnFunc ;
    CommonStatsEachElement statsEachElement;//Ice Quantum
    CommonStatsType statsType;// Atk% Flat_Atk Def% Dmg% Crit_rate Crit_dam Def_shred Respen Vul Break_effect Weakness_Break_Efficiency HealingBonus 
    // Constructor to initialize atvStats and set owner to 'this'

    UnitStatus status;
    Unit() {
        atvStats = make_unique<ActionValueStats>();  // Create atvStats in Unit
        atvStats->charptr = this;  // Set owner to this object (Unit, Ally, or Enemy)
    }
       
    void speedBuff(BuffClass buffSet){
        if(buffSet.statsType==Stats::FLAT_SPD)this->atvStats->speedBuff(0,buffSet.value);
        else this->atvStats->speedBuff(buffSet.value,0);
    }
    void resetATV(){
        this->atvStats->resetATV();
    }
    void resetATV(double baseSpeed){
        this->atvStats->resetATV(baseSpeed);
    }
    
#pragma region Get Method
    ActionValueStats* getAtvStats() {
        return atvStats.get();
    }

    CommonStatsEachElement& getStatsEachElement() {
        return statsEachElement;
    }

    CommonStatsType& getStatsType() {
        return statsType;
    }
    // Getters for atvStats
    double getBaseSpeed()  {
        return atvStats->baseSpeed;
    }
    double getFlatSpeed()  {
        return atvStats->flatSpeed;
    }
    double getSpeedPercent()  {
        return atvStats->speedPercent;
    }
    double getATV(){
        return atvStats->atv;
    }
    double getMaxATV(){
        return atvStats->maxAtv;
    }
    int getTurnCnt(){
        return atvStats->turnCnt;
    }
    int getNum(){
        return atvStats->num;
    }
    Side getSide(){
        return atvStats->side;
    }
    UnitType getType(){
        return atvStats->type;
    }
    int getPriority(){
        return atvStats->priority;
    }
    string getName(){
        return atvStats->name;
    }
    
#pragma endregion

#pragma region Set Method
    // Setters for atvStats
    void setBaseSpeed(double baseSpeed){
        atvStats->baseSpeed = baseSpeed;
    }
    void setFlatSpeed(double flatSpeed) {
        atvStats->flatSpeed = flatSpeed;
    }
    void setSpeedPercent(double speedPercent) {
        atvStats->speedPercent = speedPercent;
    }
    void setATV(double atv) {
        atvStats->atv = atv;
    }
    void setMaxATV(double maxAtv) {
        atvStats->maxAtv = maxAtv;
    }
    void setTurnCnt(int turnCnt) {
        atvStats->turnCnt = turnCnt;
    }
    void setUnitNum(int unitNum) {
        atvStats->num = unitNum;
    }
    void setSide(Side Side) {
        atvStats->side = Side;
    }
    void setType(UnitType type) {
        atvStats->type = type;
    }
    void setPriority(int priority) {
        atvStats->priority = priority;
    }
    void setName(string name) {
        atvStats->name = name;
    }
#pragma endregion
#pragma endregion

#pragma region Check Method
    bool isSameUnit(Unit *ptr){
        if(this->atvStats->name == ptr->atvStats->name)return true;
        return false;
    }
    bool isSameName(string name){
        if(this->atvStats->name == name)return true;
        return false;
    }
    bool isSameNum(Unit *ptr){
        if(this->atvStats->num == ptr->atvStats->num)return true;
        return false;
    }
    bool isSameNum(int num){
        if(this->atvStats->num == num)return true;
        return false;
    }
    bool isAlive(){
        if(this->status == UnitStatus::ALIVE)return true;
        return false;
    }
    bool isDeath(){
        if(this->status == UnitStatus::DEATH)return true;
        return false;
    }
    bool isAtvChangeAble(){
        if(this->status == UnitStatus::DEATH||this->status == UnitStatus::ATV_FREEZE||this->status == UnitStatus::RETIRE)return false;
        return true;
    }
    bool isExisted(){
        if(this->status == UnitStatus::DEATH||this->status == UnitStatus::RETIRE)return false;
        return true;
    }
    bool isTargetable(){
        if(this->status == UnitStatus::DEATH||this->status == UnitStatus::RETIRE||this->getType()==UnitType::OUT_OF_BOUNDS)return false;
        return true;
    }

#pragma endregion
    AllyUnit* canCastToSubUnit();
    Enemy* canCastToEnemy();
    
    void summon(){
        this->status = UnitStatus::ALIVE;
        this->resetATV();
    }
    void death(){
        this->status = UnitStatus::DEATH;
    }
    
    virtual ~Unit() {}  // Virtual destructor to ensure proper cleanup of derived classes
};
#pragma region ATV get/set
    bool ActionValueStats::isSameUnit(Unit* ptr) {
        return this->name == ptr->atvStats->name;
    }
    bool ActionValueStats::isSameNum(Unit* ptr) {
        return this->num == ptr->atvStats->num;
    }
#pragma endregion
#endif