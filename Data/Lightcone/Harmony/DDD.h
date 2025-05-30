
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
            After_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_) {
                if (data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_->Action_type.second == "Ultimate") {
                All_Action_forward(14 + 2 * superimpose);
                }
            }));
    
            Buff_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_) {
                if (data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_->Action_type.second == "Ultimate") {
                All_Action_forward(14 + 2 * superimpose);
                }
            }));
        };
    }
}
#endif