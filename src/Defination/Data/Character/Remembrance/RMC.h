#include "../include.h"

namespace RMC{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
//temp
    void basicAtk(CharUnit *ptr);
    void skill(CharUnit *ptr);
    void increaseCharge(CharUnit *ptr,double charge);
    void memoSkill(CharUnit *ptr);
    void memoEchanceSkill(CharUnit *ptr);


    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(103,160,160,eidolon,ElementType::ICE,Path::REMEMBRANCE,"RMC",UnitType::STANDARD);
        ptr->setAllyBaseStats(1048,543,631);
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        setMemoStats(ptr,688,68,130,0,ElementType::ICE,"Mem",UnitType::STANDARD);
        
        AllyUnit *rmcPtr = ptr;
        AllyUnit *memPtr = ptr->getMemosprite();
        //substats
        

        ptr->pushSubstats(Stats::CD);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(160);
        ptr->setRelicMainStats(Stats::CD,Stats::FLAT_SPD,Stats::DMG,Stats::ER);


        //func
        
        ptr->turnFunc = [ptr,rmcPtr,memPtr](){
            if(ptr->atvStats->turnCnt==1){
                skill(ptr);
            }else{
                basicAtk(ptr);
            }
        };
        ptr->memosprite->turnFunc = [ptr,rmcPtr,memPtr](){
        
            if(ptr->memosprite->buffCheck["Mem_Charge"]==1){
                memoEchanceSkill(ptr);
            }else{
                memoSkill(ptr);
            }
        };

        ptr->addUltCondition([ptr,rmcPtr,memPtr]() -> bool {
            if (ptr->memosprite->buffNote["Mem_Charge"] >= 60 && chooseAllyBuff(ptr->memosprite.get())->atvStats->atv <= 20) return false;
            return true;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [rmcPtr,memPtr](CharUnit *ptr) {

            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::ULT,ptr->getMemosprite(),TraceType::AOE,"RMC Ult",
            [ptr,rmcPtr,memPtr](shared_ptr<AllyAttackAction> &act){
                increaseCharge(ptr, 40);
                buffSingle(memPtr,{{Stats::CR,AType::NONE,100.0}});
                if (ptr->print) CharCmd::printUltStart("RMC");

                attack(act);

                buffSingle(memPtr,{{Stats::CR,AType::NONE,-100.0}});
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,264,20),
                DmgSrc(DmgSrcType::ATK,264,20),
                DmgSrc(DmgSrcType::ATK,264,20)
            );
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [rmcPtr,memPtr](CharUnit *ptr) {
            ptr->statsType[Stats::ATK_P][AType::NONE] += 14;
            ptr->statsType[Stats::HP_P][AType::NONE] += 14;
            ptr->statsType[Stats::CD][AType::NONE] += 37.3;

            // relic

            // substats
        }));

