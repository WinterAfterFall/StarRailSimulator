#include "../include.h"

namespace Robin{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    
    //temp
    void basicAtk(CharUnit *ptr);
    void skill(CharUnit *ptr);
    bool doubleTurn(CharUnit *ptr);
    

    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(102, 160, 160, eidolon, ElementType::PHYSICAL, Path::HARMONY, "Robin",UnitType::STANDARD);
        AllyUnit *robinPtr = ptr;
        ptr->setAllyBaseStats(1280, 640, 485);
        ptr->pushSubstats(Stats::ATK_P);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(120);
        ptr->setRelicMainStats(Stats::ATK_P,Stats::ATK_P,Stats::ATK_P,Stats::ER);

        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);

        AllyUnit *rb = ptr;

        ptr->turnFunc = [ptr,allyptr = ptr]() {
            if (!allyptr->getBuffCheck("Pinion'sAria")) {
            skill(ptr);
            } else {
            basicAtk(ptr);
            }
        };

        ptr->addUltCondition([ptr]() -> bool {
            if(driverType!=DriverType::DOUBLE_TURN)return true;
            AllyUnit *target = chooseAllyBuff(ptr);
            if((charUnit[driverNum]->atvStats->atv<charUnit[driverNum]->atvStats->maxAtv*0.2 || target->atvStats->atv == 0))return false;
            if((charUnit[driverNum]->atvStats->atv < target->atvStats->atv))return false;
            return true;
        });

        ptr->addUltCondition([ptr,rb]() -> bool {
            if(driverType!=DriverType::ALWAYS_PULL){
                CharUnit *ally =charUnit[ptr->currentCharNum].get();
                    if(ally->getATV()==0)return false;
                if(auto *each = ally->memosprite.get()){
                    if(each->getATV()==0)return false;
                }
                return true;
            }
            AllyUnit *dps = chooseAllyBuff(ptr);
            AllyUnit *driver = charUnit[driverNum].get();
            if(driver->getATV()>dps->getATV())return false;
            return true;
        });

        ptr->addUltCondition([ptr]() -> bool {
            if(driverType!=DriverType::ALWAYS_PULL)return true;
            AllyUnit *dps = chooseAllyBuff(ptr);
            AllyUnit *driver = charUnit[driverNum].get();
            if(driver->getATV()<dps->getATV())return false;
            return true;
        });

        ptr->addUltCondition([ptr]() -> bool {
            if(!ptr->countdownList[0]->isDeath())return false;
            if(!ptr->getBuffCheck("Pinion'sAria"))return false;
            return true;
        });
        
        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [robinPtr](CharUnit *ptr){
            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::ULT,ptr,TraceType::AOE,"RB Ult",
            [ptr,robinPtr](shared_ptr<AllyBuffAction> &act){
                ptr->countdownList[0]->summon();
                ptr->atvStats->baseSpeed = -1;
                updateMaxAtv(ptr->atvStats.get());
                resetTurn(ptr->atvStats.get());

                ptr->buffNote["Concerto_state"] = calculateAtkForBuff(ptr, 22.8) + 200;
                buffAllAlly({{Stats::FLAT_ATK, AType::TEMP, ptr->buffNote["Concerto_state"]}});
                buffAllAlly({{Stats::FLAT_ATK, AType::NONE, ptr->buffNote["Concerto_state"]}});

                buffAllAlly({{Stats::CD, AType::FUA, 25}});
                if(ptr->eidolon >= 1)buffAllAlly({{Stats::RESPEN, AType::NONE, 24}});
                if(ptr->eidolon >= 2)buffAllAllyExcludingBuffer(robinPtr,{{Stats::SPD_P,AType::NONE,16}});

                allActionForward(100);
            });
            act->addBuffAllAllies();
            act->addToActionBar();
            if(ptr->print)CharCmd::printUltStart("Robin");
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr){
            ptr->statsType[Stats::ATK_P][AType::NONE] += 28;
            ptr->statsType[Stats::HP_P][AType::NONE] += 18;
            ptr->atvStats->flatSpeed += 5;
            // relic
            // substats
            ptr->atvStats->baseSpeed = 102;
            return;
        }));

        startWaveList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr){
            if(ptr->technique == 1){
                increaseEnergy(ptr, 5);
            }
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr){
            actionForward(ptr->atvStats.get(), 25);
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr){
            buffAllAlly({{Stats::CD, AType::NONE, 20}});
        }));

        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [robinPtr](CharUnit *ptr){
            if(isBuffEnd(robinPtr,"Pinion'sAria")){
                buffAllAlly({{Stats::DMG, AType::NONE, -50}});
            }
        }));

        whenAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_ACTTACK, [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr, 2);
            if(ptr->eidolon >= 2){
                increaseEnergy(ptr, 1);
            }
            if(!ptr->countdownList[0]->isDeath()){
                shared_ptr<AllyAttackAction> newAct = 
                make_shared<AllyAttackAction>(AType::ADDTIONAL,ptr,TraceType::SINGLE,"RB AddDmg");
                double x1 = 0, x2 = 0;

                ptr->statsType[Stats::CR][AType::NONE] += 100;
                x1 = ptr->statsType[Stats::CD][AType::NONE];
                x2 = enemyUnit[mainEnemyNum]->statsType[Stats::CD][AType::NONE];
                ptr->statsType[Stats::CD][AType::NONE] = 150;
                enemyUnit[mainEnemyNum]->statsType[Stats::CD][AType::NONE] = 0;

                newAct->addDamageIns(DmgSrc(DmgSrcType::ATK,120));
                attack(newAct);

                ptr->statsType[Stats::CR][AType::NONE] -= 100;
                ptr->statsType[Stats::CD][AType::NONE] = x1;
                enemyUnit[mainEnemyNum]->statsType[Stats::CD][AType::NONE] = x2;
            }
        }));

        statsAdjustList.push_back(TriggerByStats(PRIORITY_ACTTACK, [ptr](AllyUnit *target, Stats statsType){
            if(target->atvStats->name != "Robin")return;
            if(ptr->countdownList[0]->isDeath())return;
            if(statsType == Stats::ATK_P || statsType == Stats::FLAT_ATK){
                double buffValue = calculateAtkForBuff(ptr, 22.8) + 200;
                buffAllAlly({{Stats::FLAT_ATK, AType::TEMP, buffValue - ptr->buffNote["Concerto_state"]}});
                buffAllAlly({{Stats::FLAT_ATK, AType::NONE, buffValue - ptr->buffNote["Concerto_state"]}});
                ptr->buffNote["Concerto_state"] = buffValue;
            }
        }));


        // countdown
        setCountdownStats(ptr,90, "Concerto_state");
        ptr->countdownList[0]->turnFunc = [ptr,robinPtr](){
            if( !ptr->countdownList[0]->isDeath()){
                ptr->countdownList[0]->death();
                ptr->atvStats->baseSpeed = 102;
                updateMaxAtv(ptr->atvStats.get());
                resetTurn(ptr->atvStats.get());
                buffAllAlly({{Stats::FLAT_ATK, AType::TEMP, -ptr->buffNote["Concerto_state"]}});
                buffAllAlly({{Stats::FLAT_ATK, AType::NONE, -ptr->buffNote["Concerto_state"]}});
                buffAllAlly({{Stats::CD, AType::FUA, -25}});
                if(ptr->eidolon >= 1)buffAllAlly({{Stats::RESPEN, AType::NONE, -24}});
                if(ptr->eidolon >= 2)buffAllAllyExcludingBuffer(robinPtr,{{Stats::SPD_P,AType::NONE,-16}});
                }
                actionForward(ptr->atvStats.get(),100);
                if(ptr->print)CharCmd::printUltEnd("Robin");
            };
        
        
    }


    void skill(CharUnit *ptr){
        genSkillPoint(ptr,-1);
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::SINGLE,"RB Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            increaseEnergy(ptr,35);
            buffAllAlly({{Stats::DMG,AType::NONE,50}});
            ptr->setBuffCheck("Pinion'sAria",true);
            extendBuffTime(ptr,"Pinion'sAria", 3);
        });
        act->addBuffSingleTarget(ptr);
        act->addToActionBar();
    }

    void basicAtk(CharUnit *ptr){
        genSkillPoint(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"RB BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,20);
            attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,100,10));
        act->addToActionBar();
    }
}
