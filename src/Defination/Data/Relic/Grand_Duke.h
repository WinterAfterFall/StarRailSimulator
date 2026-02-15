#include "../include.h"
namespace Relic{
    void Grand_Duke(CharUnit *ptr);
    void Grand_Duke(CharUnit *ptr){
        ptr->Relic.Name = "Grand_Duke";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::DMG][AType::Fua] += 20;
        }));

        BeforeAttackPerHit_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (act->Attacker->Atv_stats->Name != ptr->Atv_stats->Name) return;

            bool check = false;
            for (auto e : act->actionTypeList) {
                if (e == AType::Fua) {
                    check = true;
                    break;
                }
            }
            int hitCnt = 0;
            if (check) {
                hitCnt += act->Attacker->hitCount;
                if (hitCnt > 8) {
                    hitCnt = 8;
                }
                act->Attacker->Stats_type[Stats::ATK_P][AType::None] -= act->Attacker->Stack["Grand_Duke"] * 6;
                act->Attacker->Stack["Grand_Duke"] = hitCnt;
                act->Attacker->Stats_type[Stats::ATK_P][AType::None] += act->Attacker->Stack["Grand_Duke"] * 6;
                extendBuffTime(act->Attacker,"Grand_Duke", 3);
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (turn->Name != ptr->Atv_stats->Name) return;

            if (isBuffEnd(ptr,"Grand_Duke")) {
                ptr->Stats_type[Stats::ATK_P][AType::None] -= ptr->Stack["Grand_Duke"] * 6;
                ptr->Stack["Grand_Duke"] = 0;
            }
        }));
        
    }
}