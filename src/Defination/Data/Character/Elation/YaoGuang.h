#include "../include.h"

namespace YaoGuang{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(101,180,180,eidolon,ElementType::PHYSICAL,Path::ELATION,"Yao Guang",UnitType::STANDARD);
        ptr->setAllyBaseStats(1242,465,654);

        //substats
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::CD);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(320);
        ptr->setRelicMainStats(Stats::CR,Stats::FLAT_SPD,Stats::HP_P,Stats::ER);

        elationCount++;
        cbDuration += 1; // A6: Certified Banger duration +1
        
        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);

        #pragma region Ability

        function<void()> ba = [ptr]() {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::BLAST,"YG BA",
            [ptr](shared_ptr<AllyAttackAction> &act){
                genSkillPoint(ptr,1);
                genPunchLine(ptr,3);
                increaseEnergy(ptr,20);
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,90,10),
                DmgSrc(DmgSrcType::ATK,30,5)
            );
            act->addToActionBar();
        };

        function<void()> skill = [ptr]() {
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::SINGLE,"YG Skill",
            [ptr](shared_ptr<AllyBuffAction> &act){
                genSkillPoint(ptr,-1);
                genPunchLine(ptr,3);
                increaseEnergy(ptr,30);
                if(isHaveToAddBuff(ptr,"YG Skill",3)){
                    if(ptr->eidolon>=2)
                    buffAllAlly({
                        {Stats::SPD_P,AType::NONE,12},
                        {Stats::ELATION,AType::NONE,16}
                    });

                    double buff = calculateElationForBuff(ptr,20);
                    buffAllAlly({
                        {Stats::ELATION,AType::NONE,buff - ptr->getBuffNote("YG Skill")},
                        {Stats::ELATION,AType::TEMP,buff - ptr->getBuffNote("YG Skill")}
                    });

                    
                    ptr->setBuffNote("YG Skill",buff);

                }
            });
            act->addBuffSingleTarget(ptr);
            act->addToActionBar();
        };
        #pragma endregion
        ptr->turnFunc = [ptr,ba,skill]() {
            if(ptr->getBuffCheck("YG Skill"))ba();
            else skill();

        };
        
        ptr->addUltCondition([ptr]() -> bool {
            return true;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [](CharUnit *ptr) {
            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::ULT,ptr,TraceType::AOE,"YG Ult",
            [ptr](shared_ptr<AllyBuffAction> &act){
                CharCmd::printUltStart(ptr->getName());

                genPunchLine(ptr,5);

                buffAllAlly({
                    {Stats::RESPEN,AType::NONE,20}
                },"YG Ult",3);

                if(ptr->eidolon>=4)
                buffAllAlly({
                    {Stats::MTPR_INC,AType::ELATION_SKILL,50}
                });

                if(ptr->eidolon>=1)ahaInstant(40);
                else ahaInstant(20);

                if(ptr->eidolon>=4)
                buffAllAlly({
                    {Stats::MTPR_INC,AType::ELATION_SKILL,-50}
                });


            });
            act->addBuffAllAllies();
            act->addToActionBar();
            dealDamage();
        }));

        elationSkillList.push_back(TriggerByYourSelfFunc(114, ptr, [](CharUnit *ptr) {
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::ELATION_SKILL,ptr,TraceType::AOE,"YG Elation",
            [ptr](shared_ptr<AllyAttackAction> &act){
                debuffAllEnemyApply(ptr,{{Stats::VUL,AType::NONE,16}},"Woe's Whisper",3);
                increaseEnergy(ptr,5);    
                attack(act);
                genSkillPoint(ptr,1);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ELATION,100,20),
                DmgSrc(DmgSrcType::ELATION,100,20),
                DmgSrc(DmgSrcType::ELATION,100,20)
            );
            act->addEnemyBounce(
                DmgSrc(DmgSrcType::ELATION,20,5),5
            );
            act->addToAhaInstant();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::CR][AType::NONE] += 18.7;
            ptr->statsType[Stats::CD][AType::NONE] += 60;
            ptr->statsType[Stats::ELATION][AType::NONE] += 10+30;
            ptr->atvStats->flatSpeed += 9;
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if(ptr->eidolon>=1)buffAllAlly({{Stats::DEF_SHRED,AType::ELATION_DMG,20}});
            if(ptr->eidolon>=6){
                buffAllAlly({{Stats::MERRYMAKE,AType::ELATION_DMG,25}});
                buffSingle(ptr,{{Stats::MTPR_INC,AType::ELATION_SKILL,100}});
            }
            statsAdjust(ptr,Stats::SPD_P);
        }));

        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if(isBuffEnd(ptr,"YG Skill")){
                buffAllAlly({
                        {Stats::ELATION,AType::NONE,-ptr->getBuffNote("YG Skill")},
                        {Stats::ELATION,AType::TEMP,-ptr->getBuffNote("YG Skill")}
                });
                ptr->setBuffNote("YG Skill",0);
                if(ptr->eidolon>=2)
                buffAllAlly({
                    {Stats::SPD_P,AType::NONE,-12},
                    {Stats::ELATION,AType::NONE,-16}
                });
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            AllyUnit *ally = turn->canCastToAllyUnit();
            Enemy *enemy = turn->canCastToEnemy();
            if(ally){
                if(isBuffEnd(ally,"YG Ult")){
                    buffSingle(ally,{{Stats::RESPEN,AType::NONE,-20}});
                }
            }
            if(!enemy)return;
            if(isDebuffEnd(enemy,"Woe's Whisper")){
                debuffSingle(enemy,{{Stats::VUL,AType::NONE,-16}});
            }

        }));

        

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if(!ptr->technique)return;
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::SINGLE,"YG Skill",
            [ptr](shared_ptr<AllyBuffAction> &act){
                genPunchLine(ptr,3);
                increaseEnergy(ptr,30);
                if(isHaveToAddBuff(ptr,"YG Skill",3)){
                    if(ptr->eidolon>=2)
                    buffAllAlly({
                        {Stats::SPD_P,AType::NONE,12},
                        {Stats::ELATION,AType::NONE,16}
                    });

                    double buff = calculateElationForBuff(ptr,20);
                    buffAllAlly({
                        {Stats::ELATION,AType::NONE,buff - ptr->getBuffNote("YG Skill")},
                        {Stats::ELATION,AType::TEMP,buff - ptr->getBuffNote("YG Skill")}
                    });
                    
                    ptr->setBuffNote("YG Skill",buff);

                }
            });
            act->addBuffSingleTarget(ptr);
            act->addToActionBar();
            act->turnReset= 0;
            dealDamage();
        }));

        beforeAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            ptr->setBuffCheck("YG Talent SP check",0);
        }));

        skillPointList.push_back(TriggerSkillPointFunc(PRIORITY_IMMEDIATELY, [ptr](AllyUnit *spMaker, int spChange) {
            if(spChange<0)ptr->setBuffCheck("YG Talent SP check",1);
        }));

        whenAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyAttackAction> &act) {
            
            if(ptr->statsType[Stats::CERTIFIED_BANGER][AType::NONE]<=0)return;
            shared_ptr<AllyAttackAction> newAct = make_shared<AllyAttackAction>(AType::ELATION_DMG,act->attacker,TraceType::SINGLE,"YG Talent");
            newAct->addDamageIns(DmgSrc(DmgSrcType::ELATION,20));
            if(ptr->getBuffCheck("YG Talent SP check"))newAct->addDamageIns(DmgSrc(DmgSrcType::ELATION,20));
            if(calculateElationOnStats(ptr)>calculateElationOnStats(act->attacker))act->source = ptr;
            newAct->addAttackType(AType::ADDTIONAL);
            attack(newAct);
        }));

        statsAdjustList.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr](AllyUnit* target, Stats statsType) {
            if(!target->isSameName(ptr))return;
            if (statsType == Stats::FLAT_SPD||statsType == Stats::SPD_P) {
                double buffValue = min(200.0,max(0.0,calculateSpeedOnStats(ptr) - 120));

                buffSingleChar(ptr,{{Stats::ELATION, AType::NONE, buffValue - ptr->buffNote["YG A2"]}});
                ptr->buffNote["YG A2"] =  buffValue;
            }
        }));



    }
}
