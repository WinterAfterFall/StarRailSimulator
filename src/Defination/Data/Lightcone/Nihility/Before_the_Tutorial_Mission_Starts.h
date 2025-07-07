#include "../include.h"
namespace Nihility_Lightcone{
    function<void(Ally *ptr)> Before_the_Tutorial(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "Before_the_Tutorial";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type["Ehr"][AT_NONE] += 20 + 5 * superimpose;
            }));
    
            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (act->Attacker->Atv_stats->Unit_Name != ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name) return;
                for (auto e : act->targetList) {
                    if (e->Stats_type[ST_DEF_SHRED][AT_NONE] > 0) {
                        Increase_energy(ptr, 3 + superimpose);
                        return;
                    }
                }
            }));
        };
    }
}