
#ifndef A_Grounded_Ascent_H
#define A_Grounded_Ascent_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Harmony_Lightcone{
    void A_Grounded_Ascent(Ally *ptr);
    void A_Grounded_Ascent(Ally *ptr){
        
        SetBaseStats(ptr->Sub_Unit_ptr[0].get(),1164,476,529);
        ptr->Light_cone.Name = "A_Grounded_Ascent";
        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (turn->Unit_num != ptr->Sub_Unit_ptr[0]->currentAllyTargetNum) return;
            Sub_Unit *tempstats = dynamic_cast<Sub_Unit*>(turn->ptr_to_unit);
            if (!tempstats) return;
            if (Buff_end(tempstats, "Hymn")) {
                Buff_single_target(tempstats, "Dmg%", "None", -(tempstats->Stack["Hymn"] * 15));
                tempstats->Stack["Hymn"] = 0;
            }
        }));

        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr](Sub_Unit* target) {
            target->setBuffCountdown("Hymn",0);
            Buff_single_target(target, "Dmg%", "None", -(target->Stack["Hymn"] * 15));
            target->Stack["Hymn"] = 0;
        }));

        Buff_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](ActionData &data_) {
            if (data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_.traceType == "Single_target") {
                Increase_energy(ptr, 6);
                for (auto e : data_.Target_Buff) {
                    Stack_Buff_single_target(e, "Dmg%", "None", 15, 1, 3, "Hymn");
                    Extend_Buff_single_target(e, "Hymn", 3);
                }
                ++ptr->Sub_Unit_ptr[0]->Stack["Hymn_cnt"];
                if (ptr->Sub_Unit_ptr[0]->Stack["Hymn_cnt"] == 2) {
                    Skill_point(ptr->Sub_Unit_ptr[0].get(), 1);
                    ptr->Sub_Unit_ptr[0]->Stack["Hymn_cnt"] = 0;
                }
            }
        }));

        
    }
}
#endif