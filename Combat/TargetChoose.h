#ifndef TARGET_CHOOSE_H
#define TARGET_CHOOSE_H
#include<bits/stdc++.h>
#include "../Unit/Trigger_Function.h"
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12
#define K_const 10000

//Ally
bool Action_value_stats::isSameUnit(SubUnit *ptr){
    if(this->Unit_Name == ptr->Atv_stats->Unit_Name)return true;
    return false;
}

SubUnit* Action_value_stats::canCastToSubUnit(){
    return dynamic_cast<SubUnit*>(this->ptr_to_unit);
}
Enemy* Action_value_stats::canCastToEnemy(){
    return dynamic_cast<Enemy*>(this->ptr_to_unit);
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