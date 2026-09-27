#include "../include.h"
namespace Erudition_Lightcone{
    function<void(CharUnit *ptr)> GreatCosmic(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,476,331);
            ptr->lightCone.name = "GreatCosmic";
    
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::ATK_P][AType::NONE] += (6 + superimpose * 2);
                ptr->statsType[Stats::DMG][AType::NONE] += (3+superimpose)*7;
            }));
    
            // After_attack_List.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &act) {

            // }));
        };
    }
}