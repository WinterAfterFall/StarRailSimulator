
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
    
                int sz2 = data_.Damage_spilt.Adjacent.size();
                int sz3 = data_.Damage_spilt.Other.size();
    
                for (int i = 1; i <= Total_enemy; i++) {
                    if (Enemy_unit[i]->Target_type == "Main") {
                        if (Enemy_unit[i]->Debuff["FireFly_LC_debuff"] == 0) {
                            Enemy_unit[i]->Debuff["FireFly_LC_debuff"] = 1;
                            Speed_Buff(Enemy_unit[i]->Atv_stats.get(), -20, 0);
                            Enemy_unit[i]->Stats_type["Vul"]["Break_dmg"] += 20 + 4 * superimpose;
                            Enemy_unit[i]->Total_debuff++;
                        }
                        Extend_Debuff_single_target(Enemy_unit[i].get(), "FireFly_LC_debuff", 2);
                        Apply_debuff(ptr->Sub_Unit_ptr[0].get(), Enemy_unit[i].get());
                    }
    
                    if (sz2 > 0 && Enemy_unit[i]->Target_type == "Adjacent") {
                        if (Enemy_unit[i]->Debuff["FireFly_LC_debuff"] == 0) {
                            Enemy_unit[i]->Debuff["FireFly_LC_debuff"] = 1;
                            Speed_Buff(Enemy_unit[i]->Atv_stats.get(), -20, 0);
                            Enemy_unit[i]->Stats_type["Vul"]["Break_dmg"] += 20 + 4 * superimpose;
                            Enemy_unit[i]->Total_debuff++;
                        }
                        Extend_Debuff_single_target(Enemy_unit[i].get(), "FireFly_LC_debuff", 2);
                        Apply_debuff(ptr->Sub_Unit_ptr[0].get(), Enemy_unit[i].get());
                    }
    
                    if (sz3 > 0 && Enemy_unit[i]->Target_type == "Other") {
                        if (Enemy_unit[i]->Debuff["FireFly_LC_debuff"] == 0) {
                            Enemy_unit[i]->Debuff["FireFly_LC_debuff"] = 1;
                            Speed_Buff(Enemy_unit[i]->Atv_stats.get(), -20, 0);
                            Enemy_unit[i]->Stats_type["Vul"]["Break_dmg"] += 20 + 4 * superimpose;
                            Enemy_unit[i]->Total_debuff++;
                        }
                        Extend_Debuff_single_target(Enemy_unit[i].get(), "FireFly_LC_debuff", 2);
                        Apply_debuff(ptr->Sub_Unit_ptr[0].get(), Enemy_unit[i].get());
                    }
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