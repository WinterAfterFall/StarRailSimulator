
#ifndef Fugue_LC_H
#define Fugue_LC_H

#include "../Library.h"
namespace Nihility_Lightcone{
    void Fugue_LC(Ally *ptr);
    void Fugue_LC(Ally *ptr){

        SetBaseStats(ptr->Sub_Unit_ptr[0].get(),953,582,529);
        ptr->Light_cone.Name = "Fugue_LC";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"] += 60;
        }));

        Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr](Enemy *target, Sub_Unit *Breaker) {
            if (target->Debuff["Fugue_LC_Debuff"] == 0) {
                target->Debuff["Fugue_LC_Debuff"] = 1;
                target->Stats_type["Vul"]["Break_dmg"] += 18;
                target->Total_debuff++;
            }
            Apply_debuff(ptr->Sub_Unit_ptr[0].get(), target);
            Extend_Debuff_single_target(target, "Fugue_LC_Debuff", 2);
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (turn->Side != "Enemy") return;
            if (Debuff_end(Enemy_unit[turn->Unit_num].get(), "Fugue_LC_Debuff")) {
                Enemy_unit[turn->Unit_num]->Debuff["Fugue_LC_Debuff"] = 0;
                Enemy_unit[turn->Unit_num]->Stats_type["Vul"]["Break_dmg"] -= 18;
                Enemy_unit[turn->Unit_num]->Total_debuff--;
            }
        }));

        
        
        
    }
}
#endif