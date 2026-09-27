#include "../include.h"
namespace Relic{
    void Eagle_Beaked_Helmet(CharUnit *ptr){
        ptr->Relic.name = "Eagle_Beaked_Helmet";
        ptr->addUltCondition([ptr]() -> bool {
            if(ptr->atvStats->atv<=ptr->atvStats->maxAtv*0.25)return false;
            return true;
        });

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsEachElement[Stats::DMG][ElementType::WIND][AType::NONE] += 10;
        }));

        whenUseUltList.push_back(TriggerByAllyFunc(PRIORITY_IMMEDIATELY,[ptr](CharUnit *ally){
            if (ally->isSameOwner(ptr)) {
                actionForward(ptr->atvStats.get(), 25);
            }
        }));
        
    }
    
}