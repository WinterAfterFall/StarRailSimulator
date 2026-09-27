#include "../include.h"
namespace Elation_Lightcone{
    function<void(CharUnit *ptr)> MushyShroomy(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(847,476,397);
            ptr->lightCone.name = "Mushy Shroomy's Adventures";
            string debuffName = ptr->getName() +  " MushyShroomy Debuff";
    
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::ELATION][AType::NONE] += 10 + superimpose * 2;
            }));


            beforeAllyActionList.push_back(TriggerByAllyActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose,debuffName](shared_ptr<AllyActionData> &act) {
                if(act->isSameAction(ptr,AType::ELATION_SKILL)){
                    debuffAllEnemyApply(ptr,{{Stats::VUL,AType::ELATION_DMG,5.0 + superimpose}},debuffName,2);
                }
            }));

            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose,debuffName](CharUnit *ptr) {
                Enemy* enemy = turn->canCastToEnemy();
                if(!enemy)return;
                if(isDebuffEnd(enemy,debuffName)){
                    debuffSingle(enemy,{{Stats::VUL,AType::ELATION_DMG,-5.0 - superimpose}});
                }
            }));

        };
    }
}
