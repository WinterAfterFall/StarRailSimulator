
#ifndef Calculus_H
#define Calculus_H

#include "../Library.h"
namespace Erudition_Lightcone{
    void Calculus(Ally *ptr);
    void Calculus(Ally *ptr){
        SetBaseStats(ptr->Sub_Unit_ptr[0].get(),1058,529,397);
        ptr->Light_cone.Name = "Calculus";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 12;
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (Buff_end(ptr->Sub_Unit_ptr[0].get(), "Calculus_Speed_buff")) {
                Speed_Buff(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), -16, 0);
                ptr->Sub_Unit_ptr[0]->Buff_check["Calculus_Speed_buff"] = 0;
            }
        }));

        Before_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](ActionData &data_) {
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] -= ptr->Sub_Unit_ptr[0]->Buff_note["Calculus_Atk_buff"];
            ptr->Sub_Unit_ptr[0]->Buff_note["Calculus_Atk_buff"] = data_.Target_Attack.size() * 8;

            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += ptr->Sub_Unit_ptr[0]->Buff_note["Calculus_Atk_buff"];
            if (ptr->Sub_Unit_ptr[0]->Buff_note["Calculus_Atk_buff"] >= 24) {
                if (!Buff_check(ptr->Sub_Unit_ptr[0].get(), "Calculus_Speed_buff")) {
                    Speed_Buff(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 16, 0);
                    ptr->Sub_Unit_ptr[0]->Buff_check["Calculus_Speed_buff"] = 1;
                }
                Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "Calculus_Speed_buff", 1);
            }
        }));
        
        
    }
}
#endif