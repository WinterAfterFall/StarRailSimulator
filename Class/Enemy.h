#ifndef ENEMY_H
#define ENEMY_H
#include <bits/stdc++.h>
#include "Ally.h"
using namespace std;
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12
class Enemy : public Unit {
public:
    
    //*
   
    int Total_debuff = 0;
    unordered_map<string,int> Debuff;
    unordered_map<string,double> DebuffNote;
    unordered_map<string,int> Stack;
    unordered_map<string,int> Debuff_time_count;

    vector<unordered_map<string,double>> damageAvgNote;
    vector<unordered_map<string,double>> damageRealTimeNote;

    //Max Damage
    vector<unordered_map<string,double>> maxDamageAvgNote;
    vector<unordered_map<string,double>> maxDamageRealTimeNote;

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

    SubUnit *target = nullptr;

    int Bleed = 0,Bleeder = 0;
    int Burn = 0,Burner = 0;
    int Shock = 0,Shocker = 0;
    int Wind_shear = 0,Wind_shearer = 0;
    int  Wind_shear_stack = 0;
    int Freeze = 0;
    int Entanglement= 0,Entanglement_stack = 0;
    int Imprisonment = 0;
    unordered_map<string,bool> Default_Weakness_type;
    unordered_map<string,bool> Weakness_type;
    unordered_map<string,double> DefaultElementRes;
    
    double Total_toughness_broken_time =0;
    double when_toughness_broken;
 
    //Constructor now calls the base class constructor to initialize Atv_stats and set ptr_to_unit
    Enemy() : Unit() {  // Call Unit constructor to initialize Atv_stats and set ptr_to_unit
    
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

    //debuff.h
    bool debuffApply(SubUnit *ptr, string debuffName);
    bool debuffMark(SubUnit *ptr, string debuffName);
    void debuffStack(SubUnit *ptr,string debuffName,int Stack_increase);
    pair<int,int> debuffStack(SubUnit *ptr,string debuffName,int Stack_increase,int StackLimit);
    void debuffRemove(string debuffName);
    void debuffRemoveStack(string debuffName);

    bool isDebuffEnd(string Debuff_name);
    void extendDebuffTime(string Debuff_name,int Turn_extend);

    void debuffSingleTarget(string stats_type, string Attack_type, double Value);
    void debuffSingleTarget(string stats_type, string Attack_type, string Element, double Value);

    void debuffStackSingleTarget(SubUnit *ptr,string stats_type, string Attack_type, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);
    void debuffStackSingleTarget(SubUnit *ptr,string stats_type, string Attack_type, string Element, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name);



};  
//check if it is ally unit

#endif