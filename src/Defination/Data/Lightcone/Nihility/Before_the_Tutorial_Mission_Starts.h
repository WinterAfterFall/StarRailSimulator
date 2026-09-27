#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> Before_the_Tutorial(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,476,331);
            ptr->lightCone.name = "Before_the_Tutorial";
    
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::EHR][AType::NONE] += 15 + 5 * superimpose;
            }));
    
            afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (!act->isSameOwnerName(ptr)) return;
                for (auto e : act->targetList) {
                    for (auto &shred : e->statsType[Stats::DEF_SHRED]) {
                        if (shred.second <= 0) continue;
                        increaseEnergy(ptr, 3 + superimpose);
                        return;
                    }
                }
            }));
        };
    }
}