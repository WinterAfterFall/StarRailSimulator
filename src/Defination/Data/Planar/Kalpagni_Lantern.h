#include "../include.h"
namespace Planar{
    void Kalpagni_Lantern(Ally *ptr);
    void Kalpagni_Lantern(Ally *ptr){
        
        ptr->Planar.Name="Kalpagni_Lantern";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Atv_stats->speedPercent += 6;
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_BE][AT_NONE] += 40;
        }));
       
    }
}