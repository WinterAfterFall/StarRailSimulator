#include "../include.h"
PairSetType transString(string s){
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    if(s == "speed" || s == "spd")return PairSetType::SPD_P;
    else if(s == "fua")return PairSetType::FUA;
    else if(s == "dmg")return PairSetType::DMG;
    else if(s == "be")return PairSetType::BE;
    else if(s == "atk")return PairSetType::ATK;
    else if(s == "hp")return PairSetType::HP;
    else if(s == "def")return PairSetType::DEF;
    else if(s == "crit rate" || s == "cr")return PairSetType::CRIT_RATE;
    else if(s == "crit dam" || s == "cd")return PairSetType::CRIT_DAM;
    else if(s == "heal")return PairSetType::HEAL_OUT;
    return PairSetType::ERROR;
}
function<void(CharUnit *ptr)> CharUnit::relicPairSet(PairSetType type){
    if(type == PairSetType::SPD_P)
    return [=](CharUnit *ptr) {
        ptr->atvStats->speedPercent+=6;
    };
    if(type == PairSetType::ATK)
    return [=](CharUnit *ptr) {
        ptr->statsType[Stats::ATK_P][AType::NONE] += 12;
    };
    if(type == PairSetType::HP)
    return [=](CharUnit *ptr) {
        ptr->statsType[Stats::HP_P][AType::NONE] += 12;
    };
    if(type == PairSetType::DEF)
    return [=](CharUnit *ptr) {
        ptr->statsType[Stats::DEF_P][AType::NONE] += 15;
    };
    if(type == PairSetType::CRIT_RATE)
    return [=](CharUnit *ptr) {
        ptr->statsType[Stats::CR][AType::NONE] += 8;
    };
    if(type == PairSetType::CRIT_DAM)
    return [=](CharUnit *ptr) {
        ptr->statsType[Stats::CD][AType::NONE] += 16;
    };
    if(type == PairSetType::BE)
    return [=](CharUnit *ptr) {
        ptr->statsType[Stats::BE][AType::NONE] += 16;
    };
    if(type == PairSetType::HEAL_OUT)
    return [=](CharUnit *ptr) {
        ptr->statsType[Stats::HEALING_OUT][AType::NONE] += 10;
    };
    if(type == PairSetType::FUA)
    return [=](CharUnit *ptr) {
        ptr->statsType[Stats::DMG][AType::FUA] += 20;
    };
    if(type == PairSetType::DMG)
    return [=](CharUnit *ptr) {
        ptr->statsEachElement[Stats::DMG][ptr->elementType][AType::NONE] += 10;
    };


    return [=](CharUnit *ptr) {
        
    };
}