#include "../include.h"
namespace Elation_Lightcone{
    // A Little Getaway (4★) — kit: docs/kit-reference/Lightcone/Elation.md (nanoka 4.5.54)
    function<void(CharUnit *ptr)> ALittleGetaway(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,423,397);
            ptr->lightCone.name = "A Little Getaway";

            // Elation 20/25/30/35/40% · during the wearer's Elation Skill: ignore 8/10/12/14/16% DEF
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::ELATION][AType::NONE] += 15 + 5 * superimpose;
                ptr->statsType[Stats::DEF_SHRED][AType::ELATION_SKILL] += 6 + 2 * superimpose;
            }));
        };
    }
}
