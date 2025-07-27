#include "../include.h"
namespace Relic{
    void Hero_Wreath(Ally *ptr);
    void Hero_Wreath(Ally *ptr){
        ptr->Relic.Name = "Hero_Wreath";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::ATK_P][AType::None] += 12;
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Sub_Unit_ptr.size() > 1 && ptr->Sub_Unit_ptr[0]->Buff_check["Hero_Wreath"] == 0) {
                for (int i = 1; i < ptr->Sub_Unit_ptr.size(); i++) {
                    if (!ptr->Sub_Unit_ptr[i]->isDeath()) {
                        ptr->Sub_Unit_ptr[0]->Buff_check["Hero_Wreath"] = 1;
                        ptr->Sub_Unit_ptr[0]->buffSingle({{Stats::SPD_P,AType::None,6}});
                        break;
                    }
                }
            }
        }));

        BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (act->Attacker->Atv_stats->Side == "Ally" && ptr->Sub_Unit_ptr.size() > 1) {
                ptr->buffAlly({{Stats::CD, AType::None, 30}}, "Hero_Wreath_buff",2);
            }
        }));
        
        
        
    }
}