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
   
    int totalDebuff = 0;
    unordered_map<string,int> debuffCheck;
    unordered_map<string,double> debuffNote;
    unordered_map<string,int> stack;
    unordered_map<string,int> debuffEnd;

    double atk = 718;
    double maxToughness; 
    double currentToughness;
    bool toughnessStatus = 1;
    double toughnessAvgMultiplier = 0;
    EnemyType targetType;//*
    unordered_map<string,double> attackCoolDown;
    int aoeCharge = 0;
    vector<AllyUnit*> tauntList;
    double toughnessReduceNote = 0;
    int hitCount = 0;
    Enemy * nextToLeft = nullptr;
    Enemy * nextToRight = nullptr;

    
    std::vector<BreakSideEffect> breakDotList;
    std::vector<BreakSideEffect> breakImsList;
    std::vector<BreakSideEffect> breakEngList;
    std::vector<BreakSideEffect> breakFrzList;

    int shockCount = 0;
    int windSheerCount = 0;
    int bleedCount = 0;
    int burnCount = 0;
    int dotCount = 0;

    void changeShock(int amount){
        shockCount += amount;
        dotCount += amount;
    }
    void changeWindSheer(int amount){
        windSheerCount += amount;
        dotCount += amount;
    }
    void changeBleed(int amount){
        bleedCount += amount;
        dotCount += amount;
    }
    void changeBurn(int amount){
        burnCount += amount;
        dotCount += amount;
    }
    void changeDotType(DotType dotType,int amount){
        if(dotType == DotType::SHOCK) changeShock(amount);
        else if(dotType == DotType::WIND_SHEAR) changeWindSheer(amount);
        else if(dotType == DotType::BLEED) changeBleed(amount);
        else if(dotType == DotType::BURN) changeBurn(amount);
    }

    bool addBreakSEList(BreakSideEffect input) {
        if(input.type == BreakSEType::FREEZE) {
            for(auto itr = breakFrzList.begin(); itr != breakFrzList.end();) {
                if(itr->ptr->isSameName(input.ptr)) {
                    itr->countdown = input.countdown;
                    return false;
                } else {
                    ++itr;
                }
            }
            breakFrzList.push_back(input);
        } else if(input.type == BreakSEType::IMPRISONMENT) {
            for(auto itr = breakImsList.begin(); itr != breakImsList.end();) {
                if(itr->ptr->isSameName(input.ptr)) {
                    itr->countdown = input.countdown;
                    return false;
                } else {
                    ++itr;
                }
            }
            breakImsList.push_back(input);
        } else if(input.type == BreakSEType::ENTANGLEMENT) {
            for(auto itr = breakEngList.begin(); itr != breakEngList.end();) {
                if(itr->ptr->isSameName(input.ptr)) {
                    itr->countdown = input.countdown;
                    return false;
                } else {
                    ++itr;
                }
            }
            breakEngList.push_back(input);
        }else{
            for(auto itr = breakDotList.begin(); itr != breakDotList.end();) {
                if(itr->ptr->isSameName(input.ptr)) {
                    itr->countdown = input.countdown;
                    itr->stack += input.stack;
                    return false;
                } else {
                    ++itr;
                }
            }
            breakDotList.push_back(input);
            dotCount++;
            if(input.type == BreakSEType::BURN){
                burnCount++;
            } else if(input.type == BreakSEType::SHOCK){
                shockCount++;
            } else if(input.type == BreakSEType::WIND_SHEAR){
                windSheerCount++;
            } else if(input.type == BreakSEType::BLEED){
                bleedCount++;
            }
        }
        return true;
    }
    unordered_map<ElementType,bool> defaultWeaknessType;
    unordered_map<ElementType,bool> weaknessType;
    unordered_map<ElementType,double> defaultElementRes;
    unordered_map<ElementType,int> weaknessTypeCountdown;
    int defaultWeaknessElementAmount;
    int currentWeaknessElementAmount;
    
    double totalToughnessBrokenTime =0;
    double whenToughnessBroken;
 
    //Constructor now calls the base class constructor to initialize atvStats and set owner
    Enemy() : Unit() {  // Call Unit constructor to initialize atvStats and set owner
    
    }

    ~Enemy() {}
    
    // Getters and Setters
    void setTotalDebuff(int value) {
        this->totalDebuff = value;
    }
    void setDebuff(string debuffName, int value) {
        this->debuffCheck[debuffName] = value;
    }
    void setDebuffNote(string debuffName, int value) {
        this->debuffNote[debuffName] = value;
    }
    void setStack(string debuffName, int value) {
        this->stack[debuffName] = value;
    }
    void setDebuffTimeCount(string debuffName, int value) {
        this->debuffEnd[debuffName] = value;
    }

    //getter
    int getTotalDebuff() {
        return this->totalDebuff;
    }
    int getDebuff(string debuffName) {
        return this->debuffCheck[debuffName];
    }
    int getDebuffNote(string debuffName) {
        return this->debuffNote[debuffName];
    }
    int getStack(string debuffName) {
        return this->stack[debuffName];
    }
    int getDebuffTimeCount(string debuffName) {
        return this->debuffEnd[debuffName];
    }
    
    //add
    void addTotalDebuff(int value) {
        this->totalDebuff += value;
    }
    void addStack(string debuffName,int value) {
        this->stack[debuffName] += value;
        if (this->stack[debuffName] < 0) this->stack[debuffName] = 0;
    }


    //DeBuff
    
    //create
    void baAttack(double skillRatio,double energy);
    void aoeAttack(double skillRatio,double energy);
    void addTaunt(AllyUnit* ptr);
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
