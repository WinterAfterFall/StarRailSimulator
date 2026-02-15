#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> BP2(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(1058,529,331);
            ptr->Light_cone.Name = "Holiday";
            ptr->newApplyBaseChanceRequire(100);
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::DMG][AType::None] += 12 + 4 * superimpose;
            }));
            
            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if(act->isSameCharName(ptr)){
                    debuffEnemyTargetsApply(ptr,act->targetList,{{Stats::VUL,AType::None,8.5+1.5*superimpose}},"Holiday Vul",2);
                }
            }));


            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;

                if(isDebuffEnd(enemy,"Holiday Vul")){
                    debuffSingle(enemy,{{Stats::VUL,AType::None,-(8.5+1.5*superimpose)}});
                }
            }));
        };
    }
}