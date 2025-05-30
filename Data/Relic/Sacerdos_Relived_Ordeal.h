
#ifndef Sacerdos_H
#define Sacerdos_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Relic{
    void Sacerdos_Relived_Ordeal(Ally *ptr);
    void Sacerdos_Relived_Ordeal(Ally *ptr){
        ptr->Relic.Name = "Sacerdos_Relived_Ordeal";
        string Sacerdos = ptr->getSubUnit()->getUnitName() + " Sacerdos";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Sacerdos]() {
            ptr->Sub_Unit_ptr[0]->Atv_stats->Speed_percent += 6;
        }));

        Buff_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,Sacerdos](shared_ptr<AllyActionData> &data_) {
            if (data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_->traceType == "Single_target") {
                for (auto each : data_->buffTargetList) {
                    each->buffStackSingle({{ST_CD, AT_NONE, 18}}, 1, 2, Sacerdos,2);
                }
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Sacerdos]() {
            if (turn->Unit_num != ptr->Sub_Unit_ptr[0]->currentAllyTargetNum) return;
            SubUnit *tempstats = dynamic_cast<SubUnit *>(turn->ptrToChar);
            if (!tempstats) return;
            if (tempstats->isBuffEnd(Sacerdos)) {
                tempstats->buffResetStack({{ST_CD, AT_NONE, 18}},Sacerdos);
            }
        }));
    }
}
#endif