#include "../include.h"

namespace Aglaea{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);

//temp
    void basicAtk(CharUnit *ptr);
    void skill(CharUnit *ptr);
    void memoSkill(CharUnit *ptr);
    void enchanceBasicAtk(CharUnit *ptr);
    void summon(CharUnit *ptr);


    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(102,350,350,eidolon,ElementType::LIGHTNING,Path::REMEMBRANCE,"Aglaea",UnitType::STANDARD);
        AllyUnit *agPtr = ptr;
        ptr->setAllyBaseStats(1242,699,485);
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        setMemoStats(ptr,720,66,0,35,ElementType::LIGHTNING,"Garmentmaker",UnitType::STANDARD);
        setCountdownStats(ptr,100,"Supreme_Stance");

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        // ptr->setSpeedRequire(135);
        ptr->setRelicMainStats(Stats::CR,Stats::ATK_P,Stats::DMG,Stats::ER);




        //func
        
        ptr->turnFunc = [ptr, allyPtr = ptr]() {
            if (ptr->getMemosprite()->isDeath()) {
                skill(ptr);
                return;
            }

            if (ptr->countdownList[0]->isDeath()) {
                basicAtk(ptr);
            } else {
                enchanceBasicAtk(ptr);
            }
        };
        ptr->addUltCondition([ptr,agPtr]() -> bool {
            if (ptr->countdownList[0]->isDeath() && 
                (ptr->countdownList[0]->atv > ptr->atvStats->atv && 
                (ptr->atvStats->atv != ptr->atvStats->maxAtv))) return false;
            if (ptr->memosprite->atvStats->atv == 0 || ptr->atvStats->atv == 0) return false;
            return true;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [agPtr](CharUnit *ptr) {

            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::ULT,ptr,TraceType::SINGLE,"AG Ult",
            [ptr,agPtr](shared_ptr<AllyBuffAction> &act){
                if (ptr->memosprite->isDeath()) summon(ptr);

                if (ptr->countdownList[0]->isDeath())
                buffSingle(agPtr,{{Stats::SPD_P, AType::NONE, 15.0 * ptr->memosprite->stack["Brewed_by_Tears"]}});

                actionForward(ptr->atvStats.get(), 100);
                ptr->countdownList[0]->summon();
                double buffValue = calculateSpeedForBuff(ptr, 360) +
                calculateSpeedForBuff(ptr->memosprite.get(), 720);

                buffSingleChar(ptr,{{Stats::FLAT_ATK, AType::TEMP, buffValue - ptr->buffNote["Aglaea_A2"]}});
                buffSingleChar(ptr,{{Stats::FLAT_ATK, AType::NONE, buffValue - ptr->buffNote["Aglaea_A2"]}});
                ptr->buffNote["Aglaea_A2"] =  buffValue;
                if (ptr->print) CharCmd::printUltStart("Aglaea");
            });
            act->addBuffSingleTarget(ptr);
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [agPtr](CharUnit *ptr) {
            ptr->statsType[Stats::DEF_P][AType::NONE] += 12.5;
            ptr->statsType[Stats::CR][AType::NONE] += 12;
            ptr->statsEachElement[Stats::DMG][ElementType::LIGHTNING][AType::NONE] += 22.4;
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [agPtr](CharUnit *ptr) {
            if (ptr->technique == 1) {
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::TECHNIQUE,ptr,TraceType::AOE,"AG Tech",
                [ptr](shared_ptr<AllyAttackAction> &act){
                    increaseEnergy(ptr, 30);
                    summon(ptr);
                    attack(act);
                });
                act->addDamageIns(
                    DmgSrc(DmgSrcType::ATK, 100, 20),
                    DmgSrc(DmgSrcType::ATK, 100, 20),
                    DmgSrc(DmgSrcType::ATK, 100, 20)
                );
                act->addToActionBar();
                dealDamage();
            }
        }));

        whenAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_ACTTACK, [ptr,agPtr](shared_ptr<AllyAttackAction> &act) {
            if (act->attacker->atvStats->name == "Garmentmaker") {
                if (act->attacker->stack["Brewed_by_Tears"] < 6) {
                    buffSingle(act->attacker,{{Stats::FLAT_SPD, AType::NONE, 55.0}});
                    act->attacker->stack["Brewed_by_Tears"]++;
                    if (!ptr->countdownList[0]->isDeath()) {
                        buffSingle(agPtr,{{Stats::SPD_P, AType::NONE, 15.0}});
                    }
                }
            }
            if (act->attacker->isSameName("Aglaea")) {
                if (debuffApply(ptr,enemyUnit[mainEnemyNum].get(),"Seam_Stitch")) {
                    if (ptr->eidolon >= 1) {
                        debuffSingle(enemyUnit[mainEnemyNum].get(),{{Stats::VUL, AType::NONE, 15}});
                    }
                }
            }
            if (act->attacker->atvStats->num == ptr->atvStats->num) {
                shared_ptr<AllyAttackAction> dataAdditional = 
                make_shared<AllyAttackAction>(AType::ADDTIONAL,ptr,TraceType::SINGLE,"AG AddDmg");
                dataAdditional->addDamageIns(DmgSrc(DmgSrcType::ATK,30));
                attack(dataAdditional);
                if (ptr->eidolon >= 1) {
                    increaseEnergy(ptr, 20);
                }
            }
        }));

        beforeAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,agPtr](shared_ptr<AllyAttackAction> &act) {
            if (ptr->eidolon >= 2) {
                if (act->attacker->atvStats->name == "Aglaea" || act->attacker->atvStats->name == "Garmentmaker") {
                    buffStackChar(ptr,{{Stats::DEF_SHRED,AType::NONE,14}},1,3,"Aglaea_E2");
                } else {
                    buffCharResetStack(ptr,{{Stats::DEF_SHRED,AType::NONE,14}},"Aglaea_E2");
                }
            }
        }));

        buffList.push_back(TriggerByAllyBuffActionFunc(PRIORITY_IMMEDIATELY, [ptr,agPtr](shared_ptr<AllyBuffAction> &act) {
            if (ptr->eidolon >= 2) {
                if (act->attacker->atvStats->name == "Aglaea" || act->attacker->atvStats->name == "Garmentmaker") {
                    buffStackChar(ptr,{{Stats::DEF_SHRED,AType::NONE,14}},1,3,"Aglaea_E2");
                } else {
                    buffCharResetStack(ptr,{{Stats::DEF_SHRED,AType::NONE,14}},"Aglaea_E2");
                }
            }
        }));

        statsAdjustList.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,agPtr](AllyUnit *target, Stats statsType) {
            if (target->atvStats->name != "Aglaea") return;
            if (ptr->countdownList[0]->isDeath()) return;
            if (statsType == Stats::FLAT_SPD||statsType == Stats::SPD_P) {
                // adjust
                double buffValue = calculateSpeedForBuff(ptr, 360) + 
                calculateSpeedForBuff(ptr->memosprite.get(), 720);

                buffSingleChar(ptr,{{Stats::FLAT_ATK, AType::TEMP, buffValue - ptr->buffNote["Aglaea_A2"]}});
                buffSingleChar(ptr,{{Stats::FLAT_ATK, AType::NONE, buffValue - ptr->buffNote["Aglaea_A2"]}});
                ptr->buffNote["Aglaea_A2"] =  buffValue;
                return;
            }
        }));

        
        ptr->memosprite->turnFunc = [ptr,agPtr](){
        
            memoSkill(ptr);
            
        };

        ptr->countdownList[0]->turnFunc = [ptr,agPtr](){
            buffSingle(agPtr,{{Stats::SPD_P, AType::NONE, -15.0 * ptr->memosprite->stack["Brewed_by_Tears"]}});
            
            ptr->countdownList[0]->death();
            
            buffSingleChar(ptr,{{Stats::FLAT_ATK, AType::TEMP,-ptr->buffNote["Aglaea_A2"]}});
            buffSingleChar(ptr,{{Stats::FLAT_ATK, AType::NONE,-ptr->buffNote["Aglaea_A2"]}});
    
            ptr->buffNote["Aglaea_A2"] = 0;
            ptr->memosprite->death(); 
            double temp =0;
            if(ptr->memosprite->stack["Brewed_by_Tears"]>1){
                temp = ptr->memosprite->stack["Brewed_by_Tears"]-1;
            }
            buffSingle(ptr->memosprite.get(),{{Stats::FLAT_SPD, AType::NONE, -55.0 * temp}});
            ptr->memosprite->stack["Brewed_by_Tears"] = 1;
            increaseEnergy(ptr,20);
    
            if(ptr->print)CharCmd::printUltEnd("Aglaea");
        };


    }
    



    void enchanceBasicAtk(CharUnit *ptr){
       
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::BLAST,"AG Joint",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,20);
            attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,200,10),
            DmgSrc(DmgSrcType::ATK,90,5)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,200,10),
            DmgSrc(DmgSrcType::ATK,90,5)
        );
        act->setJoint();
        act->switchAttacker.push_back(SwitchAtk(1,1));
        act->addToActionBar();
    }
    void basicAtk(CharUnit *ptr){
        
        genSkillPoint(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"AG BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,20);
            attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,100,10)
        );
        act->addToActionBar();
    }
    void skill(CharUnit *ptr){
        genSkillPoint(ptr,-1);
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::SINGLE,"AG Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            increaseEnergy(ptr,30);
            if(ptr->memosprite->isDeath()){
                summon(ptr);
                act->turnReset=false;
            }
        });
        act->addBuffSingleTarget(ptr);
        act->addActionType(AType::SUMMON);
        act->addToActionBar();
    }
    void summon(CharUnit *ptr){
        ptr->getMemosprite()->summon(100);
        actionForward(ptr->memosprite->atvStats.get(),100);
    }
    

    
    void memoSkill(CharUnit *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr->getMemosprite(),TraceType::BLAST,"AG Memo Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,10);
            attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,110,10),
            DmgSrc(DmgSrcType::ATK,65,5)
        );
        act->addAttackType(AType::SUMMON);
        act->addToActionBar();
    }
}