#include "../include.h"
namespace Erudition_Lightcone{
    function<void(Ally *ptr)> The_Herta_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,635,463);
            ptr->Light_cone.Name = "The_Herta_LC";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::None] += 10 + 2 * superimpose;
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (ptr->getSubUnit()->isBuffEnd("The_Herta_LC_buff")) {
                    ptr->getSubUnit()->buffSingle({
                        {Stats::DMG,AType::SKILL,-(50.0 + 10 * superimpose)},
                        {Stats::DMG,AType::Ult,-(50.0 + 10 * superimpose)},
                });
                }
            }));

            AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if (act->isSameAction(ptr->getSubUnit(),AType::Ult)) {
                    ptr->getSubUnit()->buffSingle({
                        {Stats::DMG,AType::SKILL,(50.0 + 10 * superimpose)},
                        {Stats::DMG,AType::Ult,(50.0 + 10 * superimpose)},
                        },"The_Herta_LC_buff",3);
                    if (ptr->Ult_cost >= 140) {
                        Skill_point(ptr->Sub_Unit_ptr[0].get(), 1);
                    }
                }
            }));
            
        };
    }
}