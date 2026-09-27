
#include "../include.h"

namespace Castorice{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);

    void basicAttack(CharUnit *ptr);
    void skill(CharUnit *ptr);
    void enchanceSkill(CharUnit *ptr);
    void kamikaze(CharUnit *ptr);
    void driverCondition(CharUnit *ptr, CharUnit *target);
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){

        CharUnit *ptr = setCharBasicStats(95,0,0,eidolon,ElementType::QUANTUM,Path::REMEMBRANCE,"Castorice",UnitType::STANDARD);
        ptr->setAllyBaseStats(1630,524,485);
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        setMemoStats(ptr,34000,0,165,0,ElementType::QUANTUM,"Netherwing",UnitType::BACKUP);
        AllyUnit *casPtr = ptr;
        AllyUnit *polluxPtr = ptr->getMemosprite();

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::HP_P);
        ptr->setTotalSubstats(25);


        //func
        
        ptr->setRelicMainStats(Stats::CD,Stats::HP_P,Stats::HP_P,Stats::HP_P);

        //adjust
        if(ptr->eidolon>=2)ptr->adjust["NetherwingLifeSpan"] = 1;
        else ptr->adjust["NetherwingLifeSpan"] = 3;
        
        ptr->turnFunc = [ptr, allyPtr = ptr]() {

            if (ptr->getMemosprite()->isDeath()) {
                skill(ptr);
            } else {
                enchanceSkill(ptr);
            }
        };
        
        ptr->memosprite->turnFunc = [ptr,casPtr,polluxPtr](){
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr->getMemosprite(),TraceType::AOE,"Pollux Skill",
            [ptr,casPtr,polluxPtr](shared_ptr<AllyAttackAction> &act){
                increaseEnergy(ptr,0);
                while(ptr->getMemosprite()->currentHP>8500){
                    if(ptr->getMemosprite()->stack["Breath Scorches the Shadow"]==0){
                        for(auto &each : act->damageSplit[0]){
                            each.dmgSrc.hp = 24;
                        }
                    }
                    else
                    if(ptr->getMemosprite()->stack["Breath Scorches the Shadow"]==1){
                        for(auto &each : act->damageSplit[0]){
                            each.dmgSrc.hp = 28;
                        }
                    }
                    else
                    {
                        for(auto &each : act->damageSplit[0]){
                            each.dmgSrc.hp = 34;
                        }
                    }
                    if(ptr->eidolon>=1){
                        for(auto &each : act->damageSplit[0]){
                            each.dmgSrc.hp *= 1.239;
                        }
                    }
                    ptr->getMemosprite()->stack["Breath Scorches the Shadow"]++;
                    buffStackSingle(polluxPtr,{{Stats::DMG,AType::NONE,30}},1,6,"Where The West Wind Dwells");
                    attack(act);
                    if(ptr->getMemosprite()->getStack("Ardent Will")>0)
                    ptr->getMemosprite()->stack["Ardent Will"]--;
                    else 
                    ptr->getMemosprite()->currentHP-=8500;
                }
                if(isBuffEnd(polluxPtr,"NetherwingLifeSpan")){
                    if(ptr->getMemosprite()->stack["Breath Scorches the Shadow"]==0){
                        for(auto &each : act->damageSplit[0]){
                            each.dmgSrc.hp = 24;
                        }
                    }
                    else
                    if(ptr->getMemosprite()->stack["Breath Scorches the Shadow"]==1){
                        for(auto &each : act->damageSplit[0]){
                            each.dmgSrc.hp = 28;
                        }
                    }
                    else
                    {
                        for(auto &each : act->damageSplit[0]){
                            each.dmgSrc.hp = 34;
                        }
                    }
                    buffStackSingle(polluxPtr,{{Stats::DMG,AType::NONE,30}},1,6,"Where The West Wind Dwells");
                }else{
                    for(auto &each : act->damageSplit[0]){
                            each.dmgSrc.hp = 40;
                        }
                }
                if(ptr->eidolon>=1){
                    for(auto &each : act->damageSplit[0]){
                        each.dmgSrc.hp *= 1.239;
                    }
                }
                attack(act);
            });
            act->addAttackType(AType::SUMMON);
            if(ptr->eidolon>=6)act->dontCareWeakness = 100;
            act->source = ptr;
            act->addDamageIns(
                DmgSrc(DmgSrcType::HP,24,10),
                DmgSrc(DmgSrcType::HP,24,10),
                DmgSrc(DmgSrcType::HP,24,10)
            );
            act->addToActionBar();
        };

        
        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [casPtr,polluxPtr](CharUnit *ptr) {
            ptr->statsType[Stats::CD][AType::NONE] += 13.3;
            ptr->statsType[Stats::CR][AType::NONE] += 18.7;
            ptr->statsEachElement[Stats::DMG][ElementType::QUANTUM][AType::NONE] += 14.4;
        }));
        
        ptr->addUltCondition([ptr,casPtr,polluxPtr]() -> bool {
            if(ptr->buffNote["Newbud"] >= 34000)return true;
            return false;
        });
        ptr->addUltCondition([ptr,casPtr,polluxPtr]() -> bool {
            if(ptr->getMemosprite()->isDeath())return true;
            return false;
        });

        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [casPtr,polluxPtr](CharUnit *ptr) {
            ptr->buffNote["Newbud"] = 0;

            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::ULT,ptr,TraceType::SINGLE,"Cas Ult",
            [ptr,casPtr,polluxPtr](shared_ptr<AllyBuffAction> &act){
                if(ptr->print)CharCmd::printUltStart("Castorice");
                debuffAllEnemyMark({{Stats::RESPEN,AType::NONE,20}},polluxPtr,"Lost Netherland");
                ptr->getMemosprite()->summon(100);
                actionForward(ptr->getMemosprite()->atvStats.get(),100);
                extendBuffTime(polluxPtr,"NetherwingLifeSpan",ptr->adjust["NetherwingLifeSpan"]);
                buffAllAlly({{Stats::DMG,AType::NONE,10}},"Roar Rumbles the Realm",3);
                if(ptr->eidolon>=2){
                    ptr->getMemosprite()->setStack("Ardent Will",2);
                    actionForward(ptr->atvStats.get(),100);
                    ptr->buffNote["Newbud"] = 10200;
                }
            });
            act->addBuffSingleTarget(ptr);
            act->addToActionBar();
            dealDamage();
        }));
        

        whenOnFieldList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [casPtr,polluxPtr](CharUnit *ptr) {
            if(ptr->eidolon>=4){
                buffAllAlly({{Stats::HEALING_IN,AType::NONE,20}});
            }
            if(ptr->eidolon>=6){
                buffSingleChar(ptr,{{Stats::RESPEN,AType::NONE,20}});
            }
        }));

        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [casPtr,polluxPtr](CharUnit *ptr) {
            if(ptr->technique==1){
                debuffAllEnemyMark({{Stats::RESPEN,AType::NONE,20}},polluxPtr,"Lost Netherland");
                

                ptr->getMemosprite()->summon(50);
                actionForward(ptr->getMemosprite()->atvStats.get(),100);
                turn = ptr->getMemosprite()->atvStats.get();
                extendBuffTime(polluxPtr,"NetherwingLifeSpan",1);
                decreaseHP(ptr,"Netherwing",0,0,40);
                buffAllAlly({{Stats::DMG,AType::NONE,10}},"Roar Rumbles the Realm",3);
                if(ptr->eidolon>=2){
                    ptr->getMemosprite()->setStack("Ardent Will",2);
                    actionForward(ptr->atvStats.get(),100);
                    ptr->buffNote["Newbud"] = 10200;
                }
            }
            else
            {
                ptr->buffNote["Newbud"]=10200;
            }
            if(!ptr->getBuffCheck("Inverted Torch")&&ptr->currentHP>=ptr->totalHP*0.5){
                buffSingle(casPtr,{{Stats::SPD_P,AType::NONE,40}});
                ptr->setBuffCheck("Inverted Torch",true);
            }
        }));

        healingList.push_back(TriggerHealing(PRIORITY_IMMEDIATELY, [ptr,casPtr,polluxPtr](AllyUnit *healer, AllyUnit *target, double value) {
            if(target->isSameName("Netherwing"))return;
            value = (value + target->getBuffNote("NetherwingHealLimit") > 4080) 
            ? 4080 - target->getBuffNote("NetherwingHealLimit")
            : value;
            target->buffNote["NetherwingHealLimit"]+=value;
            if(ptr->getMemosprite()->isDeath()){
                ptr->buffNote["Newbud"]+=value;
            }
            else {
                ptr->getMemosprite()->restoreHP(ptr->getMemosprite(),HealSrc(HealSrcType::CONST,value));
            }
            if(target->isSameName("Castorice")){
                if(!ptr->getBuffCheck("Inverted Torch")&&ptr->currentHP>=ptr->totalHP*0.5){
                buffSingle(casPtr,{{Stats::SPD_P,AType::NONE,40}});
                ptr->setBuffCheck("Inverted Torch",true);
                }
            }
            
        }));

        hpDecreaseList.push_back(TriggerDecreaseHP(PRIORITY_IMMEDIATELY, [ptr,casPtr,polluxPtr](Unit *trigger, AllyUnit *target, double value) {
            if(ptr->getMemosprite()->isDeath()){
                ptr->buffNote["Newbud"]+=value;
            }else {
                ptr->getMemosprite()->restoreHP(ptr->getMemosprite(),HealSrc(HealSrcType::CONST,value));
            }
            if(ptr->buffNote["CastoriceTalentBuff"]!=decreaseHPCount){
                ptr->buffNote["CastoriceTalentBuff"] = decreaseHPCount;
                buffStackChar(ptr,{{Stats::DMG,AType::NONE,20}},1,3,"CastoriceTalentBuff",3);
            }
            if(target->isSameName("Castorice")){
                if(ptr->getBuffCheck("Inverted Torch")&&ptr->currentHP<ptr->totalHP*0.5){
                    buffSingle(casPtr,{{Stats::SPD_P,AType::NONE,-40}});
                    ptr->setBuffCheck("Inverted Torch",false);
                }
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [casPtr,polluxPtr](CharUnit *ptr) {
            
            if(isBuffEnd(polluxPtr,"NetherwingLifeSpan")){
                kamikaze(ptr);
            }
            if(turn->isSameName("Netherwing")){
                buffResetStack(polluxPtr,{{Stats::DMG,AType::NONE,30}},"Where The West Wind Dwells");
            }
            AllyUnit *tempUnit = turn->canCastToAllyUnit();
            if(tempUnit){
                if(isBuffEnd(tempUnit,"Roar Rumbles the Realm")){
                    buffSingle(tempUnit,{{Stats::DMG,AType::NONE,-10}});
                }
                if(isBuffEnd(tempUnit,"CastoriceTalentBuff")){
                    buffResetStack(tempUnit,{{Stats::DMG,AType::NONE,20}},"CastoriceTalentBuff");
                }
            }
            
        }));

        buffList.push_back(TriggerByAllyBuffActionFunc(PRIORITY_ACTION, [ptr,casPtr,polluxPtr](shared_ptr<AllyBuffAction> &act) {
            for(auto &e : allyList){
                e->buffNote["NetherwingHealLimit"] = 0;
            }
        }));

        beforeAttackActionList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_ACTION, [ptr,casPtr,polluxPtr](shared_ptr<AllyAttackAction> &act) {
            for(auto &e : allyList){
                e->buffNote["NetherwingHealLimit"] = 0;
            }
        }));
        
        statsAdjustList.push_back(TriggerByStats(PRIORITY_ACTION, [ptr,casPtr,polluxPtr](AllyUnit* target, Stats statsType) {
            if(!target->isSameName("Netherwing"))return;
            if(statsType != Stats::FLAT_HP && statsType != Stats::HP_P)return;
            double temp;
            temp = 34000 - calculateHpOnStats(ptr->getMemosprite());
            buffSingle(polluxPtr,{{Stats::FLAT_HP,AType::NONE,temp}});
            
        }));

        allyDeathList.push_back(TriggerAllyDeath(PRIORITY_ACTION, [ptr,casPtr,polluxPtr](AllyUnit* target) {
            if(isBuffGoneByDeath(target,"Roar Rumbles the Realm")){
                buffSingle(target,{{Stats::DMG,AType::NONE,-10}});
            }
        }));
    }
    void basicAttack(CharUnit *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Cas BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::HP,50,10)
        );
        act->addToActionBar();
    }
    void skill(CharUnit *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::BLAST,"Cas Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,0);
            decreaseHP(ptr,"Netherwing",0,0,30);
            attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::HP,50,20),
            DmgSrc(DmgSrcType::HP,30,10)
        );
        
        act->addToActionBar();
    }
    void enchanceSkill(CharUnit *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::AOE,"Cas ESkill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,0);
            decreaseHP(ptr,"Netherwing",0,0,40);
            if(ptr->eidolon>=1){
                for(auto &each1 : act->damageSplit){
                    for(auto &each2 : each1){
                        each2.dmgSrc.hp *= 1.239;
                    }
                }
            }
            attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::HP,30,10),
            DmgSrc(DmgSrcType::HP,30,10),
            DmgSrc(DmgSrcType::HP,30,10)
        );
        act->addDamageIns(
            DmgSrc(DmgSrcType::HP,50,10),
            DmgSrc(DmgSrcType::HP,50,10),
            DmgSrc(DmgSrcType::HP,50,10)
        );
        act->setJoint();
        act->switchAttacker.push_back(SwitchAtk(1,ptr,1));
        act->addToActionBar();
    }
    void kamikaze(CharUnit *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr->getMemosprite(),TraceType::BOUNCE,"Pullux Kamikaze",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,0);
            attack(act);
            ptr->restoreHP(HealSrc(HealSrcType::HP,6,HealSrcType::CONST,800));
            for(auto &each : enemyList){
                debuffRemove(each,"Lost Netherland"); 
                debuffSingle(each,{{Stats::RESPEN,AType::NONE,-20}});
            }
            ptr->getMemosprite()->death();
            ptr->getMemosprite()->setStack("Breath Scorches the Shadow",0);
            if(ptr->print)CharCmd::printUltEnd("Castorice");
        });
        act->addAttackType(AType::SUMMON);
        act->source = ptr;
        if(ptr->eidolon>=6){
            act->addEnemyBounce(DmgSrc(DmgSrcType::HP,40,5),9);
            act->dontCareWeakness = 100;
        }else{
            act->addEnemyBounce(DmgSrc(DmgSrcType::HP,40,5),6);
        }
        if(ptr->eidolon>=1){
            for(auto &each1 : act->damageSplit){
                for(auto &each2 : each1){
                    each2.dmgSrc.hp *= 1.239;
                }
            }
        }
        act->addToActionBar();
        dealDamage();
        
    }
    void driverCondition(CharUnit *ptr, CharUnit *target) {
        target->ultCondition.push_back([ptr, target]() -> bool {
            if(ptr->getMemosprite()->isDeath())return false;
            return true;
        });
    }
    void healerCondition(CharUnit *ptr, CharUnit *target) {
        target->ultCondition.push_back([ptr, target]() -> bool {
            if(ptr->buffNote["Newbud"] >= 34000||ptr->getMemosprite()->currentHP==34000)return false;
            return true;
        });
    }
    void castoriceWithDriver(CharUnit *ptr, CharUnit *target) {
        ptr->ultCondition.push_back([ptr, target]() -> bool {
            if(target->atvStats->atv>=10000/165)return true;
            // if(target->atvStats->atv>=10)return true;
            if(turn->isSameUnit(target)&&phaseStatus == PhaseStatus::BEFORE_TURN)return true;
            return false;
        });
    } 

}
#