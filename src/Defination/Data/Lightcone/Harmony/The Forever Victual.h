#include "../include.h"
namespace Harmony_Lightcone{
    function<void(CharUnit *ptr)> ForeverVictual(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,476,331);
            ptr->lightCone.name = "The Forever Victual";
    
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::ATK_P][AType::NONE] += 12 + 4 * superimpose;
            }));

            beforeAllyActionList.push_back(TriggerByAllyActionFunc(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if(act->isSameAction(ptr,AType::SKILL))
                buffStackSingle(ptr,{{Stats::ATK_P,AType::NONE,6.0 + 2 * superimpose}},1,3,"The Forever Victual");
            }));
        };
    }
}