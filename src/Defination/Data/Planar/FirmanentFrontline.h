#include "../include.h"
namespace Planar{
    function<void(CharUnit *ptr)> FirmanentFrontline(bool trigger){
        if(trigger)
        return [=](CharUnit *ptr) {
            ptr->Planar.name = "FirmanentFrontline";
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
                ptr->statsType[Stats::ATK_P][AType::NONE] += 12;
                ptr->statsType[Stats::DMG][AType::NONE] += 18;
            }));
        };
        else 
        return [=](CharUnit *ptr) {
            ptr->Planar.name = "FirmanentFrontline";
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
                ptr->statsType[Stats::ATK_P][AType::NONE] += 12;
                ptr->statsType[Stats::DMG][AType::NONE] += 12;
            }));
        };
    }
}