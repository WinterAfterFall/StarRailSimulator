#ifndef ENERGY_H
#define ENERGY_H
#include<bits/stdc++.h>
#include "../Class/Trigger_Function.h"
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12
#define K_const 10000


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
    allEventWhenEnergyIncrease(ptr->ptr_to_unit,Energy*ptr->ptr_to_unit->Energy_recharge/100);
    if(ptr->ptr_to_unit->Current_energy+Energy*ptr->ptr_to_unit->Energy_recharge/100 > ptr->ptr_to_unit->Max_energy){
        ptr->ptr_to_unit->Current_energy = ptr->ptr_to_unit->Max_energy;
    }else{
        ptr->ptr_to_unit->Current_energy +=  Energy*ptr->ptr_to_unit->Energy_recharge/100;
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
    allEventWhenEnergyIncrease(ptr->ptr_to_unit,Energy_percent/100*ptr->ptr_to_unit->Max_energy+Flat_energy);
    if(ptr->ptr_to_unit->Current_energy+Flat_energy+Energy_percent/100*ptr->ptr_to_unit->Max_energy > ptr->ptr_to_unit->Max_energy){
        ptr->ptr_to_unit->Current_energy = ptr->ptr_to_unit->Max_energy;
    }else{
        ptr->ptr_to_unit->Current_energy += Flat_energy+Energy_percent/100*ptr->ptr_to_unit->Max_energy;
    }
    
    return;
}
bool ultUseCheck(Ally *ptr){
    if(ptr->Ult_cost>ptr->Current_energy)return false;
    for(function<bool()> &e : ptr->ultImmediatelyUseCondtion){
        if(e()) goto jumpto;
    }
    for(function<bool()> &e : ptr->ultCondition){
        if(!e()) return false;
    }
    jumpto:
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

void Ally::addUltImmediatelyUseCondition(function<bool()> condition) {
    ultImmediatelyUseCondtion.push_back(condition);
}
#endif