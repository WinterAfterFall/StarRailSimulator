
#ifndef Memories_of_the_Past_H
#define Memories_of_the_Past_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Harmony_Lightcone{
    function<void(Ally *ptr)> Memories_of_the_Past(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats( 953, 423, 397);
            ptr->Light_cone.Name = "Memories_of_the_Past";
    
            After_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (act->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name) {
                    Increase_energy(ptr, 3 + superimpose);
                }
            }));
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_BE][AT_NONE] += 21 + 7 * superimpose;
            }));
        };
    }
}
#endif