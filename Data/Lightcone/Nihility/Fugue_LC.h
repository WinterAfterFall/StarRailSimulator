
#ifndef Fugue_LC_H
#define Fugue_LC_H

#include "../Library.h"
namespace Nihility_Lightcone{
    function<void(Ally *ptr)> Fugue_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,582,529);
            ptr->Light_cone.Name = "Fugue_LC";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"] += 50 + 10 * superimpose;
            }));
    
            Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](Enemy *target, SubUnit *Breaker) {
                if (target->debuffApply(ptr->Sub_Unit_ptr[0].get(),"Fugue_LC_Debuff")) {
                    target->Stats_type["Vul"]["Break_dmg"] += 15 + 3 * superimpose;
                }
                Extend_Debuff_single_target(target, "Fugue_LC_Debuff", 2);
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (turn->Side != "Enemy") return;
                if (Debuff_end(Enemy_unit[turn->Unit_num].get(), "Fugue_LC_Debuff")) {
                    Enemy_unit[turn->Unit_num]->Debuff["Fugue_LC_Debuff"] = 0;
                    Enemy_unit[turn->Unit_num]->Stats_type["Vul"]["Break_dmg"] -= 15 + 3 * superimpose;
                    Enemy_unit[turn->Unit_num]->Total_debuff--;
                }
            }));
        };
    }
}
#endif