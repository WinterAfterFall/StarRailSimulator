#include "../include.h"

void statsAdjust(AllyUnit *ptr,Stats statsType){
    if(statsType == Stats::ATK_P||statsType == Stats::FLAT_ATK)atkAdjust(ptr);
    if(statsType == Stats::HP_P||statsType == Stats::FLAT_HP)hpAdjust(ptr);
    if(statsType == Stats::DEF_P||statsType == Stats::FLAT_DEF)defAdjust(ptr);
    if(!adjustCheck)allEventAdjustStats(ptr,statsType);
}
void atkAdjust(AllyUnit *ptr){
    ptr->totalATK = calculateAtkOnStats(ptr);
}
void hpAdjust(AllyUnit *ptr){
    double newMaxHP = calculateHpOnStats(ptr);
    double delta = newMaxHP - ptr->totalHP;
    if(delta > 0) ptr->currentHP += delta;                    // maxHP เพิ่ม x -> currentHP เพิ่ม x
    if(ptr->currentHP > newMaxHP) ptr->currentHP = newMaxHP;  // maxHP ลดจนต่ำกว่า currentHP -> clamp ลงมาเท่า maxHP
    ptr->totalHP = newMaxHP;                                  // maxHP ลดแต่ยังสูงกว่า currentHP -> currentHP คงเดิม
}
void defAdjust(AllyUnit *ptr){
    ptr->totalDEF= calculateDefOnStats(ptr);
}