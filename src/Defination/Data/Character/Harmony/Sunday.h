#include "../include.h"

namespace Sunday{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void skill(CharUnit *ptr);

    bool ultCondition(CharUnit *ptr);
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(96, 130, 130, eidolon, ElementType::IMAGINARY, Path::HARMONY, "Sunday",UnitType::STANDARD);
        AllyUnit *sdPtr = ptr;
        ptr->setAllyBaseStats(1242, 640, 533);
        ptr->pushSubstats(Stats::CD);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(134);
        ptr->setRelicMainStats(Stats::HP_P,Stats::FLAT_SPD,Stats::HP_P,Stats::ER);

        driverNum = sdPtr->atvStats->num;
        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->turnFunc = [ptr, allyPtr = ptr]() {
            skill(ptr);
        };

        ptr->addUltCondition([ptr,sdPtr]() -> bool {
            if(chooseCharacterBuff(ptr)->isSameName("Saber"))return true;
            if(chooseCharacterBuff(ptr)->maxEnergy!=0){
                if (chooseCharacterBuff(ptr)->maxEnergy <= 200 &&
                    chooseCharacterBuff(ptr)->maxEnergy - 
                    chooseCharacterBuff(ptr)->currentEnergy < 30) return false;
                if (chooseCharacterBuff(ptr)->maxEnergy >= 200 &&
                    chooseCharacterBuff(ptr)->maxEnergy - 
                    chooseCharacterBuff(ptr)->currentEnergy 
                    < chooseCharacterBuff(ptr)->maxEnergy * 0.2) return false;
            }
            return true;
        });
        // ptr->addUltImmediatelyUseCondition([ptr,sdPtr]() -> bool {
        //     if(Buff_check(ptr, "Ode_to_Caress_and_Cicatrix"))return false;
        //     return true;
        // });
        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [sdPtr](CharUnit *ptr) {
            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::ULT,ptr,TraceType::SINGLE,"SD Ult",
            [ptr,sdPtr](shared_ptr<AllyBuffAction> &act){
                if (ptr->print)CharCmd::printUltStart("Sunday");
                if (ptr->eidolon >= 2) {
                    if (ptr->buffCheck["Ult_first_time"] == 0) {
                        ptr->buffCheck["Ult_first_time"] = 1;
                        genSkillPoint(ptr, 2);
                    }
                }

                if(ptr->eidolon>=6)
                buffStackChar(chooseCharacterBuff(ptr),{{Stats::CR,AType::NONE,20}},1,3,"The_Sorrowing_Body",4);

                if (chooseCharacterBuff(ptr)->maxEnergy > 200)
                increaseEnergy(chooseCharacterBuff(ptr), 20, 0);
                else
                increaseEnergy(chooseCharacterBuff(ptr), 0, 40);

                if (!isHaveToAddBuff(sdPtr,"Ode_to_Caress_and_Cicatrix",3))
                {
                    if(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")){
                        //ตัวหลัก
                        buffSingle(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix"),{{Stats::CD, AType::TEMP, -sdPtr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                        buffSingle(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix"),{{Stats::CD, AType::NONE, -sdPtr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                        if (ptr->eidolon >= 2)
                        buffSingle(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix"),{{Stats::DMG, AType::NONE, -30}});
                        ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")->setBuffCheck("Ode_to_Caress_and_Cicatrix",false);
                        //Memopsrite
                        if(auto *each = ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")->memosprite.get()){
                            if(each->getBuffCheck("Ode_to_Caress_and_Cicatrix")){
                                buffSingle(each,{{Stats::CD, AType::TEMP, -sdPtr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                                buffSingle(each,{{Stats::CD, AType::NONE, -sdPtr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                                if (ptr->eidolon >= 2)
                                buffSingle(each,{{Stats::DMG, AType::NONE, -30}});
                                each->setBuffCheck("Ode_to_Caress_and_Cicatrix",false);
                            }
                        }
                    }
                }
                ptr->buffCheck["Ode_to_Caress_and_Cicatrix"] = 1;
                ptr->setBuffAllyTarget("Ode_to_Caress_and_Cicatrix",chooseCharacterBuff(ptr));
                ptr->setBuffNote("Ode_to_Caress_and_Cicatrix",calculateCritdamForBuff(ptr, 30) + 12);
                if(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")->isTargetable()){
                    ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")->setBuffCheck("Ode_to_Caress_and_Cicatrix",true);
                    buffSingle(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix"),{{Stats::CD, AType::TEMP, sdPtr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                    buffSingle(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix"),{{Stats::CD, AType::NONE, sdPtr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                    if (ptr->eidolon >= 2)
                    buffSingle(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix"),{{Stats::DMG, AType::NONE, 30}});
                }
                if(auto *each = ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")->memosprite.get(); each && each->isTargetable()){
                    each->setBuffCheck("Ode_to_Caress_and_Cicatrix",true);
                    buffSingle(each,{{Stats::CD, AType::TEMP, sdPtr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                    buffSingle(each,{{Stats::CD, AType::NONE, sdPtr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                    if (ptr->eidolon >= 2)
                    buffSingle(each,{{Stats::DMG, AType::NONE, 30}});
                }
            });
            act->addBuffChar(chooseCharacterBuff(ptr));
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [sdPtr](CharUnit *ptr) {
            ptr->statsType[Stats::CD][AType::NONE] += 37.3;
            ptr->statsType[Stats::DEF_P][AType::NONE] += 12.5;
            ptr->statsType[Stats::RES][AType::NONE] += 18;


            // relic

            // substats
        }));


        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [sdPtr](CharUnit *ptr) {
            if(turn->isSameName("Sunday")&&ptr->eidolon>=4){
                increaseEnergy(ptr,8);
            }
            if (isBuffEnd(sdPtr,"Ode_to_Caress_and_Cicatrix")) {
                if(!ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix"))return;
                if(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")->getBuffCheck("Ode_to_Caress_and_Cicatrix")){
                    buffSingle(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix"),{{Stats::CD, AType::TEMP, -sdPtr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                    buffSingle(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix"),{{Stats::CD, AType::NONE, -sdPtr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                    if (ptr->eidolon >= 2)
                    buffSingle(ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix"),{{Stats::DMG, AType::NONE, -30}});
                    ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")->setBuffCheck("Ode_to_Caress_and_Cicatrix",false);
                }
                if(auto *each = ptr->getBuffAllyTarget("Ode_to_Caress_and_Cicatrix")->memosprite.get()){
                    if(each->getBuffCheck("Ode_to_Caress_and_Cicatrix")){
                        buffSingle(each,{{Stats::CD, AType::TEMP, -sdPtr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                        buffSingle(each,{{Stats::CD, AType::NONE, -sdPtr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                        if (ptr->eidolon >= 2)
                        buffSingle(each,{{Stats::DMG, AType::NONE, -30}});
                        each->setBuffCheck("Ode_to_Caress_and_Cicatrix",false);
                    }
                }
                ptr->setBuffAllyTarget("Ode_to_Caress_and_Cicatrix",nullptr);
                if (ptr->print)CharCmd::printUltEnd("Sunday");
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [sdPtr](CharUnit *ptr) {
            AllyUnit *tempStats = turn->canCastToAllyUnit();
            if(!tempStats)return;
            if (isBuffEnd(tempStats,"Benison_of_Paper_and_Rites")) {
                if (tempStats->owner->isAllyHaveSummon()) {
                    buffSingle(tempStats,{{Stats::DMG,AType::NONE,-80}});
                } else {
                    buffSingle(tempStats,{{Stats::DMG,AType::NONE,-30}});
                }
                if (ptr->eidolon >= 1&&isBuffEnd(tempStats,"Sunday_E1")) {
                    if (turn->side == Side::MEMOSPRITE) {
                        buffSingle(tempStats,{{Stats::DEF_SHRED,AType::NONE,-40}});
                    } else {
                        buffSingle(tempStats,{{Stats::DEF_SHRED,AType::NONE,-16}});
                        buffSingle(tempStats,{{Stats::DEF_SHRED,AType::SUMMON,-24}});
                    }
                }
            }
            if (isBuffEnd(tempStats,"The_Sorrowing_Body")) {
                if(ptr->eidolon>=6){
                    buffResetStack(tempStats,{{Stats::CR,AType::NONE,20}},"The_Sorrowing_Body");
                }else{
                    buffSingle(tempStats,{{Stats::CR,AType::NONE,-20}});
                }
                
            }
            if (isBuffEnd(tempStats,"The_Glorious_Mysteries")){
                buffSingle(tempStats,{{Stats::DMG,AType::NONE,-50}});
            }
            
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [sdPtr](CharUnit *ptr) {
            increaseEnergy(ptr, 25);
        }));

        buffList.push_back(TriggerByAllyBuffActionFunc(PRIORITY_IMMEDIATELY, [ptr,sdPtr](shared_ptr<AllyBuffAction> &act) {
            if (chooseCharacterBuff(ptr)->getBuffCheck("Ode_to_Caress_and_Cicatrix") && act->actionName=="SD Skill") {
                genSkillPoint(ptr, 1);
            }
        }));

        statsAdjustList.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,sdPtr](AllyUnit *target, Stats statsType) {
            if(ptr->eidolon>=6&&target->getStack("The_Sorrowing_Body")>0&&statsType == Stats::CR){
                double temp = (calculateCritrateForBuff(target,100) - 100)*2;
                if(temp<0)temp=0;
                buffSingle(target,{{Stats::CD, AType::TEMP, temp - target->getBuffNote("The_Sorrowing_Body")}});
                buffSingle(target,{{Stats::CD, AType::NONE, temp - target->getBuffNote("The_Sorrowing_Body")}});
                target->buffNote["The_Sorrowing_Body"] = temp;
            }
            if (target->atvStats->name != "Sunday") return;
            if (!target->getBuffCheck("Ode_to_Caress_and_Cicatrix")) return;
            if (statsType != Stats::CD) return;   
            double buffValue = calculateCritdamForBuff(ptr, 30) + 12;
            if(chooseCharacterBuff(ptr)->getBuffCheck("Ode_to_Caress_and_Cicatrix")){
                buffSingle(chooseCharacterBuff(ptr),{{Stats::CD, AType::TEMP, buffValue - ptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                buffSingle(chooseCharacterBuff(ptr),{{Stats::CD, AType::NONE, buffValue - ptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
            }
            if(auto *each = chooseCharacterBuff(ptr)->memosprite.get(); each && each->getBuffCheck("Ode_to_Caress_and_Cicatrix")){
                buffSingle(each,{{Stats::CD, AType::TEMP, buffValue - ptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                buffSingle(each,{{Stats::CD, AType::NONE, buffValue - ptr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
            }
            ptr->buffNote["Ode_to_Caress_and_Cicatrix"] =  buffValue;
            
        }));

        allyDeathList.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY,[ptr,sdPtr](AllyUnit* target){
            if(isBuffGoneByDeath(target,"Ode_to_Caress_and_Cicatrix")){
                buffSingle(target,{{Stats::CD, AType::TEMP, -sdPtr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                buffSingle(target,{{Stats::CD, AType::NONE, -sdPtr->getBuffNote("Ode_to_Caress_and_Cicatrix")}});
                if (ptr->eidolon >= 2)
                buffSingle(target,{{Stats::DMG, AType::NONE, -30}});
            }
            if (isBuffGoneByDeath(target,"Benison_of_Paper_and_Rites")){
                if (target->owner->isAllyHaveSummon()) {
                    buffSingle(target,{{Stats::DMG,AType::NONE,-80}});
                } else {
                    buffSingle(target,{{Stats::DMG,AType::NONE,-30}});
                }
                if (ptr->eidolon >= 1&&isBuffGoneByDeath(target,"Sunday_E1")) {
                    if (turn->side == Side::MEMOSPRITE) {
                        buffSingle(target,{{Stats::DEF_SHRED,AType::NONE,-40}});
                    } else {
                        buffSingle(target,{{Stats::DEF_SHRED,AType::NONE,-16}});
                        buffSingle(target,{{Stats::DEF_SHRED,AType::SUMMON,-24}});
                    }
                }
            }
            if(ptr->eidolon>=6){
                buffResetStack(target,{{Stats::CR,AType::NONE,20}},"The_Sorrowing_Body");
            }
            else if(isBuffGoneByDeath(target,"The_Sorrowing_Body"))
            {
                buffSingle(target,{{Stats::CR,AType::NONE,-20}});
            }
            if (isBuffGoneByDeath(target,"The_Glorious_Mysteries")){
                buffSingle(target,{{Stats::DMG,AType::NONE,-50}});
            }
        }));





    }

    
    void skill(CharUnit *ptr){
        genSkillPoint(ptr,-1);
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::SINGLE,"SD Skill",
        [ptr,sdPtr=ptr](shared_ptr<AllyBuffAction> &act){
            increaseEnergy(ptr,30);
            if(ptr->eidolon>=6){
                buffStackChar(chooseCharacterBuff(ptr),{{Stats::CR,AType::NONE,20}},1,3,"The_Sorrowing_Body",4);
            }
            else
            {
                buffSingleChar(chooseCharacterBuff(ptr),{{Stats::CR,AType::NONE,20}},"The_Sorrowing_Body",3);
            }

            if(chooseCharacterBuff(ptr)->isAllyHaveSummon())
            buffSingleChar(chooseCharacterBuff(ptr),{{Stats::DMG,AType::NONE,80}},"Benison_of_Paper_and_Rites",2);
            else
            buffSingleChar(chooseCharacterBuff(ptr),{{Stats::DMG,AType::NONE,30}},"Benison_of_Paper_and_Rites",2);

            if(ptr->eidolon>=1){
                buffSingle(chooseCharacterBuff(ptr),{
                    {Stats::DEF_SHRED,AType::NONE,16},
                    {Stats::DEF_SHRED,AType::SUMMON,24},
                },"Sunday_E1",2);
                buffSingleChar(chooseCharacterBuff(ptr),{{Stats::DEF_SHRED,AType::NONE,40}},"Sunday_E1",2);
            }
            
            if(ptr->technique==1&&!sdPtr->getBuffCheck("Technique_use")){
                ptr->setBuffCheck("Technique_use",1);
                buffSingleChar(chooseCharacterBuff(ptr),{{Stats::DMG,AType::NONE,50}},"The_Glorious_Mysteries",2);
            }
            
            //Action Forward
            for(std::unique_ptr<TimerATV> &e : chooseCharacterBuff(ptr)->summonList){
                actionForward(e.get(),100);
            }
            if(auto *each = chooseCharacterBuff(ptr)->memosprite.get()){
                actionForward(each->atvStats.get(),100);
            }
            actionForward(chooseCharacterBuff(ptr)->atvStats.get(),100);
        });
        act->addBuffChar(chooseCharacterBuff(ptr));
        act->addToActionBar();
    }

    bool ultCondition(CharUnit *ptr){
        //if(currentAtv<150&&(Ally_unit[mainDpsNum]->countdownList[0]->atvStats->Base_speed==-1))return true;
        return false;
    }

}