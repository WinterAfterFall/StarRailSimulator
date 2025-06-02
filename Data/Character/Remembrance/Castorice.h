
#ifndef Castorice_H
#define Castorice_H

#define F first
#define S second
#include "../Library.h"

namespace Castorice{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);

    void BasicAttack(Ally *ptr);
    void Skill(Ally *ptr);
    void Enchance_Skill(Ally *ptr);
    void Kamikaze(Ally *ptr);
    void DriverCondition(Ally *ptr, Ally *target);
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){

        Ally *ptr = SetAllyBasicStats(95,0,0,E,ET_QT,"Remembrance","Castorice",TYPE_STD);
        SetMemoStats(ptr,0,0,ET_QT,"Netherwing",ALLYTYPE_BACKUP);
        SubUnit *Casptr = ptr->getSubUnit();
        SubUnit *Polluxptr = ptr->getSubUnit(1);
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->SetAllyBaseStats(1630,524,485);

        //substats
        ptr->pushSubstats(ST_CD);
        ptr->pushSubstats(ST_CR);
        ptr->pushSubstats(ST_HP_P);
        ptr->setTotalSubstats(20);


        //func
        
        ptr->setRelicMainStats(ST_CD,ST_HP_P,ST_HP_P,ST_HP_P);

        // SetCountdownStats(ptr,"Supreme_Stance");
        //adjust
        if(ptr->Eidolon>=2)ptr->Adjust["NetherwingLifeSpan"] = 1;
        else ptr->Adjust["NetherwingLifeSpan"] = 1;
        
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {

            if (ptr->getSubUnit(1)->currentHP==0) {
                Skill(ptr);
            } else {
                // if(ptr->getSubUnit(1)->currentHP==34000)BasicAttack(ptr); 
                // else 
                Enchance_Skill(ptr);
            }
        };
        
        ptr->Sub_Unit_ptr[1]->Turn_func = [ptr,Casptr,Polluxptr](){
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(ActionType::SKILL,ptr->getSubUnit(1),TT_AOE,"Pollux Skill",
            [ptr,Casptr,Polluxptr](shared_ptr<AllyAttackAction> &act){
                Increase_energy(ptr,0);
                while(ptr->getSubUnit(1)->currentHP>8500){
                    if(ptr->getSubUnit(1)->Stack["Breath Scorches the Shadow"]==0){
                        for(auto &each : act->damageSplit[0]){
                            each.dmgSrc.HP = 24;
                        }
                    }
                    else
                    if(ptr->getSubUnit(1)->Stack["Breath Scorches the Shadow"]==1){
                        for(auto &each : act->damageSplit[0]){
                            each.dmgSrc.HP = 28;
                        }
                    }
                    else
                    {
                        for(auto &each : act->damageSplit[0]){
                            each.dmgSrc.HP = 34;
                        }
                    }
                    if(ptr->Eidolon>=1){
                        for(auto &each : act->damageSplit[0]){
                            each.dmgSrc.HP *= 1.239;
                        }
                    }
                    ptr->getSubUnit(1)->Stack["Breath Scorches the Shadow"]++;
                    Polluxptr->buffStackSingle({{ST_DMG,AT_NONE,30}},1,6,"Where The West Wind Dwells");
                    Attack(act);
                    if(ptr->getSubUnit(1)->getStack("Ardent Will")>0)
                    ptr->getSubUnit(1)->Stack["Ardent Will"]--;
                    else 
                    ptr->getSubUnit(1)->currentHP-=8500;
                }
                if(Polluxptr->isBuffEnd("NetherwingLifeSpan")){
                    if(ptr->getSubUnit(1)->Stack["Breath Scorches the Shadow"]==0){
                        for(auto &each : act->damageSplit[0]){
                            each.dmgSrc.HP = 24;
                        }
                    }
                    else
                    if(ptr->getSubUnit(1)->Stack["Breath Scorches the Shadow"]==1){
                        for(auto &each : act->damageSplit[0]){
                            each.dmgSrc.HP = 28;
                        }
                    }
                    else
                    {
                        for(auto &each : act->damageSplit[0]){
                            each.dmgSrc.HP = 34;
                        }
                    }
                    Polluxptr->buffStackSingle({{ST_DMG,AT_NONE,30}},1,6,"Where The West Wind Dwells");
                }else{
                    for(auto &each : act->damageSplit[0]){
                            each.dmgSrc.HP = 40;
                        }
                }
                if(ptr->Eidolon>=1){
                    for(auto &each : act->damageSplit[0]){
                        each.dmgSrc.HP *= 1.239;
                    }
                }
                Attack(act);
            });
            act->addActionType(ActionType::Summon);
            if(ptr->Eidolon>=6)act->Dont_care_weakness = 100;
            act->source = ptr->getSubUnit();
            act->addDamageIns(
                DmgSrc(DmgSrcType::HP,24,10),
                DmgSrc(DmgSrcType::HP,24,10),
                DmgSrc(DmgSrcType::HP,24,10)
            );
            act->addToActionBar();
        };

        
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Casptr,Polluxptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CD][AT_NONE] += 13.3;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CR][AT_NONE] += 18.7;
            ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG][ET_QT][AT_NONE] += 14.4;
        }));
        
        ptr->addUltCondition([ptr,Casptr,Polluxptr]() -> bool {
            if(ptr->getSubUnit()->Buff_note["Newbud"] >= 34000)return true;
            return false;
        });
        ptr->addUltCondition([ptr,Casptr,Polluxptr]() -> bool {
            if(ptr->getSubUnit(1)->currentHP==0)return true;
            return false;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,Casptr,Polluxptr]() {
            if(!ultUseCheck(ptr))return;
            ptr->getSubUnit()->Buff_note["Newbud"] = 0;

            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(ActionType::Ult,ptr->getSubUnit(),TT_SINGLE,"Cas Ult",
            [ptr,Casptr,Polluxptr](shared_ptr<AllyBuffAction> &act){
                if(ptr->Print)CharCmd::printUltStart("Castorice");
                debuffAllEnemyMark({{ST_RESPEN,AT_NONE,20}},Polluxptr,"Lost Netherland");
                ptr->getSubUnit(1)->currentHP = 34000;
                Polluxptr->buffSingle({{ST_FLAT_HP,AT_NONE,34000}});
                Polluxptr->resetATV(165);
                Action_forward(ptr->getSubUnit(1)->Atv_stats.get(),100);
                Polluxptr->extendBuffTime("NetherwingLifeSpan",ptr->Adjust["NetherwingLifeSpan"]);
                buffAllAlly({{ST_DMG,AT_NONE,10}},"Roar Rumbles the Realm",3);
                if(ptr->Eidolon>=2){
                    ptr->getSubUnit(1)->setStack("Ardent Will",2);
                    Action_forward(ptr->getSubUnit()->Atv_stats.get(),100);
                    ptr->getSubUnit()->Buff_note["Newbud"] = 10200;
                }
            });
            act->addBuffSingleTarget(ptr->Sub_Unit_ptr[0].get());
            act->addToActionBar();
            Deal_damage();
        }));
        

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Casptr,Polluxptr]() {
            if(ptr->Eidolon>=4){
                buffAllAlly({{ST_HEALING_IN,AT_NONE,20}});
            }
            if(ptr->Eidolon>=6){
                ptr->buffAlly({{ST_RESPEN,AT_NONE,20}});
            }
        }));

        Setup_Memo_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Casptr,Polluxptr]() {
            ptr->Sub_Unit_ptr[1]->Atv_stats->baseSpeed = -1;
            ptr->getSubUnit(1)->Atv_stats->flatSpeed = 0;
            ptr->getSubUnit(1)->Atv_stats->speedPercent = 0;
            ptr->Sub_Unit_ptr[1]->currentHP = 0;
            ptr->Sub_Unit_ptr[1]->baseHp = 0;
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Casptr,Polluxptr]() {
            if(ptr->Technique==1){
                debuffAllEnemyMark({{ST_RESPEN,AT_NONE,20}},Polluxptr,"Lost Netherland");
                

                ptr->getSubUnit(1)->currentHP = 1;
                Polluxptr->buffSingle({{ST_FLAT_HP,AT_NONE,34000}});
                ptr->getSubUnit(1)->currentHP = 17000;

                Polluxptr->resetATV(165);
                Action_forward(ptr->getSubUnit(1)->Atv_stats.get(),100);
                turn = ptr->getSubUnit(1)->Atv_stats.get();
                Polluxptr->extendBuffTime("NetherwingLifeSpan",1);
                DecreaseHP(ptr->Sub_Unit_ptr[0].get(),"Netherwing",0,0,40);
                buffAllAlly({{ST_DMG,AT_NONE,10}},"Roar Rumbles the Realm",3);
                if(ptr->Eidolon>=2){
                    ptr->getSubUnit(1)->setStack("Ardent Will",2);
                    Action_forward(ptr->getSubUnit()->Atv_stats.get(),100);
                    ptr->getSubUnit()->Buff_note["Newbud"] = 10200;
                }
            }
            else
            {
                ptr->getSubUnit()->Buff_note["Newbud"]=10200;
            }
            if(!ptr->getSubUnit()->getBuffCheck("Inverted Torch")&&ptr->getSubUnit()->currentHP>=ptr->getSubUnit()->totalHP*0.5){
                Casptr->buffSingle({{ST_SPD,ST_SPD_P,40}});
                ptr->getSubUnit()->setBuffCheck("Inverted Torch",true);
            }
        }));

        Healing_List.push_back(TriggerHealing(PRIORITY_IMMEDIATELY, [ptr,Casptr,Polluxptr](SubUnit *Healer, SubUnit *target, double Value) {
            if(target->isSameUnitName("Netherwing"))return;
            Value = (Value + target->getBuffNote("NetherwingHealLimit") > 4080) 
            ? 4080 - target->getBuffNote("NetherwingHealLimit")
            : Value;
            target->Buff_note["NetherwingHealLimit"]+=Value;
            if(ptr->getSubUnit(1)->currentHP==0){
                ptr->getSubUnit()->Buff_note["Newbud"]+=Value;
            }
            else {
                ptr->getSubUnit(1)->RestoreHP(ptr->getSubUnit(1),HealSrc(HealSrcType::CONST,Value));
            }
            if(target->isSameUnitName("Castorice")){
                if(!ptr->getSubUnit()->getBuffCheck("Inverted Torch")&&ptr->getSubUnit()->currentHP>=ptr->getSubUnit()->totalHP*0.5){
                Casptr->buffSingle({{ST_SPD,ST_SPD_P,40}});
                ptr->getSubUnit()->setBuffCheck("Inverted Torch",true);
                }
            }
            
        }));

        HPDecrease_List.push_back(TriggerDecreaseHP(PRIORITY_IMMEDIATELY, [ptr,Casptr,Polluxptr](Unit *Trigger, SubUnit *target, double Value) {
            if(ptr->getSubUnit(1)->currentHP==0){
                ptr->getSubUnit()->Buff_note["Newbud"]+=Value;
            }else {
                ptr->getSubUnit(1)->RestoreHP(ptr->getSubUnit(1),HealSrc(HealSrcType::CONST,Value));
            }
            if(ptr->getSubUnit()->Buff_note["CastoriceTalentBuff"]!=decreaseHPCount){
                ptr->getSubUnit()->Buff_note["CastoriceTalentBuff"] = decreaseHPCount;
                ptr->buffStackAlly({{ST_DMG,AT_NONE,20}},1,3,"CastoriceTalentBuff",3);
            }
            if(target->isSameUnitName("Castorice")){
                if(ptr->getSubUnit()->getBuffCheck("Inverted Torch")&&ptr->getSubUnit()->currentHP<ptr->getSubUnit()->totalHP*0.5){
                    Casptr->buffSingle({{ST_SPD,ST_SPD_P,-40}});
                    ptr->getSubUnit()->setBuffCheck("Inverted Torch",false);
                }
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,Casptr,Polluxptr]() {
            
            if(Polluxptr->isBuffEnd("NetherwingLifeSpan")){
                Kamikaze(ptr);
            }
            if(turn->isSameCharName("Netherwing")){
                Polluxptr->buffResetStack({{ST_DMG,AT_NONE,30}},"Where The West Wind Dwells");
            }
            SubUnit *tempUnit = turn->canCastToSubUnit();
            if(tempUnit){
                if(tempUnit->isBuffEnd("Roar Rumbles the Realm")){
                    tempUnit->buffSingle({{ST_DMG,AT_NONE,-10}});
                }
                if(tempUnit->isBuffEnd("CastoriceTalentBuff")){
                    tempUnit->buffResetStack({{ST_DMG,AT_NONE,20}},"CastoriceTalentBuff");
                }
            }
            
        }));

        Buff_List.push_back(TriggerByAllyBuffAction_Func(PRIORITY_ACTION, [ptr,Casptr,Polluxptr](shared_ptr<AllyBuffAction> &act) {
            for(int i=1;i<=Total_ally;i++){
                for(unique_ptr<SubUnit> &e : Ally_unit[i]->Sub_Unit_ptr){
                    e->Buff_note["NetherwingHealLimit"] = 0;
                }
            }

            
        }));

        Before_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTION, [ptr,Casptr,Polluxptr](shared_ptr<AllyAttackAction> &act) {
            for(int i=1;i<=Total_ally;i++){
                for(unique_ptr<SubUnit> &e : Ally_unit[i]->Sub_Unit_ptr){
                    e->Buff_note["NetherwingHealLimit"] = 0;
                }
            }
        }));
        
        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_ACTION, [ptr,Casptr,Polluxptr](SubUnit* Target, string StatsType) {
            if(!Target->isSameUnitName("Netherwing"))return;
            if(StatsType != ST_FLAT_HP && StatsType != ST_HP_P)return;
            double temp;
            if(ptr->getSubUnit(1)->currentHP==0){
                temp = -calculateHpOnStats(ptr->getSubUnit(1));
            }else{
                temp = 34000 - calculateHpOnStats(ptr->getSubUnit(1));
            }
             
            Polluxptr->buffSingle({{ST_FLAT_HP,AT_NONE,temp}});
        }));

        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_ACTION, [ptr,Casptr,Polluxptr](SubUnit* target) {
            if(target->isBuffGoneByDeath("Roar Rumbles the Realm")){
                target->buffSingle({{ST_DMG,AT_NONE,-10}});
            }
        }));
    }
    void BasicAttack(Ally *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::BA,ptr->getSubUnit(),TT_SINGLE,"Cas BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::HP,50,10)
        );
        act->addToActionBar();
    }
    void Skill(Ally *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::SKILL,ptr->getSubUnit(),TT_BLAST,"Cas Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,0);
            DecreaseHP(ptr->Sub_Unit_ptr[0].get(),"Netherwing",0,0,30);
            Attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::HP,50,20),
            DmgSrc(DmgSrcType::HP,30,10)
        );
        
        act->addToActionBar();
    }
    void Enchance_Skill(Ally *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::SKILL,ptr->getSubUnit(),TT_AOE,"Cas ESkill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,0);
            DecreaseHP(ptr->Sub_Unit_ptr[0].get(),"Netherwing",0,0,40);
            if(ptr->Eidolon>=1){
                for(auto &each1 : act->damageSplit){
                    for(auto &each2 : each1){
                        each2.dmgSrc.HP *= 1.239;
                    }
                }
            }
            Attack(act);
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
        act->switchAttacker.push_back(SwitchAtk(1,ptr->getSubUnit(),1));
        act->addToActionBar();
    }
    void Kamikaze(Ally *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(ActionType::SKILL,ptr->getSubUnit(1),TT_BOUNCE,"Pullux Kamikaze",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,0);
            Attack(act);
            ptr->getSubUnit()->RestoreHP(HealSrc(HealSrcType::HP,6,HealSrcType::CONST,800));
            for(int i=1;i<=Total_enemy;i++){
                Enemy_unit[i]->debuffRemove("Lost Netherland"); 
                Enemy_unit[i]->debuffSingle({{ST_RESPEN,AT_NONE,-20}});
            }
            ptr->getSubUnit(1)->Death();
            ptr->getSubUnit(1)->buffSingle({{ST_FLAT_HP,AT_NONE,-34000}});
            ptr->getSubUnit(1)->setStack("Breath Scorches the Shadow",0);
            if(ptr->Print)CharCmd::printUltEnd("Castorice");
        });
        act->addActionType(ActionType::Summon);
        act->source = ptr->getSubUnit();
        if(ptr->Eidolon>=6){
            act->addEnemyBounce(DmgSrc(DmgSrcType::HP,40,5),9);
            act->Dont_care_weakness = 100;
        }else{
            act->addEnemyBounce(DmgSrc(DmgSrcType::HP,40,5),6);
        }
        if(ptr->Eidolon>=1){
            for(auto &each1 : act->damageSplit){
                for(auto &each2 : each1){
                    each2.dmgSrc.HP *= 1.239;
                }
            }
        }
        act->addToActionBar();
        Deal_damage();
        
    }
    void DriverCondition(Ally *ptr, Ally *target) {
        target->ultCondition.push_back([ptr, target]() -> bool {
            if(ptr->getSubUnit(1)->currentHP==0)return false;
            return true;
        });
    }
    void HealerCondition(Ally *ptr, Ally *target) {
        target->ultCondition.push_back([ptr, target]() -> bool {
            if(ptr->getSubUnit()->Buff_note["Newbud"] >= 34000||ptr->getSubUnit(1)->currentHP==34000)return false;
            return true;
        });
    }
    void CastoriceWithDriver(Ally *ptr, Ally *target) {
        ptr->ultCondition.push_back([ptr, target]() -> bool {
            if(target->getSubUnit()->Atv_stats->atv>=10000/165)return true;
            // if(target->getSubUnit()->Atv_stats->atv>=10)return true;
            if(turn->isSameUnit(target->getSubUnit())&&Ult_After_Turn==0)return true;
            return false;
        });
    } 

}
#endif