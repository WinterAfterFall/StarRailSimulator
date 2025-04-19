
#ifndef Geniuses_Greetings_H
#define Geniuses_Greetings_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Remembrance_Lightcone{
    function<void(Ally *ptr)> Geniuses_Greetings(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "Geniuses_Greetings";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type["ATK%"]["None"] += 12 + 4 * superimpose;
            }));
    
            After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_) {
                if (data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_->Action_type.second == "Ultimate") {
                    Buff_single_with_all_memo_each(ptr, "Dmg%", "Basic_Attack", (15 + superimpose * 5) , "Geniuses_Greetings");
                    Extend_Buff_single_with_all_memo(ptr, "Geniuses_Greetings", 3);
                }
            }));
    
            Buff_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_) {
                if (data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_->Action_type.second == "Ultimate") {
                    Buff_single_with_all_memo_each(ptr, "Dmg%", "Basic_Attack", (15 + superimpose * 5), "Geniuses_Greetings");
                    Extend_Buff_single_with_all_memo(ptr, "Geniuses_Greetings", 3);
                }
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                SubUnit *tempstats = dynamic_cast<SubUnit *>(turn->ptr_to_unit);
                if (!tempstats) return;
                if (Buff_end(tempstats, "Geniuses_Greetings")) {
                    tempstats->Stats_type["Dmg%"]["Basic_Attack"] -= (15 + superimpose * 5);
                    tempstats->Buff_check["Geniuses_Greetings"] = 0;
                }
            }));
        };
    }
    void Geniuses_Greetings(Ally *ptr){

    }
    
}
#endif