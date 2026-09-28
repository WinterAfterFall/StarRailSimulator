#include "../include.h"
namespace Elation_Lightcone{
    function<void(CharUnit *ptr)> TodayGoodLuck(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,529,397);
            ptr->lightCone.name = "Today's Good Luck";
    
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::CR][AType::NONE] += 10.0 + superimpose *2;
            }));

            // fired once per character that uses an Elation Skill (not only the first one in the Aha queue)
            whenUseElationSkillList.push_back(TriggerByAllyFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](CharUnit *ally) {
                if(ally!=ptr)return;
                buffStackSingle(ptr,{{Stats::ELATION,AType::NONE,10.0 + superimpose *2}},1,2,"TDGL Stack");
            }));

        };
    }
}
