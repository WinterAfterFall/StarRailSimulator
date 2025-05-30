
#ifndef RMC_H
#define RMC_H

#define F first
#define S second
#include "../Library.h"

namespace RMC{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
//temp
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);
    void Increase_Charge(Ally *ptr,double charge);
    void Memo_Skill(Ally *ptr);
    void Memo_Echance_Skill(Ally *ptr);


    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(103,160,160,E,"Ice","Remembrance","RMC",TYPE_STD);
        ptr->SetAllyBaseStats(1048,543,631);
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        SetMemoStats(ptr,68,0,"Ice","Mem",TYPE_STD);
        
        SubUnit *RMCptr = ptr->getSubUnit();
        SubUnit *Memptr = ptr->getSubUnit(1);
        //substats
        

        ptr->pushSubstats(ST_CD);
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(160);
        ptr->setRelicMainStats(ST_CD,ST_FLAT_SPD,ST_DMG,ST_EnergyRecharge);


        //func
        
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr,RMCptr,Memptr](){
            if(ptr->Sub_Unit_ptr[0]->Atv_stats->turn_cnt==1){
                Skill(ptr);
            }else{
                Basic_Atk(ptr);
            }
        };
        ptr->Sub_Unit_ptr[1]->Turn_func = [ptr,RMCptr,Memptr](){
        
            if(ptr->Sub_Unit_ptr[1]->Buff_check["Mem_Charge"]==1){
                Memo_Echance_Skill(ptr);
            }else{
                Memo_Skill(ptr);
            }
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr,RMCptr,Memptr]() {
            if (ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Charge"] >= 60 && chooseSubUnitBuff(ptr->Sub_Unit_ptr[1].get())->Atv_stats->atv <= 20) return;
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
            data_->setUltimate(ptr->Sub_Unit_ptr[1].get(), "Aoe", "RMC Ultimate");
            data_->addEnemyOtherTarget();
            data_->Damage_spilt.Main.push_back({264, 0, 0, 20});
            data_->Damage_spilt.Adjacent.push_back({264, 0, 0, 20});
            data_->Damage_spilt.Other.push_back({264, 0, 0, 20});
            data_->actionFunction = [ptr,RMCptr,Memptr](shared_ptr<AllyActionData> &data_) {
                Increase_Charge(ptr, 40);
                Memptr->buffSingle({{ST_CR,AT_NONE,100.0}});
                if (ptr->Print) CharCmd::printUltStart("RMC");
                
                Attack(data_);

                Memptr->buffSingle({{ST_CR,AT_NONE,-100.0}});
            };
            Action_bar.push(data_);
            Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AT_NONE] += 14;
            ptr->Sub_Unit_ptr[0]->Stats_type["Hp%"][AT_NONE] += 14;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CD][AT_NONE] += 37.3;

            // relic

            // substats
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr](SubUnit *target, string StatsType) {
            if (target->Atv_stats->Unit_Name != "Mem") return;
            if (StatsType == ST_CD) {
                double buffValue = (calculateCritdamForBuff(ptr->Sub_Unit_ptr[1].get(), 13.2) + 26.4);
                buffAllAlly({{ST_CD, AT_TEMP, buffValue - ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Talent_Buff"]}});
                buffAllAlly({{ST_CD, AT_NONE, buffValue - ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Talent_Buff"]}});
                ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Talent_Buff"] = buffValue;
                return;
            }
        }));


        Setup_Memo_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr]() {
            ptr->Sub_Unit_ptr[1]->Stats_type["Flat_Hp"][AT_NONE] += 688;
            ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed = -1;
            ptr->Sub_Unit_ptr[1]->currentHP = 0;
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr]() {
            if (ptr->Technique == 1) {
                for (int i = 1; i <= Total_enemy; i++) {
                    Action_forward(Enemy_unit[i]->Atv_stats.get(), -50);
                }
                shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
                data_->setTechnique(ptr->Sub_Unit_ptr[0].get(), "Aoe", "RMC Technique");
                data_->addEnemyOtherTarget();
                data_->Damage_spilt.Main.push_back({50, 0, 0, 0});
                data_->Damage_spilt.Adjacent.push_back({50, 0, 0, 0});
                data_->Damage_spilt.Other.push_back({50, 0, 0, 0});
                data_->actionFunction = [ptr,RMCptr,Memptr](shared_ptr<AllyActionData> &data_) {
                    Attack(data_);
                };
                Action_bar.push(data_);
                if (!actionBarUse) Deal_damage();
            }
            Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 30);
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr]() {
            double buffValue = (calculateCritdamForBuff(ptr->Sub_Unit_ptr[1].get(), 13.2) + 26.4);
            buffAllAlly({{ST_CD, AT_TEMP, buffValue - ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Talent_Buff"]}});
            buffAllAlly({{ST_CD, AT_NONE, buffValue - ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Talent_Buff"]}});
            ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Talent_Buff"] = buffValue;
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr]() {
            if (chooseSubUnitBuff(RMCptr)->isBuffEnd("Mem_Support")) {
                chooseCharacterBuff(RMCptr)->setBuffNote("Mem_Support",0);
                chooseCharacterBuff(RMCptr)->buffAlly({{ST_CR,AT_NONE,-10}});
            }
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr]() {
            ptr->Sub_Unit_ptr[1]->Buff_check["RMC_E2"] = 1;
        }));
        AfterDealingDamage_List.push_back(TriggerAfterDealDamage(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr]
            (shared_ptr<AllyActionData> &data_, Enemy *src, double damage) {
            Ally *ptr = data_->Attacker->ptrToChar;
            SubUnit *subUnit ;
            for(auto &each : ptr->Sub_Unit_ptr){
                if (each->getBuffCheck("Mem_Support")){
                    subUnit = each.get();
                    goto jump;
                }
            }
            return;
            jump:
            Cal_DamageNote(data_,src,src,damage,subUnit->getBuffNote("Mem_Support"),"Mem True " + data_->actionName);
        }));

        When_Energy_Increase_List.push_back(TriggerEnergy_Increase_Func(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr](Ally *target, double Energy) {
            if (ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed == -1) return;
            if(Energy==0){
                Increase_Charge(ptr,3);
                return;
            }
            if (Energy + target->Current_energy > target->Max_energy) {
                Energy = target->Max_energy - target->Current_energy;
            }
            ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Energy_cnt"] += Energy;
            Increase_Charge(ptr, floor(ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Energy_cnt"] / 10));
            ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Energy_cnt"] -= floor(ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Energy_cnt"] / 10) * 10;
        }));

        After_attack_List.push_back(TriggerByAllyAttackAction_Func(PRIORITY_IMMEDIATELY, [ptr,RMCptr,Memptr](shared_ptr<AllyActionData> &data_) {
            if (data_->Attacker->Atv_stats->Unit_Name != "Mem" && data_->Attacker->Atv_stats->Side == "Memosprite" && ptr->Sub_Unit_ptr[1]->Buff_check["RMC_E2"] == 1) {
                Increase_energy(ptr, 8);
                ptr->Sub_Unit_ptr[1]->Buff_check["RMC_E2"] = 0;
            }
        }));



        

    }


    void Increase_Charge(Ally *ptr,double charge){
        if(ptr->Sub_Unit_ptr[1]->Atv_stats->Base_speed==-1)return;
        ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Charge"]+=charge;
        if(ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Charge"]>=100){
            ptr->Sub_Unit_ptr[1]->Buff_note["Mem_Charge"]= 0;
            ptr->Sub_Unit_ptr[1]->Buff_check["Mem_Charge"]=1;
            Action_forward(ptr->Sub_Unit_ptr[1]->Atv_stats.get(),100);
        }
    }


    void Basic_Atk(Ally *ptr){
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->setBasicAttack(ptr->Sub_Unit_ptr[0].get(),"Single_target","RMC Basic Attack");
        data_->addEnemyTarget(chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()));
        data_->Turn_reset=true;
        data_->Damage_spilt.Main.push_back({100,0,0,10});
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(ptr,20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Skill(Ally *ptr){

        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->setSkill(ptr->Sub_Unit_ptr[0].get(),"Single_target","Buff","RMC Skill");
        data_->addBuffSingleTarget(ptr->Sub_Unit_ptr[0].get());
        data_->Turn_reset=true;
        data_->buffType.push_back("Summon");
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(ptr,30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            if(ptr->Sub_Unit_ptr[1]->currentHP == 0){
                ptr->Sub_Unit_ptr[1]->currentHP = ptr->Sub_Unit_ptr[1]->totalHP;
                ptr->Sub_Unit_ptr[1]->resetATV(130);
                Increase_Charge(ptr,90);
            }
        };
        Action_bar.push(data_);

    }



    void Memo_Skill(Ally *ptr){
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->setSkill(ptr->Sub_Unit_ptr[1].get(),"Aoe","Mem Skill");
        data_->addEnemyAdjacentTarget();
        data_->abilityTypeList.push_back("Summon");
        data_->Turn_reset=true;
        if(Total_enemy==1){
            data_->Damage_spilt.Main.push_back({39.6,0,0,5});
            data_->Damage_spilt.Main.push_back({39.6,0,0,5});
            data_->Damage_spilt.Main.push_back({39.6,0,0,5});
            data_->Damage_spilt.Main.push_back({39.6,0,0,5});
        }else if(Total_enemy==2){
            data_->Damage_spilt.Main.push_back({39.6,0,0,5});
            data_->Damage_spilt.Main.push_back({39.6,0,0,5});
            data_->Damage_spilt.Adjacent.push_back({39.6,0,0,5});
            data_->Damage_spilt.Adjacent.push_back({39.6,0,0,5});

        }else{
            data_->Damage_spilt.Main.push_back({39.6,0,0,5});
            data_->Damage_spilt.Main.push_back({39.6,0,0,5});
            data_->Damage_spilt.Adjacent.push_back({39.6,0,0,5});
        }
        data_->Damage_spilt.Main.push_back({99,0,0,10});
        data_->Damage_spilt.Adjacent.push_back({99,0,0,10});
        data_->Damage_spilt.Other.push_back({99,0,0,10});
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(ptr,10);
            Increase_Charge(ptr,5);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Memo_Echance_Skill(Ally *ptr){

        ptr->Sub_Unit_ptr[1]->Buff_check["Mem_Charge"]=0;
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->setSkill(ptr->Sub_Unit_ptr[1].get(),"Single","Buff","Mem Buff");
        data_->addBuffSingleTarget(chooseSubUnitBuff(ptr->Sub_Unit_ptr[1].get()));
        data_->Turn_reset=true;
        data_->abilityTypeList.push_back("Summon");
        
        
        data_->actionFunction = [ptr,RMCptr = ptr->Sub_Unit_ptr[1].get()](shared_ptr<AllyActionData> &data_){
            Increase_energy(ptr,10);
            if(ptr->Print)CharCmd::printUltStart("Mem");
            if(chooseSubUnitBuff(RMCptr)->isHaveToAddBuff("Mem_Support",3)){
                if(chooseCharacterBuff(ptr->Sub_Unit_ptr[1].get())->Max_energy == 0)
                chooseCharacterBuff(RMCptr)->setBuffNote("Mem_Support",36);
                else if (chooseCharacterBuff(RMCptr)->Max_energy >= 200)
                chooseCharacterBuff(RMCptr)->setBuffNote("Mem_Support",50);
                else 
                chooseCharacterBuff(RMCptr)->setBuffNote("Mem_Support",30 + 2 * floor((chooseCharacterBuff(RMCptr)->Max_energy - 100) / 10));

                chooseCharacterBuff(RMCptr)->buffAlly({{ST_CR,AT_NONE,10}});
            }
            Action_forward(chooseSubUnitBuff(ptr->Sub_Unit_ptr[1].get())->Atv_stats.get(),100);
        };
        Action_bar.push(data_);
    }  
}
#endif