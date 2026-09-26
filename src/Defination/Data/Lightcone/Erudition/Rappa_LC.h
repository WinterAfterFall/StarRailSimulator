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


            WhenUseUlt_List.push_back(TriggerByAlly_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](CharUnit *ally){
                if (ally->isSameOwner(ptr)) {
                    ptr->buffCheck["Ration"] = 1;
                    ptr->stack["Ration"] = 0;
                }
            }));

            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (act->isSameAction(ptr,AType::BA)&& ptr->buffCheck["Ration"] == 1) {
                    ptr->stack["Ration"]++;
                    if (ptr->stack["Ration"] == 2) {
                        Action_forward(ptr->Atv_stats.get(), (45 + superimpose * 5));
                        ptr->buffCheck["Ration"] = 0;
                    }
                }
            }));
            
        };
    }
}
