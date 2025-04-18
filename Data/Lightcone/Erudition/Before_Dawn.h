
#ifndef Before_Dawn_H
#define Before_Dawn_H

#include "../Library.h"
namespace Erudition_Lightcone{
    function<void(Ally *ptr)> Before_Dawn(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1058,582,463);

            ptr->Light_cone.Name = "Before_Dawn";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"] += 30 + 6 * superimpose;
                ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Skill"] += 15 + 3 * superimpose;
                ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Ultimate"] += 15 + 3 * superimpose;
            }));
    
            Before_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](ActionData &data_) {
                if (data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name &&
                    ptr->Sub_Unit_ptr[0]->Stack["Somnus_Corpus"] == 1) {
                    for (auto e : data_.Skill_Type) {
                        if (e == "Fua") {
                            ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Fua"] += 40 + 8 * superimpose;
                            break;
                        }
                    }
                }
            }));
    
            After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](ActionData &data_) {
                if (data_.Attacker->Atv_stats->Unit_Name != ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name) return;
    
                for (auto e : data_.Skill_Type) {
                    if (e == "Skill" || e == "Ultimate") {
                        ptr->Sub_Unit_ptr[0]->Stack["Somnus_Corpus"] = 1;
                        break;
                    }
                }
    
                if (data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name &&
                    ptr->Sub_Unit_ptr[0]->Stack["Somnus_Corpus"] == 1) {
                    for (auto e : data_.Skill_Type) {
                        if (e == "Fua") {
                            ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Fua"] -= 40 + 8 * superimpose;
                            ptr->Sub_Unit_ptr[0]->Stack["Somnus_Corpus"] = 0;
                            break;
                        }
                    }
                }
            }));
        };
    }
}
#endif