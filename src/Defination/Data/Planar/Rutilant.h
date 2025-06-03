#include "../include.h"
namespace Planar{
    void Rutilant(Ally *ptr);
    void Rutilant(Ally *ptr){
        
        ptr->Planar.Name = "Rutilant";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AT_NONE] += 8;
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG]["Skill"] += 20;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG]["Basic_Attack"] += 20;
        }));
        
       
    }
}