
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
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"] += 8;
            ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Ultimate"] += 20;
            ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Skill"] += 20;
        }));

        Before_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyActionData> &data_) {
            if (data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_->Action_type.second == "Ultimate") {
                if (!Buff_check(ptr->Sub_Unit_ptr[0].get(), "Scholar_buff")) {
                    ptr->Sub_Unit_ptr[0]->Buff_check["Scholar_buff"] = 1;
                    ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Skill"] += 25;
                }
            }
        }));

        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyActionData> &data_) {
            if (data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_->Action_type.second == "Skill") {
                if (Buff_check(ptr->Sub_Unit_ptr[0].get(), "Scholar_buff")) {
                    ptr->Sub_Unit_ptr[0]->Buff_check["Scholar_buff"] = 0;
                    ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Skill"] -= 25;
                }
            }
        }));

        Buff_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyActionData> &data_) {
            if (data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_->Action_type.second == "Ultimate") {
                if (!Buff_check(ptr->Sub_Unit_ptr[0].get(), "Scholar_buff")) {
                    ptr->Sub_Unit_ptr[0]->Buff_check["Scholar_buff"] = 1;
                    ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Skill"] += 25;
                }
            }
        }));

        
    }
}
#endif