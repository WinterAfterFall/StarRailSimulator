#include "../include.h"
namespace Nihility_Lightcone{
    function<void(Ally *ptr)> Jiaoqiu_LC(int superimpose,bool isDot){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,582,529);
            ptr->Light_cone.Name = "Jiaoqiu_LC";
            string Cornered = ptr->getSubUnit()->getUnitName() + " Cornered";
            string Unarmored = ptr->getSubUnit()->getUnitName() + " Unarmored";
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Sub_Unit_ptr[0]->Stats_type[Stats::EHR][AType::None] += 40 + 10 * superimpose;
            }));
            
            AfterAttackActionList.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,isDot,Unarmored,Cornered](shared_ptr<AllyAttackAction> &act) {
                if((act->isSameAction(AType::BA)||
                    act->isSameAction(AType::SKILL)||
                    act->isSameAction(AType::Ult))&&act->isSameUnit(ptr->getSubUnit())){
                        for(auto &each : act->targetList){
                            if(isDot) each->debuffSingleApply({{Stats::VUL,AType::None,20.0 + superimpose*4}},ptr->getSubUnit(),Cornered,2);
                            else each->debuffSingleApply({{Stats::VUL,AType::None,8.0 + superimpose*2}},ptr->getSubUnit(),Unarmored,2);
                            
                        }
                    }
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose,Unarmored,Cornered]() {
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;

                if(enemy->isDebuffEnd(Cornered)){
                    enemy->debuffSingle({{Stats::VUL,AType::None,-(20.0 + superimpose*4)}});
                }
                if(enemy->isDebuffEnd(Unarmored)){
                    enemy->debuffSingle({{Stats::VUL,AType::None,-(8.0 + superimpose*2)}});
                }
            }));
    
        };
    }
}