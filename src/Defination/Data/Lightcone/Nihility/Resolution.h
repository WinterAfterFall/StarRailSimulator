#include "../include.h"
namespace Nihility_Lightcone{
    function<void(Ally *ptr)> Resolution(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "Resolution";
            string ensnared = ptr->getSubUnit()->getUnitName() + " Ensnared";
            ptr->newEhrRequire(50 + superimpose);

            After_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,ensnared](shared_ptr<AllyAttackAction> &act) {
                if (act->Attacker->Atv_stats->Unit_Name != ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name) return;
                for (auto e : act->targetList) {
                    if (!e->debuffApply(ptr->Sub_Unit_ptr[0].get(),ensnared)) continue;
                    e->Stats_type[ST_DEF_SHRED][AT_NONE] += 11 + superimpose;
                    e->Debuff_time_count[ensnared] = 1 + e->Atv_stats->turnCnt;
                }
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,ensnared]() {
                if (turn->Side == "Enemy") {
                    if (Enemy_unit[turn->num]->Debuff_time_count[ensnared] == Enemy_unit[turn->num]->Atv_stats->turnCnt) {
                        Enemy_unit[turn->num]->Stats_type[ST_DEF_SHRED][AT_NONE] -= 11 + superimpose;
                        Enemy_unit[turn->num]->Debuff[ensnared] = 0;
                        --Enemy_unit[turn->num]->Total_debuff;
                    }
                }
            }));
        };
    }
}