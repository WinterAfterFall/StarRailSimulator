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


            // fired once per character that uses an Elation Skill (not only the first one in the Aha queue)
            whenUseElationSkillList.push_back(TriggerByAllyFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose,debuffName](CharUnit *ally) {
                if(ally!=ptr)return;
                debuffAllEnemyApply(ptr,{{Stats::VUL,AType::ELATION_DMG,5.0 + superimpose}},debuffName,2);
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
