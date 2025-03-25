
#ifndef Harmony_MC_H
#define Harmony_MC_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Harmony_MC{
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Reset(Ally *ptr);
    void Turn_func(Unit *ptr);
    void Basic_Atk(Ally *ptr);  
    void Skill_func(Ally *ptr);
    void Ult_func(Ally *ptr);//*
    void Stats_Adjust(Ally *ptr,Sub_Unit *target, string StatsType);;
    void Tune_stats(Ally *ptr);
    void Before_turn(Ally *ptr);
    void After_turn(Ally *ptr);
    void When_Combat(Ally *ptr);
    void Start_game(Ally *ptr);
    void Toughness_break_func(Ally *ptr,Enemy *target,Sub_Unit *Breaker);
    void After_attack(Ally *ptr, Combat_data &data_);

    
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally_unit[num] = make_unique<Ally>();

        Ally_unit[num]->Sub_Unit_ptr[0]->Base_hp = 1087;
        Ally_unit[num]->Sub_Unit_ptr[0]->Base_atk = 446;
        Ally_unit[num]->Sub_Unit_ptr[0]->Base_def = 679;
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Base_speed = 105;
        Ally_unit[num]->Max_energy = 140;
        Ally_unit[num]->Ult_cost = 140;
        Ally_unit[num]->Eidolon = E;
        Ally_unit[num]->Sub_Unit_ptr[0]->Element_type.push_back("Imaginary");
        Ally_unit[num]->Path.push_back("Harmony");
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Unit_num = num;
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Char_Name = "Harmony_MC";
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Unit_Name = "Harmony_MC";
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Side = "Ally";
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->ptr_to_unit = Ally_unit[num]->Sub_Unit_ptr[0].get();

        //func
        LC(Ally_unit[num].get());
        Relic(Ally_unit[num].get());
        Planar(Ally_unit[num].get());
        Ally_unit[num]->Sub_Unit_ptr[0]->Turn_func = Turn_func;
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF,Ally_unit[num].get(),Ult_func));
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Reset));
        Tune_stats_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Tune_stats));
        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),When_Combat));
        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Start_game));
        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF,Ally_unit[num].get(),Before_turn));
        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF,Ally_unit[num].get(),After_turn));
        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_ACTTACK,Ally_unit[num].get(),After_attack));
        Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Toughness_break_func));
        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Stats_Adjust));



        //substats
        Ally_unit[num]->Total_substats=20;
        Ally_unit[num]->Separate_sub=20;

        Ally_unit[num]->Substats.push_back({"Break_effect",20});

        Ally_unit[num]->Max_damage_Substats.resize(Ally_unit[num]->Substats.size());
        
    }
    void Reset(Ally *ptr){
        ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"]+=37.3;
        ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Imaginary"]["None"]+=14.4;


        //relic
        ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"]+=43.2;
        ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed+=25;
        ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"]+=43.2;
        ptr->Energy_recharge+=19.4;
        
        

        //substats
        ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed+=ptr->Sub_Speed_use;

    }
    void Tune_stats(Ally *ptr){
        Cal_Speed_Needed(ptr,145);
    }
    void Turn_func(Unit *ptr){
        auto ally_ptr = dynamic_cast<Sub_Unit*>(ptr);
        if(sp>Sp_Safety||ptr->Atv_stats->turn_cnt==1){
            Skill_func(ally_ptr->ptr_to_unit);           
        }else{
            
            Basic_Atk(ally_ptr->ptr_to_unit);
        }
    }
    void Ult_func(Ally *ptr){
        if(Buff_check(ptr->Sub_Unit_ptr[0].get(),"Harmony_MC_ult")||!ultUseCheck(ptr))return;
        if(!Buff_check(ptr->Sub_Unit_ptr[0].get(),"Harmony_MC_ult")){
            Buff_All_Ally("Break_effect","None",33);
        }
        ptr->Sub_Unit_ptr[0]->Buff_check["Harmony_MC_ult"]=1;
        Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Harmony_MC_ult",3);
        Combat_data data_ = Combat_data();
        data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(),"Aoe","Buff");
        data_.Add_Buff_All_Ally();
        Action_bar.push(data_);
        Deal_damage();
    }
    void Basic_Atk(Ally *ptr){
        Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
        Increase_energy(ptr,20);
        Combat_data data_ = Combat_data();
        data_.Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target");
        data_.Add_Target(chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()));
        data_.Turn_reset = 1;
        data_.Damage_spilt.Main.push_back({110,0,0,10});
        Action_bar.push(data_);
    }
    void Skill_func(Ally *ptr){
        if(ptr->Sub_Unit_ptr[0]->Atv_stats->turn_cnt==1){

        }else{
            Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
        }
        
        Increase_energy(ptr,30);
        Combat_data data_ = Combat_data();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Bounce");
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
        
        Action_bar.push(data_);
    }
    void Toughness_break_func(Ally *ptr,Enemy *target,Sub_Unit *Breaker){
        Increase_energy(ptr,11);
        Action_forward(target->Atv_stats.get(),-30);
    }
    void Start_game(Ally *ptr){
        
        if(ptr->Technique==1){
            Buff_All_Ally("Break_effect","None",30);
        }
        ptr->Energy_recharge+=25;
    }
    void When_Combat(Ally *ptr){
        ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"]=calculateBreakEffectForBuff(ptr->Sub_Unit_ptr[0].get(),15);                  
        Buff_All_Ally_Excluding_Buffer("Break_effect","None",ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"],"Harmony_MC");
        Buff_All_Ally_Excluding_Buffer("Break_effect",AT_TEMP,ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"],"Harmony_MC");
        return;
    }
    void Stats_Adjust(Ally *ptr,Sub_Unit *target, string StatsType){
        if(target->Atv_stats->Unit_Name!="Harmony_MC")return;
        if(StatsType=="Break_effect"){
            Buff_All_Ally_Excluding_Buffer("Break_effect","None",-ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"],"Harmony_MC");
            Buff_All_Ally_Excluding_Buffer("Break_effect",AT_TEMP,-ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"],"Harmony_MC");
            
           
                

            ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"]=calculateBreakEffectForBuff(ptr->Sub_Unit_ptr[0].get(),15);
                    
                
                        

            Buff_All_Ally_Excluding_Buffer("Break_effect","None",ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"],"Harmony_MC");
            Buff_All_Ally_Excluding_Buffer("Break_effect",AT_TEMP,ptr->Sub_Unit_ptr[0]->Buff_note["Harmony_MC_E4"],"Harmony_MC");
            return;
               
        }
        
        
    }
    void Before_turn(Ally *ptr){
        if(turn->Char_Name=="Harmony_MC"&&Buff_end(ptr->Sub_Unit_ptr[0].get(),"Harmony_MC_ult")){
            Buff_All_Ally("Break_effect","None",-33);
            ptr->Sub_Unit_ptr[0]->Buff_check["Harmony_MC_ult"]=0;
            
        }
        

        
    }
    void After_turn(Ally *ptr){
        if(turn->Char_Name=="Harmony_MC"&&turn->turn_cnt==3){
            ptr->Energy_recharge-=25;
        }
        if(turn->Side=="Ally"||turn->Side=="Memosprite"){
            if(turn->turn_cnt==2&&ptr->Technique==1){
                Buff_single_target(Ally_unit[turn->Unit_num]->Sub_Unit_ptr[0].get(),"Break_effect","None",-30);

            }
            
        }
        

        
    }
    void After_attack(Ally *ptr, Combat_data &data_){
        

        if(ptr->Sub_Unit_ptr[0]->Buff_check["Harmony_MC_ult"]==1){
            Superbreak_trigger(data_,100*(1.7-(0.1*Total_enemy)));
        }
    }
}
#endif
