#ifndef COMBAT_H
#define COMBAT_H
#include<bits/stdc++.h>
#include "../Print.h"
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12
#define K_const 10000


void Take_action(){
    
    ++(turn->turn_cnt);
    Ult_After_Turn = 0;
    After_Turn_Check = 0;
    allEventBeforeTurn();
    allUltimateCheck();
    
    Print();
    if(Turn_Skip==0){
        
        turn->ptr_to_unit->Turn_func(turn->ptr_to_unit);  
        Deal_damage();
        
        
    }
    
    Ult_After_Turn = 1;
    
    
    allUltimateCheck();
    After_Turn_Check = 1;
    
    allEventAfterTurn();
    

}

void Deal_damage(){
    actionBarUse = true;
    while(!Action_bar.empty()){
        ActionData temp = Action_bar.front();
        
        if(temp.Action_type.first =="Attack"){
            
            allEventBeforeAttack(temp);
            
            if(temp.actionFunction)temp.actionFunction(temp);
            else Attack(temp);
            
            if(temp.Turn_reset)atv_reset(turn);
            
            
            for(int i=0;i<temp.Attack_trigger;i++){
                temp.Attacker = temp.All_Attacker[i];
                allEventWhenAttack(temp);
            }
            temp.Attacker = temp.All_Attacker[0];
            allEventAfterAttack(temp);  
            
            
              
            


        }else if(temp.Action_type.first =="Buff"){
            
            if(temp.Turn_reset ==1){
                atv_reset(turn);
            }
            
            allEventBuff(temp);
            
            
        }
        if(temp.healPtr)Heal(*(temp.healPtr.get()));
        Action_bar.pop();
    }
    if(turn!=nullptr&&turn->Side=="Enemy"){
        atv_reset(turn);
    }
    actionBarUse = false;
}
void Attack(ActionData &data_){
    int Total_hit = 0;
    int temp = 0;
    unordered_map<string,int> Total_hit_each;
    string Current_Attack_Name = data_.Attacker->Atv_stats->Char_Name;
    

    for(int i=0, sz1 = data_.Damage_spilt.Main.size(),sz2 = data_.Damage_spilt.Adjacent.size(),sz3 = data_.Damage_spilt.Other.size();i<sz1;i++){
        if(temp!=data_.Joint.size()&&data_.Joint[temp].changeWhen==i){
            data_.Attacker = data_.Joint[temp].attacker;
            data_.source = data_.Joint[temp].source;
            Current_Attack_Name = data_.Attacker->Atv_stats->Char_Name;
            ++temp;
        }
        for(auto Enemy_target : data_.Target_Attack){
            if(Enemy_target->Target_type=="Main"&&(data_.Damage_spilt.Main[i].Atk_ratio!=0||data_.Damage_spilt.Main[i].Hp_ratio!=0||data_.Damage_spilt.Main[i].Def_ratio!=0)){
                Total_hit++;
                Total_hit_each[Current_Attack_Name]++;
            }else if(i<sz2 && Enemy_target->Target_type=="Adjacent"&&(data_.Damage_spilt.Adjacent[i].Atk_ratio!=0||data_.Damage_spilt.Adjacent[i].Hp_ratio!=0||data_.Damage_spilt.Adjacent[i].Def_ratio!=0)){
                Total_hit++;
                Total_hit_each[Current_Attack_Name]++;
            }else if(i<sz3 && Enemy_target->Target_type=="Other"&&(data_.Damage_spilt.Other[i].Atk_ratio!=0||data_.Damage_spilt.Other[i].Hp_ratio!=0||data_.Damage_spilt.Other[i].Def_ratio!=0)){
                Total_hit++;
                Total_hit_each[Current_Attack_Name]++;
            }
        }
        allEventAttackHitCount(data_,Total_hit_each[Current_Attack_Name],Total_hit);
        for(auto Enemy_target : data_.Target_Attack){
            if(Enemy_target->Target_type=="Main"){
            Cal_Damage(data_,Enemy_target,data_.Damage_spilt.Main[i]);
            Cal_Toughness_reduction(data_,Enemy_target,data_.Damage_spilt.Main[i].Toughness_ratio);
            }
            
            if(i<sz2 && Enemy_target->Target_type=="Adjacent"){
            Cal_Damage(data_,Enemy_target,data_.Damage_spilt.Adjacent[i]);
            Cal_Toughness_reduction(data_,Enemy_target,data_.Damage_spilt.Adjacent[i].Toughness_ratio);
            }
            
            if(i<sz3 && Enemy_target->Target_type=="Other"){
            Cal_Damage(data_,Enemy_target,data_.Damage_spilt.Other[i]);
            Cal_Toughness_reduction(data_,Enemy_target,data_.Damage_spilt.Other[i].Toughness_ratio);
            }    
        }
    }
}
void Heal(Heal_data& Healptr){
    Healing(Healptr);
}
void Skill_point(Sub_Unit *ptr,int p){
    
    allEventSkillPoint(ptr,p);
    sp+=p;
    if(sp>Max_sp){
        sp = Max_sp;
    }
    return ;
}
void Apply_debuff(Sub_Unit *ptr,Enemy* target){
    allEventApplyDebuff(ptr,target);
}
void Superbreak_trigger(ActionData &data_, double Superbreak_ratio){
    ActionData data_2 = ActionData();
    data_2.SuperBreak_set(data_.Attacker,data_.traceType);
    
    for(int i=1;i<=Total_enemy;i++){
        double toughness_reduce=0;
        if(Enemy_unit[i]->Toughness_status==1)continue;
        if(Enemy_unit[i]->Target_type=="Main"){
            for(int j=0,sz=data_.Damage_spilt.Main.size();j<sz;j++){
                toughness_reduce+=data_.Damage_spilt.Main[j].Toughness_ratio;
            }
            
        }
            
        if(Enemy_unit[i]->Target_type=="Adjacent"){
            for(int j=0,sz=data_.Damage_spilt.Adjacent.size();j<sz;j++){
                toughness_reduce+=data_.Damage_spilt.Adjacent[j].Toughness_ratio;
            }
            
        }
            
        if(Enemy_unit[i]->Target_type=="Other"){
            for(int j=0,sz=data_.Damage_spilt.Other.size();j<sz;j++){
                toughness_reduce+=data_.Damage_spilt.Other[j].Toughness_ratio;
            }
            
        }
        if(toughness_reduce==0)continue;
        toughness_reduce = Cal_Total_Toughness_Reduce(data_,Enemy_unit[i].get(),toughness_reduce);
        if(Enemy_unit[i]->Current_toughness+toughness_reduce<=0){
        Cal_Superbreak_damage(data_2,Enemy_unit[i].get(),Superbreak_ratio*toughness_reduce/10);
        }else{
        Cal_Superbreak_damage(data_2,Enemy_unit[i].get(),Superbreak_ratio*(-1)*Enemy_unit[i]->Current_toughness/10);
        }
    }
}
void Dot_trigger(double Dot_ratio,Enemy *target,string Dot_type){
    ActionData data_;
    data_.Skill_Type.push_back("Dot");
    
    data_.Action_type.first = "Attack";
    data_.Action_type.second = "Dot";
    data_.traceType = "Single_target";
    
    if(target->Bleed > 0&&(Dot_type=="None"||"Physical")){
        data_.Attacker=Ally_unit[target->Bleeder]->Sub_Unit_ptr[0].get();
        data_.Damage_element = "Physical";
        data_.Skill_Type.push_back("Bleed");
        Cal_Dot_Toughness_break_damage(data_,target,Dot_ratio*2*(0.5+target->Max_toughness/40));
    }
    if(target->Burn > 0&&(Dot_type=="None"||"Fire")){
        data_.Attacker=Ally_unit[target->Burner]->Sub_Unit_ptr[0].get();
        data_.Damage_element = "Fire";
        data_.Skill_Type.resize(0);
        data_.Skill_Type.push_back("Burn");
        Cal_Dot_Toughness_break_damage(data_,target,Dot_ratio*1);
    }
    if(target->Shock > 0&&(Dot_type=="None"||"Lightning")){
        data_.Attacker=Ally_unit[target->Shocker]->Sub_Unit_ptr[0].get();
        
        data_.Damage_element = "Lightning";
        data_.Skill_Type.resize(0);
        data_.Skill_Type.push_back("Shock");
        Cal_Dot_Toughness_break_damage(data_,target,Dot_ratio*2);
    }
    if(target->Wind_shear > 0&&(Dot_type=="None"||"Wind")){
        data_.Attacker=Ally_unit[target->Wind_shearer]->Sub_Unit_ptr[0].get();
        data_.Skill_Type.resize(0);
        data_.Damage_element = "Wind";
        data_.Skill_Type.push_back("Wind_shear");
        Cal_Dot_Toughness_break_damage(data_,target,Dot_ratio*1*target->Wind_shear_stack);
    }
    for(TriggerDot_Func &e : Dot_List){
        e.Call(target,e.ptr,Dot_ratio,Dot_type);
    }
    
}
void Toughness_break(ActionData &data_,Enemy* target){
    Sub_Unit *temp1;
    string temp2;
    if(Force_break!=0){
        temp1 = data_.Attacker;
        temp2 = data_.Damage_element;
        data_.Attacker = Ally_unit[Force_break]->Sub_Unit_ptr[0].get();
        data_.Damage_element = Ally_unit[Force_break]->Sub_Unit_ptr[0]->Element_type[0];
    }
    double Constant = 0;
    ActionData data_2 = ActionData();
    data_2.Break_dmg_set(data_.Attacker);
    ++target->Total_debuff;
    allEventApplyDebuff(data_.Attacker,target);
    

    if(SuperBreak__Mode==1){
        target->Atv_stats->atv=target->Atv_stats->Max_atv*0.5;
    }

    if(data_.Damage_element=="Physical"){
        Action_forward(target->Atv_stats.get(),-25);
        target->Bleed = 2;
        target->Bleeder =data_.Attacker->Atv_stats->Unit_num;
        Constant=2;

    }else if(data_.Damage_element=="Fire"){
        Action_forward(target->Atv_stats.get(),-25);
        target->Burn = 2;
        target->Burner =data_.Attacker->Atv_stats->Unit_num;
        Constant=2;

    }else if(data_.Damage_element=="Ice"){
        Action_forward(target->Atv_stats.get(),-25);
        target->Freeze = data_.Attacker->Atv_stats->Unit_num;
        Constant=1;

    }else if(data_.Damage_element=="Lightning"){
        Action_forward(target->Atv_stats.get(),-25);
        target->Shock = 2;
        target->Shocker =data_.Attacker->Atv_stats->Unit_num;
        Constant=1;

    }else if(data_.Damage_element=="Wind"){
        Action_forward(target->Atv_stats.get(),-25);
        target->Wind_shear = 2;
        target->Wind_shearer =data_.Attacker->Atv_stats->Unit_num;
        if(target->Wind_shear_stack>=3){
            target->Wind_shear_stack=5;
        }else { target->Wind_shear_stack=3;}
        Constant=1.5;

    }else if(data_.Damage_element=="Quantum"){
        Action_forward(target->Atv_stats.get(),-20*Cal_BreakEffect_multiplier(data_,target));
        target->Entanglement = data_.Attacker->Atv_stats->Unit_num;
        target->Entanglement_stack = 0;
        Constant=0.5;

    }else if(data_.Damage_element=="Imaginary"){
        Action_forward(target->Atv_stats.get(),-30*Cal_BreakEffect_multiplier(data_,target));
        Speed_Buff(target->Atv_stats.get(),-10,0);
        target->Imprisonment = data_.Attacker->Atv_stats->Unit_num;
        Constant=0.5;
    }
        
    
    Cal_Break_damage(data_2,target,Constant);
    target->Toughness_status=0;
    allEventWhenToughnessBreak(data_,target);

    if(Force_break!=0){
        data_.Attacker = temp1;
        data_.Damage_element = temp2;
    }
    
}
#endif