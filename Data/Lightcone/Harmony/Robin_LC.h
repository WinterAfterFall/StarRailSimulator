
#ifndef Robin_LC_H
#define Robin_LC_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Harmony_Lightcone{
    function<void(Ally *ptr)> Robin_LC(int superimpose){
        return [=](Ally *ptr) {
            SetBaseStats(ptr->Sub_Unit_ptr[0].get(),953,635,463);
            ptr->Light_cone.Name = "Robin_LC";
            
            When_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](ActionData &data_) {
                if (ptr->Sub_Unit_ptr[0]->Stack["Cantillation"] < 5) {
                    ptr->Sub_Unit_ptr[0]->Stack["Cantillation"]++;
                    ptr->Energy_recharge += 2.5 + 0.5 * superimpose;
                }
            }));
    
            After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](ActionData &data_) {
                if (data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_.Action_type.second == "Ultimate") {
                    ptr->Energy_recharge -= ptr->Sub_Unit_ptr[0]->Stack["Cantillation"] * (2.5 + 0.5 * superimpose);
                    ptr->Sub_Unit_ptr[0]->Stack["Cantillation"] = 0;
                    if (!Buff_check(ptr->Sub_Unit_ptr[0].get(), "Cadenza")) {
                        Buff_All_Ally("Dmg%", "None", (20 + 4 * superimpose));
                        Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "Atk%", "None", (36 + 12 * superimpose));
                        ptr->Sub_Unit_ptr[0]->Buff_check["Cadenza"] = 1;
                    }
                    Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "Cadenza", 1);
                }
            }));
    
            Buff_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](ActionData &data_) {
                if (data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_.Action_type.second == "Ultimate") {
                    ptr->Energy_recharge -= ptr->Sub_Unit_ptr[0]->Stack["Cantillation"] * (2.5 + 0.5 * superimpose);
                    ptr->Sub_Unit_ptr[0]->Stack["Cantillation"] = 0;
                    if (!Buff_check(ptr->Sub_Unit_ptr[0].get(), "Cadenza")) {
                        Buff_All_Ally("Dmg%", "None", (20 + 4 * superimpose));
                        Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "Atk%", "None", (36 + 12 * superimpose));
                        ptr->Sub_Unit_ptr[0]->Buff_check["Cadenza"] = 1;
                    }
                    Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "Cadenza", 1);
                }
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (Buff_end(ptr->Sub_Unit_ptr[0].get(), "Cadenza")) {
                    Buff_All_Ally("Dmg%", "None", -(20 + 4 * superimpose));
                    Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "Atk%", "None", -(36 + 12 * superimpose));
                    ptr->Sub_Unit_ptr[0]->Buff_check["Cadenza"] = 0;
                }
            }));
        };
    }   
}
#endif