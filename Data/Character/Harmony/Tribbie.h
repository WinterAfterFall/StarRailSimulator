
#ifndef Tribbie_H
#define Tribbie_H

#define F first
#define S second
#include "../Library.h"

namespace Tribbie{
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Reset(Ally *ptr);
    void Turn_func(Unit *ptr);
    void Before_turn(Ally *ptr);
    void After_turn(Ally *ptr);
    void Ult_func(Ally *ptr);
    void Tune_stats(Ally *ptr);    
    void Start_game(Ally *ptr);
    void Print_Stats(Ally *ptr);
    void When_attack(Ally *ptr,Combat_data &data_);
    void Stats_Adjust(Ally *ptr,Sub_Unit *target, string StatsType);
    



//temp
    void Skill(Ally *ptr);
    void Basic_Atk(Ally *ptr);

    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally_unit[num] = make_unique<Ally>();
        SetBaseStats(Ally_unit[num]->Sub_Unit_ptr[0].get(),1048,524,728);
        SetBasicStats(Ally_unit[num].get(),96,120,120,E,"Quantum","Harmony",num,"Tribbie","Ally");
        //substats
        Ally_unit[num]->Total_substats=20;
        Ally_unit[num]->Separate_sub=20;
        Ally_unit[num]->Reroll_check=1;

        Ally_unit[num]->Substats.push_back({"Crit_dam",20});
        Ally_unit[num]->Substats.push_back({"Crit_rate",0});
        Ally_unit[num]->Substats.push_back({"Hp%",0});

        Ally_unit[num]->Max_damage_Substats.resize(Ally_unit[num]->Substats.size());


