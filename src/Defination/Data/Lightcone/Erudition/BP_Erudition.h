#include "../include.h"
namespace Erudition_Lightcone{
    function<void(CharUnit *ptr)> BP_Erudition(int superimpose){
    return [=](CharUnit *ptr) {
        ptr->setAllyBaseStats(847,529,331);
        ptr->lightCone.name = "BP_Erudition";
        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
            if (ptr->maxEnergy > 160) {
                ptr->statsType[Stats::DMG][AType::NONE] += 24 + superimpose * 8;
            } else {
                ptr->statsType[Stats::DMG][AType::NONE] += ptr->maxEnergy * (0.15 + 0.05 * superimpose);
            }
        }));
    };
}
}