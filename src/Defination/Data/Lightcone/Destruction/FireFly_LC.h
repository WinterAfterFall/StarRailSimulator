#include "../include.h"
namespace Destruction_Lightcone{
    function<void(CharUnit *ptr)> FireFly_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1164,476,529);
            ptr->Light_cone.Name = "FireFly_LC";
            string debuffName = ptr->getName() + " FireFlyLC debuff";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,debuffName]() {
                ptr->Stats_type[Stats::BE][AType::None] += 50 + 10 * superimpose;
            }));
            
    
            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,debuffName](shared_ptr<AllyAttackAction> &act) {
                if (act->Attacker->Atv_stats->num != ptr->Atv_stats->num && act->Attacker->Atv_stats->side != Side::Ally) return;
                for(Enemy* &e :act->targetList){
                    debuffSingleApply(ptr,e,{
                        {Stats::VUL,AType::Break,20.0 + 4 * superimpose},
                        {Stats::SPD_P,AType::None,-20.0}
                    },debuffName,2);
                } 
            }));
    
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,debuffName]() {
                if (turn != nullptr && turn->side == Side::Enemy) {
                    if (isDebuffEnd(enemyUnit[turn->num].get(),debuffName)) {
                        debuffSingle(enemyUnit[turn->num].get(),{
                            {Stats::VUL,AType::Break,-20.0 - 4 * superimpose},
                            {Stats::SPD_P,AType::None,20.0}
                        });
                    }
                }
            }));
        };
    }

}
