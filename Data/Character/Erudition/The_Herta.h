
#ifndef The_Herta_H
#define The_Herta_H

#define F first
#define S second
#include "../Library.h"

namespace The_Herta{
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Reset(Ally *ptr);
    void Turn_func(Unit *ptr);

    void Ult_func(Ally *ptr);
    void Tune_stats(Ally *ptr);
    void Start_game(Ally *ptr);
    void After_attack(Ally *ptr,ActionData &data_);
    void After_turn(Ally *ptr);
    void Enemy_Death(Ally *ptr,Enemy *target,SubUnit *Killer);
    void When_Combat(Ally *ptr);


//temp
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);
    void Enchance_Skill(Ally *ptr);
    void Apply_Herta_Stack(Ally* ptr ,Enemy* target,int Stack);
    void Herta_reset_Stack();
    bool Enchance_Skill_Condition(Ally *ptr);


    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally_unit[num] = make_unique<Ally>();
        Ally *ptr = Ally_unit[num].get();
        SetBaseStats(Ally_unit[num]->Sub_Unit_ptr[0].get(),1164,679,485);
        SetBasicStats(Ally_unit[num].get(),99,220,220,E,"Ice","Erudition",num,"The_Herta","Ally");
        Ally_unit[num]->Speed_Boot=0;

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

        Ally_unit[num]->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = Ally_unit[num]->Sub_Unit_ptr[0].get()]() {

            if (Enchance_Skill_Condition(ptr)) {
                return;
            } else if (sp > Sp_Safety || Sp_status == "Positive") {
                Skill(ptr);
            } else {
                Basic_Atk(ptr);
            }
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            if ((ptr->Sub_Unit_ptr[0]->Atv_stats->atv < ptr->Sub_Unit_ptr[0]->Atv_stats->Max_atv * 0.3)) return;
            if (!ultUseCheck(ptr)) return;

            ActionData data_ = ActionData();
            data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(), "Aoe","The Herta Ultimate");
            data_.Add_Target_Other();
            data_.actionFunction = [ptr](ActionData &data_){
                double Increase_mtpr = ptr->Sub_Unit_ptr[0]->Stack["The_Herta_A6"];
                data_.Damage_spilt.Main.push_back({200 + Increase_mtpr, 0, 0, 20});
                data_.Damage_spilt.Adjacent.push_back({200 + Increase_mtpr, 0, 0, 20});
                data_.Damage_spilt.Other.push_back({200 + Increase_mtpr, 0, 0, 20});
                ptr->Sub_Unit_ptr[0]->Buff_note["The_Herta_Skill_Enchance"]++;
                if (ptr->Eidolon >= 2) {
                    ptr->Sub_Unit_ptr[0]->Buff_note["The_Herta_Skill_Enchance"]++;
                }
                if (!Buff_check(ptr->Sub_Unit_ptr[0].get(), "Ult_The_Herta_Buff")) {
                    Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "Atk%", "None", 80);
                    ptr->Sub_Unit_ptr[0]->Buff_check["Ult_The_Herta_Buff"] = 1;
                }
                Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "Ult_The_Herta_Buff", 3);
                
                if (ptr->Print)CharCmd::printUltStart("The Herta");
                Attack(data_);

                Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(), 100);
                Herta_reset_Stack();
            };
            

            Action_bar.push(data_);
            if(!actionBarUse)Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 18;
            ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Ice"]["None"] += 22.4;
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += 5;

            // relic
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"] += 32.4;
            if (ptr->Speed_Boot) {
                ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += 25;
            } else {
                ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 43.2;
            }

            ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Ice"]["None"] += 38.8;

            if (ptr->Er_Rope) {
                ptr->Energy_recharge += 19.4;
            } else {
                ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 43.2;
            }

            // substats
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += ptr->Sub_Speed_use;
            int cnt = 0;
            for (int i = 1; i <= Total_ally; i++) {
                for (auto e : Ally_unit[i]->Path) {
                    if (e == "Erudition") cnt++;
                }
                if (cnt >= 2) {
                    ptr->Sub_Unit_ptr[0]->Buff_check["Two_Erudition"] = 1;
                    break;
                }
            }
        }));

        Tune_stats_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            Cal_Speed_Needed(ptr, ptr->Speed_tune_value);
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Technique == 1) {
                Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "Atk%", "None", 60);
                Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "The_Herta_Technique", 2);
            }
            Apply_Herta_Stack(ptr, Enemy_unit[Main_Enemy_num].get(), 25);
            for (int i = 1; i <= Total_enemy; i++) {
                Apply_Herta_Stack(ptr, Enemy_unit[i].get(), 1);
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr]() {
            if (Buff_end(ptr->Sub_Unit_ptr[0].get(), "The_Herta_Technique")) {
                Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "Atk%", "None", -60);
            }
            if (Buff_end(ptr->Sub_Unit_ptr[0].get(), "Ult_The_Herta_Buff")) {
                Buff_single_target(ptr->Sub_Unit_ptr[0].get(), "Atk%", "None", -80);
                ptr->Sub_Unit_ptr[0]->Buff_check["Ult_The_Herta_Buff"] = 0;
            }
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Sub_Unit_ptr[0]->Buff_check["Two_Erudition"] == 1) {
                Buff_All_Ally("Crit_dam", "None", 80);
            }
        }));

        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_BUFF, [ptr](ActionData &data_){
            if(data_.Action_type.second=="Skill" && ptr->Sub_Unit_ptr[0]->Buff_check["Ther_Herta_A2"]){
                ptr->Sub_Unit_ptr[0]->Buff_check["Ther_Herta_A2"] = 0;
                Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Dmg%","None",-50);
                if(ptr->Eidolon >= 2){
                    Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(),35);
                }
            }
            bool Erudition_check = 0;

            for(auto e : data_.Attacker->ptr_to_unit->Path){
                if(e == "Erudition") Erudition_check = 1;
            }
            for(auto e : data_.Target_Attack){
                Apply_Herta_Stack(ptr, e, 1);
            }
            if(Erudition_check){
                Apply_Herta_Stack(ptr, Enemy_unit[Main_Enemy_num].get(), 3);
            } else {
                Apply_Herta_Stack(ptr, Enemy_unit[Main_Enemy_num].get(), 1);
            }
            int energy_gen = data_.Target_Attack.size();
            if(energy_gen < 9) energy_gen = 9;
            Increase_energy(ptr, 0, energy_gen);
        }));

        Enemy_Death_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr](Enemy *target, SubUnit *Killer) {
            Apply_Herta_Stack(ptr, Enemy_unit[Main_Enemy_num].get(), 1);
        }));


        
    }
    

    bool Stack_Herta_Check(Ally *ptr){
        if(Enemy_unit[Main_Enemy_num]->Debuff["Herta_Stack"]>=42)return true;
        for(int i=1;i<=Total_enemy;i++){
            if(i==Main_Enemy_num)continue;
            if(Enemy_unit[Main_Enemy_num]->Debuff["Herta_Stack"] + Enemy_unit[i]->Debuff["Herta_Stack"]>42)return true;
        }
        return false;
    }
    bool Enchance_Skill_Condition(Ally *ptr){
        if(ptr->Eidolon>=2&&Driver_Type=="Double_turn"&&Ally_unit[Driver_num]->Sub_Unit_ptr[0]->Atv_stats->Max_atv < ptr->Sub_Unit_ptr[0]->Atv_stats->Max_atv&&ptr->Sub_Unit_ptr[0]->Atv_stats->Max_atv*0.65<Ally_unit[Driver_num]->Sub_Unit_ptr[0]->Atv_stats->atv){
            if(ptr->Current_energy>=190&&(CharCmd::Using_Skill(ptr)||ptr->Current_energy<200)){
                if(ptr->Sub_Unit_ptr[0]->Buff_note["The_Herta_Skill_Enchance"]>0){
                    Enchance_Skill(ptr);
                }else{
                    Skill(ptr);  
                }
                return true;
            }else if(ptr->Current_energy>=200){
                Basic_Atk(ptr);
                return true;
            }else{
                Enchance_Skill(ptr);
                return true;
            }
            
        }
        if(ptr->Sub_Unit_ptr[0]->Buff_note["The_Herta_Skill_Enchance"]>0){
            if(CharCmd::Using_Skill(ptr)&&Stack_Herta_Check(ptr)){
                Enchance_Skill(ptr);
            }else{
                Basic_Atk(ptr);
            }
            
            return true;
        }
        return false;
    }

    void Basic_Atk(Ally *ptr){
        ActionData data_ = ActionData();
        data_.Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","The Herta BasicAttack");
        data_.Add_Target(chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()));
        data_.Turn_reset=true;
        data_.Damage_spilt.Main.push_back({100,0,0,10});
        data_.actionFunction =[ptr](ActionData &data_){
            Increase_energy(ptr,20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Skill(Ally *ptr){
        

        ActionData data_ = ActionData();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Blast","The Herta Skill");
        data_.Add_Target_Other();
        data_.Damage_spilt.Main.push_back({70,0,0,5});
        data_.Damage_spilt.Main.push_back({70,0,0,5});
        data_.Damage_spilt.Main.push_back({70,0,0,5});

        data_.Damage_spilt.Adjacent.push_back({0,0,0,0});
        data_.Damage_spilt.Adjacent.push_back({70,0,0,5});
        data_.Damage_spilt.Adjacent.push_back({70,0,0,5});

        data_.Damage_spilt.Other.push_back({0,0,0,0});
        data_.Damage_spilt.Other.push_back({0,0,0,0});
        data_.Damage_spilt.Other.push_back({70,0,0,5});
        data_.Turn_reset=true;
        data_.actionFunction =[ptr](ActionData &data_){
            Increase_energy(ptr,30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            Apply_Herta_Stack(ptr,Enemy_unit[Main_Enemy_num].get(),1);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Enchance_Skill(Ally *ptr){
        ActionData data_ = ActionData();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Aoe","The Herta EnchanceSkill");
        data_.Add_Target_Other();
        data_.Turn_reset=true;
        data_.actionFunction =[ptr](ActionData &data_){
            Increase_energy(ptr,30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            double Increase_mtpr = Enemy_unit[Main_Enemy_num]->Debuff["Herta_Stack"];
            double mx =-1;
            if(ptr->Eidolon>=1){
                for(int i=2;i<=Total_enemy;i++){
                if(Enemy_unit[i]->Debuff["Herta_Stack"]>mx){
                    mx = Enemy_unit[i]->Debuff["Herta_Stack"];
                }
                }
                Increase_mtpr+=(0.5*mx);
            }
            
            if(ptr->Sub_Unit_ptr[0]->Buff_check["Two_Erudition"]==1){
                Increase_mtpr*=2;
            }
            data_.Damage_spilt.Main.push_back({80,0,0,5});
            data_.Damage_spilt.Main.push_back({80,0,0,5});
            data_.Damage_spilt.Main.push_back({80,0,0,5});
            data_.Damage_spilt.Main.push_back({40+Increase_mtpr*8,0,0,5});


            data_.Damage_spilt.Adjacent.push_back({0,0,0,0});
            data_.Damage_spilt.Adjacent.push_back({80,0,0,5});
            data_.Damage_spilt.Adjacent.push_back({80,0,0,5});
            data_.Damage_spilt.Adjacent.push_back({40+Increase_mtpr*4,0,0,5});


            data_.Damage_spilt.Other.push_back({0,0,0,0});
            data_.Damage_spilt.Other.push_back({0,0,0,0});
            data_.Damage_spilt.Other.push_back({80,0,0,5});
            data_.Damage_spilt.Other.push_back({40+Increase_mtpr*4,0,0,5});
            ptr->Sub_Unit_ptr[0]->Buff_note["The_Herta_Skill_Enchance"]--;

            Enemy_unit[Main_Enemy_num]->Debuff["Herta_Stack"] = 1;
            if(ptr->Eidolon>=1){
                Enemy_unit[Main_Enemy_num]->Debuff["Herta_Stack"] = 15;
            }
            Herta_reset_Stack();

            Apply_Herta_Stack(ptr,Enemy_unit[Main_Enemy_num].get(),1);
            ptr->Sub_Unit_ptr[0]->Buff_check["Ther_Herta_A2"] = 1;
            Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Dmg%","None",50); 
            Attack(data_);
        };
        
        Action_bar.push(data_);
    }

    
    void Herta_reset_Stack(){
        vector<int> vec;
        for(int i=1;i<=Total_enemy;i++){
            vec.push_back(Enemy_unit[i]->Debuff["Herta_Stack"]);
        }
        sort(vec.begin(),vec.end(),greater<int>());
        for(int i=1;i<=Total_enemy;i++){
            Enemy_unit[i]->Debuff["Herta_Stack"] = vec[i-1];
        }
        
    }
    void Apply_Herta_Stack(Ally* ptr ,Enemy* target,int Stack){
        if(ptr->Sub_Unit_ptr[0]->Stack["The_Herta_A6"]+Stack>99){
            ptr->Sub_Unit_ptr[0]->Stack["The_Herta_A6"] = 99;
        }else{
            ptr->Sub_Unit_ptr[0]->Stack["The_Herta_A6"]+=Stack;
        }
        if(target->Debuff["Herta_Stack"]==42){
            for(int i=1;i<=Total_enemy;i++){
                if(Enemy_unit[i]->Debuff["Herta_Stack"]<42){
                    if(Enemy_unit[i]->Debuff["Herta_Stack"]+Stack>42){
                        Enemy_unit[i]->Debuff["Herta_Stack"] = 42;
                    }else{
                        Enemy_unit[i]->Debuff["Herta_Stack"] += Stack;
                    }               
                    return;     
                }
            }
            return;
        }
        if(target->Debuff["Herta_Stack"]+Stack>42){
            target->Debuff["Herta_Stack"] = 42;
        }else{
            target->Debuff["Herta_Stack"] += Stack;
        }
    }


    
    

        

}
#endif