#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> BP2(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1058,529,331);
            ptr->lightCone.name = "A Trail of Bygone Blood";
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr){
                        
                ptr->statsType[Stats::CR][AType::NONE]+=10 + (2*superimpose);
                ptr->statsType[Stats::DMG][AType::SKILL]+=20 + (4*superimpose);
                ptr->statsType[Stats::DMG][AType::ULT]+=20 + (4*superimpose);
                
                }
            ));
        };
    }
}
