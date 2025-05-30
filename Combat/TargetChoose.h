#ifndef TARGET_CHOOSE_H
#define TARGET_CHOOSE_H
#include<bits/stdc++.h>
#include "../Class/ClassLibrary.h"
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12
#define K_const 10000

//Ally
bool ActionValueStats::isSameUnit(SubUnit *ptr){
    if(this->Unit_Name == ptr->Atv_stats->Unit_Name)return true;
    return false;
}

SubUnit* ActionValueStats::canCastToSubUnit(){
    return dynamic_cast<SubUnit*>(this->ptrToChar);
}
Enemy* ActionValueStats::canCastToEnemy(){
    return dynamic_cast<Enemy*>(this->ptrToChar);
}
SubUnit* Unit::canCastToSubUnit() {
    return dynamic_cast<SubUnit*>(this);
}
Enemy* Unit::canCastToEnemy(){
    return dynamic_cast<Enemy*>(this);
}

SubUnit* chooseSubUnitBuff(SubUnit *ptr){
    return Ally_unit[ptr->currentAllyTargetNum]->Sub_Unit_ptr[ptr->currentSubUnitTargetNum].get();
}
Ally* chooseCharacterBuff(SubUnit *ptr){
    return Ally_unit[ptr->currentAllyTargetNum].get();
}
Enemy* chooseEnemyTarget(SubUnit *ptr){
    return Enemy_unit[ptr->Enemy_target_num].get();
}

void Ally::updateTargetingSubUnits(int newTargetNum) {
    for (int i = 1; i <= Total_ally; ++i) {
        if(Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->Unit_num == this->Sub_Unit_ptr[0]->Atv_stats->Unit_num)continue;
        for (unique_ptr<SubUnit> &subUnit : Ally_unit[i]->Sub_Unit_ptr) {
            if (subUnit->currentAllyTargetNum == this->Sub_Unit_ptr[0]->Atv_stats->Unit_num) 
            subUnit->currentSubUnitTargetNum = newTargetNum;
        }
    }
}

//SubUnit
void SubUnit::addTargetChangeCondition(function<bool()> condition) {
    changeTargetCondition.push_back(condition);
}

void SubUnit::addTargetChangeConditionImmediately(function<bool()> condition) {
    changeTargetImmediatelyCondtion.push_back(condition);
}
void SubUnit::updateTargetingSubUnits(int newTargetNum) {
    for (int i = 1; i <= Total_ally; ++i) {
        if(Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->Unit_num == this->Atv_stats->Unit_num)continue;
        for (unique_ptr<SubUnit> &subUnit : Ally_unit[i]->Sub_Unit_ptr) {
            if (subUnit->currentAllyTargetNum == this->Atv_stats->Unit_num) 
            subUnit->currentSubUnitTargetNum = newTargetNum;
            
        }
    }
}



#endif