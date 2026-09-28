#include "../include.h"
namespace Elation_Lightcone{
    // Tomorrow, Together (4★) — kit: docs/kit-reference/Lightcone/Elation.md (nanoka 4.5.54)
    function<void(CharUnit *ptr)> TomorrowTogether(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,476,331);
            ptr->lightCone.name = "Tomorrow, Together";
            string buffName = ptr->getName() + " Tomorrow Together";

            // CRIT DMG 12/15/18/21/24%
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::CD][AType::NONE] += 9 + 3 * superimpose;
            }));

            // after the wearer uses Ultimate -> all allies Elation 8/9/10/11/12% for 1 turn
            afterAllyActionList.push_back(TriggerByAllyActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose,buffName](shared_ptr<AllyActionData> &act) {
                if(!act->isSameAction(ptr,AType::ULT))return;
                buffAllAlly({{Stats::ELATION,AType::NONE,7.0 + superimpose}},buffName,1);
            }));

            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose,buffName](CharUnit *ptr) {
                AllyUnit *ally = turn->canCastToAllyUnit();
                if(!ally)return;
                if(isBuffEnd(ally,buffName))buffSingle(ally,{{Stats::ELATION,AType::NONE,-(7.0 + superimpose)}});
            }));
        };
    }
}
