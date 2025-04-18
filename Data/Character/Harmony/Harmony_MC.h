
#ifndef Harmony_MC_H
#define Harmony_MC_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Harmony_MC{
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Basic_Atk(Ally *ptr);  
    void Skill_func(Ally *ptr);

    
    void Setup(int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally* ptr = SetAllyBasicStats( 105, 140, 140, E, "Imaginary", "Harmony", "Harmony_MC",TYPE_STD);
        ptr->SetAllyBaseStats(1087, 446, 679);
        //substats
        ptr->pushSubstats("Break_effect");
        ptr->setTotalSubstats(20);
        //func
        LC(ptr);
        Relic(ptr);
        Planar(ptr);
        ptr->Sub_Unit_ptr[0]->Turn_func = [ptr](){
            if(sp > Sp_Safety || ptr->Sub_Unit_ptr[0]->Atv_stats->turn_cnt == 1){
                Skill_func(ptr);           
            } else {
                Basic_Atk(ptr);
            }
        };

        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr](){
            if(Buff_check(ptr->Sub_Unit_ptr[0].get(),"Harmony_MC_ult") || !ultUseCheck(ptr)) return;
            
            
            ActionData data_ = ActionData();
            data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(), "Aoe", "Buff", "HMC Ultimate");
            data_.Add_Buff_All_Ally();
            data_.actionFunction = [ptr](ActionData &data_){
                if(!Buff_check(ptr->Sub_Unit_ptr[0].get(),"Harmony_MC_ult")){
                    Buff_All_Ally("Break_effect","None",33);
                }
                ptr->Sub_Unit_ptr[0]->Buff_check["Harmony_MC_ult"] = 1;
                Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Harmony_MC_ult",3);
            };

            Action_bar.push(data_);
            if(!actionBarUse)Deal_damage();
        }));

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"] += 37.3;
            ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Imaginary"]["None"] += 14.4;

            // relic
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 43.2;
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += 25;
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] += 43.2;
            ptr->Energy_recharge += 19.4;

            // substats
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed += ptr->Sub_Speed_use;
        }));

        Tune_stats_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            Cal_Speed_Needed(ptr, 145);
        }));

        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"] = calculateBreakEffectForBuff(ptr->Sub_Unit_ptr[0].get(), 15);                  
            Buff_All_Ally_Excluding_Buffer("Break_effect",AT_TEMP,ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"],"Harmony_MC");
            Buff_All_Ally_Excluding_Buffer("Break_effect","None",ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"],"Harmony_MC");
        }));

        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY, [ptr](){
            if(ptr->Technique == 1){
                Buff_All_Ally("Break_effect","None",30);
            }
            ptr->Energy_recharge += 25;
        }));

        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr](){
            if(turn->Char_Name == "Harmony_MC" && Buff_end(ptr->Sub_Unit_ptr[0].get(),"Harmony_MC_ult")){
                Buff_All_Ally("Break_effect","None",-33);
                ptr->Sub_Unit_ptr[0]->Buff_check["Harmony_MC_ult"] = 0;
            }
        }));

        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF, [ptr](){
            if(turn->Char_Name == "Harmony_MC" && turn->turn_cnt == 3){
                ptr->Energy_recharge -= 25;
            }
            if(turn->Side == "Ally" || turn->Side == "Memosprite"){
                if(turn->turn_cnt == 2 && ptr->Technique == 1){
                    Buff_single_target(Ally_unit[turn->Unit_num]->Sub_Unit_ptr[0].get(),"Break_effect","None",-30);
                }
            }
        }));

        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_ACTTACK, [ptr](ActionData &data_){
            if(ptr->Sub_Unit_ptr[0]->Buff_check["Harmony_MC_ult"] == 1){
                Superbreak_trigger(data_, 100 * (1.7 - (0.1 * Total_enemy)));
            }
        }));

        Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY, [ptr](Enemy *target, SubUnit *Breaker){
            Increase_energy(ptr, 11);
            Action_forward(target->Atv_stats.get(), -30);
        }));

        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY, [ptr](SubUnit *target, string StatsType){
            if(target->Atv_stats->Unit_Name != "Harmony_MC") return;
            if(StatsType == "Break_effect"){
                double temp = calculateBreakEffectForBuff(ptr->Sub_Unit_ptr[0].get(), 15);
                Buff_All_Ally_Excluding_Buffer("Break_effect",AT_TEMP,temp - ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"],"Harmony_MC");
                Buff_All_Ally_Excluding_Buffer("Break_effect","None",temp - ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"],"Harmony_MC");
                ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"] =  temp ;
            }
        }));
 
    }



void Basic_Atk(Ally *ptr){
        
        ActionData data_ = ActionData();
        data_.Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","HMC BasicAttack");
        data_.Add_Target(chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()));
        data_.Turn_reset = 1;
        data_.Damage_spilt.Main.push_back({110,0,0,10});
        data_.actionFunction = [ptr](ActionData &data_){
            Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
            Increase_energy(ptr,20);
            Attack(data_);
        };
        Action_bar.push(data_);
    }
    void Skill_func(Ally *ptr){
        
        ActionData data_ = ActionData();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Bounce","HMC Skill");
        data_.Add_Target_Adjacent();
        data_.Turn_reset = 1;
        data_.Damage_spilt.Main.push_back({55,0,0,10});
        data_.Damage_spilt.Main.push_back({55,0,0,5});
        data_.Damage_spilt.Main.push_back({55,0,0,5});
        
        if(Total_enemy==1){
            data_.Damage_spilt.Main.push_back({55,0,0,5});
            data_.Damage_spilt.Main.push_back({55,0,0,5});
            data_.Damage_spilt.Main.push_back({55,0,0,5});
            data_.Damage_spilt.Main.push_back({55,0,0,5});
        }else if(Total_enemy==2){
            data_.Damage_spilt.Main.push_back({55,0,0,5});
            data_.Damage_spilt.Adjacent.push_back({55,0,0,5});
            data_.Damage_spilt.Adjacent.push_back({55,0,0,5});
            data_.Damage_spilt.Adjacent.push_back({55,0,0,5});
        }else if(Total_enemy>=3){
            data_.Damage_spilt.Adjacent.push_back({55,0,0,5});
            data_.Damage_spilt.Adjacent.push_back({55,0,0,5});
        }
        data_.actionFunction = [ptr](ActionData &data_){
            if(ptr->Sub_Unit_ptr[0]->Atv_stats->turn_cnt!=1)Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);     
            Increase_energy(ptr,30);
            Attack(data_);
        };
        
        Action_bar.push(data_);
    }




}
#endif
