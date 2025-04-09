
#ifndef FireFly_LC_H
#define FireFly_LC_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Destruction_Lightcone{
    function<void(Ally *ptr)> FireFly_LC(int superimpose){
        return [=](Ally *ptr) {
            SetBaseStats(ptr->Sub_Unit_ptr[0].get(),1164,476,529);
            ptr->Light_cone.Name = "FireFly_LC";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"] += 50 + 10 * superimpose;
            }));
    
            After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](ActionData &data_) {
                if (data_.Attacker->Atv_stats->Unit_num != ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num && data_.Attacker->Atv_stats->Side != "Ally") return;
                for(Enemy* &e :data_.Target_Attack){
                    if (e->debuffApply(ptr->Sub_Unit_ptr[0].get(),"FireFly_LC_debuff")) {
                        Speed_Buff(e->Atv_stats.get(), -20, 0);
                        e->Stats_type["Vul"]["Break_dmg"] += 20 + 4 * superimpose;
                    }
                    Extend_Debuff_single_target(e, "FireFly_LC_debuff", 2);
                } 
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (turn != nullptr && turn->Side == "Enemy") {
                    if (Debuff_end(Enemy_unit[turn->Unit_num].get(), "FireFly_LC_debuff")) {
                        Enemy_unit[turn->Unit_num]->Debuff["FireFly_LC_debuff"] = 0;
                        Speed_Buff(Enemy_unit[turn->Unit_num]->Atv_stats.get(), 20, 0);
                        Enemy_unit[turn->Unit_num]->Stats_type["Vul"]["Break_dmg"] -= 20 + 4 * superimpose;
                        Enemy_unit[turn->Unit_num]->Total_debuff--;
                    }
                }
            }));
        };
    }

}
#endif