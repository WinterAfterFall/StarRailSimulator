#include "../include.h"

namespace Cipher{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);

    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(105,130,130,eidolon,ElementType::QUANTUM,Path::NIHILITY,"Cipher",UnitType::STANDARD);
        ptr->setAllyBaseStats(1087,660,509);

        //func


        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(170);
        if(ptr->eidolon>=2)
            ptr->setApplyBaseChance(120);
        ptr->setRelicMainStats(Stats::CD,Stats::FLAT_SPD,Stats::DMG,Stats::ATK_P);
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        

        AllyUnit *cph = ptr; 
        
        ptr->adjust["Cipher A2"] = 2;
        ptr->adjust["Cipher Ult Share"] = 1;
        ptr->adjust["Cipher Use Only BA"] = 1;

        
        function<void()> ba = [ptr,cph]() {
            genSkillPoint(cph,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Cipher BA",
            [ptr,cph](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,20);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };
        function<void()> skill = [ptr,cph]() {
            genSkillPoint(cph,-1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::BLAST,"Cipher Skill",
            [ptr,cph](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,30);
                for(auto &each : act->targetList){
                    if(debuffApply(cph,each,"Cipher Weaken",2)){
                        each->statsType[Stats::DMG_REDUCE][AType::NONE] += 10;
                    }
                }
                buffSingle(cph,{{Stats::ATK_P,AType::NONE,30}},"Cipher Skill",2);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,100,10)
            );
            act->addToActionBar();
        };
        
        
        ptr->turnFunc = [ptr,cph,ba,skill]() {
            if(CharCmd::usingSkill(ptr)&&!ptr->adjust["Cipher Use Only BA"])skill();
            else ba();
        };

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [cph](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::AOE,"Cipher Ult",
            [ptr,cph](shared_ptr<AllyAttackAction> &act){
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,120,10)
            );
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,40,20),
                DmgSrc(DmgSrcType::ATK,40,20),
                DmgSrc(DmgSrcType::ATK,40,20)
            );
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->atvStats->flatSpeed += 14;
            ptr->statsEachElement[Stats::DMG][ElementType::QUANTUM][AType::NONE] += 14.4;
            ptr->statsType[Stats::EHR][AType::NONE] += 10;
            ptr->statsType[Stats::CR][AType::NONE] += 25 * ptr->getAdjust("Cipher A2");

            // ptr->statsEachElement[Stats::DMG][ElementType::QUANTUM][AType::NONE] += 12;
            // ptr->statsType[Stats::CR][AType::NONE] += 4;
            // ptr->statsType[Stats::CD][AType::NONE] += 24;

            debuffAllEnemyMark({{Stats::VUL,AType::NONE,40}},ptr,"Cipher A6");
            // relic

            // substats
        }));

        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_LAST, ptr, [cph](CharUnit *ptr){
            if(turn->isSameName("Cipher"))cph->setBuffCheck("Cipher Fua",0);
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_LAST, ptr, [cph](CharUnit *ptr){
            auto enemy =  turn->canCastToEnemy();
            auto ally =  turn->canCastToAllyUnit();
            if(ally){
                if(isBuffEnd(ally,"Cipher Skill")){
                    buffSingle(ally,{{Stats::ATK_P,AType::NONE,-30}});
                }
                if(ptr->eidolon>=1&&isBuffEnd(ally,"Cipher E1"))
                    buffSingle(ally,{{Stats::ATK_P,AType::NONE,-80}});
            }
            if(enemy){
                if(isDebuffEnd(enemy,"Cipher Weaken")){
                    enemy->statsType[Stats::DMG_REDUCE][AType::NONE] -= 10;
                }
                if(ptr->eidolon>=2&&isDebuffEnd(enemy,"Cipher E2")){
                    debuffSingle(enemy,{{Stats::VUL,AType::NONE,-30}});
                }
            }
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_LAST, ptr, [cph](CharUnit *ptr){
                shared_ptr<AllyAttackAction> newAct = 
                make_shared<AllyAttackAction>(AType::TECHNIQUE,ptr,TraceType::AOE,"Cipher Tech",
                [ptr,cph](shared_ptr<AllyAttackAction> &act){
                    attack(act);
                });
                newAct->addDamageIns(
                    DmgSrc(DmgSrcType::ATK,100),
                    DmgSrc(DmgSrcType::ATK,100),
                    DmgSrc(DmgSrcType::ATK,100)
                );
                newAct->addToActionBar();
                dealDamage();
        }));

        beforeAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_ACTTACK,[ptr,cph](
            shared_ptr<AllyAttackAction> &act){
                if(ptr->eidolon>=2&&act->isSameName(cph)){
                    for(auto &each : act->targetList){
                        debuffSingleApply(cph,each,{{Stats::VUL,AType::NONE,30}},"Cipher E2",2);
                    }
                }
                if(act->isSameAction("Cipher",AType::SKILL)||act->isSameAction("Cipher",AType::ULT))
                    debuffApply(cph,enemyUnit[mainEnemyNum].get(),"Patron");

                if(!act->isSameName("Cipher")&&!cph->getBuffCheck("Cipher Fua")){
                    cph->setBuffCheck("Cipher Fua",1);
                    shared_ptr<AllyAttackAction> newAct = 
                    make_shared<AllyAttackAction>(AType::FUA,ptr,TraceType::SINGLE,"Cipher Fua",
                    [ptr,cph](shared_ptr<AllyAttackAction> &act){
                        increaseEnergy(ptr,5);

                        if(ptr->eidolon>=1)
                            buffSingle(cph,{{Stats::ATK_P,AType::NONE,80}},"Cipher E1",2);

                        buffSingle(cph,{{Stats::CD,AType::NONE,100}});
                        if(ptr->eidolon>=6)buffSingle(cph,{{Stats::DMG,AType::NONE,350}});
                        attack(act);
                        buffSingle(cph,{{Stats::CD,AType::NONE,-100}});
                        if(ptr->eidolon>=6)buffSingle(cph,{{Stats::DMG,AType::NONE,-350}});
                    });
                    newAct->addDamageIns(
                        DmgSrc(DmgSrcType::ATK,150,20)
                    );
                    newAct->addToActionBar();
                    dealDamage();
                }
            }));

            
            afterDealingDamageList.push_back(TriggerAfterDealDamage(PRIORITY_ACTTACK,[ptr,cph](
                shared_ptr<AllyAttackAction> &act, Enemy *target, double damage){
                    double percent = (target->targetType == EnemyType::MAIN)
                    ? (12 * (1 + 0.5 * ptr->adjust["Cipher A2"]))
                    : (8 * (1 + 0.5 * ptr->adjust["Cipher A2"]));
                    
                    if(ptr->eidolon>=6&&act->actionName=="Cipher Fua"){
                        percent += (16 * (1 + 0.5 * ptr->adjust["Cipher A2"]));
                    }
                    if(ptr->eidolon>=1)percent *= 1.5;
                    if(act->actionName=="Cipher Tech")percent *= 2;

                    for(int i=1;i<=ptr->getAdjust("Cipher Ult Share")&&i<=totalEnemy;i++){
                        calDamageNote(act,target,enemyUnit[i].get(),damage*percent/100,75.0/ptr->getAdjust("Cipher Ult Share"),"Cph True " + act->actionName);
                    }
                    calDamageNote(act,target,enemyUnit[mainEnemyNum].get(),damage*percent/100,25,"Cph True " + act->actionName);
                            

                    if(ptr->eidolon<6)return;
                    act->attacker->owner
                    ->buffNote["CipherNote" + target->getName()] += damage * percent/100 * 0.2;
                    if(act->actionName!="Cipher Ult")return;
                    
                    double totaldmg = 0;
                    for(int i=1;i<=totalAlly;i++){
                        for(int j=1;j<=totalEnemy;j++){
                            totaldmg = charUnit[i]->getBuffNote("CipherNote" + enemyUnit[j]->getName());
                            for(int k=1;k<=ptr->getAdjust("Cipher Ult Share")&&k<=totalEnemy;k++){
                                act->attacker = charUnit[i].get();
                                calDamageNote(act,enemyUnit[j].get(),enemyUnit[k].get(),totaldmg*0.75/ptr->getAdjust("Cipher Ult Share"),100,"Cph E6 " + act->attacker->getName());
                            }
                            calDamageNote(act,enemyUnit[j].get(),enemyUnit[mainEnemyNum].get(),totaldmg*0.25,100,"Cph E6 " + act->attacker->getName());
                            charUnit[i]->buffNote["CipherNote" + enemyUnit[j]->getName()] *= 0.2;
                        }  
                    }
                }));

            if(ptr->eidolon>=4)    
                whenAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_ACTTACK,[ptr,cph](
                shared_ptr<AllyAttackAction> &act){
                    for(auto &each : act->targetList){
                        if(each->getDebuff("Patron")){
                            shared_ptr<AllyAttackAction> newAct = make_shared<AllyAttackAction>(
                                AType::ADDTIONAL,cph,TraceType::SINGLE,"Cipher E4");
                            newAct->addDamageIns(DmgSrc(DmgSrcType::ATK,50));
                            attack(newAct);
                            break;
                        }
                    }
                }));
    }
}
