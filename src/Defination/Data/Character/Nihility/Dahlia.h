#include "../include.h"

namespace Dahlia{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(96,130,130,eidolon,ElementType::FIRE,Path::NIHILITY,"Dahlia",UnitType::STANDARD);
        ptr->setAllyBaseStats(1087,679,606);

        //substats
        ptr->pushSubstats(Stats::BE);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(140);
        ptr->setApplyBaseChance(100);
        ptr->setRelicMainStats(Stats::EHR,Stats::SPD_P,Stats::ATK_P,Stats::BE);

        
        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        dahliaCheck = 1;
        #pragma region Ability

        function<void()> ba = [ptr]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Dahlia BA",
            [ptr](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ptr,1);
                increaseEnergy(ptr,20);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };

        function<void()> skill = [ptr]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::BLAST,"Dahlia Skill",
            [ptr](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ptr,-1);
                increaseEnergy(ptr,30);
                if(isHaveToAddBuff(ptr,"Dahlia Skill",3)){
                    ptr->setBuffNote("Dahlia A2",calculateBreakEffectForBuff(ptr,24) + 50);
                    buffAllAlly({{Stats::BREAK_EFF,AType::NONE,50}});
                    buffAllAlly({{Stats::BE,AType::TEMP,ptr->getBuffNote("Dahlia A2")},
                    {Stats::BE,AType::NONE,ptr->getBuffNote("Dahlia A2")}},"Dahlia A2",1);
                }
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,160,10),
                DmgSrc(DmgSrcType::ATK,160,10)
            );
            act->addToActionBar();
        };

        function<void()> fua = [ptr]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::FUA,ptr,TraceType::BOUNCE,"Dahlia Fua",
            [ptr](shared_ptr<AllyAttackAction> &act){
                if(ptr->getBuffCheck("Dahlia Fua SP"))ptr->setBuffCheck("Dahlia Fua SP",0);
                else genSkillPoint(ptr,1);  
                increaseEnergy(ptr,2);
                for(auto &each : act->targetList){
                    debuffSingleApply(ptr,each,{{Stats::VUL,AType::NONE,12}},"Dahlia E4",2);
                }
                attack(act);
                if(ptr->eidolon>=6){
                    actionForward(ptr->getAtvStats(),20);
                    actionForward(chooseAllyBuff(ptr)->getAtvStats(),20);
                }
            });
            if(ptr->eidolon>=4)act->addEnemyBounce(DmgSrc(DmgSrcType::ATK,30,3),10);
            else act->addEnemyBounce(DmgSrc(DmgSrcType::ATK,30,3),5);
            act->addToActionBar();
            dealDamage();
        };

        #pragma endregion
        ptr->turnFunc = [ptr,ba,skill]() {
            if(ptr->getBuffCheck("Dahlia Skill"))ba();
            else skill();

        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::BLAST,"Dahlia Ult",
            [ptr](shared_ptr<AllyAttackAction> &act){
                for(auto &each : act->targetList){
                    weaknessApply(ptr,each,{chooseCharacterBuff(ptr)->elementType},4);
                    debuffSingleApply(ptr,each,{{Stats::DEF_SHRED,AType::NONE,18}},"Wilt",4);
                }
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,300,20),
                DmgSrc(DmgSrcType::ATK,300,20),
                DmgSrc(DmgSrcType::ATK,300,20)
            );
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::BE][AType::NONE] += 37.3;
            ptr->statsType[Stats::RES][AType::NONE] += 18;
            ptr->atvStats->flatSpeed += 5;
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if(ptr->eidolon>=2)debuffAllEnemyApply(ptr,{{Stats::RESPEN,AType::NONE,20}},"Dahlia E2");
            if(ptr->eidolon>=6){
                buffSingle(ptr,{{Stats::BE,AType::NONE,150}});
                buffSingle(chooseAllyBuff(ptr),{{Stats::BE,AType::NONE,150}});
            }
        }));

        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if(isBuffEnd(ptr,"Dahlia Skill")){
                buffAllAlly({{Stats::BREAK_EFF,AType::NONE,-50}});
            }
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(isBuffEnd(ally,"Dahlia A2")){
                buffSingle(ally,{
                    {Stats::BE,AType::TEMP,-ptr->getBuffNote("Dahlia A2")},
                    {Stats::BE,AType::NONE,-ptr->getBuffNote("Dahlia A2")}});
                ptr->setBuffNote("Dahlia A2",0);

            }
        }));
        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            Enemy *enemy = turn->canCastToEnemy();
            if(!enemy)return;
            if(isDebuffEnd(enemy,"Wilt")){
                debuffSingle(enemy,{{Stats::DEF_SHRED,AType::NONE,-18}});
            }
            if(isDebuffEnd(enemy,"Dahlia E4")){
                debuffSingle(enemy,{{Stats::VUL,AType::NONE,-12}});
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(!ally)return;
            if(isBuffEnd(ally,"Dahlia A6")){
                buffSingle(ally,{{Stats::SPD_P,AType::NONE,-30}});
            }
        }));

        beforeAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_ACTTACK, [ptr,fua](shared_ptr<AllyAttackAction> &act){
            if(act->attacker->getBuffCheck("Dahlia A6")){
                for(auto &each1 : act->damageSplit){
                    for(auto &each : each1){
                        if(each.target->getDebuff("Dahlia A6"))continue;
                        each.dmgSrc.toughnessReduce += 20;
                        each.target->setDebuff("Dahlia A6",1);
                    }
                }
                for(auto &each : act->targetList){
                    each->setDebuff("Dahlia A6",0);
                }
            }
            if(ptr->eidolon>=1 && (act->isSameName(chooseCharacterBuff(ptr)) || act->isSameName(ptr))){
                for(auto &each1 : act->damageSplit){
                    for(auto &each : each1){
                        if(each.target->getDebuff("Dahlia E1"))continue;
                        each.dmgSrc.toughnessReduce += max(10.0,min(300.0,each.target->maxToughness*0.25));
                        each.target->setDebuff("Dahlia E1",1);
                    }
                }
            }
        }));

        afterActionList.push_back(TriggerByActionFunc(PRIORITY_ACTTACK, [ptr,fua](shared_ptr<ActionData> &act){
            for(auto &each : allyList){
                ptr->setBuffCheck("Dahlia A6",0);
            }
        }));

        afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_ACTTACK, [ptr,fua](shared_ptr<AllyAttackAction> &act){
            if(ptr->eidolon>=1){
                if(act->isSameName(chooseCharacterBuff(ptr))||act->isSameName(ptr))superbreakTrigger(act,100,"Dahlia");
                else superbreakTrigger(act,60,"Dahlia");
            }
            else if(act->isSameName(chooseCharacterBuff(ptr))||act->isSameName(ptr)) superbreakTrigger(act,60,"Dahlia");

            if(act->isSameAction(ptr,AType::FUA)){
                superbreakTrigger(act,200,"Dahlia");
            }
            if(act->isSameName(chooseCharacterBuff(ptr))){
                fua();
            }
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            increaseEnergy(ptr,35);
            if(ptr->technique){
                if(isHaveToAddBuff(ptr,"Dahlia Skill",3)){
                    ptr->setBuffNote("Dahlia A2",calculateBreakEffectForBuff(ptr,24) + 50);
                    buffAllAlly({{Stats::BREAK_EFF,AType::NONE,50}});
                    buffAllAlly({{Stats::BE,AType::TEMP,ptr->getBuffNote("Dahlia A2")},
                    {Stats::BE,AType::NONE,ptr->getBuffNote("Dahlia A2")}},"Dahlia A2",1);
                }
            }
            if(ptr->eidolon>=2){
                for(auto &each : enemyList){
                    weaknessApply(ptr,each,{chooseCharacterBuff(ptr)->elementType},3);
                    debuffSingleApply(ptr,each,{{Stats::DEF_SHRED,AType::NONE,18}},"Wilt",3);
                }
            }
        }));

        weaknessApplyList.push_back(TriggerByWeaknessApplyFunc(PRIORITY_IMMEDIATELY, [ptr](AllyUnit *trigger,Enemy *target, vector<ElementType> elementList) {
            buffSingle(ptr,{{Stats::SPD_P,AType::NONE,30}},"Dahlia A6",2);
            if(trigger->elementType == ElementType::FIRE){
                increaseEnergy(ptr,10,0);
                if(phaseStatus == PhaseStatus::WHILE_ACTION)ptr->setBuffCheck("Dahlia A6",1);
            }
        }));

    }
}
