#include "../include.h"
namespace Planar{
    void Talia(Ally *ptr);
    void Talia(Ally *ptr){
        
        ptr->Planar.Name = "Talia";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_BE][AT_NONE] += 16;
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_BE][AT_NONE] += 20;
        }));
        
       
    }
}