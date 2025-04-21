
#ifndef Serval_H
#define Serval_H

#define F first
#define S second
#include "../Library.h"

namespace Serval{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);





//temp
    bool Use_Skill();
    
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally *ptr = SetAllyBasicStats(104,100,100,E,"Lightning","Erudition","Serval",TYPE_STD);
        SubUnit *Servalptr = ptr->getSubUnit();
        ptr->SetAllyBaseStats(917,653,375);
        //substats
        ptr->pushSubstats("Crit_dam");
        ptr->pushSubstats("Crit_rate");
        ptr->pushSubstats("Atk%");
        ptr->setTotalSubstats(20);
        ptr->setSpeedRequire(150);
        ptr->setApplyBaseChance(100);
        ptr->setRelicMainStats(ST_EHR,ST_FLAT_SPD,ST_DMG_PERCENT,ST_EnergyRecharge);


        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            if (allyPtr->Atv_stats->turn_cnt % 3 != 1) {
                Basic_Atk(ptr);
            } else {
                Skill(ptr);
            }
        };

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Ehr"]["None"] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"] += 18.7;

            // relic

            // substats
        }));

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            if (!ultUseCheck(ptr)) return;
            shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
            data_->Ultimate_set(ptr->Sub_Unit_ptr[0].get(), "Aoe", "Serval Ultimate");
            data_->Add_Target_Other();
            data_->Damage_spilt.Main.push_back({194, 0, 0, 20});
            data_->Damage_spilt.Adjacent.push_back({194, 0, 0, 20});
            data_->Damage_spilt.Other.push_back({194, 0, 0, 20});
            data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
                Attack(data_);
                if (ptr->Eidolon >= 4){
                    for (int i = 1; i <= Total_enemy; i++) {
                        if (Enemy_unit[i]->debuffApply(ptr->getSubUnit(),"Serval_Shock")) {
                            Enemy_unit[i]->Debuff["Shock_check"]++;
                        }
                    }
                    extendDebuffAll("Serval_Shock", 2);
                }
            };
            Action_bar.push(data_);
            
            
            if (!actionBarUse) Deal_damage();
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if (turn->Unit_Name == "Serval") {
                if (ptr->Sub_Unit_ptr[0].get()->isBuffEnd("Serval_A6")) {
                    ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] -= 20;
                }
            }
            if (turn->Side == "Enemy") {
                Enemy *tempstats = dynamic_cast<Enemy*>(turn->ptr_to_unit);
                if (tempstats) {
                    if (tempstats->isDebuffEnd("Serval_Shock")) {
                        tempstats->Debuff["Shock_check"]--;
                    }
                }
            }
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            Increase_energy(ptr, 15);
            if (ptr->Eidolon >= 6) {
                ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["None"] += 30;
            }
        }));

        Dot_List.push_back(TriggerDot_Func(PRIORITY_BUFF, [ptr,Servalptr](Enemy* target, double Dot_ratio, string Dot_type) {
            if (Dot_type != "None" && Dot_type != "Lightning") return;
            if (!target->getDebuff("Serval_Shock")) return;
            shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
            data_->Dot_set(ptr->Sub_Unit_ptr[0].get(), "Single_target", "Serval Shock");
            data_->Damage_spilt.Main.push_back({114, 0, 0, 0});
            Cal_Dot_damage(data_, target, Dot_ratio);
        }));

        When_attack_List.push_back(TriggerByAction_Func(PRIORITY_ACTTACK, [ptr](shared_ptr<AllyActionData> &data_) {
            if (data_->Attacker->Atv_stats->Unit_Name != "Serval") return;
            shared_ptr<AllyActionData> data_temp = make_shared<AllyActionData>();
            data_temp->Additional_set(ptr->Sub_Unit_ptr[0].get(), "Single_target", "Serval Additional Damage");
            for (int i = 1; i <= Total_enemy; i++) {
                if (Enemy_unit[i]->getDebuff("Serval_Shock")) {
                    Cal_Additional_damage(data_temp, Enemy_unit[i].get(), {79, 0, 0, 0});
                    if (ptr->Eidolon >= 2) {
                        Increase_energy(ptr, 4);
                    }
                }
            }
        }));

        Enemy_Death_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr,Servalptr](Enemy *target, SubUnit *Killer) {
            Servalptr->buffSingle({{ST_ATK_PERCENT,AT_NONE,20}},"Serval_A6",2);
        }));


        
    }



    void Basic_Atk(Ally *ptr){
        
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Serval BasicAttack");
        data_->Add_Target(chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()));
        if(Total_enemy>=2){
            if(ptr->Sub_Unit_ptr[0]->Enemy_target_num==1){
                data_->Add_Target(Enemy_unit[2].get());
            }else{
                data_->Add_Target(Enemy_unit[1].get());
            }
        }
        data_->Turn_reset=true;
        data_->Damage_spilt.Main.push_back({110,0,0,10});
        if(ptr->Eidolon>=1)data_->Damage_spilt.Adjacent.push_back({60,0,0,0});
        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num].get(),20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Skill(Ally *ptr){
        shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
        data_->Skill_set(ptr->Sub_Unit_ptr[0].get(),"Blast","Serval Skill");
        data_->Add_Target_Adjacent();
        data_->Turn_reset=true;
        data_->Damage_spilt.Main.push_back({154,0,0,20});
        data_->Damage_spilt.Adjacent.push_back({66,0,0,10});

        data_->actionFunction = [ptr](shared_ptr<AllyActionData> &data_){
            Increase_energy(ptr,30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            for (int i = 1; i <= Total_enemy; i++) {
                if (Enemy_unit[i]->debuffApply(ptr->getSubUnit(),"Serval_Shock")) {
                    Enemy_unit[i]->Debuff["Shock_check"]++;
                }
            }
            extendDebuffAll("Serval_Shock", 2);
            Attack(data_);
        };
        Action_bar.push(data_);
        
    }







}
#endif