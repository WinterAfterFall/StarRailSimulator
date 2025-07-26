#include "../include.h"
namespace Harmony_Lightcone{
    function<void(Ally *ptr)> DDD(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,423,397);
            ptr->Light_cone.Name = "DDD";

            AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if (act->isSameAction(ptr->getSubUnit(),AType::Ult)){
                All_Action_forward(14 + 2 * superimpose);
                }
            }));

        };
    }
}