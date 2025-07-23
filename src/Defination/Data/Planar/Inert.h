#include "../include.h"
namespace Planar{
    void Inert(Ally *ptr){
        
        ptr->Planar.Name = "SpaceSealing";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AT_NONE] += 8;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG][AT_ULT] += 15;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG][AT_FUA] += 15;
        }));
        
       
    }
}