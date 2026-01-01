#include "../include.h"
namespace Erudition_Lightcone{
    function<void(CharUnit *ptr)> Cosmos_Fell(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "Cosmos_Fell";
    
            WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 14 + 2*superimpose;
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CD][AType::None] += 15 + 5*superimpose;
            }));
        };
    }
}