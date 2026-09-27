#include "../include.h"
namespace Erudition_Lightcone{
    function<void(CharUnit *ptr)> Rappa_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,582,529);
            ptr->lightCone.name = "Rappa_LC";
    
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::BE][AType::NONE] += 50 + superimpose * 10;
            }));
    
            startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                increaseEnergy(ptr, (27.5 + superimpose * 2.5));
            }));


            whenUseUltList.push_back(TriggerByAllyFunc(PRIORITY_IMMEDIATELY,[ptr,superimpose](CharUnit *ally){
                if (ally->isSameOwner(ptr)) {
                    ptr->buffCheck["Ration"] = 1;
                    ptr->stack["Ration"] = 0;
                }
            }));

            afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (act->isSameAction(ptr,AType::BA)&& ptr->buffCheck["Ration"] == 1) {
                    ptr->stack["Ration"]++;
                    if (ptr->stack["Ration"] == 2) {
                        actionForward(ptr->atvStats.get(), (45 + superimpose * 5));
                        ptr->buffCheck["Ration"] = 0;
                    }
                }
            }));
            
        };
    }
}
