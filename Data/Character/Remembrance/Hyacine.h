
#ifndef Hyacine_H
#define Hyacine_H

#define F first
#define S second
#include "../Library.h"

namespace Hyacine{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
//temp
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);
    void Memo_Skill(Ally *ptr);
    void SummonIca(Ally *ptr);
    void IcaAttack(Ally *ptr);
    void BeforeHycHeal();
    void AfterHycHeal();


    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(110,140,140,E,ElementType::Wind,"Remembrance","Hyacine",TYPE_STD);
        ptr->SetAllyBaseStats(1087,388,631);
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        SetMemoStats(ptr,50,0,ElementType::Wind,"Little Ica",TYPE_STD);
        
        SubUnit *Hycptr = ptr->getSubUnit();
        SubUnit *Icaptr = ptr->getSubUnit(1);
        //substats
        

        // ptr->pushSubstats(ST_CD);
        ptr->pushSubstats(ST_HP_P);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(210);
        ptr->setRelicMainStats(ST_HEALING_OUT,ST_FLAT_SPD,ST_HP_P,ST_EnergyRecharge);


        //func
        
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr,Hycptr,Icaptr](){
            if(sp>Sp_Safety||Icaptr->currentHP==0){
                Skill(ptr);
            }else{
                Basic_Atk(ptr);
            }
        };
        ptr->Sub_Unit_ptr[1]->Turn_func = [ptr,Hycptr,Icaptr](){
    
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
            make_shared<AllyBuffAction>(ActionType::Ult,ptr->getSubUnit(),TT_AOE,"Hyc Ult",
            [ptr,Hycptr](shared_ptr<AllyBuffAction> &act){
                if(ptr->Print)CharCmd::printUltStart("Hyacine");
                SummonIca(ptr);
                BeforeHycHeal();
                ptr->getSubUnit()->RestoreHP(ptr->getSubUnit(1),
                HealSrc(HealSrcType::HP,12,HealSrcType::CONST,240),
                HealSrc(HealSrcType::HP,10,HealSrcType::CONST,200)
                );
                AfterHycHeal();
                if(Hycptr->isHaveToAddBuff("After Rain",3)){
                    buffAllAlly({
                        {ST_HP_P,AT_NONE,30},
                        {ST_FLAT_HP,AT_NONE,600},
                    });
                    if(ptr->Eidolon>=1)
                    buffAllAlly({
                        {ST_HP_P,AT_NONE,50},
                    });
                    

                }
                IcaAttack(ptr);
            });
            act->addBuffAllAllies();
            act->addActionType(ActionType::Summon);
            act->addToActionBar();
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr]() {
            ptr->Sub_Unit_ptr[0]->Atv_stats->flatSpeed += 14;
            ptr->Sub_Unit_ptr[0]->Stats_type["Hp%"][AT_NONE] += 10;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_RES][AT_NONE] += 18;

            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AT_NONE] += 100;
        }));

        Setup_Memo_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr]() {
            ptr->Sub_Unit_ptr[1]->Atv_stats->baseSpeed = -1;
            ptr->Sub_Unit_ptr[1]->currentHP = 0;
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr]() {
            if(ptr->Technique){
                BeforeHycHeal();
                ptr->getSubUnit()->RestoreHP(HealSrc(HealSrcType::HP,30,HealSrcType::CONST,600));
                AfterHycHeal();
                buffAllAlly({
                        {ST_HP_P,AT_NONE,20}
                    },"Day So Right, Life So Fine!",2);
            }
            double spd = calculateSpeedForBuff(Hycptr,100);
            double healout = floor((spd-200.0));
            if(healout <= 0)healout = 0;
            if(spd >= 200&&!Hycptr->getBuffCheck("Hyc A6 MaxHP")){
                ptr->buffAlly({
                    {ST_HP_P,AT_NONE,20}
                });
                Hycptr->setBuffCheck("Hyc A6 MaxHP",1);
            }else if(spd < 200&&Hycptr->getBuffCheck("Hyc A6 MaxHP")){
                ptr->buffAlly({
                    {ST_HP_P,AT_NONE,-20}
                });
                Hycptr->setBuffCheck("Hyc A6 MaxHP",0);
            }
            ptr->buffAlly({
                    {ST_HEALING_OUT,AT_TEMP,healout - Hycptr->getBuffNote("Hyc A6 Healout")},
                    {ST_HEALING_OUT,AT_NONE,healout - Hycptr->getBuffNote("Hyc A6 Healout")},
            });
            if(ptr->Eidolon>=4)
            ptr->buffAlly({
                {ST_CD,AT_TEMP,(healout - Hycptr->getBuffNote("Hyc A6 Healout"))*2},
                {ST_CD,AT_NONE,(healout - Hycptr->getBuffNote("Hyc A6 Healout"))*2},
            });

            Hycptr->setBuffNote("Hyc A6 Healout",healout);

        }));

        

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr]() {
            if(Hycptr->isBuffEnd("After Rain")){
                if(ptr->Print)CharCmd::printUltEnd("Hyacine");
                buffAllAlly({
                        {ST_HP_P,AT_NONE,-30},
                        {ST_FLAT_HP,AT_NONE,-600},
                });
                if(ptr->Eidolon>=1)
                buffAllAlly({
                    {ST_HP_P,AT_NONE,-50}
                });
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr]() {
            if(Icaptr->isBuffEnd("First Light Heals the World")){
                Icaptr->buffResetStack({{ST_DMG,AT_NONE,80}},"First Light Heals the World");
            }
            SubUnit *allyptr = turn->canCastToSubUnit();
            if(!allyptr)return;
            if(allyptr->isBuffEnd("Day So Right, Life So Fine!")){
                allyptr->buffSingle({{ST_HP_P,AT_NONE,-20}});
            }
        }));

        BeforeAction_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr](shared_ptr<ActionData> &act) {
            
            for(int i=1;i<=Total_ally;i++){
                for(auto &each : Ally_unit[i]->Sub_Unit_ptr){
                    each->setBuffCheck("Ica Talent Heal",0);
                }
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
            for(int i=1;i<=Total_ally;i++){
                for(auto &each : Ally_unit[i]->Sub_Unit_ptr){
                    if(each->getBuffCheck("Ica Talent Heal"))
                    Icaptr->RestoreHP(each.get(),HealSrc(HealSrcType::HP,4,HealSrcType::CONST,40));
                    else
                    Icaptr->RestoreHP(each.get(),HealSrc(HealSrcType::HP,2,HealSrcType::CONST,20));
                    healCount--;
                }
            }
            AfterHycHeal();
            healCount++;
        }));

        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr](SubUnit* target) {
            if(target->isSameUnit(Icaptr)){
                Action_forward(Hycptr->Atv_stats.get(),30);
            }
            if(target->isBuffGoneByDeath("First Light Heals the World")){
                target->buffResetStack({{ST_DMG,AT_NONE,80}},"First Light Heals the World");
            }
            if(target->isBuffGoneByDeath("Day So Right, Life So Fine!")){
                target->buffSingle({{ST_HP_P,AT_NONE,-20}});
            }
        }));
        
        Healing_List.push_back(TriggerHealing(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr](SubUnit *Healer, SubUnit *target, double Value) {
            if(Healer->isSameUnitName("Hyacine")||Healer->isSameUnitName("Little Ica")){
                Icaptr->buffStackSingle({
                    {ST_DMG,AT_NONE,80}
                },1,3,"First Light Heals the World",2);
                Icaptr->Buff_note["Tally RestoreHP"] += Value;
            }
        }));
        
        HPDecrease_List.push_back(TriggerDecreaseHP(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr](Unit *Trigger, SubUnit *target, double Value) {
            if(target->isSameUnit(Icaptr))return;
            Hycptr->setBuffCheck("Ica Talent Trigger",1);
            target->setBuffCheck("Ica Talent Heal",1);
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr](SubUnit* Target, string StatsType) {
            if(!Target->isSameUnitName("Hyacine"))return;
            if(StatsType!=ST_SPD)return;
            double spd = calculateSpeedForBuff(Hycptr,100);
            double healout = floor((spd-200.0));
            if(healout<=0)healout = 0;
            if(spd >= 200&&!Hycptr->getBuffCheck("Hyc A6 MaxHP")){
                ptr->buffAlly({
                    {ST_HP_P,AT_NONE,20}
                });
                Hycptr->setBuffCheck("Hyc A6 MaxHP",1);
            }else if(spd < 200&&Hycptr->getBuffCheck("Hyc A6 MaxHP")){
                ptr->buffAlly({
                    {ST_HP_P,AT_NONE,-20}
                });
                Hycptr->setBuffCheck("Hyc A6 MaxHP",0);
            }
            ptr->buffAlly({
                {ST_HEALING_OUT,AT_TEMP,healout - Hycptr->getBuffNote("Hyc A6 Healout")},
                {ST_HEALING_OUT,AT_NONE,healout - Hycptr->getBuffNote("Hyc A6 Healout")},
            });
            if(ptr->Eidolon>=4)
            ptr->buffAlly({
                {ST_CD,AT_TEMP,(healout - Hycptr->getBuffNote("Hyc A6 Healout"))*2},
                {ST_CD,AT_NONE,(healout - Hycptr->getBuffNote("Hyc A6 Healout"))*2},
            });

            Hycptr->setBuffNote("Hyc A6 Healout",healout);
        }));

        //Eidolon
        if(ptr->Eidolon>=1)
        When_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr](shared_ptr<AllyAttackAction> &act) {
            if(Hycptr->getBuffCheck("After Rain")){
                ptr->getSubUnit()->RestoreHP(act->Attacker,
                HealSrc(HealSrcType::HP,8)
                );
            }
        }));

        if(ptr->Eidolon>=2){
            HPDecrease_List.push_back(TriggerDecreaseHP(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr](Unit *Trigger, SubUnit *target, double Value) {
                target->buffSingle({{ST_SPD,ST_SPD_P,30}},"Hyacine E2",2);
            }));

            After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr]() {
                SubUnit *allyptr = turn->canCastToSubUnit();
                if(allyptr&&allyptr->isBuffEnd("Hyacine E2")){
                    allyptr->buffSingle({{ST_SPD,ST_SPD_P,-30}});
                }
            }));    
        }

        if(ptr->Eidolon>=6)
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Hycptr,Icaptr]() {
            buffAllAlly({
                {ST_RESPEN,AT_NONE,20}
            });
        }));




        

    }


    void Basic_Atk(Ally *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::BA,ptr->getSubUnit(),TT_SINGLE,"Hyc BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(act);
            IcaAttack(ptr);
        });
        act->addDamageIns(DmgSrc(DmgSrcType::HP,50,10));
        act->addToActionBar();
    }
    void Skill(Ally *ptr){
        shared_ptr<AllyBuffAction> act = 
        make_shared<AllyBuffAction>(ActionType::SKILL,ptr->getSubUnit(),TT_AOE,"Hyc Skill",
        [ptr](shared_ptr<AllyBuffAction> &act){
            Increase_energy(ptr,30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            SummonIca(ptr);
            BeforeHycHeal();
            ptr->getSubUnit()->RestoreHP(ptr->getSubUnit(1),
            HealSrc(HealSrcType::HP,10,HealSrcType::CONST,200),
            HealSrc(HealSrcType::HP,8,HealSrcType::CONST,160)
            );
            AfterHycHeal();
            IcaAttack(ptr);
        });
        act->addActionType(ActionType::Summon);
        act->addBuffAllAllies();
        act->addToActionBar();
    }



    void Memo_Skill(Ally *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::SKILL,ptr->getSubUnit(1),TT_AOE,"Ica Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,5);
            Attack(act);
            ptr->getSubUnit(1)->resetATV(-1);
        });
        act->addActionType(ActionType::Summon);
        act->addDamageIns(
            DmgSrc(DmgSrcType::CONST,ptr->getSubUnit(1)->getBuffNote("Tally RestoreHP")*0.2,10),
            DmgSrc(DmgSrcType::CONST,ptr->getSubUnit(1)->getBuffNote("Tally RestoreHP")*0.2,10),
            DmgSrc(DmgSrcType::CONST,ptr->getSubUnit(1)->getBuffNote("Tally RestoreHP")*0.2,10)
        );
        if(ptr->Eidolon>=6)
        ptr->getSubUnit(1)->Buff_note["Tally RestoreHP"] *= 0.88;
        else
        ptr->getSubUnit(1)->Buff_note["Tally RestoreHP"] *= 0.5;
        act->addToActionBar();
    }

    void SummonIca(Ally *ptr){
        if(ptr->Sub_Unit_ptr[1]->currentHP>0)return;
        ptr->Sub_Unit_ptr[1]->currentHP = ptr->Sub_Unit_ptr[1]->totalHP;
        if(ptr->Sub_Unit_ptr[1]->Buff_check["Ica First Summon"]==0){
            ptr->Sub_Unit_ptr[1]->Buff_check["Ica First Summon"]=1;
            Increase_energy(ptr,30);
        }
        Increase_energy(ptr,15);
    }

    void IcaAttack(Ally *ptr){
        if(ptr->getSubUnit()->getBuffCheck("After Rain")){
            ptr->getSubUnit(1)->resetATV(100);
            Action_forward(ptr->getSubUnit(1)->Atv_stats.get(),100);
        }
    }

    void BeforeHycHeal(){
        for(int i=1;i<=Total_ally;i++){
            for(auto &each : Ally_unit[i]->Sub_Unit_ptr){
                if(each->currentHP*2<=each->totalHP){
                    if(each->isHaveToAddBuff("Hyc A2")){
                        each->buffSingle({
                            {ST_HEALING_IN,AT_NONE,25}
                        });
                    }
                }
            }
        }
    }
    void AfterHycHeal(){
        for(int i=1;i<=Total_ally;i++){
            for(auto &each : Ally_unit[i]->Sub_Unit_ptr){
                if(each->getBuffCheck("Hyc A2")){
                    each->buffSingle({
                        {ST_HEALING_IN,AT_NONE,-25}
                    });
                    each->setBuffCheck("Hyc A2",0);
                }
            }
        }
    }
    namespace setting{

    }
}
#endif