#include "../include.h"
namespace Abundance_Lightcone{
    function<void(CharUnit *ptr)> Multiplication(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,318,198);
            ptr->Light_cone.Name = "Multiplication";
            AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if(act->isSameCharAction(ptr,AType::BA)){
                    Action_forward(turn, 10+2*superimpose);
                }
            }));
        };
    }
}