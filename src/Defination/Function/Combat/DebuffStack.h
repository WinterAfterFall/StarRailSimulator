#include "../include.h"

pair<int,int> calDebuffStack(AllyUnit *ptr,Enemy *enemy,string debuffName,int Stack_increase,int StackLimit){
    allEventBeforeApplyDebuff(ptr, enemy);
    if (!enemy->getStack(debuffName)) enemy->addTotalDebuff(1);
    Stack_increase = (enemy->getStack(debuffName) + Stack_increase <= StackLimit) ? Stack_increase : StackLimit - enemy->getStack(debuffName);
    enemy->addStack(debuffName, Stack_increase);
    allEventAfterApplyDebuff(ptr, enemy);
    return {Stack_increase, enemy->getStack(debuffName)};
}
int debuffRemoveStack(Enemy *enemy,string debuffName){
    int ans = enemy->getStack(debuffName);
    enemy->setStack(debuffName,0);
    return ans;
}

void debuffStackRemove(Enemy *enemy,vector<BuffClass> debuffSet,string debuffName){
    int stack = debuffRemoveStack(enemy,debuffName);
    for(auto &e : debuffSet){
        e.value *= -stack;
    }
    debuffSingle(enemy,debuffSet);
}
void debuffStackRemove(Enemy *enemy,vector<BuffElementClass> debuffSet,string debuffName){
    int stack = debuffRemoveStack(enemy,debuffName);
    for(auto &e : debuffSet){
        e.value *= -stack;
    }
    debuffSingle(enemy,debuffSet);
}
void debuffStackSingle(AllyUnit *ptr,Enemy *enemy,vector<BuffClass> debuffSet, int Stack_increase, int Stack_limit, string Stack_Name) {
    int stack = calDebuffStack(ptr,enemy,Stack_Name,Stack_increase,Stack_limit).first;
    for(auto &e : debuffSet){
        e.value *= stack;
    }
    debuffSingle(enemy,debuffSet);
}
void debuffStackSingle(AllyUnit *ptr,Enemy *enemy,vector<BuffElementClass> debuffSet, int Stack_increase, int Stack_limit, string Stack_Name) {
    int stack = calDebuffStack(ptr,enemy,Stack_Name,Stack_increase,Stack_limit).first;
    for(auto &e : debuffSet){
        e.value *= stack;
    }
    debuffSingle(enemy,debuffSet);
}
void debuffStackSingle(AllyUnit *ptr,Enemy *enemy,vector<BuffClass> debuffSet, int Stack_increase, int Stack_limit, string Stack_Name,int extend) {
    int stack = calDebuffStack(ptr,enemy,Stack_Name,Stack_increase,Stack_limit).first;
    for(auto &e : debuffSet){
        e.value *= stack;
    }
    debuffSingle(enemy,debuffSet);
    extendDebuff(enemy,Stack_Name,extend);
}
void debuffStackSingle(AllyUnit *ptr,Enemy *enemy,vector<BuffElementClass> debuffSet, int Stack_increase, int Stack_limit, string Stack_Name,int extend) {
    int stack = calDebuffStack(ptr,enemy,Stack_Name,Stack_increase,Stack_limit).first;
    for(auto &e : debuffSet){
        e.value *= stack;
    }
    debuffSingle(enemy,debuffSet);
    extendDebuff(enemy,Stack_Name,extend);
}
void debuffStackAll(AllyUnit* ptr,vector<BuffClass> debuffSet,  int Stack_increase, int Stack_limit, string Stack_Name) {
    for (auto &each : enemyList) {
        debuffStackSingle(ptr,each,debuffSet,Stack_increase, Stack_limit, Stack_Name);
    }
}

void debuffStackAll(AllyUnit* ptr,vector<BuffElementClass> debuffSet,  int Stack_increase, int Stack_limit, string Stack_Name) {
    for (auto &each : enemyList) {
        debuffStackSingle(ptr,each,debuffSet,Stack_increase, Stack_limit, Stack_Name);
    }
}

void debuffStackAll(AllyUnit* ptr,vector<BuffClass> debuffSet,  int Stack_increase, int Stack_limit, string Stack_Name, int extend) {
    for (auto &each : enemyList) {
        debuffStackSingle(ptr,each,debuffSet,Stack_increase, Stack_limit, Stack_Name,extend);
    }
}

void debuffStackAll(AllyUnit* ptr,vector<BuffElementClass> debuffSet,  int Stack_increase, int Stack_limit, string Stack_Name, int extend) {
    for (auto &each : enemyList) {
        debuffStackSingle(ptr,each,debuffSet,Stack_increase, Stack_limit, Stack_Name,extend);
    }
}

void debuffStackEnemyTargets(AllyUnit* ptr,vector<Enemy*> targets, vector<BuffClass> debuffSet,  int Stack_increase, int Stack_limit, string Stack_Name) {
    for (auto* enemy : targets) {
        debuffStackSingle(ptr,enemy,debuffSet, Stack_increase, Stack_limit, Stack_Name);
    }
}

void debuffStackEnemyTargets(AllyUnit* ptr,vector<Enemy*> targets, vector<BuffElementClass> debuffSet,int Stack_increase, int Stack_limit, string Stack_Name) {
    for (auto* enemy : targets) {
        debuffStackSingle(ptr,enemy,debuffSet, Stack_increase, Stack_limit, Stack_Name);
    }
}

void debuffStackEnemyTargets(AllyUnit* ptr,vector<Enemy*> targets, vector<BuffClass> debuffSet,int Stack_increase, int Stack_limit, string Stack_Name, int extend) {
    for (auto* enemy : targets) {
        debuffStackSingle(ptr,enemy,debuffSet, Stack_increase, Stack_limit, Stack_Name,extend);
    }
}

void debuffStackEnemyTargets(AllyUnit* ptr,vector<Enemy*> targets, vector<BuffElementClass> debuffSet,int Stack_increase, int Stack_limit, string Stack_Name, int extend) {
    for (auto* enemy : targets) {
        debuffStackSingle(ptr,enemy,debuffSet, Stack_increase, Stack_limit, Stack_Name,extend);
    }
}
