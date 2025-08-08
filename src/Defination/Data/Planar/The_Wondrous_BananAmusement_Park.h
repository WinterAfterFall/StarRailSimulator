#include "../include.h"
namespace Planar{
    void The_Wondrous_BananAmusement_Park(Ally *ptr);
    void The_Wondrous_BananAmusement_Park(Ally *ptr){
        
        ptr->Planar.Name="The_Wondrous_BananAmusement_Park"; 
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CD][AType::None] += 16;
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Summon_ptr.size() != 0 || ptr->Sub_Unit_ptr.size() > 1) {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CD][AType::None] += 32;
            }
        }));
       
    }
}