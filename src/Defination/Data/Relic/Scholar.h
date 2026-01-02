#include "../include.h"
namespace Relic{
    void Scholar(CharUnit *ptr);
    void Scholar(CharUnit *ptr){
        ptr->Relic.Name = "Scholar";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Stats_type[Stats::CR][AType::None] += 8;
            ptr->Stats_type[Stats::DMG][AType::Ult] += 20;
            ptr->Stats_type[Stats::DMG][AType::SKILL] += 20;
        }));

        WhenUseUlt_List.push_back(TriggerByAlly_Func(PRIORITY_IMMEDIATELY,[ptr](Ally *ally){
            if (ally->isSameChar(ptr)) {
                if (isHaveToAddBuff(ptr,"Scholar_buff")) {
                    ptr->Stats_type[Stats::DMG][AType::SKILL] += 25;
                }
            }
        }));

        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (act->isSameAction(ptr,AType::SKILL)) {
                if (ptr->getBuffCheck("Scholar_buff")) {
                    ptr->Buff_check["Scholar_buff"] = 0;
                    ptr->Stats_type[Stats::DMG][AType::SKILL] -= 25;
                }
            }
        }));

        
    }
}