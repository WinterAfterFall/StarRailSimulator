#include "../include.h"
namespace Relic{
    void GeniusBrilliant(CharUnit *ptr){
        ptr->Relic.name = "GeniusBrilliant";

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsEachElement[Stats::DMG][ElementType::QUANTUM][AType::NONE] += 10;
            ptr->statsType[Stats::DEF_SHRED][AType::NONE] += 20;
        }));
        
        
    }
    
}