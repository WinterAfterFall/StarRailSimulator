
#ifndef Rappa_LC_H
#define Rappa_LC_H

#include "../Library.h"
namespace Erudition_Lightcone{
    function<void(Ally *ptr)> Rappa_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,582,529);
            ptr->Light_cone.Name = "Rappa_LC";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_BE][AT_NONE] += 50 + superimpose * 10;
            }));
    
            Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                Increase_energy(ptr, (27.5 + superimpose * 2.5));
            }));
    
            Buff_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_) {
                if (data_->Action_type.second == "Ultimate") {
                    ptr->Sub_Unit_ptr[0]->Buff_check["Ration"] = 1;
                    ptr->Sub_Unit_ptr[0]->Stack["Ration"] = 0;
                }
            }));
    
            Before_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_) {
                if (data_->Action_type.second == "Ultimate") {
                    ptr->Sub_Unit_ptr[0]->Buff_check["Ration"] = 1;
                    ptr->Sub_Unit_ptr[0]->Stack["Ration"] = 0;
                }
            }));
    
            After_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyActionData> &data_) {
                if (data_->Action_type.second == "Basic_Attack" && ptr->Sub_Unit_ptr[0]->Buff_check["Ration"] == 1) {
                    ptr->Sub_Unit_ptr[0]->Stack["Ration"]++;
                    if (ptr->Sub_Unit_ptr[0]->Stack["Ration"] == 2) {
                        Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), (40 + superimpose * 5));
                        ptr->Sub_Unit_ptr[0]->Buff_check["Ration"] = 0;
                    }
                }
            }));
        };
    }
}
#endif