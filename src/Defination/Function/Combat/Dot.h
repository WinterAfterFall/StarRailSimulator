#include "../include.h"

void Enemy::dotSingleApply(vector<DotType> dotType, SubUnit *ptr, string dotName) {
    if(!this->debuffApply(ptr,dotName))return;
    for(auto &each : dotType) {
        this->changeDotType(each,1);
    }
}

void Enemy::dotSingleApply(vector<DotType> dotType, SubUnit *ptr, string dotName, int extend) {
    if(!this->debuffApply(ptr,dotName,extend))return;
    for(auto &each : dotType) {
        this->changeDotType(each,1);
    }
}

void Enemy::dotSingleMark(vector<DotType> dotType, SubUnit *ptr, string dotName) {
    if(!this->debuffMark(ptr,dotName))return;
    for(auto &each : dotType) {
        this->changeDotType(each,1);
    }
}

void Enemy::dotSingleMark(vector<DotType> dotType, SubUnit *ptr, string dotName, int extend) {
    if(!this->debuffMark(ptr,dotName,extend))return;
    for(auto &each : dotType) {
        this->changeDotType(each,1);
    }
}

void Enemy::dotSingleStack(vector<DotType> dotType, SubUnit *ptr, int Stack_increase, int Stack_limit, string dotName) {
    for(auto &each : dotType) {
        if(!this->getStack(dotName))this->changeDotType(each,1);
    }
    int stack = this->calDebuffStack(ptr,dotName,Stack_increase,Stack_limit).first;
}

void Enemy::dotSingleStack(vector<DotType> dotType, SubUnit *ptr, int Stack_increase, int Stack_limit, string dotName, int extend) {
    for(auto &each : dotType) {
        if(!this->getStack(dotName))this->changeDotType(each,1);
    }
    int stack = this->calDebuffStack(ptr,dotName,Stack_increase,Stack_limit).first;
    this->extendDebuff(dotName,extend);
}

void dotAllEnemyApply(vector<DotType> dotType, SubUnit *ptr, string dotName){
    for(int i =1 ;i<=Total_enemy;i++){
        Enemy_unit[i]->dotSingleApply(dotType,ptr,dotName);
    }
}
void dotAllEnemyApply(vector<DotType> dotType, SubUnit *ptr, string dotName,int extend){
    for(int i =1 ;i<=Total_enemy;i++){
        Enemy_unit[i]->dotSingleApply(dotType,ptr,dotName,extend);
    }
}
void dotEnemyTargetsApply(vector<Enemy*> targets, vector<DotType> dotType, SubUnit *ptr, string dotName) {
    for (auto &enemy : targets) {
        enemy->dotSingleApply(dotType, ptr, dotName);
    }
}
void dotEnemyTargetsApply(vector<Enemy*> targets, vector<DotType> dotType, SubUnit *ptr, string dotName, int extend) {
    for (auto &enemy : targets) {
        enemy->dotSingleApply(dotType, ptr, dotName, extend);
    }
}

void dotAllEnemyMark(vector<DotType> dotType, SubUnit *ptr, string dotName){
    for(int i =1 ;i<=Total_enemy;i++){
        Enemy_unit[i]->dotSingleMark(dotType,ptr,dotName);
    }
}
void dotAllEnemyMark(vector<DotType> dotType, SubUnit *ptr, string dotName,int extend){
    for(int i =1 ;i<=Total_enemy;i++){
        Enemy_unit[i]->dotSingleMark(dotType,ptr,dotName,extend);
    }
}
void dotEnemyTargetsMark(vector<Enemy*> targets,vector<DotType> dotType, SubUnit *ptr, string dotName){
    for (auto &enemy : targets) {
        enemy->dotSingleMark(dotType, ptr, dotName);
    }    
}
void dotEnemyTargetsMark(vector<Enemy*> targets,vector<DotType> dotType, SubUnit *ptr, string dotName,int extend){
    for (auto &enemy : targets) {
        enemy->dotSingleMark(dotType, ptr, dotName, extend);
    }
}

void dotAllEnemyStack(vector<DotType> dotType, SubUnit *ptr, int Stack_increase, int Stack_limit, string dotName){
    for(int i =1 ;i<=Total_enemy;i++){
        Enemy_unit[i]->dotSingleStack(dotType,ptr,Stack_increase,Stack_limit,dotName);
    }
}
void dotAllEnemyStack(vector<DotType> dotType, SubUnit *ptr, int Stack_increase, int Stack_limit, string dotName,int extend){
    for(int i =1 ;i<=Total_enemy;i++){
        Enemy_unit[i]->dotSingleStack(dotType,ptr,Stack_increase,Stack_limit,dotName,extend);
    }
}
void dotEnemyTargetsStack(vector<Enemy*> targets,vector<DotType> dotType, SubUnit *ptr, int Stack_increase, int Stack_limit, string dotName){
    for (auto &enemy : targets) {
        enemy->dotSingleStack(dotType,ptr,Stack_increase,Stack_limit,dotName);
    }
}
void dotEnemyTargetsStack(vector<Enemy*> targets,vector<DotType> dotType, SubUnit *ptr, int Stack_increase, int Stack_limit, string dotName,int extend){
    for (auto &enemy : targets) {
        enemy->dotSingleStack(dotType,ptr,Stack_increase,Stack_limit,dotName);
    }
}

void Enemy::dotRemove(vector<DotType> dotType) {
    for(auto &each : dotType) {
        this->changeDotType(each,-1);
    }
}
int Enemy::dotStackRemove(vector<DotType> dotType, string dotName) {
    int stack = this->debuffRemoveStack(dotName);
    for(auto &each : dotType) {
        this->changeDotType(each,-1);
    }
    return stack;
}