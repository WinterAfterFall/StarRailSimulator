
#ifndef Aglaea_LC_H
#define Aglaea_LC_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Remembrance_Lightcone{
    function<void(Ally *ptr)> Aglaea_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1058,635,397);
            ptr->Light_cone.Name = "Aglaea_LC";
            ptr->Sub_Unit_ptr[0]->Atv_stats->Base_speed+= 10 + superimpose * 2;
            When_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_) {
                if (data_->Attacker->Atv_stats->Unit_num == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num) {
                if (ptr->Sub_Unit_ptr[0]->Stack["Aglaea_LC_stack"] < 6) {
                    Buff_single_with_all_memo(ptr, ST_CD, "None", 7.5 + 1.5 * superimpose);
                    ptr->Sub_Unit_ptr[0]->Stack["Aglaea_LC_stack"]++;
                    if (ptr->Sub_Unit_ptr[0]->Stack["Aglaea_LC_stack"] == 6) {
                    Buff_single_with_all_memo(ptr, ST_DMG, "Basic_Attack", 6 * (7.5 + 1.5 * superimpose));
                    }
                }
                }
            }));
        };
    }
    
}
#endif