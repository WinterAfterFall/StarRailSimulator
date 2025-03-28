
#ifndef Tingyun_H
#define Tingyun_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Tingyun{
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Reset(Ally *ptr);
    void Turn_func(Unit *ptr);
    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);
    void Ult_func(Ally *ptr);//*
    void Before_turn(Ally *ptr);
    void After_turn(Ally *ptr);
    void When_Attack(Ally *ptr, ActionData &data_);
    void Start_game(Ally *ptr);
    
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally_unit[num] = make_unique<Ally>();

        Ally_unit[num]->Sub_Unit_ptr[0]->Base_hp = 847;
        Ally_unit[num]->Sub_Unit_ptr[0]->Base_atk = 529;
        Ally_unit[num]->Sub_Unit_ptr[0]->Base_def = 397;
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Base_speed = 112;
        Ally_unit[num]->Max_energy = 130;
        Ally_unit[num]->Ult_cost = 130;
        Ally_unit[num]->Eidolon = E;
        Ally_unit[num]->Sub_Unit_ptr[0]->Element_type.push_back("Lightning");
        Ally_unit[num]->Path.push_back("Harmony");
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Unit_num = num;
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Char_Name = "Tingyun";
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Unit_Name = "Tingyun";
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->Side = "Ally";
        Ally_unit[num]->Sub_Unit_ptr[0]->Atv_stats->ptr_to_unit = Ally_unit[num]->Sub_Unit_ptr[0].get();
        Ally_unit[num]->Technique = 2;

        //func
        LC(Ally_unit[num].get());
        Relic(Ally_unit[num].get());
        Planar(Ally_unit[num].get());
        
        Ally_unit[num]->Sub_Unit_ptr[0]->Turn_func = Turn_func;
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF,Ally_unit[num].get(),Ult_func));
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Reset));
        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Before_turn));
        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF,Ally_unit[num].get(),After_turn));
        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Start_game));
        When_attack_List.push_back(TriggerByAction_Func(PRIORITY_ACTTACK,Ally_unit[num].get(),When_Attack));



    }
    void Reset(Ally *ptr){
        ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Lightning"]["None"]+=8;
        ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"]+=28;
        ptr->Sub_Unit_ptr[0]->Stats_type["Def%"]["None"]+=22.5;


        //relic
        ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"]+=43.2;
        ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed+=25;
        ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"]+=43.2;
        ptr->Energy_recharge+=19.4;

        //substats
        ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"]+=77.76;
        ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Basic_Attack"]+=40;
    }
    void Turn_func(Unit *ptr){
        auto ally_ptr = dynamic_cast<Sub_Unit*>(ptr);
        if(chooseSubUnitBuff(ally_ptr)->Buff_check["Benediction"] ==0){
            Skill(ally_ptr->ptr_to_unit);
        }else{
            Basic_Atk(ally_ptr->ptr_to_unit);
        }
    }
    void Skill(Ally *ptr){
        if(ptr->Print){
            cout<<"-----------------------tingyun skill at "<<Current_atv<<endl;
        }
        Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
        Increase_energy(ptr,30);
        ActionData data_ = ActionData();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Buff");
        data_.Add_Buff_Single_Target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()));
        data_.Turn_reset = 1;
        Action_bar.push(data_);
        if(!Buff_check(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),"Benediction")){
            Buff_single_target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),"Atk%","None",55);
            chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Buff_check["Benediction"] = 1;
        }
        Extend_Buff_single_target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),"Benediction",3);
    }
    void Basic_Atk(Ally *ptr){
        ActionData data_ = ActionData();
        Increase_energy(ptr,20);
        Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
        data_.Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target");
        data_.Add_Target(chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()));
        data_.Turn_reset = 1;
        data_.Damage_spilt.Main.push_back({33,0,0,3});
        data_.Damage_spilt.Main.push_back({77,0,0,7});
        Action_bar.push(data_);
    }
    void Ult_func(Ally *ptr){
        if(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Max_energy - Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Current_energy<=30)return ;

        if(!ultUseCheck(ptr))return;
        ActionData data_ = ActionData();
        data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Buff");
        data_.Add_Buff_Single_Target(ptr->Sub_Unit_ptr[0].get());
        Action_bar.push(data_);

        Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum].get(),0,50);
        if(ptr->Eidolon>=6){
            Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum].get(),0,10);
        }
        if(ptr->Eidolon>=1){
            Speed_Buff(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats.get(),20,0);
            Extend_Buff_single_target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),"Windfall_of_Lucky_Springs",1);
            }
        if(Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Sub_Unit_ptr[0]->Buff_check["Rejoicing_Clouds"]==0){
            Buff_single_target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),"Dmg%","None",56);
            chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Buff_check["Rejoicing_Clouds"] = 1;
        }
        if(turn->Char_Name==Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Sub_Unit_ptr[0]->Atv_stats->Char_Name&&Ult_After_Turn==0){
            Extend_Buff_single_target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),"Rejoicing_Clouds",1);
        }else{
            Extend_Buff_single_target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),"Rejoicing_Clouds",2);
        }
        

        Deal_damage();
    }
    void Before_turn(Ally *ptr){
        if(turn->Char_Name!="Tingyun")return;
        Increase_energy(ptr,5);
    }
    void After_turn(Ally *ptr){
        Sub_Unit* tempUnit = isSubUnitCheck();
        if(!tempUnit)return;
        if(turn->Char_Name=="Tingyun"){
            if(Buff_end(ptr->Sub_Unit_ptr[0].get(),"Nourished_Joviality")){
            Speed_Buff(ptr->Sub_Unit_ptr[0]->Atv_stats.get(),-20,0);
        }
        }
        if(Buff_end(tempUnit,"Benediction")){
            tempUnit->Buff_check["Benediction"] = 0;
            Buff_single_target(tempUnit,"Atk%","None",-55);
        
        }
        
        if(Buff_end(tempUnit,"Windfall_of_Lucky_Springs")){
             Speed_Buff(tempUnit->Atv_stats.get(),-20,0);
        }
        
        if(Buff_end(tempUnit,"Rejoicing_Clouds")){
            Buff_single_target(tempUnit,"Dmg%","None",-56);
            tempUnit->Buff_check["Rejoicing_Clouds"] = 0;
        }
    }
    void When_Attack(Ally *ptr, ActionData &data_){
        Sub_Unit* tempUnit = data_.Attacker;
        if(!tempUnit)return;
        if(Buff_check(tempUnit,"Benediction")){
        if(data_.Attacker->Atv_stats->Unit_Name == ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name){
                ActionData temp = ActionData();
                temp.Additional_set(ptr->Sub_Unit_ptr[0].get(),"Single_target");
                Cal_Additional_damage(temp,Enemy_unit[Main_Enemy_num].get(),{66,0,0,0});
                
        }else if(data_.Attacker->Atv_stats->Unit_Name == Ally_unit[ptr->Sub_Unit_ptr[0]->allyTargetNum]->Sub_Unit_ptr[ptr->Sub_Unit_ptr[0]->Sub_Unit_num]->Atv_stats->Unit_Name){
                ActionData temp = ActionData();
                temp.Additional_set(tempUnit,"Single_target");
        
                if(ptr->Eidolon>=4){
                    Cal_Additional_damage(temp,Enemy_unit[Main_Enemy_num].get(),{64,0,0,0});
                }else{
                    Cal_Additional_damage(temp,Enemy_unit[Main_Enemy_num].get(),{44,0,0,0});
                }
        }
        }
        if(data_.Action_type.second=="Skill"&&data_.Attacker->Atv_stats->Char_Name=="Tingyun"){
            Speed_Buff(ptr->Sub_Unit_ptr[0]->Atv_stats.get(),-20,0);
            Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Nourished_Joviality",1);

        }
    }
    void Start_game(Ally *ptr){
        Increase_energy(ptr,0,50*ptr->Technique);
    }
    

    

    
}
#endif
