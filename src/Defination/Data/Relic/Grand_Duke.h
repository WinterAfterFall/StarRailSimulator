#include "../include.h"
namespace Relic{
    void Grand_Duke(CharUnit *ptr);
    void Grand_Duke(CharUnit *ptr){
        ptr->Relic.name = "Grand_Duke";
        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::DMG][AType::FUA] += 20;
        }));

        beforeAttackPerHitList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (act->attacker->atvStats->name != ptr->atvStats->name) return;

            bool check = false;
            for (auto e : act->actionTypeList) {
                if (e == AType::FUA) {
                    check = true;
                    break;
                }
            }
            int hitCnt = 0;
            if (check) {
                hitCnt += act->attacker->hitCount;
                if (hitCnt > 8) {
                    hitCnt = 8;
                }
                act->attacker->statsType[Stats::ATK_P][AType::NONE] -= act->attacker->stack["Grand_Duke"] * 6;
                act->attacker->stack["Grand_Duke"] = hitCnt;
                act->attacker->statsType[Stats::ATK_P][AType::NONE] += act->attacker->stack["Grand_Duke"] * 6;
                extendBuffTime(act->attacker,"Grand_Duke", 3);
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if (turn->name != ptr->atvStats->name) return;

            if (isBuffEnd(ptr,"Grand_Duke")) {
                ptr->statsType[Stats::ATK_P][AType::NONE] -= ptr->stack["Grand_Duke"] * 6;
                ptr->stack["Grand_Duke"] = 0;
            }
        }));
        
    }
}