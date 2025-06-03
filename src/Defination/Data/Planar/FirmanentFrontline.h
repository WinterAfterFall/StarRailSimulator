#include "../include.h"
namespace Planar{
    function<void(Ally *ptr)> FirmanentFrontline(bool trigger){
        if(trigger)
        return [=](Ally *ptr) {
            ptr->Planar.Name = "FirmanentFrontline";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_ATK_P][AT_NONE] += 12;
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG][AT_NONE] += 18;
            }));
        };
        else 
        return [=](Ally *ptr) {
            ptr->Planar.Name = "FirmanentFrontline";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_ATK_P][AT_NONE] += 12;
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG][AT_NONE] += 12;
            }));
        };
    }
}