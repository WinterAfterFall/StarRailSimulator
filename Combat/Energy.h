#ifndef ENERGY_H
#define ENERGY_H
#include<bits/stdc++.h>
#include "../Print.h"
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
void Increase_energy(Ally *ptr,double Energy_percent,double Flat_energy){
    allEventWhenEnergyIncrease(ptr,Energy_percent/100*ptr->Max_energy+Flat_energy);
    if(ptr->Current_energy+Flat_energy+Energy_percent/100*ptr->Max_energy > ptr->Max_energy){
        ptr->Current_energy = ptr->Max_energy;
    }else{
        ptr->Current_energy += Flat_energy+Energy_percent/100*ptr->Max_energy;
    }
    
    return;
}
bool ultUseCheck(Ally *ptr){
    if(ptr->Ult_cost<=ptr->Current_energy){
        ptr->Current_energy = ptr->Current_energy - ptr->Ult_cost;
        Increase_energy(ptr,5);
        return true;
    }
    return false;
}
void allUltimateCheck(){
    for(TriggerByYourSelf_Func &e : Ultimate_List){
        e.Call(e.ptr);
    }
}
#endif