#include "../include.h"

void Increase_energy(CharUnit *ptr,double Energy ){
    allEventWhenEnergyIncrease(ptr,Energy*ptr->Energy_recharge/100);
    if(ptr->Current_energy+Energy*ptr->Energy_recharge/100 > ptr->Max_energy){
        ptr->Current_energy = ptr->Max_energy;
    }else{
        ptr->Current_energy +=  Energy*ptr->Energy_recharge/100;
    }
    
    return ;
}
void Increase_energy(AllyUnit *ptr,double Energy ){
    allEventWhenEnergyIncrease(ptr->owner,Energy*ptr->owner->Energy_recharge/100);
    if(ptr->owner->Current_energy+Energy*ptr->owner->Energy_recharge/100 > ptr->owner->Max_energy){
        ptr->owner->Current_energy = ptr->owner->Max_energy;
    }else{
        ptr->owner->Current_energy +=  Energy*ptr->owner->Energy_recharge/100;
    }
    
    return ;
}
void Increase_energy(CharUnit *ptr,double Energy_percent,double Flat_energy){
    allEventWhenEnergyIncrease(ptr,Energy_percent/100*ptr->Max_energy+Flat_energy);
    if(ptr->Current_energy+Flat_energy+Energy_percent/100*ptr->Max_energy > ptr->Max_energy){
        ptr->Current_energy = ptr->Max_energy;
    }else{
        ptr->Current_energy += Flat_energy+Energy_percent/100*ptr->Max_energy;
    }
    
    return;
}
void Increase_energy(AllyUnit *ptr,double Energy_percent,double Flat_energy){
    allEventWhenEnergyIncrease(ptr->owner,Energy_percent/100*ptr->owner->Max_energy+Flat_energy);
    if(ptr->owner->Current_energy+Flat_energy+Energy_percent/100*ptr->owner->Max_energy > ptr->owner->Max_energy){
        ptr->owner->Current_energy = ptr->owner->Max_energy;
    }else{
        ptr->owner->Current_energy += Flat_energy+Energy_percent/100*ptr->owner->Max_energy;
    }
    
    return;
}
bool ultUseCheck(CharUnit *ptr){
    if(!ptr->isExsited())return false;
    if(ptr->Ult_cost>ptr->Current_energy)return false;
    for(function<bool()> &e : ptr->ultCondition){
        if(!e()) return false;
    }
    ptr->Current_energy = ptr->Current_energy - ptr->Ult_cost;
    Increase_energy(ptr,5);
    for(TriggerByAlly_Func &e : WhenUseUlt_List){
        e.Call(ptr);
    }
    return true;
}
void allUltimateCheck(){
    for(TriggerByYourSelf_Func &e : Ultimate_List){
        e.Call();
    }
}
void CharUnit::addUltCondition(function<bool()> condition) {
    ultCondition.push_back(condition);
}
