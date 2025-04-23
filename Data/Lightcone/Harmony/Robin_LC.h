
#ifndef Robin_LC_H
#define Robin_LC_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"
namespace Harmony_Lightcone{
    function<void(Ally *ptr)> Robin_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,635,463);
            ptr->Light_cone.Name = "Robin_LC";
            
            When_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_) {
                if (ptr->Sub_Unit_ptr[0]->Stack["Cantillation"] < 5) {
                    ptr->Sub_Unit_ptr[0]->Stack["Cantillation"]++;
                    ptr->Energy_recharge += 2.5 + 0.5 * superimpose;
                }
            }));
    
            Before_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_) {
                if (data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_->Action_type.second == "Ultimate") {
                    ptr->Energy_recharge -= ptr->Sub_Unit_ptr[0]->Stack["Cantillation"] * (2.5 + 0.5 * superimpose);
                    ptr->Sub_Unit_ptr[0]->Stack["Cantillation"] = 0;
                    if (ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Cadenza",1)) {
                        buffAllAlly({{ST_DMG, AT_NONE, (20.0 + 4 * superimpose)}});
                        ptr->Sub_Unit_ptr[0]->buffSingle({{ST_ATK_P, AT_NONE, (36.0 + 12 * superimpose)}});
                    }
                }
            }));
    
            Buff_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_) {
                if (data_->Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name && data_->Action_type.second == "Ultimate") {
                    ptr->Energy_recharge -= ptr->Sub_Unit_ptr[0]->Stack["Cantillation"] * (2.5 + 0.5 * superimpose);
                    ptr->Sub_Unit_ptr[0]->Stack["Cantillation"] = 0;
                    if (ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Cadenza",1)) {
                        buffAllAlly({{ST_DMG, AT_NONE, (20.0 + 4 * superimpose)}});
                        ptr->Sub_Unit_ptr[0]->buffSingle({{ST_ATK_P, AT_NONE, (36.0 + 12 * superimpose)}});
                    }
                }
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (ptr->getSubUnit()->isBuffEnd("Cadenza")) {
                    buffAllAlly({{ST_DMG, AT_NONE, -(20.0 + 4 * superimpose)}});
                    ptr->Sub_Unit_ptr[0]->buffSingle({{ST_ATK_P, AT_NONE, -(36.0 + 12 * superimpose)}});
                }
            }));
        };
    }   
}
#endif