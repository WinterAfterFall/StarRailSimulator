#include "../include.h"
namespace Destruction_Lightcone{
    function<void(Ally *ptr)> Saber_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,582,529);
            ptr->Light_cone.Name = "Saber_LC";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](){
                        
                ptr->Sub_Unit_ptr[0]->Stats_type[ST_CD][AT_NONE]+=27 + (9*superimpose);
                
                }
            ));
            
            AllyActionList.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](shared_ptr<AllyActionData> &act){
                if (act->isSameAction(ptr->getSubUnit(),AT_ULT)) {
                    ptr->getSubUnit()->buffSingle({{ST_ATK_P,AT_NONE,30.0 + 10.0 * superimpose}},"Saber_LC",2);
                    if(ptr->Max_energy>=300){
                        Increase_energy(ptr,10,0);
                        ptr->getSubUnit()->buffSingle({{ST_ATK_P,AT_NONE,30.0 + 10.0 * superimpose}},"Extra Saber_LC",2);

                    }
                }
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,superimpose]() {
                if (ptr->Sub_Unit_ptr[0]->isBuffEnd("Saber_LC")) {
                    ptr->getSubUnit()->buffSingle({{ST_ATK_P,AT_NONE,-(30.0 + 10.0 * superimpose)}});
                }
                if (ptr->Sub_Unit_ptr[0]->isBuffEnd("Extra Saber_LC")) {
                    ptr->getSubUnit()->buffSingle({{ST_ATK_P,AT_NONE,-(30.0 + 10.0 * superimpose)}});
                }
            }));
        };
    }
}
