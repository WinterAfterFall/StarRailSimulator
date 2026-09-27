#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> Cipher_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,582,529);
            ptr->lightCone.name = "Cipher_LC";
            ptr->newApplyBaseChanceRequire(120);

            afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                if(!act->isSameOwnerName(ptr))return;
                debuffAllEnemyApply(ptr,{{Stats::DEF_SHRED,AType::NONE,14.0 + (superimpose * 2)}},"Bamboozle",2);
                double speed = ptr->atvStats->baseSpeed * (1 + ptr->atvStats->speedPercent / 100) + ptr->atvStats->flatSpeed;
                if(speed >= 170)
                debuffAllEnemyApply(ptr,{{Stats::DEF_SHRED,AType::NONE,7.0 + superimpose}},"Theft",2);
            }));

            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->atvStats->speedPercent += 15 + 3 * superimpose;
            }));

            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;
                if(isDebuffEnd(enemy,"Bamboozle")){
                    debuffSingle(enemy,{{Stats::DEF_SHRED,AType::NONE,-(14.0 + (superimpose * 2))}});
                }
                if(isDebuffEnd(enemy,"Theft")){
                    debuffSingle(enemy,{{Stats::DEF_SHRED,AType::NONE,-(7.0 + superimpose)}});
                }
            }));
        };
    }
}