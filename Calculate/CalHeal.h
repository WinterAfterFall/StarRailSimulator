#ifndef Cal_Heal_H
#define Cal_Heal_H
#include "../Print.h"

double calculateHeal(Heal_data* Healptr ,HealRatio healRatio,Sub_Unit *target){
    
    double TotalHeal = 0;
    TotalHeal+=Cal_Atk_multiplier(Healptr)*healRatio.ATK/100; 
    TotalHeal+=Cal_Hp_multiplier(Healptr)*healRatio.HP/100; 
    TotalHeal+=Cal_Def_multiplier(Healptr)*healRatio.DEF/100; 
    TotalHeal+=calculateHealFromLostHP(target,Healptr->healFromLostHP);
    TotalHeal+=calculateHealFromTotalHP(target,Healptr->healFromTotalHP);
    TotalHeal+=Healptr->fixHeal;
    TotalHeal*=Cal_HealBonus_multiplier(Healptr,target);
    return TotalHeal;
}
double calculateHealFromLostHP(Sub_Unit *target,double percent){
    double TotalHeal;
    TotalHeal = (percent/100.0)*(target->totalHP-target->currentHP);
    return TotalHeal;
}
double calculateHealFromTotalHP(Sub_Unit *target,double percent){
    double TotalHeal = 0;
    TotalHeal = (percent/100.0)*(target->totalHP);
    return TotalHeal;
}
#endif