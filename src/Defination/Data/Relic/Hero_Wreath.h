#include "../include.h"
namespace Relic{
    void Hero_Wreath(CharUnit *ptr);
    void Hero_Wreath(CharUnit *ptr){
        ptr->Relic.Name = "Hero_Wreath";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::ATK_P][AType::None] += 12;
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->memospriteList.size() > 0 && ptr->Buff_check["Hero_Wreath"] == 0) {
                for (auto &each : ptr->memospriteList) {
                    if (!each->isDeath()) {
                        ptr->Buff_check["Hero_Wreath"] = 1;
                        buffSingle(ptr,{{Stats::SPD_P,AType::None,6}});
                        break;
                    }
                }
            }
        }));

        BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (act->Attacker->Atv_stats->side == Side::Ally && ptr->memospriteList.size() > 0) {
                buffSingleChar(ptr,{{Stats::CD, AType::None, 30}}, "Hero_Wreath_buff",2);
            }
        }));
        
        
        
    }
}