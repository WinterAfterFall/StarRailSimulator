
#ifndef Aglaea_LC_H
#define Aglaea_LC_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Remembrance_Lightcone{
    void Aglaea_LC(Ally *ptr);
    void Aglaea_LC(Ally *ptr){
        SetBaseStats(ptr->Sub_Unit_ptr[0].get(),1058,635,397);
        ptr->Sub_Unit_ptr[0]->Atv_stats->Base_speed+=12;
        ptr->Light_cone.Name = "Aglaea_LC";
        When_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](ActionData &data_) {
            if (data_.Attacker->Atv_stats->Unit_num == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num) {
            if (ptr->Sub_Unit_ptr[0]->Stack["Aglaea_LC_stack"] < 6) {
                Buff_single_with_all_memo(ptr, "Crit_dam", "None", 9);
                ptr->Sub_Unit_ptr[0]->Stack["Aglaea_LC_stack"]++;
                if (ptr->Sub_Unit_ptr[0]->Stack["Aglaea_LC_stack"] == 6) {
                Buff_single_with_all_memo(ptr, "Dmg%", "Basic_Attack", 9 * 6);
                }
            }
            }
        }));

    }
    
}
#endif