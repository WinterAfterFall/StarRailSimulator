#include "../include.h"
namespace Relic{
    void Hero_Wreath(CharUnit *ptr);
    void Hero_Wreath(CharUnit *ptr){
        ptr->Relic.name = "Hero_Wreath";

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::ATK_P][AType::NONE] += 12;
        }));

        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            bool onField = ptr->memosprite && ptr->memosprite->isExisted();
            if (onField && ptr->buffCheck["Hero_Wreath"] == 0) {
                ptr->buffCheck["Hero_Wreath"] = 1;
                buffSingle(ptr,{{Stats::SPD_P,AType::NONE,6}});
            } else if (!onField && ptr->buffCheck["Hero_Wreath"] == 1) {
                ptr->buffCheck["Hero_Wreath"] = 0;
                buffSingle(ptr,{{Stats::SPD_P,AType::NONE,-6}});
            }
        }));

        beforeAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (act->attacker->atvStats->side == Side::MEMOSPRITE && act->attacker->owner->isSameName(ptr)) {
                buffSingleChar(ptr,{{Stats::CD, AType::NONE, 30}}, "Hero_Wreath_buff",2);
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if (isBuffEnd(ptr, "Hero_Wreath_buff")) buffSingle(ptr, {{Stats::CD, AType::NONE, -30}});
            if(auto *each = ptr->memosprite.get()){
                if (isBuffEnd(each, "Hero_Wreath_buff")) buffSingle(each, {{Stats::CD, AType::NONE, -30}});
            }
        }));
        
        
        
    }
}