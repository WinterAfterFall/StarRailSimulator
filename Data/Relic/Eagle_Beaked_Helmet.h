
#ifndef Eagle_Beaked_Helmet_H
#define Eagle_Beaked_Helmet_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Relic{
    void Eagle_Beaked_Helmet(Ally *ptr);
    void Eagle_Beaked_Helmet(Ally *ptr){
        ptr->Relic.Name = "Eagle_Beaked_Helmet";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr){
            ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Wind"]["None"]+=10;
        }
        ));
        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr, Combat_data &data_){
            
            if(data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_.Action_type.second=="Ultimate"){
                Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(),25);
            }
            
        }
        ));

        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr, Combat_data &data_){
            
            if(data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_.Action_type.second=="Ultimate"){
                Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(),25);
            }
        }
        ));
        
        
    }
}
#endif