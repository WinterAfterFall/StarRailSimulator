
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
            After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_){
                        
                if(data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_->Action_type.second == "Basic_Attack"){
                    Action_forward(turn, 10+2*superimpose);
                }
            
            }));
            Buff_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_){

                if(data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_->Action_type.second == "Basic_Attack"){
                    Action_forward(turn, 10+2*superimpose);
                }

                }
            ));
        };
    }
}
#endif