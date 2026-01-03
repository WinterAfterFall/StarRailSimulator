#include "../include.h"
namespace Relic{
    void Sacerdos_Relived_Ordeal(CharUnit *ptr);
    void Sacerdos_Relived_Ordeal(CharUnit *ptr){
        ptr->Relic.Name = "Sacerdos_Relived_Ordeal";
        string Sacerdos = ptr->getUnitName() + " Sacerdos";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Sacerdos]() {
            ptr->Atv_stats->speedPercent += 6;
        }));

        Buff_List.push_back(TriggerByAllyBuffAction_Func(PRIORITY_IMMEDIATELY, [ptr,Sacerdos](shared_ptr<AllyBuffAction> &act) {
            if (act->Attacker->Atv_stats->StatsOwnerName == ptr->Atv_stats->StatsOwnerName && act->traceType == TraceType::Single) {
                for (auto each : act->buffTargetList) {
                    buffStackSingle(each,{{Stats::CD, AType::None, 18}}, 1, 2, Sacerdos,2);
                }
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Sacerdos]() {
            if (turn->num != ptr->currentCharNum) return;
            AllyUnit *tempstats = dynamic_cast<AllyUnit *>(turn->charptr);
            if (!tempstats) return;
            if (isBuffEnd(tempstats,Sacerdos)) {
                buffResetStack(tempstats,{{Stats::CD, AType::None, 18}},Sacerdos);
            }
        }));
    }
}