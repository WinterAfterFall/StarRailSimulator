#include "../include.h"
namespace Relic{
    void Iron_Cavalry(CharUnit *ptr);
    void Iron_Cavalry(CharUnit *ptr){
        ptr->Relic.name = "Iron_Cavalry";
        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::BE][AType::NONE] += 16;
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::DEF_SHRED][AType::BREAK] += 10;
            ptr->statsType[Stats::DEF_SHRED][AType::SPB] += 15;
        }));

        
    }
}