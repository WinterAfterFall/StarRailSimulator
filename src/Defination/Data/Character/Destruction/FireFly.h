#include "../include.h"

namespace FireFly{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void skillFunc(CharUnit *ptr);
    void enchanceSkillFunc(CharUnit *ptr);
    vector<BuffClass> combustionBuff(CharUnit *ptr, double sign);


    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats( 104, 240, 240, eidolon, ElementType::FIRE, Path::DESTRUCTION, "FireFly", UnitType::STANDARD);
        AllyUnit *ffPtr = ptr;
        ptr->setAllyBaseStats( 814, 523, 776);

        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);

        //substats
        ptr->pushSubstats(Stats::BE);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(150);
        ptr->setRelicMainStats(Stats::ATK_P,Stats::FLAT_SPD,Stats::ATK_P,Stats::BE);


        ptr->turnFunc = [ptr] (){
            if(ptr->countdownList[0]->isDeath()){
                skillFunc(ptr);
            }else {
                enchanceSkillFunc(ptr);
            }
        };
        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            ptr->statsType[Stats::BE][AType::NONE] += 37.3;
            ptr->statsType[Stats::RES][AType::NONE] += 18;
            ptr->atvStats->flatSpeed += 5;

            // relic

            // substats

            // eidolon
            // E2: start with 2 free extra turns (assume 2 kills per fight)
            if (ptr->eidolon >= 2) {
            ptr->stack["FireFly_E2"] = 2;
            }
        }));

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_DEBUFF, ptr, [ffPtr](CharUnit *ptr) {
            buffSingle(ffPtr,combustionBuff(ptr,1));
            ptr->setStack("FireFly A2 delay",0);
            actionForward(ffPtr->atvStats.get(), 100);
            ptr->countdownList[0]->summon();
            if (ptr->print)CharCmd::printUltStart("FireFly");
            }
        ));
        // Ultimate: cannot be used while in Complete Combustion
        ptr->addUltCondition([ptr]() -> bool {
            return ptr->countdownList[0]->isDeath();
        });

        // A6: every 10 ATK above 1800 -> BE +0.8%
        statsAdjustList.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,ffPtr](AllyUnit *target, Stats statsType) {
            if (target->atvStats->name != "FireFly") return;
            if (statsType == Stats::ATK_P || statsType == Stats::FLAT_ATK) {
            double temp = 0;
            temp = floor(((ptr->statsType[Stats::ATK_P][AType::NONE] / 100 * ptr->baseAtk + ptr->baseAtk) + ptr->statsType[Stats::FLAT_ATK][AType::NONE] - 1800) / 10) * 0.8;
            if (temp <= 0)temp = 0;
            buffSingle(ffPtr,
                {
                    {Stats::BE,AType::TEMP,temp - ffPtr->buffNote["FireFly_ModuleY"]},
                    {Stats::BE,AType::NONE,temp - ffPtr->buffNote["FireFly_ModuleY"]}
                });
            ptr->buffNote["FireFly_ModuleY"] = temp;

            }
        }));

        toughnessBreakList.push_back(TriggerBySomeAllyFunc(PRIORITY_IMMEDIATELY, [ptr] (Enemy *target, AllyUnit *breaker) {
            if (ptr->atvStats->num != breaker->atvStats->num || ptr->countdownList[0]->isDeath()) return;
            if (ptr->eidolon >= 2) {
                ptr->stack["FireFly_E2"]++;
            }
            // A2: Weakness Break during Combustion delays the countdown by 10% (max 3 per Combustion)
            if (ptr->getStack("FireFly A2 delay") < 3) {
                ptr->addStack("FireFly A2 delay",1);
                actionForward(ptr->countdownList[0].get(), -10);
            }
            }
        ));

        startWaveList.push_back(TriggerByYourSelfFunc(PRIORITY_ACTTACK, ptr, [](CharUnit *ptr) {
            if (ptr->technique == 1) {
            shared_ptr<AllyAttackAction> act =
            make_shared<AllyAttackAction>(AType::TECHNIQUE,ptr,TraceType::AOE,"FF Tech",
            [ptr](shared_ptr<AllyAttackAction> &act){
                for(auto &each : act->targetList){
                    weaknessApply(ptr,each,{ElementType::FIRE},"FireFly Weakness",2);
                }
                attack(act);
            });
            act->addDamageIns(
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20),
                DmgSrc(DmgSrcType::ATK,200,20)
            );
            act->addToActionBar();
            dealDamage();
            }
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            allEventAdjustStats(ptr, Stats::FLAT_ATK);
            // Talent: energy below 50% at battle start -> set to 50%
            if (ptr->currentEnergy < ptr->maxEnergy / 2) ptr->currentEnergy = ptr->maxEnergy / 2;
        }));

        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            if (turn->isSameUnit(ptr)) ptr->setBuffCheck("FireFly_E2_used",0);
        }));

        afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_ACTTACK, [ptr]( shared_ptr<AllyAttackAction> &act ) {
            if (!act->isSameAction(ptr,AType::SKILL)) return;
            if (ptr->countdownList[0]->isDeath()) return;
            // E2: extra turn after Enhanced Skill kills/breaks, once per turn
            if (ptr->eidolon >= 2 && ptr->stack["FireFly_E2"] > 0 && !ptr->getBuffCheck("FireFly_E2_used")) {
            ptr->stack["FireFly_E2"]--;
            ptr->setBuffCheck("FireFly_E2_used",1);
            actionForward(ptr->atvStats.get(), 100);
            }
            // A4: during Combustion, BE >= 150%/300% -> Super Break 100%/150%
            if (ptr->statsType[Stats::BE][AType::NONE] >= 300) {
                superbreakTrigger(act, 150,"A4");
            } else if (ptr->statsType[Stats::BE][AType::NONE] >= 150) {
                superbreakTrigger(act, 100,"A4");
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr) {
            Enemy *enemy = turn->canCastToEnemy();
            if(!enemy)return;
            isDebuffEnd(enemy,"FireFly Weakness");
        }));



        //countdown
        setCountdownStats(ptr,70, "Combustion_state");
        ptr->countdownList[0]->turnFunc = [ptr,ffPtr](){


            if(ptr->print)CharCmd::printUltEnd("FireFly");
            buffSingle(ffPtr,combustionBuff(ptr,-1));
            ptr->countdownList[0]->death();
        };
    }

    // Complete Combustion: SPD +60 · Break Efficiency +50% · Break DMG +20% · A2 BE +25% · Talent Effect RES +30%
    // E1 Enhanced Skill ignores 15% DEF · E6 RES PEN +20% + Break Efficiency +50%
    vector<BuffClass> combustionBuff(CharUnit *ptr, double sign){
        vector<BuffClass> buff = {
            {Stats::FLAT_SPD,AType::NONE,60*sign},
            {Stats::BREAK_EFF,AType::NONE,50*sign},
            {Stats::VUL,AType::BREAK,20*sign},
            {Stats::BE,AType::NONE,25*sign},
            {Stats::RES,AType::NONE,30*sign},
        };
        if (ptr->eidolon >= 1) buff.push_back({Stats::DEF_SHRED,AType::SKILL,15*sign});
        if (ptr->eidolon >= 4) buff.push_back({Stats::RES,AType::NONE,50*sign});
        if (ptr->eidolon >= 6) {
            buff.push_back({Stats::RESPEN,AType::NONE,20*sign});
            buff.push_back({Stats::BREAK_EFF,AType::NONE,50*sign});
        }
        return buff;
    }

    void skillFunc(CharUnit *ptr){
        genSkillPoint(ptr,-1);
        shared_ptr<AllyAttackAction> act =
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::SINGLE,"FF Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,60,0);
            attack(act);
            actionForward(ptr->atvStats.get(), 25);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,80,8));
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,120,12));
        act->addToActionBar();


    }
    void enchanceSkillFunc(CharUnit *ptr){
        if(ptr->eidolon<1)genSkillPoint(ptr,-1);
        shared_ptr<AllyAttackAction> act =
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::BLAST,"FF ESkill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            double skillDmg = 0;
            if(ptr->statsType[Stats::BE][AType::NONE]>=360){
                skillDmg = 272;
            }else{
                skillDmg = 200 + (ptr->statsType[Stats::BE][AType::NONE])*0.2;
            }

            // hit split 15/15/15/15/40 · adjacent = half of main
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,0.15*skillDmg,4.5),DmgSrc(DmgSrcType::ATK,0.15*0.5*skillDmg,2.25));
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,0.15*skillDmg,4.5),DmgSrc(DmgSrcType::ATK,0.15*0.5*skillDmg,2.25));
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,0.15*skillDmg,4.5),DmgSrc(DmgSrcType::ATK,0.15*0.5*skillDmg,2.25));
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,0.15*skillDmg,4.5),DmgSrc(DmgSrcType::ATK,0.15*0.5*skillDmg,2.25));
            act->addDamageIns(DmgSrc(DmgSrcType::ATK,0.4*skillDmg,12),DmgSrc(DmgSrcType::ATK,0.4*0.5*skillDmg,6));

            for(auto &each : act->targetList){
                weaknessApply(ptr,each,{ElementType::FIRE},"FireFly Weakness",2);
            }
            attack(act);
        });
        act->addToActionBar();
    }
}
