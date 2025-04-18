
#ifndef SweatNowCryLess_H
#define SweatNowCryLess_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Remembrance_Lightcone{
    function<void(Ally *ptr)> SweatNowCryLess(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1058,529,198);
            ptr->Light_cone.Name = "SweatNowCryLess";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"] += 10 + 2 * superimpose;
            }));
    
            Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (!Buff_check(ptr->Sub_Unit_ptr[0].get(), "SweatNowCryLess") && ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed > -1) {
                    Buff_single_with_all_memo(ptr, "Dmg%", "None", 20 + superimpose * 4);
                    ptr->Sub_Unit_ptr[0]->Buff_check["SweatNowCryLess"] = 1;
                }
            }));
        };
    }
    
}
#endif