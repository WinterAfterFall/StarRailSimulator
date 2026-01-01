#ifndef ALLY_UNIT_H
#define ALLY_UNIT_H
#include <bits/stdc++.h>
#include "Unit.h"
using namespace std;
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12

class AllyUnit : public Unit {
public:
#pragma region Attribute

#pragma region Stats
    double baseAtk;
    double baseHp;
    double baseDef;
    double baseTaunt = 0;
    vector<ElementType> Element_type ;
    // * 
    double totalATK;    
    double totalHP;     
    double totalDEF;    
    double currentHP;   
    double currentSheild;
    int hitCount = 0;
    double taunt = 0;
    double tauntMtpr = 1;
    CharUnit* owner = nullptr;


    // * 
#pragma endregion

#pragma region Record Buff Value
    unordered_map<string,int> Stack;
    unordered_map<string,double> Buff_note;
    unordered_map<string,int> Buff_countdown;
    unordered_map<string,bool> Buff_check;
    unordered_map<string,AllyUnit*> buffSubUnitTarget;
    unordered_map<string,CharUnit*> buffAllyTarget;
#pragma endregion

    int defaultCharNum = Main_dps_num;
    int defaultMemoNum = 0;
    int currentCharNum = Main_dps_num;
    int currentMemoNum = 0;
    int Enemy_target_num = Main_Enemy_num;


#pragma endregion
#pragma region Constructor

    AllyUnit() : Unit() {

    }
    ~AllyUnit() {}

#pragma endregion 

    void tauntMtprChange(int value){
        tauntMtpr += value;
        totalTaunt -= taunt;
        taunt = baseTaunt * tauntMtpr/100.0;
        totalTaunt += taunt;
    }
    double calHitChance(){
        return (taunt/totalTaunt*100.0);
    }
    double calHitChance(vector<AllyUnit*> target){
        double total = 0;
        for(auto &each : target){
            total += each->taunt;
        }
        return (taunt/total*100.0);
    }

    

    bool isSameUnitName(AllyUnit *ptr){
        if(this->Atv_stats->UnitName== ptr->Atv_stats->UnitName)return true;
        return false;
    
    }
    bool isSameStatsOwnerName(AllyUnit *ptr){
        if(this->Atv_stats->StatsOwnerName == ptr->Atv_stats->StatsOwnerName)return true;
        return false;
    }
    bool isSameUnitName(string name){
        if(this->Atv_stats->UnitName == name)return true;
        return false;
    }
    bool isSameStatsOwnerName(string name){
        if(this->Atv_stats->StatsOwnerName == name)return true;
        return false;
    }
    bool isSameNum(AllyUnit *ptr){
        if(this->Atv_stats->num == ptr->Atv_stats->num)return true;
        return false;
    }
    bool isSameNum(int num){
        if(this->Atv_stats->num == num)return true;
        return false;
    }

    #pragma region Getters
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

        void setDefaultAllyTargetNum(int value) {
            this->defaultCharNum = value;
        }
        void setDefaultSubUnitTargetNum(int value) {
            this->defaultMemoNum = value;
        }
        void setCurrentAllyTargetNum(int value) {
            this->currentCharNum = value;
        }
        void setCurrentSubUnitTargetNum(int value) {
            this->currentMemoNum = value;
        }
        void setDefaultTargetNum(int ally,int AllyUnit) {
            this->defaultCharNum = ally;
            this->defaultMemoNum = AllyUnit;
        }
        void setCurrentTargetNum(int ally,int AllyUnit) {
            this->currentCharNum = ally;
            this->currentMemoNum = AllyUnit;
        }
    #pragma endregion

    #pragma region Setters
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
    #pragma endregion

    //add
    void addStack(string buffName,int value) {
        this->Stack[buffName] += value;
    }

    
    #pragma region Declaration
    
    void summon(double percent){
        this->status = UnitStatus::Alive;
        this->currentHP = percent/100*this->totalHP;
        this->resetATV();
    }
    



    
    /*-----------------Combat-----------------*/
    //ChangeHP
    void death();



    
    //TargetChoose.h

    //Healing
    void RestoreHP(HealSrc main,HealSrc adjacent,HealSrc other);
    void RestoreHP(AllyUnit *target,HealSrc Healptr);
    void RestoreHP(HealSrc healSrc);
    void RestoreHP(AllyUnit *target,HealSrc main,HealSrc other);
    /*-----------------Print-----------------*/
    //PrintStats.h
    void printAtkStats();
    void printHpStats();
    void printCritStats();
    //Combat.h
    #pragma endregion

};
#endif