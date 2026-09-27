#include "../include.h"

namespace RuanMei{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
    void basicAtk(CharUnit *ptr);  
    void skillFunc(CharUnit *ptr);
    
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(104, 130, 130, eidolon, ElementType::ICE, Path::HARMONY, "Ruan_Mei",UnitType::STANDARD);
        AllyUnit *rmPtr = ptr;
        ptr->setAllyBaseStats(1087, 660, 485);
        //func
        lc(ptr);
        Relic(ptr);
        Planar(ptr);

        //substats
        ptr->pushSubstats(Stats::BE);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(140);
        ptr->setRelicMainStats(Stats::ATK_P,Stats::FLAT_SPD,Stats::ATK_P,Stats::ER);

        
        
        ptr->turnFunc = [ptr,allyptr = ptr ]() {
            if (allyptr->buffCheck["Mei_Skill"] == 0) {
                skillFunc(ptr);
            } else {
                basicAtk(ptr);
            }
        };

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [rmPtr](CharUnit *ptr){

            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::ULT,ptr,TraceType::AOE,"RM Ult",
            [ptr,rmPtr](shared_ptr<AllyBuffAction> &act){
                if(ptr->print)CharCmd::printUltStart("Ruan Mei");
                if(isHaveToAddBuff(rmPtr,"RuanMei_Ult",2)){
                    buffAllAlly({{Stats::RESPEN, AType::NONE, 25}});
                    if(ptr->eidolon >= 1)buffAllAlly({{Stats::DEF_SHRED, AType::NONE, 20}});
                }
            });
            act->addBuffAllAllies();
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr){
            ptr->statsType[Stats::BE][AType::NONE] += 37.3;
            ptr->statsType[Stats::DEF_P][AType::NONE] += 22.5;
            ptr->atvStats->flatSpeed += 5;

            // relic

            // substats
        }));

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr){
            buffAllAlly({
                {Stats::BE, AType::NONE, 20},
            });
            buffAllAllyExcludingBuffer(ptr,{{Stats::SPD_P,AType::NONE,10}});
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_ACTION, ptr, [](CharUnit *ptr){
            if(ptr->technique == 1){
            
                shared_ptr<AllyBuffAction> act = 
                make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::SINGLE,"RM SKill",
                [ptr](shared_ptr<AllyBuffAction> &act){
                    increaseEnergy(ptr,30);
                    buffAllAlly({
                        {Stats::DMG,AType::NONE,68},
                        {Stats::BREAK_EFF,AType::NONE,50},
                    });
                    isHaveToAddBuff(ptr,"Mei_Skill",3);
                });
                act->addBuffSingleTarget(ptr);
                act->setTurnReset(false);
                act->addToActionBar();
                dealDamage();
                return;
            }
        }));

        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [rmPtr](CharUnit *ptr){
            if(isBuffEnd(rmPtr,"Mei_Skill")){
                buffAllAlly({
                    {Stats::DMG,AType::NONE,-68},
                    {Stats::BREAK_EFF,AType::NONE,-50},
                });
            }
            if(turn->name == "Ruan_Mei"){
                increaseEnergy(ptr, 5);
                if(isBuffEnd(rmPtr,"RuanMei_Ult")){
                    buffAllAlly({{Stats::RESPEN, AType::NONE, -25}});
                    if(ptr->eidolon >= 1)buffAllAlly({{Stats::DEF_SHRED, AType::NONE, -20}});
                    if(ptr->print == 1)CharCmd::printUltEnd("Ruan Mei");
                }
            }
            if(turn->side == Side::ENEMY && turnSkip == 0){
                if(enemyUnit[turn->num]->debuffCheck["RuanMei_Ult_bloom"] == 1){
                    turnSkip = 1;
                    debuffRemove(enemyUnit[turn->num].get(),"RuanMei_Ult_bloom");
                    actionForward(enemyUnit[turn->num]->atvStats.get(), -10 -calculateBreakEffectForBuff(ptr,20));
                    shared_ptr<AllyAttackAction> act = 
                    make_shared<AllyAttackAction>(AType::BREAK,ptr,TraceType::SINGLE,"RM Ult Break");
                    double temp = 0.5;
                    calBreakDamage(act, enemyUnit[turn->num].get(), temp);
                }
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [](CharUnit *ptr){
        }));

        afterAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,rmPtr](shared_ptr<AllyAttackAction> &act){
            if(rmPtr->getBuffCheck("RuanMei_Ult")){
                for(Enemy * &e : act->targetList){
                    debuffApply(ptr,e,"RuanMei_Ult_bloom");
                }
            }
        }));

        toughnessBreakList.push_back(TriggerBySomeAllyFunc(PRIORITY_IMMEDIATELY, [ptr](Enemy *target, AllyUnit *breaker){
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::BREAK,ptr,TraceType::SINGLE,"RM Talent Break");
            double temp;
            temp = 1.2;
            calBreakDamage(act, target, temp);
        }));
    
    }



    void basicAtk(CharUnit *ptr){
        genSkillPoint(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"RM BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,20);
            attack(act);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::ATK,100,10));
        act->addToActionBar();
    }
    void skillFunc(CharUnit *ptr){
        genSkillPoint(ptr,-1);
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::SINGLE,"RM Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            increaseEnergy(ptr,30);
            buffAllAlly({
                {Stats::DMG,AType::NONE,68},
                {Stats::BREAK_EFF,AType::NONE,50},
            });
            isHaveToAddBuff(ptr,"Mei_Skill",3);
        });
        act->addBuffSingleTarget(ptr);
        act->addToActionBar();
    }
}
