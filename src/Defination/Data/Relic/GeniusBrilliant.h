#include "../include.h"
namespace Relic{
    void GeniusBrilliant(Ally *ptr){
        ptr->Relic.Name = "GeniusBrilliant";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG][ElementType::Quantum][AType::None] += 10;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_DEF_SHRED][AType::None] += 20;
        }));
        
        
    }
    
}