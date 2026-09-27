#include "../include.h"
namespace Harmony_Lightcone{
    function<void(CharUnit *ptr)> Memories_of_the_Past(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats( 953, 423, 397);
            ptr->lightCone.name = "Memories_of_the_Past";
    
            afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (act->attacker->atvStats->name != ptr->atvStats->name) return;
                if (ptr->getBuffCheck("Memories_of_the_Past_Triggered")) return;
                ptr->setBuffCheck("Memories_of_the_Past_Triggered",1);
                increaseEnergy(ptr, 3 + superimpose);
            }));

            beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
                ptr->setBuffCheck("Memories_of_the_Past_Triggered",0);
            }));
    
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::BE][AType::NONE] += 21 + 7 * superimpose;
            }));
        };
    }
}