#include "../include.h"
namespace Erudition_Lightcone{
    function<void(Ally *ptr)> Cosmos_Fell(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "Cosmos_Fell";
    
            When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AT_NONE] += 14 + 2*superimpose;
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_CD][AT_NONE] += 15 + 5*superimpose;
            }));
        };
    }
}