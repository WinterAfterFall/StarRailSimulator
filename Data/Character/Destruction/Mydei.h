#ifndef MYDEI_H
#define MYDEI_H

#define endl '\n'
#define F first
#define S second
#include "../Library.h"

namespace Mydei{
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar);
    void Reset(Ally *ptr);
    void Turn_func(Unit *ptr);
    void Ult_func(Ally *ptr);//*
    void Tune_stats(Ally *ptr);
    void Start_game(Ally *ptr);
    void Stats_Adjust(Ally *ptr,Sub_Unit *target, string StatsType);
    void WhenDecreaseHP(Ally *ptr,Unit *Trigger,Sub_Unit *target,double Value);
    void WhenHeal(Ally *ptr,Sub_Unit *Healer,Sub_Unit *target,double Value);
    void Enemy_hit(Ally *ptr,Enemy *Attacker,vector<Sub_Unit*> target);
    void Before_turn(Ally *ptr);
    void After_attack(Ally *ptr,Combat_data &data_);

    void Print(Ally *ptr);
    

    //
    void Basic_Atk(Ally *ptr);      
    void Skill(Ally *ptr);
    void Enchance_Skill(Ally *ptr);
    void KingSlayer(Ally *ptr);
    void ChargePoint(Ally *ptr,double point);
    double CalculateChargePoint(Sub_Unit *ptr,double Value);
    
    void Setup(int num ,int E,function<void(Ally *ptr)> LC,function<void(Ally *ptr)> Relic,function<void(Ally *ptr)> Planar){
        Ally_unit[num] = make_unique<Ally>();
        SetBaseStats(Ally_unit[num]->Sub_Unit_ptr[0].get(),1552,427,194);
        SetBasicStats(Ally_unit[num].get(),95,160,160,E,"Imaginary","Destruction",num,"Mydei","Ally");

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
        Ultimate_List.push_back(TriggerByYourSelf_Func(PRIORITY_BUFF,Ally_unit[num].get(),Ult_func));
        Reset_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Reset));
        Tune_stats_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Tune_stats));
        Start_game_List.push_back(TriggerByYourSelf_Func(PRIORITY_IMMEDIATELY,Ally_unit[num].get(),Start_game));
        Stats_Adjust_List.push_back(TriggerByStats(PRIORITY_ACTTACK,Ally_unit[num].get(),Stats_Adjust));
        HPDecrease_List.push_back(TriggerDecreaseHP(PRIORITY_ACTTACK,Ally_unit[num].get(),WhenDecreaseHP));
        Healing_List.push_back(TriggerHealing(PRIORITY_ACTTACK,Ally_unit[num].get(),WhenHeal));
        Enemy_hit_List.push_back(TriggerByEnemyHit(PRIORITY_ACTTACK,Ally_unit[num].get(),Enemy_hit));
        Before_turn_List.push_back(TriggerByYourSelf_Func(PRIORITY_ACTTACK,Ally_unit[num].get(),Before_turn));
        After_attack_List.push_back(TriggerByAction_Func(PRIORITY_ACTTACK,Ally_unit[num].get(),After_attack));
        


        Ally_unit[num]->SetRelic(0,1,1,0);
        Ally_unit[num]->Speed_tune_value = 135;



        // SetMemoStats(Ally_unit[num].get(),66,35,"Lightning","MemName","Memosprite");
        // SetCountdownStats(Ally_unit[num].get(),"Name");
        // Ally_unit[num]->Sub_Unit_ptr[1]->Turn_func = Mem_turn;
        // Ally_unit[num]->Countdown_ptr[0]->Turn_func = CountDown_turn;

    }

    void Reset(Ally *ptr){
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_CRIT_DAM]["None"]+=37.3;
        ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_PERCENT]["None"]+=18;
        ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed+=5;



        //relic
        if(ptr->Body_CritDam){
            ptr->Sub_Unit_ptr[0]->Stats_type["Crit_dam"]["None"]+=64.8;
        }else{
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_PERCENT]["None"]+=43.2;
        }
        if(ptr->Speed_Boot){
            ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed+=25;
        }else{
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"]+=43.2;
        }
        if(ptr->Element_Orb){
            ptr->Sub_Unit_ptr[0]->Stats_each_element["Dmg%"]["Imaginary"]["None"]+=38.8;
        }else{
            ptr->Sub_Unit_ptr[0]->Stats_type["Atk%"]["None"]+=43.2;
        }
        if(ptr->Er_Rope){
            ptr->Energy_recharge += 19.4;
        }else{
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HP_PERCENT]["None"]+=43.2;
        }


        //substats
        ptr->Sub_Unit_ptr[0]->Atv_stats->Flat_Speed+=ptr->Sub_Speed_use;
        ptr->Sub_Unit_ptr[0]->Stats_type["Ehr"]["None"]+=ptr->Sub_effect_hit_rate_use;
        //eidolon

    }
    void Turn_func(Unit *ptr){
        auto ally_ptr = dynamic_cast<Sub_Unit*>(ptr);
        if(ally_ptr->Buff_check["Mydei_Vendetta"]==false){
            Skill(ally_ptr->ptr_to_unit);
        }else {
            Enchance_Skill(ally_ptr->ptr_to_unit);
        }
    }
    void Basic_Atk(Ally *ptr){
        Skill_point(ptr->Sub_Unit_ptr[0].get(),-1);
        Increase_energy(ptr,30,0);
        Combat_data data_ = Combat_data();
        Action_bar.push(data_);
        //none complete

    }
    void Skill(Ally *ptr){
        Increase_energy(ptr,30,0);
        Combat_data data_ = Combat_data();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Blast");
        data_.Add_Target_Adjacent();
        data_.resetTurn();
        data_.Damage_spilt.Main.push_back({0,90,0,20});
        data_.Damage_spilt.Adjacent.push_back({0,50,0,10});
        DecreaseHP(ptr->Sub_Unit_ptr[0].get(),ptr->Sub_Unit_ptr[0].get(),0,0,50);
        Action_bar.push(data_);
    }
    void Enchance_Skill(Ally *ptr){
        Increase_energy(ptr,30,0);
        Combat_data data_ = Combat_data();
        data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Blast");
        data_.Add_Target_Adjacent();
        data_.resetTurn();
        data_.Damage_spilt.Main.push_back({0,110,0,20});
        data_.Damage_spilt.Adjacent.push_back({0,66,0,10});
        DecreaseHP(ptr->Sub_Unit_ptr[0].get(),ptr->Sub_Unit_ptr[0].get(),0,0,35);
        Action_bar.push(data_);
    }
    void KingSlayer(Ally *ptr){
        Increase_energy(ptr,10,0);
        Combat_data data_ = Combat_data();
        if(ptr->Eidolon>=1){
            data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Aoe");
            data_.Add_Target_Other();
            data_.Damage_spilt.Main.push_back({0,155,0,15});
            data_.Damage_spilt.Main.push_back({0,155,0,15});
            data_.Damage_spilt.Adjacent.push_back({0,155,0,10});
            data_.Damage_spilt.Adjacent.push_back({0,155,0,10});
            data_.Damage_spilt.Other.push_back({0,155,0,10});
            data_.Damage_spilt.Other.push_back({0,155,0,10});
        }else{
            data_.Skill_set(ptr->Sub_Unit_ptr[0].get(),"Blast");
            data_.Add_Target_Adjacent();
            data_.Damage_spilt.Main.push_back({0,140,0,15});
            data_.Damage_spilt.Main.push_back({0,140,0,15});
            data_.Damage_spilt.Adjacent.push_back({0,84,0,10});
            data_.Damage_spilt.Adjacent.push_back({0,84,0,10});
        }
        
        Action_bar.push(data_);
        if(!actionBarUse)Deal_damage();
    }
    void Ult_func(Ally *ptr){
        if(!ultUseCheck(ptr))return;
        Combat_data data_ = Combat_data();
        data_.Ultimate_set(ptr->Sub_Unit_ptr[0].get(),"Blast");   
        data_.Add_Target_Adjacent();
        for(Enemy* e :data_.Target_Attack){
            e->target = ptr->Sub_Unit_ptr[0].get();
        }
        data_.Damage_spilt.Main.push_back({0,160,0,20});
        data_.Damage_spilt.Adjacent.push_back({0,100,0,20});
        Action_bar.push(data_);
        HealRatio healratio = HealRatio();
        healratio.setRatio(0,0,0,0,20,0);
        Healing(healratio,ptr->Sub_Unit_ptr[0].get(),ptr->Sub_Unit_ptr[0].get());
        ChargePoint(ptr,20);
        if(ptr->Print)Char_Command::printUltStart(ptr->Sub_Unit_ptr[0]->Atv_stats->Unit_Name);
        if(!actionBarUse)Deal_damage();
    }
    void Start_game(Ally *ptr){
        if(ptr->Eidolon>=6){
            ptr->Sub_Unit_ptr[0]->Buff_check["Mydei_Vendetta"]=true;
            Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(),100);
            HealRatio healratio = HealRatio();
            healratio.setRatio(0,0,0,0,25,0);
            Healing(healratio,ptr->Sub_Unit_ptr[0].get(),ptr->Sub_Unit_ptr[0].get());
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_FLAT_DEF][AT_NONE]-=10000;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_FLAT_DEF][AT_TEMP]-=10000;
            if(ptr->Eidolon>=2)Buff_single_target(ptr->Sub_Unit_ptr[0].get(),ST_DEF_SHRED,AT_NONE,15);
            if(ptr->Eidolon>=4)Buff_single_target(ptr->Sub_Unit_ptr[0].get(),ST_CRIT_DAM,AT_NONE,30);
        }
        allEventAdjustStats(ptr->Sub_Unit_ptr[0].get(),"Hp%");
        if(ptr->Technique){
            Combat_data data_ = Combat_data();
            data_.Technique_set(ptr->Sub_Unit_ptr[0].get(),"Aoe");
            data_.Add_Target_Other();
            data_.Damage_spilt.Main.push_back({0,80,0,0});
            data_.Damage_spilt.Adjacent.push_back({0,80,0,0});
            data_.Damage_spilt.Other.push_back({0,80,0,0});
            ChargePoint(ptr,50);
            Action_bar.push(data_);
            if(!actionBarUse)Deal_damage();
        }
        
        
    }
    void Tune_stats(Ally *ptr){
        Cal_Speed_Needed(ptr,ptr->Speed_tune_value);
    }
    void Stats_Adjust(Ally *ptr,Sub_Unit *target, string StatsType){
        if(target->Atv_stats->Unit_Name!="Mydei")return;
        if(StatsType==ST_FLAT_HP|| StatsType == ST_HP_PERCENT){
            if(Buff_check(ptr->Sub_Unit_ptr[0].get(),"Mydei_Vendetta")){
                ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_Talent"] = calculateHpForBuff(ptr->Sub_Unit_ptr[0].get(),50) - ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_Talent"];
                
                Buff_single_target(ptr->Sub_Unit_ptr[0].get(),ST_FLAT_HP,AT_TEMP,ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_Talent"]);
                Buff_single_target(ptr->Sub_Unit_ptr[0].get(),ST_FLAT_HP,AT_NONE,ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_Talent"]);
            }

            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CRIT_RATE][AT_NONE] -= ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_A6"]*1.2;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CRIT_RATE][AT_TEMP] -= ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_A6"]*1.2;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HEALING][AT_NONE] -= ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_A6"]*0.75;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HEALING][AT_TEMP] -= ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_A6"]*0.75;
            
            
            ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_A6"] = (floor((ptr->Sub_Unit_ptr[0]->totalHP-4000)/100) <= 40) ? floor((ptr->Sub_Unit_ptr[0]->totalHP-4000)/100) : 40;
            if(ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_A6"]<0) ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_A6"] = 0;
                    
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CRIT_RATE][AT_NONE] += ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_A6"]*1.2;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_CRIT_RATE][AT_TEMP] += ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_A6"]*1.2;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HEALING][AT_NONE] += ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_A6"]*0.75;
            ptr->Sub_Unit_ptr[0]->Stats_type[ST_HEALING][AT_TEMP] += ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_A6"]*0.75;

            
                            
        }
    }
    void WhenDecreaseHP(Ally *ptr,Unit *Trigger,Sub_Unit *target,double Value){
        if(!target->isSameUnit("Mydei"))return;
        if(isEnemyCheck(Trigger)){
            ChargePoint(ptr,((ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_A6"]*2.5+100.0)/100.0)*CalculateChargePoint(ptr->Sub_Unit_ptr[0].get(),Value));
        }else{
            ChargePoint(ptr,CalculateChargePoint(ptr->Sub_Unit_ptr[0].get(),Value));
        }
    }
    void WhenHeal(Ally *ptr,Sub_Unit *Healer,Sub_Unit *target,double Value){
        if(!target->isSameUnit("Mydei"))return;
        if(ptr->Eidolon<2)return;
        Value = (Value + ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_E2"] <= target->totalHP) ? Value : target->totalHP - ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_E2"];
        ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_E2"] += Value;
        ChargePoint(ptr,CalculateChargePoint(ptr->Sub_Unit_ptr[0].get(),Value*0.4));
        

    }
    void Enemy_hit(Ally *ptr,Enemy *Attacker,vector<Sub_Unit*> target){
        if(ptr->Eidolon<4)return;
        for(Sub_Unit *e : target){
            if(e->isSameUnit("Mydei"))goto jump;
        }
        return;
        jump:
        HealRatio healratio = HealRatio();
        healratio.setRatio(0,0,0,0,10,0);
        Healing(healratio,ptr->Sub_Unit_ptr[0].get(),ptr->Sub_Unit_ptr[0].get());


    }
    void Print(Ally *ptr){
        cout<<"Talent :"<<ptr->Sub_Unit_ptr[0]->Buff_check["Mydei_Vendetta"]<<" ";
        cout<<"A6 :"<<ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_A6"]<<" ";
        cout<<"Talent hp :"<<ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_Talent"]<<" ";
        
        cout<<endl;
    }
    void Before_turn(Ally *ptr){
        ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_E2"] = 0;
    }
    void After_attack(Ally *ptr,Combat_data &data_){
        if(ptr->Sub_Unit_ptr[0]->Buff_check["Mydei_action"]){
            ptr->Sub_Unit_ptr[0]->Buff_check["Mydei_action"] = 0;
            Action_forward(ptr->Sub_Unit_ptr[0]->Atv_stats.get(),100);
        }
    }
    double CalculateChargePoint(Sub_Unit *ptr,double Value){
        return (Value/ptr->totalHP*100.0);
    }
    void ChargePoint(Ally *ptr,double point){
        ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_Charge_point"]+=point;
        if(ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_Charge_point"]>=100&&ptr->Sub_Unit_ptr[0]->Buff_check["Mydei_Vendetta"]==false){
            ptr->Sub_Unit_ptr[0]->Buff_check["Mydei_Vendetta"]=true;
            ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_Charge_point"]-=100;
            ptr->Sub_Unit_ptr[0]->Buff_check["Mydei_action"]=1;
            HealRatio healratio = HealRatio();
            healratio.setRatio(0,0,0,0,25,0);
            Healing(healratio,ptr->Sub_Unit_ptr[0].get(),ptr->Sub_Unit_ptr[0].get());
            Buff_single_target(ptr->Sub_Unit_ptr[0].get(),ST_FLAT_DEF,AT_TEMP,-10000);
            Buff_single_target(ptr->Sub_Unit_ptr[0].get(),ST_FLAT_DEF,AT_NONE,-10000);
            if(ptr->Eidolon>=2)Buff_single_target(ptr->Sub_Unit_ptr[0].get(),ST_DEF_SHRED,AT_NONE,15);
            if(ptr->Eidolon>=4)Buff_single_target(ptr->Sub_Unit_ptr[0].get(),ST_CRIT_DAM,AT_NONE,30);
            allEventAdjustStats(ptr->Sub_Unit_ptr[0].get(),"Hp%");
        }
        if(ptr->Eidolon>=6){
            if(ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_Charge_point"]>=100){
                ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_Charge_point"]-=100;
                KingSlayer(ptr);
            }
        }else{
            if(ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_Charge_point"]>=150){
                ptr->Sub_Unit_ptr[0]->Buff_note["Mydei_Charge_point"]-=150;
                ptr->Sub_Unit_ptr[0]->Buff_note["count"]++;
                KingSlayer(ptr);
            }
        }
        
    }

    

    
}
#endif
