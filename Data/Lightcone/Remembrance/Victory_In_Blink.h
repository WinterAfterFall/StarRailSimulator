
#ifndef Victory_In_Blink_H
#define Victory_In_Blink_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Remembrance_Lightcone{
    void Victory_In_Blink(Ally *ptr);
    void Victory_In_Blink(Ally *ptr){
        SetBaseStats(ptr->Sub_Unit_ptr[0].get(),847,476,397);
        ptr->Light_cone.Name = "Victory_In_Blink";

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"] += 24;
        }));

        Buff_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](ActionData &data_) {
            if (data_.Attacker->Atv_stats->Side == "Memosprite" &&
                data_.Attacker->ptr_to_unit->Sub_Unit_ptr[0]->Atv_stats->Char_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Char_Name) {
                Buff_All_Ally_Each_Ally("Dmg%", "None", 16, "Victory_Blink");
                Extend_Buff_All_Ally("Victory_Blink", 3);
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Sub_Unit *tempstats = dynamic_cast<Sub_Unit *>(turn->ptr_to_unit);
            if (!tempstats) return;
            if (Buff_end(tempstats, "Victory_Blink")) {
                tempstats->Stats_type["Dmg%"]["None"] -= 16;
                tempstats->Buff_check["Victory_Blink"] = 0;
            }
        }));
    }
    
}
#endif