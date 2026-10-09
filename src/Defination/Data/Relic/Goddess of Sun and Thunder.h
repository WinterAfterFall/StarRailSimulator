#include "../include.h"
namespace Relic{
    // Warrior Goddess of Sun and Thunder — kit: docs/kit-reference/Relic.md
    // 2pc SPD +6% · 4pc: wearer or their memosprite heals an ally other than the healer itself -> wearer gets
    //   "Gentle Rain" 2 turns (once per turn): wearer SPD +6%, all allies CRIT DMG +15% · "cannot stack"
    // two wearers share the team CRIT DMG: it is on while at least one wearer holds Gentle Rain (sunThunderHolders)
    inline int sunThunderHolders = 0;

    void Goddess_of_Sun_and_Thunder(CharUnit *ptr){
        ptr->Relic.name = "Goddess of Sun and Thunder";

        // +1 on gain / -1 on loss · own SPD per wearer · team CD +15 only when the holder count goes 0 -> 1 / 1 -> 0
        function<void(int)> gentleRain = [ptr](int sign) {
            buffSingle(ptr,{{Stats::SPD_P,AType::NONE,6.0*sign}});
            int before = sunThunderHolders;
            sunThunderHolders += sign;
            if(before==0&&sunThunderHolders==1)buffAllAlly({{Stats::CD,AType::NONE,15}});
            else if(before==1&&sunThunderHolders==0)buffAllAlly({{Stats::CD,AType::NONE,-15}});
        };

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->atvStats->speedPercent += 6;
            sunThunderHolders = 0;
        }));

        healingList.push_back(TriggerHealing(PRIORITY_IMMEDIATELY, [ptr,gentleRain](AllyUnit *healer, AllyUnit *target, double value) {
            if(!healer->owner->isSameName(ptr))return;
            if(target==healer)return; // healing yourself does not count
            if(isHaveToAddBuff(ptr,"Goddess of Sun and Thunder",2))gentleRain(1);
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [gentleRain](CharUnit *ptr) {
            if(isBuffEnd(ptr,"Goddess of Sun and Thunder"))gentleRain(-1);
        }));

        allyDeathList.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,gentleRain](AllyUnit* target) {
            if(target->isSameName(ptr) && isBuffGoneByDeath(ptr,"Goddess of Sun and Thunder"))gentleRain(-1);
        }));
    }
}
