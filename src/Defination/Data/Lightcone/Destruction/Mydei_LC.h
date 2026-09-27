#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> Mydei_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1376,476,397);
            ptr->lightCone.name = "Mydei_LC";
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::HP_P][AType::NONE] += 15 + 3*superimpose;
                ptr->statsType[Stats::HEALING_IN][AType::NONE] += 15 + 5 * superimpose;
            }));
    
            beforeAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (!act->attacker->isSameName(ptr)) return;
                if (act->isSameAction(AType::SKILL)||act->isSameAction(AType::ULT)) {
                    double hpBefore = ptr->currentHP;
                    decreaseHP(ptr, ptr, 0, (5.5 + 0.5 * superimpose), 0);
                    ptr->buffNote["Mydei_LC_Mark"]++;
                    buffSingle(ptr,{{Stats::DMG, AType::NONE, (25.0 + 5 * superimpose)}});
                    if (hpBefore - ptr->currentHP > 500) {
                        ptr->buffNote["Mydei_LC_Mark"]++;
                        buffSingle(ptr,{{Stats::DMG, AType::NONE, (25.0 + 5 * superimpose)}});
                    }
                }
            }));
    
            afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (!act->attacker->isSameName(ptr)) return;
                buffSingle(ptr,{{Stats::DMG, AType::NONE, -(25 + 5 * superimpose) * ptr->buffNote["Mydei_LC_Mark"]}});
                ptr->buffNote["Mydei_LC_Mark"] = 0;
            }));
        };
    }
}
