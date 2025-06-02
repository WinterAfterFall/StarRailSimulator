#ifndef Cal_Heal_H
#define Cal_Heal_H
#include "../Class/ClassLibrary.h"

double calculateHeal(HealSrc healSrc, SubUnit *Healer, SubUnit *target) {
    double TotalHeal = 0;

    TotalHeal += calAtkMultiplier(Healer,target) * healSrc.ATK / 100; 
    TotalHeal += calHpMultiplier(Healer,target) * healSrc.HP / 100; 
    TotalHeal += calDefMultiplier(Healer,target) * healSrc.DEF / 100; 
    TotalHeal += calculateHealFromLostHP(target, healSrc.healFromLostHP);
    TotalHeal += calculateHealFromTotalHP(target, healSrc.healFromTotalHP);
    TotalHeal += healSrc.constHeal;
    TotalHeal *= calHealBonusMultiplier(Healer, target);

    return TotalHeal < 0 ? 0 : TotalHeal;
}

double calculateHealFromLostHP(SubUnit *target, double percent) {
    double TotalHeal;
    
    TotalHeal = (percent / 100.0) * (target->totalHP - target->currentHP);
    return (TotalHeal < 0) ? 0 : TotalHeal;
}

double calculateHealFromTotalHP(SubUnit *target, double percent) {
    double TotalHeal = 0;
    TotalHeal = (percent / 100.0) * (target->totalHP);
    return (TotalHeal < 0) ? 0 : TotalHeal;
}

#endif