#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> Resolution(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "Resolution";
            string ensnared = ptr->getUnitName() + " Ensnared";
            ptr->newApplyBaseChanceRequire(50 + superimpose*10);

            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,ensnared](shared_ptr<AllyAttackAction> &act) {
                if (act->Attacker->Atv_stats->StatsOwnerName != ptr->Atv_stats->StatsOwnerName) return;
                for (auto e : act->targetList) {
                    if (!e->debuffApply(ptr,ensnared)) continue;
                    e->Stats_type[Stats::DEF_SHRED][AType::None] += 11 + superimpose;
                    e->Debuff_time_count[ensnared] = 1 + e->Atv_stats->turnCnt;
                }
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,ensnared]() {
                if (turn->side == Side::Enemy) {
                    if (enemyUnit[turn->num]->Debuff_time_count[ensnared] == enemyUnit[turn->num]->Atv_stats->turnCnt) {
                        enemyUnit[turn->num]->Stats_type[Stats::DEF_SHRED][AType::None] -= 11 + superimpose;
                        enemyUnit[turn->num]->Debuff[ensnared] = 0;
                        --enemyUnit[turn->num]->Total_debuff;
                    }
                }
            }));
        };
    }
}