#include "../include.h"
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

            AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if (act->isSameAction(ptr->getSubUnit(),AT_ULT)) {
                    ptr->Sub_Unit_ptr[0]->Buff_check["Ration"] = 1;
                    ptr->Sub_Unit_ptr[0]->Stack["Ration"] = 0;
                }
            }));

            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (act->isSameAction(ptr->getSubUnit(),AT_BA)&& ptr->Sub_Unit_ptr[0]->Buff_check["Ration"] == 1) {
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
