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
    double Unit_Speed_Ratio = 0;
    double Unit_Hp_Ratio = 0 ;
    double Base_atk;//*
    double Base_hp;//*
    double Base_def;//*

    double totalATK;
    double totalHP;
    double totalDEF;

    double currentHP;
    double currentSheild;
    
    unordered_map<string,int> Stack;
    unordered_map<string,double> Buff_note;
    unordered_map<string,int> Buff_countdown;
    unordered_map<string,bool> Buff_check;
    unordered_map<string,SubUnit*> buffSubUnitTarget;
    unordered_map<string,Ally*> buffAllyTarget;

    vector<function<bool()>> changeTargetCondition;
    vector<function<bool()>> changeTargetImmediatelyCondtion;

    
    vector<string> Element_type ;//*
    
    double tauntBase = 0;
    double taunt = 0;
    double tauntMtpr = 1;
    //string Target_Buff = "Ally";
    int defaultAllyTargetNum = Main_dps_num;
    int defaultSubUnitTargetNum = 0;
    int currentAllyTargetNum = Main_dps_num;
    int currentSubUnitTargetNum = 0;
    int Enemy_target_num = Main_Enemy_num;
    Ally* ptr_to_unit = nullptr;
    //temp 
    // Constructor now calls the base class constructor to initialize Atv_stats and set ptr_to_unit
    SubUnit() : Unit() {
          // Call Unit constructor to initialize Atv_stats and set ptr_to_unit  // Using unique_ptr for stats
    }

    void tauntMtprChange(int value){
        tauntMtpr += value;
        totalTaunt -= taunt;
        taunt = tauntBase * tauntMtpr/100.0;
        totalTaunt += taunt;
    }
    double calHitChance(){
        return (taunt/totalTaunt*100.0);
    }

    ~SubUnit() {}
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
    //get
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

    //set
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

    
    /*--------------------Declaration--------------------*/
    /*-----------------Buff-----------------*/
    bool isHaveToAddBuff(string Buff_name);
    bool isBuffEnd(string Buff_name);
    /*-----------------Combat-----------------*/
    //ChangeHP
    void Death();

    //BuffStats.h
    void extendBuffTime(SubUnit *ptr,string Buff_name,int Turn_extend);
    //TargetChoose.h
    void addTargetChangeCondition(function<bool()> condition);
    void addTargetChangeConditionImmediately(function<bool()> condition);
    void updateTargetingSubUnits(int newTargetNum);

    /*-----------------Print-----------------*/
    //PrintStats.h
    void printAtkStats();
    void printHpStats();
    void printCritStats();
    //Combat.h
};
#endif