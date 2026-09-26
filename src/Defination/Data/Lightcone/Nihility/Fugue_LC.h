#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> Fugue_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,582,529);
            ptr->Light_cone.Name = "Fugue_LC";
            string Charring = ptr->getName() + " Charring";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,Charring]() {
                ptr->Stats_type[Stats::BE][AType::None] += 50 + 10 * superimpose;
            }));
    
            Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,Charring](Enemy *target, AllyUnit *Breaker) {
                debuffStackSingle(ptr,target,{{Stats::VUL,AType::Break,15.0 + 3 * superimpose}},1,2,Charring,2);
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,Charring]() {
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;
                if (isDebuffEnd(enemy,Charring)) {
                    debuffStackRemove(enemy,{{Stats::VUL,AType::Break,15.0 + 3 * superimpose}},Charring);
                }
            }));
        };
    }
}