#ifndef ENEMY_H
#define ENEMY_H
#include <bits/stdc++.h>
#include "CharUnit.h"

class BreakSideEffect{
        public:
        BreakSEType type;
        AllyUnit *ptr = nullptr;
        int countdown = 0;
        int stack = 0;
        
        
        BreakSideEffect(BreakSEType type, AllyUnit *ptr, int countdown,int stack) 
            : type(type), countdown(countdown), ptr(ptr), stack(stack) {}
        BreakSideEffect(BreakSEType type, AllyUnit *ptr, int countdown) 
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
    EnemyType Target_type;//*
    unordered_map<string,double> AttackCoolDown;
    int AoeCharge = 0;
    vector<AllyUnit*> tauntList;
    double toughnessReduceNote = 0;
    int hitCount = 0;
    Enemy * nextToLeft = nullptr;
    Enemy * nextToRight = nullptr;

    
    std::vector<BreakSideEffect> breakDotList;
    std::vector<BreakSideEffect> breakImsList;
    std::vector<BreakSideEffect> breakEngList;
    std::vector<BreakSideEffect> breakFrzList;

    int ShockCount = 0;
    int WindSheerCount = 0;
    int BleedCount = 0;
    int BurnCount = 0;
    int DotCount = 0;

    void changeShock(int amount){
        ShockCount += amount;
        DotCount += amount;
    }
    void changeWindSheer(int amount){
        WindSheerCount += amount;
        DotCount += amount;
    }
    void changeBleed(int amount){
        BleedCount += amount;
        DotCount += amount;
    }
    void changeBurn(int amount){
        BurnCount += amount;
        DotCount += amount;
    }
    void changeDotType(DotType dotType,int amount){
        if(dotType == DotType::Shock) changeShock(amount);
        else if(dotType == DotType::WindShear) changeWindSheer(amount);
        else if(dotType == DotType::Bleed) changeBleed(amount);
        else if(dotType == DotType::Burn) changeBurn(amount);
    }

    bool addBreakSEList(BreakSideEffect input) {
        if(input.type == BreakSEType::Freeze) {
            for(auto itr = breakFrzList.begin(); itr != breakFrzList.end();) {
                if(itr->ptr->isSameStatsOwnerName(input.ptr)) {
                    itr->countdown = input.countdown;
                    return false;
                } else {
                    ++itr;
                }
            }
            breakFrzList.push_back(input);
        } else if(input.type == BreakSEType::Imprisonment) {
            for(auto itr = breakImsList.begin(); itr != breakImsList.end();) {
                if(itr->ptr->isSameStatsOwnerName(input.ptr)) {
                    itr->countdown = input.countdown;
                    return false;
                } else {
                    ++itr;
                }
            }
            breakImsList.push_back(input);
        } else if(input.type == BreakSEType::Entanglement) {
            for(auto itr = breakEngList.begin(); itr != breakEngList.end();) {
                if(itr->ptr->isSameStatsOwnerName(input.ptr)) {
                    itr->countdown = input.countdown;
                    return false;
                } else {
                    ++itr;
                }
            }
            breakEngList.push_back(input);
        }else{
            for(auto itr = breakDotList.begin(); itr != breakDotList.end();) {
                if(itr->ptr->isSameStatsOwnerName(input.ptr)) {
                    itr->countdown = input.countdown;
                    itr->stack += input.stack;
                    return false;
                } else {
                    ++itr;
                }
            }
        }
        breakDotList.push_back(input);
        DotCount++;
        if(input.type == BreakSEType::Burn){
            BurnCount++;
        } else if(input.type == BreakSEType::Shock){
            ShockCount++;
        } else if(input.type == BreakSEType::WindShear){
            WindSheerCount++;
        } else if(input.type == BreakSEType::Bleed){
            BleedCount++;
        }
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
 
    //Constructor now calls the base class constructor to initialize Atv_stats and set owner
    Enemy() : Unit() {  // Call Unit constructor to initialize Atv_stats and set owner
    
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
    void addTaunt(AllyUnit* ptr);
    void removeTaunt(string name);
    void removeTaunt(AllyUnit* ptr);

    //weaknessapply
    // string debuffWeaknessapply(AllyUnit *ptr, string debuffName);
    // string debuffWeaknessapply(AllyUnit *ptr, string debuffName,int extend);
    // bool debuffWeaknessEND(string debuffName);







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