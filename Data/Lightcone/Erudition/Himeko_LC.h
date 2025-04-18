
#ifndef Himeko_LC_H
#define Himeko_LC_H

#include "../Library.h"
namespace Erudition_Lightcone{
    function<void(Ally *ptr)> Himeko_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1164,582,397);
            ptr->Light_cone.Name = "Himeko_LC";
    
            When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += (7.5 + superimpose * 1.5) * Total_enemy;
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (Buff_end(ptr->Sub_Unit_ptr[0].get(), "Himeko_LC_buff")) {
                    ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["None"] -= 25+superimpose*5;
                    ptr->Sub_Unit_ptr[0]->Buff_check["Himeko_LC_buff"] = 0;
                }
            }));
    
            Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](Enemy *target, SubUnit *Breaker) {
                if (!Buff_check(ptr->Sub_Unit_ptr[0].get(), "Himeko_LC_buff")) {
                    ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["None"] += 25+superimpose*5;
                    ptr->Sub_Unit_ptr[0]->Buff_check["Himeko_LC_buff"] = 1;
                }
                Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "Himeko_LC_buff", 1);
            }));
        };
    }
}
#endif