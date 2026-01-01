#include "../include.h"
namespace Relic{
    void GeniusBrilliant(CharUnit *ptr){
        ptr->Relic.Name = "GeniusBrilliant";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_each_element[Stats::DMG][ElementType::Quantum][AType::None] += 10;
            ptr->Stats_type[Stats::DEF_SHRED][AType::None] += 20;
        }));
        
        
    }
    
}