#ifndef Unit_H
#define Unit_H
#include <bits/stdc++.h>
#include "ActionValueStats.h"




// Action value stats for a unit (atv)
class Unit {
public:
    unique_ptr<ActionValueStats> Atv_stats;  // Moved Atv_stats here to be shared by both Ally and Enemy
    function<void()> Turn_func ;
    Common_stats_each_element Stats_each_element;//Ice Quantum
    Common_stats_type Stats_type;// Atk% Flat_Atk Def% Dmg% Crit_rate Crit_dam Def_shred Respen Vul Break_effect Weakness_Break_Efficiency HealingBonus 
    // Constructor to initialize Atv_stats and set owner to 'this'

    UnitStatus status;
    Unit() {
        Atv_stats = make_unique<ActionValueStats>();  // Create Atv_stats in Unit
        Atv_stats->charptr = this;  // Set owner to this object (Unit, Ally, or Enemy)
    }
       
    void speedBuff(BuffClass buffSet){
        if(buffSet.statsType==Stats::FLAT_SPD)this->Atv_stats->speedBuff(0,buffSet.value);
        else this->Atv_stats->speedBuff(buffSet.value,0);
    }
    void resetATV(){
        this->Atv_stats->resetATV();
    }
    void resetATV(double baseSpeed){
        this->Atv_stats->resetATV(baseSpeed);
    }
    
#pragma region Get Method
    ActionValueStats* getAtvStats() {
        return Atv_stats.get();
    }

    Common_stats_each_element& getStatsEachElement() {
        return Stats_each_element;
    }

    Common_stats_type& getStatsType() {
        return Stats_type;
    }
    // Getters for Atv_stats
    double getBaseSpeed()  {
        return Atv_stats->baseSpeed;
    }
    double getFlatSpeed()  {
        return Atv_stats->flatSpeed;
    }
    double getSpeedPercent()  {
        return Atv_stats->speedPercent;
    }
    double getATV(){
        return Atv_stats->atv;
    }
    double getMaxATV(){
        return Atv_stats->Max_atv;
    }
    int getTurnCnt(){
        return Atv_stats->turnCnt;
    }
    int getNum(){
        return Atv_stats->num;
    }
    Side getSide(){
        return Atv_stats->side;
    }
    UnitType getType(){
        return Atv_stats->Type;
    }
    int getPriority(){
        return Atv_stats->priority;
    }
    string getCharName(){
        return Atv_stats->UnitName;
    }
    string getUnitName(){
        return Atv_stats->StatsOwnerName;
    }
    
#pragma endregion

#pragma region Set Method
    // Setters for Atv_stats
    void setBaseSpeed(double baseSpeed){
        Atv_stats->baseSpeed = baseSpeed;
    }
    void setFlatSpeed(double flatSpeed) {
        Atv_stats->flatSpeed = flatSpeed;
    }
    void setSpeedPercent(double speedPercent) {
        Atv_stats->speedPercent = speedPercent;
    }
    void setATV(double atv) {
        Atv_stats->atv = atv;
    }
    void setMaxATV(double Max_atv) {
        Atv_stats->Max_atv = Max_atv;
    }
    void setTurnCnt(int turn_cnt) {
        Atv_stats->turnCnt = turn_cnt;
    }
    void setUnitNum(int Unit_num) {
        Atv_stats->num = Unit_num;
    }
    void setSide(Side Side) {
        Atv_stats->side = Side;
    }
    void setType(UnitType Type) {
        Atv_stats->Type = Type;
    }
    void setPriority(int priority) {
        Atv_stats->priority = priority;
    }
    void setCharName(string Char_Name) {
        Atv_stats->UnitName = Char_Name;
    }
    void setUnitName(string Unit_Name) {
        Atv_stats->StatsOwnerName = Unit_Name;
    }
#pragma endregion
#pragma endregion

#pragma region Check Method
    bool isSameChar(Unit *ptr){
        if(this->Atv_stats->UnitName== ptr->Atv_stats->UnitName)return true;
        return false;
    }
    bool isSameUnit(Unit *ptr){
        if(this->Atv_stats->StatsOwnerName == ptr->Atv_stats->StatsOwnerName)return true;
        return false;
    }
    bool isSameCharName(string name){
        if(this->Atv_stats->UnitName == name)return true;
        return false;
    }
    bool isSameUnitName(string name){
        if(this->Atv_stats->StatsOwnerName == name)return true;
        return false;
    }
    bool isSameNum(Unit *ptr){
        if(this->Atv_stats->num == ptr->Atv_stats->num)return true;
        return false;
    }
    bool isSameNum(int num){
        if(this->Atv_stats->num == num)return true;
        return false;
    }
    bool isAlive(){
        if(this->status == UnitStatus::Alive)return true;
        return false;
    }
    bool isDeath(){
        if(this->status == UnitStatus::Death)return true;
        return false;
    }
    bool isAtvChangeAble(){
        if(this->status == UnitStatus::Death||this->status == UnitStatus::AtvFreeze||this->status == UnitStatus::Retire)return false;
        return true;
    }
    bool isExsited(){
        if(this->status == UnitStatus::Death||this->status == UnitStatus::Retire)return false;
        return true;
    }
    bool isTargetable(){
        if(this->status == UnitStatus::Death||this->status == UnitStatus::Retire||this->getType()==UnitType::OutofBounds)return false;
        return true;
    }

#pragma endregion
    AllyUnit* canCastToSubUnit();
    Enemy* canCastToEnemy();
    
    void summon(){
        this->status = UnitStatus::Alive;
        this->resetATV();
    }
    void death(){
        this->status = UnitStatus::Death;
    }
    
    virtual ~Unit() {}  // Virtual destructor to ensure proper cleanup of derived classes
};
#pragma region ATV get/set
    bool ActionValueStats::isSameChar(Unit* ptr) {
        return this->UnitName == ptr->Atv_stats->UnitName;
    }
    bool ActionValueStats::isSameUnit(Unit* ptr) {
        return this->StatsOwnerName == ptr->Atv_stats->StatsOwnerName;
    }
    bool ActionValueStats::isSameNum(Unit* ptr) {
        return this->num == ptr->Atv_stats->num;
    }
#pragma endregion
#endif