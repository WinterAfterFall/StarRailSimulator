#include "../include.h"
namespace Relic{
    // Dreamlit Actor — kit: docs/kit-reference/Relic.md (nanoka 4.5.54, set 133)
    // 2pc SPD +6% · 4pc: Skill / Ultimate on one other ally -> that ally Elation +16% for 3 turns;
    //   wearer holding >= 10 Certified Banger -> also all allies CRIT DMG +12% for 3 turns
    void DreamlitActor(CharUnit *ptr){
        ptr->Relic.name = "Dreamlit Actor";
        string elationName = ptr->getName() + " Dreamlit Elation";
        string critName = ptr->getName() + " Dreamlit CD";

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->atvStats->speedPercent += 6;
        }));

        buffList.push_back(TriggerByAllyBuffActionFunc(PRIORITY_IMMEDIATELY, [ptr,elationName,critName](shared_ptr<AllyBuffAction> &act) {
            if(!act->isSameAction(ptr,AType::SKILL)&&!act->isSameAction(ptr,AType::ULT))return;
            if(act->buffTargetList.size()!=1)return;
            AllyUnit *target = act->buffTargetList[0];
            if(!target||target==ptr)return;
            buffSingle(target,{{Stats::ELATION,AType::NONE,16}},elationName,3);
            if(ptr->statsType[Stats::CERTIFIED_BANGER][AType::NONE]>=10){
                buffAllAlly({{Stats::CD,AType::NONE,12}},critName,3);
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [elationName,critName](CharUnit *ptr) {
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(!ally)return;
            if(isBuffEnd(ally,elationName))buffSingle(ally,{{Stats::ELATION,AType::NONE,-16}});
            if(isBuffEnd(ally,critName))buffSingle(ally,{{Stats::CD,AType::NONE,-12}});
        }));
    }
}
