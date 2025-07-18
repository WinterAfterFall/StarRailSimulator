#include "../include.h"

void ActionValueStats::speedBuff(double spd_percent ,double flat_spd){
    double x = this->Max_atv;
    this->flatSpeed += flat_spd;
    this->speedPercent += spd_percent;
    Update_Max_atv(this);
    this->atv=this->atv/x*this->Max_atv;
}
bool compareActionValueStats(ActionValueStats* a, ActionValueStats* b) {
    return a->atv > b->atv; // Sort by `atv` in descending order
}
void Update_Max_atv(ActionValueStats *ptr) {
    if(ptr->baseSpeed<=0){
        ptr->Max_atv = 1e6;
        return;
    }
    ptr->Max_atv = K_const / (ptr->baseSpeed + ptr->baseSpeed * ptr->speedPercent/100 + ptr->flatSpeed);
    
}
void ActionValueStats::resetATV(){
    Update_Max_atv(this);
    resetTurn(this);
}
void ActionValueStats::resetATV(double baseSpeed){
    this->baseSpeed = baseSpeed;
    Update_Max_atv(this);
    resetTurn(this);
}
void resetTurn(ActionValueStats *ptr) {

    ptr->atv = ptr->Max_atv;
    
}
void All_atv_reset() {
    for(int i=1;i<=Total_enemy;i++){
        Update_Max_atv(Enemy_unit[i]->Atv_stats.get());
        resetTurn(Enemy_unit[i]->Atv_stats.get());
    }
    
    for(int i=1;i<=Total_ally;i++){
        for(int j=0,sz = Ally_unit[i]->Summon_ptr.size();j<sz;j++){
        Update_Max_atv(Ally_unit[i]->Summon_ptr[j]->Atv_stats.get());
        resetTurn(Ally_unit[i]->Summon_ptr[j]->Atv_stats.get());
        }
    }
    for(int i=1;i<=Total_ally;i++){
        for(int j=0,sz = Ally_unit[i]->Countdown_ptr.size();j<sz;j++){
        Update_Max_atv(Ally_unit[i]->Countdown_ptr[j]->Atv_stats.get());
        resetTurn(Ally_unit[i]->Countdown_ptr[j]->Atv_stats.get());
        }
    }
    for(int i=1;i<=Total_ally;i++){
        for(int j=0,sz = Ally_unit[i]->Sub_Unit_ptr.size();j<sz;j++){
        Update_Max_atv(Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats.get());
        resetTurn(Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats.get());
        }
    }
       
    
}
void Action_forward(ActionValueStats *ptr,double fwd) {
    if(ptr->baseSpeed<=0)return;
    if(!ptr->ptrToChar->isAlive())return;
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
    vector<ActionValueStats*> vec;
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
void Find_turn(){
    pair<double,int> mx;
    turn = nullptr;
    mx.first = 1e9;
    mx.second = 0;
    for(int i=1;i<=Total_enemy;i++){
        if(!Enemy_unit[i]->isAtvChangeAble())continue;
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
            if(!Ally_unit[i]->Summon_ptr[j]->isAtvChangeAble())continue;
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
            if(!Ally_unit[i]->Countdown_ptr[j]->isAtvChangeAble())continue;
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
            if(!Ally_unit[i]->Sub_Unit_ptr[j]->isAtvChangeAble())continue;
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
        if(!Enemy_unit[i]->isAtvChangeAble())continue;;
        Enemy_unit[i]->Atv_stats->atv -= Atv_reduce;
    }
    for(int i=1;i<=Total_ally;i++){
        for(int j=0,sz = Ally_unit[i]->Sub_Unit_ptr.size();j<sz;j++){
        if(!Ally_unit[i]->Sub_Unit_ptr[j]->isAtvChangeAble())continue;
        Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->atv -= Atv_reduce;
        }
    }
    for(int i=1;i<=Total_ally;i++){
        for(int j=0,sz = Ally_unit[i]->Summon_ptr.size();j<sz;j++){
        if(!Ally_unit[i]->Summon_ptr[j]->isAtvChangeAble())continue;
        Ally_unit[i]->Summon_ptr[j]->Atv_stats->atv -= Atv_reduce;
        }
    }
    for(int i=1;i<=Total_ally;i++){
        for(int j=0,sz = Ally_unit[i]->Countdown_ptr.size();j<sz;j++){
        if(!Ally_unit[i]->Countdown_ptr[j]->isAtvChangeAble())continue;
        Ally_unit[i]->Countdown_ptr[j]->Atv_stats->atv -= Atv_reduce;
        }
    }
    Current_atv+=Atv_reduce;
}
