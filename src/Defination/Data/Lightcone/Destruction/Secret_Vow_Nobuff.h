#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> Secret_Vow_NoBuff(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1058,476,265);
            ptr->lightCone.name = "Secret_Vow";
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::DMG][AType::NONE] += 15 + 5 * superimpose;
            }));
        };
    }
}