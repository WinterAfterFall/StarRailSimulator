#ifndef Cal_Heal_H
#define Cal_Heal_H
#include "../Print.h"

double calculateHeal(Heal_data* Healptr ,Heal_data::HealRatio healRatio,Sub_Unit *target){
    double TotalHeal = 0;
    TotalHeal+=Cal_Atk_multiplier(Healptr)*healRatio.ATK/100; 
    TotalHeal+=Cal_Hp_multiplier(Healptr)*healRatio.HP/100; 
    TotalHeal+=Cal_Def_multiplier(Healptr)*healRatio.DEF/100; 
    TotalHeal*=Cal_HealBonus_multiplier(Healptr,target);
    return TotalHeal;
}
#endif