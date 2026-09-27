#include "../include.h"

pair<int,int> calDebuffStack(AllyUnit *ptr,Enemy *enemy,string debuffName,int stackIncrease,int stackLimit){
    allEventBeforeApplyDebuff(ptr, enemy);
    int current = enemy->getStack(debuffName);
    int next = min(stackLimit, max(0, current + stackIncrease));
    int applied = next - current;
    if (current == 0 && next > 0) enemy->addTotalDebuff(1);
    else if (current > 0 && next == 0) enemy->addTotalDebuff(-1);
    enemy->addStack(debuffName, applied);
    allEventAfterApplyDebuff(ptr, enemy);
    return {applied, next};
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
void debuffStackSingle(AllyUnit *ptr,Enemy *enemy,vector<BuffClass> debuffSet, int stackIncrease, int stackLimit, string stackName) {
    int stack = calDebuffStack(ptr,enemy,stackName,stackIncrease,stackLimit).first;
    for(auto &e : debuffSet){
        e.value *= stack;
    }
    debuffSingle(enemy,debuffSet);
}
void debuffStackSingle(AllyUnit *ptr,Enemy *enemy,vector<BuffElementClass> debuffSet, int stackIncrease, int stackLimit, string stackName) {
    int stack = calDebuffStack(ptr,enemy,stackName,stackIncrease,stackLimit).first;
    for(auto &e : debuffSet){
        e.value *= stack;
    }
    debuffSingle(enemy,debuffSet);
}
void debuffStackSingle(AllyUnit *ptr,Enemy *enemy,vector<BuffClass> debuffSet, int stackIncrease, int stackLimit, string stackName,int extend) {
    int stack = calDebuffStack(ptr,enemy,stackName,stackIncrease,stackLimit).first;
    for(auto &e : debuffSet){
        e.value *= stack;
    }
    debuffSingle(enemy,debuffSet);
    extendDebuff(enemy,stackName,extend);
}
void debuffStackSingle(AllyUnit *ptr,Enemy *enemy,vector<BuffElementClass> debuffSet, int stackIncrease, int stackLimit, string stackName,int extend) {
    int stack = calDebuffStack(ptr,enemy,stackName,stackIncrease,stackLimit).first;
    for(auto &e : debuffSet){
        e.value *= stack;
    }
    debuffSingle(enemy,debuffSet);
    extendDebuff(enemy,stackName,extend);
}
void debuffStackAll(AllyUnit* ptr,vector<BuffClass> debuffSet,  int stackIncrease, int stackLimit, string stackName) {
    for (auto &each : enemyList) {
        debuffStackSingle(ptr,each,debuffSet,stackIncrease, stackLimit, stackName);
    }
}

void debuffStackAll(AllyUnit* ptr,vector<BuffElementClass> debuffSet,  int stackIncrease, int stackLimit, string stackName) {
    for (auto &each : enemyList) {
        debuffStackSingle(ptr,each,debuffSet,stackIncrease, stackLimit, stackName);
    }
}

void debuffStackAll(AllyUnit* ptr,vector<BuffClass> debuffSet,  int stackIncrease, int stackLimit, string stackName, int extend) {
    for (auto &each : enemyList) {
        debuffStackSingle(ptr,each,debuffSet,stackIncrease, stackLimit, stackName,extend);
    }
}

void debuffStackAll(AllyUnit* ptr,vector<BuffElementClass> debuffSet,  int stackIncrease, int stackLimit, string stackName, int extend) {
    for (auto &each : enemyList) {
        debuffStackSingle(ptr,each,debuffSet,stackIncrease, stackLimit, stackName,extend);
    }
}

void debuffStackEnemyTargets(AllyUnit* ptr,vector<Enemy*> targets, vector<BuffClass> debuffSet,  int stackIncrease, int stackLimit, string stackName) {
    for (auto* enemy : targets) {
        debuffStackSingle(ptr,enemy,debuffSet, stackIncrease, stackLimit, stackName);
    }
}

void debuffStackEnemyTargets(AllyUnit* ptr,vector<Enemy*> targets, vector<BuffElementClass> debuffSet,int stackIncrease, int stackLimit, string stackName) {
    for (auto* enemy : targets) {
        debuffStackSingle(ptr,enemy,debuffSet, stackIncrease, stackLimit, stackName);
    }
}

void debuffStackEnemyTargets(AllyUnit* ptr,vector<Enemy*> targets, vector<BuffClass> debuffSet,int stackIncrease, int stackLimit, string stackName, int extend) {
    for (auto* enemy : targets) {
        debuffStackSingle(ptr,enemy,debuffSet, stackIncrease, stackLimit, stackName,extend);
    }
}

void debuffStackEnemyTargets(AllyUnit* ptr,vector<Enemy*> targets, vector<BuffElementClass> debuffSet,int stackIncrease, int stackLimit, string stackName, int extend) {
    for (auto* enemy : targets) {
        debuffStackSingle(ptr,enemy,debuffSet, stackIncrease, stackLimit, stackName,extend);
    }
}