        statsAdjustList.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,rmcPtr,memPtr](AllyUnit *target, Stats statsType) {
            if (target->atvStats->name != "Mem") return;
            if (statsType == Stats::CD) {
                double buffValue = (calculateCritdamForBuff(ptr->memosprite.get(), 13.2) + 26.4);
                buffAllAlly({{Stats::CD, AType::TEMP, buffValue - ptr->memosprite->buffNote["Mem_Talent_Buff"]}});
                buffAllAlly({{Stats::CD, AType::NONE, buffValue - ptr->memosprite->buffNote["Mem_Talent_Buff"]}});
                ptr->memosprite->buffNote["Mem_Talent_Buff"] = buffValue;
                return;
            }
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [rmcPtr,memPtr](CharUnit *ptr) {
            if (ptr->technique == 1) {
                for (int i = 1; i <= totalEnemy; i++) {
                    actionForward(enemyUnit[i]->atvStats.get(), -50);
                }
                shared_ptr<AllyAttackAction> act = 
                make_shared<AllyAttackAction>(AType::TECHNIQUE,ptr,TraceType::AOE,"RMC Tech",
                [ptr](shared_ptr<AllyAttackAction> &act){
                    attack(act);
                });
                act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,50,0),
                DmgSrc(DmgSrcType::ATK,50,0),
                DmgSrc(DmgSrcType::ATK,50,0)
                );
                act->addToActionBar();
                dealDamage();
            }
            actionForward(ptr->atvStats.get(), 30);
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [rmcPtr,memPtr](CharUnit *ptr) {
            double buffValue = (calculateCritdamForBuff(ptr->memosprite.get(), 13.2) + 26.4);
            buffAllAlly({{Stats::CD, AType::TEMP, buffValue - ptr->memosprite->buffNote["Mem_Talent_Buff"]}});
            buffAllAlly({{Stats::CD, AType::NONE, buffValue - ptr->memosprite->buffNote["Mem_Talent_Buff"]}});
            ptr->memosprite->buffNote["Mem_Talent_Buff"] = buffValue;
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [rmcPtr,memPtr](CharUnit *ptr) {
            if (isBuffEnd(chooseAllyBuff(rmcPtr),"Mem_Support")) {
                chooseCharacterBuff(rmcPtr)->setBuffNote("Mem_Support",0);
                buffSingleChar(chooseCharacterBuff(rmcPtr),{{Stats::CR,AType::NONE,-10}});
            }
        }));

        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [rmcPtr,memPtr](CharUnit *ptr) {
            ptr->memosprite->buffCheck["RMC_E2"] = 1;
        }));
        afterDealingDamageList.push_back(TriggerAfterDealDamage(PRIORITY_IMMEDIATELY, [rmcPtr,memPtr]
            (shared_ptr<AllyAttackAction> &act, Enemy *target, double damage) {
            CharUnit *ptr = act->attacker->owner;
            AllyUnit *ally;
            if (ptr->getBuffCheck("Mem_Support")){
                    ally = ptr;
                    goto jump;
            }
            if(auto *each = ptr->memosprite.get()){
                if (each->getBuffCheck("Mem_Support")){
                    ally = each;
                    goto jump;
                }
            }
            return;
            jump:
            calDamageNote(act,target,target,damage,ally->getBuffNote("Mem_Support"),"Mem True " + act->actionName);
        }));

        whenEnergyIncreaseList.push_back(TriggerEnergyIncreaseFunc(PRIORITY_IMMEDIATELY, [ptr,rmcPtr,memPtr](CharUnit *target, double energy) {
            if(energy==0){
                increaseCharge(ptr,3);
                return;
            }
            if (energy + target->currentEnergy > target->maxEnergy) {
                energy = target->maxEnergy - target->currentEnergy;
            }
            ptr->memosprite->buffNote["Mem_Energy_cnt"] += energy;
            increaseCharge(ptr, floor(ptr->memosprite->buffNote["Mem_Energy_cnt"] / 10));
            ptr->memosprite->buffNote["Mem_Energy_cnt"] -= floor(ptr->memosprite->buffNote["Mem_Energy_cnt"] / 10) * 10;
        }));

        afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,rmcPtr,memPtr](shared_ptr<AllyAttackAction> &act) {
            if (act->attacker->atvStats->name != "Mem" && act->attacker->atvStats->side == Side::MEMOSPRITE && ptr->memosprite->buffCheck["RMC_E2"] == 1) {
                increaseEnergy(ptr, 8);
                ptr->memosprite->buffCheck["RMC_E2"] = 0;
            }
        }));



        

    }


    void increaseCharge(CharUnit *ptr,double charge){
        if(ptr->memosprite->isDeath())return;
        ptr->memosprite->buffNote["Mem_Charge"]+=charge;
        if(ptr->memosprite->buffNote["Mem_Charge"]>=100){
            ptr->memosprite->buffNote["Mem_Charge"]= 0;
            ptr->memosprite->buffCheck["Mem_Charge"]=1;
            actionForward(ptr->memosprite->atvStats.get(),100);
        }
    }


    void basicAtk(CharUnit *ptr){
        genSkillPoint(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"RMC BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,20);
            attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,100,10));
        act->addToActionBar();
    }
    void skill(CharUnit *ptr){
        genSkillPoint(ptr,-1);
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::SINGLE,"RMC Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            increaseEnergy(ptr,30);
            if(ptr->memosprite->isDeath()){
                ptr->memosprite->summon(100);
                ptr->memosprite->resetATV(130);
                increaseCharge(ptr,90);
            }   
        });
        act->addActionType(AType::SUMMON);
        act->addBuffSingleTarget(ptr);
        act->addToActionBar();

    }



    void memoSkill(CharUnit *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr->getMemosprite(),TraceType::BOUNCE,"Mem Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,10);
            increaseCharge(ptr,5);
            attack(act);
        });
        act->addAttackType(AType::SUMMON);
        act->addEnemyBounce(DmgSrc(DmgSrcType::ATK,39.6,5),4);
        act->addDamageIns(
            DmgSrc(DmgSrcType::ATK,99,10),
            DmgSrc(DmgSrcType::ATK,99,10),
            DmgSrc(DmgSrcType::ATK,99,10)
        );
        act->addToActionBar();
    }
    void memoEchanceSkill(CharUnit *ptr){

        ptr->memosprite->buffCheck["Mem_Charge"]=0;

        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr->getMemosprite(),TraceType::SINGLE,"Mem Buff",
        [ptr,rmcPtr = ptr->memosprite.get()](shared_ptr<AllyBuffAction> &act){
            increaseEnergy(ptr,10);
            if(ptr->print)CharCmd::printUltStart("Mem");
            if(isHaveToAddBuff(chooseCharacterBuff(rmcPtr),"Mem_Support",3)){
                if(chooseCharacterBuff(ptr->memosprite.get())->maxEnergy == 0)
                chooseCharacterBuff(rmcPtr)->setBuffNote("Mem_Support",36);
                else if (chooseCharacterBuff(rmcPtr)->maxEnergy >= 200)
                chooseCharacterBuff(rmcPtr)->setBuffNote("Mem_Support",50);
                else 
                chooseCharacterBuff(rmcPtr)->setBuffNote("Mem_Support",30 + 2 * floor((chooseCharacterBuff(rmcPtr)->maxEnergy - 100) / 10));

                buffSingleChar(chooseCharacterBuff(rmcPtr),{{Stats::CR,AType::NONE,10}});
            }
            actionForward(chooseAllyBuff(ptr->memosprite.get())->atvStats.get(),100);
        });
        act->addBuffSingleTarget(chooseAllyBuff(ptr->memosprite.get()));
        act->addActionType(AType::SUMMON);
        act->addToActionBar();
    }  
}
