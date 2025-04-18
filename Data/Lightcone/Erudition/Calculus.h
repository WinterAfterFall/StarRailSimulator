
#ifndef Calculus_H
#define Calculus_H

#include "../Library.h"
namespace Erudition_Lightcone{
    function<void(Ally *ptr)> Calculus(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1058,529,397);
            ptr->Light_cone.Name = "Calculus";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 7 + superimpose;
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (Buff_end(ptr->Sub_Unit_ptr[0].get(), "Calculus_Speed_buff")) {
                    Speed_Buff(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), -(6 + 2 * superimpose), 0);
                    ptr->Sub_Unit_ptr[0]->Buff_check["Calculus_Speed_buff"] = 0;
                }
            }));
    
            Before_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_) {
                ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] -= ptr->Sub_Unit_ptr[0]->Buff_note["Calculus_Atk_buff"];
                ptr->Sub_Unit_ptr[0]->Buff_note["Calculus_Atk_buff"] = data_->Target_Attack.size() * 3 + superimpose;
    
                ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += ptr->Sub_Unit_ptr[0]->Buff_note["Calculus_Atk_buff"];
                if (ptr->Sub_Unit_ptr[0]->Buff_note["Calculus_Atk_buff"] >= 24) {
                    if (!Buff_check(ptr->Sub_Unit_ptr[0].get(), "Calculus_Speed_buff")) {
                        Speed_Buff(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), (6 + 2 * superimpose), 0);
                        ptr->Sub_Unit_ptr[0]->Buff_check["Calculus_Speed_buff"] = 1;
                    }
                    Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "Calculus_Speed_buff", 1);
                }
            }));
        };
    }
    void Calculus(Ally *ptr){

        
        
    }
}
#endif