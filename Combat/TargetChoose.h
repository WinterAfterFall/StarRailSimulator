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