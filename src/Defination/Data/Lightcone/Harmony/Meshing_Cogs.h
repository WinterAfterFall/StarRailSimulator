#include "../include.h"
namespace Harmony_Lightcone{
    function<void(CharUnit *ptr)> Meshing_Cogs(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(847,318,265);
            ptr->lightCone.name = "Meshing_Cogs";
    
            afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (act->attacker->atvStats->name != ptr->atvStats->name) return;
                if (ptr->getBuffCheck("Meshing_Cogs_Triggered")) return;
                ptr->setBuffCheck("Meshing_Cogs_Triggered",1);
                increaseEnergy(ptr, 3 + superimpose);
            }));
    
            enemyHitList.push_back(TriggerByEnemyHit(PRIORITY_IMMEDIATELY, [ptr,superimpose](Enemy *attacker, vector<AllyUnit*> target) {
                for (AllyUnit* e : target) {
                    if (e->atvStats->num != ptr->atvStats->num) continue;
                    if (ptr->getBuffCheck("Meshing_Cogs_Triggered")) return;
                    ptr->setBuffCheck("Meshing_Cogs_Triggered",1);
                    increaseEnergy(ptr, 3 + superimpose);
                    return;
                }
            }));

            beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
                ptr->setBuffCheck("Meshing_Cogs_Triggered",0);
            }));
        };
    }
}