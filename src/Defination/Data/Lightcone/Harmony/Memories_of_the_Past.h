#include "../include.h"
namespace Harmony_Lightcone{
    function<void(CharUnit *ptr)> Memories_of_the_Past(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats( 953, 423, 397);
            ptr->Light_cone.Name = "Memories_of_the_Past";
    
            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (act->Attacker->Atv_stats->StatsOwnerName == ptr->Atv_stats->StatsOwnerName) {
                    Increase_energy(ptr, 3 + superimpose);
                }
            }));
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::BE][AType::None] += 21 + 7 * superimpose;
            }));
        };
    }
}