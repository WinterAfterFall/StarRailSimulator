#include "../include.h"

namespace Hanabi{
     void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(101,110,110,eidolon,ElementType::QUANTUM,Path::HARMONY,"Hanabi",UnitType::STANDARD);
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
        
        driverNum = ptr->atvStats->num;

        #pragma region Ability

        function<void()> ba = [ptr]() {
            genSkillPoint(ptr,1);
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Hnb BA",
            [ptr](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,30);
                attack(act);
            });
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,100,10));
            act->addToActionBar();
        };

        function<void()> skill = [ptr]() {
            if(ptr->getBuffCheck("Hnb Free Skill"))genSkillPoint(ptr,0);
            else genSkillPoint(ptr,-1);
            ptr->setBuffCheck("Hnb Free Skill",0);

            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::SINGLE,"Hnb Skill",
            [ptr](shared_ptr<AllyBuffAction> &act){
                increaseEnergy(ptr,30);
                double buff = (ptr->eidolon>=6)? calculateCritdamForBuff(ptr,54) + 45 :calculateCritdamForBuff(ptr,24) + 45;

                buffSingle(chooseAllyBuff(ptr),{
                    {Stats::CD,AType::TEMP,buff - chooseAllyBuff(ptr)->getBuffNote("Hnb Skill")},
                    {Stats::CD,AType::NONE,buff - chooseAllyBuff(ptr)->getBuffNote("Hnb Skill")}
                });
                buffSingle(chooseAllyBuff(ptr),{{Stats::RESPEN,AType::NONE,10}},"Hnb Skill",2);
                chooseAllyBuff(ptr)->setBuffNote("Hnb Skill",buff);
                
                if(ptr->eidolon>=6){
                    for(auto &each : allyList){
                        if(!each->getBuffCheck("Hnb Cipher"))continue;
                        if(each->getBuffCheck("Hnb Skill"))continue;
                        buffSingle(each,{
                            {Stats::CD,AType::TEMP,buff - each->getBuffNote("Hnb Skill")},
                            {Stats::CD,AType::NONE,buff - each->getBuffNote("Hnb Skill")}
                        });
                        if(isHaveToAddBuff(each,"Hnb E6 Link"))buffSingle(each,{{Stats::RESPEN,AType::NONE,10}});
                        each->setBuffNote("Hnb Skill",buff);
                    }   
                }
                actionForward(chooseAllyBuff(ptr)->atvStats.get(),50);
            });
            act->addBuffSingleTarget(chooseAllyBuff(ptr));
            act->addToActionBar();
        };

        #pragma endregion
        ptr->turnFunc = [ptr, allyPtr = ptr,skill,ba]() {
            skill();
        };
        
        // ptr->addUltCondition([ptr,hnb]() -> bool {
        //     if(maxSp-sp<3)return false;
        //     return true;
        // });

        ptr->addUltCondition([ptr]() -> bool {
            if(phaseStatus == PhaseStatus::BEFORE_TURN&&turn->isSameUnit(chooseAllyBuff(ptr)))return true;
            return false;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [](CharUnit *ptr) {
            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::ULT,ptr,TraceType::AOE,"Hnb Ult",
            [ptr](shared_ptr<AllyBuffAction> &act){
                CharCmd::printUltStart("Hanabi");
                // start record overflow sp
                ptr->setBuffCheck("Hnb Ult",true);

                if(ptr->eidolon>=4)genSkillPoint(ptr,7);
                else genSkillPoint(ptr,6);

                // Hnb Cipher
                if(ptr->eidolon == 0)
                    buffAllAlly({
                        {Stats::VUL,AType::NONE,6.0*ptr->getStack("Hnb Talent")}
                    },"Hnb Cipher",3);
                else
                    buffAllAlly({
                        {Stats::VUL,AType::NONE,6.0*ptr->getStack("Hnb Talent")},
                        {Stats::ATK_P,AType::NONE,40}
                    },"Hnb Cipher",3);

                if(ptr->eidolon>=6){
                    double buff = calculateCritdamForBuff(ptr,54) + 45;
                    for(auto &each : allyList){
                        if(each->getBuffCheck("Hnb Skill"))continue;
                        buffSingle(each,{
                            {Stats::CD,AType::TEMP,buff - each->getBuffNote("Hnb Skill")},
                            {Stats::CD,AType::NONE,buff - each->getBuffNote("Hnb Skill")}
                        });
                        if(isHaveToAddBuff(each,"Hnb E6 Link"))buffSingle(each,{{Stats::RESPEN,AType::NONE,10}});
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
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            buffAllAlly({{Stats::ATK_P,AType::NONE,45}});
            if(ptr->eidolon>=1)buffSingle(ptr,{{Stats::SPD_P,AType::NONE,15}});
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if(ptr->technique)genSkillPoint(ptr,3);
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            AllyUnit *ally = turn->canCastToAllyUnit();
            if(!ally)return;
            
            //Skill buff
            if(isBuffEnd(ally,"Hnb Skill")){
                buffSingle(ally,{
                    {Stats::CD,AType::TEMP,-ally->getBuffNote("Hnb Skill")},
                    {Stats::CD,AType::NONE,-ally->getBuffNote("Hnb Skill")},
                    {Stats::RESPEN,AType::NONE,-10}
                });
                ally->setBuffNote("Hnb Skill",0);
                
                if(ptr->eidolon>=6){
                    for(auto &each : allyList){
                        buffSingle(each,{
                            {Stats::CD,AType::TEMP,-each->getBuffNote("Hnb Skill")},
                            {Stats::CD,AType::NONE,-each->getBuffNote("Hnb Skill")}
                        });
                        if(each->getBuffCheck("Hnb E6 Link")){
                            buffSingle(each,{{Stats::RESPEN,AType::NONE,-10}});
                            each->setBuffCheck("Hnb E6 Link",0);
                        }
                        each->setBuffNote("Hnb Skill",0);
                    }   
                }
            }

            // Hnb Ult
            if(isBuffEnd(ally,"Hnb Cipher")){
                buffSingle(ally,{{Stats::VUL,AType::NONE,-6.0 * ptr->getStack("Hnb Talent")}});
                if(ptr->eidolon>=1)buffSingle(ally,{{Stats::ATK_P,AType::NONE,-40}});
                if(ptr->eidolon>=6&&!ally->getBuffCheck("Hnb Skill")){
                    buffSingle(ally,{
                        {Stats::CD,AType::TEMP,-ally->getBuffNote("Hnb Skill")},
                        {Stats::CD,AType::NONE,-ally->getBuffNote("Hnb Skill")}
                    });
                    if(ally->getBuffCheck("Hnb E6 Link")){
                        buffSingle(ally,{{Stats::RESPEN,AType::NONE,-10}});
                        ally->setBuffCheck("Hnb E6 Link",0);
                    }
                    ally->setBuffNote("Hnb Skill",0);
                }
            }

            if(ptr->getBuffCheck("Hnb Ult")){
                ptr->setBuffCheck("Hnb Ult",0);
                genSkillPoint(ptr,ptr->getStack("Hnb sp record"));
                ptr->setStack("Hnb sp record",0);
            }

        }));
        allyDeathList.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr](AllyUnit* target) {
            
            //Skill buff
            if(isBuffGoneByDeath(target,"Hnb Skill")){
                buffSingle(target,{
                    {Stats::CD,AType::TEMP,-target->getBuffNote("Hnb Skill")},
                    {Stats::CD,AType::NONE,-target->getBuffNote("Hnb Skill")},
                    {Stats::RESPEN,AType::NONE,-10}
                });
                target->setBuffNote("Hnb Skill",0);
                
                if(ptr->eidolon>=6){
                    for(auto &each : allyList){
                        buffSingle(each,{
                            {Stats::CD,AType::TEMP,-each->getBuffNote("Hnb Skill")},
                            {Stats::CD,AType::NONE,-each->getBuffNote("Hnb Skill")}
                        });
                        each->setBuffNote("Hnb Skill",0);
                        if(each->getBuffCheck("Hnb E6 Link")){
                            buffSingle(each,{{Stats::RESPEN,AType::NONE,-10}});
                            each->setBuffCheck("Hnb E6 Link",0);
                        }
                    }   
                }
            }

            // Hnb Ult
            if(isBuffGoneByDeath(target,"Hnb Cipher")){
                buffSingle(target,{{Stats::VUL,AType::NONE,-6.0 * ptr->getStack("Hnb Talent")}});
                if(ptr->eidolon>=1)buffSingle(target,{{Stats::ATK_P,AType::NONE,-40}});
                if(ptr->eidolon>=6&&!target->getBuffCheck("Hnb Skill")){
                    buffSingle(target,{
                        {Stats::CD,AType::TEMP,-target->getBuffNote("Hnb Skill")},
                        {Stats::CD,AType::NONE,-target->getBuffNote("Hnb Skill")}
                    });
                    if(target->getBuffCheck("Hnb E6 Link")){
                        buffSingle(target,{{Stats::RESPEN,AType::NONE,-10}});
                        target->setBuffCheck("Hnb E6 Link",0);
                    }
                    target->setBuffNote("Hnb Skill",0);
                }   
            }
        }));

        skillPointList.push_back(TriggerSkillPointFunc(PRIORITY_IMMEDIATELY, [ptr](AllyUnit *spMaker, int spChange) {
            if(ptr->getBuffCheck("Hnb Ult")){
                ptr->addStack("Hnb sp record",max(0,sp + spChange - maxSp));
            }
            if(spChange>=0)return;
            if(!ptr->getStack("Hnb Talent")){
                for(auto &each : enemyList){
                    each->totalDebuff++;
                }
            }
            pair<int,int> stk = calStack(ptr,-spChange,3,"Hnb Cipher");
            for(auto &each : allyList){
                if(each->getBuffCheck("Hnb Cipher")) buffSingle(each,{{Stats::VUL,AType::NONE,4.0*stk.first}});
                else buffSingle(each,{{Stats::VUL,AType::NONE,10.0*stk.first}});
            }
            if(ptr->eidolon>=2)debuffAllEnemy({{Stats::DEF_SHRED,AType::NONE,10.0*stk.first}});

            if(spMaker->getBuffCheck("Hnb Skill")||ptr->eidolon>=6){
                increaseEnergy(ptr,1);
            }

            if(ptr->getBuffNote("Hanabi turn note" + turn->getUnitName()) != turn->turnCnt || turn->turnCnt==0)
            ptr->setStack("Hnb sp record",0);

            ptr->addStack("Hnb sp record",spChange*-1);
            if(ptr->getStack("Hnb sp record")>=3)ptr->setBuffCheck("Hnb Free Skill",1);
            
   
        }));
        

    }
}
