
#ifndef Multiplication_H
#define Multiplication_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Abundance_Lightcone{
    function<void(Ally *ptr)> Multiplication(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,318,198);
            ptr->Light_cone.Name = "Multiplication";
            AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &data_){
                if(data_->isSameAction(ptr->getSubUnit(),AT_BA)){
                    Action_forward(turn, 10+2*superimpose);
                }
            }));
        };
    }
}
#endif