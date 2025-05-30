
#ifndef The_Herta_LC_H
#define The_Herta_LC_H

#include "../Library.h"
namespace Erudition_Lightcone{
    function<void(Ally *ptr)> The_Herta_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,635,463);
            ptr->Light_cone.Name = "The_Herta_LC";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AT_NONE] += 10 + 2 * superimpose;
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (ptr->getSubUnit()->isBuffEnd("The_Herta_LC_buff")) {
                    ptr->getSubUnit()->buffSingle({
                        {ST_DMG,AT_SKILL,-(50.0 + 10 * superimpose)},
                        {ST_DMG,AT_ULT,-(50.0 + 10 * superimpose)},
                });
                }
            }));
    
            Buff_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_) {
                if (data_->Action_type.second == "Ultimate" && data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name) {
                    ptr->getSubUnit()->buffSingle({
                        {ST_DMG,AT_SKILL,(50.0 + 10 * superimpose)},
                        {ST_DMG,AT_ULT,(50.0 + 10 * superimpose)},
                        },"The_Herta_LC_buff",3);
                    if (ptr->Ult_cost >= 140) {
                        Skill_point(ptr->Sub_Unit_ptr[0].get(), 1);
                    }
                }
            }));
    
            Before_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_) {
                if (data_->Action_type.second == "Ultimate" && data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name) {
                    if (data_->Action_type.second == "Ultimate" && data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name) {
                    ptr->getSubUnit()->buffSingle({
                        {ST_DMG,AT_SKILL,(50.0 + 10 * superimpose)},
                        {ST_DMG,AT_ULT,(50.0 + 10 * superimpose)},
                        },"The_Herta_LC_buff",3);
                    if (ptr->Ult_cost >= 140) {
                        Skill_point(ptr->Sub_Unit_ptr[0].get(), 1);
                    }
                }
                }
            }));
        };
    }
}
#endif