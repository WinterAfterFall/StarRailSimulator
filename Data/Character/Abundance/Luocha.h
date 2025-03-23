
#ifndef Luocha_H
#define Luocha_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Luocha{
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Reset(Ally *ptr);
    void Turn_func(Unit *ptr);
    void Basic_Atk(Ally *ptr);
    void Talent(Ally *ptr);
    void Abyss_Flower(Ally *ptr);
    void Ult_func(Ally *ptr);//*
    void After_turn(Ally *ptr);
    void Start_game(Ally *ptr);
    void When_attack(Ally *ptr,Combat_data &data_);

    
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally_unit[num] = make_unique<Ally>();

        Ally_unit[num]->Sub_Unit_ptr[0]->Base_hp = 1280;
        Ally_unit[num]->Sub_Unit_ptr[0]->Base_atk = 756;
        Ally_unit[num]->Sub_Unit_ptr[0]->Base_def = 363;
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Base_speed = 101;
        Ally_unit[num]->Max_energy = 100;
        Ally_unit[num]->Ult_cost = 100;
        Ally_unit[num]->Eidolon = E;
        Ally_unit[num]->Sub_Unit_ptr[0]->Element_type.push_back("Imaginary");
        Ally_unit[num]->Path.push_back("Abundance"); 
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Unit_num = num;
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Char_Name = "Luocha";
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Unit_Name = "Luocha";
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Side = "Ally";
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->ptr_to_unit = Ally_unit[num]->Sub_Unit_ptr[0].get();

        //func
        LC(Ally_unit[num].get());
        Relic(Ally_unit[num].get());
        Planar(Ally_unit[num].get());
        
        Ally_unit[num]->Sub_Unit_ptr[0]->Turn_func = Turn_func;
        Ultimate_List.push_back({PRIORITY_DEBUFF,Ally_unit[num].get(),Ult_func});
        Reset_List.push_back({PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Reset});
        After_turn_List.push_back({PRIORITY_IMMEDIATELY,Ally_unit[num].get(),After_turn});
        Start_game_List.push_back({PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Start_game});
        When_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),When_attack));

    }
    void Reset(Ally *ptr){
        ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] +=28;
        ptr->Sub_Unit_ptr[0]->Stats_type["Hp%"]["None"] +=18;
        ptr->Sub_Unit_ptr[0]->Stats_type["Def%"]["None"] +=12.5;


        //relic
        // bonus heal +35.7
        ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed+=25;
        ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] +=43.2;
        ptr->Energy_recharge+=19.4;
        
        

        //substats
        ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"] +=19.44; //5

        ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed+=34.5; //15


    }
    void Turn_func(Unit *ptr){
        auto ally_ptr = dynamic_cast<Sub_Unit*>(ptr);
        Basic_Atk(ally_ptr->ptr_to_unit);
            
    }
    void Talent(Ally *ptr){
        Increase_energy(ptr,30);
        ++ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"];
        Heal_data healData = Heal_data();
        healData.setHealer(ptr->Sub_Unit_ptr[0].get());
        healData.main.setRatio(60,0,0,800,0,0);
        Healing(healData);
        Abyss_Flower(ptr);
        
    }
    void Abyss_Flower(Ally *ptr){
        if(ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"]==2){
        Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Cycle_of_Life",2);
        if(ptr->Eidolon>=1){
            Buff_All_Ally("Atk%","None",20);
        }
        }
    }
    void Basic_Atk(Ally *ptr){
        Increase_energy(ptr,20);
        Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
        Combat_data data_ = Combat_data();
        data_.Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target");
        data_.Add_Target_Main();
        data_.Turn_reset = 1;
        data_.Damage_spilt.Main.push_back({30,0,0,3});
        data_.Damage_spilt.Main.push_back({30,0,0,3});
        data_.Damage_spilt.Main.push_back({40,0,0,4});
        Action_bar.push(data_);
        if(ptr->Sub_Unit_ptr[0]->Atv_stats->turn_cnt%2==1){
            Talent(ptr);
        }
    }
    void Ult_func(Ally *ptr){
        if(ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"]>=2)return;
        if(!ultUseCheck(ptr))return;
        Combat_data data_ = Combat_data();
        data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(),"Aoe");
        data_.Add_Target_Other();
        data_.Damage_spilt.Main.push_back({200,0,0,20});
        data_.Damage_spilt.Adjacent.push_back({200,0,0,20});
        data_.Damage_spilt.Other.push_back({200,0,0,20});
        Action_bar.push(data_);
        ++ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"];
        Abyss_Flower(ptr);
        Deal_damage();
    }
    void After_turn(Ally *ptr){
        if(turn->Char_Name=="Luocha"){
            if(Buff_end(ptr->Sub_Unit_ptr[0].get(),"Cycle_of_Life")){
                if(ptr->Eidolon>=1){
                    Buff_All_Ally("Atk%","None",-20);
                }
                ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"]=0;
            }
        }
    }
    void Start_game(Ally *ptr){
        if(ptr->Technique==1){
            ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"]=2;
            Abyss_Flower(ptr);
        }
    }
    void When_attack(Ally *ptr,Combat_data &data_){
        if(ptr->Sub_Unit_ptr[0]->Stack["Abyss_Flower"]>=2){
            HealRatio healRatio = HealRatio();
            HealRatio healRatioMain = HealRatio();
            
            healRatioMain.setRatio(18,0,0,240,0,0);
            healRatio.setRatio(7,0,0,93,0,0);

            Healing(healRatioMain,healRatio,ptr->Sub_Unit_ptr[0].get(),data_.Attacker);
        }
    }

    

    
}
#endif
