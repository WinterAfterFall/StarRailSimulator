
#ifndef DDD_H
#define DDD_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Harmony_Lightcone{
    function<void(Ally *ptr)> DDD(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,423,397);
            ptr->Light_cone.Name = "DDD";

            AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &data_){
                if (data_->isSameAction(ptr->getSubUnit(),AT_ULT)){
                All_Action_forward(14 + 2 * superimpose);
                }
            }));

        };
    }
}
#endif