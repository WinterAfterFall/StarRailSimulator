
#ifndef Bronya_LC_H
#define Bronya_LC_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Harmony_Lightcone{
    function<void(Ally *ptr)> Bronya_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1164,529,463);
            ptr->Light_cone.Name = "Bronya_LC";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Energy_recharge += 8 + 2 * superimpose;
            }));
    
            After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_) {
                if (data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name) {
                    if (data_->Action_type.second == "Skill") {
                        ptr->Sub_Unit_ptr[0]->Buff_check["Battle_Isnt_Over_buff"] = 1;
                    } else if (data_->Action_type.second == "Ultimate") {
                        if (ptr->Sub_Unit_ptr[0]->Buff_check["Battle_Isnt_Over_cnt"] == 0) {
                            ptr->Sub_Unit_ptr[0]->Buff_check["Battle_Isnt_Over_cnt"] = true;
                            Skill_point(ptr->Sub_Unit_ptr[0].get(), 1);
                        } else {
                            ptr->Sub_Unit_ptr[0]->Buff_check["Battle_Isnt_Over_cnt"] = false;
                        }
                    }
                }
            }));
    
            Buff_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_) {
                if (data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name) {
                    if (data_->Action_type.second == "Skill") {
                        ptr->Sub_Unit_ptr[0]->Buff_check["Battle_Isnt_Over_buff"] = 1;
                    } else if (data_->Action_type.second == "Ultimate") {
                        if (ptr->Sub_Unit_ptr[0]->Buff_check["Battle_Isnt_Over_cnt"] == 0) {
                            ptr->Sub_Unit_ptr[0]->Buff_check["Battle_Isnt_Over_cnt"] = true;
                            Skill_point(ptr->Sub_Unit_ptr[0].get(), 1);
                        } else {
                            ptr->Sub_Unit_ptr[0]->Buff_check["Battle_Isnt_Over_cnt"] = false;
                        }
                    }
                }
            }));
    
            Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                SubUnit *tempstats = dynamic_cast<SubUnit *>(turn->ptr_to_unit);
                if (!tempstats) return;
                if (ptr->Sub_Unit_ptr[0]->Buff_check["Battle_Isnt_Over_buff"] == 1) {
                    tempstats->Stats_type[ST_DMG]["None"] += 25 + 5 * superimpose;
                    ptr->Sub_Unit_ptr[0]->Buff_check["Battle_Isnt_Over_buff"] = 0;
                    ptr->Sub_Unit_ptr[0]->Buff_check["Battle_Isnt_Over_buff_check"] = 1;
                }
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                SubUnit *tempstats = dynamic_cast<SubUnit *>(turn->ptr_to_unit);
                if (!tempstats) return;
                if (ptr->Sub_Unit_ptr[0]->Buff_check["Battle_Isnt_Over_buff_check"] == 1) {
                    tempstats->Stats_type[ST_DMG]["None"] -= 25 + 5 * superimpose;
                    ptr->Sub_Unit_ptr[0]->Buff_check["Battle_Isnt_Over_buff_check"] = 0;
                }
            }));
        };
    }
    
}
#endif