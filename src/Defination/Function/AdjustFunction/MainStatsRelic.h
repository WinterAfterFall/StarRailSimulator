#include "../include.h"

//Main Stats
void Ally::setRelicMainStats(Stats Body, Stats Boot, Stats Orb, Stats Rope) {
    this->Body = RelicMainStatsSet(Body);
    this->Boot = RelicMainStatsSet(Boot);
    this->Orb = RelicMainStatsSet(Orb);
    this->Rope = RelicMainStatsSet(Rope);
}
void Ally::setBody(Stats stats) {
    this->Body = RelicMainStatsSet(stats);
}
void Ally::setBoot(Stats stats) {
    this->Boot = RelicMainStatsSet(stats);
}
void Ally::setOrb(Stats stats) {
    this->Orb = RelicMainStatsSet(stats);
}
void Ally::setRope(Stats stats) {
    this->Rope = RelicMainStatsSet(stats);
}
function<void(Ally *ptr)> Ally::RelicMainStatsSet(Stats stats){
    if(stats == Stats::FLAT_SPD)
    return [=](Ally *ptr) {
        ptr->getSubUnit()->Atv_stats->flatSpeed+=25;
    };
    if(stats == Stats::ATK_P)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 43.2;
    };
    if(stats == Stats::HP_P)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::HP_P][AType::None] += 43.2;
    };
    if(stats == Stats::DEF_P)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DEF_P][AType::None] += 54;
    };
    if(stats == Stats::CR)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::None] += 32.4;
    };
    if(stats == Stats::CD)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CD][AType::None] += 64.8;
    };
    if(stats == Stats::BE)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::BE][AType::None] += 64.8;
    };
    if(stats == Stats::HEALING_OUT)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::HEALING_OUT][AType::None] += 34.57;
    };
    if(stats == Stats::DMG)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_each_element[Stats::DMG][ptr->Sub_Unit_ptr[0]->Element_type[0]][AType::None] += 38.88;
    };
    if(stats == Stats::EHR)
    return [=](Ally *ptr) {
        ptr->Sub_Unit_ptr[0]->Stats_type[Stats::EHR][AType::None] += 43.2;
    };
    if(stats == Stats::ER)
    return [=](Ally *ptr) {
        ptr->Energy_recharge+=19.4;
    };

    return [=](Ally *ptr) {
        
    };
}

