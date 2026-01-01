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
    for(auto &each : atvList){
        Update_Max_atv(each);
        resetTurn(each);
    }
}
void Action_forward(ActionValueStats *ptr,double fwd) {
    if(ptr->baseSpeed<=0)return;
    if(!ptr->charptr->isAlive())return;
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
    for(auto &each : allyList){
        vec.push_back(each->Atv_stats.get());
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

    for(auto &each : atvList){
        if(!each->charptr->isAtvChangeAble())continue;
        if(mx.first > each->atv){
            mx.first = each->atv;
            mx.second = each->priority;
            turn = each;
            continue;
        }
        if(mx.first == each->atv){
            if(mx.second<each->priority){
                mx.second = each->priority;
                turn = each;
            }
        }
    }
}

void Atv_fix(double Atv_reduce){
    for(auto &each : atvList){
        if(!each->charptr->isAtvChangeAble())continue;
        each->atv -= Atv_reduce;
    }
    Current_atv+=Atv_reduce;
}
