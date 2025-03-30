
#ifndef Pela_H
#define Pela_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Pela{
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);

    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally_unit[num] = make_unique<Ally>();
        Ally *ptr = Ally_unit[num].get();
        SetBaseStats(Ally_unit[num]->Sub_Unit_ptr[0].get(),1087,660,509);
        SetBasicStats(Ally_unit[num].get(),105,110,110,E,"Ice","Nihility",num,"Pela","Ally");

        //substats
        Ally_unit[num]->Total_substats=20;
        Ally_unit[num]->Separate_sub=20;
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
            Basic_Atk(ptr);
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            for (int i = 1; i <= Total_enemy; i++) {
                if (Enemy_unit[i]->Debuff["Zone_Suppression"] == 0) break;
                if (i == Total_enemy) return;
            }
            if (!ultUseCheck(ptr)) return;
            ActionData data_ = ActionData();
            data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(), "Aoe", "Pela Ultimate");
            data_.Add_Target_Other();
            data_.Turn_reset = true;
            data_.Damage_spilt.Main.push_back({108, 0, 0, 20});
            data_.Damage_spilt.Adjacent.push_back({108, 0, 0, 20});
            data_.Damage_spilt.Other.push_back({108, 0, 0, 20});
            data_.actionFunction = [ptr](ActionData &data_) {
                Debuff_All_Enemy_Apply_ver(ptr->Sub_Unit_ptr[0].get(), "Def_shred", "None", 42, "Zone_Suppression");
                Extend_Debuff_All_Enemy("Zone_Suppression", 2);
                Attack(data_);
            };
            Action_bar.push(data_);
            if (!actionBarUse) Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_each_element["Ice"]["None"]["None"] += 22.4;
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_type["Ehr"]["None"] += 10;

            // relic
            ptr->Sub_Unit_ptr[0]->Stats_type["Ehr"]["None"] += 43.2;
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += 25;
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 43.2;
            ptr->Energy_recharge += 19.4;

            // substats
            ptr->Sub_Unit_ptr[0]->Stats_type["Ehr"]["None"] += ptr->Sub_effect_hit_rate_use;
        }));

        Tune_stats_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Cal_effect_hit_rate(ptr, 100);
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Technique == 1) {
                Debuff_All_Enemy_Apply_ver(ptr->Sub_Unit_ptr[0].get(), "Def_shred", "None", 20, "Pela_Technique");
                Extend_Debuff_All_Enemy("Pela_Technique", 2);
                Increase_energy(ptr, 20);
            }
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Buff_All_Ally("Ehr", "None", 10);
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (turn->Side == "Enemy") {
                if (Enemy_unit[turn->Unit_num]->Debuff_time_count["Zone_Suppression"] == Enemy_unit[turn->Unit_num]->Atv_stats->turn_cnt) {
                    Enemy_unit[turn->Unit_num]->Debuff["Zone_Suppression"] = 0;
                    Enemy_unit[turn->Unit_num]->Stats_type["Def_shred"]["None"] -= 42;
                    --Enemy_unit[turn->Unit_num]->Total_debuff;
                }
                if (Enemy_unit[turn->Unit_num]->Debuff_time_count["Pela_Technique"] == turn->turn_cnt) {
                    Enemy_unit[turn->Unit_num]->Stats_type["Def_shred"]["None"] -= 20;
                    --Enemy_unit[turn->Unit_num]->Total_debuff;
                }
            }
        }));
        
        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY, [ptr](ActionData &data_) {
            if (data_.Attacker->Atv_stats->Char_Name != "Pela") return;

            for (auto e : data_.Target_Attack) {
                if (e->Total_debuff == 0) continue;
                Increase_energy(ptr, 11);
                break;
            }

            if (ptr->Eidolon >= 6) {
                ActionData temp = ActionData();
                temp.Additional_set(ptr->Sub_Unit_ptr[0].get(), "Single_target", "Pela E6");
                for (auto e : data_.Target_Attack) {
                    Cal_Additional_damage(temp, e, {40, 0, 0, 0});
                }
            }
        }));



        //substats
        Ally_unit[num]->Total_substats=20;
        Ally_unit[num]->Separate_sub=20;

        Ally_unit[num]->Substats.push_back({"Speed",20});

        Ally_unit[num]->Max_damage_Substats.resize(Ally_unit[num]->Substats.size());


    }



    void Basic_Atk(Ally *ptr){
        ActionData data_ = ActionData();
        data_.Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Pela BasicAttack");
        data_.Add_Target(chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()));
        data_.Turn_reset=true;
        data_.Damage_spilt.Main.push_back({55,0,0,5});
        data_.Damage_spilt.Main.push_back({55,0,0,5});
        data_.actionFunction = [ptr](ActionData &data_){
            Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num].get(),20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    





    

    
}

#endif
