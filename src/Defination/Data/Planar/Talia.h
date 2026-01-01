#include "../include.h"
namespace Planar{
    void Talia(CharUnit *ptr);
    void Talia(CharUnit *ptr){
        
        ptr->Planar.Name = "Talia";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::BE][AType::None] += 16;
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::BE][AType::None] += 20;
        }));
        
       
    }
}