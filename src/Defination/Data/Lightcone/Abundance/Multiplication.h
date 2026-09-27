#include "../include.h"
namespace Abundance_Lightcone{
    function<void(CharUnit *ptr)> Multiplication(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,318,198);
            ptr->lightCone.name = "Multiplication";
            // After allyAction() so the BA turn reset does not wipe the advance
            afterAllyActionList.push_back(TriggerByAllyActionFunc(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if(act->isSameAction(ptr,AType::BA)){
                    actionForward(ptr->atvStats.get(), 10+2*superimpose);
                }
            }));
        };
    }
}
