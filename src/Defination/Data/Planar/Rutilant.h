#include "../include.h"
namespace Planar{
    void Rutilant(CharUnit *ptr);
    void Rutilant(CharUnit *ptr){
        
        ptr->Planar.Name = "    ";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::None] += 8;
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::SKILL] += 20;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::BA] += 20;
        }));
        
       
    }
}