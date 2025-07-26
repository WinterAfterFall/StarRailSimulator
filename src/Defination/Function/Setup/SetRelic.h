#include "../include.h"

function<void(Ally *ptr)> Ally::RelicPairSet(string stats){
    if(stats == ST_SPD_P)
    return [=](Ally *ptr) {
        ptr->getSubUnit()->Atv_stats->speedPercent+=6;
    };
    if(stats == ST_ATK_P)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_ATK_P][AType::None] += 12;
    };
    if(stats == ST_HP_P)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_P][AType::None] += 12;
    };
    if(stats == ST_DEF_P)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_DEF_P][AType::None] += 15;
    };
    if(stats == ST_CR)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AType::None] += 8;
    };
    if(stats == ST_CD)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_CD][AType::None] += 16;
    };
    if(stats == ST_BE)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_BE][AType::None] += 16;
    };
    if(stats == ST_HEALING_OUT)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_HEALING_OUT][AType::None] += 10;
    };
    if(stats == "Fua")
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG][AType::Fua] += 20;
    };
    if(stats == ST_DMG)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG][ptr->Sub_Unit_ptr[0]->Element_type[0]][AType::None] += 10;
    };


    return [=](Ally *ptr) {
        
    };
}