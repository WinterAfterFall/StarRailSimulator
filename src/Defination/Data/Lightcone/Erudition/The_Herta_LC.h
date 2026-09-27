#include "../include.h"
namespace Erudition_Lightcone{
    function<void(CharUnit *ptr)> The_Herta_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,635,463);
            ptr->lightCone.name = "The_Herta_LC";
    
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::CR][AType::NONE] += 10 + 2 * superimpose;
            }));
    
            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                if (isBuffEnd(ptr,"The_Herta_LC_buff")) {
                    buffSingle(ptr,{
                        {Stats::DMG,AType::SKILL,-(50.0 + 10 * superimpose)},
                        {Stats::DMG,AType::ULT,-(50.0 + 10 * superimpose)},
                });
                }
            }));

            beforeAllyActionList.push_back(TriggerByAllyActionFunc(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if (act->isSameAction(ptr,AType::ULT)) {
                    buffSingle(ptr,{
                        {Stats::DMG,AType::SKILL,(50.0 + 10 * superimpose)},
                        {Stats::DMG,AType::ULT,(50.0 + 10 * superimpose)},
                        },"The_Herta_LC_buff",3);
                    if (ptr->ultCost >= 140) {
                        genSkillPoint(ptr, 1);
                    }
                }
            }));
            
        };
    }
}