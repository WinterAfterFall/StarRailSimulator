#ifndef Name_H
#define Name_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Template_name{
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Reset(Ally *ptr);
    void Turn_func(Unit *ptr);
    void Basic_Atk(Ally *ptr);
    void Enchance_Basic_Atk(Ally *ptr);
    void Skill(Ally *ptr);
    void Enchance_Skill(Ally *ptr);
    void Ult_func(Ally *ptr);//*
    void Tune_stats(Ally *ptr);
    void Setup_Memo(Ally *ptr);
    
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally_unit[num] = make_unique<Ally>();
        SetBaseStats(Ally_unit[num]->Sub_Unit_ptr[0].get(),1000,423,400);
        SetBasicStats(Ally_unit[num].get(),102,350,350,E,"Element","Path",num,"Name","Ally");

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
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF,Ally_unit[num].get(),Ult_func));
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Reset));
        Tune_stats_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Tune_stats));
        Setup_Memo_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Setup_Memo));



        Ally_unit[num]->SetRelic(0,1,1,1);
        Ally_unit[num]->Speed_tune_value = 135;
        Aglaea_num = num;



        SetMemoStats(Ally_unit[num].get(),66,35,"Lightning","MemName","Memosprite");
        SetCountdownStats(Ally_unit[num].get(),"Name");
        // Ally_unit[num]->Sub_Unit_ptr[1]->Turn_func = Mem_turn;
        // Ally_unit[num]->Countdown_ptr[0]->Turn_func = CountDown_turn;

    }

    void Reset(Ally *ptr){
        ptr->Sub_Unit_ptr[0]->Stats_type["Def%"]["None"]+=12.5;
        ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"]+=12;
        ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Lightning"]["None"]+=22.4;



        //relic
        if(ptr->Body_CritDam){
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"]+=64.8;
        }else{
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_rate"]["None"]+=32.4;
        }
        if(ptr->Speed_Boot){
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed+=25;
        }else{
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"]+=43.2;
        }
        if(ptr->Element_Orb){
            ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Lightning"]["None"]+=38.8;
        }else{
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"]+=43.2;
        }
        if(ptr->Er_Rope){
            ptr->Energy_recharge += 19.4;
        }else{
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"]+=43.2;
        }


        //substats
        ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed+=ptr->Sub_Speed_use;
        ptr->Sub_Unit_ptr[0]->Stats_type["Ehr"]["None"]+=ptr->Sub_effect_hit_rate_use;
        //eidolon

    }
    void Turn_func(Unit *ptr){
        auto ally_ptr = dynamic_cast<Sub_Unit*>(ptr);
        if(1){
            Skill(ally_ptr->ptr_to_unit);
        }else {
            Basic_Atk(ally_ptr->ptr_to_unit);
        }
    }
    void Basic_Atk(Ally *ptr){
        Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
        Increase_energy(ptr,30,0);
        Combat_data data_ = Combat_data();
        Action_bar.push(data_);


    }
    void Skill(Ally *ptr){
        Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
        Increase_energy(ptr,30,0);
        Combat_data data_ = Combat_data();
        Action_bar.push(data_);


    }
    void Ult_func(Ally *ptr){
        if(!ultUseCheck(ptr))return;     
    } 

    void Tune_stats(Ally *ptr){
        Cal_Speed_Needed(ptr,150);
    }

    
}
#endif
