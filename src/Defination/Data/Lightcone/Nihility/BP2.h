#include "../include.h"
namespace Nihility_Lightcone{
    function<void(Ally *ptr)> BP2(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(1058,529,331);
            ptr->Light_cone.Name = "Holiday";
            ptr->setApplyBaseChance(100);
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::DMG][AType::None] += 12 + 4 * superimpose;
            }));
            
            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if(act->isSameUnit(ptr->getSubUnit())){
                    debuffEnemyTargetsApply(act->targetList,{{Stats::VUL,AType::None,8.5+1.5*superimpose}},ptr->getSubUnit(),"Holiday Vul",2);
                }
            }));


            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;

                if(enemy->isDebuffEnd("Holiday Vul")){
                    enemy->debuffSingle({{Stats::VUL,AType::None,-(8.5+1.5*superimpose)}});
                }
            }));
        };
    }
}