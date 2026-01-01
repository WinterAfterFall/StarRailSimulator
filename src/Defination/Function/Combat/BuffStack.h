#include "../include.h"

//check if it is ally uni
pair<int,int> calStack(AllyUnit *ptr,int Stack_increase,int StackLimit,string buffName){
    Stack_increase = (ptr->getStack(buffName) + Stack_increase <= StackLimit) ? Stack_increase : StackLimit - ptr->getStack(buffName);
    ptr->addStack(buffName, Stack_increase);
    return {Stack_increase, ptr->getStack(buffName)};
}

//stack buff/debuff
void buffStackSingle(AllyUnit *ptr,vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name) {
    int stack = calStack(ptr,Stack_increase,Stack_limit,Stack_Name).first;
    for(auto &e : buffSet){
        e.value *= stack;
    }
    buffSingle(ptr,buffSet);
}
void buffStackSingle(AllyUnit *ptr,vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name,int extend) {
    int stack = calStack(ptr,Stack_increase,Stack_limit,Stack_Name).first;
    for(auto &e : buffSet){
        e.value *= stack;
    }
    extendBuffTime(ptr,Stack_Name,extend);
    buffSingle(ptr,buffSet);
}
void buffStackSingle(AllyUnit *ptr,vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name) {
    int stack = calStack(ptr,Stack_increase,Stack_limit,Stack_Name).first;
    for(auto &e : buffSet){
        e.value *= stack;
    }
    buffSingle(ptr,buffSet);
}
void buffStackSingle(AllyUnit *ptr,vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name,int extend) {
    int stack = calStack(ptr,Stack_increase,Stack_limit,Stack_Name).first;
    for(auto &e : buffSet){
        e.value *= stack;
    }
    extendBuffTime(ptr,Stack_Name,extend);
    buffSingle(ptr,buffSet);
}

