#include "../include.h"

//Main Stats
void CharUnit::setRelicMainStats(Stats Body, Stats Boot, Stats Orb, Stats Rope) {
    this->Body = RelicMainStatsSet(Body);
    this->Boot = RelicMainStatsSet(Boot);
    this->Orb = RelicMainStatsSet(Orb);
    this->Rope = RelicMainStatsSet(Rope);
}
void CharUnit::setBody(Stats stats) {
    this->Body = RelicMainStatsSet(stats);
}
void CharUnit::setBoot(Stats stats) {
    this->Boot = RelicMainStatsSet(stats);
}
void CharUnit::setOrb(Stats stats) {
    this->Orb = RelicMainStatsSet(stats);
}
void CharUnit::setRope(Stats stats) {
    this->Rope = RelicMainStatsSet(stats);
}
function<void(CharUnit *ptr)> CharUnit::RelicMainStatsSet(Stats stats){
    if(stats == Stats::FLAT_SPD)
    return [=](CharUnit *ptr) {
        ptr->Atv_stats->flatSpeed+=25;
    };
    if(stats == Stats::ATK_P)
    return [=](CharUnit *ptr) {
        ptr->Stats_type[Stats::ATK_P][AType::None] += 43.2;
    };
    if(stats == Stats::HP_P)
    return [=](CharUnit *ptr) {
        ptr->Stats_type[Stats::HP_P][AType::None] += 43.2;
    };
    if(stats == Stats::DEF_P)
    return [=](CharUnit *ptr) {
        ptr->Stats_type[Stats::DEF_P][AType::None] += 54;
    };
    if(stats == Stats::CR)
    return [=](CharUnit *ptr) {
        ptr->Stats_type[Stats::CR][AType::None] += 32.4;
    };
    if(stats == Stats::CD)
    return [=](CharUnit *ptr) {
        ptr->Stats_type[Stats::CD][AType::None] += 64.8;
    };
    if(stats == Stats::BE)
    return [=](CharUnit *ptr) {
        ptr->Stats_type[Stats::BE][AType::None] += 64.8;
    };
    if(stats == Stats::HEALING_OUT)
    return [=](CharUnit *ptr) {
        ptr->Stats_type[Stats::HEALING_OUT][AType::None] += 34.57;
    };
    if(stats == Stats::DMG)
    return [=](CharUnit *ptr) {
        ptr->Stats_each_element[Stats::DMG][ptr->Element_type[0]][AType::None] += 38.88;
    };
    if(stats == Stats::EHR)
    return [=](CharUnit *ptr) {
        ptr->Stats_type[Stats::EHR][AType::None] += 43.2;
    };
    if(stats == Stats::ER)
    return [=](CharUnit *ptr) {
        ptr->Energy_recharge+=19.4;
    };

    return [=](CharUnit *ptr) {
        
    };
}

