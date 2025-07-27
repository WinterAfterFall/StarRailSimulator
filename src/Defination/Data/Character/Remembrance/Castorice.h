
#include "../include.h"

namespace Castorice{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);

    void BasicAttack(Ally *ptr);
    void Skill(Ally *ptr);
    void Enchance_Skill(Ally *ptr);
    void Kamikaze(Ally *ptr);
    void DriverCondition(Ally *ptr, Ally *target);
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){

        Ally *ptr = SetAllyBasicStats(95,0,0,E,ElementType::Quantum,"Remembrance","Castorice",TYPE_STD);
        SetMemoStats(ptr,34000,0,165,0,ElementType::Quantum,"Netherwing",ALLYTYPE_BACKUP);
        SubUnit *Casptr = ptr->getSubUnit();
        SubUnit *Polluxptr = ptr->getSubUnit(1);
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->SetAllyBaseStats(1630,524,485);

        //substats
        ptr->pushSubstats(Stats::CD);
        ptr->pushSubstats(Stats::CR);
        ptr->pushSubstats(Stats::HP_P);
        ptr->setTotalSubstats(20);


        //func
        
        ptr->setRelicMainStats(Stats::CD,Stats::HP_P,Stats::HP_P,Stats::HP_P);

        //adjust
        if(ptr->Eidolon>=2)ptr->Adjust["NetherwingLifeSpan"] = 1;
        else ptr->Adjust["NetherwingLifeSpan"] = 3;
        
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {

            if (ptr->getSubUnit(1)->isDeath()) {
                Skill(ptr);
            } else {
                Enchance_Skill(ptr);
            }
        };
        
        ptr->Sub_Unit_ptr[1]->Turn_func = [ptr,Casptr,Polluxptr](){
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr->getSubUnit(1),TT_AOE,"Pollux Skill",
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
                    Polluxptr->buffStackSingle({{Stats::DMG,AType::None,30}},1,6,"Where The West Wind Dwells");
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
                    Polluxptr->buffStackSingle({{Stats::DMG,AType::None,30}},1,6,"Where The West Wind Dwells");
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
            act->addActionType(AType::Summon);
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
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CD][AType::None] += 13.3;
            ptr->Sub_Unit_ptr[0]->Stats_type[Stats::CR][AType::None] += 18.7;
            ptr->Sub_Unit_ptr[0]->Stats_each_element[Stats::DMG][ElementType::Quantum][AType::None] += 14.4;
        }));
        
        ptr->addUltCondition([ptr,Casptr,Polluxptr]() -> bool {
            if(ptr->getSubUnit()->Buff_note["Newbud"] >= 34000)return true;
            return false;
        });
        ptr->addUltCondition([ptr,Casptr,Polluxptr]() -> bool {
            if(ptr->getSubUnit(1)->isDeath())return true;
            return false;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,Casptr,Polluxptr]() {
            if(!ultUseCheck(ptr))return;
            ptr->getSubUnit()->Buff_note["Newbud"] = 0;

            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::Ult,ptr->getSubUnit(),TT_SINGLE,"Cas Ult",
            [ptr,Casptr,Polluxptr](shared_ptr<AllyBuffAction> &act){
                if(ptr->Print)CharCmd::printUltStart("Castorice");
                debuffAllEnemyMark({{Stats::RESPEN,AType::None,20}},Polluxptr,"Lost Netherland");
                ptr->getSubUnit(1)->summon(100);
                Action_forward(ptr->getSubUnit(1)->Atv_stats.get(),100);
                Polluxptr->extendBuffTime("NetherwingLifeSpan",ptr->Adjust["NetherwingLifeSpan"]);
                buffAllAlly({{Stats::DMG,AType::None,10}},"Roar Rumbles the Realm",3);
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
                buffAllAlly({{Stats::HEALING_IN,AType::None,20}});
            }
            if(ptr->Eidolon>=6){
                ptr->buffAlly({{Stats::RESPEN,AType::None,20}});
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Casptr,Polluxptr]() {
            if(ptr->Technique==1){
                debuffAllEnemyMark({{Stats::RESPEN,AType::None,20}},Polluxptr,"Lost Netherland");
                

                ptr->getSubUnit(1)->summon(50);
                Action_forward(ptr->getSubUnit(1)->Atv_stats.get(),100);
                turn = ptr->getSubUnit(1)->Atv_stats.get();
                Polluxptr->extendBuffTime("NetherwingLifeSpan",1);
                DecreaseHP(ptr->Sub_Unit_ptr[0].get(),"Netherwing",0,0,40);
                buffAllAlly({{Stats::DMG,AType::None,10}},"Roar Rumbles the Realm",3);
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
                Casptr->buffSingle({{Stats::SPD_P,AType::None,40}});
                ptr->getSubUnit()->setBuffCheck("Inverted Torch",true);
            }
        }));

        Healing_List.push_back(TriggerHealing(PRIORITY_IMMEDIATELY, [ptr,Casptr,Polluxptr](SubUnit *Healer, SubUnit *target, double Value) {
            if(target->isSameUnitName("Netherwing"))return;
            Value = (Value + target->getBuffNote("NetherwingHealLimit") > 4080) 
            ? 4080 - target->getBuffNote("NetherwingHealLimit")
            : Value;
            target->Buff_note["NetherwingHealLimit"]+=Value;
            if(ptr->getSubUnit(1)->isDeath()){
                ptr->getSubUnit()->Buff_note["Newbud"]+=Value;
            }
            else {
                ptr->getSubUnit(1)->RestoreHP(ptr->getSubUnit(1),HealSrc(HealSrcType::CONST,Value));
            }
            if(target->isSameUnitName("Castorice")){
                if(!ptr->getSubUnit()->getBuffCheck("Inverted Torch")&&ptr->getSubUnit()->currentHP>=ptr->getSubUnit()->totalHP*0.5){
                Casptr->buffSingle({{Stats::SPD_P,AType::None,40}});
                ptr->getSubUnit()->setBuffCheck("Inverted Torch",true);
                }
            }
            
        }));

        HPDecrease_List.push_back(TriggerDecreaseHP(PRIORITY_IMMEDIATELY, [ptr,Casptr,Polluxptr](Unit *Trigger, SubUnit *target, double Value) {
            if(ptr->getSubUnit(1)->isDeath()){
                ptr->getSubUnit()->Buff_note["Newbud"]+=Value;
            }else {
                ptr->getSubUnit(1)->RestoreHP(ptr->getSubUnit(1),HealSrc(HealSrcType::CONST,Value));
            }
            if(ptr->getSubUnit()->Buff_note["CastoriceTalentBuff"]!=decreaseHPCount){
                ptr->getSubUnit()->Buff_note["CastoriceTalentBuff"] = decreaseHPCount;
                ptr->buffStackAlly({{Stats::DMG,AType::None,20}},1,3,"CastoriceTalentBuff",3);
            }
            if(target->isSameUnitName("Castorice")){
                if(ptr->getSubUnit()->getBuffCheck("Inverted Torch")&&ptr->getSubUnit()->currentHP<ptr->getSubUnit()->totalHP*0.5){
                    Casptr->buffSingle({{Stats::SPD_P,AType::None,-40}});
                    ptr->getSubUnit()->setBuffCheck("Inverted Torch",false);
                }
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,Casptr,Polluxptr]() {
            
            if(Polluxptr->isBuffEnd("NetherwingLifeSpan")){
                Kamikaze(ptr);
            }
            if(turn->isSameCharName("Netherwing")){
                Polluxptr->buffResetStack({{Stats::DMG,AType::None,30}},"Where The West Wind Dwells");
            }
            SubUnit *tempUnit = turn->canCastToSubUnit();
            if(tempUnit){
                if(tempUnit->isBuffEnd("Roar Rumbles the Realm")){
                    tempUnit->buffSingle({{Stats::DMG,AType::None,-10}});
                }
                if(tempUnit->isBuffEnd("CastoriceTalentBuff")){
                    tempUnit->buffResetStack({{Stats::DMG,AType::None,20}},"CastoriceTalentBuff");
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

        BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTION, [ptr,Casptr,Polluxptr](shared_ptr<AllyAttackAction> &act) {
            for(int i=1;i<=Total_ally;i++){
                for(unique_ptr<SubUnit> &e : Ally_unit[i]->Sub_Unit_ptr){
                    e->Buff_note["NetherwingHealLimit"] = 0;
                }
            }
        }));
        
        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_ACTION, [ptr,Casptr,Polluxptr](SubUnit* Target, Stats StatsType) {
            if(!Target->isSameUnitName("Netherwing"))return;
            if(StatsType != Stats::FLAT_HP && StatsType != Stats::HP_P)return;
            double temp;
            temp = 34000 - calculateHpOnStats(ptr->getSubUnit(1));
            Polluxptr->buffSingle({{Stats::FLAT_HP,AType::None,temp}});
            
        }));

        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_ACTION, [ptr,Casptr,Polluxptr](SubUnit* target) {
            if(target->isBuffGoneByDeath("Roar Rumbles the Realm")){
                target->buffSingle({{Stats::DMG,AType::None,-10}});
            }
        }));
    }
    void BasicAttack(Ally *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr->getSubUnit(),TT_SINGLE,"Cas BA",
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
        make_shared<AllyAttackAction>(AType::SKILL,ptr->getSubUnit(),TT_BLAST,"Cas Skill",
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
        make_shared<AllyAttackAction>(AType::SKILL,ptr->getSubUnit(),TT_AOE,"Cas ESkill",
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
        make_shared<AllyAttackAction>(AType::SKILL,ptr->getSubUnit(1),TT_BOUNCE,"Pullux Kamikaze",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,0);
            Attack(act);
            ptr->getSubUnit()->RestoreHP(HealSrc(HealSrcType::HP,6,HealSrcType::CONST,800));
            for(int i=1;i<=Total_enemy;i++){
                Enemy_unit[i]->debuffRemove("Lost Netherland"); 
                Enemy_unit[i]->debuffSingle({{Stats::RESPEN,AType::None,-20}});
            }
            ptr->getSubUnit(1)->death();
            ptr->getSubUnit(1)->setStack("Breath Scorches the Shadow",0);
            if(ptr->Print)CharCmd::printUltEnd("Castorice");
        });
        act->addActionType(AType::Summon);
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
            if(ptr->getSubUnit(1)->isDeath())return false;
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
            if(turn->isSameUnit(target->getSubUnit())&&Situation == "Before Turn")return true;
            return false;
        });
    } 

}
#