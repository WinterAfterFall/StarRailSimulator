
#ifndef Before_the_Tutorial_Mission_Starts_H
#define Before_the_Tutorial_Mission_Starts_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Nihility_Lightcone{
    function<void(Ally *ptr)> Before_the_Tutorial(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "Before_the_Tutorial";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type["Ehr"]["None"] += 20 + 5 * superimpose;
            }));
    
            After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](ActionData &data_) {
                if (data_.Attacker->Atv_stats->Unit_Name != ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name) return;
                for (auto e : data_.Target_Attack) {
                    if (e->Stats_type["Def"]["None"] > 0) {
                        Increase_energy(ptr, 3 + superimpose);
                        return;
                    }
                }
            }));
        };
    }
}
#endif