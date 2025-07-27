#include "../include.h"

function<void(Ally *ptr)> Ally::RelicPairSet(Stats stats){
    if(stats == Stats::SPD_P)
    return [=](Ally *ptr) {
        ptr->getSubUnit()->Atv_stats->speedPercent+=6;
    };
    if(stats == Stats::ATK_P)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 12;
    };
    if(stats == Stats::HP_P)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::HP_P][AType::None] += 12;
    };
    if(stats == Stats::DEF_P)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DEF_P][AType::None] += 15;
    };
    if(stats == Stats::CR)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::None] += 8;
    };
    if(stats == Stats::CD)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CD][AType::None] += 16;
    };
    if(stats == Stats::BE)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::BE][AType::None] += 16;
    };
    if(stats == Stats::HEALING_OUT)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::HEALING_OUT][AType::None] += 10;
    };
    // if(stats == "Fua")
    // return [=](Ally *ptr) {
    //     ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::Fua] += 20;
    // };
    if(stats == Stats::DMG)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_each_element[Stats::DMG][ptr->Sub_Unit_ptr[0]->Element_type[0]][AType::None] += 10;
    };


    return [=](Ally *ptr) {
        
    };
}