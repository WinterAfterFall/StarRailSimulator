#include "../include.h"
PairSetType transString(string s){
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    if(s == "speed" || s == "spd")return PairSetType::Spd_P;
    else if(s == "fua")return PairSetType::Fua;
    else if(s == "dmg")return PairSetType::DMG;
    else if(s == "be")return PairSetType::BE;
    else if(s == "atk")return PairSetType::ATK;
    else if(s == "hp")return PairSetType::HP;
    else if(s == "def")return PairSetType::DEF;
    else if(s == "crit rate" || s == "cr")return PairSetType::CritRate;
    else if(s == "crit dam" || s == "cd")return PairSetType::CritDam;
    else if(s == "heal")return PairSetType::HealOut;
    return PairSetType::ERROR;
}
function<void(CharUnit *ptr)> CharUnit::RelicPairSet(PairSetType Type){
    if(Type == PairSetType::Spd_P)
    return [=](CharUnit *ptr) {
        ptr->Atv_stats->speedPercent+=6;
    };
    if(Type == PairSetType::ATK)
    return [=](CharUnit *ptr) {
        ptr->Stats_type[Stats::ATK_P][AType::None] += 12;
    };
    if(Type == PairSetType::HP)
    return [=](CharUnit *ptr) {
        ptr->Stats_type[Stats::HP_P][AType::None] += 12;
    };
    if(Type == PairSetType::DEF)
    return [=](CharUnit *ptr) {
        ptr->Stats_type[Stats::DEF_P][AType::None] += 15;
    };
    if(Type == PairSetType::CritRate)
    return [=](CharUnit *ptr) {
        ptr->Stats_type[Stats::CR][AType::None] += 8;
    };
    if(Type == PairSetType::CritDam)
    return [=](CharUnit *ptr) {
        ptr->Stats_type[Stats::CD][AType::None] += 16;
    };
    if(Type == PairSetType::BE)
    return [=](CharUnit *ptr) {
        ptr->Stats_type[Stats::BE][AType::None] += 16;
    };
    if(Type == PairSetType::HealOut)
    return [=](CharUnit *ptr) {
        ptr->Stats_type[Stats::HEALING_OUT][AType::None] += 10;
    };
    if(Type == PairSetType::Fua)
    return [=](CharUnit *ptr) {
        ptr->Stats_type[Stats::DMG][AType::Fua] += 20;
    };
    if(Type == PairSetType::DMG)
    return [=](CharUnit *ptr) {
        ptr->Stats_each_element[Stats::DMG][ptr->Element_type[0]][AType::None] += 10;
    };


    return [=](CharUnit *ptr) {
        
    };
}