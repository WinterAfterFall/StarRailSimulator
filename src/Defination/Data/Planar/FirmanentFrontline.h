#include "../include.h"
namespace Planar{
    function<void(CharUnit *ptr)> FirmanentFrontline(bool trigger){
        if(trigger)
        return [=](CharUnit *ptr) {
            ptr->Planar.Name = "FirmanentFrontline";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
                ptr->Stats_type[Stats::ATK_P][AType::None] += 12;
                ptr->Stats_type[Stats::DMG][AType::None] += 18;
            }));
        };
        else 
        return [=](CharUnit *ptr) {
            ptr->Planar.Name = "FirmanentFrontline";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
                ptr->Stats_type[Stats::ATK_P][AType::None] += 12;
                ptr->Stats_type[Stats::DMG][AType::None] += 12;
            }));
        };
    }
}