
#ifndef SweatNowCryLess_H
#define SweatNowCryLess_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Remembrance_Lightcone{
    void SweatNowCryLess(Ally *ptr);
    void SweatNowCryLess(Ally *ptr){
        SetBaseStats(ptr->Sub_Unit_ptr[0].get(),1058,529,198);
        ptr->Light_cone.Name = "SweatNowCryLess";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"] += 20;
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (!Buff_check(ptr->Sub_Unit_ptr[0].get(), "SweatNowCryLess") && ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed > -1) {
                Buff_single_with_all_memo(ptr, "Dmg%", "None", 36);
                ptr->Sub_Unit_ptr[0]->Buff_check["SweatNowCryLess"] = 1;
            }
        }));

    }
    
}
#endif