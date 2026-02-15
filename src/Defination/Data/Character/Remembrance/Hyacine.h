#include "../include.h"

namespace Hyacine{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);
//temp
    void Basic_Atk(CharUnit *ptr);
    void Skill(CharUnit *ptr);
    void Memo_Skill(CharUnit *ptr);
    void SummonIca(CharUnit *ptr);
    void IcaAttack(CharUnit *ptr);
    void BeforeHycHeal();
    void AfterHycHeal();


    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){
        CharUnit *ptr = SetCharBasicStats(110,140,140,E,ElementType::Wind,Path::Remembrance,"Hyacine",UnitType::Standard);
        ptr->SetAllyBaseStats(1087,388,631);
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        SetMemoStats(ptr,0,50,0,0,ElementType::Wind,"Little Ica",UnitType::Standard);
        
        AllyUnit *Hycptr = ptr;
        AllyUnit *Icaptr = ptr->getMemosprite();
        //substats
        

        // ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::HP_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(210);
        ptr->setRelicMainStats(Stats::HEALING_OUT,Stats::FLAT_SPD,Stats::HP_P,Stats::ER);


        //func
        
        ptr->Turn_func = [ptr,Hycptr,Icaptr](){
            if(sp>Sp_Safety||Icaptr->isDeath()){
                Skill(ptr);
            }else{
                Basic_Atk(ptr);
            }
        };
        ptr->memospriteList[0]->Turn_func = [ptr,Hycptr,Icaptr](){
    
            Memo_Skill(ptr);
            
        };
        ptr->addUltCondition([ptr,Hycptr,Icaptr]() -> bool {
            if(Hycptr->getBuffCheck("After Rain")){
                if(turn->isSameUnit(Hycptr))return true;
                else return false;
            }
            return true;
        });
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,Hycptr,Icaptr]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::Ult,ptr,TraceType::Aoe,"Hyc Ult",
            [ptr,Hycptr](shared_ptr<AllyBuffAction> &act){
                if(ptr->Print)CharCmd::printUltStart("Hyacine");
                SummonIca(ptr);
                BeforeHycHeal();
                ptr->RestoreHP(ptr->getMemosprite(),
                HealSrc(HealSrcType::HP,12,HealSrcType::CONST,240),
                HealSrc(HealSrcType::HP,10,HealSrcType::CONST,200)
                );
                AfterHycHeal();
                if(isHaveToAddBuff(Hycptr,"After Rain",3)){
                    buffAllAlly({
                        {Stats::HP_P,AType::None,30},
                        {Stats::FLAT_HP,AType::None,600},
                    });
                    if(ptr->Eidolon>=1)
                    buffAllAlly({
                        {Stats::HP_P,AType::None,50},
                    });
                    

                }
                IcaAttack(ptr);
            });
            act->addBuffAllAllies();
            act->addActionType(AType::Summon);
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr]() {
            ptr->Atv_stats->flatSpeed += 14;
            ptr->Stats_type[Stats::HP_P][AType::None] += 10;
            ptr->Stats_type[Stats::RES][AType::None] += 18;

            ptr->Stats_type[Stats::CR][AType::None] += 100;
        }));


        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr]() {
            if(ptr->Technique){
                BeforeHycHeal();
                ptr->RestoreHP(HealSrc(HealSrcType::HP,30,HealSrcType::CONST,600));
                AfterHycHeal();
                buffAllAlly({
                        {Stats::HP_P,AType::None,20}
                    },"Day So Right, Life So Fine!",2);
            }
            double spd = calculateSpeedForBuff(Hycptr,100);
            double healout = floor((spd-200.0));
            if(healout <= 0)healout = 0;
            if(spd >= 200&&!Hycptr->getBuffCheck("Hyc A6 MaxHP")){
                buffSingleChar(ptr,{
                    {Stats::HP_P,AType::None,20}
                });
                Hycptr->setBuffCheck("Hyc A6 MaxHP",1);
            }else if(spd < 200&&Hycptr->getBuffCheck("Hyc A6 MaxHP")){
                buffSingleChar(ptr,{
                    {Stats::HP_P,AType::None,-20}
                });
                Hycptr->setBuffCheck("Hyc A6 MaxHP",0);
            }
            buffSingleChar(ptr,{
                    {Stats::HEALING_OUT,AType::TEMP,healout - Hycptr->getBuffNote("Hyc A6 Healout")},
                    {Stats::HEALING_OUT,AType::None,healout - Hycptr->getBuffNote("Hyc A6 Healout")},
            });
            if(ptr->Eidolon>=4)
            buffSingleChar(ptr,{
                {Stats::CD,AType::TEMP,(healout - Hycptr->getBuffNote("Hyc A6 Healout"))*2},
                {Stats::CD,AType::None,(healout - Hycptr->getBuffNote("Hyc A6 Healout"))*2},
            });

            Hycptr->setBuffNote("Hyc A6 Healout",healout);

        }));

        

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr]() {
            if(isBuffEnd(Hycptr,"After Rain")){
                if(ptr->Print)CharCmd::printUltEnd("Hyacine");
                buffAllAlly({
                        {Stats::HP_P,AType::None,-30},
                        {Stats::FLAT_HP,AType::None,-600},
                });
                if(ptr->Eidolon>=1)
                buffAllAlly({
                    {Stats::HP_P,AType::None,-50}
                });
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr]() {
            if(isBuffEnd(Icaptr,"First Light Heals the World")){
                buffResetStack(Icaptr,{{Stats::DMG,AType::None,80}},"First Light Heals the World");
            }
            AllyUnit *allyptr = turn->canCastToSubUnit();
            if(!allyptr)return;
            if(isBuffEnd(allyptr,"Day So Right, Life So Fine!")){
                buffSingle(allyptr,{{Stats::HP_P,AType::None,-20}});
            }
        }));

        BeforeAction_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr](shared_ptr<ActionData> &act) {
            for(auto &each :allyList){
                each->setBuffCheck("Ica Talent Heal",0);
            }
            if(act->castToEnemyActionData()){
            Hycptr->setBuffCheck("Ica Talent Trigger",1);
            }
        }));

        AfterAction_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr](shared_ptr<ActionData> &act) {
            
            if(!Hycptr->getBuffCheck("Ica Talent Trigger"))return;
            Hycptr->setBuffCheck("Ica Talent Trigger",0);
            DecreaseHP(Icaptr,Icaptr,0,4,0);
            BeforeHycHeal();
            for(auto &each : allyList){
                if(each->getBuffCheck("Ica Talent Heal"))
                Icaptr->RestoreHP(each,HealSrc(HealSrcType::HP,4,HealSrcType::CONST,40));
                else
                Icaptr->RestoreHP(each,HealSrc(HealSrcType::HP,2,HealSrcType::CONST,20));
                healCount--;
            }
            AfterHycHeal();
            healCount++;
        }));

        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr](AllyUnit* target) {
            if(target->isSameName(Icaptr)){
                Action_forward(Hycptr->Atv_stats.get(),30);
            }
            if(isBuffGoneByDeath(target,"First Light Heals the World")){
                buffResetStack(target,{{Stats::DMG,AType::None,80}},"First Light Heals the World");
            }
            if(isBuffGoneByDeath(target,"Day So Right, Life So Fine!")){
                buffSingle(target,{{Stats::HP_P,AType::None,-20}});
            }
        }));
        
        Healing_List.push_back(TriggerHealing(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr](AllyUnit *Healer, AllyUnit *target, double Value) {
            if(Healer->isSameName("Hyacine")||Healer->isSameName("Little Ica")){
                buffStackSingle(Icaptr,{
                    {Stats::DMG,AType::None,80}
                },1,3,"First Light Heals the World",2);
                Icaptr->Buff_note["Tally RestoreHP"] += Value;
            }
        }));
        
        HPDecrease_List.push_back(TriggerDecreaseHP(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr](Unit *Trigger, AllyUnit *target, double Value) {
            if(target->isSameName(Icaptr))return;
            Hycptr->setBuffCheck("Ica Talent Trigger",1);
            target->setBuffCheck("Ica Talent Heal",1);
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr](AllyUnit* Target, Stats StatsType) {
            if(!Target->isSameName("Hyacine"))return;
            if(StatsType!=Stats::SPD_P||StatsType!=Stats::FLAT_SPD)return;
            double spd = calculateSpeedForBuff(Hycptr,100);
            double healout = floor((spd-200.0));
            if(healout<=0)healout = 0;
            if(spd >= 200&&!Hycptr->getBuffCheck("Hyc A6 MaxHP")){
                buffSingleChar(ptr,{
                    {Stats::HP_P,AType::None,20}
                });
                Hycptr->setBuffCheck("Hyc A6 MaxHP",1);
            }else if(spd < 200&&Hycptr->getBuffCheck("Hyc A6 MaxHP")){
                buffSingleChar(ptr,{
                    {Stats::HP_P,AType::None,-20}
                });
                Hycptr->setBuffCheck("Hyc A6 MaxHP",0);
            }
            buffSingleChar(ptr,{
                {Stats::HEALING_OUT,AType::TEMP,healout - Hycptr->getBuffNote("Hyc A6 Healout")},
                {Stats::HEALING_OUT,AType::None,healout - Hycptr->getBuffNote("Hyc A6 Healout")},
            });
            if(ptr->Eidolon>=4)
            buffSingleChar(ptr,{
                {Stats::CD,AType::TEMP,(healout - Hycptr->getBuffNote("Hyc A6 Healout"))*2},
                {Stats::CD,AType::None,(healout - Hycptr->getBuffNote("Hyc A6 Healout"))*2},
            });

            Hycptr->setBuffNote("Hyc A6 Healout",healout);
        }));

        //Eidolon
        if(ptr->Eidolon>=1)
        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr](shared_ptr<AllyAttackAction> &act) {
            if(Hycptr->getBuffCheck("After Rain")){
                ptr->RestoreHP(act->Attacker,
                HealSrc(HealSrcType::HP,8)
                );
            }
        }));

        if(ptr->Eidolon>=2){
            HPDecrease_List.push_back(TriggerDecreaseHP(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr](Unit *Trigger, AllyUnit *target, double Value) {
                buffSingle(target,{{Stats::SPD_P,AType::None,30}},"Hyacine E2",2);
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr]() {
                AllyUnit *allyptr = turn->canCastToSubUnit();
                if(allyptr&&isBuffEnd(allyptr,"Hyacine E2")){
                    buffSingle(allyptr,{{Stats::SPD_P,AType::None,-30}});
                }
            }));    
        }

        if(ptr->Eidolon>=6)
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr]() {
            buffAllAlly({
                {Stats::RESPEN,AType::None,20}
            });
        }));




        

    }


    void Basic_Atk(CharUnit *ptr){
        Skill_point(ptr,1);
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"Hyc BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,20);
            Attack(act);
            IcaAttack(ptr);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::HP,50,10));
        act->addToActionBar();
    }
    void Skill(CharUnit *ptr){
        Skill_point(ptr,-1);
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(AType::SKILL,ptr,TraceType::Aoe,"Hyc Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            Increase_energy(ptr,30);
            SummonIca(ptr);
            BeforeHycHeal();
            ptr->RestoreHP(ptr->getMemosprite(),
            HealSrc(HealSrcType::HP,10,HealSrcType::CONST,200),
            HealSrc(HealSrcType::HP,8,HealSrcType::CONST,160)
            );
            AfterHycHeal();
            IcaAttack(ptr);
        });
        act->addActionType(AType::Summon);
        act->addBuffAllAllies();
        act->addToActionBar();
    }



    void Memo_Skill(CharUnit *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr->getMemosprite(),TraceType::Aoe,"Ica Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,5);
            Attack(act);
            ptr->getMemosprite()->resetATV(-1);
        });
        act->addAttackType(AType::Summon);
        act->addDamageIns(
            DmgSrc(DmgSrcType::CONST,ptr->getMemosprite()->getBuffNote("Tally RestoreHP")*0.2,10),
            DmgSrc(DmgSrcType::CONST,ptr->getMemosprite()->getBuffNote("Tally RestoreHP")*0.2,10),
            DmgSrc(DmgSrcType::CONST,ptr->getMemosprite()->getBuffNote("Tally RestoreHP")*0.2,10)
        );
        if(ptr->Eidolon>=6)
        ptr->getMemosprite()->Buff_note["Tally RestoreHP"] *= 0.88;
        else
        ptr->getMemosprite()->Buff_note["Tally RestoreHP"] *= 0.5;
        act->addToActionBar();
    }

    void SummonIca(CharUnit *ptr){
        if(!ptr->memospriteList[0]->isDeath())return;
        ptr->memospriteList[0]->summon(100);
        if(ptr->memospriteList[0]->Buff_check["Ica First Summon"]==0){
            ptr->memospriteList[0]->Buff_check["Ica First Summon"]=1;
            Increase_energy(ptr,30);
        }
        Increase_energy(ptr,15);
    }

    void IcaAttack(CharUnit *ptr){
        if(ptr->getBuffCheck("After Rain")){
            ptr->getMemosprite()->resetATV(100);
            Action_forward(ptr->getMemosprite()->Atv_stats.get(),100);
        }
    }

    void BeforeHycHeal(){
        for(auto &each : allyList){
            if(each->currentHP*2<=each->totalHP){
                if(isHaveToAddBuff(each,"Hyc A2")){
                    buffSingle(each,{
                        {Stats::HEALING_IN,AType::None,25}
                    });
                }
            }
        }
    }
    void AfterHycHeal(){
        for(auto &each : allyList){
            if(each->getBuffCheck("Hyc A2")){
                buffSingle(each,{
                    {Stats::HEALING_IN,AType::None,-25}
                });
                each->setBuffCheck("Hyc A2",0);
            }
        }
    }
}