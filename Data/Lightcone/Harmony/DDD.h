
#ifndef DDD_H
#define DDD_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Harmony_Lightcone{
    void DDD(Ally *ptr);
    void DDD(Ally *ptr){
        SetBaseStats(ptr->Sub_Unit_ptr[0].get(),953,423,397);
        ptr->Light_cone.Name = "DDD";

        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr, ActionData &data_){
            
            if(data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_.Action_type.second=="Ultimate"){
                All_Action_forward(24);
            }
            
        }
        ));

        Buff_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr, ActionData &data_){
            
            if(data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_.Action_type.second=="Ultimate"){
                All_Action_forward(24);
            }
        }
        ));
    }
}
#endif