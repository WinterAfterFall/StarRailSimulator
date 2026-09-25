#include "../include.h"
namespace Relic{
    void Hero_Wreath(CharUnit *ptr);
    void Hero_Wreath(CharUnit *ptr){
        ptr->Relic.Name = "Hero_Wreath";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::ATK_P][AType::None] += 12;
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->memospriteList.size() > 0 && ptr->buffCheck["Hero_Wreath"] == 0) {
                for (auto &each : ptr->memospriteList) {
                    if (!each->isDeath()) {
                        ptr->buffCheck["Hero_Wreath"] = 1;
                        buffSingle(ptr,{{Stats::SPD_P,AType::None,6}});
                        break;
                    }
                }
            }
        }));

        BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (act->Attacker->Atv_stats->side == Side::Memosprite && act->Attacker->owner->isSameName(ptr)) {
                buffSingleChar(ptr,{{Stats::CD, AType::None, 30}}, "Hero_Wreath_buff",2);
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (isBuffEnd(ptr, "Hero_Wreath_buff")) buffSingle(ptr, {{Stats::CD, AType::None, -30}});
            for (auto &each : ptr->memospriteList) {
                if (isBuffEnd(each.get(), "Hero_Wreath_buff")) buffSingle(each.get(), {{Stats::CD, AType::None, -30}});
            }
        }));
        
        
        
    }
}