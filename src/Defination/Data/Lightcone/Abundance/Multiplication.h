#include "../include.h"
namespace Abundance_Lightcone{
    function<void(CharUnit *ptr)> Multiplication(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,318,198);
            ptr->Light_cone.Name = "Multiplication";
            // After AllyAction() so the BA turn reset does not wipe the advance
            AfterAllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if(act->isSameAction(ptr,AType::BA)){
                    Action_forward(ptr->Atv_stats.get(), 10+2*superimpose);
                }
            }));
        };
    }
}
