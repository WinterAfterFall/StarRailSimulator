#include "../include.h"

namespace SW{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);

    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(107,110,110,eidolon,ElementType::QUANTUM,Path::NIHILITY,"SW",UnitType::STANDARD);
        ptr->setAllyBaseStats(1048,640,461);

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(140);
        ptr->setApplyBaseChance(100);
        ptr->setRelicMainStats(Stats::EHR,Stats::FLAT_SPD,Stats::DMG,Stats::ER);

        
        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        
        #pragma region Ability
        AllyUnit *sw = ptr;

        ptr->adjust["SW Targets amount"] = 1;
        
        function<void()> ba = [ptr,sw]() {
            genSkillPoint(sw,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"SW BA",
            [sw](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(sw,20);
                attack(act);
            });
            act->addDamageInsByDebuff(DmgSrc(DmgSrcType::ATK,25,2.5),"Bug 2");
            act->addDamageInsByDebuff(DmgSrc(DmgSrcType::ATK,25,2.5),"Bug 2");
            act->addDamageInsByDebuff(DmgSrc(DmgSrcType::ATK,50,5),"Bug 2");
            act->addToActionBar();
        };

        function<void()> skill = [ptr,sw]() {
            genSkillPoint(sw,-1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::SINGLE,"SW Skill",
            [sw](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(sw,30);
                for(auto &enemy : act->targetList){
                    for(int i=1;i<=totalAlly;i++){
                        if(enemy->defaultWeaknessType[charUnit[i]->elementType])continue;
                        weaknessApply(sw,enemy,{charUnit[i]->elementType},3);
                        debuffSingleApply(sw,enemy,{{Stats::RESPEN,charUnit[i]->elementType,AType::NONE,20}},"SW Weakness",3);
                        sw->setBuffNote("SW Weakness num",i);
                        break;
                    }
                    debuffSingleApply(sw,enemy,{{Stats::RESPEN,AType::NONE,13}},"SW Res",2);
                }
                attack(act);
            });
            act->addDamageInsByDebuff(DmgSrc(DmgSrcType::ATK,196,20),string("SW Res"),ptr->getAdjust("SW Targets amount"));
            act->addToActionBar();
        };

        #pragma endregion

        ptr->turnFunc = [ptr, allyPtr = ptr,ba,skill]() {
            for(int i = 1;i<= totalEnemy&&i<=ptr->adjust["SW Targets amount"];i++){
                if(!enemyUnit[i]->getDebuff("SW Res")){
                    skill();
                    return;
                }
            }
            ba();
        };
        
        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [sw](CharUnit *ptr) {

            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr,TraceType::AOE,"SW Ult",
            [ptr,sw](shared_ptr<AllyAttackAction> &act){
                debuffAllEnemyApply(sw,{
                    {Stats::DEF_SHRED,AType::NONE,45}
                },"SW Ult",3);
                attack(act);
                if(ptr->eidolon>=1){
                    int debuffcnt = 0;
                    for(auto &enemy : act->targetList){
                        debuffcnt += enemy->totalDebuff;
                    }
                    debuffcnt = (debuffcnt>=5) ? 5 : debuffcnt;
                    increaseEnergy(sw,7*debuffcnt);
                }
                if(ptr->eidolon>=4){
                    int debuffcnt = 0;
                    for(auto &enemy : act->targetList){
                        debuffcnt = (enemy->totalDebuff>=5) ? 5 : enemy->totalDebuff;
                        shared_ptr<AllyAttackAction> add = 
                        make_shared<AllyAttackAction>(AType::ADDTIONAL,ptr,TraceType::SINGLE,"SW AddDmg");
                            add->addDamageIns(DmgSrc(DmgSrcType::ATK,20*debuffcnt),enemy);  
                        attack(add);
                    }
                }
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,380,20),
                DmgSrc(DmgSrcType::ATK,380,20),
                DmgSrc(DmgSrcType::ATK,380,20)
            );
            act->addToActionBar();
            dealDamage();

        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsEachElement[Stats::DMG][ElementType::QUANTUM][AType::NONE] += 8;
            ptr->statsType[Stats::ATK_P][AType::NONE] += 28;
            ptr->statsType[Stats::EHR][AType::NONE] += 18;

            // relic

            // Trace
            ptr->statsType[Stats::ATK_P][AType::NONE] += 50;

            if(ptr->eidolon>=6){
            ptr->statsType[Stats::DMG][AType::NONE] += 100;
            }

        }));
               
        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [sw](CharUnit *ptr) {

            if(turn->isSameUnit(sw)){
                increaseEnergy(sw,5);
            }
        }));


        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [sw](CharUnit *ptr) {
            Enemy *enemy = turn->canCastToEnemy();
            if(enemy){
                if(isDebuffEnd(enemy,"SW Weakness")){
                    debuffSingle(enemy,{{Stats::RESPEN,charUnit[sw->getBuffNote("SW Weakness num")]->elementType,AType::NONE,-20}});
                }
                if(isDebuffEnd(enemy,"SW Res")){
                    debuffSingle(enemy,{{Stats::RESPEN,AType::NONE,-13}});
                }
                if(isDebuffEnd(enemy,"SW Ult")){
                    debuffSingle(enemy,{{Stats::DEF_SHRED,AType::NONE,-45}});
                }
                isDebuffEnd(enemy,"Bug 1");
                if(isDebuffEnd(enemy,"Bug 2")){
                    debuffSingle(enemy,{{Stats::DEF_SHRED,AType::NONE,-12}});
                }
                if(isDebuffEnd(enemy,"Bug 3")){
                    enemy->atkPercent+=10;
                    debuffSingle(enemy,{{Stats::SPD_P,AType::NONE,6}});
                }

            }
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [sw](CharUnit *ptr) {
            
            if(ptr->technique){
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::TECHNIQUE,ptr,TraceType::AOE,"SW Technique",
                [sw](shared_ptr<AllyAttackAction> &act){
                    attack(act);
                });
                act->addDamageIns(
                    DmgSrc(DmgSrcType::ATK,80,20),
                    DmgSrc(DmgSrcType::ATK,80,20),
                    DmgSrc(DmgSrcType::ATK,80,20)
                );
                act->dontCareWeakness = 100;
                act->addToActionBar();
                dealDamage();
            }
            increaseEnergy(sw,20);

            if(ptr->eidolon>=2){
                debuffAllEnemyMark({{Stats::VUL,AType::NONE,20}},sw,"SW E2");
            }
        }));

        whenAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,sw](shared_ptr<AllyAttackAction> &act) {
            if(ptr->eidolon>=2||act->isSameName(sw)){
                for(auto &enemy : act->targetList){
                    if(!enemy->getDebuff("Bug 1")){
                        debuffApply(sw,enemy,"Bug 1",4);
                    }
                    else if(!enemy->getDebuff("Bug 2")){
                        debuffSingleApply(sw,enemy,{{Stats::DEF_SHRED,AType::NONE,12}},"Bug 2",4);
                    }
                    else {
                        debuffApply(sw,enemy,"Bug 1",4);
                        debuffSingleApply(sw,enemy,{{Stats::DEF_SHRED,AType::NONE,12}},"Bug 2",4);
                        if(debuffApply(sw,enemy,"Bug 3",4)){
                            enemy->atkPercent-=10;
                            debuffSingle(enemy,{{Stats::SPD_P,AType::NONE,-6}});
                        }
                    }
                }
            }
        }));

        toughnessBreakList.push_back(TriggerBySomeAllyFunc(PRIORITY_IMMEDIATELY, [ptr,sw](Enemy *target, AllyUnit *trigger) {
                if(!target->getDebuff("Bug 1")){
                    debuffApply(sw,target,"Bug 1",4);
                }
                else if(!target->getDebuff("Bug 2")){
                    debuffSingleApply(sw,target,{{Stats::DEF_SHRED,AType::NONE,12}},"Bug 2",4);
                }
                else {
                    debuffApply(sw,target,"Bug 1",4);
                    debuffSingleApply(sw,target,{{Stats::DEF_SHRED,AType::NONE,12}},"Bug 2",4);
                    if(debuffApply(sw,target,"Bug 3",4)){
                        target->atkPercent-=10;
                        debuffSingle(target,{{Stats::SPD_P,AType::NONE,-6}});
                    }
                }
        }));
    }
}
