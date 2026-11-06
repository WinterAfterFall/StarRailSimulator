#include "../include.h"
namespace Elation_Lightcone{
    // See You at the World's End!
    // CRIT DMG 6/7/8/9/10% per Elation character in the team · Aeon Aha on field -> +12/14/16/18/20% more
    function<void(CharUnit *ptr)> SeeYouAtTheWorldsEnd(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(847,476,397);
            ptr->lightCone.name = "See You at the World's End!";

            // elationCount / aeonAha are fixed at setup -> safe to read in resetList
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::CD][AType::NONE] += (5.0 + superimpose) * elationCount;
                if(aeonAha)ptr->statsType[Stats::CD][AType::NONE] += 10.0 + 2 * superimpose;
            }));
        };
    }
}
