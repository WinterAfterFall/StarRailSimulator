#include "../include.h"
namespace Harmony_Lightcone{
    function<void(Ally *ptr)> DDD(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,423,397);
            ptr->Light_cone.Name = "DDD";

            WhenUseUlt_List.push_back(TriggerByAlly_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](Ally *ally){
                if (ally->isSameAlly(ptr)) {
                    All_Action_forward(14 + 2 * superimpose);
                }
            }));

        };
    }
}