#ifndef SetRelic_H
#define SetRelic_H
#include "../Class/Trigger_Function.h"

function<void(Ally *ptr)> Ally::RelicPairSet(string stats){
    if(stats == ST_SPD_P)
    return [=](Ally *ptr) {
        ptr->getSubUnit()->Atv_stats->Speed_percent+=6;
    };
    if(stats == ST_ATK_P)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_ATK_P][AT_NONE] += 12;
    };
    if(stats == ST_HP_P)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_P][AT_NONE] += 12;
    };
    if(stats == ST_DEF_P)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_DEF_P][AT_NONE] += 15;
    };
    if(stats == ST_CR)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AT_NONE] += 8;
    };
    if(stats == ST_CD)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_CD][AT_NONE] += 16;
    };
    if(stats == ST_BE)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_BE][AT_NONE] += 16;
    };
    if(stats == ST_HEALING_OUT)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_HEALING_OUT][AT_NONE] += 10;
    };
    if(stats == AT_FUA)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG][AT_FUA] += 20;
    };
    if(stats == ST_DMG)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG][ptr->Sub_Unit_ptr[0]->Element_type[0]][AT_NONE] += 10;
    };


    return [=](Ally *ptr) {
        
    };
}
function<void(Ally *ptr)> Ally::RelicMainStatsSet(string stats){
    if(stats == ST_FLAT_SPD)
    return [=](Ally *ptr) {
        ptr->getSubUnit()->Atv_stats->Flat_Speed+=25;
    };
    if(stats == ST_ATK_P)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_ATK_P][AT_NONE] += 43.2;
    };
    if(stats == ST_HP_P)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_P][AT_NONE] += 43.2;
    };
    if(stats == ST_DEF_P)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_DEF_P][AT_NONE] += 54;
    };
    if(stats == ST_CR)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AT_NONE] += 32.4;
    };
    if(stats == ST_CD)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_CD][AT_NONE] += 64.8;
    };
    if(stats == ST_BE)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_BE][AT_NONE] += 64.8;
    };
    if(stats == ST_HEALING_OUT)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_HEALING_OUT][AT_NONE] += 34.57;
    };
    if(stats == ST_DMG)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG][ptr->Sub_Unit_ptr[0]->Element_type[0]][AT_NONE] += 38.88;
    };
    if(stats == ST_EHR)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_EHR][AT_NONE] += 43.2;
    };
    if(stats == ST_EnergyRecharge)
    return [=](Ally *ptr) {
        ptr->Energy_recharge+=19.4;
    };

    return [=](Ally *ptr) {
        
    };
}

#endif