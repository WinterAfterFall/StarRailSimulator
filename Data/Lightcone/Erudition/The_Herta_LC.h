
#ifndef The_Herta_LC_H
#define The_Herta_LC_H

#include "../Library.h"
namespace Erudition_Lightcone{
    function<void(Ally *ptr)> templateLC(int superimpose){
        return [=](Ally *ptr) {
            SetBaseStats(ptr->Sub_Unit_ptr[0].get(),953,635,463);
            ptr->Light_cone.Name = "The_Herta_LC";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"] += 10 + 2 * superimpose;
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (Buff_end(ptr->Sub_Unit_ptr[0].get(), "The_Herta_LC_buff")) {
                    ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Skill"] -= 50 + 10 * superimpose;
                    ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Ultimate"] -= 50 + 10 * superimpose;
                    ptr->Sub_Unit_ptr[0]->Buff_check["The_Herta_LC_buff"] = 0;
                }
            }));
    
            Buff_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](ActionData &data_) {
                if (data_.Action_type.second == "Ultimate" && data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name) {
                    if (!Buff_check(ptr->Sub_Unit_ptr[0].get(), "The_Herta_LC_buff")) {
                        ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Skill"] += 50 + 10 * superimpose;
                        ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Ultimate"] += 50 + 10 * superimpose;
                        ptr->Sub_Unit_ptr[0]->Buff_check["The_Herta_LC_buff"] = 1;
                    }
                    Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "The_Herta_LC_buff", 3);
                    if (ptr->Ult_cost >= 140) {
                        Skill_point(ptr->Sub_Unit_ptr[0].get(), 1);
                    }
                }
            }));
    
            Before_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](ActionData &data_) {
                if (data_.Action_type.second == "Ultimate" && data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name) {
                    if (!Buff_check(ptr->Sub_Unit_ptr[0].get(), "The_Herta_LC_buff")) {
                        ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Skill"] += 50 + 10 * superimpose;
                        ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Ultimate"] += 50 + 10 * superimpose;
                        ptr->Sub_Unit_ptr[0]->Buff_check["The_Herta_LC_buff"] = 1;
                    }
                    Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "The_Herta_LC_buff", 3);
                    if (ptr->Ult_cost >= 140) {
                        Skill_point(ptr->Sub_Unit_ptr[0].get(), 1);
                    }
                }
            }));
        };
    }
    void The_Herta_LC(Ally *ptr){

        
        
    }
}
#endif