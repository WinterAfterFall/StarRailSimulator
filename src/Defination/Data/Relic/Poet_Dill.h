#include "../include.h"
namespace Relic{
    void Poet_Dill(Ally *ptr);
    void Poet_Dill(Ally *ptr){
        ptr->Relic.Name = "Poet_Dill";
        
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Atv_stats->speedPercent -= 8;
            ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG][ElementType::Quantum][AT_NONE] += 10;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AT_NONE] += 32;
        }));
        
        
    }
}