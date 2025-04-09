
#ifndef Resolution_H
#define Resolution_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Nihility_Lightcone{
    function<void(Ally *ptr)> Resolution(int superimpose){
        return [=](Ally *ptr) {
            SetBaseStats(ptr->Sub_Unit_ptr[0].get(),953,476,331);
            ptr->Light_cone.Name = "Resolution";

            Tune_stats_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                Cal_effect_hit_rate(ptr, 50 + superimpose);
            }));

            After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](ActionData &data_) {
                if (data_.Attacker->Atv_stats->Unit_Name != ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name) return;
                for (auto e : data_.Target_Attack) {
                    if (!e->debuffApply(ptr->Sub_Unit_ptr[0].get(),"Ensnared")) continue;
                    e->Stats_type["Def"]["None"] += 11 + superimpose;
                    e->Debuff_time_count["Ensnared"] = 1 + e->Atv_stats->turn_cnt;
                }
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (turn->Side == "Enemy") {
                    if (Enemy_unit[turn->Unit_num]->Debuff_time_count["Ensnared"] == Enemy_unit[turn->Unit_num]->Atv_stats->turn_cnt) {
                        Enemy_unit[turn->Unit_num]->Stats_type["Def"]["None"] -= 11 + superimpose;
                        Enemy_unit[turn->Unit_num]->Debuff["Ensnared"] = 0;
                        --Enemy_unit[turn->Unit_num]->Total_debuff;
                    }
                }
            }));
        };
    }
}
#endif