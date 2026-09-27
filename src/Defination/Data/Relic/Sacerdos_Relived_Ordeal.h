#include "../include.h"
namespace Relic{
    void Sacerdos_Relived_Ordeal(CharUnit *ptr);
    void Sacerdos_Relived_Ordeal(CharUnit *ptr){
        ptr->Relic.name = "Sacerdos_Relived_Ordeal";
        string sacerdos = ptr->getName() + " Sacerdos";

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [sacerdos](CharUnit *ptr) {
            ptr->atvStats->speedPercent += 6;
        }));

        buffList.push_back(TriggerByAllyBuffActionFunc(PRIORITY_IMMEDIATELY, [ptr,sacerdos](shared_ptr<AllyBuffAction> &act) {
            if (act->attacker->atvStats->name == ptr->atvStats->name && act->traceType == TraceType::SINGLE
                && (act->isSameAction(AType::SKILL) || act->isSameAction(AType::ULT))) {
                for (auto each : act->buffTargetList) {
                    buffStackSingle(each,{{Stats::CD, AType::NONE, 18}}, 1, 2, sacerdos,2);
                }
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [sacerdos](CharUnit *ptr) {
            AllyUnit *tempstats = dynamic_cast<AllyUnit *>(turn->charptr);
            if (!tempstats) return;
            if (isBuffEnd(tempstats,sacerdos)) {
                buffResetStack(tempstats,{{Stats::CD, AType::NONE, 18}},sacerdos);
            }
        }));
    }
}