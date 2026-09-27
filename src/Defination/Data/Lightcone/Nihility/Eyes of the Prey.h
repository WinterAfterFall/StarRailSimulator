#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> EyesOfThePrey(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,476,331);
            ptr->lightCone.name = "Eyes of the Prey";
    
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::EHR][AType::NONE] += 15 + superimpose * 5;
                ptr->statsType[Stats::DMG][AType::DOT] += 18 + superimpose * 6;
            }));
        };
    }
}