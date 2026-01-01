#include "../include.h"
namespace Planar{
    void Kalpagni_Lantern(CharUnit *ptr);
    void Kalpagni_Lantern(CharUnit *ptr){
        
        ptr->Planar.Name="Kalpagni_Lantern";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Atv_stats->speedPercent += 6;
        }));

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::BE][AType::None] += 40;
        }));
       
    }
}