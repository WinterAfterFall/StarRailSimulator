
#ifndef Victory_In_Blink_H
#define Victory_In_Blink_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Remembrance_Lightcone{
    function<void(Ally *ptr)> Victory_In_Blink(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(847,476,397);
            ptr->Light_cone.Name = "Victory_In_Blink";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"] += 9 + 3 * superimpose;
            }));
    
            Buff_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_) {
                if (data_->Attacker->Atv_stats->Side == "Memosprite" &&
                    data_->Attacker->ptr_to_unit->Sub_Unit_ptr[0]->Atv_stats->Char_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Char_Name) {
                    Buff_All_Ally_Each_Ally("Dmg%", "None", (6 + 2 * superimpose), "Victory_Blink");
                    Extend_Buff_All_Ally("Victory_Blink", 3);
                }
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                SubUnit *tempstats = dynamic_cast<SubUnit *>(turn->ptr_to_unit);
                if (!tempstats) return;
                if (Buff_end(tempstats, "Victory_Blink")) {
                    tempstats->Stats_type["Dmg%"]["None"] -= (6 + 2 * superimpose);
                    tempstats->Buff_check["Victory_Blink"] = 0;
                }
            }));
    
            AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,superimpose](SubUnit* target) {
                if(target->getBuffCheck("Victory_Blink")){
                    target->setBuffCheck("Victory_Blink",0);
                    target->setBuffCountdown("Victory_Blink",0);
                    target->Stats_type["Dmg%"]["None"] -= (6 + 2 * superimpose);
                }
            }));
        };
    }
    
}
#endif