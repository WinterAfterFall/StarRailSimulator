#include "../include.h"
namespace Elation_Lightcone{
    function<void(CharUnit *ptr)> TodayGoodLuck(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,529,397);
            ptr->lightCone.name = "Today's Good Luck";
    
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::CR][AType::NONE] += 10.0 + superimpose *2;
            }));

            beforeAllyActionList.push_back(TriggerByAllyActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &act) {
                if(act->isSameAction(ptr,AType::ELATION_SKILL)){
                    buffStackSingle(ptr,{{Stats::ELATION,AType::NONE,10.0 + superimpose *2}},1,2,"TDGL Stack");
                }
            }));

        };
    }
}
