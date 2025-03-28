
#ifndef RuanMei_H
#define RuanMei_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Ruan_Mei{
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Reset(Ally *ptr);
    void Turn_func(Unit *ptr);
    void Basic_Atk(Ally *ptr);  
    void Skill_func(Ally *ptr);
    void Ult_func(Ally *ptr);//*
    void Tune_stats(Ally *ptr);
    void Before_turn(Ally *ptr);
    void After_turn(Ally *ptr);
    void Start_game(Ally *ptr);
    void Toughness_break(Ally *ptr,Enemy *target,Sub_Unit *Breaker);
    void After_attack(Ally *ptr, ActionData &data_);

    
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally_unit[num] = make_unique<Ally>();

        Ally_unit[num]->Sub_Unit_ptr[0]->Base_hp = 1087;
        Ally_unit[num]->Sub_Unit_ptr[0]->Base_atk = 660;
        Ally_unit[num]->Sub_Unit_ptr[0]->Base_def = 485;
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Base_speed = 104;
        Ally_unit[num]->Max_energy = 130;
        Ally_unit[num]->Ult_cost = 130;
        Ally_unit[num]->Eidolon = E;
        Ally_unit[num]->Sub_Unit_ptr[0]->Element_type.push_back("Ice");
        Ally_unit[num]->Path.push_back("Harmony");
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Unit_num = num;
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Char_Name = "Ruan_Mei";
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Unit_Name = "Ruan_Mei";
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
        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Start_game));
        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Start_game));
        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Before_turn));
        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),After_turn));
        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),After_attack));
        Toughness_break_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Toughness_break));





        
        

        //substats
        Ally_unit[num]->Total_substats=20;
        Ally_unit[num]->Separate_sub=20;
        Ally_unit[num]->Substats.push_back({"Break_effect",20});
        Ally_unit[num]->Max_damage_Substats.resize(Ally_unit[num]->Substats.size());
        
    }
    void Reset(Ally *ptr){
        ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"]+=37.3;
        ptr->Sub_Unit_ptr[0]->Stats_type["Def%"]["None"]+=22.5;
        ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed+=5;


        //relic
        ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"]+=43.2;
        ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed+=25;
        ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"]+=43.2;
        ptr->Energy_recharge+=19.4;
        
        

        //substats
        ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed+=ptr->Sub_Speed_use;

    }
    void When_Combat(Ally *ptr){
        Buff_All_Ally("Dmg%","None",36);
        Buff_All_Ally("Break_effect","None",20);
        Speed_Buff_All_Ally_Exclude_Buffer(10,0,"Ruan_Mei");
    } 
    void Tune_stats(Ally *ptr){
        Cal_Speed_Needed(ptr,145);
    }
    void Turn_func(Unit *ptr){
        auto ally_ptr = dynamic_cast<Sub_Unit*>(ptr);
        if(ally_ptr->Buff_check["Mei_Skill"] ==0){
            Skill_func(ally_ptr->ptr_to_unit);
        }else{
            
            Basic_Atk(ally_ptr->ptr_to_unit);
        }
    }
    void Basic_Atk(Ally *ptr){
        Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
        Increase_energy(ptr,20);
        ActionData data_ = ActionData();
        data_.Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target");
        data_.Add_Target_Main();
        data_.Turn_reset = 1;
        data_.Damage_spilt.Main.push_back({100,0,0,10});
        Action_bar.push(data_);
    }
    void Skill_func(Ally *ptr){
        Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
        Increase_energy(ptr,30);
        Buff_All_Ally("Dmg%","None",32);
        Buff_All_Ally("Weakness_Break_Efficiency","None",50);
        ptr->Sub_Unit_ptr[0]->Buff_check["Mei_Skill"] = 1;
        Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Mei_Skill",3);

        ActionData data_ = ActionData();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Buff");
        data_.Add_Buff_Single_Target(ptr->Sub_Unit_ptr[0].get());
        data_.Turn_reset = 1;
        Action_bar.push(data_);
    }
    void Ult_func(Ally *ptr){
        //return;
        if(!ultUseCheck(ptr))return;
        if(ptr->Print==1)cout<<"-------------------------------------------- Ruan Mei ult start at "<<Current_atv<<endl;
        if(!Buff_check(ptr->Sub_Unit_ptr[0].get(),"RuanMei_Ult")){
        Buff_All_Ally("Respen","None",25);
        if(ptr->Eidolon>=1){
            Buff_All_Ally("Def_shred","None",20);
        }
        }
        ptr->Sub_Unit_ptr[0]->Buff_check["RuanMei_Ult"] = 1;
        Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"RuanMei_Ult",2);

        
        ActionData data_ = ActionData();
        data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(),"Aoe","Buff");
        data_.Add_Buff_All_Ally();
        Action_bar.push(data_);
        Deal_damage();
    }
    void Before_turn(Ally *ptr){
        
        if(Buff_end(ptr->Sub_Unit_ptr[0].get(),"Mei_Skill")){
            ptr->Sub_Unit_ptr[0]->Buff_check["Mei_Skill"] = 0;
            Buff_All_Ally("Dmg%","None",-32);
            Buff_All_Ally("Weakness_Break_Efficiency","None",-50);
        }
        if(turn->Char_Name=="Ruan_Mei"){
            Increase_energy(ptr,5);
            if(Buff_end(ptr->Sub_Unit_ptr[0].get(),"RuanMei_Ult")){
                Buff_All_Ally("Respen","None",-25);
            if(ptr->Eidolon>=1){
                Buff_All_Ally("Def_shred","None",-20);
            }
                ptr->Sub_Unit_ptr[0]->Buff_check["RuanMei_Ult"] = 0;
                if(ptr->Print==1)cout<<"-------------------------------------------- Ruan Mei ult end at "<<Current_atv<<endl;
            }
        }
        if(turn->Side=="Enemy"&&Turn_Skip==0){
            if(Enemy_unit[turn->Unit_num]->Debuff["RuanMei_Ult_bloom"]==1){
                Turn_Skip = 1;
                Enemy_unit[turn->Unit_num]->Debuff["RuanMei_Ult_bloom"]=0;
                Enemy_unit[turn->Unit_num]->Total_debuff--;
                Action_forward(Enemy_unit[turn->Unit_num]->Atv_stats.get(),-10-(0.2*(ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"])));
                ActionData data_ = ActionData();
                data_.Break_dmg_set(ptr->Sub_Unit_ptr[0].get());
                double temp;
                temp = 0.5;
                Cal_Break_damage( data_,Enemy_unit[turn->Unit_num].get(),temp);
            }
        }
    }
    void After_attack(Ally *ptr, ActionData &data_){
        if(Buff_check(ptr->Sub_Unit_ptr[0].get(),"RuanMei_Ult")){
        int sz2 = data_.Damage_spilt.Adjacent.size();
        int sz3 = data_.Damage_spilt.Other.size();
        for(int i=1;i<=Total_enemy;i++){

            if(Enemy_unit[i]->Target_type=="Main"){
                if(Enemy_unit[i]->Debuff["RuanMei_Ult_bloom"]==1)continue;
                Apply_debuff(ptr->Sub_Unit_ptr[0].get(),Enemy_unit[i].get());
                Enemy_unit[i]->Total_debuff++;
                Enemy_unit[i]->Debuff["RuanMei_Ult_bloom"]=1;
            }
            
            if(0<sz2 && Enemy_unit[i]->Target_type=="Adjacent"){
                if(Enemy_unit[i]->Debuff["RuanMei_Ult_bloom"]==1)continue;
                Apply_debuff(ptr->Sub_Unit_ptr[0].get(),Enemy_unit[i].get());
                Enemy_unit[i]->Total_debuff++;
                Enemy_unit[i]->Debuff["RuanMei_Ult_bloom"]=1;
            }
            
            if(0<sz3 && Enemy_unit[i]->Target_type=="Other"){
                if(Enemy_unit[i]->Debuff["RuanMei_Ult_bloom"]==1)continue;
                Apply_debuff(ptr->Sub_Unit_ptr[0].get(),Enemy_unit[i].get());
                Enemy_unit[i]->Total_debuff++;
                Enemy_unit[i]->Debuff["RuanMei_Ult_bloom"]=1;
            }
            
            
        }
        }
    }
    void Toughness_break(Ally *ptr,Enemy *target,Sub_Unit *Breaker){
        ActionData data_ = ActionData();
        double temp;
        data_.Break_dmg_set(ptr->Sub_Unit_ptr[0].get());
        temp = 1.2;
        Cal_Break_damage( data_,target,temp);
        if(ptr->Eidolon>=2){
            if(Debuff_check(target,"RuanMei_E2")){
            Debuff_single_target(target,"Atk%","None",40);
            target->Debuff["RuanMei_E2"]=1;
            }
        }
        
    }
    void After_turn(Ally *ptr){
        
        if(turn->Side=="Enemy"&&ptr->Eidolon>=2&&Turn_Skip==0&&Debuff_check(Enemy_unit[turn->Unit_num].get(),"RuanMei_E2")){
            Debuff_single_target(Enemy_unit[turn->Unit_num].get(),"Atk%","None",40);
            Enemy_unit[turn->Unit_num]->Debuff["RuanMei_E2"]=0;
        }
    }
    void Start_game(Ally *ptr){
        if(ptr->Technique==1){
            Increase_energy(ptr,30);
        Buff_All_Ally("Dmg%","None",32);
        Buff_All_Ally("Weakness_Break_Efficiency","None",50);
        ptr->Sub_Unit_ptr[0]->Buff_check["Mei_Skill"] = 1;
        Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Mei_Skill",3);

        ActionData data_ = ActionData();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Buff");
        data_.Add_Buff_Single_Target(ptr->Sub_Unit_ptr[0].get());
        Action_bar.push(data_);
        Deal_damage();
        return;
        }
    }
}
#endif
