
#ifndef Resolution_H
#define Resolution_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Nihility_Lightcone{
    function<void(Ally *ptr)> Resolution(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "Resolution";
            string ensnared = ptr->getSubUnit()->getUnitName() + " Ensnared";
            ptr->newEhrRequire(50 + superimpose);

            After_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,ensnared](shared_ptr<AllyAttackAction> &data_) {
                if (data_->Attacker->Atv_stats->Unit_Name != ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name) return;
                for (auto e : data_->targetList) {
                    if (!e->debuffApply(ptr->Sub_Unit_ptr[0].get(),ensnared)) continue;
                    e->Stats_type[ST_DEF_SHRED][AT_NONE] += 11 + superimpose;
                    e->Debuff_time_count[ensnared] = 1 + e->Atv_stats->turn_cnt;
                }
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,ensnared]() {
                if (turn->Side == "Enemy") {
                    if (Enemy_unit[turn->Unit_num]->Debuff_time_count[ensnared] == Enemy_unit[turn->Unit_num]->Atv_stats->turn_cnt) {
                        Enemy_unit[turn->Unit_num]->Stats_type[ST_DEF_SHRED][AT_NONE] -= 11 + superimpose;
                        Enemy_unit[turn->Unit_num]->Debuff[ensnared] = 0;
                        --Enemy_unit[turn->Unit_num]->Total_debuff;
                    }
                }
            }));
        };
    }
}
#endif