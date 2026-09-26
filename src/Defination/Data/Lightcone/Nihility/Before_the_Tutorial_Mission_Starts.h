#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> Before_the_Tutorial(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "Before_the_Tutorial";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::EHR][AType::None] += 15 + 5 * superimpose;
            }));
    
            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (!act->isSameOwnerName(ptr)) return;
                for (auto e : act->targetList) {
                    for (auto &shred : e->Stats_type[Stats::DEF_SHRED]) {
                        if (shred.second <= 0) continue;
                        Increase_energy(ptr, 3 + superimpose);
                        return;
                    }
                }
            }));
        };
    }
}