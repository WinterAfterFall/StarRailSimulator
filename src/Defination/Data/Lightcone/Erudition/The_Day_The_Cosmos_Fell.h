#include "../include.h"
namespace Erudition_Lightcone{
    function<void(CharUnit *ptr)> Cosmos_Fell(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,476,331);
            ptr->lightCone.name = "Cosmos_Fell";
    
            whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::ATK_P][AType::NONE] += 14 + 2*superimpose;
                ptr->statsType[Stats::CD][AType::NONE] += 15 + 5*superimpose;
            }));
        };
    }
}