
#ifndef Jingyuan_H
#define Jingyuan_H

#define F first
#define S second
#include "../Library.h"

namespace Jingyuan{
    void Setup_Jingyuan(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Reset(Ally *ptr);
    void Turn_func(Unit *ptr);
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);
    void After_turn(Ally *ptr);
    void Start_game(Ally *ptr);
    void Ult_func(Ally *ptr);//*

    bool Temp_Turn_Condition(Unit *ptr);
    bool Robin_temp(Ally *ptr);
    bool Temp_ult_Condition(Ally *ptr);

    /*
    void Setup_Jingyuan(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Reset(Ally *ptr);
    void Turn_func(Unit *ptr);
    void Before_turn(Ally *ptr);
    void After_turn(Ally *ptr);
    void Before_attack(Ally *ptr, Combat_data &data_);
    void After_attack(Ally *ptr, Combat_data &data_);
    void Buff_func(Ally *ptr, Combat_data &data_);
    void Dot_func(Enemy *target, Ally *ptr, double Dot_ratio);
    void Toughness_break_func(Ally *ptr, Enemy *target, int num);
    void Enemy_hit_func(Ally *ptr, Enemy *target);
    void Start_game(Ally *ptr);
    void Start_wave(Ally *ptr);
    void Apply_debuff_func(Ally *ptr, Enemy *target, int total_debuff);
    void Hit_func(Ally *ptr, int Hit_cnt);
    void Ult_func(Ally *ptr);//*
    */

