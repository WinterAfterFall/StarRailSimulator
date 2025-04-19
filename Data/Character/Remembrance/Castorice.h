
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

        Ally *ptr = SetAllyBasicStats(95,0,0,E,"Quantum","Remembrance","Castorice",TYPE_STD);
        ptr->SetAllyBaseStats(1630,524,485);

        //substats
        ptr->pushSubstats(ST_CRIT_DAM);
        ptr->pushSubstats(ST_CRIT_RATE);
        ptr->pushSubstats(ST_HP_PERCENT);
        ptr->setTotalSubstats(20);


        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->setRelicMainStats(ST_CRIT_DAM,ST_HP_PERCENT,ST_HP_PERCENT,ST_HP_PERCENT);

        SetMemoStats(ptr,0,0,"Quantum","Netherwing",ALLYTYPE_BACKUP);
        // SetCountdownStats(ptr,"Supreme_Stance");
        //adjust
        ptr->Adjust["NetherwingLifeSpan"] = 3;
        
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {

            if (ptr->getSubUnit(1)->currentHP==0) {
                Skill(ptr);
            } else {
                // if(ptr->getSubUnit(1)->currentHP==34000)BasicAttack(ptr); 
                // else 
                Enchance_Skill(ptr);
            }
        };
        ptr->Sub_Unit_ptr[1]->Turn_func = [ptr](){
            shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
            data_->Skill_set(ptr->getSubUnit(1),"Aoe","Breath Scorches the Shadow");
            data_->Add_Target_Other();
            data_->Skill_Type.push_back("Summon");
            data_->resetTurn();
            if(ptr->Eidolon>=6)data_->Dont_care_weakness = 100;
            data_->source = ptr->getSubUnit();
            data_->Damage_spilt.Main.push_back({0,24,0,10});
            data_->Damage_spilt.Adjacent.push_back({0,24,0,10});
            data_->Damage_spilt.Other.push_back({0,24,0,10});
            data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
                Increase_energy(ptr,0);
                while(ptr->getSubUnit(1)->currentHP>8500){
                    if(ptr->getSubUnit(1)->Stack["Breath Scorches the Shadow"]==0){
                        data_->Damage_spilt.Main[0].Hp_ratio = 24;
                        data_->Damage_spilt.Adjacent[0].Hp_ratio = 24;
                        data_->Damage_spilt.Other[0].Hp_ratio = 24;
                    }
                    else
                    if(ptr->getSubUnit(1)->Stack["Breath Scorches the Shadow"]==1){
                        data_->Damage_spilt.Main[0].Hp_ratio = 28;
                        data_->Damage_spilt.Adjacent[0].Hp_ratio = 28;
                        data_->Damage_spilt.Other[0].Hp_ratio = 28;
                    }
                    else
                    {
                        data_->Damage_spilt.Main[0].Hp_ratio = 34;
                        data_->Damage_spilt.Adjacent[0].Hp_ratio = 34;
                        data_->Damage_spilt.Other[0].Hp_ratio = 34;
                    }
                    if(ptr->Eidolon>=1){
                        data_->Damage_spilt.Main[0].Hp_ratio *= 1.239;
                        data_->Damage_spilt.Adjacent[0].Hp_ratio *= 1.239;
                        data_->Damage_spilt.Other[0].Hp_ratio *= 1.239;
                    }
                    ptr->getSubUnit(1)->Stack["Breath Scorches the Shadow"]++;
                    Stack_Buff_single_target(ptr->getSubUnit(1),ST_DMG_PERCENT,AT_NONE,30,1,6,"Where The West Wind Dwells");
                    Attack(data_);
                    if(ptr->getSubUnit(1)->getStack("Ardent Will")>0)
                    ptr->getSubUnit(1)->Stack["Ardent Will"]--;
                    else 
                    ptr->getSubUnit(1)->currentHP-=8500;
                }
                if(Buff_end(ptr->getSubUnit(1),"NetherwingLifeSpan")){
                    if(ptr->getSubUnit(1)->Stack["Breath Scorches the Shadow"]==0){
                        data_->Damage_spilt.Main[0].Hp_ratio = 24;
                        data_->Damage_spilt.Adjacent[0].Hp_ratio = 24;
                        data_->Damage_spilt.Other[0].Hp_ratio = 24;
                    }
                    else
                    if(ptr->getSubUnit(1)->Stack["Breath Scorches the Shadow"]==1){
                        data_->Damage_spilt.Main[0].Hp_ratio = 28;
                        data_->Damage_spilt.Adjacent[0].Hp_ratio = 28;
                        data_->Damage_spilt.Other[0].Hp_ratio = 28;
                    }
                    else
                    {
                        data_->Damage_spilt.Main[0].Hp_ratio = 34;
                        data_->Damage_spilt.Adjacent[0].Hp_ratio = 34;
                        data_->Damage_spilt.Other[0].Hp_ratio = 34;
                    }
                    Stack_Buff_single_target(ptr->getSubUnit(1),ST_DMG_PERCENT,AT_NONE,30,1,6,"Where The West Wind Dwells");
                }else{
                    data_->Damage_spilt.Main[0].Hp_ratio = 40;
                    data_->Damage_spilt.Adjacent[0].Hp_ratio = 40;
                    data_->Damage_spilt.Other[0].Hp_ratio = 40;
                }
                if(ptr->Eidolon>=1){
                    data_->Damage_spilt.Main[0].Hp_ratio *= 1.239;
                    data_->Damage_spilt.Adjacent[0].Hp_ratio *= 1.239;
                    data_->Damage_spilt.Other[0].Hp_ratio *= 1.239;
                }

                Attack(data_);
                
                
            };
            Action_bar.push(data_);
            
        };

        
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CRIT_DAM]["None"] += 13.3;
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"] += 18.7;
            ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Quantum"]["None"] += 14.4;
            
            // relic

            // substats
            
            // countdown
        }));
        
        ptr->addUltCondition([ptr]() -> bool {
            if(ptr->getSubUnit()->Buff_note["Newbud"] >= 34000)return true;
            return false;
        });
        ptr->addUltCondition([ptr]() -> bool {
            if(ptr->getSubUnit(1)->currentHP==0)return true;
            return false;
        });

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if(!ultUseCheck(ptr))return;
            ptr->getSubUnit()->Buff_note["Newbud"] = 0;

            shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
            data_->Ultimate_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Summon","Castorice Ultimate");
            data_->Add_Buff_Single_Target(ptr->Sub_Unit_ptr[0].get());
            data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_) {
                if(ptr->Print)CharCmd::printUltStart("Castorice");
                debuffAllEnemyMarkVer(ptr->getSubUnit(1),ST_RESPEN,AT_NONE,20,"Lost Netherland");
                ptr->getSubUnit(1)->currentHP = 34000;
                Buff_single_target(ptr->getSubUnit(1),ST_FLAT_HP,AT_NONE,34000);
                ptr->getSubUnit(1)->Atv_stats->Base_speed = 165;
                Update_Max_atv(ptr->getSubUnit(1)->Atv_stats.get());
                atv_reset(ptr->getSubUnit(1)->Atv_stats.get());
                Action_forward(ptr->getSubUnit(1)->Atv_stats.get(),100);
                Extend_Buff_single_target(ptr->getSubUnit(1),"NetherwingLifeSpan",ptr->Adjust["NetherwingLifeSpan"]);       
                Buff_All_Ally_Each_Ally(ST_DMG_PERCENT,AT_NONE,10,"Roar Rumbles the Realm");
                Extend_Buff_All_Ally("Roar Rumbles the Realm",3);
                if(ptr->Eidolon>=2){
                    ptr->getSubUnit(1)->setStack("Ardent Will",2);
                    Action_forward(ptr->getSubUnit()->Atv_stats.get(),100);
                    ptr->getSubUnit()->Buff_note["Newbud"] = 10200;
                }
            };
            Action_bar.push(data_);
            if (!actionBarUse) Deal_damage();
        }));
        

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if(ptr->Eidolon>=4){
                Buff_All_Ally(ST_HEALING_OUT,AT_NONE,20);
            }
            if(ptr->Eidolon>=6){
                Buff_single_with_all_memo(ptr,ST_RESPEN,AT_NONE,20);
            }
        }));

        Setup_Memo_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed = -1;
            ptr->getSubUnit(1)->Atv_stats->Flat_Speed = 0;
            ptr->getSubUnit(1)->Atv_stats->Speed_percent = 0;
            ptr->Sub_Unit_ptr[1]->currentHP = 0;
            ptr->Sub_Unit_ptr[1]->Base_hp = 0;
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if(ptr->Technique==1){
                debuffAllEnemyMarkVer(ptr->getSubUnit(1),ST_RESPEN,AT_NONE,20,"Lost Netherland");
                

                ptr->getSubUnit(1)->currentHP = 17000;
                Buff_single_target(ptr->getSubUnit(1),ST_FLAT_HP,AT_NONE,34000);
                ptr->getSubUnit(1)->Atv_stats->Base_speed = 165;
                Update_Max_atv(ptr->getSubUnit(1)->Atv_stats.get());
                atv_reset(ptr->getSubUnit(1)->Atv_stats.get());
                Action_forward(ptr->getSubUnit(1)->Atv_stats.get(),100);
                turn = ptr->getSubUnit(1)->Atv_stats.get();
                Extend_Buff_single_target(ptr->getSubUnit(1),"NetherwingLifeSpan",1);
                DecreaseHP(ptr->Sub_Unit_ptr[0].get(),"Netherwing",0,0,40);
                Buff_All_Ally_Each_Ally(ST_DMG_PERCENT,AT_NONE,10,"Roar Rumbles the Realm");
                Extend_Buff_All_Ally("Roar Rumbles the Realm",3);
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
                Speed_Buff(ptr->getSubUnit()->Atv_stats.get(),40,0);
                ptr->getSubUnit()->setBuffCheck("Inverted Torch",true);
            }
        }));

        Healing_List.push_back(TriggerHealing(PRIORITY_IMMEDIATELY, [ptr](SubUnit *Healer, SubUnit *target, double Value) {
            if(target->isSameUnitName("Netherwing"))return;
            Value = (Value + target->getBuffNote("NetherwingHealLimit") > 4080) 
            ? 4080 - target->getBuffNote("NetherwingHealLimit")
            : Value;
            target->Buff_note["NetherwingHealLimit"]+=Value;
            if(ptr->getSubUnit(1)->currentHP==0){
                ptr->getSubUnit()->Buff_note["Newbud"]+=Value;
            }
            else {
                HealRatio healRatio = HealRatio();
                healRatio.setRatio(0,0,0,Value,0,0);
                Healing(healRatio,ptr->getSubUnit(1),ptr->getSubUnit(1));
            }
            if(target->isSameUnitName("Castorice")){
                if(!ptr->getSubUnit()->getBuffCheck("Inverted Torch")&&ptr->getSubUnit()->currentHP>=ptr->getSubUnit()->totalHP*0.5){
                    Speed_Buff(ptr->getSubUnit()->Atv_stats.get(),40,0);
                    ptr->getSubUnit()->setBuffCheck("Inverted Torch",true);
                }
            }
            
        }));

        HPDecrease_List.push_back(TriggerDecreaseHP(PRIORITY_IMMEDIATELY, [ptr](Unit *Trigger, SubUnit *target, double Value) {
            if(ptr->getSubUnit(1)->currentHP==0){
                ptr->getSubUnit()->Buff_note["Newbud"]+=Value;
            }else {
                HealRatio healRatio = HealRatio();
                healRatio.setRatio(0,0,0,Value,0,0);
                Healing(healRatio,ptr->getSubUnit(1),ptr->getSubUnit(1));
            }
            if(ptr->getSubUnit()->Buff_note["CastoriceTalentBuff"]!=decreaseHPCount){
                ptr->getSubUnit()->Buff_note["CastoriceTalentBuff"] = decreaseHPCount;
                Stack_Buff_single_with_all_memo(ptr,ST_DMG_PERCENT,AT_NONE,20,1,3,"CastoriceTalentBuff");
                Extend_Buff_single_with_all_memo(ptr,"CastoriceTalentBuff",3);
            }
            if(target->isSameUnitName("Castorice")){
                if(ptr->getSubUnit()->getBuffCheck("Inverted Torch")&&ptr->getSubUnit()->currentHP<ptr->getSubUnit()->totalHP*0.5){
                    Speed_Buff(ptr->getSubUnit()->Atv_stats.get(),-40,0);
                    ptr->getSubUnit()->setBuffCheck("Inverted Torch",false);
                }
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            
            if(Buff_end(ptr->getSubUnit(1),"NetherwingLifeSpan")){
                Kamikaze(ptr);
            }
            if(turn->isSameCharName("Netherwing")){
                Buff_single_target(ptr->getSubUnit(1),ST_DMG_PERCENT,AT_NONE,-30*ptr->getSubUnit(1)->getStack("Where The West Wind Dwells"));
                ptr->getSubUnit(1)->Stack["Where The West Wind Dwells"] = 0;
            }
            SubUnit *tempUnit = turn->canCastToSubUnit();
            if(tempUnit){
                if(Buff_end(tempUnit,"Roar Rumbles the Realm")){
                    tempUnit->setBuffCheck("Roar Rumbles the Realm",0);
                    Buff_single_target(tempUnit,ST_DMG_PERCENT,AT_NONE,-10);
                }
                if(Buff_end(tempUnit,"CastoriceTalentBuff")){
                    Buff_single_target(tempUnit,ST_DMG_PERCENT,AT_NONE,-20*tempUnit->getStack("CastoriceTalentBuff"));
                    tempUnit->setStack("CastoriceTalentBuff",0);
                }
            }
            
        }));

        Buff_List.push_back(TriggerByAction_Func(PRIORITY_ACTION, [ptr](shared_ptr<AllyActionData> &data_) {
            for(int i=1;i<=Total_ally;i++){
                for(unique_ptr<SubUnit> &e : Ally_unit[i]->Sub_Unit_ptr){
                    e->Buff_note["NetherwingHealLimit"] = 0;
                }
            }

            
        }));

        Before_attack_List.push_back(TriggerByAction_Func(PRIORITY_ACTION, [ptr](shared_ptr<AllyActionData> &data_) {
            for(int i=1;i<=Total_ally;i++){
                for(unique_ptr<SubUnit> &e : Ally_unit[i]->Sub_Unit_ptr){
                    e->Buff_note["NetherwingHealLimit"] = 0;
                }
            }
        }));

        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_ACTION, [ptr](shared_ptr<AllyActionData> &data_) {
            if(data_->actionName=="Wings Sweep the Ruins"){
                
            }
        }));
        
        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_ACTION, [ptr](SubUnit* Target, string StatsType) {
            if(!Target->isSameUnitName("Netherwing"))return;
            if(StatsType != ST_FLAT_HP && StatsType != ST_HP_PERCENT)return;
            double temp;
            if(ptr->getSubUnit(1)->currentHP==0){
                temp = -calculateHpOnStats(ptr->getSubUnit(1));
            }else{
                temp = 34000 - calculateHpOnStats(ptr->getSubUnit(1));
            }
             
            Buff_single_target(ptr->getSubUnit(1),ST_FLAT_HP,AT_NONE,temp);
        }));

        AllyDeath_List.push_back(TriggerAllyDeath(PRIORITY_ACTION, [ptr](SubUnit* target) {
            if(target->getBuffCheck("Roar Rumbles the Realm")){
                target->setBuffCheck("Roar Rumbles the Realm",0);
                target->setBuffCountdown("Roar Rumbles the Realm",0);
                Buff_single_target(target,ST_DMG_PERCENT,AT_NONE,-10);
            }
        }));
    }
    void BasicAttack(Ally *ptr){
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Basic_Attack_set(ptr->getSubUnit(),"Single_target","Castorice Skill");
        data_->Add_Target_Adjacent();
        data_->resetTurn();
        data_->Damage_spilt.Main.push_back({0,50,0,20});
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Skill(Ally *ptr){
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Skill_set(ptr->getSubUnit(),"Blast","Castorice Skill");
        data_->Add_Target_Adjacent();
        data_->resetTurn();
        data_->Damage_spilt.Main.push_back({0,50,0,20});
        data_->Damage_spilt.Adjacent.push_back({0,30,0,10});
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(ptr,0);
            DecreaseHP(ptr->Sub_Unit_ptr[0].get(),"Netherwing",0,0,30);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Enchance_Skill(Ally *ptr){
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Skill_set(ptr->getSubUnit(),"Aoe","Castorice Enchance Skill");
        data_->Add_Target_Other();
        data_->resetTurn();
        data_->Damage_spilt.Main.push_back({0,30,0,10});
        data_->Damage_spilt.Adjacent.push_back({0,30,0,10});
        data_->Damage_spilt.Other.push_back({0,30,0,10});
        data_->Damage_spilt.Main.push_back({0,50,0,10});
        data_->Damage_spilt.Adjacent.push_back({0,50,0,10});
        data_->Damage_spilt.Other.push_back({0,50,0,10});
        data_->All_Attacker.push_back(ptr->Sub_Unit_ptr[1].get());
        data_->Attack_trigger++;
        data_->Joint.push_back(AttackSource(1,ptr->Sub_Unit_ptr[1].get(),ptr->Sub_Unit_ptr[0].get()));
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(ptr,0);
            DecreaseHP(ptr->Sub_Unit_ptr[0].get(),"Netherwing",0,0,40);
            if(ptr->Eidolon>=1){
                for(Ratio_data &e : data_->Damage_spilt.Main)e.Hp_ratio*= 1.239;
                for(Ratio_data &e : data_->Damage_spilt.Adjacent)e.Hp_ratio*= 1.239;
                for(Ratio_data &e : data_->Damage_spilt.Other)e.Hp_ratio*= 1.239;
            }
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Kamikaze(Ally *ptr){
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Skill_set(ptr->getSubUnit(1),"Aoe","Wings Sweep the Ruins");
        data_->Add_Target_Other();
        data_->Skill_Type.push_back("Summon");
        data_->source = ptr->getSubUnit();
        if(ptr->Eidolon>=6)data_->Dont_care_weakness = 100;
        data_->Damage_spilt.Main.push_back({0,40,0,5});
        data_->Damage_spilt.Main.push_back({0,40,0,5});
        if(Total_enemy==1){
            data_->Damage_spilt.Main.push_back({0,40,0,5});
            data_->Damage_spilt.Main.push_back({0,40,0,5});
            data_->Damage_spilt.Main.push_back({0,40,0,5});
            data_->Damage_spilt.Main.push_back({0,40,0,5});

        }else if(Total_enemy==2){
            data_->Damage_spilt.Main.push_back({0,40,0,5});
            data_->Damage_spilt.Main.push_back({0,40,0,5});
            data_->Damage_spilt.Adjacent.push_back({0,40,0,5});
            data_->Damage_spilt.Adjacent.push_back({0,40,0,5});

        }else {
            data_->Damage_spilt.Adjacent.push_back({0,40,0,5});
            data_->Damage_spilt.Adjacent.push_back({0,40,0,5});
        }
        if(ptr->Eidolon>=1){
            for(Ratio_data &e : data_->Damage_spilt.Main)e.Hp_ratio*= 1.239;
            for(Ratio_data &e : data_->Damage_spilt.Adjacent)e.Hp_ratio*= 1.239;
            for(Ratio_data &e : data_->Damage_spilt.Other)e.Hp_ratio*= 1.239;
        }
        if(ptr->Eidolon>=6){
            data_->Damage_spilt.Main.push_back({0,40*1.239,0,5});
            data_->Damage_spilt.Main.push_back({0,40*1.239,0,5});
            data_->Damage_spilt.Main.push_back({0,40*1.239,0,5});
        }
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(ptr,0);
            Attack(data_);
            HealRatio healRatio = HealRatio();
            healRatio.setRatio(0,6,0,800,0,0);
            Healing(healRatio,ptr->getSubUnit(0));
            for(int i=1;i<=Total_enemy;i++){
                Enemy_unit[i]->debuffRemove("Lost Netherland"); 
                Enemy_unit[i]->debuffSingleTarget(ST_RESPEN,AT_NONE,-20);
            }
            ptr->getSubUnit(1)->Death();
            Buff_single_target(ptr->getSubUnit(1),ST_FLAT_HP,AT_NONE,-34000);
            ptr->getSubUnit(1)->setStack("Breath Scorches the Shadow",0);
            if(ptr->Print)CharCmd::printUltEnd("Castorice");
        };
        Action_bar.push(data_);
        if(!actionBarUse)Deal_damage();
        
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