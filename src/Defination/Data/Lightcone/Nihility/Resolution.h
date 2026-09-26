#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> Resolution(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,476,331);
            ptr->Light_cone.Name = "Resolution";
            string ensnared = ptr->getName() + " Ensnared";
            ptr->newApplyBaseChanceRequire(50 + superimpose*10);

            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,ensnared](shared_ptr<AllyAttackAction> &act) {
                if (!act->isSameOwnerName(ptr)) return;
                for (auto e : act->targetList) {
                    debuffSingleApply(ptr,e,{{Stats::DEF_SHRED,AType::None,11.0 + superimpose}},ensnared,1);
                }
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,ensnared]() {
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;
                if(isDebuffEnd(enemy,ensnared)){
                    debuffSingle(enemy,{{Stats::DEF_SHRED,AType::None,-(11.0 + superimpose)}});
                }
            }));
        };
    }
}