
#ifndef BP_Erudition_S1_H
#define BP_Erudition_S1_H

#include "../Library.h"
namespace Erudition_Lightcone{
    void BP_Erudition_S1(Ally *ptr);
    void BP_Erudition_S1(Ally *ptr){
        ptr->Light_cone.Name = "BP_Erudition_S1";
        SetBaseStats(ptr->Sub_Unit_ptr[0].get(),847,529,331);
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Max_energy > 160) {
                ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["None"] += 32;
            } else {
                ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["None"] += ptr->Max_energy * 0.2;
            }
        }));
        
        
    }
}
#endif