#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> BP2(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(1058,529,331);
            ptr->lightCone.name = "Holiday";
            ptr->newApplyBaseChanceRequire(100);
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::DMG][AType::NONE] += 12 + 4 * superimpose;
            }));
            
            afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if(act->isSameOwnerName(ptr)){
                    debuffEnemyTargetsApply(ptr,act->targetList,{{Stats::VUL,AType::NONE,8.5+1.5*superimpose}},"Holiday Vul",2);
                }
            }));


            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;

                if(isDebuffEnd(enemy,"Holiday Vul")){
                    debuffSingle(enemy,{{Stats::VUL,AType::NONE,-(8.5+1.5*superimpose)}});
                }
            }));
        };
    }
}