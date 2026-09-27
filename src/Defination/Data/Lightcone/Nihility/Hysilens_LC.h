#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> Hysilens_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->setAllyBaseStats(953,635,463);
            ptr->lightCone.name = "Hysilens_LC";
            ptr->newApplyBaseChanceRequire(80);
            resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                ptr->statsType[Stats::EHR][AType::NONE] += 35 + 5 * superimpose;
            }));

            beforeAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                for(Enemy* &e : act->targetList){
                    if(!e->getDebuff("Hys LC Enthrallment"))continue;
                    buffSingle(act->attacker,{{Stats::SPD_P,AType::NONE,7.5 + 2.5*superimpose}},"Hys LC SPD",3);
                    return;
                }
            }));
            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [superimpose](CharUnit *ptr) {
                AllyUnit *ally = turn->canCastToAllyUnit();
                if(ally){
                    if(isBuffEnd(ally,"Hys LC SPD")){
                        buffSingle(ally,{{Stats::SPD_P,AType::NONE,-(7.5 + 2.5*superimpose)}});
                    }
                    return;
                }
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;
                if(isDebuffEnd(enemy,"Hys LC Enthrallment")){
                    if(enemy->getStack("Hys LC") > 0) enemy->addTotalDebuff(-1);
                    debuffStackRemove(enemy,{{Stats::VUL,AType::DOT,3.75 + 1.25 * superimpose}},"Hys LC");
                }
            }));

            beforeApplyDebuff.push_back(TriggerBySomeAllyFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](Enemy *target, AllyUnit *trigger) {
                if(ptr->getBuffCheck("Hys LC Stacking"))return;
                if(trigger->isSameName(ptr)){
                    target->setDebuffNote("Hys LC TotalDebuff",target->totalDebuff);
                }
            }));

            afterApplyDebuff.push_back(TriggerBySomeAllyFunc(PRIORITY_IMMEDIATELY, [ptr,superimpose](Enemy *target, AllyUnit *trigger) {
                // The VUL stack is itself a debuff apply; skip it so it does not count itself
                if(ptr->getBuffCheck("Hys LC Stacking"))return;
                if(!trigger->isSameName(ptr))return;
                int applied = target->totalDebuff - target->getDebuffNote("Hys LC TotalDebuff");
                if(applied <= 0)return;
                if(target->getDebuff("Hys LC Enthrallment")){
                    ptr->setBuffCheck("Hys LC Stacking",1);
                    debuffStackSingle(ptr,target,{{Stats::VUL,AType::DOT,3.75 + 1.25 * superimpose}},applied,6,"Hys LC");
                    ptr->setBuffCheck("Hys LC Stacking",0);
                    return;
                }
                // Enter Enthrallment without firing debuff events again (would recurse into this handler)
                target->setDebuff("Hys LC Enthrallment",1);
                target->addTotalDebuff(1);
                extendDebuff(target,"Hys LC Enthrallment",3);
            }));

        };
    }
}
