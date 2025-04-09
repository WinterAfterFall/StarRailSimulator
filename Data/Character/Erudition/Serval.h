
#ifndef Serval_H
#define Serval_H

#define F first
#define S second
#include "../Library.h"

namespace Serval{
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);





//temp
    bool Use_Skill();
    
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally_unit[num] = make_unique<Ally>();
        Ally *ptr = Ally_unit[num].get();
        SetBaseStats(Ally_unit[num]->Sub_Unit_ptr[0].get(),917,653,375);
        SetBasicStats(Ally_unit[num].get(),104,100,100,E,"Lightning","Erudition",num,"Serval","Ally");

        //substats
        Ally_unit[num]->Total_substats=20;
        Ally_unit[num]->SeparateRatio=20;
        Ally_unit[num]->Reroll_check=1;

        Ally_unit[num]->Substats.push_back({"Crit_dam",20});
        Ally_unit[num]->Substats.push_back({"Crit_rate",0});
        Ally_unit[num]->Substats.push_back({"Atk%",0});

        Ally_unit[num]->Max_damage_Substats.resize(Ally_unit[num]->Substats.size());


        //func
        LC(Ally_unit[num].get());
        Relic(Ally_unit[num].get());
        Planar(Ally_unit[num].get());
        Ally_unit[num]->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
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
            ptr->Sub_Unit_ptr[0]->Stats_type["Ehr"]["None"] += 43.2;
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += 25;
            ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Lightning"]["None"] += 38.8;
            ptr->Energy_recharge += 19.4;

            // substats
            ptr->Sub_Unit_ptr[0]->Stats_type["Ehr"]["None"] += ptr->Sub_effect_hit_rate_use;
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += ptr->Sub_Speed_use;
        }));

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            if (!ultUseCheck(ptr)) return;
            ActionData data_ = ActionData();
            data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(), "Aoe", "Serval Ultimate");
            data_.Add_Target_Other();
            data_.Damage_spilt.Main.push_back({194, 0, 0, 20});
            data_.Damage_spilt.Adjacent.push_back({194, 0, 0, 20});
            data_.Damage_spilt.Other.push_back({194, 0, 0, 20});
            data_.actionFunction = [ptr](ActionData &data_){
                Attack(data_);
                if (ptr->Eidolon >= 4){
                    for (int i = 1; i <= Total_enemy; i++) {
                        if (!Debuff_check(Enemy_unit[i].get(), "Serval_Shock")) {
                            Enemy_unit[i]->Debuff["Serval_Shock"] = 1;
                            Enemy_unit[i]->Debuff["Shock_check"]++;
                            Enemy_unit[i]->Total_debuff++;
                        }
                        debuffApply(ptr->Sub_Unit_ptr[0].get(), Enemy_unit[i].get());
                        Extend_Debuff_single_target(Enemy_unit[i].get(), "Serval_Shock", 2);
                    }
                }
            };
            Action_bar.push(data_);
            
            
            if (!actionBarUse) Deal_damage();
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if (turn->Unit_Name == "Serval") {
                if (Buff_end(ptr->Sub_Unit_ptr[0].get(), "Serval_A6")) {
                    ptr->Sub_Unit_ptr[0]->Buff_check["Serval_A6"] = 0;
                    ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] -= 20;
                }
            }
            if (turn->Side == "Enemy") {
                Enemy *tempstats = dynamic_cast<Enemy*>(turn->ptr_to_unit);
                if (tempstats) {
                    if (Debuff_end(tempstats, "Serval_Shock")) {
                        tempstats->Debuff["Serval_Shock"] = 0;
                        tempstats->Debuff["Shock_check"]--;
                        tempstats->Total_debuff--;
                    }
                }
            }
        }));
        Tune_stats_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Cal_Speed_Needed(ptr, 150);
            Cal_effect_hit_rate(ptr, 100);
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            Increase_energy(ptr, 15);
            if (ptr->Eidolon >= 6) {
                ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["None"] += 30;
            }
        }));

        Dot_List.push_back(TriggerDot_Func(PRIORITY_BUFF, [ptr](Enemy* target, double Dot_ratio, string Dot_type) {
            if (Dot_type != "None" && Dot_type != "Lightning") return;
            if (!Debuff_check(target, "Serval_Shock")) return;
            ActionData data_ = ActionData();
            data_.Dot_set(ptr->Sub_Unit_ptr[0].get(), "Single_target", "Serval Shock");
            data_.Damage_spilt.Main.push_back({114, 0, 0, 0});
            Cal_Dot_damage(data_, target, Dot_ratio);
        }));

        When_attack_List.push_back(TriggerByAction_Func(PRIORITY_ACTTACK, [ptr](ActionData &data_) {
            if (data_.Attacker->Atv_stats->Unit_Name != "Serval") return;
            ActionData data_temp = ActionData();
            data_temp.Additional_set(ptr->Sub_Unit_ptr[0].get(), "Single_target", "Serval Additional Damage");
            for (int i = 1; i <= Total_enemy; i++) {
                if (Debuff_check(Enemy_unit[i].get(), "Serval_Shock")) {
                    Cal_Additional_damage(data_temp, Enemy_unit[i].get(), {79, 0, 0, 0});
                    if (ptr->Eidolon >= 2) {
                        Increase_energy(ptr, 4);
                    }
                }
            }
        }));

        Enemy_Death_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr](Enemy *target, SubUnit *Killer) {
            if (!Buff_check(ptr->Sub_Unit_ptr[0].get(), "Serval_A6")) {
                ptr->Sub_Unit_ptr[0]->Buff_check["Serval_A6"] = 1;
                ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 20;
            }
            Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "Serval_A6", 2);
        }));


        
    }



    void Basic_Atk(Ally *ptr){
        
        ActionData data_ = ActionData();
        data_.Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Serval BasicAttack");
        data_.Add_Target(chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()));
        if(Total_enemy>=2){
            if(ptr->Sub_Unit_ptr[0]->Enemy_target_num==1){
                data_.Add_Target(Enemy_unit[2].get());
            }else{
                data_.Add_Target(Enemy_unit[1].get());
            }
        }
        data_.Turn_reset=true;
        data_.Damage_spilt.Main.push_back({110,0,0,10});
        if(ptr->Eidolon>=1)data_.Damage_spilt.Adjacent.push_back({60,0,0,0});
        data_.actionFunction = [ptr](ActionData &data_){
            Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num].get(),20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Skill(Ally *ptr){
        ActionData data_ = ActionData();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Blast","Serval Skill");
        data_.Add_Target_Adjacent();
        data_.Turn_reset=true;
        data_.Damage_spilt.Main.push_back({154,0,0,20});
        data_.Damage_spilt.Adjacent.push_back({66,0,0,10});

        data_.actionFunction = [ptr](ActionData &data_){
            Increase_energy(ptr,30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            for(int i=1;i<=Total_enemy;i++){
                if(!Debuff_check(Enemy_unit[i].get(),"Serval_Shock")){
                    Enemy_unit[i]->Debuff["Serval_Shock"] = 1;
                    Enemy_unit[i]->Debuff["Shock_check"]++;
                    Enemy_unit[i]->Total_debuff++;
                }
                debuffApply(ptr->Sub_Unit_ptr[0].get(),Enemy_unit[i].get());
                Extend_Debuff_single_target(Enemy_unit[i].get(),"Serval_Shock",2);
            }
            Attack(data_);
        };
        Action_bar.push(data_);
        
    }







}
#endif