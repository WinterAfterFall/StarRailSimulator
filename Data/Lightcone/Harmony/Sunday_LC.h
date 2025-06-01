
#ifndef Sunday_LC_H
#define Sunday_LC_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Harmony_Lightcone{
    function<void(Ally *ptr)> Sunday_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1164,476,529);
            ptr->Light_cone.Name = "Sunday_LC";
            string hymn = ptr->getSubUnit()->getUnitName() +  " Hymn";
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,hymn]() {
                if (turn->Unit_num != ptr->Sub_Unit_ptr[0]->currentAllyTargetNum) return;
                SubUnit *tempstats = dynamic_cast<SubUnit*>(turn->ptrToChar);
                if (!tempstats) return;
                if (tempstats->isBuffEnd(hymn)) {
                    tempstats->buffResetStack({{ST_DMG,AT_NONE,(12.75 + (2.25)*superimpose)}},hymn);
                }
            }));
    
            AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,superimpose,hymn](SubUnit* target) {
                target->buffResetStack({{ST_DMG,AT_NONE,(12.75 + (2.25)*superimpose)}},hymn);
            }));
    
            Buff_List.push_back(TriggerByAllyBuffAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,hymn](shared_ptr<AllyBuffAction> &act) {
                if (act->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && act->traceType == "Single_target") {
                    Increase_energy(ptr, 5.5 + 0.5 * superimpose);
                    for (auto each : act->buffTargetList) {
                        each->buffStackSingle({{ST_DMG,AT_NONE,(12.75 + (2.25)*superimpose)}},1,3,hymn,3);
                    }
                    ++ptr->Sub_Unit_ptr[0]->Stack["Hymn_cnt"];
                    if (ptr->Sub_Unit_ptr[0]->Stack["Hymn_cnt"] == 2) {
                        Skill_point(ptr->Sub_Unit_ptr[0].get(), 1);
                        ptr->Sub_Unit_ptr[0]->Stack["Hymn_cnt"] = 0;
                    }
                }
            }));
        };
    }
}
#endif