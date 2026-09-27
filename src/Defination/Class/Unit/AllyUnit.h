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
    ElementType elementType;
    // * 
    double totalATK;    
    double totalHP;     
    double totalDEF;    
    double currentHP;   
    double currentSheild;
    int hitCount = 0;
    double taunt = 0;
    double tauntIncrease = 0;  // % · taunt = baseTaunt * (1 + tauntIncrease/100) · 0 = ไม่มี increase
    CharUnit* owner = nullptr;


    // * 
#pragma endregion

#pragma region Record Buff Value
    unordered_map<string,int> stack;
    unordered_map<string,double> buffNote;
    unordered_map<string,int> buffEnd;
    unordered_map<string,bool> buffCheck;
    unordered_map<string,AllyUnit*> buffSubUnitTarget;
    unordered_map<string,CharUnit*> buffAllyTarget;
#pragma endregion

    int defaultCharNum = mainDpsNum;
    int defaultMemoNum = 0;
    int currentCharNum = mainDpsNum;
    int currentMemoNum = 0;
    int enemyTargetNum = mainEnemyNum;


#pragma endregion
#pragma region Constructor

    AllyUnit() : Unit() {

    }
    ~AllyUnit() {}

#pragma endregion 

    void tauntIncreaseChange(double value){   // trace "taunt +X%" -> value = X · เรียกที่ไหนก็ได้ (recompute taunt สด)
        tauntIncrease += value;
        taunt = baseTaunt * (1 + tauntIncrease/100.0);
    }
    double calHitChance(vector<AllyUnit*> target){
        double total = 0;
        for(auto &each : target){
            total += each->taunt;
        }
        return (taunt/total*100.0);
    }

    

    bool isSameName(AllyUnit *ptr){
        if(this->atvStats->name == ptr->atvStats->name)return true;
        return false;
    }
    bool isSameName(string name){
        if(this->atvStats->name == name)return true;
        return false;
    }
    bool isSameNum(AllyUnit *ptr){
        if(this->atvStats->num == ptr->atvStats->num)return true;
        return false;
    }
    bool isSameNum(int num){
        if(this->atvStats->num == num)return true;
        return false;
    }

    #pragma region Getters
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
    #pragma endregion

    //add
    void addStack(string buffName,int value) {
        this->stack[buffName] += value;
        if (this->stack[buffName] < 0) this->stack[buffName] = 0;
    }

    
    #pragma region Declaration
    
    void summon(double percent){
        this->status = UnitStatus::ALIVE;
        this->currentHP = percent/100*this->totalHP;
        this->resetATV();
    }
    



    
    /*-----------------Combat-----------------*/
    //ChangeHP
    void death();



    
    //TargetChoose.h

    //Healing
    void restoreHP(HealSrc main,HealSrc adjacent,HealSrc other);
    void restoreHP(AllyUnit *target,HealSrc healPtr);
    void restoreHP(HealSrc healSrc);
    void restoreHP(AllyUnit *target,HealSrc main,HealSrc other);
    /*-----------------Print-----------------*/
    //PrintStats.h
    void printAtkStats();
    void printHpStats();
    void printCritStats();
    //Combat.h
    #pragma endregion

};
#endif
