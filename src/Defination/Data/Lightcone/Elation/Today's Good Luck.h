#include "../include.h"
namespace Elation_Lightcone{
    function<void(CharUnit *ptr)> TodayGoodLuck(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,529,397);
            ptr->Light_cone.Name = "Today's Good Luck";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::CR][AType::None] += 10.0 + superimpose *2;
            }));

            AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &act) {
                if(act->isSameAction(ptr,AType::ElationSkill)){
                    buffStackSingle(ptr,{{Stats::Elation,AType::None,10.0 + superimpose *2}},1,2,"TDGL Stack");
                }
            }));

        };
    }
}
