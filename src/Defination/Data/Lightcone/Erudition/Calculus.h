#include "../include.h"
namespace Erudition_Lightcone{
    function<void(CharUnit *ptr)> Calculus(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1058,529,397);
            ptr->Light_cone.Name = "Calculus";
    
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::ATK_P][AType::None] += 7 + superimpose;
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (isBuffEnd(ptr,"Calculus_Speed_buff")) {
                    buffSingle(ptr,{{Stats::SPD_P,AType::None,-(6.0 + 2 * superimpose)}});
                }
                
            }));
    
            BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                ptr->Stats_type[Stats::ATK_P][AType::None] -= ptr->Buff_note["Calculus_Atk_buff"];
                ptr->Buff_note["Calculus_Atk_buff"] = act->targetList.size() * 3 + superimpose;
    
                ptr->Stats_type[Stats::ATK_P][AType::None] += ptr->Buff_note["Calculus_Atk_buff"];
                if (ptr->Buff_note["Calculus_Atk_buff"] >= 24) {
                    buffSingle(ptr,{{Stats::SPD_P,AType::None,(6.0 + 2 * superimpose)}},"Calculus_Speed_buff",1);
                }
            }));
        };
    }
}