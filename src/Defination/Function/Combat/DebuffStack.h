#include "../include.h"

pair<int,int> Enemy::calDebuffStack(SubUnit *ptr,string debuffName,int Stack_increase,int StackLimit){
    allEventBeforeApplyDebuff(ptr, this);
    if (!this->getStack(debuffName)) this->addTotalDebuff(1);
    Stack_increase = (this->getStack(debuffName) + Stack_increase <= StackLimit) ? Stack_increase : StackLimit - this->getStack(debuffName);
    this->addStack(debuffName, Stack_increase);
    allEventAfterApplyDebuff(ptr, this);
    return {Stack_increase, this->getStack(debuffName)};
}
int Enemy::debuffRemoveStack(string debuffName){
    int ans = this->getStack(debuffName);
    this->setStack(debuffName,0);
    return ans;
}

void Enemy::debuffStackRemove(vector<BuffClass> debuffSet,string debuffName){
    int stack = this->debuffRemoveStack(debuffName);
    for(auto &e : debuffSet){
        e.value *= -stack;
    }
    this->debuffSingle(debuffSet);
}
void Enemy::debuffStackRemove(vector<BuffElementClass> debuffSet,string debuffName){
    int stack = this->debuffRemoveStack(debuffName);
    for(auto &e : debuffSet){
        e.value *= -stack;
    }
    this->debuffSingle(debuffSet);
}
void Enemy::debuffStackSingle(vector<BuffClass> debuffSet,SubUnit *ptr, int Stack_increase, int Stack_limit, string Stack_Name) {
    int stack = this->calDebuffStack(ptr,Stack_Name,Stack_increase,Stack_limit).first;
    for(auto &e : debuffSet){
        e.value *= stack;
    }
    this->debuffSingle(debuffSet);
}
void Enemy::debuffStackSingle(vector<BuffElementClass> debuffSet,SubUnit *ptr, int Stack_increase, int Stack_limit, string Stack_Name) {
    int stack = this->calDebuffStack(ptr,Stack_Name,Stack_increase,Stack_limit).first;
    for(auto &e : debuffSet){
        e.value *= stack;
    }
    this->debuffSingle(debuffSet);
}
void Enemy::debuffStackSingle(vector<BuffClass> debuffSet,SubUnit *ptr, int Stack_increase, int Stack_limit, string Stack_Name,int extend) {
    int stack = this->calDebuffStack(ptr,Stack_Name,Stack_increase,Stack_limit).first;
    for(auto &e : debuffSet){
        e.value *= stack;
    }
    this->debuffSingle(debuffSet);
    this->extendDebuff(Stack_Name,extend);
}
void Enemy::debuffStackSingle(vector<BuffElementClass> debuffSet,SubUnit *ptr, int Stack_increase, int Stack_limit, string Stack_Name,int extend) {
    int stack = this->calDebuffStack(ptr,Stack_Name,Stack_increase,Stack_limit).first;
    for(auto &e : debuffSet){
        e.value *= stack;
    }
    this->debuffSingle(debuffSet);
    this->extendDebuff(Stack_Name,extend);
}
void debuffStackAll(vector<BuffClass> debuffSet, SubUnit* ptr, int Stack_increase, int Stack_limit, string Stack_Name) {
    for (int i = 1; i <= Total_enemy; i++) {
        Enemy_unit[i]->debuffStackSingle(debuffSet, ptr, Stack_increase, Stack_limit, Stack_Name);
    }
}

void debuffStackAll(vector<BuffElementClass> debuffSet, SubUnit* ptr, int Stack_increase, int Stack_limit, string Stack_Name) {
    for (int i = 1; i <= Total_enemy; i++) {
        Enemy_unit[i]->debuffStackSingle(debuffSet, ptr, Stack_increase, Stack_limit, Stack_Name);
    }
}

void debuffStackAll(vector<BuffClass> debuffSet, SubUnit* ptr, int Stack_increase, int Stack_limit, string Stack_Name, int extend) {
    for (int i = 1; i <= Total_enemy; i++) {
        Enemy_unit[i]->debuffStackSingle(debuffSet, ptr, Stack_increase, Stack_limit, Stack_Name, extend);
    }
}

void debuffStackAll(vector<BuffElementClass> debuffSet, SubUnit* ptr, int Stack_increase, int Stack_limit, string Stack_Name, int extend) {
    for (int i = 1; i <= Total_enemy; i++) {
        Enemy_unit[i]->debuffStackSingle(debuffSet, ptr, Stack_increase, Stack_limit, Stack_Name, extend);
    }
}

