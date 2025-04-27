#ifndef MainStatsRelic_H
#define MainStatsRelic_H

#include "../Class/Trigger_Function.h"

//Main Stats
void Ally::setRelicMainStats(string Body, string Boot, string Orb, string Rope) {
    this->Body = RelicMainStatsSet(Body);
    this->Boot = RelicMainStatsSet(Boot);
    this->Orb = RelicMainStatsSet(Orb);
    this->Rope = RelicMainStatsSet(Rope);
}
void Ally::setBody(string stats) {
    this->Body = RelicMainStatsSet(stats);
}
void Ally::setBoot(string stats) {
    this->Boot = RelicMainStatsSet(stats);
}
void Ally::setOrb(string stats) {
    this->Orb = RelicMainStatsSet(stats);
}
void Ally::setRope(string stats) {
    this->Rope = RelicMainStatsSet(stats);
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