        //func
        LC(Ally_unit[num].get());
        Relic(Ally_unit[num].get());
        Planar(Ally_unit[num].get());
        Ally_unit[num]->Sub_Unit_ptr[0]->Turn_func = Turn_func;
        Ally_unit[num]->Char.Print_Func = Print_Stats;
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF,Ally_unit[num].get(),Ult_func));
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Reset));
        Tune_stats_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Tune_stats));
        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Before_turn));
        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),After_turn));
        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Start_game));
        When_attack_List.push_back(TriggerByAction_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),When_attack));
        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Stats_Adjust));
        




        Ally_unit[num]->SetRelic(0,0,0,1);
        // Ally_unit[num]->Speed_tune_value =133.4;
        








    }
    void Reset(Ally *ptr){
        ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"]+=37.3;
        ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"]+=12;
        ptr->Sub_Unit_ptr[0]->Stats_type["Hp%"]["None"]+=10;



        //relic
        
        if(ptr->Body_CritDam){
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"]+=64.8;
        }else{
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"]+=32.4;
        }

        if(ptr->Speed_Boot){
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed+=25;
        }else{
            ptr->Sub_Unit_ptr[0]->Stats_type["Hp%"]["None"]+=43.2;
        }
        if(ptr->Element_Orb){
            ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Quantum"]["None"]+=38.8;
        }else{
            ptr->Sub_Unit_ptr[0]->Stats_type["Hp%"]["None"]+=43.2;
        }
        if(ptr->Er_Rope){
            ptr->Energy_recharge += 19.4;
        }else{
            ptr->Sub_Unit_ptr[0]->Stats_type["Hp%"]["None"]+=43.2;
        }
        
        


        //substats
        ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed+=ptr->Sub_Speed_use;
        if(ptr->Eidolon>=6){
            ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["Fua"]+=729;
        }


        //countdown 

        
    }
    void Tune_stats(Ally *ptr){
        Cal_Speed_Needed(ptr,ptr->Speed_tune_value);
    }
    void Turn_func(Unit *ptr){
        auto ally_ptr = dynamic_cast<Sub_Unit*>(ptr);
        if(Buff_check(ally_ptr,"Numinosity")){
            Basic_Atk(ally_ptr->ptr_to_unit);
        }else{
            Skill(ally_ptr->ptr_to_unit);
        }
    }
    void Basic_Atk(Ally *ptr){
        Increase_energy(ptr,20);
        Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
        Combat_data data_ = Combat_data();
        data_.Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Blast");
        data_.Add_Target_Adjacent();
        data_.Turn_reset=true;
        data_.Damage_spilt.Main.push_back({0,30,0,10});
        data_.Damage_spilt.Adjacent.push_back({0,15,0,5});

        Action_bar.push(data_);
    }
    
    void Skill(Ally *ptr){
        Increase_energy(ptr,30);
        Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
        Combat_data data_ = Combat_data();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Aoe","Buff");
        data_.Add_Buff_All_Ally();
        data_.Turn_reset=true;
        Buff_All_Ally("Respen","None",24);
        Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Numinosity",3);
        ptr->Sub_Unit_ptr[0]->Buff_check["Numinosity"] = 1;

        
        
        Action_bar.push(data_);
    }

    void Ult_func(Ally *ptr){
        if(ptr->Light_cone.Name=="DDD"&&chooseSubUnitBuff(ptr->Sub_Unit_ptr[0].get())->Atv_stats->atv<=0)return;
        if(ptr->Light_cone.Name=="DDD"&&Driver_num!=0&&Ally_unit[Driver_num]->Sub_Unit_ptr[0]->Atv_stats->atv<=0)return;
        if(ptr->Light_cone.Name=="Eagle_Beaked_Helmet"&&ptr->Sub_Unit_ptr[0]->Atv_stats->atv<=0)return;

        if(!ultUseCheck(ptr))return;
            Combat_data data_ = Combat_data();
            data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(),"Aoe");
            data_.Add_Target_Other();
            data_.Damage_spilt.Main.push_back({0,30,0,20});
            data_.Damage_spilt.Adjacent.push_back({0,30,0,20});
            data_.Damage_spilt.Other.push_back({0,30,0,20});
            if(!Buff_check(ptr->Sub_Unit_ptr[0].get(),"Tribbie_Zone")){
                Buff_All_Ally("Vul","None",30);
                ptr->Sub_Unit_ptr[0]->Buff_check["Tribbie_Zone"] = 1;

                //A4 Trace
                ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"] = 0;
                for(int i=1;i<=Total_ally;i++){
                    ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]+=calculateHpForBuff(Ally_unit[i]->Sub_Unit_ptr[0].get(),9);  
                }
                Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Flat_Hp","None",ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]);
                Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Flat_Hp",AT_TEMP,ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]);
                
                //Eidolon 1
                if(ptr->Eidolon>=1){
                Buff_All_Ally("True_Damage","None",24);
                }
            }
            
            for(int i=1;i<=Total_ally;i++){
                if(i==ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num)continue;
                Ally_unit[i]->Sub_Unit_ptr[0]->Buff_check["Tribbie_ult_launch"] = 0;
            }
            
            Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Tribbie_Zone",2);
            Action_bar.push(data_);
            if(ptr->Print)cout<<"---------------------------------------------------- Tribbie Ult at "<<Current_atv<<endl;
            if(ptr->Eidolon>=6){
            Combat_data data_2 = Combat_data();
            data_2.Fua_set(ptr->Sub_Unit_ptr[0].get(),"Aoe");
            data_2.Add_Target_Other();
            Increase_energy(ptr,5);
            
            data_2.Damage_spilt.Main.push_back({0,18,0,5});
            data_2.Damage_spilt.Adjacent.push_back({0,18,0,5});
            data_2.Damage_spilt.Other.push_back({0,18,0,5});
            Action_bar.push(data_2);
            
            }
            if(!actionBarUse)Deal_damage();      
    }
    void Before_turn(Ally *ptr){
        
        if(Buff_end(ptr->Sub_Unit_ptr[0].get(),"Tribbie_Zone")){
            Buff_All_Ally("Vul","None",-30);
            ptr->Sub_Unit_ptr[0]->Buff_check["Tribbie_Zone"] = 0;
            if(ptr->Eidolon>=1){
                Buff_All_Ally("True_Damage","None",-24);
            }
            Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Flat_Hp","None",-ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]);
            Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Flat_Hp",AT_TEMP,-ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]);

            ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"] = 0;
            if(ptr->Print)cout<<"---------------------------------------------------- Tribbie Ult END at "<<Current_atv<<endl;
        }
        if(Buff_end(ptr->Sub_Unit_ptr[0].get(),"Numinosity")){
            Buff_All_Ally("Respen","None",-24);
            ptr->Sub_Unit_ptr[0]->Buff_check["Numinosity"] = 0;
        }
        
    }
    void Stats_Adjust(Ally *ptr,Sub_Unit *target, string StatsType){
        if(Buff_check(ptr->Sub_Unit_ptr[0].get(),"Tribbie_Zone"))return;
        if(StatsType=="Hp%"|| StatsType == "Flat_Hp"){
            //before TYPE_TEMP
            Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Flat_Hp","None",-ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]);
            Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Flat_Hp",AT_TEMP,-ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]);

            //adjust
            ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"] = 0;
                    for(int i=1;i<=Total_ally;i++){
                        ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]+=calculateHpForBuff(Ally_unit[i]->Sub_Unit_ptr[0].get(),9);  
                    }
                    
            //after
            Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Flat_Hp","None",ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]);
            Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Flat_Hp",AT_TEMP,ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]);
                            
            
            return;
        }
    }

    void When_attack(Ally *ptr,Combat_data &data_){
        
        int temp = data_.Target_Attack.size();
        if(data_.Attacker->Atv_stats->Char_Name=="Tribbie"&&data_.Action_type.second=="Fua"){
            Stack_Buff_single_target(data_.Attacker,"Dmg%","None",72,1,3,"Tribbie_A2");
            Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Tribbie_A2",3);
        }
        Increase_energy(ptr,(1.5)*temp);
        if(Buff_check(ptr->Sub_Unit_ptr[0].get(),"Tribbie_Zone")){
            Combat_data data_1 = Combat_data();
            data_1.Additional_set(ptr->Sub_Unit_ptr[0].get(),"Single_target");
            if(ptr->Eidolon>=2){
                Cal_Additional_damage(data_1,chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()),{0,(14.4)*(temp+1),0,0});
            }else{
                Cal_Additional_damage(data_1,chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()),{0,(12.0)*temp,0,0});
            }
            

        }
        if(data_.Action_type.second=="Ultimate"&&Buff_check(data_.Attacker,"Tribbie_ult_launch")==0&&data_.Attacker->Atv_stats->Char_Name!="Tribbie"&&data_.Attacker->Atv_stats->Side=="Ally"){
            data_.Attacker->Buff_check["Tribbie_ult_launch"]=1;
            Combat_data data_2 = Combat_data();
            data_2.Fua_set(ptr->Sub_Unit_ptr[0].get(),"Aoe");
            data_2.Add_Target_Other();
            Increase_energy(ptr,5);
            
            data_2.Damage_spilt.Main.push_back({0,18,0,5});
            data_2.Damage_spilt.Adjacent.push_back({0,18,0,5});
            data_2.Damage_spilt.Other.push_back({0,18,0,5});
            Action_bar.push(data_2);
            if(!actionBarUse)Deal_damage();
        }
        
    }
    void After_turn(Ally *ptr){
        
        if(Buff_end(ptr->Sub_Unit_ptr[0].get(),"Tribbie_A2")){
            Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Dmg%","None",-ptr->Sub_Unit_ptr[0]->Stack["Tribbie_A2"]*72);
            ptr->Sub_Unit_ptr[0]->Stack["Tribbie_A2"] = 0;
        }
    }
    void Start_game(Ally *ptr){
        Increase_energy(ptr,30);
        Buff_All_Ally("Respen","None",24);
        Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Numinosity",3);
        ptr->Sub_Unit_ptr[0]->Buff_check["Numinosity"] = 1;
    }
    void Print_Stats(Ally *ptr){
        cout<<endl;
        cout<<"Tribbie : ";
        cout<<ptr->Sub_Unit_ptr[0]->Buff_check["Numinosity"]<<" ";
        cout<<ptr->Sub_Unit_ptr[0]->Buff_check["Tribbie_Zone"]<<" ";
        cout<<ptr->Sub_Unit_ptr[0]->Stack["Tribbie_A2"]<<" ";
        cout<<ptr->Sub_Unit_ptr[0]->Buff_note["Tribbie_A4"]<<" ";
        for(int i=1;i<=Total_ally;i++){
                if(i==ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num)continue;
                cout<<Ally_unit[i]->Sub_Unit_ptr[0]->Buff_check["Tribbie_ult_launch"]<<" ";
            }

    }

}
#endif