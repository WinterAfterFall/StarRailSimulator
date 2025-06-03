#include "../include.h"
namespace Abundance_Lightcone{
    function<void(Ally *ptr)> Multiplication(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,318,198);
            ptr->Light_cone.Name = "Multiplication";
            AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if(act->isSameAction(ptr->getSubUnit(),AT_BA)){
                    Action_forward(turn, 10+2*superimpose);
                }
            }));
        };
    }
}