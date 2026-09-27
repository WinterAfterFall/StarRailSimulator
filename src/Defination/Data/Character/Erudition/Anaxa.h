
#include "../include.h"

namespace  Anaxa{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void basicAtk(CharUnit *ptr);
    void skill(CharUnit *ptr);
    void anaxaDebuff(CharUnit *ptr, Enemy *enemy);


//temp


    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(97,140,140,eidolon,ElementType::WIND,Path::ERUDITION,"Anaxa",UnitType::STANDARD);
        ptr->setAllyBaseStats(970,757,558);
        AllyUnit *anaxaPtr = ptr;


        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(135);
        ptr->setRelicMainStats(Stats::CR,Stats::FLAT_SPD,Stats::ATK_P,Stats::ATK_P);



        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->turnFunc = [ptr, allyPtr = ptr]() {
            allyPtr->setBuffCheck("AnaxaTalent",true);
            if (sp>spSafety||turn->turnCnt==1) {
                skill(ptr);
            } else {
                basicAtk(ptr);
            }
        };
        // ptr->addUltCondition([ptr,Anaxaptr]() -> bool {
        //     AllyUnit *Driverptr = Ally_unit[driverNum].get();
        //     if(Anaxaptr->atvStats->atv - Anaxaptr->atvStats->maxAtv*0.25 > Driverptr->atvStats->atv&&Anaxaptr->atvStats->atv!=0)
        //     return false;
        //     return true;
        // });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_ACTTACK, ptr, [anaxaPtr](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,anaxaPtr,TraceType::AOE,"Anaxa Ult",
            [ptr,anaxaPtr](shared_ptr<AllyAttackAction> &act){
                if(ptr->print)CharCmd::printUltStart("Anaxa");
                for(auto &each : act->targetList){
                    debuffApply(anaxaPtr,each,"Sublimation",1);
                    weaknessApply(ptr,each,{ElementType::FIRE,ElementType::ICE,ElementType::LIGHTNING,ElementType::WIND,ElementType::QUANTUM,ElementType::IMAGINARY,ElementType::PHYSICAL},"Sublimation",1);
                }
                for(auto &each : act->targetList){
                    each->debuffNote["AnaxaA6"] = each->currentWeaknessElementAmount*4;
                    debuffSingle(each,{{Stats::DEF_SHRED,AType::NONE,each->debuffNote["AnaxaA6"]}});
                    if(each->currentWeaknessElementAmount>=5){
                        each->debuffNote["AnaxaDmgBonus"] = 30;
                        debuffSingle(each,{{Stats::DMG,AType::NONE,30}});
                    }
                }
    
                attack(act);
    
                for(auto &each : act->targetList){
                    debuffSingle(each,{{Stats::DEF_SHRED,AType::NONE, -each->debuffNote["AnaxaA6"]}});
                    debuffSingle(each,{{Stats::DMG,AType::NONE, -each->debuffNote["AnaxaDmgBonus"]}});
                    each->debuffNote["AnaxaDmgBonus"] = 0;
                    each->debuffNote["AnaxaA6"] = 0;
                }
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,160,20),
                DmgSrc(DmgSrcType::ATK,160,20),
                DmgSrc(DmgSrcType::ATK,160,20)
            );
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [anaxaPtr](CharUnit *ptr) {
            ptr->statsType[Stats::CR][AType::NONE] += 12;
            ptr->statsType[Stats::HP_P][AType::NONE] += 10;
            ptr->statsEachElement[Stats::DMG][ElementType::WIND][AType::NONE] += 22.4;

            ptr->statsType[Stats::DMG][AType::NONE] += 30;
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [anaxaPtr](CharUnit *ptr) {
            if(!ptr->adjust["AnaxaA4"]){
                int cnt = 0;
                for(int i=1; i<=totalAlly;i++){
                    if(charUnit[i]->path==Path::ERUDITION)
                    cnt++;
                    
                }
                if(cnt>=2)ptr->adjust["AnaxaA4"] = 2;
                else ptr->adjust["AnaxaA4"] = 1;
            }
            if(ptr->eidolon>=6){
                buffAllAlly({{Stats::DMG,AType::NONE,50}});
                ptr->statsType[Stats::CD][AType::NONE] += 140;
                
            }else if(ptr->adjust["AnaxaA4"]==2){
                buffAllAlly({{Stats::DMG,AType::NONE,50}});
            }else if(ptr->adjust["AnaxaA4"]==1){
                ptr->statsType[Stats::CD][AType::NONE] += 140;
            }
        }));


        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [anaxaPtr](CharUnit *ptr) {
            buffStackSingle(ptr,{{Stats::DEF_SHRED,AType::NONE,4}},3,7,"Qualitative Shift");
            for(auto &each : enemyList){
                anaxaDebuff(ptr,each);
                if(ptr->eidolon>=2){
                    anaxaDebuff(ptr,each);
                    debuffSingleMark(ptr,each,{{Stats::RESPEN,AType::NONE,20}},"AnaxaE2");
                }
                
            }
        }));

        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [anaxaPtr](CharUnit *ptr) {
            Enemy *enemy = turn->canCastToEnemy();
            if(enemy){
            isDebuffEnd(enemy,"Sublimation");
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [anaxaPtr](CharUnit *ptr) {
            Enemy *enemy = turn->canCastToEnemy();
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(enemy){
                for(auto &e : enemyWeak){
                    isDebuffEnd(enemy,"AnaxaTalent " + toString(e.first) );
                }
                if(isDebuffEnd(enemy,"AnaxaE1")){
                    debuffSingle(enemy,{{Stats::DEF_SHRED,AType::NONE,-16}});
                }
            }
            if(ally){
                if(isBuffEnd(ally,"AnaxaE4")){
                    buffResetStack(ally,{{Stats::ATK_P,AType::NONE,30}},"AnaxaE4");
                }
            }
        }));

        beforeAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,anaxaPtr](shared_ptr<AllyAttackAction> &act) {
            if(act->attacker->isSameName("Anaxa")){
                if(ptr->eidolon>=6){
                    for(auto &each1 : act->damageSplit){
                        for(auto &each2 : each1){
                            each2.dmgSrc.atk *=1.3;
                            each2.dmgSrc.hp *=1.3;
                            each2.dmgSrc.def *=1.3;
                            each2.dmgSrc.constDmg *=1.3;
                        }
                    }
                }
            }

        }));

        afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,anaxaPtr](shared_ptr<AllyAttackAction> &act) {
            if((act->actionName=="Anaxa BA"||act->actionName=="Anaxa Skill")){
                if(anaxaPtr->getBuffCheck("AnaxaTalent"))
                for(auto &each : act->targetList){
                    skill(ptr);
                    if(each->currentWeaknessElementAmount>=5){
                        dealDamage();
                        anaxaPtr->setBuffCheck("AnaxaTalent",false);
                        break;
                    }
                }
                else anaxaPtr->setBuffCheck("AnaxaTalent",true);
            }
        }));
    }




    void basicAtk(CharUnit *ptr){
        
        genSkillPoint(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Anaxa BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(charUnit[ptr->atvStats->num].get(),30);
            for(auto &each : act->targetList){
                anaxaDebuff(ptr,each);
            }

            for(auto &each : act->targetList){
                each->debuffNote["AnaxaA6"] = each->currentWeaknessElementAmount*4;
                debuffSingle(each,{{Stats::DEF_SHRED,AType::NONE,each->debuffNote["AnaxaA6"]}});
                if(each->currentWeaknessElementAmount>=5){
                    each->debuffNote["AnaxaDmgBonus"] = 30;
                    debuffSingle(each,{{Stats::DMG,AType::NONE,30}});
                }
            }

            attack(act);

            for(auto &each : act->targetList){
                debuffSingle(each,{{Stats::DEF_SHRED,AType::NONE, -each->debuffNote["AnaxaA6"]}});
                debuffSingle(each,{{Stats::DMG,AType::NONE, -each->debuffNote["AnaxaDmgBonus"]}});
                each->debuffNote["AnaxaDmgBonus"] = 0;
                each->debuffNote["AnaxaA6"] = 0;
            }
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,100,10)
        );
        act->addToActionBar();
    }
    void skill(CharUnit *ptr){

        genSkillPoint(ptr,-1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::BOUNCE,"Anaxa Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(charUnit[ptr->atvStats->num].get(),30);
            if(!ptr->getBuffCheck("AnaxaFirstTurn")){
                ptr->setBuffCheck("AnaxaFirstTurn",true);
                increaseEnergy(ptr,30);
                if(ptr->eidolon>=1){
                    genSkillPoint(ptr,1);
                }
            }

            buffSingle(act->attacker,{{Stats::DMG,AType::NONE,20.0 * totalEnemy}});
            if(ptr->eidolon>=4)buffStackSingle(act->attacker,{{Stats::ATK_P,AType::NONE,30}},1,2,"AnaxaE4",2);
            int cnt = 5;
            while(1){
                for(auto &each : act->targetList){
                    anaxaDebuff(ptr,each);
                    --cnt;
                    if(ptr->eidolon>=1)debuffSingleApply(ptr,each,{{Stats::DEF_SHRED,AType::NONE,16}},"AnaxaE1",2);
                    if(cnt==0)break;
                }
                if(cnt==0)break;    
            }
            
            for(auto &each : act->targetList){
                each->debuffNote["AnaxaA6"] = each->currentWeaknessElementAmount*4;
                debuffSingle(each,{{Stats::DEF_SHRED,AType::NONE,each->debuffNote["AnaxaA6"]}});
                if(each->currentWeaknessElementAmount>=5){
                    each->debuffNote["AnaxaDmgBonus"] = 30;
                    debuffSingle(each,{{Stats::DMG,AType::NONE,30}});
                }
            }
            CharCmd::printText("Anaxa Skill");
            attack(act);

            for(auto &each : act->targetList){
                debuffSingle(each,{{Stats::DEF_SHRED,AType::NONE, -each->debuffNote["AnaxaA6"]}});
                debuffSingle(each,{{Stats::DMG,AType::NONE, -each->debuffNote["AnaxaDmgBonus"]}});
                each->debuffNote["AnaxaDmgBonus"] = 0;
                each->debuffNote["AnaxaA6"] = 0;
            }
            buffSingle(act->attacker,{{Stats::DMG,AType::NONE,-20.0 * totalEnemy}});
        });
        act->addEnemyFairBounce(DmgSrc(DmgSrcType::ATK,70,10),5);
        act->addToActionBar();
    }
    void anaxaDebuff(CharUnit *ptr, Enemy *enemy) {
        string element;
        weaknessApplyChoose(ptr,enemy,1,"AnaxaTalent",3);
    }
    

}