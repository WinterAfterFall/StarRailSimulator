
#ifndef Serval_H
#define Serval_H

#define F first
#define S second
#include "../Library.h"

namespace Serval{
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Reset(Ally *ptr);
    void Turn_func(Unit *ptr);

    void Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);

    void Ult_func(Ally *ptr);
    void Tune_stats(Ally *ptr);
    void Dot(Enemy* target,Ally *ptr,double Dot_ratio,string Dot_type);
    void After_turn(Ally *ptr);
    void When_attack(Ally *ptr,ActionData &data_);
    void Enemy_Death_func(Ally *ptr,Enemy *target,Sub_Unit *Killer);
    void Start_game(Ally *ptr);



//temp
    bool Use_Skill();
    
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally_unit[num] = make_unique<Ally>();
        SetBaseStats(Ally_unit[num]->Sub_Unit_ptr[0].get(),917,653,375);
        SetBasicStats(Ally_unit[num].get(),104,100,100,E,"Lightning","Erudition",num,"Serval","Ally");

        //substats
        Ally_unit[num]->Total_substats=20;
        Ally_unit[num]->Separate_sub=20;
        Ally_unit[num]->Reroll_check=1;

        Ally_unit[num]->Substats.push_back({"Crit_dam",20});
        Ally_unit[num]->Substats.push_back({"Crit_rate",0});
        Ally_unit[num]->Substats.push_back({"Atk%",0});

        Ally_unit[num]->Max_damage_Substats.resize(Ally_unit[num]->Substats.size());


        //func
        LC(Ally_unit[num].get());
        Relic(Ally_unit[num].get());
        Planar(Ally_unit[num].get());
        Ally_unit[num]->Sub_Unit_ptr[0]->Turn_func = Turn_func;
        void Turn_func(){
            auto ally_ptr = dynamic_cast<Sub_Unit*>(ptr);
            if(ptr->Atv_stats->turn_cnt%3!=1){
                Basic_Atk(ally_ptr->ptr_to_unit);
            }else{
                Skill(ally_ptr->ptr_to_unit);
            }
        }

        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Reset));
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK,Ally_unit[num].get(),Ult_func));
        After_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF,Ally_unit[num].get(),After_turn));
        Tune_stats_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Tune_stats));
        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK,Ally_unit[num].get(),Start_game));
        Dot_List.push_back(TriggerDot_Func(PRIORITY_BUFF,Ally_unit[num].get(),Dot));
        When_attack_List.push_back(TriggerByAction_Func(PRIORITY_ACTTACK,Ally_unit[num].get(),When_attack));
        Enemy_Death_List.push_back(TriggerBySomeAlly_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Enemy_Death_func));


        
    }
    void Reset(Ally *ptr){
        ptr->Sub_Unit_ptr[0]->Stats_type["Ehr"]["None"]+=18;
        ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"]+=18.7;


        //relic
        ptr->Sub_Unit_ptr[0]->Stats_type["Ehr"]["None"]+=43.2;
        ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed+=25;
        ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Lightning"]["None"]+=38.8;
        ptr->Energy_recharge +=19.4;

        //substats
        ptr->Sub_Unit_ptr[0]->Stats_type["Ehr"]["None"]+=ptr->Sub_effect_hit_rate_use;
        ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed+=ptr->Sub_Speed_use;


        
    }
    void Tune_stats(Ally *ptr){
        Cal_Speed_Needed(ptr,150);
        Cal_effect_hit_rate(ptr,100);

    }

    void Basic_Atk(Ally *ptr){
        Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num].get(),20);
        Skill_point(ptr->Sub_Unit_ptr[0].get(),1);
        ActionData data_ = ActionData();
        data_.Basic_Attack_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Serval BasicAttack");
        data_.Add_Target(chooseEnemyTarget(ptr->Sub_Unit_ptr[0].get()));
        if(Total_enemy>=2){
            if(ptr->Sub_Unit_ptr[0]->Enemy_target_num==1){
                data_.Add_Target(Enemy_unit[2].get());
            }else{
                data_.Add_Target(Enemy_unit[1].get());
            }
        }
        data_.Turn_reset=true;
        data_.Damage_spilt.Main.push_back({110,0,0,10});
        if(ptr->Eidolon>=1)data_.Damage_spilt.Adjacent.push_back({60,0,0,0});

        Action_bar.push(data_);
    }
    void Skill(Ally *ptr){
        Increase_energy(Ally_unit[ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_num].get(),30);
        Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
        ActionData data_ = ActionData();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Blast","Serval Skill");
        data_.Add_Target_Adjacent();
        data_.Turn_reset=true;
        data_.Damage_spilt.Main.push_back({154,0,0,20});
        data_.Damage_spilt.Adjacent.push_back({66,0,0,10});


        Action_bar.push(data_);
        for(int i=1;i<=Total_enemy;i++){
            if(!Debuff_check(Enemy_unit[i].get(),"Serval_Shock")){
                Enemy_unit[i]->Debuff["Serval_Shock"] = 1;
                Enemy_unit[i]->Debuff["Shock_check"]++;
                Enemy_unit[i]->Total_debuff++;
            }
            Apply_debuff(ptr->Sub_Unit_ptr[0].get(),Enemy_unit[i].get());
            Extend_Debuff_single_target(Enemy_unit[i].get(),"Serval_Shock",2);
        }
    }

    void Ult_func(Ally *ptr){
        if(!ultUseCheck(ptr))return;
            ActionData data_ = ActionData();
            data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(),"Aoe","Serval Ultimate");
            data_.Add_Target_Other();
            data_.Damage_spilt.Main.push_back({194,0,0,20});
            data_.Damage_spilt.Adjacent.push_back({194,0,0,20});
            data_.Damage_spilt.Other.push_back({194,0,0,20});
            Action_bar.push(data_);
            if(ptr->Eidolon<4)return;
            for(int i=1;i<=Total_enemy;i++){
            if(!Debuff_check(Enemy_unit[i].get(),"Serval_Shock")){
                Enemy_unit[i]->Debuff["Serval_Shock"] = 1;
                Enemy_unit[i]->Debuff["Shock_check"]++;
                Enemy_unit[i]->Total_debuff++;
            }
            Apply_debuff(ptr->Sub_Unit_ptr[0].get(),Enemy_unit[i].get());
            Extend_Debuff_single_target(Enemy_unit[i].get(),"Serval_Shock",2);
        }
        Deal_damage();
            
        }
    void Dot(Enemy* target,Ally *ptr,double Dot_ratio,string Dot_type){
        if(Dot_type!="None"&&Dot_type!="Lightning")return;
        if(!Debuff_check(target,"Serval_Shock"))return;
        ActionData data_ = ActionData();
        data_.Dot_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Serval Shock");
        data_.Damage_spilt.Main.push_back({114,0,0,0});
        Cal_Dot_damage(data_,target,Dot_ratio);
    }
    void After_turn(Ally *ptr){
        if(turn->Unit_Name=="Serval"){
            if(Buff_end(ptr->Sub_Unit_ptr[0].get(),"Serval_A6")){
                ptr->Sub_Unit_ptr[0]->Buff_check["Serval_A6"] = 0;
                ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"]-=20;
            }
        }
        if(turn->Side=="Enemy"){
            Enemy *tempstats = dynamic_cast<Enemy*>(turn->ptr_to_unit);
            if(tempstats){
                if(Debuff_end(tempstats,"Serval_Shock")){
                    tempstats->Debuff["Serval_Shock"] = 0;
                    tempstats->Debuff["Shock_check"]--;
                    tempstats->Total_debuff--;
                }
            }
        }
    }
    void When_attack(Ally *ptr,ActionData &data_){
        if(data_.Attacker->Atv_stats->Unit_Name!="Serval")return;
        ActionData data_temp = ActionData();
        data_temp.Additional_set(ptr->Sub_Unit_ptr[0].get(),"Single_target","Serval Additional Damage");
        for(int i=1;i<=Total_enemy;i++){
            if(Debuff_check(Enemy_unit[i].get(),"Serval_Shock")){
                Cal_Additional_damage(data_temp,Enemy_unit[i].get(),{79,0,0,0});
                if(ptr->Eidolon>=2){
                    Increase_energy(ptr,4);
                }
            }
        }
    }
    void Enemy_Death_func(Ally *ptr,Enemy *target,Sub_Unit *Killer){
        if(!Buff_check(ptr->Sub_Unit_ptr[0].get(),"Serval_A6")){
            ptr->Sub_Unit_ptr[0]->Buff_check["Serval_A6"] = 1;
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"]+=20;

        }
        Extend_Buff_single_target(ptr->Sub_Unit_ptr[0].get(),"Serval_A6",2);
    }
    void Start_game(Ally *ptr){
        Increase_energy(ptr,15);
        if(ptr->Eidolon>=6){
        ptr->Sub_Unit_ptr[0]->Stats_type["Dmg%"]["None"]+=30;
        }
    }
}
#endif