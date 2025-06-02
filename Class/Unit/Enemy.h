#ifndef ENEMY_H
#define ENEMY_H
#include <bits/stdc++.h>
#include "Ally.h"
using namespace std;
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12


class BreakSideEffect{
        public:
        BreakSEType type;
        SubUnit *ptr = nullptr;
        int countdown = 0;
        int stack = 0;
        
        
        BreakSideEffect(BreakSEType type, SubUnit *ptr, int countdown,int stack) 
            : type(type), countdown(countdown), ptr(ptr), stack(stack) {}
        BreakSideEffect(BreakSEType type, SubUnit *ptr, int countdown) 
            : type(type), countdown(countdown), ptr(ptr) {}

            bool operator<(const BreakSideEffect& other) const {
            if ((countdown >= 0) != (other.countdown >= 0)) {
                return countdown >= 0; // non-negative comes first
            }
            return countdown < other.countdown;
        }
};

class Enemy : public Unit {
public:
    
    #pragma region Damage Record
    double avgDmgRecord = 0;
    double totalDmgRecord = 0;
    unordered_map<string,double> dmgRecordEachType;
    #pragma endregion
   
    int Total_debuff = 0;
    unordered_map<string,int> Debuff;
    unordered_map<string,double> DebuffNote;
    unordered_map<string,int> Stack;
    unordered_map<string,int> Debuff_time_count;

    double ATK = 718;
    double atkPercent = 0;
    double dmgPercent = 0;
    double Max_toughness; 
    double Current_toughness;
    bool Toughness_status = 1;
    double toughnessAvgMultiplier = 0;
    string Target_type = "";//*
    unordered_map<string,double> AttackCoolDown;
    int AoeCharge = 0;
    vector<SubUnit*> tauntList;
    double toughnessReduceNote = 0;
    int hitCount = 0;

    
    std::vector<BreakSideEffect> breakDotList;
    std::vector<BreakSideEffect> breakImsList;
    std::vector<BreakSideEffect> breakEngist;
    std::vector<BreakSideEffect> breakFrzist;

    bool addBreakSEList(BreakSideEffect input) {
        if(input.type == BreakSEType::Freeze) {
            for(auto itr = breakFrzist.begin(); itr != breakFrzist.end();) {
                if(itr->ptr->isSameUnit(input.ptr)) {
                    itr->countdown = input.countdown;
                    return false;
                } else {
                    ++itr;
                }
            }
        } else if(input.type == BreakSEType::Imprisonment) {
            for(auto itr = breakImsList.begin(); itr != breakImsList.end();) {
                if(itr->ptr->isSameUnit(input.ptr)) {
                    itr->countdown = input.countdown;
                    return false;
                } else {
                    ++itr;
                }
            }
        } else if(input.type == BreakSEType::Entanglement) {
            for(auto itr = breakEngist.begin(); itr != breakEngist.end();) {
                if(itr->ptr->isSameUnit(input.ptr)) {
                    itr->countdown = input.countdown;
                    return false;
                } else {
                    ++itr;
                }
            }
        }else{
            for(auto itr = breakDotList.begin(); itr != breakDotList.end();) {
                if(itr->ptr->isSameUnit(input.ptr)) {
                    itr->countdown = input.countdown;
                    itr->stack += input.stack;
                    return false;
                } else {
                    ++itr;
                }
            }
        }
        breakDotList.push_back(input);
        return true;
    }
    unordered_map<ElementType,bool> Default_Weakness_type;
    unordered_map<ElementType,bool> Weakness_type;
    unordered_map<ElementType,double> DefaultElementRes;
    unordered_map<ElementType,int> Weakness_typeCountdown;
    int defaultWeaknessElementAmount;
    int currentWeaknessElementAmount;
    
    double Total_toughness_broken_time =0;
    double when_toughness_broken;
 
    //Constructor now calls the base class constructor to initialize Atv_stats and set ptrToChar
    Enemy() : Unit() {  // Call Unit constructor to initialize Atv_stats and set ptrToChar
    
    }

    ~Enemy() {}
    
