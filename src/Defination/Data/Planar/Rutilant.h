#include "../include.h"
namespace Planar{
    void Rutilant(Ally *ptr);
    void Rutilant(Ally *ptr){
        
        ptr->Planar.Name = "    ";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::None] += 8;
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::SKILL] += 20;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::BA] += 20;
        }));
        
       
    }
}