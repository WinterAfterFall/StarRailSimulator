
#ifndef Passkey_H
#define Passkey_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Erudition_Lightcone{
    function<void(Ally *ptr)> Passkey(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(741,370,265);
            ptr->Light_cone.Name = "Passkey";
    
            After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_) {
                if (data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name&&data_->Action_type.second==AT_SKILL) {
                    Increase_energy(ptr, 7 + superimpose);
                }
            }));
    
            Buff_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_) {
                if (data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name&&data_->Action_type.second==AT_SKILL) {
                    Increase_energy(ptr, 7 + superimpose);
                }
            }));
        };
    }
}
#endif