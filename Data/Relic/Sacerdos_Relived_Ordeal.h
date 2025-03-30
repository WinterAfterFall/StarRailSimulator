
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

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Atv_stats->Speed_percent += 6;
        }));

        Buff_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](ActionData &data_) {
            if (data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_.traceType == "Single_target") {
                for (auto e : data_.Target_Buff) {
                    Stack_Buff_single_target(e, "Crit_dam", "None", 18, 1, 2, "Sacerdos");
                    Extend_Buff_single_target(e, "Sacerdos", 2);
                }
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (turn->Unit_num != ptr->Sub_Unit_ptr[0]->allyTargetNum) return;
            Sub_Unit *tempstats = dynamic_cast<Sub_Unit *>(turn->ptr_to_unit);
            if (!tempstats) return;
            if (Buff_end(tempstats, "Sacerdos")) {
                Buff_single_target(tempstats, "Crit_dam", "None", -(tempstats->Stack["Sacerdos"] * 18));
                tempstats->Stack["Sacerdos"] = 0;
            }
        }));
    }
}
#endif