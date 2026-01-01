#include "../include.h"
namespace Harmony_Lightcone{
    function<void(CharUnit *ptr)> Sunday_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1164,476,529);
            ptr->Light_cone.Name = "Sunday_LC";
            string hymn = ptr->getUnitName() +  " Hymn";
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,hymn]() {
                if (turn->num != ptr->Sub_Unit_ptr[0]->currentAllyTargetNum) return;
                AllyUnit *tempstats = dynamic_cast<AllyUnit*>(turn->charptr);
                if (!tempstats) return;
                if (tempstats->isBuffEnd(hymn)) {
                    tempstats->buffResetStack({{Stats::DMG,AType::None,(12.75 + (2.25)*superimpose)}},hymn);
                }
            }));
    
            AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,superimpose,hymn](AllyUnit* target) {
                target->buffResetStack({{Stats::DMG,AType::None,(12.75 + (2.25)*superimpose)}},hymn);
            }));
    
            Buff_List.push_back(TriggerByAllyBuffAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,hymn](shared_ptr<AllyBuffAction> &act) {
                if (act->Attacker->Atv_stats->StatsOwnerName == ptr->Sub_Unit_ptr[0]->Atv_stats->StatsOwnerName && act->traceType == TraceType::Single) {
                    Increase_energy(ptr, 5.5 + 0.5 * superimpose);
                    for (auto each : act->buffTargetList) {
                        each->buffStackSingle({{Stats::DMG,AType::None,(12.75 + (2.25)*superimpose)}},1,3,hymn,3);
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