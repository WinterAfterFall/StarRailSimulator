#ifndef ATV_H
#define ATV_H
#include<bits/stdc++.h>
#include "../Class/Trigger_Function.h"
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12
#define K_const 10000


bool compareActionValueStats(Action_value_stats* a, Action_value_stats* b) {
    return a->atv > b->atv; // Sort by `atv` in descending order
}
void Update_Max_atv(Action_value_stats *ptr) {
    if(ptr->Base_speed<=0){
        ptr->Max_atv = 1e6;
        return;
    }
    ptr->Max_atv = K_const / (ptr->Base_speed + ptr->Base_speed * ptr->Speed_percent/100 + ptr->Flat_Speed);
    
}
void atv_reset(Action_value_stats *ptr) {

    ptr->atv = ptr->Max_atv;
    
}
void All_atv_reset() {
    for(int i=1;i<=Total_enemy;i++){
        Update_Max_atv(Enemy_unit[i]->Atv_stats.get());
        atv_reset(Enemy_unit[i]->Atv_stats.get());
    }
    
    for(int i=1;i<=Total_ally;i++){
        for(int j=0,sz = Ally_unit[i]->Summon_ptr.size();j<sz;j++){
        Update_Max_atv(Ally_unit[i]->Summon_ptr[j]->Atv_stats.get());
        atv_reset(Ally_unit[i]->Summon_ptr[j]->Atv_stats.get());
        }
    }
    for(int i=1;i<=Total_ally;i++){
        for(int j=0,sz = Ally_unit[i]->Countdown_ptr.size();j<sz;j++){
        Update_Max_atv(Ally_unit[i]->Countdown_ptr[j]->Atv_stats.get());
        atv_reset(Ally_unit[i]->Countdown_ptr[j]->Atv_stats.get());
        }
    }
    for(int i=1;i<=Total_ally;i++){
        for(int j=0,sz = Ally_unit[i]->Sub_Unit_ptr.size();j<sz;j++){
        Update_Max_atv(Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats.get());
        atv_reset(Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats.get());
        }
    }
       
    
}
void Action_forward(Action_value_stats *ptr,double fwd) {
    if(ptr->Base_speed<=0)return;
    if(ptr->Unit_num==0){
        return ;
    }
    if (ptr->atv <= ptr->Max_atv*fwd/100 ) {
        ptr->atv = 0;
        ptr->priority = ++Turn_priority;
        return ;
    } else {
        ptr->atv = ptr->atv - ptr->Max_atv*fwd/100;
        return ;
    }
}
void All_Action_forward(double fwd){
    vector<Action_value_stats*> vec;
    for(int i=1;i<=Total_ally;i++){
        for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
            vec.push_back(Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats.get());
        }
    }
    sort(vec.begin(),vec.end(),compareActionValueStats);
    for(int i=0;i<vec.size();i++){
        Action_forward(vec[i],fwd);
      
    }
}


void Speed_Buff(Action_value_stats *ptr,double spd_percent ,double flat_spd ) {
    double x = ptr->Max_atv;
    ptr->Flat_Speed += flat_spd;
    ptr->Speed_percent += spd_percent;
    Update_Max_atv(ptr);
    ptr->atv=ptr->atv/x*ptr->Max_atv;
    SubUnit *temp = ptr->canCastToSubUnit();
    if(!temp)return;
    StatsAdjust(temp,"Speed");
}
void Find_turn(){
    pair<double,int> mx;
    turn = nullptr;
    mx.first = 1e9;
    mx.second = 0;
    for(int i=1;i<=Total_enemy;i++){
        if(mx.first > Enemy_unit[i]->Atv_stats->atv){
            mx.first = Enemy_unit[i]->Atv_stats->atv;
            mx.second = Enemy_unit[i]->Atv_stats->priority;
            turn = Enemy_unit[i]->Atv_stats.get();
            continue;
        }
        if(mx.first == Enemy_unit[i]->Atv_stats->atv){
            if(mx.second<Enemy_unit[i]->Atv_stats->priority){
                mx.second = Enemy_unit[i]->Atv_stats->priority;
            turn = Enemy_unit[i]->Atv_stats.get();
            }
        }
    }
    for(int i=1;i<=Total_ally;i++){
        for(int j=0,sz = Ally_unit[i]->Summon_ptr.size();j<sz;j++){ 
        if(mx.first >Ally_unit[i]->Summon_ptr[j]->Atv_stats->atv){
            mx.first = Ally_unit[i]->Summon_ptr[j]->Atv_stats->atv;
            mx.second = Ally_unit[i]->Summon_ptr[j]->Atv_stats->priority;
            turn = Ally_unit[i]->Summon_ptr[j]->Atv_stats.get();
            continue;
        }
        if(mx.first == Ally_unit[i]->Summon_ptr[j]->Atv_stats->atv){
            if(mx.second<Ally_unit[i]->Summon_ptr[j]->Atv_stats->priority){
                mx.second = Ally_unit[i]->Summon_ptr[j]->Atv_stats->priority;
            turn = Ally_unit[i]->Summon_ptr[j]->Atv_stats.get();
            }
        }
    }
    }
    for(int i=1;i<=Total_ally;i++){
        for(int j=0,sz = Ally_unit[i]->Countdown_ptr.size();j<sz;j++){ 
        if(mx.first >Ally_unit[i]->Countdown_ptr[j]->Atv_stats->atv){
            mx.first = Ally_unit[i]->Countdown_ptr[j]->Atv_stats->atv;
            mx.second = Ally_unit[i]->Countdown_ptr[j]->Atv_stats->priority;
            turn = Ally_unit[i]->Countdown_ptr[j]->Atv_stats.get();
            continue;
        }
        if(mx.first == Ally_unit[i]->Countdown_ptr[j]->Atv_stats->atv){
            if(mx.second<Ally_unit[i]->Countdown_ptr[j]->Atv_stats->priority){
                mx.second = Ally_unit[i]->Countdown_ptr[j]->Atv_stats->priority;
            turn = Ally_unit[i]->Countdown_ptr[j]->Atv_stats.get();
            }
        }
    }
    }
    for(int i=1;i<=Total_ally;i++){
        for(int j=0,sz = Ally_unit[i]->Sub_Unit_ptr.size();j<sz;j++){ 
        if(mx.first >Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->atv){
            mx.first = Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->atv;
            mx.second = Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->priority;
            turn = Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats.get();
            continue;
        }
        if(mx.first == Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->atv){
            if(mx.second<Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->priority){
                mx.second = Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->priority;
            turn = Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats.get();
            }
        }
    }
    }
}
void Atv_fix(double Atv_reduce){
    for(int i=1;i<=Total_enemy;i++){
        Enemy_unit[i]->Atv_stats->atv -= Atv_reduce;
    }
    for(int i=1;i<=Total_ally;i++){
        for(int j=0,sz = Ally_unit[i]->Summon_ptr.size();j<sz;j++){
        Ally_unit[i]->Summon_ptr[j]->Atv_stats->atv -= Atv_reduce;
        }
    }
    for(int i=1;i<=Total_ally;i++){
        for(int j=0,sz = Ally_unit[i]->Countdown_ptr.size();j<sz;j++){
        Ally_unit[i]->Countdown_ptr[j]->Atv_stats->atv -= Atv_reduce;
        }
    }
    for(int i=1;i<=Total_ally;i++){
        for(int j=0,sz = Ally_unit[i]->Sub_Unit_ptr.size();j<sz;j++){
        Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->atv -= Atv_reduce;
        }
    }
    Current_atv+=Atv_reduce;
}
#endif