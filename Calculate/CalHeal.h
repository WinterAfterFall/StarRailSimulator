#ifndef Cal_Heal_H
#define Cal_Heal_H
#include "../Print.h"

double calculateHeal(Heal_data& Healptr ,HealRatio healRatio,Sub_Unit *target){
    
    double TotalHeal = 0;
    TotalHeal+=Cal_Atk_multiplier(Healptr)*healRatio.ATK/100; 
    TotalHeal+=Cal_Hp_multiplier(Healptr)*healRatio.HP/100; 
    TotalHeal+=Cal_Def_multiplier(Healptr)*healRatio.DEF/100; 
    TotalHeal+=calculateHealFromLostHP(target,healRatio.healFromLostHP);
    TotalHeal+=calculateHealFromTotalHP(target,healRatio.healFromTotalHP);
    TotalHeal+=healRatio.fixHeal;
    TotalHeal*=Cal_HealBonus_multiplier(Healptr,target);
    return TotalHeal;
}
double calculateHeal(HealRatio healRatio,Sub_Unit *Healer,Sub_Unit *target){
    
    double TotalHeal = 0;
    TotalHeal+=Healer->totalATK*healRatio.ATK/100; 
    TotalHeal+=Healer->totalHP*healRatio.HP/100; 
    TotalHeal+=Healer->totalDEF*healRatio.DEF/100; 
    TotalHeal+=calculateHealFromLostHP(target,healRatio.healFromLostHP);
    TotalHeal+=calculateHealFromTotalHP(target,healRatio.healFromTotalHP);
    TotalHeal+=healRatio.fixHeal;
    TotalHeal*=Cal_HealBonus_multiplier(Healer,target);
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