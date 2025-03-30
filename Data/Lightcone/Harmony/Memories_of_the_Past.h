
#ifndef Memories_of_the_Past_H
#define Memories_of_the_Past_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Harmony_Lightcone{
    void Memories_of_the_Past(Ally *ptr);
    void Memories_of_the_Past(Ally *ptr) {
        SetBaseStats(ptr->Sub_Unit_ptr[0].get(), 953, 423, 397);
        ptr->Light_cone.Name = "Memories_of_the_Past";

        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](ActionData &data_) {
            if (data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name) {
                Increase_energy(ptr, 8);
            }
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"] += 56;
        }));
    }
}
#endif