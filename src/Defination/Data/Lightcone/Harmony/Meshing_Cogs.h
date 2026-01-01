#include "../include.h"
namespace Harmony_Lightcone{
    function<void(CharUnit *ptr)> Meshing_Cogs(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(847,318,265);
            ptr->Light_cone.Name = "Meshing_Cogs";
    
            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (act->Attacker->Atv_stats->StatsOwnerName == ptr->Atv_stats->StatsOwnerName) {
                    Increase_energy(ptr, 3 + superimpose);
                }
            }));
    
            Enemy_hit_List.push_back(TriggerByEnemyHit(PRIORITY_IMMEDIATELY, [ptr,superimpose](Enemy *Attacker, vector<AllyUnit*> target) {
                for (AllyUnit* e : target) {
                    if (e->Atv_stats->num == ptr->Atv_stats->num) {
                        Increase_energy(ptr, 3 + superimpose);
                    }
                }
            }));
        };
    }
}