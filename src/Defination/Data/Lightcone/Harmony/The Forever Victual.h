#include "../include.h"
namespace Harmony_Lightcone{
    function<void(Ally *ptr)> ForeverVictual(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "The Forever Victual";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 12 + 4 * superimpose;
            }));

            AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if(act->isSameAction(ptr,AType::SKILL))
                ptr->getSubUnit()->buffStackSingle({{Stats::ATK_P,AType::None,6.0 + 2 * superimpose}},1,3,"The Forever Victual");
            }));
        };
    }
}