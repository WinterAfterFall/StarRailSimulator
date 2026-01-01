#include "../include.h"

void StatsAdjust(AllyUnit *ptr,Stats statsType){
    if(statsType == Stats::ATK_P||statsType == Stats::FLAT_ATK)AtkAdjust(ptr);
    if(statsType == Stats::HP_P||statsType == Stats::FLAT_HP)HpAdjust(ptr);
    if(statsType == Stats::DEF_P||statsType == Stats::FLAT_DEF)DefAdjust(ptr);
    if(!AdjustCheck)allEventAdjustStats(ptr,statsType);
}
void AtkAdjust(AllyUnit *ptr){
    ptr->totalATK = calculateAtkOnStats(ptr);
}
void HpAdjust(AllyUnit *ptr){
    double temp = calculateHpOnStats(ptr);
    if(temp<ptr->currentHP){
        ptr->currentHP = (ptr->currentHP > temp) ? temp : ptr->currentHP;
    }else{
        ptr->currentHP += (temp-ptr->totalHP);
    }
    ptr->totalHP = temp;
    
}
void DefAdjust(AllyUnit *ptr){
    ptr->totalDEF= calculateDefOnStats(ptr);
}