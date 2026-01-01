#include "../include.h"
namespace Erudition_Lightcone{
    function<void(CharUnit *ptr)> Rappa_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,582,529);
            ptr->Light_cone.Name = "Rappa_LC";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::BE][AType::None] += 50 + superimpose * 10;
            }));
    
            Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                Increase_energy(ptr, (27.5 + superimpose * 2.5));
            }));


            WhenUseUlt_List.push_back(TriggerByAlly_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](Ally *ally){
                if (ally->isSameChar(ptr)) {
                    ptr->Buff_check["Ration"] = 1;
                    ptr->Stack["Ration"] = 0;
                }
            }));

            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (act->isSameAction(ptr,AType::BA)&& ptr->Buff_check["Ration"] == 1) {
                    ptr->Stack["Ration"]++;
                    if (ptr->Stack["Ration"] == 2) {
                        Action_forward(ptr->Atv_stats.get(), (40 + superimpose * 5));
                        ptr->Buff_check["Ration"] = 0;
                    }
                }
            }));
            
        };
    }
}
