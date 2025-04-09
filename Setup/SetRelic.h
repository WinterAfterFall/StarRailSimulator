#ifndef SetRelic_H
#define SetRelic_H
#include "../Unit/Trigger_Function.h"

function<void(Ally *ptr)> Ally::RelicPairSet(string stats){
    if(stats == ST_SPD_PERCENT)
    return [=](Ally *ptr) {
        ptr->getSubUnit()->Atv_stats->Speed_percent+=6;
    };
    if(stats == ST_ATK_PERCENT)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_ATK_PERCENT]["None"] += 12;
    };
    if(stats == ST_HP_PERCENT)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_PERCENT]["None"] += 12;
    };
    if(stats == ST_DEF_PERCENT)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_DEF_PERCENT]["None"] += 15;
    };
    if(stats == ST_CRIT_RATE)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_CRIT_RATE]["None"] += 8;
    };
    if(stats == ST_CRIT_DAM)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_CRIT_DAM]["None"] += 16;
    };
    if(stats == ST_BREAK_EFFECT)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_BREAK_EFFECT]["None"] += 16;
    };
    if(stats == ST_HEALING_OUT)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_HEALING_OUT]["None"] += 10;
    };
    if(stats == AT_Fua)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG_PERCENT][AT_Fua] += 20;
    };
    if(stats == ST_DMG_PERCENT)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG_PERCENT][ptr->Sub_Unit_ptr[0]->Element_type[0]][AT_Fua] += 10;
    };


    return [=](Ally *ptr) {
        
    };
}
#endif