#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> GNSW(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,476,331);
            ptr->lightCone.name = "GNSW";
    
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::DMG][AType::NONE] += (9 + (3 * superimpose)) * 3;
            }));
        };
    }
}