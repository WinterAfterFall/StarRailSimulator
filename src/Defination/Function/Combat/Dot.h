#include "../include.h"

void dotSingleApply(AllyUnit *ptr, Enemy *enemy ,vector<DotType> dotType,string dotName) {
    if(!debuffApply(ptr,enemy,dotName))return;
    for(auto &each : dotType) {
        enemy->changeDotType(each,1);
    }
}

void dotSingleApply(AllyUnit *ptr, Enemy *enemy ,vector<DotType> dotType,string dotName, int extend) {
    if(!debuffApply(ptr,enemy,dotName,extend))return;
    for(auto &each : dotType) {
        enemy->changeDotType(each,1);
    }
}

void dotSingleMark(AllyUnit *ptr, Enemy *enemy ,vector<DotType> dotType,string dotName) {
    if(!debuffMark(ptr,enemy,dotName))return;
    for(auto &each : dotType) {
        enemy->changeDotType(each,1);
    }
}

void dotSingleMark(AllyUnit *ptr, Enemy *enemy ,vector<DotType> dotType,string dotName, int extend) {
    if(!debuffMark(ptr,enemy,dotName,extend))return;
    for(auto &each : dotType) {
        enemy->changeDotType(each,1);
    }
}

void dotSingleStack(AllyUnit *ptr, Enemy *enemy ,vector<DotType> dotType,int Stack_increase, int Stack_limit, string dotName) {
    for(auto &each : dotType) {
        if(!enemy->getStack(dotName))enemy->changeDotType(each,1);
    }
    int stack = calDebuffStack(ptr,enemy,dotName,Stack_increase,Stack_limit).first;
}

void dotSingleStack(AllyUnit *ptr, Enemy *enemy,vector<DotType> dotType,int Stack_increase, int Stack_limit, string dotName, int extend) {
    for(auto &each : dotType) {
        if(!enemy->getStack(dotName))enemy->changeDotType(each,1);
    }
    int stack = calDebuffStack(ptr,enemy,dotName,Stack_increase,Stack_limit).first;
    extendDebuff(enemy,dotName,extend);
}

void dotAllEnemyApply(AllyUnit *ptr,vector<DotType> dotType,string dotName){
    for(auto &each : enemyList){
        dotSingleApply(ptr,each,dotType,dotName);
    }
}
void dotAllEnemyApply(AllyUnit *ptr,vector<DotType> dotType,string dotName,int extend){
    for(auto &each : enemyList){
        dotSingleApply(ptr,each,dotType,dotName,extend);
    }
}
void dotEnemyTargetsApply(AllyUnit *ptr,vector<Enemy*> targets, vector<DotType> dotType,string dotName) {
    for (auto &enemy : targets) {
        dotSingleApply(ptr,enemy,dotType, dotName);
    }
}
void dotEnemyTargetsApply(AllyUnit *ptr,vector<Enemy*> targets, vector<DotType> dotType,string dotName, int extend) {
    for (auto &enemy : targets) {
        dotSingleApply(ptr,enemy,dotType,dotName, extend);
    }
}

void dotAllEnemyMark(AllyUnit *ptr,vector<DotType> dotType,string dotName){
    for(auto &each : enemyList){
        dotSingleMark(ptr,each,dotType,dotName);
    }
}
void dotAllEnemyMark(AllyUnit *ptr,vector<DotType> dotType,string dotName,int extend){
    for(auto &each : enemyList){
        dotSingleMark(ptr,each,dotType,dotName,extend);
    }
}
void dotEnemyTargetsMark(AllyUnit *ptr,vector<Enemy*> targets,vector<DotType> dotType,string dotName){
    for (auto &enemy : targets) {
        dotSingleMark(ptr,enemy,dotType,dotName);
    }    
}
void dotEnemyTargetsMark(AllyUnit *ptr,vector<Enemy*> targets,vector<DotType> dotType,string dotName,int extend){
    for (auto &enemy : targets) {
        dotSingleMark(ptr,enemy,dotType,dotName, extend);
    }
}

void dotAllEnemyStack(AllyUnit *ptr,vector<DotType> dotType,int Stack_increase, int Stack_limit, string dotName){
    for(auto &each : enemyList){
        dotSingleStack(ptr,each,dotType,Stack_increase,Stack_limit,dotName);
    }
}
void dotAllEnemyStack(AllyUnit *ptr,vector<DotType> dotType,int Stack_increase, int Stack_limit, string dotName,int extend){
    for(auto &each : enemyList){
        dotSingleStack(ptr,each,dotType,Stack_increase,Stack_limit,dotName,extend);
    }
}
void dotEnemyTargetsStack(AllyUnit *ptr,vector<Enemy*> targets,vector<DotType> dotType,int Stack_increase, int Stack_limit, string dotName){
    for (auto &enemy : targets) {
        dotSingleStack(ptr,enemy,dotType,Stack_increase,Stack_limit,dotName);
    }
}
void dotEnemyTargetsStack(AllyUnit *ptr,vector<Enemy*> targets,vector<DotType> dotType,int Stack_increase, int Stack_limit, string dotName,int extend){
    for (auto &enemy : targets) {
        dotSingleStack(ptr,enemy,dotType,Stack_increase,Stack_limit,dotName);
    }
}

void dotRemove(Enemy *enemy,vector<DotType> dotType) {
    for(auto &each : dotType) {
        enemy->changeDotType(each,-1);
    }
}
int dotStackRemove(Enemy *enemy,vector<DotType> dotType, string dotName) {
    int stack = debuffRemoveStack(enemy,dotName);
    for(auto &each : dotType) {
        enemy->changeDotType(each,-1);
    }
    return stack;
}