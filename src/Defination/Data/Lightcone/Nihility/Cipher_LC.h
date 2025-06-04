#include "../include.h"
namespace Nihility_Lightcone{
    function<void(Ally *ptr)> Cipher_LC(int superimpose){
        return [=](Ally *ptr) {
            ptr->SetAllyBaseStats(953,582,529);
            ptr->Light_cone.Name = "Cipher_LC";
            ptr->newEhrRequire(120);

            Before_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                for(auto &each : act->targetList){
                    each->debuffSingleApply({{ST_DEF_SHRED,AT_NONE,14.0 + (superimpose * 2)}},ptr->getSubUnit(),"Bamboozle",2);
                    each->debuffSingleApply({{ST_DEF_SHRED,AT_NONE,7.0 + superimpose}},ptr->getSubUnit(),"Theft",2);
                }

            }));

            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->getSubUnit()->Atv_stats->speedPercent += 15 + 3 * superimpose;
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;
                if(enemy->isDebuffEnd("Bamboozle")){
                    enemy->debuffSingle({{ST_DEF_SHRED,AT_NONE,-(14.0 + (superimpose * 2))}});
                }
                if(enemy->isDebuffEnd("Theft")){
                    enemy->debuffSingle({{ST_DEF_SHRED,AT_NONE,-(7.0 + superimpose)}});
                }
            }));
        };
    }
}