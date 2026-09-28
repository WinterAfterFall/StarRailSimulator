#include "../include.h"
namespace Elation_Lightcone{
    // Elation Brimming With Blessings (Herta Shop) — kit: docs/kit-reference/Lightcone/Elation.md (nanoka 4.5.54)
    function<void(CharUnit *ptr)> ElationHertaShop(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,529,463);
            ptr->lightCone.name = "Elation Brimming With Blessings";
            string buffName = ptr->getName() + " Elation Brimming";

            // ATK 20/25/30/35/40%
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::ATK_P][AType::NONE] += 15 + 5 * superimpose;
            }));

            // Skill / Ultimate on one ally character -> that ally Elation 12/15/18/21/24% for 2 turns
            buffList.push_back(TriggerByAllyBuffActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose,buffName](shared_ptr<AllyBuffAction> &act) {
                if(!act->isSameAction(ptr,AType::SKILL)&&!act->isSameAction(ptr,AType::ULT))return;
                if(act->buffTargetList.size()!=1)return;
                CharUnit *target = dynamic_cast<CharUnit*>(act->buffTargetList[0]);
                if(!target)return;
                buffSingle(target,{{Stats::ELATION,AType::NONE,9.0 + 3 * superimpose}},buffName,2);
            }));

            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose,buffName](CharUnit *ptr) {
                AllyUnit *ally = turn->canCastToAllyUnit();
                if(!ally)return;
                if(isBuffEnd(ally,buffName))buffSingle(ally,{{Stats::ELATION,AType::NONE,-(9.0 + 3 * superimpose)}});
            }));
        };
    }
}
