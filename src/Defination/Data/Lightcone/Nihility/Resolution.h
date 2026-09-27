#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> Resolution(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,476,331);
            ptr->lightCone.name = "Resolution";
            string ensnared = ptr->getName() + " Ensnared";
            ptr->newApplyBaseChanceRequire(50 + superimpose*10);

            afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose,ensnared](shared_ptr<AllyAttackAction> &act) {
                if (!act->isSameOwnerName(ptr)) return;
                for (auto e : act->targetList) {
                    debuffSingleApply(ptr,e,{{Stats::DEF_SHRED,AType::NONE,11.0 + superimpose}},ensnared,1);
                }
            }));

            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose,ensnared](CharUnit *ptr) {
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;
                if(isDebuffEnd(enemy,ensnared)){
                    debuffSingle(enemy,{{Stats::DEF_SHRED,AType::NONE,-(11.0 + superimpose)}});
                }
            }));
        };
    }
}