#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> Fugue_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,582,529);
            ptr->Light_cone.Name = "Fugue_LC";
            string Charring = ptr->getUnitName() + " Charring";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,Charring]() {
                ptr->Stats_type[Stats::BE][AType::None] += 50 + 10 * superimpose;
            }));
    
            Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,Charring](Enemy *target, AllyUnit *Breaker) {
                target->debuffSingleApply({{Stats::VUL,AType::None,15.0 + 3 * superimpose}},ptr,Charring,2);
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,Charring]() {
                if (turn->side != Side::Enemy) return;
                if (enemyUnit[turn->num]->isDebuffEnd(Charring)) {
                    enemyUnit[turn->num]->debuffSingle({{Stats::VUL,AType::None,-(15.0 + 3 * superimpose)}});

                }
            }));
        };
    }
}