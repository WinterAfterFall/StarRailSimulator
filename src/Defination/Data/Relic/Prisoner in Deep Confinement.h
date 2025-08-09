#include "../include.h"
namespace Relic{
    void Prisoner(Ally *ptr){
        ptr->Relic.Name = "Prisoner";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 12;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DEF_SHRED][AType::None] += 18;
        }));
        
        
    }
    
}