#include "../include.h"
namespace Relic{
    void Scholar(Ally *ptr);
    void Scholar(Ally *ptr){
        ptr->Relic.Name = "Scholar";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::None] += 8;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::Ult] += 20;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::SKILL] += 20;
        }));

        AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr](shared_ptr<AllyActionData> &act){
            if (act->isSameAction(ptr->getSubUnit(),AType::Ult)) {
                if (ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Scholar_buff")) {
                    ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::SKILL] += 25;
                }
            }
        }));

        AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            if (act->isSameAction(ptr->getSubUnit(),AType::SKILL)) {
                if (ptr->Sub_Unit_ptr[0]->getBuffCheck("Scholar_buff")) {
                    ptr->Sub_Unit_ptr[0]->Buff_check["Scholar_buff"] = 0;
                    ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::SKILL] -= 25;
                }
            }
        }));

        
    }
}