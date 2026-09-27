#include "../include.h"

namespace HanabiV1{
     void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(101,110,110,eidolon,ElementType::QUANTUM,Path::HARMONY,"HanabiV1",UnitType::STANDARD);
        ptr->setAllyBaseStats(1397,524,485);

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(160);
        ptr->setRelicMainStats(Stats::CD,Stats::FLAT_SPD,Stats::HP_P,Stats::ER);

        maxSp+=3;
        if(ptr->eidolon>=4)maxSp++;
        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        
        AllyUnit *hnb = ptr;
        driverNum = hnb->atvStats->num;

        #pragma region Ability

        function<void()> ba = [ptr,hnb]() {
            genSkillPoint(hnb,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Hnb BA",
            [hnb](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(hnb,30);
                attack(act);
            });
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,100,10));
            act->addToActionBar();
        };

        function<void()> skill = [ptr,hnb]() {
            genSkillPoint(hnb,-1);
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::SINGLE,"Hnb Skill",
            [ptr,hnb](shared_ptr<AllyBuffAction> &act){
                increaseEnergy(hnb,30);
                double buff = (ptr->eidolon>=6)? calculateCritdamForBuff(hnb,54) + 45 :calculateCritdamForBuff(hnb,24) + 45;

                buffSingle(chooseAllyBuff(hnb),{
                    {Stats::CD,AType::TEMP,buff - chooseAllyBuff(hnb)->getBuffNote("Hnb Skill")},
                    {Stats::CD,AType::NONE,buff - chooseAllyBuff(hnb)->getBuffNote("Hnb Skill")}
                });
                extendBuffTime(chooseAllyBuff(hnb),"Hnb Skill",2);
                chooseAllyBuff(hnb)->setBuffNote("Hnb Skill",buff);
                
                if(ptr->eidolon>=6){
                    for(auto &each : allyList){
                        if(!each->getBuffCheck("Hnb Cipher"))continue;
                        buffSingle(each,{
                            {Stats::CD,AType::TEMP,buff - each->getBuffNote("Hnb Skill")},
                            {Stats::CD,AType::NONE,buff - each->getBuffNote("Hnb Skill")}
                        });
                        each->setBuffNote("Hnb Skill",buff);
                    }   
                }
                actionForward(chooseAllyBuff(hnb)->atvStats.get(),50);
            });
            act->addBuffSingleTarget(chooseAllyBuff(hnb));
            act->addToActionBar();
        };

        #pragma endregion
        ptr->turnFunc = [ptr, allyPtr = ptr,skill,ba]() {
            skill();
        };
        
        ptr->addUltCondition([ptr,hnb]() -> bool {
            if(maxSp-sp<3)return false;
            return true;
        });

        ptr->addUltCondition([ptr,hnb]() -> bool {
            if(phaseStatus == PhaseStatus::BEFORE_TURN&&turn->isSameUnit(chooseAllyBuff(hnb)))return true;
            return false;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [hnb](CharUnit *ptr) {
            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::ULT,ptr,TraceType::AOE,"Hnb Ult",
            [ptr,hnb](shared_ptr<AllyBuffAction> &act){
                if(ptr->eidolon>=4)genSkillPoint(hnb,5);
                else genSkillPoint(hnb,4);
                
                for(auto &each : allyList){
                    if(isHaveToAddBuff(each,"Hnb Cipher")){
                        buffSingle(each,{{Stats::DMG,AType::NONE,10.0 * each->getStack("Hnb Talent")}});
                        if(ptr->eidolon>=1){
                            buffSingle(each,{{Stats::ATK_P,AType::NONE,40}});
                            extendBuffTime(each,"Hnb Cipher",3);
                        }
                        else extendBuffTime(each,"Hnb Cipher",2);
                    }
                }   

                if(ptr->eidolon>=6){
                    double buff = calculateCritdamForBuff(hnb,54) + 45;
                    for(auto &each : allyList){
                        buffSingle(each,{
                            {Stats::CD,AType::TEMP,buff - each->getBuffNote("Hnb Skill")},
                            {Stats::CD,AType::NONE,buff - each->getBuffNote("Hnb Skill")}
                        });
                        each->setBuffNote("Hnb Skill",buff);
                    }   
                }

                
            });
            act->addBuffAllAllies();
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::HP_P][AType::NONE] += 28;
            ptr->statsType[Stats::CD][AType::NONE] += 24;
            ptr->statsType[Stats::RES][AType::NONE] += 10;

            // relic

            // substats
            int qtCount = 0;

            for(int i=1;i<=totalAlly;i++){
                if(charUnit[i]->elementType ==ElementType::QUANTUM)
                    qtCount++;
            }

            double atkBuff = 20;
            if(qtCount == 2)atkBuff = 30;
            else if(qtCount >= 3)atkBuff = 45;
            for(auto &each : charList){
                if(each->elementType ==ElementType::QUANTUM)
                    buffSingle(each,{{Stats::ATK_P,AType::NONE,atkBuff}});
                else
                    buffSingle(each,{{Stats::ATK_P,AType::NONE,15}});
            }
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [hnb](CharUnit *ptr) {
            if(ptr->technique)genSkillPoint(hnb,3);
        }));

        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [hnb](CharUnit *ptr) {
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(!ally)return;
            if(isBuffEnd(ally,"Hnb Skill")){
                buffSingle(ally,{
                    {Stats::CD,AType::TEMP,-ally->getBuffNote("Hnb Skill")},
                    {Stats::CD,AType::NONE,-ally->getBuffNote("Hnb Skill")}
                });
                ally->setBuffNote("Hnb Skill",0);
                
                if(ptr->eidolon>=6){
                    for(int i=1;i<=totalAlly;i++){
                        for(auto &each : allyList){
                            buffSingle(each,{
                                {Stats::CD,AType::TEMP,-each->getBuffNote("Hnb Skill")},
                                {Stats::CD,AType::NONE,-each->getBuffNote("Hnb Skill")}
                            });
                            each->setBuffNote("Hnb Skill",0);
                        }   
                    }
                }
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [hnb](CharUnit *ptr) {
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(!ally)return;
            if(isBuffEnd(ally,"Hnb Cipher")){
                buffSingle(ally,{{Stats::DMG,AType::NONE,-10.0 * ally->getStack("Hnb Talent")}});
                if(ptr->eidolon>=1)buffSingle(ally,{{Stats::ATK_P,AType::NONE,-40}});
                if(ptr->eidolon>=6){
                    for(int i=1;i<=totalAlly;i++){
                        for(auto &each : allyList){
                            if(each->getBuffCheck("Hnb Skill"))continue;
                            buffSingle(each,{
                                {Stats::CD,AType::TEMP,-each->getBuffNote("Hnb Skill")},
                                {Stats::CD,AType::NONE,-each->getBuffNote("Hnb Skill")}
                            });
                            each->setBuffNote("Hnb Skill",0);
                        }   
                    }
                }
            }
            if(isBuffEnd(ally,"Hnb Talent")){
                if(ally->getBuffCheck("Hnb Cipher"))
                    buffResetStack(ally,{{Stats::DMG,AType::NONE,16}},"Hnb Talent");
                else
                    buffResetStack(ally,{{Stats::DMG,AType::NONE,6}},"Hnb Talent");
                if(ptr->eidolon>=2)buffResetStack(ally,{{Stats::DEF_SHRED,AType::NONE,8}},"Hnb E2");
            }
        }));

        allyDeathList.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,hnb](AllyUnit* target) {
            if(isBuffGoneByDeath(target,"Hnb Cipher")){
                buffSingle(target,{{Stats::DMG,AType::NONE,-10.0 * target->getStack("Hnb Talent")}});
                if(ptr->eidolon>=1)buffSingle(target,{{Stats::ATK_P,AType::NONE,-40}});
            }
            if(isBuffGoneByDeath(target,"Hnb Talent")){
                if(target->getBuffCheck("Hnb Cipher"))
                    buffResetStack(target,{{Stats::DMG,AType::NONE,16}},"Hnb Talent");
                else
                    buffResetStack(target,{{Stats::DMG,AType::NONE,6}},"Hnb Talent");
                if(ptr->eidolon>=2)buffResetStack(target,{{Stats::DEF_SHRED,AType::NONE,8}},"Hnb E2");
            }
            if(isBuffGoneByDeath(target,"Hnb Skill")){
                buffSingle(target,{
                    {Stats::CD,AType::TEMP,-target->getBuffNote("Hnb Skill")},
                    {Stats::CD,AType::NONE,-target->getBuffNote("Hnb Skill")}
                });
                target->setBuffNote("Hnb Skill",0);


                if(ptr->eidolon>=6){
                    for(int i=1;i<=totalAlly;i++){
                        for(auto &each : allyList){
                            buffSingle(each,{
                                {Stats::CD,AType::TEMP,-each->getBuffNote("Hnb Skill")},
                                {Stats::CD,AType::NONE,-each->getBuffNote("Hnb Skill")}
                            });
                            each->setBuffNote("Hnb Skill",0);
                        }   
                    }
                }

            }
        }));

        skillPointList.push_back(TriggerSkillPointFunc(PRIORITY_IMMEDIATELY, [ptr,hnb](AllyUnit *spMaker, int spChange) {
            if(spChange>=0)return;
            for(auto &each : allyList){
                if(each->getBuffCheck("Hnb Cipher"))
                    buffStackSingle(each,{{Stats::DMG,AType::NONE,16}},-spChange,3,"Hnb Talent",2);
                else 
                    buffStackSingle(each,{{Stats::DMG,AType::NONE,6}},-spChange,3,"Hnb Talent",2);
                if(ptr->eidolon>=2)buffStackSingle(each,{{Stats::DEF_SHRED,AType::NONE,8}},-spChange,3,"Hnb E2");
            }   
        }));
        

    }
}
