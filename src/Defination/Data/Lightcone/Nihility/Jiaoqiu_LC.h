#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> Jiaoqiu_LC(int superimpose,bool isDot){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,582,529);
            ptr->Light_cone.Name = "Jiaoqiu_LC";
            string Cornered = ptr->getUnitName() + " Cornered";
            string Unarmored = ptr->getUnitName() + " Unarmored";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::EHR][AType::None] += 40 + 10 * superimpose;
            }));
            
            BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,isDot,Unarmored,Cornered](shared_ptr<AllyAttackAction> &act) {
                if((act->isSameAction(AType::BA)||
                    act->isSameAction(AType::SKILL)||
                    act->isSameAction(AType::Ult))&&act->isSameUnitName(ptr)){
                        for(auto &each : act->targetList){
                            if(isDot) debuffSingleApply(each,{{Stats::VUL,AType::None,20.0 + superimpose*4}},ptr,Cornered,2);
                            else debuffSingleApply(each,{{Stats::VUL,AType::None,8.0 + superimpose*2}},ptr,Unarmored,2);
                            
                        }
                    }
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,Unarmored,Cornered]() {
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;

                if(isDebuffEnd(enemy,Cornered)){
                    debuffSingle(enemy,{{Stats::VUL,AType::None,-(20.0 + superimpose*4)}});
                }
                if(isDebuffEnd(enemy,Unarmored)){
                    debuffSingle(enemy,{{Stats::VUL,AType::None,-(8.0 + superimpose*2)}});
                }
            }));
    
        };
    }
}