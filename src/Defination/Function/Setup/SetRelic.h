#include "../include.h"

function<void(Ally *ptr)> Ally::RelicPairSet(PairSetType Type){
    if(Type == PairSetType::Speed)
    return [=](Ally *ptr) {
        ptr->getSubUnit()->Atv_stats->speedPercent+=6;
    };
    if(Type == PairSetType::ATK)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 12;
    };
    if(Type == PairSetType::HP)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::HP_P][AType::None] += 12;
    };
    if(Type == PairSetType::DEF)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DEF_P][AType::None] += 15;
    };
    if(Type == PairSetType::CritRate)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::None] += 8;
    };
    if(Type == PairSetType::CritDam)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CD][AType::None] += 16;
    };
    if(Type == PairSetType::BE)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::BE][AType::None] += 16;
    };
    if(Type == PairSetType::HealOut)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::HEALING_OUT][AType::None] += 10;
    };
    if(Type == PairSetType::Fua)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::Fua] += 20;
    };
    if(Type == PairSetType::DMG)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_each_element[Stats::DMG][ptr->Sub_Unit_ptr[0]->Element_type[0]][AType::None] += 10;
    };


    return [=](Ally *ptr) {
        
    };
}