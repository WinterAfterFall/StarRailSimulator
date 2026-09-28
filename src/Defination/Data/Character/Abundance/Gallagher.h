
#include "../include.h"

namespace Gallagher{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void basicAtk(CharUnit *ptr);
    void enchanceBasicAtk(CharUnit *ptr);
    void skillFunc(CharUnit *ptr);



    
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(98,110,110,eidolon,ElementType::FIRE,Path::ABUNDANCE,"Gallagher",UnitType::STANDARD);
        ptr->setAllyBaseStats(1305,529,441);

        //substats
        ptr->pushSubstats(Stats::BE);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(150);
        ptr->setRelicMainStats(Stats::HEALING_OUT,Stats::FLAT_SPD,Stats::ATK_P,Stats::ER);


        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        
        ptr->turnFunc = [ptr]() {
            if (ptr->atvStats->turnCnt % 8 == 1) {
                skillFunc(ptr);
            } else {
                if (ptr->buffCheck["Gallagher_enchance_basic_atk"] == 1) {
                    enchanceBasicAtk(ptr);
                } else {
                    basicAtk(ptr);
                }
            }
        };
        ptr->addUltCondition([ptr]() -> bool {
            return phaseStatus != PhaseStatus::BEFORE_TURN && ptr->atvStats->atv != 0;
        });

        ultimateList.push_back({PRIORITY_DEBUFF, ptr, [charPtr = ptr](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,charPtr,TraceType::AOE,"Gall Ult",
                [ptr,charPtr](shared_ptr<AllyAttackAction> &act){
                    actionForward(ptr->atvStats.get(), 100);
                    ptr->buffCheck["Gallagher_enchance_basic_atk"] = 1;
                    debuffAllEnemyApply(charPtr,{{Stats::VUL,AType::BREAK,13.2}},"Besotted");  
                    if (ptr->eidolon >= 4) {
                        extendDebuffAll("Besotted", 3);
                    } else {
                        extendDebuffAll("Besotted", 2);
                    }
                    attack(act);
                });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,165,20),
                DmgSrc(DmgSrcType::ATK,165,20),
                DmgSrc(DmgSrcType::ATK,165,20)
            );

            act->addToActionBar();
            if(!actionBarUse)dealDamage();
            if (ptr->print) CharCmd::printUltStart("Gallagher");
        }});

        resetList.push_back({PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::BE][AType::NONE] += 13.3;
            ptr->statsType[Stats::HP_P][AType::NONE] += 18;
            ptr->statsType[Stats::RES][AType::NONE] += 28;

            // relic

            // substats
            if (ptr->eidolon >= 1) {
                ptr->statsType[Stats::RES][AType::NONE] += 50;
            }
            if (ptr->eidolon >= 6) {
                ptr->statsType[Stats::BREAK_EFF][AType::NONE] += 20;
                ptr->statsType[Stats::BE][AType::NONE] += 20;
            }
        }});

        afterTurnList.push_back({PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            Enemy * focusUnit = turn->canCastToEnemy();
            if(!focusUnit)return;
            if (isDebuffEnd(focusUnit,"Besotted")) {
                debuffSingle(focusUnit,{{Stats::VUL, AType::BREAK, -13.2}});
            }
            if (isDebuffEnd(focusUnit,"Nectar_Blitz")) {
                focusUnit->statsType[Stats::ATK_REDUCE][AType::NONE] -= 16;
            }
        }});


        startGameList.push_back({PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if (ptr->eidolon >= 1) {
                increaseEnergy(ptr, 20);
            }
        }});

        whenOnFieldList.push_back({PRIORITY_IMMEDIATELY, ptr, [charPtr = ptr](CharUnit *ptr) {
            double temp = calculateBreakEffectForBuff(ptr,50);
            if(temp>75)temp = 75;
            buffSingle(charPtr,{{Stats::HEALING_OUT,AType::NONE,temp - charPtr->getBuffNote("Novel Concoction")}});
            ptr->buffNote["Novel Concoction"] = temp;
            if (ptr->technique) {
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::TECHNIQUE,charPtr,TraceType::AOE,"Gall Tech",
                [ptr,charPtr](shared_ptr<AllyAttackAction> &act){
                    debuffAllEnemyApply(charPtr,{{Stats::VUL, AType::BREAK, 13.2}},"Besotted",2);
                    attack(act);
                });
                act->addDamageIns(
                    DmgSrc(DmgSrcType::ATK,50,20),
                    DmgSrc(DmgSrcType::ATK,50,20),
                    DmgSrc(DmgSrcType::ATK,50,20)
                );
                act->addToActionBar();
                dealDamage();
            }
        }});

        whenAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_HEAL, [ptr](shared_ptr<AllyAttackAction> &act) {
            
            if(act->isSameAction("Gallagher",AType::BA)&&act->attacker->buffCheck["Gallagher_enchance_basic_atk"] == 1){
                ptr->buffCheck["Gallagher_enchance_basic_atk"] = 0;
                int cnt = 0;
                for (Enemy *e : act->targetList) {
                    if (e->getDebuff("Besotted")) {
                        cnt++;
                        
                    }
                }
                ptr->restoreHP(HealSrc(HealSrcType::CONST,707.0*cnt));
            } else {
                int cnt = 0;
                for (Enemy *e : act->targetList) {
                    if (e->getDebuff("Besotted")) {
                        cnt++;           
                    }
                }
                ptr->restoreHP(act->attacker,HealSrc(HealSrcType::CONST,707.0*cnt));
            }
        }));
        statsAdjustList.push_back(TriggerByStats(PRIORITY_HEAL, [ptr](AllyUnit* target, Stats statsType) {
            if(statsType!=Stats::BE||!target->isSameName("Gallagher"))return;

            double temp = calculateBreakEffectForBuff( ptr,50);
            if(temp>75)temp = 75;
            buffSingle(ptr,{{Stats::HEALING_OUT,AType::NONE,temp - ptr->buffNote["Novel Concoction"]}});
            ptr->buffNote["Novel Concoction"] = temp;
        }));

        

        //substats

        
    }



    void basicAtk(CharUnit *ptr){
        
        genSkillPoint(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Gall BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,20);
            attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,55,5));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,55,5));
        act->addToActionBar();
    }
    void enchanceBasicAtk(CharUnit *ptr){
        genSkillPoint(ptr,1);
       shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Gall EBA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,20);
            for(Enemy* &target : act->targetList){
                if(debuffApply(act->attacker,target,"Nectar_Blitz"))
                    target->statsType[Stats::ATK_REDUCE][AType::NONE] += 16;
                extendDebuff(target,"Nectar_Blitz",2);
            }
            attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,68.75,7.5));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,41.25,4.5));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,165,18));
        act->addToActionBar();

    }
    void skillFunc(CharUnit *ptr){
        genSkillPoint(ptr,-1);
        
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::SINGLE,"Gall Skill",
        [ptr](shared_ptr<AllyBuffAction> act){
            ptr->restoreHP(HealSrc(HealSrcType::CONST,1768),HealSrc(),HealSrc());
            increaseEnergy(ptr,30);
        });
        act->addBuffSingleTarget(chooseAllyBuff(ptr));
        act->addToActionBar();
    }
}