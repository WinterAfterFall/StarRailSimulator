#include "../include.h"

void StatsAdjust(SubUnit *ptr,string statsType){
    if(statsType == "Atk%"||statsType == "Flat_Atk")AtkAdjust(ptr);
    if(statsType == "Hp%"||statsType == "Flat_Hp")HpAdjust(ptr);
    if(statsType == "Def%"||statsType == "Flat_Def")DefAdjust(ptr);
    if(!AdjustCheck)allEventAdjustStats(ptr,statsType);
}
void AtkAdjust(SubUnit *ptr){
    ptr->totalATK = calculateAtkOnStats(ptr);
}
void HpAdjust(SubUnit *ptr){
    double temp = calculateHpOnStats(ptr);
    if(temp<ptr->currentHP){
        ptr->currentHP = (ptr->currentHP > temp) ? temp : ptr->currentHP;
    }else{
        ptr->currentHP += (temp-ptr->totalHP);
    }
    ptr->totalHP = temp;
    
}
void DefAdjust(SubUnit *ptr){
    ptr->totalDEF= calculateDefOnStats(ptr);
}