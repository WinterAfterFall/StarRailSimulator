#include "../include.h"
namespace Erudition_Lightcone{
    function<void(Ally *ptr)> BP_Erudition(int superimpose){
    return [=](Ally *ptr) {
        ptr->SetAllyBaseStats(847,529,331);
        ptr->Light_cone.Name = "BP_Erudition";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
            if (ptr->Max_energy > 160) {
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG][AT_NONE] += 24 + superimpose * 8;
            } else {
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG][AT_NONE] += ptr->Max_energy * (0.15 + 0.05 * superimpose);
            }
        }));
    };
}
}