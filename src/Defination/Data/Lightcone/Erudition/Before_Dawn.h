#include "../include.h"
namespace Erudition_Lightcone{
    function<void(CharUnit *ptr)> Before_Dawn(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1058,582,463);

            ptr->lightCone.name = "Before_Dawn";
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::CD][AType::NONE] += 30 + 6 * superimpose;
                ptr->statsType[Stats::DMG][AType::SKILL] += 15 + 3 * superimpose;
                ptr->statsType[Stats::DMG][AType::ULT] += 15 + 3 * superimpose;
            }));
    
            beforeAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (act->attacker->atvStats->name == ptr->atvStats->name &&
                    ptr->stack["Somnus_Corpus"] == 1) {
                    for (auto e : act->actionTypeList) {
                        if (e == AType::FUA) {
                            ptr->statsType[Stats::DMG][AType::FUA] += 40 + 8 * superimpose;
                            break;
                        }
                    }
                }
            }));
    
            afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (act->attacker->atvStats->name != ptr->atvStats->name) return;
    
                for (auto e : act->actionTypeList) {
                    if (e == AType::SKILL || e == AType::ULT) {
                        ptr->stack["Somnus_Corpus"] = 1;
                        break;
                    }
                }
    
                if (act->attacker->atvStats->name == ptr->atvStats->name &&
                    ptr->stack["Somnus_Corpus"] == 1) {
                    for (auto e : act->actionTypeList) {
                        if (e == AType::FUA) {
                            ptr->statsType[Stats::DMG][AType::FUA] -= 40 + 8 * superimpose;
                            ptr->stack["Somnus_Corpus"] = 0;
                            break;
                        }
                    }
                }
            }));
        };
    }
}