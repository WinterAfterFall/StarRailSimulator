#ifndef SUBUNIT_H
#define SUBUNIT_H
#include <bits/stdc++.h>
#include "Unit.h"
using namespace std;
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12

class SubUnit : public Unit {
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

    // * 
#pragma endregion
    
#pragma region AdjustStats
    double Unit_Speed_Ratio = 0;
    double Unit_Hp_Ratio = 0 ;
    double fixHP = 0;
#pragma endregion

#pragma region Record Buff Value
    unordered_map<string,int> Stack;
    unordered_map<string,double> Buff_note;
    unordered_map<string,int> Buff_countdown;
    unordered_map<string,bool> Buff_check;
    unordered_map<string,SubUnit*> buffSubUnitTarget;
    unordered_map<string,Ally*> buffAllyTarget;
#pragma endregion









    //string Target_Buff = Side::Ally;
    int defaultAllyTargetNum = Main_dps_num;
    int defaultSubUnitTargetNum = 0;
    int currentAllyTargetNum = Main_dps_num;
    int currentSubUnitTargetNum = 0;
    int Enemy_target_num = Main_Enemy_num;
    Ally* ptrToChar = nullptr;


#pragma endregion
#pragma region Constructor

    SubUnit() : Unit() {

    }
    ~SubUnit() {}

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
    double calHitChance(vector<SubUnit*> target){
        double total = 0;
        for(auto &each : target){
            total += each->taunt;
        }
        return (taunt/total*100.0);
    }

    

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
    bool isSameNum(SubUnit *ptr){
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
        void setBuffSubUnitTarget(string buffName, SubUnit* target) {
            this->buffSubUnitTarget[buffName] = target;
        }
        void setBuffAllyTarget(string buffName, Ally* target) {
            this->buffAllyTarget[buffName] = target;
        }

        void setDefaultAllyTargetNum(int value) {
            this->defaultAllyTargetNum = value;
        }
        void setDefaultSubUnitTargetNum(int value) {
            this->defaultSubUnitTargetNum = value;
        }
        void setCurrentAllyTargetNum(int value) {
            this->currentAllyTargetNum = value;
        }
        void setCurrentSubUnitTargetNum(int value) {
            this->currentSubUnitTargetNum = value;
        }
        void setDefaultTargetNum(int ally,int subUnit) {
            this->defaultAllyTargetNum = ally;
            this->defaultSubUnitTargetNum = subUnit;
        }
        void setCurrentTargetNum(int ally,int subUnit) {
            this->currentAllyTargetNum = ally;
            this->currentSubUnitTargetNum = subUnit;
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
        SubUnit* getBuffSubUnitTarget(string buffName) {
            return this->buffSubUnitTarget[buffName];
        }
        Ally* getBuffAllyTarget(string buffName) {
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

    //BuffStats.h
    bool isHaveToAddBuff(string Buff_name);
    bool isHaveToAddBuff(string Buff_name,int extend);
    bool isBuffGoneByDeath(string Buff_name);
    bool isBuffEnd(string Buff_name);
    void extendBuffTime(string Buff_name,int Turn_extend);

    void buffSingle(vector<BuffClass> buffSet);
    void buffSingle(vector<BuffClass> buffSet,string buffName,int extend);
    void buffSingle(vector<BuffElementClass> buffSet);
    void buffSingle(vector<BuffElementClass> buffSet,string buffName,int extend);
    void buffAllAllyExcludingBuffer(vector<BuffClass> buffSet);
    void buffAllAllyExcludingBuffer(vector<BuffElementClass> buffSet);
    void buffAllAllyExcludingBuffer(vector<BuffClass> buffSet,string Buff_name,int Turn_extend);
    void buffAllAllyExcludingBuffer(vector<BuffElementClass> buffSet,string Buff_name,int Turn_extend);

    //Stack.h
    pair<int,int> calStack(int Stack_increase,int StackLimit,string buffName);
    void buffResetStack(vector<BuffClass> buffSet,string Stack_Name);
    void buffResetStack(vector<BuffElementClass> buffSet,string Stack_Name);

    void buffStackSingle(vector<BuffClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Nam);
    void buffStackSingle(vector<BuffClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Nam,int extend);
    void buffStackSingle(vector<BuffElementClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Nam);
    void buffStackSingle(vector<BuffElementClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Nam,int extend);

    void buffStackExcludingBuffer(vector<BuffClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name);
    void buffStackExcludingBuffer(vector<BuffClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name, int extend);
    void buffStackExcludingBuffer(vector<BuffElementClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name);
    void buffStackExcludingBuffer(vector<BuffElementClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name, int extend);

    
    //TargetChoose.h

    //Healing
    void RestoreHP(HealSrc main,HealSrc adjacent,HealSrc other);
    void RestoreHP(SubUnit *target,HealSrc Healptr);
    void RestoreHP(HealSrc healSrc);
    void RestoreHP(SubUnit *target,HealSrc main,HealSrc other);
    /*-----------------Print-----------------*/
    //PrintStats.h
    void printAtkStats();
    void printHpStats();
    void printCritStats();
    //Combat.h
    #pragma endregion

};
#endif