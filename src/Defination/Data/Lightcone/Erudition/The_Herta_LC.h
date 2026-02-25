#include "../include.h"
namespace Erudition_Lightcone{
    function<void(CharUnit *ptr)> The_Herta_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,635,463);
            ptr->Light_cone.Name = "The_Herta_LC";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::CR][AType::None] += 10 + 2 * superimpose;
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (isBuffEnd(ptr,"The_Herta_LC_buff")) {
                    buffSingle(ptr,{
                        {Stats::DMG,AType::SKILL,-(50.0 + 10 * superimpose)},
                        {Stats::DMG,AType::Ult,-(50.0 + 10 * superimpose)},
                });
                }
            }));

            AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if (act->isSameAction(ptr,AType::Ult)) {
                    buffSingle(ptr,{
                        {Stats::DMG,AType::SKILL,(50.0 + 10 * superimpose)},
                        {Stats::DMG,AType::Ult,(50.0 + 10 * superimpose)},
                        },"The_Herta_LC_buff",3);
                    if (ptr->Ult_cost >= 140) {
                        genSkillPoint(ptr, 1);
                    }
                }
            }));
            
        };
    }
}