
#include "../include.h"

namespace Castorice{
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar);

    void BasicAttack(CharUnit *ptr);
    void Skill(CharUnit *ptr);
    void Enchance_Skill(CharUnit *ptr);
    void Kamikaze(CharUnit *ptr);
    void DriverCondition(CharUnit *ptr, CharUnit *target);
    void Setup(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar){

        CharUnit *ptr = SetCharBasicStats(95,0,0,E,ElementType::Quantum,Path::Remembrance,"Castorice",UnitType::Standard);
        SetMemoStats(ptr,34000,0,165,0,ElementType::Quantum,"Netherwing",UnitType::Backup);
        AllyUnit *Casptr = ptr;
        AllyUnit *Polluxptr = ptr->getMemosprite();
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
        
        ptr->Turn_func = [ptr, allyPtr = ptr]() {

            if (ptr->getMemosprite()->isDeath()) {
                Skill(ptr);
            } else {
                Enchance_Skill(ptr);
            }
        };
        
        ptr->memospriteList[0]->Turn_func = [ptr,Casptr,Polluxptr](){
            shared_ptr<AllyAttackAction> act = 
            make_shared<AllyAttackAction>(AType::SKILL,ptr->getMemosprite(),TraceType::Aoe,"Pollux Skill",
            [ptr,Casptr,Polluxptr](shared_ptr<AllyAttackAction> &act){
                Increase_energy(ptr,0);
                while(ptr->getMemosprite()->currentHP>8500){
                    if(ptr->getMemosprite()->Stack["Breath Scorches the Shadow"]==0){
                        for(auto &each : act->damageSplit[0]){
                            each.dmgSrc.HP = 24;
                        }
                    }
                    else
                    if(ptr->getMemosprite()->Stack["Breath Scorches the Shadow"]==1){
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
                    ptr->getMemosprite()->Stack["Breath Scorches the Shadow"]++;
                    buffStackSingle(Polluxptr,{{Stats::DMG,AType::None,30}},1,6,"Where The West Wind Dwells");
                    Attack(act);
                    if(ptr->getMemosprite()->getStack("Ardent Will")>0)
                    ptr->getMemosprite()->Stack["Ardent Will"]--;
                    else 
                    ptr->getMemosprite()->currentHP-=8500;
                }
                if(isBuffEnd(Polluxptr,"NetherwingLifeSpan")){
                    if(ptr->getMemosprite()->Stack["Breath Scorches the Shadow"]==0){
                        for(auto &each : act->damageSplit[0]){
                            each.dmgSrc.HP = 24;
                        }
                    }
                    else
                    if(ptr->getMemosprite()->Stack["Breath Scorches the Shadow"]==1){
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
                    buffStackSingle(Polluxptr,{{Stats::DMG,AType::None,30}},1,6,"Where The West Wind Dwells");
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
            act->addAttackType(AType::Summon);
            if(ptr->Eidolon>=6)act->Dont_care_weakness = 100;
            act->source = ptr;
            act->addDamageIns(
                DmgSrc(DmgSrcType::HP,24,10),
                DmgSrc(DmgSrcType::HP,24,10),
                DmgSrc(DmgSrcType::HP,24,10)
            );
            act->addToActionBar();
        };

        
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Casptr,Polluxptr]() {
            ptr->Stats_type[Stats::CD][AType::None] += 13.3;
            ptr->Stats_type[Stats::CR][AType::None] += 18.7;
            ptr->Stats_each_element[Stats::DMG][ElementType::Quantum][AType::None] += 14.4;
        }));
        
        ptr->addUltCondition([ptr,Casptr,Polluxptr]() -> bool {
            if(ptr->Buff_note["Newbud"] >= 34000)return true;
            return false;
        });
        ptr->addUltCondition([ptr,Casptr,Polluxptr]() -> bool {
            if(ptr->getMemosprite()->isDeath())return true;
            return false;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,Casptr,Polluxptr]() {
            if(!ultUseCheck(ptr))return;
            ptr->Buff_note["Newbud"] = 0;

            shared_ptr<AllyBuffAction> act = 
            make_shared<AllyBuffAction>(AType::Ult,ptr,TraceType::Single,"Cas Ult",
            [ptr,Casptr,Polluxptr](shared_ptr<AllyBuffAction> &act){
                if(ptr->Print)CharCmd::printUltStart("Castorice");
                debuffAllEnemyMark({{Stats::RESPEN,AType::None,20}},Polluxptr,"Lost Netherland");
                ptr->getMemosprite()->summon(100);
                Action_forward(ptr->getMemosprite()->Atv_stats.get(),100);
                extendBuffTime(Polluxptr,"NetherwingLifeSpan",ptr->Adjust["NetherwingLifeSpan"]);
                buffAllAlly({{Stats::DMG,AType::None,10}},"Roar Rumbles the Realm",3);
                if(ptr->Eidolon>=2){
                    ptr->getMemosprite()->setStack("Ardent Will",2);
                    Action_forward(ptr->Atv_stats.get(),100);
                    ptr->Buff_note["Newbud"] = 10200;
                }
            });
            act->addBuffSingleTarget(ptr);
            act->addToActionBar();
            Deal_damage();
        }));
        

        WhenOnField_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Casptr,Polluxptr]() {
            if(ptr->Eidolon>=4){
                buffAllAlly({{Stats::HEALING_IN,AType::None,20}});
            }
            if(ptr->Eidolon>=6){
                buffSingleChar(ptr,{{Stats::RESPEN,AType::None,20}});
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,Casptr,Polluxptr]() {
            if(ptr->Technique==1){
                debuffAllEnemyMark({{Stats::RESPEN,AType::None,20}},Polluxptr,"Lost Netherland");
                

                ptr->getMemosprite()->summon(50);
                Action_forward(ptr->getMemosprite()->Atv_stats.get(),100);
                turn = ptr->getMemosprite()->Atv_stats.get();
                extendBuffTime(Polluxptr,"NetherwingLifeSpan",1);
                DecreaseHP(ptr,"Netherwing",0,0,40);
                buffAllAlly({{Stats::DMG,AType::None,10}},"Roar Rumbles the Realm",3);
                if(ptr->Eidolon>=2){
                    ptr->getMemosprite()->setStack("Ardent Will",2);
                    Action_forward(ptr->Atv_stats.get(),100);
                    ptr->Buff_note["Newbud"] = 10200;
                }
            }
            else
            {
                ptr->Buff_note["Newbud"]=10200;
            }
            if(!ptr->getBuffCheck("Inverted Torch")&&ptr->currentHP>=ptr->totalHP*0.5){
                buffSingle(Casptr,{{Stats::SPD_P,AType::None,40}});
                ptr->setBuffCheck("Inverted Torch",true);
            }
        }));

        Healing_List.push_back(TriggerHealing(PRIORITY_IMMEDIATELY, [ptr,Casptr,Polluxptr](AllyUnit *Healer, AllyUnit *target, double Value) {
            if(target->isSameName("Netherwing"))return;
            Value = (Value + target->getBuffNote("NetherwingHealLimit") > 4080) 
            ? 4080 - target->getBuffNote("NetherwingHealLimit")
            : Value;
            target->Buff_note["NetherwingHealLimit"]+=Value;
            if(ptr->getMemosprite()->isDeath()){
                ptr->Buff_note["Newbud"]+=Value;
            }
            else {
                ptr->getMemosprite()->RestoreHP(ptr->getMemosprite(),HealSrc(HealSrcType::CONST,Value));
            }
            if(target->isSameName("Castorice")){
                if(!ptr->getBuffCheck("Inverted Torch")&&ptr->currentHP>=ptr->totalHP*0.5){
                buffSingle(Casptr,{{Stats::SPD_P,AType::None,40}});
                ptr->setBuffCheck("Inverted Torch",true);
                }
            }
            
        }));

        HPDecrease_List.push_back(TriggerDecreaseHP(PRIORITY_IMMEDIATELY, [ptr,Casptr,Polluxptr](Unit *Trigger, AllyUnit *target, double Value) {
            if(ptr->getMemosprite()->isDeath()){
                ptr->Buff_note["Newbud"]+=Value;
            }else {
                ptr->getMemosprite()->RestoreHP(ptr->getMemosprite(),HealSrc(HealSrcType::CONST,Value));
            }
            if(ptr->Buff_note["CastoriceTalentBuff"]!=decreaseHPCount){
                ptr->Buff_note["CastoriceTalentBuff"] = decreaseHPCount;
                buffStackChar(ptr,{{Stats::DMG,AType::None,20}},1,3,"CastoriceTalentBuff",3);
            }
            if(target->isSameName("Castorice")){
                if(ptr->getBuffCheck("Inverted Torch")&&ptr->currentHP<ptr->totalHP*0.5){
                    buffSingle(Casptr,{{Stats::SPD_P,AType::None,-40}});
                    ptr->setBuffCheck("Inverted Torch",false);
                }
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,Casptr,Polluxptr]() {
            
            if(isBuffEnd(Polluxptr,"NetherwingLifeSpan")){
                Kamikaze(ptr);
            }
            if(turn->isSameName("Netherwing")){
                buffResetStack(Polluxptr,{{Stats::DMG,AType::None,30}},"Where The West Wind Dwells");
            }
            AllyUnit *tempUnit = turn->canCastToSubUnit();
            if(tempUnit){
                if(isBuffEnd(tempUnit,"Roar Rumbles the Realm")){
                    buffSingle(tempUnit,{{Stats::DMG,AType::None,-10}});
                }
                if(isBuffEnd(tempUnit,"CastoriceTalentBuff")){
                    buffResetStack(tempUnit,{{Stats::DMG,AType::None,20}},"CastoriceTalentBuff");
                }
            }
            
        }));

        Buff_List.push_back(TriggerByAllyBuffAction_Func(PRIORITY_ACTION, [ptr,Casptr,Polluxptr](shared_ptr<AllyBuffAction> &act) {
            for(auto &e : allyList){
                e->Buff_note["NetherwingHealLimit"] = 0;
            }
        }));

        BeforeAttackAction_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_ACTION, [ptr,Casptr,Polluxptr](shared_ptr<AllyAttackAction> &act) {
            for(auto &e : allyList){
                e->Buff_note["NetherwingHealLimit"] = 0;
            }
        }));
        
        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_ACTION, [ptr,Casptr,Polluxptr](AllyUnit* Target, Stats StatsType) {
            if(!Target->isSameName("Netherwing"))return;
            if(StatsType != Stats::FLAT_HP && StatsType != Stats::HP_P)return;
            double temp;
            temp = 34000 - calculateHpOnStats(ptr->getMemosprite());
            buffSingle(Polluxptr,{{Stats::FLAT_HP,AType::None,temp}});
            
        }));

        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_ACTION, [ptr,Casptr,Polluxptr](AllyUnit* target) {
            if(isBuffGoneByDeath(target,"Roar Rumbles the Realm")){
                buffSingle(target,{{Stats::DMG,AType::None,-10}});
            }
        }));
    }
    void BasicAttack(CharUnit *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::BA,ptr,TraceType::Single,"Cas BA",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::HP,50,10)
        );
        act->addToActionBar();
    }
    void Skill(CharUnit *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::Blast,"Cas Skill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,0);
            DecreaseHP(ptr,"Netherwing",0,0,30);
            Attack(act);
        });
        act->addDamageIns(
            DmgSrc(DmgSrcType::HP,50,20),
            DmgSrc(DmgSrcType::HP,30,10)
        );
        
        act->addToActionBar();
    }
    void Enchance_Skill(CharUnit *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr,TraceType::Aoe,"Cas ESkill",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,0);
            DecreaseHP(ptr,"Netherwing",0,0,40);
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
        act->switchAttacker.push_back(SwitchAtk(1,ptr,1));
        act->addToActionBar();
    }
    void Kamikaze(CharUnit *ptr){
        shared_ptr<AllyAttackAction> act = 
        make_shared<AllyAttackAction>(AType::SKILL,ptr->getMemosprite(),TraceType::Bounce,"Pullux Kamikaze",
        [ptr](shared_ptr<AllyAttackAction> &act){
            Increase_energy(ptr,0);
            Attack(act);
            ptr->RestoreHP(HealSrc(HealSrcType::HP,6,HealSrcType::CONST,800));
            for(auto &each : enemyList){
                debuffRemove(each,"Lost Netherland"); 
                debuffSingle(each,{{Stats::RESPEN,AType::None,-20}});
            }
            ptr->getMemosprite()->death();
            ptr->getMemosprite()->setStack("Breath Scorches the Shadow",0);
            if(ptr->Print)CharCmd::printUltEnd("Castorice");
        });
        act->addAttackType(AType::Summon);
        act->source = ptr;
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
    void DriverCondition(CharUnit *ptr, CharUnit *target) {
        target->ultCondition.push_back([ptr, target]() -> bool {
            if(ptr->getMemosprite()->isDeath())return false;
            return true;
        });
    }
    void HealerCondition(CharUnit *ptr, CharUnit *target) {
        target->ultCondition.push_back([ptr, target]() -> bool {
            if(ptr->Buff_note["Newbud"] >= 34000||ptr->getMemosprite()->currentHP==34000)return false;
            return true;
        });
    }
    void CastoriceWithDriver(CharUnit *ptr, CharUnit *target) {
        ptr->ultCondition.push_back([ptr, target]() -> bool {
            if(target->Atv_stats->atv>=10000/165)return true;
            // if(target->Atv_stats->atv>=10)return true;
            if(turn->isSameUnit(target)&&phaseStatus == PhaseStatus::BeforeTurn)return true;
            return false;
        });
    } 

}
#