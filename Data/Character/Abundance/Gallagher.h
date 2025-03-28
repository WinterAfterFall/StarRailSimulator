
#ifndef Gallagher_H
#define Gallagher_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Gallagher{
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Reset(Ally *ptr);
    void Turn_func(Unit *ptr);
    void Basic_Atk(Ally *ptr);
    void Enchance_Basic_Atk(Ally *ptr);
    void Skill_func(Ally *ptr);
    void Ult_func(Ally *ptr);//*
    void Tune_stats(Ally *ptr);
    void After_turn(Ally *ptr);
    void Start_game(Ally *ptr);
    void When_Combat(Ally *ptr);
    void When_attack(Ally *ptr,ActionData &data_);


    
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally_unit[num] = make_unique<Ally>();

        Ally_unit[num]->Sub_Unit_ptr[0]->Base_hp = 1305;
        Ally_unit[num]->Sub_Unit_ptr[0]->Base_atk = 529;
        Ally_unit[num]->Sub_Unit_ptr[0]->Base_def = 441;
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Base_speed = 98;
        Ally_unit[num]->Max_energy = 110;
        Ally_unit[num]->Ult_cost = 110;
        Ally_unit[num]->Eidolon = E;
        Ally_unit[num]->Sub_Unit_ptr[0]->Element_type.push_back("Fire");
        Ally_unit[num]->Path.push_back("Abundance");
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Unit_num = num;
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Char_Name = "Gallagher";
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Unit_Name = "Gallagher";
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
        Tune_stats_List.push_back({PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Tune_stats});
        Start_game_List.push_back({PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Start_game});
        When_Combat_List.push_back({PRIORITY_IMMEDIATELY,Ally_unit[num].get(),When_Combat});
        When_attack_List.push_back(TriggerByAction_Func(PRIORITY_HEAL,Ally_unit[num].get(),When_attack));


        //substats
        Ally_unit[num]->Total_substats=20;
        Ally_unit[num]->Separate_sub=20;

        Ally_unit[num]->Substats.push_back({"Break_effect",20});

        Ally_unit[num]->Max_damage_Substats.resize(Ally_unit[num]->Substats.size());
        
    }
    void Reset(Ally *ptr){
        ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"]+=13.3;
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_PERCENT]["None"]+=18;
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_RES]["None"]+=18;

        //relic
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_HEALING]["None"]+=85.7;
        ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed+=25;
        ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"]+=43.2;
        ptr->Energy_recharge+=19.4;
        
        

        //substats
        ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed+=ptr->Sub_Speed_use;
        if(ptr->Eidolon>=6){
            ptr->Sub_Unit_ptr[0]->Stats_type["Weakness_Break_Efficiency"]["None"]+=20;
            ptr->Sub_Unit_ptr[0]->Stats_type["Break_effect"]["None"]+=20;

        }

    }
    void Tune_stats(Ally *ptr){
        Cal_Speed_Needed(ptr,150);
    }
    void Turn_func(Unit *ptr){
        auto ally_ptr = dynamic_cast<Sub_Unit*>(ptr);
        
        if(ptr->Atv_stats->turn_cnt%8==1){
            
            Skill_func(ally_ptr->ptr_to_unit);
        }else{
            
            if(ally_ptr->Buff_check["Gallagher_enchance_basic_atk"] ==1){
                Enchance_Basic_Atk(ally_ptr->ptr_to_unit);
            }else{
                Basic_Atk(ally_ptr->ptr_to_unit);
            }
        }
    }
    void Basic_Atk(Ally *ptr){
        Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
        Increase_energy(ptr,20);
        ActionData data_ = ActionData();
        data_.Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target");
        data_.Add_Target_Main();
        data_.Turn_reset = 1;
        data_.Damage_spilt.Main.push_back({55,0,0,5});
        data_.Damage_spilt.Main.push_back({55,0,0,5});
        Action_bar.push(data_);
    }
    void Enchance_Basic_Atk(Ally *ptr){
        Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
        Increase_energy(ptr,20);
        if(!Debuff_check(Enemy_unit[Main_Enemy_num].get(),"Nectar_Blitz")){
            Enemy_unit[Main_Enemy_num]->Debuff["Nectar_Blitz"] = 1;
            ++Enemy_unit[Main_Enemy_num]->Total_debuff;
            
        }
        Apply_debuff(ptr->Sub_Unit_ptr[0].get(),Enemy_unit[Main_Enemy_num].get());
        Extend_Debuff_single_target(Enemy_unit[Main_Enemy_num].get(),"Nectar_Blitz",2);
        
        ActionData data_ = ActionData();
        data_.Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target");
        data_.Add_Target_Main();
        data_.Turn_reset = 1;
        data_.Damage_spilt.Main.push_back({62.5,0,0,7.5});
        data_.Damage_spilt.Main.push_back({37.5,0,0,4.5});
        data_.Damage_spilt.Main.push_back({150,0,0,18});
        Action_bar.push(data_);
        

    }
    void Skill_func(Ally *ptr){

        Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
        Increase_energy(ptr,30);
        ActionData data_ = ActionData();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Heal");
        data_.Add_Buff_Single_Target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()));
        data_.resetTurn();
        data_.createHealRatio();
        data_.healPtr->setHealer(ptr->Sub_Unit_ptr[0].get());
        data_.healPtr->main.setRatio(0,0,0,1768,0,0);
        Action_bar.push(data_);
    }
    void Ult_func(Ally *ptr){
        if(Ult_After_Turn==0||ptr->Sub_Unit_ptr[0]->Atv_stats->atv==0||!ultUseCheck(ptr))return;
        Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(),100);
        ptr->Sub_Unit_ptr[0]->Buff_check["Gallagher_enchance_basic_atk"] = 1;
        Debuff_All_Enemy_Apply_ver(ptr->Sub_Unit_ptr[0].get(),"Vul","Break_dmg",13.2,"Besotted");
        if(ptr->Eidolon>=4){
            Extend_Debuff_All_Enemy("Besotted",3);
        }else{
            Extend_Debuff_All_Enemy("Besotted",2);
        }

        ActionData data_ = ActionData();
        data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(),"Aoe");
        data_.Add_Target_Other();
        data_.Damage_spilt.Main.push_back({165,0,0,20});
        data_.Damage_spilt.Adjacent.push_back({165,0,0,20});
        data_.Damage_spilt.Other.push_back({165,0,0,20});
        Action_bar.push(data_);
        if(ptr->Print)Char_Command::printUltStart(ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name);
        Deal_damage();
        

    }
    void After_turn(Ally *ptr){
        if(turn->Side =="Enemy"){
            if(Debuff_end(Enemy_unit[turn->Unit_num].get(),"Besotted")){
                Debuff_single_target(Enemy_unit[turn->Unit_num].get(),"Vul","Break_dmg",-13.2);
                Enemy_unit[turn->Unit_num]->Debuff["Besotted"]=0;
                --Enemy_unit[turn->Unit_num]->Total_debuff;
            }
            if(Debuff_end(Enemy_unit[turn->Unit_num].get(),"Nectar_Blitz")){
                --Enemy_unit[turn->Unit_num]->Total_debuff;
                Enemy_unit[Main_Enemy_num]->Debuff["Nectar_Blitz"] = 0;
            }
        }
    }
    void Start_game(Ally *ptr){
        if(ptr->Eidolon>=1){
            Increase_energy(ptr,20);
        }
    }
    void When_Combat(Ally *ptr){
        if(ptr->Technique){
            ActionData data_ = ActionData();
            data_.Technique_set(ptr->Sub_Unit_ptr[0].get(),"Aoe");
            data_.Damage_spilt.Main.push_back({50,0,0,20});
            data_.Damage_spilt.Adjacent.push_back({50,0,0,20});
            data_.Damage_spilt.Other.push_back({50,0,0,20});
            Action_bar.push(data_);
            Extend_Debuff_All_Enemy("Besotted",2);
            Debuff_All_Enemy_Apply_ver(ptr->Sub_Unit_ptr[0].get(),"Vul","Break_dmg",13.2,"Besotted");
            if(!actionBarUse)Deal_damage();
        }
        
    }
    void When_attack(Ally *ptr,ActionData &data_){
        Heal_data healData = Heal_data();
        healData.setHealer(ptr->Sub_Unit_ptr[0].get());
        healData.main.setRatio(0,0,0,707,0,0);

        if(data_.Action_type.second==AT_BASIC_ATK&&data_.Attacker->Atv_stats->Unit_Name=="Gallagher"&&data_.Attacker->Buff_check["Gallagher_enchance_basic_atk"]==1){
            ptr->Sub_Unit_ptr[0]->Buff_check["Gallagher_enchance_basic_atk"] =0;
            
            for(Enemy* e:data_.Target_Attack){
                if(Debuff_check(e,"Besotted")){
                    healData.adjacent.setRatio(0,0,0,707,0,0);
                    healData.other.setRatio(0,0,0,707,0,0);
                    Healing(healData);
                }
            }
        }else{
            for(Enemy* e:data_.Target_Attack){
                if(Debuff_check(e,"Besotted")){
                    Healing(healData.main,ptr->Sub_Unit_ptr[0].get(),data_.Attacker);
                }
            }
        }
    }
}
#endif
