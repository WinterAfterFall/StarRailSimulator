#include "../include.h"

void Increase_energy(Ally *ptr,double Energy ){
    allEventWhenEnergyIncrease(ptr,Energy*ptr->Energy_recharge/100);
    if(ptr->Current_energy+Energy*ptr->Energy_recharge/100 > ptr->Max_energy){
        ptr->Current_energy = ptr->Max_energy;
    }else{
        ptr->Current_energy +=  Energy*ptr->Energy_recharge/100;
    }
    
    return ;
}
void Increase_energy(SubUnit *ptr,double Energy ){
    allEventWhenEnergyIncrease(ptr->ptrToChar,Energy*ptr->ptrToChar->Energy_recharge/100);
    if(ptr->ptrToChar->Current_energy+Energy*ptr->ptrToChar->Energy_recharge/100 > ptr->ptrToChar->Max_energy){
        ptr->ptrToChar->Current_energy = ptr->ptrToChar->Max_energy;
    }else{
        ptr->ptrToChar->Current_energy +=  Energy*ptr->ptrToChar->Energy_recharge/100;
    }
    
    return ;
}
void Increase_energy(Ally *ptr,double Energy_percent,double Flat_energy){
    allEventWhenEnergyIncrease(ptr,Energy_percent/100*ptr->Max_energy+Flat_energy);
    if(ptr->Current_energy+Flat_energy+Energy_percent/100*ptr->Max_energy > ptr->Max_energy){
        ptr->Current_energy = ptr->Max_energy;
    }else{
        ptr->Current_energy += Flat_energy+Energy_percent/100*ptr->Max_energy;
    }
    
    return;
}
void Increase_energy(SubUnit *ptr,double Energy_percent,double Flat_energy){
    allEventWhenEnergyIncrease(ptr->ptrToChar,Energy_percent/100*ptr->ptrToChar->Max_energy+Flat_energy);
    if(ptr->ptrToChar->Current_energy+Flat_energy+Energy_percent/100*ptr->ptrToChar->Max_energy > ptr->ptrToChar->Max_energy){
        ptr->ptrToChar->Current_energy = ptr->ptrToChar->Max_energy;
    }else{
        ptr->ptrToChar->Current_energy += Flat_energy+Energy_percent/100*ptr->ptrToChar->Max_energy;
    }
    
    return;
}
bool ultUseCheck(Ally *ptr){
    if(!ptr->getSubUnit()->isExsited())return false;
    if(ptr->Ult_cost>ptr->Current_energy)return false;
    for(function<bool()> &e : ptr->ultCondition){
        if(!e()) return false;
    }
    ptr->Current_energy = ptr->Current_energy - ptr->Ult_cost;
    Increase_energy(ptr,5);
    return true;
}
void allUltimateCheck(){
    for(TriggerByYourSelf_Func &e : Ultimate_List){
        e.Call();
    }
}
void Ally::addUltCondition(function<bool()> condition) {
    ultCondition.push_back(condition);
}
