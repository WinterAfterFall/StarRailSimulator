#include "../include.h"
namespace Harmony_Lightcone{
    function<void(CharUnit *ptr)> Robin_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,635,463);
            ptr->Light_cone.Name = "Robin_LC";
            
            When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if (ptr->Sub_Unit_ptr[0]->Stack["Cantillation"] < 5) {
                    ptr->Sub_Unit_ptr[0]->Stack["Cantillation"]++;
                    ptr->Energy_recharge += 2.5 + 0.5 * superimpose;
                }
            }));

            WhenUseUlt_List.push_back(TriggerByAlly_Func(PRIORITY_IMMEDIATELY,[ptr,superimpose](Ally *ally){
                if (ally->isSameChar(ptr)) {
                    ptr->Energy_recharge -= ptr->Sub_Unit_ptr[0]->Stack["Cantillation"] * (2.5 + 0.5 * superimpose);
                    ptr->Sub_Unit_ptr[0]->Stack["Cantillation"] = 0;
                    if (ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Cadenza",1)) {
                        buffAllAlly({{Stats::DMG, AType::None, (20.0 + 4 * superimpose)}});
                        ptr->Sub_Unit_ptr[0]->buffSingle({{Stats::ATK_P, AType::None, (36.0 + 12 * superimpose)}});
                    }
                }
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                if (ptr->isBuffEnd("Cadenza")) {
                    buffAllAlly({{Stats::DMG, AType::None, -(20.0 + 4 * superimpose)}});
                    ptr->Sub_Unit_ptr[0]->buffSingle({{Stats::ATK_P, AType::None, -(36.0 + 12 * superimpose)}});
                }
            }));
        };
    }   
}
