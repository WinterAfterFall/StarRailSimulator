#include "../include.h"
namespace Harmony_Lightcone{
    function<void(CharUnit *ptr)> Meshing_Cogs(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(847,318,265);
            ptr->Light_cone.Name = "Meshing_Cogs";
    
            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (act->Attacker->Atv_stats->Name != ptr->Atv_stats->Name) return;
                if (ptr->getBuffCheck("Meshing_Cogs_Triggered")) return;
                ptr->setBuffCheck("Meshing_Cogs_Triggered",1);
                Increase_energy(ptr, 3 + superimpose);
            }));
    
            Enemy_hit_List.push_back(TriggerByEnemyHit(PRIORITY_IMMEDIATELY, [ptr,superimpose](Enemy *Attacker, vector<AllyUnit*> target) {
                for (AllyUnit* e : target) {
                    if (e->Atv_stats->num != ptr->Atv_stats->num) continue;
                    if (ptr->getBuffCheck("Meshing_Cogs_Triggered")) return;
                    ptr->setBuffCheck("Meshing_Cogs_Triggered",1);
                    Increase_energy(ptr, 3 + superimpose);
                    return;
                }
            }));

            Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
                ptr->setBuffCheck("Meshing_Cogs_Triggered",0);
            }));
        };
    }
}