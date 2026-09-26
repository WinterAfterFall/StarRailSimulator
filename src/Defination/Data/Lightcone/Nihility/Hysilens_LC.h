#include "../include.h"
namespace Nihility_Lightcone{
    function<void(CharUnit *ptr)> Hysilens_LC(int superimpose){
        return [=](CharUnit *ptr) {
            ptr->SetAllyBaseStats(953,635,463);
            ptr->Light_cone.Name = "Hysilens_LC";
            ptr->newApplyBaseChanceRequire(80);
            Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                ptr->Stats_type[Stats::EHR][AType::None] += 35 + 5 * superimpose;
            }));

            BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](shared_ptr<AllyAttackAction> &act) {
                for(Enemy* &e : act->targetList){
                    if(!e->getDebuff("Hys LC Enthrallment"))continue;
                    buffSingle(act->Attacker,{{Stats::SPD_P,AType::None,7.5 + 2.5*superimpose}},"Hys LC SPD",3);
                    return;
                }
            }));
            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose]() {
                AllyUnit *ally = turn->canCastToAllyUnit();
                if(ally){
                    if(isBuffEnd(ally,"Hys LC SPD")){
                        buffSingle(ally,{{Stats::SPD_P,AType::None,-(7.5 + 2.5*superimpose)}});
                    }
                    return;
                }
                Enemy *enemy = turn->canCastToEnemy();
                if(!enemy)return;
                if(isDebuffEnd(enemy,"Hys LC Enthrallment")){
                    if(enemy->getStack("Hys LC") > 0) enemy->addTotalDebuff(-1);
                    debuffStackRemove(enemy,{{Stats::VUL,AType::Dot,3.75 + 1.25 * superimpose}},"Hys LC");
                }
            }));

            BeforeApplyDebuff.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](Enemy *target, AllyUnit *Trigger) {
                if(ptr->getBuffCheck("Hys LC Stacking"))return;
                if(Trigger->isSameName(ptr)){
                    target->setDebuffNote("Hys LC TotalDebuff",target->Total_debuff);
                }
            }));

            AfterApplyDebuff.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr,superimpose](Enemy *target, AllyUnit *Trigger) {
                // The VUL stack is itself a debuff apply; skip it so it does not count itself
                if(ptr->getBuffCheck("Hys LC Stacking"))return;
                if(!Trigger->isSameName(ptr))return;
                int applied = target->Total_debuff - target->getDebuffNote("Hys LC TotalDebuff");
                if(applied <= 0)return;
                if(target->getDebuff("Hys LC Enthrallment")){
                    ptr->setBuffCheck("Hys LC Stacking",1);
                    debuffStackSingle(ptr,target,{{Stats::VUL,AType::Dot,3.75 + 1.25 * superimpose}},applied,6,"Hys LC");
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
