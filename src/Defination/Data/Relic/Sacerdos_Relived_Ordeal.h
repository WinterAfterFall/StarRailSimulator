#include "../include.h"
namespace Relic{
    void Sacerdos_Relived_Ordeal(Ally *ptr);
    void Sacerdos_Relived_Ordeal(Ally *ptr){
        ptr->Relic.Name = "Sacerdos_Relived_Ordeal";
        string Sacerdos = ptr->getSubUnit()->getUnitName() + " Sacerdos";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Sacerdos]() {
            ptr->Sub_Unit_ptr[0]->Atv_stats->speedPercent += 6;
        }));

        Buff_List.push_back(TriggerByAllyBuffAction_Func(PRIORITY_IMMEDIATELY, [ptr,Sacerdos](shared_ptr<AllyBuffAction> &act) {
            if (act->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && act->traceType == "Single_target") {
                for (auto each : act->buffTargetList) {
                    each->buffStackSingle({{ST_CD, AT_NONE, 18}}, 1, 2, Sacerdos,2);
                }
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Sacerdos]() {
            if (turn->num != ptr->Sub_Unit_ptr[0]->currentAllyTargetNum) return;
            SubUnit *tempstats = dynamic_cast<SubUnit *>(turn->ptrToChar);
            if (!tempstats) return;
            if (tempstats->isBuffEnd(Sacerdos)) {
                tempstats->buffResetStack({{ST_CD, AT_NONE, 18}},Sacerdos);
            }
        }));
    }
}