    void Setup_Jingyuan(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally_unit[num] = make_unique<Ally>();
        Ally *ptr = Ally_unit[num].get();
        SetBaseStats(Ally_unit[num]->Sub_Unit_ptr[0].get(), 1164, 698, 485);
        SetBasicStats(Ally_unit[num].get(), 99, 130, 130, E, "Lightning", "Erudition", num, "Jingyuan", "Ally");
        

        //substats
        Ally_unit[num]->Total_substats=15;
        Ally_unit[num]->Separate_sub=15;
        Ally_unit[num]->Reroll_check=1;
        Ally_unit[num]->Substats.push_back({"Crit_dam",15});
        Ally_unit[num]->Substats.push_back({"Crit_rate",0});
        Ally_unit[num]->Substats.push_back({"Atk%",0});

        Ally_unit[num]->Max_damage_Substats.resize(Ally_unit[num]->Substats.size());


        //func
        LC(Ally_unit[num].get());
        Relic(Ally_unit[num].get());
        Planar(Ally_unit[num].get());
        Ally_unit[num]->Sub_Unit_ptr[0]->Turn_func = [ptr, allyPtr = ptr->Sub_Unit_ptr[0].get()]() {
            if ((sp <= Sp_Safety && Robin_temp(ptr)) || allyPtr->Atv_stats->turn_cnt == 1 && Sp_status == "Negative") {
                Basic_Atk(ptr);
            } else {
                Skill(ptr);
            }
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK, [ptr]() {
            if (((turn->Char_Name != "Jingyuan" || Ult_After_Turn == 1) && Robin_temp(ptr)) || !ultUseCheck(ptr)) return;
            ActionData data_ = ActionData();
            
            data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(), "Aoe","Jingyuan Ultimate");
            data_.Add_Target_Other();
            data_.Damage_spilt.Main.push_back({200, 0, 0, 20});
            data_.Damage_spilt.Adjacent.push_back({200, 0, 0, 20});
            data_.Damage_spilt.Other.push_back({200, 0, 0, 20});
            data_.actionFunction = [ptr](ActionData &data_){
                Attack(data_);
                if (ptr->Print)Char_Command::printUltStart("Jingyuan");
                ptr->Sub_Unit_ptr[0]->Stack["LL_stack"] += 3;
                if (ptr->Sub_Unit_ptr[0]->Stack["LL_stack"] >= 10) {
                    ptr->Summon_ptr[0]->Atv_stats->Flat_Speed = 70;
                    Speed_Buff(ptr->Summon_ptr[0]->Atv_stats.get(), 0, 0);
                } else {
                    Speed_Buff(ptr->Summon_ptr[0]->Atv_stats.get(), 0, 30);
                }
            };
            
            Action_bar.push(data_);
            if(!actionBarUse)Deal_damage();
        }));
        

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (!(ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num == turn->Unit_num && turn->Side == "Ally")) return;
            if (Buff_end(ptr->Sub_Unit_ptr[0].get(), "War_Marshal")) {
                ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"] -= 10;
                ptr->Sub_Unit_ptr[0]->Buff_check["War_Marshal"];
            }
            if (ptr->Eidolon >= 2 && Buff_end(ptr->Sub_Unit_ptr[0].get(), "Swing_Skies_Squashed")) {
                ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Basic_Attack"] -= 20;
                ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Skill"] -= 20;
                ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Ultimate"] -= 20;
                ptr->Sub_Unit_ptr[0]->Buff_check["Swing_Skies_Squashed"] = 0;
            }
        }));


        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 28;
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"] += 12;
            ptr->Sub_Unit_ptr[0]->Stats_type["Def%"]["None"] += 12.5;

            // relic
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"] += 32.4;
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += 25;
            ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Lightning"]["None"] += 38.8;
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 43.2;

            // substats
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += 11.5;

            // LL
            ptr->Sub_Unit_ptr[0]->Stack["LL_stack"] = 3;
            ptr->Summon_ptr[0]->Atv_stats->Flat_Speed = 0;
            ptr->Summon_ptr[0]->Atv_stats->Speed_percent = 0;
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr]() {
            if (ptr->Technique == 1) {
                ptr->Sub_Unit_ptr[0]->Stack["LL_stack"] += 3;
                Speed_Buff(ptr->Summon_ptr[0]->Atv_stats.get(), 0, 30);
            }
            Increase_energy(ptr, 15);
        }));


        //LL
        SetSummonStats(ptr, 60, "LL");
        Ally_unit[num]->Summon_ptr[0]->Turn_func = [ptr](){
            
            ActionData temp = ActionData();
            temp.Fua_set(ptr->Sub_Unit_ptr[0].get(),"Bounce","LL Attack");
            temp.Add_Target_Adjacent();
            temp.Skill_Type.push_back("Summon");
            temp.Turn_reset = 1;
            temp.actionFunction = [ptr](ActionData &data_){
                if(ptr->Sub_Unit_ptr[0]->Stack["LL_stack"]>=6){
                    ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["Summon"]+=25;
                }

                for(int i=1;i<=ptr->Sub_Unit_ptr[0]->Stack["LL_stack"];i++){
                    data_.Damage_spilt.Main.push_back({66,0,0,5});
                    if(ptr->Eidolon>=1){
                        data_.Damage_spilt.Adjacent.push_back({33,0,0,0});
                    }else{
                        data_.Damage_spilt.Adjacent.push_back({66*0.25,0,0,0});
                    }
                    
                }
                Attack(data_);

                if(ptr->Sub_Unit_ptr[0]->Stack["LL_stack"]>=6){
                    ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["Summon"]-=25;
                }
        
                turn->Flat_Speed = 0;
                ptr->Sub_Unit_ptr[0]->Stack["LL_stack"] = 3;
                
                
                if(ptr->Eidolon>=2){
                Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Swing_Skies_Squashed",2);
                
                if(!Buff_check(ptr->Sub_Unit_ptr[0].get(),"Swing_Skies_Squashed")){
                    ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Basic_Attack"]+=20;
                    ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Skill"]+=20;
                    ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Ultimate"]+=20;
                    ptr->Sub_Unit_ptr[0]->Buff_check["Swing_Skies_Squashed"] = 1;
                }
                }
            };
            
            Action_bar.push(temp);
            

        };

        
        

         
            
    }

    void Basic_Atk(Ally *ptr){
        
        ActionData data_ = ActionData();
        data_.Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Jingyuan BasicAtttack");
        data_.Add_Target(chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()));
        data_.Turn_reset=true;
        data_.Damage_spilt.Main.push_back({55,0,0,5.5});
        data_.Damage_spilt.Main.push_back({45,0,0,4.5});
        data_.actionFunction = [ptr] (ActionData &data_){
            Increase_energy(ptr,20);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Skill(Ally *ptr){
        
        ActionData data_ = ActionData();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Aoe","Jingyuan Skill");
        data_.Add_Target_Other();
        data_.Turn_reset=true;
        data_.Damage_spilt.Main.push_back({40,0,0,4});
        data_.Damage_spilt.Main.push_back({30,0,0,3});
        data_.Damage_spilt.Main.push_back({30,0,0,3});

        data_.Damage_spilt.Adjacent.push_back({40,0,0,4});
        data_.Damage_spilt.Adjacent.push_back({30,0,0,3});
        data_.Damage_spilt.Adjacent.push_back({30,0,0,3});

        data_.Damage_spilt.Other.push_back({40,0,0,4});
        data_.Damage_spilt.Other.push_back({30,0,0,3});
        data_.Damage_spilt.Other.push_back({30,0,0,3});
        data_.actionFunction = [ptr] (ActionData &data_){
            Increase_energy(ptr,30);
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
            if(!Buff_check(ptr->Sub_Unit_ptr[0].get(),"War_Marshal")){
                ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"]+=10;
                ptr->Sub_Unit_ptr[0]->Buff_check["War_Marshal"]=1;
    
            }
            Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"War_Marshal",2);
            ptr->Sub_Unit_ptr[0]->Stack["LL_stack"]+=2;
            if(ptr->Sub_Unit_ptr[0]->Stack["LL_stack"]>=10){
                ptr->Summon_ptr[0]->Atv_stats->Flat_Speed=70;
                Speed_Buff(ptr->Summon_ptr[0]->Atv_stats.get(),0,0);
            }else{
                Speed_Buff(ptr->Summon_ptr[0]->Atv_stats.get(),0,20);
            }
            Attack(data_);
        };
        Action_bar.push(data_);
        
    }



    bool Temp_Turn_Condition(Unit *ptr){
        return true;
    }
    bool Temp_ult_Condition(Ally *ptr){
        return true;
    }
    bool Robin_temp(Ally *ptr){
        if(Robin_num!=0&&Ally_unit[Robin_num]->Sub_Unit_ptr[0]->Atv_stats->Base_speed==-1){
            return false;
        }
        return true;
    }
}
#endif