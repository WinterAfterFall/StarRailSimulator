#include "../include.h"
namespace Planar{
    function<void(Ally *ptr)> FirmanentFrontline(bool trigger){
        if(trigger)
        return [=](Ally *ptr) {
            ptr->Planar.Name = "FirmanentFrontline";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 12;
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::None] += 18;
            }));
        };
        else 
        return [=](Ally *ptr) {
            ptr->Planar.Name = "FirmanentFrontline";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 12;
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::None] += 12;
            }));
        };
    }
}