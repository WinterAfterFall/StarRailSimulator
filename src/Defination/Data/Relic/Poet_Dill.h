#include "../include.h"
namespace Relic{
    void Poet_Dill(CharUnit *ptr);
    void Poet_Dill(CharUnit *ptr){
        ptr->Relic.name = "Poet_Dill";
        
        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->atvStats->speedPercent -= 8;
            ptr->statsEachElement[Stats::DMG][ElementType::QUANTUM][AType::NONE] += 10;
        }));
        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            buffSingleChar(ptr,{{Stats::CR, AType::NONE, 32.0}});
        }));
        
        
    }
}