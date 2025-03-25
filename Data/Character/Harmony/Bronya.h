
#ifndef Bronya_H
#define Bronya_H

#define F first
#define S second
#include "../Library.h"

namespace Bronya{
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Reset(Ally *ptr);
    void Turn_func(Unit *ptr);
    void Before_turn(Ally *ptr);
    void After_turn(Ally *ptr);
    void After_attack(Ally *ptr,Combat_data &data_);
    void Ult_func(Ally *ptr);
    void Tune_stats(Ally *ptr);    
    void Start_game(Ally *ptr);
    void When_Combat(Ally *ptr);



//temp
    void Skill(Ally *ptr);

    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally_unit[num] = make_unique<Ally>();
        SetBaseStats(Ally_unit[num]->Sub_Unit_ptr[0].get(),1242,582,534);
        SetBasicStats(Ally_unit[num].get(),99,120,120,E,"Wind","Harmony",num,"Bronya","Ally");
        //substats
        Ally_unit[num]->Total_substats=20;
        Ally_unit[num]->Separate_sub=20;

        Ally_unit[num]->Substats.push_back({"Crit_dam",20});

        Ally_unit[num]->Max_damage_Substats.resize(Ally_unit[num]->Substats.size());


        //func
        LC(Ally_unit[num].get());
        Relic(Ally_unit[num].get());
        Planar(Ally_unit[num].get());
        Ally_unit[num]->Sub_Unit_ptr[0]->Turn_func = Turn_func;
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF,Ally_unit[num].get(),Ult_func));
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Reset));
        Tune_stats_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Tune_stats));
        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Start_game));
        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),After_turn));
        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Before_turn));
        When_Combat_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),When_Combat));
        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),After_attack));





        Ally_unit[num]->Er_Rope =1;
        Ally_unit[num]->Body_CritDam =1;
        Ally_unit[num]->Element_Orb =0;
        Ally_unit[num]->Speed_tune_value =133.4;
        








    }
    void Reset(Ally *ptr){
        ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"]+=24;
        ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Wind"]["None"]+=22.4;



        //relic
        
        ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"]+=64.8;
        
        if(ptr->Speed_Boot){
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed+=25;
        }else{
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"]+=43.2;
        }
        if(ptr->Element_Orb){
            ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Lightning"]["None"]+=38.8;
        }else{
            ptr->Sub_Unit_ptr[0]->Stats_type["Hp%"]["None"]+=43.2;
        }
        ptr->Energy_recharge += 19.4;
        


        //substats
        ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed+=ptr->Sub_Speed_use;
        ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["Basic_Attack"]=100;


        //countdown 

        
    }
    void Tune_stats(Ally *ptr){
        Cal_Speed_Needed(ptr,ptr->Speed_tune_value);
    }
    void Turn_func(Unit *ptr){
        auto ally_ptr = dynamic_cast<Sub_Unit*>(ptr);
        
        Skill(ally_ptr->ptr_to_unit);
        
    }
    
    void Skill(Ally *ptr){
        Increase_energy(ptr,30);
        Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
        Combat_data data_ = Combat_data();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Buff");
        data_.Add_Buff_Single_Target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()));
        data_.Turn_reset=true;
        Action_forward(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats.get(),100);
        if(!Buff_check(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),"Bronya_Skill")){
            chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Buff_check["Bronya_Skill"] = 1;
            Buff_single_target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),"Dmg%","None",66);
        }
        if(ptr->Eidolon>=6){
            Extend_Buff_single_target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),"Bronya_Skill",2);
        }else{
            Extend_Buff_single_target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),"Bronya_Skill",1);
        }
        if(ptr->Eidolon>=2){
            if(!Buff_check(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),"Bronya_Skill_E2")){
                Speed_Buff(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats.get(),30,0);
                chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Buff_check["Bronya_Skill_E2"] = 1;

            }
            Extend_Buff_single_target(chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get()),"Bronya_Skill_E2",2);
        }
        if(ptr->Eidolon>=1){
            if(ptr->Sub_Unit_ptr[0]->Stack["Bronya_Skill_E1"]==1&&ptr->Sub_Unit_ptr[0]->Buff_check["Bronya_Skill_E1"]==0){
                Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
                Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Bronya_Skill_E1",1);
                ptr->Sub_Unit_ptr[0]->Buff_check["Bronya_Skill_E1"]=1;

            }
            ptr->Sub_Unit_ptr[0]->Stack["Bronya_Skill_E1"]++;
        }
        
        Action_bar.push(data_);
    }

    void Ult_func(Ally *ptr){
        if(!ultUseCheck(ptr))return;
            Combat_data data_ = Combat_data();
            data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(),"Aoe","Buff");
            data_.Add_Buff_All_Ally();
            for(auto e:data_.Target_Buff){
                Extend_Buff_single_target(e,"Bronya_Ult",2);
                Buff_single_target(e,"Crit_dam","None",-e->Buff_note["Bronya_Ult"]);
                Buff_single_target(e,"Crit_dam",AT_TEMP,-e->Buff_note["Bronya_Ult"]);
                e->Buff_note["Bronya_Ult"] = calculateCritdamForBuff(ptr->Sub_Unit_ptr[0].get(),16)+20;
                Buff_single_target(e,"Crit_dam","None",e->Buff_note["Bronya_Ult"]);
                Buff_single_target(e,"Crit_dam",AT_TEMP,e->Buff_note["Bronya_Ult"]);
                if(e->Buff_check["Bronya_Ult"])continue;
                e->Buff_check["Bronya_Ult"] = 1;
                Buff_single_target(e,"Atk%","None",55);
            }
            if(Ult_After_Turn==0&&(turn->Side=="Memosprite"||turn->Side=="Ally")){
                Sub_Unit *temp = dynamic_cast<Sub_Unit*>(turn->ptr_to_unit);
                Extend_Buff_single_target(temp,"Bronya_Ult",1);
            }
            Action_bar.push(data_);
            if(ptr->Print)cout<<"---------------------------------------------------- Bronya Ult at "<<Current_atv<<endl;

            Deal_damage();        
    }
    void After_attack(Ally *ptr,Combat_data &data_){
        if(data_.Action_type.second=="Basic_Attack"&&data_.Attacker->Atv_stats->Char_Name=="Bronya"){
            Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(),30);
        }
        if(ptr->Eidolon>=4&&data_.Action_type.second=="Basic_Attack"&&data_.Attacker->Atv_stats->Char_Name!="Bronya"&&ptr->Sub_Unit_ptr[0]->Buff_check["Bronya_E4"]==0){
            Combat_data data_temp = Combat_data();
            data_temp.Fua_set(ptr->Sub_Unit_ptr[0].get(),"Single_target");
            data_temp.Add_Target(chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()));
            data_temp.Damage_spilt.Main.push_back({80,0,0,10});
            Increase_energy(ptr,5);
            ptr->Sub_Unit_ptr[0]->Buff_check["Bronya_E4"] =1;
            Action_bar.push(data_temp);
        }
    }
    void Before_turn(Ally *ptr){
        if(turn->Char_Name=="Bronya"){
            ptr->Sub_Unit_ptr[0]->Buff_check["Bronya_E4"] =0;
        }
        if(ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num!=Driver_num)return;
        if( (Aglaea_num!=0&&Ally_unit[Aglaea_num]->Countdown_ptr[0]->Atv_stats->Base_speed>0)||Ally_unit[Aglaea_num]->Sub_Unit_ptr[1]->Atv_stats->Base_speed<=0){
            Char_Command::Set_Target_Buff(ptr->Sub_Unit_ptr[0].get(),Aglaea_num,0);
        }else{
            Char_Command::Set_Target_Buff(ptr->Sub_Unit_ptr[0].get(),Aglaea_num,1);
        }
    }
    void After_turn(Ally *ptr){
        Sub_Unit *tempstats = dynamic_cast<Sub_Unit*>(turn->ptr_to_unit);
        if(!tempstats)return;
        if(Buff_end(tempstats,"Bronya_Skill")){
            tempstats->Buff_check["Bronya_Skill"] = 0;
            Buff_single_target(tempstats,"Dmg%","None",-66);
        }
        if(Buff_end(ptr->Sub_Unit_ptr[0].get(),"Bronya_Skill_E1")){
            ptr->Sub_Unit_ptr[0]->Buff_check["Bronya_Skill_E1"]=0;
            ptr->Sub_Unit_ptr[0]->Stack["Bronya_Skill_E1"]=0;
        }
        if(Buff_end(tempstats,"Bronya_Skill_E2")){
            Speed_Buff(tempstats->Atv_stats.get(),-30,0);
            chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Buff_check["Bronya_Skill_E2"] = 0;
            
        }
        
        if(Buff_end(tempstats,"Bronya_Ult")){
            Buff_single_target(tempstats,"Atk%","None",-55);
            Buff_single_target(tempstats,"Crit_dam","None",-tempstats->Buff_note["Bronya_Ult"]);
            Buff_single_target(tempstats,"Crit_dam",AT_TEMP,-tempstats->Buff_note["Bronya_Ult"]);
            tempstats->Buff_note["Bronya_Ult"] = 0;
            tempstats->Buff_check["Bronya_Ult"] = 0;
        }
        if(Buff_end(tempstats,"Bronya_A4")){
            Buff_single_target(tempstats,"Def%","None",-20);
        }
        if(Buff_end(tempstats,"Bronya_Technique")){
            Buff_single_target(tempstats,"Atk%","None",-15);
        }
        
    }
    void Start_game(Ally *ptr){
        if(ptr->Technique==1){
            Buff_All_Ally("Atk%","None",15);
            Extend_Buff_All_Ally("Bronya_Technique",2);
        }
        Buff_All_Ally("Def%","None",20);
        Extend_Buff_All_Ally("Bronya_A4",2);

    }
    void When_Combat(Ally *ptr){
        Buff_All_Ally("Dmg%","None",10);
        
    }
}
#endif