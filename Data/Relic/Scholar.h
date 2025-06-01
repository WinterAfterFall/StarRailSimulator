
#ifndef Scholar_H
#define Scholar_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Relic{
    void Scholar(Ally *ptr);
    void Scholar(Ally *ptr){
        ptr->Relic.Name = "Scholar";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AT_NONE] += 8;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG]["Ultimate"] += 20;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG]["Skill"] += 20;
        }));

        AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr](shared_ptr<AllyActionData> &data_){
            if (data_->isSameAction(ptr->getSubUnit(),AT_ULT)) {
                if (ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Scholar_buff")) {
                    ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG]["Skill"] += 25;
                }
            }
        }));

        After_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &data_) {
            if (data_->isSameAction(ptr->getSubUnit(),AT_SKILL)) {
                if (ptr->Sub_Unit_ptr[0]->getBuffCheck("Scholar_buff")) {
                    ptr->Sub_Unit_ptr[0]->Buff_check["Scholar_buff"] = 0;
                    ptr->Sub_Unit_ptr[0]->Stats_type[ST_DMG]["Skill"] -= 25;
                }
            }
        }));

        
    }
}
#endif