#include "../include.h"
namespace Erudition_Lightcone{
    function<void(CharUnit *ptr)> Calculus(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1058,529,397);
            ptr->lightCone.name = "Calculus";
    
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::ATK_P][AType::NONE] += 7 + superimpose;
            }));
    
            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                if (isBuffEnd(ptr,"Calculus_Speed_buff")) {
                    buffSingle(ptr,{{Stats::SPD_P,AType::NONE,-(6.0 + 2 * superimpose)}});
                }
                
            }));
    
            afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (!act->isSameName(ptr)) return;
                ptr->statsType[Stats::ATK_P][AType::NONE] -= ptr->buffNote["Calculus_Atk_buff"];
                int stack = min((int)act->targetList.size(), 5);
                ptr->buffNote["Calculus_Atk_buff"] = stack * (3 + superimpose);
    
                ptr->statsType[Stats::ATK_P][AType::NONE] += ptr->buffNote["Calculus_Atk_buff"];
                if (act->targetList.size() >= 3) {
                    buffSingle(ptr,{{Stats::SPD_P,AType::NONE,(6.0 + 2 * superimpose)}},"Calculus_Speed_buff",1);
                }
            }));
        };
    }
}