    // Getters and Setters
    void setTotalDebuff(int value) {
        this->Total_debuff = value;
    }
    void setDebuff(string debuffName, int value) {
        this->Debuff[debuffName] = value;
    }
    void setDebuffNote(string debuffName, int value) {
        this->DebuffNote[debuffName] = value;
    }
    void setStack(string debuffName, int value) {
        this->Stack[debuffName] = value;
    }
    void setDebuffTimeCount(string debuffName, int value) {
        this->Debuff_time_count[debuffName] = value;
    }

    //getter
    int getTotalDebuff() {
        return this->Total_debuff;
    }
    int getDebuff(string debuffName) {
        return this->Debuff[debuffName];
    }
    int getDebuffNote(string debuffName) {
        return this->DebuffNote[debuffName];
    }
    int getStack(string debuffName) {
        return this->Stack[debuffName];
    }
    int getDebuffTimeCount(string debuffName) {
        return this->Debuff_time_count[debuffName];
    }
    
    //add
    void addTotalDebuff(int value) {
        this->Total_debuff += value;
    }
    void addStack(string debuffName,int value) {
        this->Stack[debuffName] += value;
    }


    //DeBuff
    
    //create
    void BaAttack(double SkillRatio,double energy);
    void AoeAttack(double SkillRatio,double energy);
    void addTaunt(SubUnit* ptr);
    void removeTaunt(string name);
    void removeTaunt(SubUnit* ptr);

    //weaknessapply
    // string debuffWeaknessapply(SubUnit *ptr, string debuffName);
    // string debuffWeaknessapply(SubUnit *ptr, string debuffName,int extend);
    // bool debuffWeaknessEND(string debuffName);

    //debuff.h
    bool debuffApply(SubUnit *ptr, string debuffName);
    bool debuffApply(SubUnit *ptr, string debuffName,int extend);
    bool debuffMark(SubUnit *ptr, string debuffName);
    bool debuffMark(SubUnit *ptr, string debuffName,int extend);
    void debuffRemove(string debuffName);

    ElementType weaknessApplyChoose(int extend);
    void weaknessApply(ElementType Debuff_name ,int extend);
    
    bool isDebuffEnd(string Debuff_name);
    void extendDebuff(string Debuff_name,int Turn_extend);
    
    //Single target
    void debuffSingle(vector<BuffClass> debuffSet);
    void debuffSingle(vector<BuffElementClass> debuffSet);
    void debuffSingleApply(vector<BuffClass> debuffSet,SubUnit *ptr,string debuffName);
    void debuffSingleApply(vector<BuffElementClass> debuffSet,SubUnit *ptr,string debuffName);
    void debuffSingleMark(vector<BuffClass> debuffSet,SubUnit *ptr,string debuffName);
    void debuffSingleMark(vector<BuffElementClass> ,SubUnit *ptr,string debuffName);
    void debuffSingleApply(vector<BuffClass> debuffSet,SubUnit *ptr,string debuffName ,int extend);
    void debuffSingleApply(vector<BuffElementClass> debuffSet,SubUnit *ptr,string debuffName ,int extend);
    void debuffSingleMark(vector<BuffClass> buffSet, SubUnit* ptr, string debuffName, int extend);
    void debuffSingleMark(vector<BuffElementClass> buffSet, SubUnit* ptr, string debuffName, int extend);

    //Stack
    int debuffRemoveStack(string debuffName);
    pair<int,int> calDebuffStack(SubUnit *ptr,string debuffName,int Stack_increase,int StackLimit);
    void debuffStackRemove(vector<BuffClass> buffSet,string debuffName);
    void debuffStackRemove(vector<BuffElementClass> buffSet,string debuffName);
    void debuffStackSingle(vector<BuffClass>,SubUnit *ptr, int Stack_increase, int Stack_limit, string Stack_Name);
    void debuffStackSingle(vector<BuffElementClass>,SubUnit *ptr, int Stack_increase, int Stack_limit, string Stack_Name);
    void debuffStackSingle(vector<BuffClass>,SubUnit *ptr, int Stack_increase, int Stack_limit, string Stack_Name,int extend);
    void debuffStackSingle(vector<BuffElementClass>,SubUnit *ptr, int Stack_increase, int Stack_limit, string Stack_Name,int extend);

}; 
// Define DamageSrc cmp
bool DamageSrc::operator<(const DamageSrc& other) const {
    if (recv && other.recv) {
        return recv->getNum() < other.recv->getNum();
    }
    // fallback: nullptr considered less
    return recv < other.recv;
}

#endif