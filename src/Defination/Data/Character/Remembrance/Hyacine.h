#include "../include.h"

namespace Hyacine{
    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
//temp
    void basicAtk(CharUnit *ptr);
    void skill(CharUnit *ptr);
    void memoSkill(CharUnit *ptr);
    void summonIca(CharUnit *ptr);
    void icaAttack(CharUnit *ptr);
    void beforeHycHeal();
    void afterHycHeal();


    void setup(int eidolon,function<void(CharUnit *ptr)> lc,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = setCharBasicStats(110,140,140,eidolon,ElementType::WIND,Path::REMEMBRANCE,"Hyacine",UnitType::STANDARD);
        ptr->setAllyBaseStats(1087,388,631);
        lc(ptr);
        Relic(ptr);
        Planar(ptr);
        setMemoStats(ptr,0,50,0,0,ElementType::WIND,"Little Ica",UnitType::STANDARD);
        
        AllyUnit *hycPtr = ptr;
        AllyUnit *icaPtr = ptr->getMemosprite();
        //substats
        

        // ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::HP_P);
        ptr->setTotalSubstats(25);
        ptr->setSpeedRequire(210);
        ptr->setRelicMainStats(Stats::HEALING_OUT,Stats::FLAT_SPD,Stats::HP_P,Stats::ER);


        //func
        
        ptr->turnFunc = [ptr,hycPtr,icaPtr](){
            if(sp>spSafety||icaPtr->isDeath()){
                skill(ptr);
            }else{
                basicAtk(ptr);
            }
        };
        ptr->memosprite->turnFunc = [ptr,hycPtr,icaPtr](){
    
            memoSkill(ptr);
            
        };
        ptr->addUltCondition([ptr,hycPtr,icaPtr]() -> bool {
            if(hycPtr->getBuffCheck("After Rain")){
                if(turn->isSameUnit(hycPtr))return true;
                else return false;
            }
            return true;
        });
        ultimateList.push_back(TriggerByYourSelfFunc(PRIORITY_BUFF, ptr, [hycPtr,icaPtr](CharUnit *ptr) {
            shared_ptr<AllyBuffAction> act =
            make_shared<AllyBuffAction>(AType::ULT,ptr,TraceType::AOE,"Hyc Ult",
            [ptr,hycPtr](shared_ptr<AllyBuffAction> &act){
                if(ptr->print)CharCmd::printUltStart("Hyacine");
                summonIca(ptr);
                beforeHycHeal();
                ptr->restoreHP(ptr->getMemosprite(),
                HealSrc(HealSrcType::HP,12,HealSrcType::CONST,240),
                HealSrc(HealSrcType::HP,10,HealSrcType::CONST,200)
                );
                afterHycHeal();
                if(isHaveToAddBuff(hycPtr,"After Rain",3)){
                    buffAllAlly({
                        {Stats::HP_P,AType::NONE,30},
                        {Stats::FLAT_HP,AType::NONE,600},
                    });
                    if(ptr->eidolon>=1)
                    buffAllAlly({
                        {Stats::HP_P,AType::NONE,50},
                    });


                }
                icaAttack(ptr);
            });
            act->addBuffAllAllies();
            act->addActionType(AType::SUMMON);
            act->addToActionBar();
            dealDamage();
        }));

        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [hycPtr,icaPtr](CharUnit *ptr) {
            ptr->atvStats->flatSpeed += 14;
            ptr->statsType[Stats::HP_P][AType::NONE] += 10;
            ptr->statsType[Stats::RES][AType::NONE] += 18;

            ptr->statsType[Stats::CR][AType::NONE] += 100;
        }));


        startGameList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [hycPtr,icaPtr](CharUnit *ptr) {
            if(ptr->technique){
                beforeHycHeal();
                ptr->restoreHP(HealSrc(HealSrcType::HP,30,HealSrcType::CONST,600));
                afterHycHeal();
                buffAllAlly({
                        {Stats::HP_P,AType::NONE,20}
                    },"Day So Right, Life So Fine!",2);
            }
            double spd = calculateSpeedForBuff(hycPtr,100);
            double healout = floor((spd-200.0));
            if(healout <= 0)healout = 0;
            if(spd >= 200&&!hycPtr->getBuffCheck("Hyc A6 MaxHP")){
                buffSingleChar(ptr,{
                    {Stats::HP_P,AType::NONE,20}
                });
                hycPtr->setBuffCheck("Hyc A6 MaxHP",1);
            }else if(spd < 200&&hycPtr->getBuffCheck("Hyc A6 MaxHP")){
                buffSingleChar(ptr,{
                    {Stats::HP_P,AType::NONE,-20}
                });
                hycPtr->setBuffCheck("Hyc A6 MaxHP",0);
            }
            buffSingleChar(ptr,{
                    {Stats::HEALING_OUT,AType::TEMP,healout - hycPtr->getBuffNote("Hyc A6 Healout")},
                    {Stats::HEALING_OUT,AType::NONE,healout - hycPtr->getBuffNote("Hyc A6 Healout")},
            });
            if(ptr->eidolon>=4)
            buffSingleChar(ptr,{
                {Stats::CD,AType::TEMP,(healout - hycPtr->getBuffNote("Hyc A6 Healout"))*2},
                {Stats::CD,AType::NONE,(healout - hycPtr->getBuffNote("Hyc A6 Healout"))*2},
            });

            hycPtr->setBuffNote("Hyc A6 Healout",healout);

        }));

        

        beforeTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [hycPtr,icaPtr](CharUnit *ptr) {
            if(isBuffEnd(hycPtr,"After Rain")){
                if(ptr->print)CharCmd::printUltEnd("Hyacine");
                buffAllAlly({
                        {Stats::HP_P,AType::NONE,-30},
                        {Stats::FLAT_HP,AType::NONE,-600},
                });
                if(ptr->eidolon>=1)
                buffAllAlly({
                    {Stats::HP_P,AType::NONE,-50}
                });
            }
        }));

        afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [hycPtr,icaPtr](CharUnit *ptr) {
            if(isBuffEnd(icaPtr,"First Light Heals the World")){
                buffResetStack(icaPtr,{{Stats::DMG,AType::NONE,80}},"First Light Heals the World");
            }
            AllyUnit *allyptr = turn->canCastToAllyUnit();
            if(!allyptr)return;
            if(isBuffEnd(allyptr,"Day So Right, Life So Fine!")){
                buffSingle(allyptr,{{Stats::HP_P,AType::NONE,-20}});
            }
        }));

        beforeActionList.push_back(TriggerByActionFunc(PRIORITY_IMMEDIATELY, [ptr,hycPtr,icaPtr](shared_ptr<ActionData> &act) {
            for(auto &each :allyList){
                each->setBuffCheck("Ica Talent Heal",0);
            }
            if(act->castToEnemyActionData()){
            hycPtr->setBuffCheck("Ica Talent Trigger",1);
            }
        }));

        afterActionList.push_back(TriggerByActionFunc(PRIORITY_IMMEDIATELY, [ptr,hycPtr,icaPtr](shared_ptr<ActionData> &act) {
            
            if(!hycPtr->getBuffCheck("Ica Talent Trigger"))return;
            hycPtr->setBuffCheck("Ica Talent Trigger",0);
            decreaseHP(icaPtr,icaPtr,0,4,0);
            beforeHycHeal();
            for(auto &each : allyList){
                if(each->getBuffCheck("Ica Talent Heal"))
                icaPtr->restoreHP(each,HealSrc(HealSrcType::HP,4,HealSrcType::CONST,40));
                else
                icaPtr->restoreHP(each,HealSrc(HealSrcType::HP,2,HealSrcType::CONST,20));
                healCount--;
            }
            afterHycHeal();
            healCount++;
        }));

        allyDeathList.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,hycPtr,icaPtr](AllyUnit* target) {
            if(target->isSameName(icaPtr)){
                actionForward(hycPtr->atvStats.get(),30);
            }
            if(isBuffGoneByDeath(target,"First Light Heals the World")){
                buffResetStack(target,{{Stats::DMG,AType::NONE,80}},"First Light Heals the World");
            }
            if(isBuffGoneByDeath(target,"Day So Right, Life So Fine!")){
                buffSingle(target,{{Stats::HP_P,AType::NONE,-20}});
            }
        }));
        
        healingList.push_back(TriggerHealing(PRIORITY_IMMEDIATELY, [ptr,hycPtr,icaPtr](AllyUnit *healer, AllyUnit *target, double value) {
            if(healer->isSameName("Hyacine")||healer->isSameName("Little Ica")){
                buffStackSingle(icaPtr,{
                    {Stats::DMG,AType::NONE,80}
                },1,3,"First Light Heals the World",2);
                icaPtr->buffNote["Tally RestoreHP"] += value;
            }
        }));
        
        hpDecreaseList.push_back(TriggerDecreaseHP(PRIORITY_IMMEDIATELY, [ptr,hycPtr,icaPtr](Unit *trigger, AllyUnit *target, double value) {
            if(target->isSameName(icaPtr))return;
            hycPtr->setBuffCheck("Ica Talent Trigger",1);
            target->setBuffCheck("Ica Talent Heal",1);
        }));

        statsAdjustList.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,hycPtr,icaPtr](AllyUnit* target, Stats statsType) {
            if(!target->isSameName("Hyacine"))return;
            if(statsType!=Stats::SPD_P||statsType!=Stats::FLAT_SPD)return;
            double spd = calculateSpeedForBuff(hycPtr,100);
            double healout = floor((spd-200.0));
            if(healout<=0)healout = 0;
            if(spd >= 200&&!hycPtr->getBuffCheck("Hyc A6 MaxHP")){
                buffSingleChar(ptr,{
                    {Stats::HP_P,AType::NONE,20}
                });
                hycPtr->setBuffCheck("Hyc A6 MaxHP",1);
            }else if(spd < 200&&hycPtr->getBuffCheck("Hyc A6 MaxHP")){
                buffSingleChar(ptr,{
                    {Stats::HP_P,AType::NONE,-20}
                });
                hycPtr->setBuffCheck("Hyc A6 MaxHP",0);
            }
            buffSingleChar(ptr,{
                {Stats::HEALING_OUT,AType::TEMP,healout - hycPtr->getBuffNote("Hyc A6 Healout")},
                {Stats::HEALING_OUT,AType::NONE,healout - hycPtr->getBuffNote("Hyc A6 Healout")},
            });
            if(ptr->eidolon>=4)
            buffSingleChar(ptr,{
                {Stats::CD,AType::TEMP,(healout - hycPtr->getBuffNote("Hyc A6 Healout"))*2},
                {Stats::CD,AType::NONE,(healout - hycPtr->getBuffNote("Hyc A6 Healout"))*2},
            });

            hycPtr->setBuffNote("Hyc A6 Healout",healout);
        }));

        //Eidolon
        if(ptr->eidolon>=1)
        whenAttackList.push_back(TriggerByAllyAttackActionFunc(PRIORITY_IMMEDIATELY, [ptr,hycPtr,icaPtr](shared_ptr<AllyAttackAction> &act) {
            if(hycPtr->getBuffCheck("After Rain")){
                ptr->restoreHP(act->attacker,
                HealSrc(HealSrcType::HP,8)
                );
            }
        }));

        if(ptr->eidolon>=2){
            hpDecreaseList.push_back(TriggerDecreaseHP(PRIORITY_IMMEDIATELY, [ptr,hycPtr,icaPtr](Unit *trigger, AllyUnit *target, double value) {
                buffSingle(target,{{Stats::SPD_P,AType::NONE,30}},"Hyacine E2",2);
            }));

            afterTurnList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [hycPtr,icaPtr](CharUnit *ptr) {
                AllyUnit *allyptr = turn->canCastToAllyUnit();
                if(allyptr&&isBuffEnd(allyptr,"Hyacine E2")){
                    buffSingle(allyptr,{{Stats::SPD_P,AType::NONE,-30}});
                }
            }));    
        }

        if(ptr->eidolon>=6)
        resetList.push_back(TriggerByYourSelfFunc(PRIORITY_IMMEDIATELY, ptr, [hycPtr,icaPtr](CharUnit *ptr) {
            buffAllAlly({
                {Stats::RESPEN,AType::NONE,20}
            });
        }));




        

    }


    void basicAtk(CharUnit *ptr){
        genSkillPoint(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::SINGLE,"Hyc BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,20);
            attack(act);
            icaAttack(ptr);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::HP,50,10));
        act->addToActionBar();
    }
    void skill(CharUnit *ptr){
        genSkillPoint(ptr,-1);
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::AOE,"Hyc Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            increaseEnergy(ptr,30);
            summonIca(ptr);
            beforeHycHeal();
            ptr->restoreHP(ptr->getMemosprite(),
            HealSrc(HealSrcType::HP,10,HealSrcType::CONST,200),
            HealSrc(HealSrcType::HP,8,HealSrcType::CONST,160)
            );
            afterHycHeal();
            icaAttack(ptr);
        });
        act->addActionType(AType::SUMMON);
        act->addBuffAllAllies();
        act->addToActionBar();
    }



    void memoSkill(CharUnit *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr->getMemosprite(),TraceType::AOE,"Ica Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            increaseEnergy(ptr,5);
            attack(act);
            ptr->getMemosprite()->resetATV(-1);
        });
        act->addAttackType(AType::SUMMON);
        act->addDamageIns(
            DmgSrc(DmgSrcType::CONST,ptr->getMemosprite()->getBuffNote("Tally RestoreHP")*0.2,10),
            DmgSrc(DmgSrcType::CONST,ptr->getMemosprite()->getBuffNote("Tally RestoreHP")*0.2,10),
            DmgSrc(DmgSrcType::CONST,ptr->getMemosprite()->getBuffNote("Tally RestoreHP")*0.2,10)
        );
        if(ptr->eidolon>=6)
        ptr->getMemosprite()->buffNote["Tally RestoreHP"] *= 0.88;
        else
        ptr->getMemosprite()->buffNote["Tally RestoreHP"] *= 0.5;
        act->addToActionBar();
    }

    void summonIca(CharUnit *ptr){
        if(!ptr->memosprite->isDeath())return;
        ptr->memosprite->summon(100);
        if(ptr->memosprite->buffCheck["Ica First Summon"]==0){
            ptr->memosprite->buffCheck["Ica First Summon"]=1;
            increaseEnergy(ptr,30);
        }
        increaseEnergy(ptr,15);
    }

    void icaAttack(CharUnit *ptr){
        if(ptr->getBuffCheck("After Rain")){
            ptr->getMemosprite()->resetATV(100);
            actionForward(ptr->getMemosprite()->atvStats.get(),100);
        }
    }

    void beforeHycHeal(){
        for(auto &each : allyList){
            if(each->currentHP*2<=each->totalHP){
                if(isHaveToAddBuff(each,"Hyc A2")){
                    buffSingle(each,{
                        {Stats::HEALING_IN,AType::NONE,25}
                    });
                }
            }
        }
    }
    void afterHycHeal(){
        for(auto &each : allyList){
            if(each->getBuffCheck("Hyc A2")){
                buffSingle(each,{
                    {Stats::HEALING_IN,AType::NONE,-25}
                });
                each->setBuffCheck("Hyc A2",0);
            }
        }
    }
}