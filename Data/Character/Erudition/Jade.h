
#ifndef Jade_H
#define Jade_H

#define F first
#define S second
#include "../Library.h"

namespace Jade{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);


//temp
    void Jade_Fua(Ally *ptr);
    void Jade_Talent(Ally *ptr,int amount);
    void Fua(Ally *ptr);
    void Fua_Enchance(Ally *ptr);


    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(103,140,140,E,"Quantum","Erudition","Jade",TYPE_STD);
        ptr->SetAllyBaseStats(1087,660,509);

        //substats
        ptr->pushSubstats(ST_CD);
        ptr->pushSubstats(ST_CR);
        ptr->pushSubstats("Atk%");
        ptr->setTotalSubstats(20);
        ptr->setRelicMainStats(ST_CR,ST_ATK_P,ST_DMG,ST_ATK_P);

        // ptr->setRelicMainStats(ST_CR,ST_FLAT_SPD,ST_DMG,ST_ATK_P);
        // ptr->setSpeedRequire(140);


        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            
            if (allyPtr->getBuffCheck("Jade_Skill")) {
                Basic_Atk(ptr);
            } else {
                Skill(ptr);
            }
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
            data_->setUltimate(ptr->Sub_Unit_ptr[0].get(), "Aoe","Jade Ultimate");
            data_->addEnemyOtherTarget();
            data_->Damage_spilt.Main.push_back({240, 0, 0, 20});
            data_->Damage_spilt.Adjacent.push_back({240, 0, 0, 20});
            data_->Damage_spilt.Other.push_back({240, 0, 0, 20});
            data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_) {
                ptr->Sub_Unit_ptr[0]->Stack["Jade_Ultimate_stack"] = 2;
                Attack(data_);
            };
            Action_bar.push(data_);
            if(!actionBarUse)Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"][AT_NONE] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_each_element[ST_DMG]["Quantum"][AT_NONE] += 22.4;

            // relic
            // substats
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Jade_Talent(ptr, Total_enemy);
            Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 50);
            if (ptr->Technique == 1) {
                
                shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
                data_->setTechnique(ptr->Sub_Unit_ptr[0].get(), "Aoe","Jade Technique");
                data_->addEnemyOtherTarget();
                data_->Damage_spilt.Main.push_back({50, 0, 0, 0});
                data_->Damage_spilt.Adjacent.push_back({50, 0, 0, 0});
                data_->Damage_spilt.Other.push_back({50, 0, 0, 0});
                data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_) {
                    Jade_Talent(ptr, 15);
                    Attack(data_);
                };
                Action_bar.push(data_);
                if(!actionBarUse)Deal_damage();
            }
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats->Char_Name == turn->Char_Name) {
                Jade_Talent(ptr, 3);
            }
            
            if (ptr->Sub_Unit_ptr[0].get()->isBuffEnd("Jade_Skill")) {
                chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{ST_SPD,ST_SPD_P,-30}});
            }
        }));

        When_attack_List.push_back(TriggerByAllyAction_Func(PRIORITY_IMMEDIATELY, [ptr](shared_ptr<AllyActionData> &data_) {
            if (data_->Attacker->Atv_stats->Unit_Name == "Jade" && data_->Action_type.second == "Fua") {
                Jade_Talent(ptr, 5);
                return;
            }
            if (ptr->Sub_Unit_ptr[0]->Buff_check["Jade_Skill"] == 0) return;
            if (data_->Attacker->Atv_stats->Unit_Name != "Jade" && data_->Attacker->Atv_stats->Unit_Name != chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats->Unit_Name) return;

            int temp = data_->Target_Attack.size();
            if (ptr->Eidolon >= 1 && temp < 3) temp = 3;
            ptr->Sub_Unit_ptr[0]->Stack["Jade_Talent"] += temp;
            Jade_Fua(ptr);
        }));

        Enemy_Death_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr](Enemy *target, SubUnit *Killer){
            Jade_Talent(ptr, 1);
        }));
        



        
    }



    void Basic_Atk(Ally *ptr){
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->setBasicAttack(ptr->Sub_Unit_ptr[0].get(),"Blast","Jade BasicAtttack");
        data_->addEnemyAdjacentTarget();
        data_->Turn_reset=true;
        data_->Damage_spilt.Main.push_back({90,0,0,10});
        data_->Damage_spilt.Adjacent.push_back({30,0,0,5});
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num].get(),20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Skill(Ally *ptr){
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->setSkill(ptr->Sub_Unit_ptr[0].get(),"Single_target","Buff","Jade Skill");
        data_->Add_Buff_Single_Target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()));
        data_->Turn_reset=true;
        
        
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num].get(),30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            if(ptr->Sub_Unit_ptr[0]->isHaveToAddBuff("Jade_Skill",3)){
                chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->buffSingle({{ST_SPD,ST_SPD_P,30}});
            }
        };
        Action_bar.push(data_);
    }


            
        

    void Jade_Fua(Ally *ptr){

        while(ptr->Sub_Unit_ptr[0]->Stack["Jade_Talent"]>8){
            ptr->Sub_Unit_ptr[0]->Stack["Jade_Talent"]-=8;
            if(ptr->Sub_Unit_ptr[0]->Stack["Jade_Ultimate_stack"]>0){
                Fua_Enchance(ptr);
                ptr->Sub_Unit_ptr[0]->Stack["Jade_Ultimate_stack"]--;             
            }else{
                Fua(ptr);
            }
        }
        if(!actionBarUse)Deal_damage();
    }
    void Fua(Ally *ptr){
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->setFua(ptr->Sub_Unit_ptr[0].get(),"Aoe","Jade Fua");
        data_->addEnemyOtherTarget();
        data_->Damage_spilt.Main.push_back({18,0,0,10});
        data_->Damage_spilt.Main.push_back({18,0,0,10});
        data_->Damage_spilt.Main.push_back({18,0,0,10});
        data_->Damage_spilt.Main.push_back({18,0,0,10});
        data_->Damage_spilt.Main.push_back({48,0,0,10});

        data_->Damage_spilt.Adjacent.push_back({18,0,0,10});
        data_->Damage_spilt.Adjacent.push_back({18,0,0,10});
        data_->Damage_spilt.Adjacent.push_back({18,0,0,10});
        data_->Damage_spilt.Adjacent.push_back({18,0,0,10});
        data_->Damage_spilt.Adjacent.push_back({48,0,0,10});

        data_->Damage_spilt.Other.push_back({18,0,0,10});
        data_->Damage_spilt.Other.push_back({18,0,0,10});
        data_->Damage_spilt.Other.push_back({18,0,0,10});
        data_->Damage_spilt.Other.push_back({18,0,0,10});
        data_->Damage_spilt.Other.push_back({48,0,0,10});
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(ptr,10);
            if(ptr->Eidolon>=1)ptr->getSubUnit()->buffSingle({{ST_DMG,AT_NONE,32}});
            Attack(data_);
            if(ptr->Eidolon>=1)ptr->getSubUnit()->buffSingle({{ST_DMG,AT_NONE,-32}});
        };
        Action_bar.push(data_);
        
    }
    void Fua_Enchance(Ally *ptr){
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->setFua(ptr->Sub_Unit_ptr[0].get(),"Aoe","Jade Enchance Fua");
        data_->addEnemyOtherTarget();
        data_->Damage_spilt.Main.push_back({20,0,0,10});
        data_->Damage_spilt.Main.push_back({20,0,0,10});
        data_->Damage_spilt.Main.push_back({20,0,0,10});
        data_->Damage_spilt.Main.push_back({20,0,0,10});
        data_->Damage_spilt.Main.push_back({120,0,0,10});

        data_->Damage_spilt.Adjacent.push_back({20,0,0,10});
        data_->Damage_spilt.Adjacent.push_back({20,0,0,10});
        data_->Damage_spilt.Adjacent.push_back({20,0,0,10});
        data_->Damage_spilt.Adjacent.push_back({20,0,0,10});
        data_->Damage_spilt.Adjacent.push_back({120,0,0,10});

        data_->Damage_spilt.Other.push_back({20,0,0,10});
        data_->Damage_spilt.Other.push_back({20,0,0,10});
        data_->Damage_spilt.Other.push_back({20,0,0,10});
        data_->Damage_spilt.Other.push_back({20,0,0,10});
        data_->Damage_spilt.Other.push_back({120,0,0,10});
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(ptr,10);
            if(ptr->Eidolon>=1)ptr->getSubUnit()->buffSingle({{ST_DMG,AT_NONE,32}});
            Attack(data_);
            if(ptr->Eidolon>=1)ptr->getSubUnit()->buffSingle({{ST_DMG,AT_NONE,-32}});
        };
        Action_bar.push(data_);
    }
    void Jade_Talent(Ally *ptr,int amount){
        ptr->getSubUnit()->buffStackSingle(
            {{ST_ATK_P,AT_NONE,0.5},
            {ST_CD,AT_NONE,2.4}},
            amount,50,"Pawned_Asset");
        if(ptr->Eidolon>=2&&ptr->Sub_Unit_ptr[0]->Stack["Pawned_Asset"]>=15&&ptr->getSubUnit()->isHaveToAddBuff("Jade_E2")){
            ptr->getSubUnit()->buffSingle({{ST_CR,AT_NONE,18}});
        }

    }





}
#endif