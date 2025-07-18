#include "../include.h"
namespace Harmony_Lightcone{
    function<void(Ally *ptr)> Meshing_Cogs(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(847,318,265);
            ptr->Light_cone.Name = "Meshing_Cogs";
    
            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (act->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name) {
                    Increase_energy(ptr, 3 + superimpose);
                }
            }));
    
            Enemy_hit_List.push_back(TriggerByEnemyHit(PRIORITY_IMMEDIATELY, [ptr,superimpose](Enemy *Attacker, vector<SubUnit*> target) {
                for (SubUnit* e : target) {
                    if (e->Atv_stats->num == ptr->Sub_Unit_ptr[0]->Atv_stats->num) {
                        Increase_energy(ptr, 3 + superimpose);
                    }
                }
            }));
        };
    }
}