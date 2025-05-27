#ifndef COMBAT_H
#define COMBAT_H
#include<bits/stdc++.h>
#include "../Class/ClassLibrary.h"
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
        
        turn->ptr_to_unit->Turn_func();  
        
        Deal_damage();
        
        
    }
    
    Ult_After_Turn = 1;
    
    
    allUltimateCheck();
    After_Turn_Check = 1;
    
    allEventAfterTurn();
    

}

void Deal_damage(){
    if(actionBarUse)return;
    actionBarUse = true;
    while(!Action_bar.empty()){
        shared_ptr<ActionData> temp = Action_bar.front();
        allEventBeforeAction(temp);
        if (auto allyActionData = dynamic_pointer_cast<AllyActionData>(temp)) {
            allyActionData->AllyAction();
        } else if (auto enemyActionData = dynamic_pointer_cast<EnemyActionData>(temp)) {
            enemyActionData->EnemyAction();
        }
        allEventAfterAction(temp);
        Action_bar.pop();
    }
    actionBarUse = false;
}
void AllyActionData::AllyAction(){
    std::shared_ptr<AllyActionData> self = shared_from_this();
    if(this->Action_type.first == "Attack"){
        
        allEventBeforeAttack(self);
        
        if(this->actionFunction)this->actionFunction(self);
        else Attack(self);    
        
        for(int i = 0; i < this->attackerList.size() ; i++){
            this->Attacker = this->attackerList[i];
            allEventWhenAttack(self);
        }
        
        this->Attacker = this->attackerList[0];
        allEventAfterAttack(self);  

    }else if(this->Action_type.first == "Buff"){
        if(this->actionFunction)this->actionFunction(self);
        if(this->Turn_reset)resetTurn(turn);
        allEventBuff(self);
    }
    
    if(this->damageNote)Cal_AverageDamage(this->Attacker->ptr_to_unit,this->Target_Attack); 
}
void EnemyActionData::EnemyAction(){
    this->actionFunction();
    resetTurn(turn);
}
void Attack(shared_ptr<AllyActionData> &data_){
    int Total_hit = 0;
    int temp = 0;
    unordered_map<string,int> Total_hit_each;
    string Current_Attack_Name = data_->Attacker->Atv_stats->Char_Name;
    

    for(int i=0, sz1 = data_->Damage_spilt.Main.size(),sz2 = data_->Damage_spilt.Adjacent.size(),sz3 = data_->Damage_spilt.Other.size();i<sz1;i++){
        if(temp!=data_->switchAttacker.size()&&data_->switchAttacker[temp].changeWhen==i){
            data_->Attacker = data_->switchAttacker[temp].attacker;
            data_->source = data_->switchAttacker[temp].source;
            Current_Attack_Name = data_->Attacker->Atv_stats->Char_Name;
            ++temp;
        }
        for(auto Enemy_target : data_->Target_Attack){
            if(Enemy_target->Target_type=="Main"&&(data_->Damage_spilt.Main[i].Atk_ratio!=0||data_->Damage_spilt.Main[i].Hp_ratio!=0||data_->Damage_spilt.Main[i].Def_ratio!=0)){
                Total_hit++;
                Total_hit_each[Current_Attack_Name]++;
            }else if(i<sz2 && Enemy_target->Target_type=="Adjacent"&&(data_->Damage_spilt.Adjacent[i].Atk_ratio!=0||data_->Damage_spilt.Adjacent[i].Hp_ratio!=0||data_->Damage_spilt.Adjacent[i].Def_ratio!=0)){
                Total_hit++;
                Total_hit_each[Current_Attack_Name]++;
            }else if(i<sz3 && Enemy_target->Target_type=="Other"&&(data_->Damage_spilt.Other[i].Atk_ratio!=0||data_->Damage_spilt.Other[i].Hp_ratio!=0||data_->Damage_spilt.Other[i].Def_ratio!=0)){
                Total_hit++;
                Total_hit_each[Current_Attack_Name]++;
            }
        }
        allEventAttackHitCount(data_,Total_hit_each[Current_Attack_Name],Total_hit);
        for(auto Enemy_target : data_->Target_Attack){
            if(Enemy_target->Target_type=="Main"){
            Cal_Damage(data_,Enemy_target,data_->Damage_spilt.Main[i]);
            Cal_Toughness_reduction(data_,Enemy_target,data_->Damage_spilt.Main[i].Toughness_ratio);
            }
            
            if(i<sz2 && Enemy_target->Target_type=="Adjacent"){
            Cal_Damage(data_,Enemy_target,data_->Damage_spilt.Adjacent[i]);
            Cal_Toughness_reduction(data_,Enemy_target,data_->Damage_spilt.Adjacent[i].Toughness_ratio);
            }
            
            if(i<sz3 && Enemy_target->Target_type=="Other"){
            Cal_Damage(data_,Enemy_target,data_->Damage_spilt.Other[i]);
            Cal_Toughness_reduction(data_,Enemy_target,data_->Damage_spilt.Other[i].Toughness_ratio);
            }    
        }
    }
    if(data_->Turn_reset)resetTurn(turn);
}
void Skill_point(SubUnit *ptr,int p){
    
    allEventSkillPoint(ptr,p);
    sp+=p;
    if(sp>Max_sp){
        sp = Max_sp;
    }
    return ;
}
void Superbreak_trigger(shared_ptr<AllyActionData> &data_, double Superbreak_ratio){
    shared_ptr<AllyActionData> data_2 = make_shared<AllyActionData>();
    data_2->setSuperBreak(data_->Attacker,data_->traceType);
    
    for(int i=1;i<=Total_enemy;i++){
        double toughness_reduce=0;
        if(Enemy_unit[i]->Toughness_status==1)continue;
        if(Enemy_unit[i]->Target_type=="Main"){
            for(int j=0,sz=data_->Damage_spilt.Main.size();j<sz;j++){
                toughness_reduce+=data_->Damage_spilt.Main[j].Toughness_ratio;
            }
            
        }
            
        if(Enemy_unit[i]->Target_type=="Adjacent"){
            for(int j=0,sz=data_->Damage_spilt.Adjacent.size();j<sz;j++){
                toughness_reduce+=data_->Damage_spilt.Adjacent[j].Toughness_ratio;
            }
            
        }
            
        if(Enemy_unit[i]->Target_type=="Other"){
            for(int j=0,sz=data_->Damage_spilt.Other.size();j<sz;j++){
                toughness_reduce+=data_->Damage_spilt.Other[j].Toughness_ratio;
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
    shared_ptr<AllyActionData> data_ = make_shared<AllyActionData>();
    data_->Skill_Type.push_back("Dot");
    
    data_->Action_type.first = "Attack";
    data_->Action_type.second = "Dot";
    data_->traceType = "Single_target";
    
    if(target->Bleed > 0&&(Dot_type==AT_NONE||"Physical")){
        data_->Attacker=Ally_unit[target->Bleeder]->Sub_Unit_ptr[0].get();
        data_->Damage_element = "Physical";
        data_->Skill_Type.push_back("Bleed");
        Cal_Dot_Toughness_break_damage(data_,target,Dot_ratio*2*(0.5+target->Max_toughness/40));
    }
    if(target->Burn > 0&&(Dot_type==AT_NONE||"Fire")){
        data_->Attacker=Ally_unit[target->Burner]->Sub_Unit_ptr[0].get();
        data_->Damage_element = "Fire";
        data_->Skill_Type.resize(0);
        data_->Skill_Type.push_back("Burn");
        Cal_Dot_Toughness_break_damage(data_,target,Dot_ratio*1);
    }
    if(target->Shock > 0&&(Dot_type==AT_NONE||"Lightning")){
        data_->Attacker=Ally_unit[target->Shocker]->Sub_Unit_ptr[0].get();
        
        data_->Damage_element = "Lightning";
        data_->Skill_Type.resize(0);
        data_->Skill_Type.push_back("Shock");
        Cal_Dot_Toughness_break_damage(data_,target,Dot_ratio*2);
    }
    if(target->Wind_shear > 0&&(Dot_type==AT_NONE||"Wind")){
        data_->Attacker=Ally_unit[target->Wind_shearer]->Sub_Unit_ptr[0].get();
        data_->Skill_Type.resize(0);
        data_->Damage_element = "Wind";
        data_->Skill_Type.push_back("Wind_shear");
        Cal_Dot_Toughness_break_damage(data_,target,Dot_ratio*1*target->Wind_shear_stack);
    }
    for(TriggerDot_Func &e : Dot_List){
        e.Call(target,Dot_ratio,Dot_type);
    }
    
}
void Toughness_break(shared_ptr<AllyActionData> &data_,Enemy* target){
    SubUnit *temp1;
    string temp2;
    if(Force_break!=0){
        temp1 = data_->Attacker;
        temp2 = data_->Damage_element;
        data_->Attacker = Ally_unit[Force_break]->Sub_Unit_ptr[0].get();
        data_->Damage_element = Ally_unit[Force_break]->Sub_Unit_ptr[0]->Element_type[0];
    }
    double Constant = 0;
    shared_ptr<AllyActionData> data_2 = make_shared<AllyActionData>();
    data_2->setBreakDmg(data_->Attacker,"Break");
    ++target->Total_debuff;
    allEventApplyDebuff(data_->Attacker,target);
    

    if(SuperBreak__Mode==1){
        target->Atv_stats->atv=target->Atv_stats->Max_atv*0.5;
    }

    if(data_->Damage_element=="Physical"){
        Action_forward(target->Atv_stats.get(),-25);
        target->Bleed = 2;
        target->Bleeder =data_->Attacker->Atv_stats->Unit_num;
        Constant=2;

    }else if(data_->Damage_element=="Fire"){
        Action_forward(target->Atv_stats.get(),-25);
        target->Burn = 2;
        target->Burner =data_->Attacker->Atv_stats->Unit_num;
        Constant=2;

    }else if(data_->Damage_element=="Ice"){
        Action_forward(target->Atv_stats.get(),-25);
        target->Freeze = data_->Attacker->Atv_stats->Unit_num;
        Constant=1;

    }else if(data_->Damage_element=="Lightning"){
        Action_forward(target->Atv_stats.get(),-25);
        target->Shock = 2;
        target->Shocker =data_->Attacker->Atv_stats->Unit_num;
        Constant=1;

    }else if(data_->Damage_element=="Wind"){
        Action_forward(target->Atv_stats.get(),-25);
        target->Wind_shear = 2;
        target->Wind_shearer =data_->Attacker->Atv_stats->Unit_num;
        if(target->Wind_shear_stack>=3){
            target->Wind_shear_stack=5;
        }else { target->Wind_shear_stack=3;}
        Constant=1.5;

    }else if(data_->Damage_element=="Quantum"){
        Action_forward(target->Atv_stats.get(),-20*Cal_BreakEffect_multiplier(data_,target));
        target->Entanglement = data_->Attacker->Atv_stats->Unit_num;
        target->Entanglement_stack = 0;
        Constant=0.5;

    }else if(data_->Damage_element=="Imaginary"){
        Action_forward(target->Atv_stats.get(),-30*Cal_BreakEffect_multiplier(data_,target));
        target->speedBuff({ST_SPD,ST_SPD_P,-10});

        target->Imprisonment = data_->Attacker->Atv_stats->Unit_num;
        Constant=0.5;
    }
        
    
    Cal_Break_damage(data_2,target,Constant);
    target->Toughness_status=0;
    allEventWhenToughnessBreak(data_,target);

    if(Force_break!=0){
        data_->Attacker = temp1;
        data_->Damage_element = temp2;
    }
    
}
#endif