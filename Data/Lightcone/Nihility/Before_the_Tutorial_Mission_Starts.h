
#ifndef Before_the_Tutorial_Mission_Starts_H
#define Before_the_Tutorial_Mission_Starts_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Nihility_Lightcone{
    void Before_the_Tutorial(Ally *ptr);
    void Before_the_Tutorial(Ally *ptr){

        SetBaseStats(ptr->Sub_Unit_ptr[0].get(),953,476,331);
        ptr->Light_cone.Name = "Before_the_Tutorial";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Ehr"]["None"] += 40;
        }));

        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](ActionData &data_) {
            if (data_.Attacker->Atv_stats->Unit_Name != ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name) return;
            for (auto e : data_.Target_Attack) {
                if (e->Stats_type["Def"]["None"] > 0) {
                    Increase_energy(ptr, 8);
                    return;
                }
            }
        }));



    }
}
#endif