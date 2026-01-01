#include "../include.h"
namespace Relic{
    void Prisoner(CharUnit *ptr){
        ptr->Relic.Name = "Prisoner";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::ATK_P][AType::None] += 12;
            ptr->Stats_type[Stats::DEF_SHRED][AType::None] += 18;
        }));
        
        
    }
    
}