#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> Cipher_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,582,529);
            ptr->Light_cone.Name = "Cipher_LC";
            ptr->newApplyBaseChanceRequire(120);

            BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                debuffAllEnemyApply({{Stats::DEF_SHRED,AType::None,14.0 + (superimpose * 2)}},ptr,"Bamboozle",2);
                debuffAllEnemyApply({{Stats::DEF_SHRED,AType::None,7.0 + superimpose}},ptr,"Theft",2);
            }));

            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Atv_stats->speedPercent += 15 + 3 * superimpose;
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;
                if(isDebuffEnd(enemy,"Bamboozle")){
                    debuffSingle(enemy,{{Stats::DEF_SHRED,AType::None,-(14.0 + (superimpose * 2))}});
                }
                if(isDebuffEnd(enemy,"Theft")){
                    debuffSingle(enemy,{{Stats::DEF_SHRED,AType::None,-(7.0 + superimpose)}});
                }
            }));
        };
    }
}