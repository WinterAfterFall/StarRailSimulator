#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> Jiaoqiu_LC(int superimpose,bool isDot){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,582,529);
            ptr->lightCone.name = "Jiaoqiu_LC";
            string cornered = ptr->getName() + " Cornered";
            string unarmored = ptr->getName() + " Unarmored";
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::EHR][AType::NONE] += 50 + 10 * superimpose;
            }));
            
            beforeAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose,isDot,unarmored,cornered](shared_ptr<AllyAttackAction> &act) {
                if((act->isSameAction(AType::BA)||
                    act->isSameAction(AType::SKILL)||
                    act->isSameAction(AType::ULT))&&act->isSameOwnerName(ptr)){
                        for(auto &each : act->targetList){
                            if(isDot) debuffSingleApply(ptr,each,{{Stats::VUL,AType::NONE,20.0 + superimpose*4}},cornered,2);
                            else debuffSingleApply(ptr,each,{{Stats::VUL,AType::NONE,8.0 + superimpose*2}},unarmored,2);
                            
                        }
                    }
            }));

            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose,unarmored,cornered](CharUnit *ptr) {
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;

                if(isDebuffEnd(enemy,cornered)){
                    debuffSingle(enemy,{{Stats::VUL,AType::NONE,-(20.0 + superimpose*4)}});
                }
                if(isDebuffEnd(enemy,unarmored)){
                    debuffSingle(enemy,{{Stats::VUL,AType::NONE,-(8.0 + superimpose*2)}});
                }
            }));
    
        };
    }
}