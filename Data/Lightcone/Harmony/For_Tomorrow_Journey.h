
#ifndef For_Tomorrow_Journey_H
#define For_Tomorrow_Journey_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Harmony_Lightcone{
    function<void(Ally *ptr)> For_Tomorrow_Journey(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "For_Tomorrow_Journey";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AT_NONE] += 12 + 4 * superimpose;
            }));
    
            After_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_) {
                if (data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_->Action_type.second == "Ultimate") {
                    ptr->getSubUnit()->buffSingle({
                        {ST_DMG,AT_NONE,(15.0 + 3 * superimpose)}
                    },"For_Tomorrow_Journey_Buff",1);
                }
            }));
    
            Buff_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_) {
                if (data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_->Action_type.second == "Ultimate") {
                    ptr->getSubUnit()->buffSingle({
                        {ST_DMG,AT_NONE,(15.0 + 3 * superimpose)}
                    },"For_Tomorrow_Journey_Buff",1);
                }
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (ptr->getSubUnit()->isBuffEnd("Himeko_LC_buff")) {
                    ptr->getSubUnit()->buffSingle({
                        {ST_DMG,AT_NONE,-(15.0 + 3 * superimpose)}
                    });
                }
            }));
        };
    }
}
#endif