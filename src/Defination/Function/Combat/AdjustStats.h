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
    double newMaxHP = calculateHpOnStats(ptr);
    double delta = newMaxHP - ptr->totalHP;
    if(delta > 0) ptr->currentHP += delta;                    // maxHP เพิ่ม x -> currentHP เพิ่ม x
    if(ptr->currentHP > newMaxHP) ptr->currentHP = newMaxHP;  // maxHP ลดจนต่ำกว่า currentHP -> clamp ลงมาเท่า maxHP
    ptr->totalHP = newMaxHP;                                  // maxHP ลดแต่ยังสูงกว่า currentHP -> currentHP คงเดิม
}
void DefAdjust(AllyUnit *ptr){
    ptr->totalDEF= calculateDefOnStats(ptr);
}