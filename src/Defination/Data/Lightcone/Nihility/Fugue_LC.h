#include "../include.h"
namespace Nihility_Lightcone{
    function<void(Ally *ptr)> Fugue_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,582,529);
            ptr->Light_cone.Name = "Fugue_LC";
            string Charring = ptr->getSubUnit()->getUnitName() + " Charring";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,Charring]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::BE][AType::None] += 50 + 10 * superimpose;
            }));
    
            Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,Charring](Enemy *target, SubUnit *Breaker) {
                target->debuffSingleApply({{Stats::VUL,AType::None,15.0 + 3 * superimpose}},ptr->Sub_Unit_ptr[0].get(),Charring,2);
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,Charring]() {
                if (turn->Side != "Enemy") return;
                if (Enemy_unit[turn->num]->isDebuffEnd(Charring)) {
                    Enemy_unit[turn->num]->debuffSingle({{Stats::VUL,AType::None,-(15.0 + 3 * superimpose)}});

                }
            }));
        };
    }
}