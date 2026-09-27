#include "../include.h"
namespace Relic{
    void Scholar(CharUnit *ptr);
    void Scholar(CharUnit *ptr){
        ptr->Relic.name = "Scholar";
        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::CR][AType::NONE] += 8;
            ptr->statsType[Stats::DMG][AType::ULT] += 20;
            ptr->statsType[Stats::DMG][AType::SKILL] += 20;
        }));

        whenUseUltList.push_back(TriggerByAllyFunc(PRIORITY_IMMEDIATELY,[ptr](CharUnit *ally){
            if (ally->isSameOwner(ptr)) {
                if (isHaveToAddBuff(ptr,"Scholar_buff")) {
                    ptr->statsType[Stats::DMG][AType::SKILL] += 25;
                }
            }
        }));

        afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (act->isSameAction(ptr,AType::SKILL)) {
                if (ptr->getBuffCheck("Scholar_buff")) {
                    ptr->buffCheck["Scholar_buff"] = 0;
                    ptr->statsType[Stats::DMG][AType::SKILL] -= 25;
                }
            }
        }));

        
    }
}