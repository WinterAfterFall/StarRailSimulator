#include "../include.h"
namespace Planar{
    function<void(CharUnit *ptr)> GiantTree(bool trigger){
        if(trigger)
        return [=](CharUnit *ptr) {
            ptr->Planar.name = "GiantTree";
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
                ptr->atvStats->speedPercent += 6;
                ptr->statsType[Stats::HEALING_OUT][AType::NONE] += 20;
            }));
        };
        else 
        return [=](CharUnit *ptr) {
            ptr->Planar.name = "GiantTree";
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
                ptr->atvStats->speedPercent += 6;
                ptr->statsType[Stats::HEALING_OUT][AType::NONE] += 12;
            }));
        };
    }
}