void buffStackChar(CharUnit *ptr,vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name){
    buffStackSingle(ptr,buffSet,Stack_increase,Stack_limit,Stack_Name);
    for (auto &each : ptr->memospriteList) {
        buffStackSingle(ptr,buffSet,Stack_increase,Stack_limit,Stack_Name);
    }
}
void buffStackChar(CharUnit *ptr,vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name,int extend){
    buffStackSingle(ptr,buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
    for (auto &each : ptr->memospriteList) {
        buffStackSingle(ptr,buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
    }
}
void buffStackChar(CharUnit *ptr,vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name){
    buffStackSingle(ptr,buffSet,Stack_increase,Stack_limit,Stack_Name);
    for (auto &each : ptr->memospriteList) {
        buffStackSingle(ptr,buffSet,Stack_increase,Stack_limit,Stack_Name);
    }
}
void buffStackChar(CharUnit *ptr,vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name,int extend){
    buffStackSingle(ptr,buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
    for (auto &each : ptr->memospriteList) {
        buffStackSingle(ptr,buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
    }
}

void buffStackAllAlly(vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name){
    for (auto &each : allyList) {
        buffStackSingle(each,buffSet,Stack_increase,Stack_limit,Stack_Name);
    }
}
void buffStackAllAlly(vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name,int extend){
    for (auto &each : allyList) {
        buffStackSingle(each,buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
    }
}
void buffStackAllAlly(vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name){
    for (auto &each : allyList) {
        buffStackSingle(each,buffSet,Stack_increase,Stack_limit,Stack_Name);
    }
}
void buffStackAllAlly(vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name,int extend){
    for (auto &each : allyList) {
        buffStackSingle(each,buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
    }
}
//
void buffStackAllMemosprite(vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name){
    for (auto &each : charList) {
        for (auto &each2 : each->memospriteList) {
            buffStackSingle(each,buffSet,Stack_increase,Stack_limit,Stack_Name);
        }
    }
}
void buffStackAllMemosprite(vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name,int extend){
    for (auto &each : charList) {
        for (auto &each2 : each->memospriteList) {
            buffStackSingle(each,buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
        }
    }
}
void buffStackAllMemosprite(vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name){
    for (auto &each : charList) {
        for (auto &each2 : each->memospriteList) {
            buffStackSingle(each,buffSet,Stack_increase,Stack_limit,Stack_Name);
        }
    }
}
void buffStackAllMemosprite(vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name,int extend){
    for (auto &each : charList) {
        for (auto &each2 : each->memospriteList) {
            buffStackSingle(each,buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
        }
    }
}
//
void buffStackTargets(vector<AllyUnit*> targets, vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name){
    for (auto &each : targets) {
        buffStackSingle(each,buffSet,Stack_increase,Stack_limit,Stack_Name);
    }
}
void buffStackTargets(vector<AllyUnit*> targets,vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name, int extend){
    for (auto &each : targets) {
        buffStackSingle(each,buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
    }
}
void buffStackTargets(vector<AllyUnit*> targets,vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name){
    for (auto &each : targets) {
        buffStackSingle(each,buffSet,Stack_increase,Stack_limit,Stack_Name);
    }    
}
void buffStackTargets(vector<AllyUnit*> targets,vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name, int extend){
    for (auto &each : targets) {
        buffStackSingle(each,buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
    }
}

void buffStackExcludingBuffer(AllyUnit *ptr,vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name){
    for (auto &each : allyList) {
        if(ptr->isSameUnitName(each))continue;
        buffStackSingle(each,buffSet,Stack_increase,Stack_limit,Stack_Name);
    }
}
void buffStackExcludingBuffer(AllyUnit *ptr,vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name,int extend){
    for (auto &each : allyList) {
        if(ptr->isSameUnitName(each))continue;
        buffStackSingle(each,buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
    }
}
void buffStackExcludingBuffer(AllyUnit *ptr,vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name){
    for (auto &each : allyList) {
        if(ptr->isSameUnitName(each))continue;
        buffStackSingle(each,buffSet,Stack_increase,Stack_limit,Stack_Name);
    }
}
void buffStackExcludingBuffer(AllyUnit *ptr,vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name,int extend){
    for (auto &each : allyList) {
        if(ptr->isSameUnitName(each))continue;
        buffStackSingle(each,buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
    }
}
void buffStackExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> targets, vector<BuffClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name) {
    for (auto &each : targets) {
        if(ptr->isSameUnitName(each))continue;
        buffStackSingle(ptr,buffSet,Stack_increase,Stack_limit,Stack_Name);
    }
}
void buffStackExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> targets, vector<BuffClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name, int extend) {
    for (auto &each : targets) {
        if(ptr->isSameUnitName(each))continue;
        buffStackSingle(ptr,buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
    }
}
void buffStackExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> targets, vector<BuffElementClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name) {
    for (auto &each : targets) {
        if(ptr->isSameUnitName(each))continue;
        buffStackSingle(ptr,buffSet,Stack_increase,Stack_limit,Stack_Name);
    }
}
void buffStackExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> targets, vector<BuffElementClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name, int extend) {
    for (auto &each : targets) {
        if(ptr->isSameUnitName(each))continue;
        buffStackSingle(ptr,buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
    }
}

void buffResetStack(AllyUnit *ptr,vector<BuffClass> buffSet,string Stack_Name){
    for(auto &e : buffSet){
        e.value *= -ptr->getStack(Stack_Name);
    }
    ptr->setStack(Stack_Name,0);
    buffSingle(ptr,buffSet);
}
void buffResetStack(AllyUnit *ptr,vector<BuffElementClass> buffSet,string Stack_Name){
    for(auto &e : buffSet){
        e.value *= -ptr->getStack(Stack_Name);
    }
    ptr->setStack(Stack_Name,0);
    buffSingle(ptr,buffSet);
}
void buffResetStack(CharUnit *ptr,vector<BuffClass> buffSet,string Stack_Name){
    buffResetStack(ptr,buffSet,Stack_Name);
    for(auto &e : ptr->memospriteList){
        buffResetStack(e.get(),buffSet,Stack_Name);
    }
}
void buffResetStack(CharUnit *ptr,vector<BuffElementClass> buffSet,string Stack_Name){
    buffResetStack(ptr,buffSet,Stack_Name);
    for(auto &e : ptr->memospriteList){
        buffResetStack(e.get(),buffSet,Stack_Name);
    }
}
void buffResetStackAllAlly(vector<BuffClass> buffSet,string Stack_Name){
    for(auto &each : allyList){
        buffResetStack(each,buffSet,Stack_Name);
    }
}
void buffResetStackAllAlly(vector<BuffElementClass> buffSet,string Stack_Name){
    for(auto &each : allyList){
        buffResetStack(each,buffSet,Stack_Name);
    }
}