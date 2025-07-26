#include "../include.h"
namespace Erudition_Lightcone{
    function<void(Ally *ptr)> Calculus(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1058,529,397);
            ptr->Light_cone.Name = "Calculus";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AType::None] += 7 + superimpose;
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (ptr->getSubUnit()->isBuffEnd("Calculus_Speed_buff")) {
                    ptr->getSubUnit()->buffSingle({{ST_SPD_P,AType::None,-(6.0 + 2 * superimpose)}});
                }
                
            }));
    
            BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AType::None] -= ptr->Sub_Unit_ptr[0]->Buff_note["Calculus_Atk_buff"];
                ptr->Sub_Unit_ptr[0]->Buff_note["Calculus_Atk_buff"] = act->targetList.size() * 3 + superimpose;
    
                ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AType::None] += ptr->Sub_Unit_ptr[0]->Buff_note["Calculus_Atk_buff"];
                if (ptr->Sub_Unit_ptr[0]->Buff_note["Calculus_Atk_buff"] >= 24) {
                    ptr->getSubUnit()->buffSingle({{ST_SPD_P,AType::None,(6.0 + 2 * superimpose)}},"Calculus_Speed_buff",1);
                }
            }));
        };
    }
}