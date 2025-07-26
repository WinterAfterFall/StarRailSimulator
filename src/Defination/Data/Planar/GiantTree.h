#include "../include.h"
namespace Planar{
    function<void(Ally *ptr)> GiantTree(bool trigger){
        if(trigger)
        return [=](Ally *ptr) {
            ptr->Planar.Name = "GiantTree";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
                ptr->Sub_Unit_ptr[0]->Atv_stats->speedPercent += 6;
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_HEALING_OUT][AType::None] += 20;
            }));
        };
        else 
        return [=](Ally *ptr) {
            ptr->Planar.Name = "GiantTree";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
                ptr->Sub_Unit_ptr[0]->Atv_stats->speedPercent += 6;
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_HEALING_OUT][AType::None] += 12;
            }));
        };
    }
}