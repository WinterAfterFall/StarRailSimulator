#include "../include.h"
namespace Relic{
    void Prisoner(CharUnit *ptr){
        ptr->Relic.name = "Prisoner";

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::ATK_P][AType::NONE] += 12;
            ptr->statsType[Stats::DEF_SHRED][AType::NONE] += 18;
        }));
        
        
    }
    
}