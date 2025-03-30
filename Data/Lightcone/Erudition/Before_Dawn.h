
#ifndef Before_Dawn_H
#define Before_Dawn_H

#include "../Library.h"
namespace Erudition_Lightcone{
    void Before_Dawn(Ally *ptr);
    void Before_Dawn(Ally *ptr){
        SetBaseStats(ptr->Sub_Unit_ptr[0].get(),1058,582,463);

        ptr->Light_cone.Name = "Before_Dawn";
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"] += 36;
            ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Skill"] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Ultimate"] += 18;
        }));

        Before_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](ActionData &data_) {
            if (data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name &&
                ptr->Sub_Unit_ptr[0]->Stack["Somnus_Corpus"] == 1) {
                for (auto e : data_.Skill_Type) {
                    if (e == "Fua") {
                        ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Fua"] += 48;
                        break;
                    }
                }
            }
        }));

        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](ActionData &data_) {
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
                        ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Fua"] -= 48;
                        ptr->Sub_Unit_ptr[0]->Stack["Somnus_Corpus"] = 0;
                        break;
                    }
                }
            }
        }));
        
        
    }
}
#endif