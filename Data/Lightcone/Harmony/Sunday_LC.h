
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
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (turn->Unit_num != ptr->Sub_Unit_ptr[0]->currentAllyTargetNum) return;
                SubUnit *tempstats = dynamic_cast<SubUnit*>(turn->ptr_to_unit);
                if (!tempstats) return;
                if (Buff_end(tempstats, "Hymn")) {
                    Buff_single_target(tempstats, "Dmg%", "None", -(tempstats->Stack["Hymn"] * (12.75 + (2.25)*superimpose) ));
                    tempstats->Stack["Hymn"] = 0;
                }
            }));
    
            AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,superimpose](SubUnit* target) {
                target->setBuffCountdown("Hymn",0);
                Buff_single_target(target, "Dmg%", "None", -(target->Stack["Hymn"] * (12.75 + (2.25)*superimpose)));
                target->Stack["Hymn"] = 0;
            }));
    
            Buff_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](ActionData &data_) {
                if (data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_.traceType == "Single_target") {
                    Increase_energy(ptr, 5.5 + 0.5 * superimpose);
                    for (auto e : data_.Target_Buff) {
                        Stack_Buff_single_target(e, "Dmg%", "None", (12.75 + (2.25)*superimpose), 1, 3, "Hymn");
                        Extend_Buff_single_target(e, "Hymn", 3);
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