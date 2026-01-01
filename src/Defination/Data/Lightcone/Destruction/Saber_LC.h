#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> Saber_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,582,529);
            ptr->Light_cone.Name = "Saber_LC";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](){
                        
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CD][AType::None]+=27 + (9*superimpose);
                
                }
            ));

            WhenUseUlt_List.push_back(TriggerByAlly_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](Ally *ally){
                if (ally->isSameChar(ptr)) {
                    ptr->buffSingle({{Stats::ATK_P,AType::None,30.0 + 10.0 * superimpose}},"Saber_LC",2);
                    if(ptr->Max_energy>=300){
                        Increase_energy(ptr,10,0);
                        ptr->buffSingle({{Stats::ATK_P,AType::None,30.0 + 10.0 * superimpose}},"Extra Saber_LC",2);

                    }
                }
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,superimpose]() {
                if (ptr->Sub_Unit_ptr[0]->isBuffEnd("Saber_LC")) {
                    ptr->buffSingle({{Stats::ATK_P,AType::None,-(30.0 + 10.0 * superimpose)}});
                }
                if (ptr->Sub_Unit_ptr[0]->isBuffEnd("Extra Saber_LC")) {
                    ptr->buffSingle({{Stats::ATK_P,AType::None,-(30.0 + 10.0 * superimpose)}});
                }
            }));
        };
    }
}
