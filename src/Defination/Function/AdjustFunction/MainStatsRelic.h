#include "../include.h"

//Main Stats
void CharUnit::setRelicMainStats(Stats body, Stats boot, Stats orb, Stats rope) {
    this->body = relicMainStatsSet(body);
    this->boot = relicMainStatsSet(boot);
    this->orb = relicMainStatsSet(orb);
    this->rope = relicMainStatsSet(rope);
}
void CharUnit::setBody(Stats stats) {
    this->body = relicMainStatsSet(stats);
}
void CharUnit::setBoot(Stats stats) {
    this->boot = relicMainStatsSet(stats);
}
void CharUnit::setOrb(Stats stats) {
    this->orb = relicMainStatsSet(stats);
}
void CharUnit::setRope(Stats stats) {
    this->rope = relicMainStatsSet(stats);
}
function<void(CharUnit *ptr)> CharUnit::relicMainStatsSet(Stats stats){
    if(stats == Stats::FLAT_SPD)
    return [=](CharUnit *ptr) {
        ptr->atvStats->flatSpeed+=25;
    };
    if(stats == Stats::ATK_P)
    return [=](CharUnit *ptr) {
        ptr->statsType[Stats::ATK_P][AType::NONE] += 43.2;
    };
    if(stats == Stats::HP_P)
    return [=](CharUnit *ptr) {
        ptr->statsType[Stats::HP_P][AType::NONE] += 43.2;
    };
    if(stats == Stats::DEF_P)
    return [=](CharUnit *ptr) {
        ptr->statsType[Stats::DEF_P][AType::NONE] += 54;
    };
    if(stats == Stats::CR)
    return [=](CharUnit *ptr) {
        ptr->statsType[Stats::CR][AType::NONE] += 32.4;
    };
    if(stats == Stats::CD)
    return [=](CharUnit *ptr) {
        ptr->statsType[Stats::CD][AType::NONE] += 64.8;
    };
    if(stats == Stats::BE)
    return [=](CharUnit *ptr) {
        ptr->statsType[Stats::BE][AType::NONE] += 64.8;
    };
    if(stats == Stats::HEALING_OUT)
    return [=](CharUnit *ptr) {
        ptr->statsType[Stats::HEALING_OUT][AType::NONE] += 34.57;
    };
    if(stats == Stats::DMG)
    return [=](CharUnit *ptr) {
        ptr->statsEachElement[Stats::DMG][ptr->elementType][AType::NONE] += 38.88;
    };
    if(stats == Stats::EHR)
    return [=](CharUnit *ptr) {
        ptr->statsType[Stats::EHR][AType::NONE] += 43.2;
    };
    if(stats == Stats::ER)
    return [=](CharUnit *ptr) {
        ptr->energyRecharge+=19.4;
    };

    return [=](CharUnit *ptr) {
        
    };
}

