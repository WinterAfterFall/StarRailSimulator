#include "../include.h"
namespace Harmony_Lightcone{
    function<void(CharUnit *ptr)> DDD(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,423,397);
            ptr->lightCone.name = "DDD";

            whenUseUltList.push_back(TriggerByAllyFunc(PRIORITY_IMMEDIATELY,[ptr,superimpose](CharUnit *ally){
                if (ally->isSameOwner(ptr)) {
                    allActionForward(14 + 2 * superimpose);
                }
            }));

        };
    }
}