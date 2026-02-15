#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> Before_the_Tutorial(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "Before_the_Tutorial";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::EHR][AType::None] += 20 + 5 * superimpose;
            }));
    
            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (act->Attacker->Atv_stats->Name != ptr->Atv_stats->Name) return;
                for (auto e : act->targetList) {
                    if (e->Stats_type[Stats::DEF_SHRED][AType::None] > 0) {
                        Increase_energy(ptr, 3 + superimpose);
                        return;
                    }
                }
            }));
        };
    }
}