#include "../include.h"
namespace Nihility_Lightcone{
    function<void(Ally *ptr)> GNSW(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "GNSW";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG][AT_NONE] += (9 + (3 * superimpose)) * 3;
            }));
        };
    }
}