#include "../include.h"
namespace Planar{
    // Punklorde Stage Zero — kit: docs/kit-reference/Planar.md (nanoka 4.5.54, set 325)
    // Elation +8% · first time Elation reaches 40% / 80% in combat -> CRIT DMG 20% / 32%
    // the two tiers replace each other (80% tier = 32% total, not 20 + 32) and are kept even if Elation drops later
    void PunklordeStageZero(CharUnit *ptr){
        ptr->Planar.name = "Punklorde Stage Zero";

        function<void()> check = [ptr]() {
            double elation = calculateElationOnStats(ptr);
            double tier = (elation>=80) ? 32 : (elation>=40) ? 20 : 0;
            double have = ptr->getBuffNote("Punklorde CD");
            if(tier<=have)return;
            ptr->setBuffNote("Punklorde CD",tier);
            buffSingle(ptr,{{Stats::CD,AType::NONE,tier - have}});
        };

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::ELATION][AType::NONE] += 8;
            ptr->setBuffNote("Punklorde CD",0);
        }));

        // Elation set before the battle (traces / relics / resetList) is only complete once everything is on field
        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_LAST, ptr, [check](CharUnit *ptr) {
            check();
        }));
        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [check](CharUnit *ptr) {
            check();
        }));

        statsAdjustList.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,check](AllyUnit *target, Stats statsType) {
            if(statsType!=Stats::ELATION||!target->isSameName(ptr))return;
            check();
        }));
    }
}
