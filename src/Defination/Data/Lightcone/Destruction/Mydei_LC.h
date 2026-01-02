#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> Mydei_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1376,476,397);
            ptr->Light_cone.Name = "Mydei_LC";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::HP_P][AType::None] += 15 + 3*superimpose;
                ptr->Stats_type[Stats::HEALING_OUT][AType::None] += 15 + 5 * superimpose;
            }));
    
            BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (!act->Attacker->isSameStatsOwnerName(ptr)) return;
                if (act->isSameAttack(AType::SKILL)||act->isSameAttack(AType::Ult)) {
                    ptr->Buff_note["Mydei_LC_Mark"]++;
                    buffSingle(ptr,{{Stats::DMG, AType::None, (25.0 + 5 * superimpose)}});
                    if (ptr->currentHP >= 50000.0 / (5.5 + 0.5 * superimpose)) {
                        buffSingle(ptr,{{Stats::DMG, AType::None, (25.0 + 5 * superimpose)}});
                        ptr->Buff_note["Mydei_LC_Mark"]++;
                        DecreaseHP(ptr, ptr, 0, (5.5 + 0.5 * superimpose), 0);
                    }
                }
            }));
    
            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (!act->Attacker->isSameStatsOwnerName(ptr)) return;
                buffSingle(ptr,{{Stats::DMG, AType::None, -(25 + 5 * superimpose) * ptr->Buff_note["Mydei_LC_Mark"]}});
                ptr->Buff_note["Mydei_LC_Mark"] = 0;
            }));
        };
    }
}
