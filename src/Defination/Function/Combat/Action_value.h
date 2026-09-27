#include "../include.h"

void ActionValueStats::speedBuff(double spdPercent ,double flatSpd){
    double x = this->maxAtv;
    this->flatSpeed += flatSpd;
    this->speedPercent += spdPercent;
    updateMaxAtv(this);
    this->atv=this->atv/x*this->maxAtv;
}
bool ActionValueStats::isAlive(){
    return !charptr || charptr->isAlive();
}
bool ActionValueStats::isAtvChangeAble(){
    return !charptr || charptr->isAtvChangeAble();
}
void ActionValueStats::runTurn(){
    charptr->turnFunc();
}
bool compareActionValueStats(ActionValueStats* a, ActionValueStats* b) {
    return a->atv > b->atv; // Sort by `atv` in descending order
}
void updateMaxAtv(ActionValueStats *ptr) {
    if(ptr->baseSpeed<=0){
        ptr->maxAtv = 1e6;
        return;
    }
    ptr->maxAtv = K_CONST / (ptr->baseSpeed + ptr->baseSpeed * ptr->speedPercent/100 + ptr->flatSpeed);
    
}
void ActionValueStats::resetATV(){
    updateMaxAtv(this);
    resetTurn(this);
}
void ActionValueStats::resetATV(double baseSpeed){
    this->baseSpeed = baseSpeed;
    updateMaxAtv(this);
    resetTurn(this);
}
void resetTurn(ActionValueStats *ptr) {

    ptr->atv = ptr->maxAtv;
    
}
void allAtvReset() {
    for(auto &each : atvList){
        updateMaxAtv(each);
        resetTurn(each);
    }
}
void actionForward(ActionValueStats *ptr,double fwd) {
    if(ptr->baseSpeed<=0)return;
    if(!ptr->isAlive())return;
    if (ptr->atv <= ptr->maxAtv*fwd/100 ) {
        ptr->atv = 0;
        ptr->priority = ++nextForwardPriority;
        return ;
    } else {
        ptr->atv = ptr->atv - ptr->maxAtv*fwd/100;
        return ;
    }
}
void allActionForward(double fwd){
    vector<ActionValueStats*> vec;
    for(auto &each : allyList){
        vec.push_back(each->atvStats.get());
    }
    sort(vec.begin(),vec.end(),compareActionValueStats);
    for(int i=0;i<vec.size();i++){
        actionForward(vec[i],fwd);
    }
}
void findTurn(){
    pair<double,int> mx;
    turn = nullptr;
    mx.first = 1e9;
    mx.second = 0;

    for(auto &each : atvList){
        if(!each->isAtvChangeAble())continue;
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

void atvFix(double atvReduce){
    for(auto &each : atvList){
        if(!each->isAtvChangeAble())continue;
        each->atv -= atvReduce;
    }
    currentAtv+=atvReduce;
}
void ahaSpeedAdjust(Path &path){
    if(path != Path::ELATION)return;
    double factor = 5;
    double newFlatSpeed = 0;
    vector<double> elationSpd;
    for(auto &each : charList){
        if(each->path!=Path::ELATION)continue;
        elationSpd.push_back(calculateSpeedOnStats(each));
    }
    sort(elationSpd.begin(), elationSpd.end(), greater<double>());
    for(auto &each : elationSpd){
        newFlatSpeed += each/factor;
        factor += 5;
    }
    newFlatSpeed += ahaExtraFlatSpeed;
    aha->speedBuff(0,newFlatSpeed - aha->getFlatSpeed());
}
