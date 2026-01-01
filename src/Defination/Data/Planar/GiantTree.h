#include "../include.h"
namespace Planar{
    function<void(CharUnit *ptr)> GiantTree(bool trigger){
        if(trigger)
        return [=](CharUnit *ptr) {
            ptr->Planar.Name = "GiantTree";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
                ptr->Atv_stats->speedPercent += 6;
                ptr->Stats_type[Stats::HEALING_OUT][AType::None] += 20;
            }));
        };
        else 
        return [=](CharUnit *ptr) {
            ptr->Planar.Name = "GiantTree";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
                ptr->Atv_stats->speedPercent += 6;
                ptr->Stats_type[Stats::HEALING_OUT][AType::None] += 12;
            }));
        };
    }
}