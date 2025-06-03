#include "../include.h"
namespace Harmony_Lightcone{
    function<void(Ally *ptr)> Tribbie_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1270,529,397);
            ptr->Light_cone.Name = "Tribbie_LC";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_CD][AT_NONE] += 30 + 6 * superimpose;
            }));
    
            Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                Increase_energy(ptr, 21);
                if(ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Presage",2)){
                    buffAllAlly({{ST_CD, AT_NONE, (36.0 + 12 * superimpose)}});
                }
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (ptr->getSubUnit()->isBuffEnd("Presage")) {
                    buffAllAlly({{ST_CD, AT_NONE, -(36.0 + 12 * superimpose)}});
                }
            }));

            AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if (act->isSameAction(ptr->getSubUnit(),AT_FUA)) {
                    Increase_energy(ptr, 12);
                    if(ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Presage",2)){
                        buffAllAlly({{ST_CD, AT_NONE, (36.0 + 12 * superimpose)}});
                    }
                }
            }));

        };
    }
}
