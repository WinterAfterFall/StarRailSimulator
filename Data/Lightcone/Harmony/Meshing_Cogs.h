
#ifndef Meshing_Cogs_H
#define Meshing_Cogs_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Harmony_Lightcone{
    void Meshing_Cogs(Ally *ptr);
    void Meshing_Cogs(Ally *ptr){

        SetBaseStats(ptr->Sub_Unit_ptr[0].get(),847,318,265);
        ptr->Light_cone.Name = "Meshing_Cogs";

        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr, Combat_data &data_){
            
            if(data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name){
                Increase_energy(ptr,8);
            }
            
        }
        ));
        
        Enemy_hit_List.push_back(TriggerByEnemyHit(PRIORITY_IMMEDIATELY,ptr,[](Ally *ptr,Enemy *target){
            
            
            Increase_energy(ptr,8);
            
            
        }
        ));
    }
}
#endif