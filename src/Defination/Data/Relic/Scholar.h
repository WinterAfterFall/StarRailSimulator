#include "../include.h"
namespace Relic{
    void Scholar(CharUnit *ptr);
    void Scholar(CharUnit *ptr){
        ptr->Relic.Name = "Scholar";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::None] += 8;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::Ult] += 20;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::SKILL] += 20;
        }));

        WhenUseUlt_List.push_back(TriggerByAlly_Func(PRIORITY_IMMEDIATELY,[ptr](Ally *ally){
            if (ally->isSameChar(ptr)) {
                if (ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Scholar_buff")) {
                    ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::SKILL] += 25;
                }
            }
        }));

        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (act->isSameAction(ptr->getMemosprite(),AType::SKILL)) {
                if (ptr->Sub_Unit_ptr[0]->getBuffCheck("Scholar_buff")) {
                    ptr->Sub_Unit_ptr[0]->Buff_check["Scholar_buff"] = 0;
                    ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::SKILL] -= 25;
                }
            }
        }));

        
    }
}