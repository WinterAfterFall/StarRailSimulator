#include "../include.h"

void increaseEnergy(CharUnit *ptr,double energy ){
    allEventWhenEnergyIncrease(ptr,energy*ptr->energyRecharge/100);
    ptr->currentEnergy = max(0.0, min(ptr->maxEnergy,
        ptr->currentEnergy + energy*ptr->energyRecharge/100));
    
    return ;
}
void increaseEnergy(AllyUnit *ptr,double energy ){
    allEventWhenEnergyIncrease(ptr->owner,energy*ptr->owner->energyRecharge/100);
    ptr->owner->currentEnergy = max(0.0, min(ptr->owner->maxEnergy,
        ptr->owner->currentEnergy + energy*ptr->owner->energyRecharge/100));
    
    return ;
}
void increaseEnergy(CharUnit *ptr,double energyPercent,double flatEnergy){
    allEventWhenEnergyIncrease(ptr,energyPercent/100*ptr->maxEnergy+flatEnergy);
    ptr->currentEnergy = max(0.0, min(ptr->maxEnergy,
        ptr->currentEnergy + flatEnergy + energyPercent/100*ptr->maxEnergy));
    
    return;
}
void increaseEnergy(AllyUnit *ptr,double energyPercent,double flatEnergy){
    allEventWhenEnergyIncrease(ptr->owner,energyPercent/100*ptr->owner->maxEnergy+flatEnergy);
    ptr->owner->currentEnergy = max(0.0, min(ptr->owner->maxEnergy,
        ptr->owner->currentEnergy + flatEnergy + energyPercent/100*ptr->owner->maxEnergy));
    
    return;
}
bool ultUseCheck(CharUnit *ptr){
    if(!ptr->isExisted())return false;
    if(ptr->ultCost>ptr->currentEnergy)return false;
    for(function<bool()> &e : ptr->ultCondition){
        if(!e()) return false;
    }
    ptr->currentEnergy = ptr->currentEnergy - ptr->ultCost;
    increaseEnergy(ptr,5);
    for(TriggerByAllyFunc &e : whenUseUltList){
        e.call(ptr);
    }
    return true;
}
void allUltimateCheck(){
    for(TriggerByYourSelfFunc &e : ultimateList){
        if(!ultUseCheck(e.owner)) continue;
        e.call(e.owner);
        if(phaseStatus != PhaseStatus::WHILE_ACTION) dealDamage();
    }
}
void CharUnit::addUltCondition(function<bool()> condition) {
    ultCondition.push_back(condition);
}
