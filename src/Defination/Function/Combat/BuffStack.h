#include "../include.h"

//check if it is ally uni
pair<int,int> calStack(AllyUnit *ptr,int stackIncrease,int stackLimit,string buffName){
    int current = ptr->getStack(buffName);
    int next = min(stackLimit, max(0, current + stackIncrease));
    int applied = next - current;
    ptr->addStack(buffName, applied);
    return {applied, next};
}

//stack buff/debuff
void buffStackSingle(AllyUnit *ptr,vector<BuffClass> buffSet , int stackIncrease, int stackLimit, string stackName) {
    int stack = calStack(ptr,stackIncrease,stackLimit,stackName).first;
    for(auto &e : buffSet){
        e.value *= stack;
    }
    buffSingle(ptr,buffSet);
}
void buffStackSingle(AllyUnit *ptr,vector<BuffClass> buffSet , int stackIncrease, int stackLimit, string stackName,int extend) {
    int stack = calStack(ptr,stackIncrease,stackLimit,stackName).first;
    for(auto &e : buffSet){
        e.value *= stack;
    }
    extendBuffTime(ptr,stackName,extend);
    buffSingle(ptr,buffSet);
}
void buffStackSingle(AllyUnit *ptr,vector<BuffElementClass> buffSet , int stackIncrease, int stackLimit, string stackName) {
    int stack = calStack(ptr,stackIncrease,stackLimit,stackName).first;
    for(auto &e : buffSet){
        e.value *= stack;
    }
    buffSingle(ptr,buffSet);
}
void buffStackSingle(AllyUnit *ptr,vector<BuffElementClass> buffSet , int stackIncrease, int stackLimit, string stackName,int extend) {
    int stack = calStack(ptr,stackIncrease,stackLimit,stackName).first;
    for(auto &e : buffSet){
        e.value *= stack;
    }
    extendBuffTime(ptr,stackName,extend);
    buffSingle(ptr,buffSet);
}

void buffStackChar(CharUnit *ptr,vector<BuffClass> buffSet , int stackIncrease, int stackLimit, string stackName){
    buffStackSingle(ptr,buffSet,stackIncrease,stackLimit,stackName);
    if(auto *each = ptr->memosprite.get()){
        buffStackSingle(each,buffSet,stackIncrease,stackLimit,stackName);
    }
}
void buffStackChar(CharUnit *ptr,vector<BuffClass> buffSet , int stackIncrease, int stackLimit, string stackName,int extend){
    buffStackSingle(ptr,buffSet,stackIncrease,stackLimit,stackName,extend);
    if(auto *each = ptr->memosprite.get()){
        buffStackSingle(each,buffSet,stackIncrease,stackLimit,stackName,extend);
    }
}
void buffStackChar(CharUnit *ptr,vector<BuffElementClass> buffSet , int stackIncrease, int stackLimit, string stackName){
    buffStackSingle(ptr,buffSet,stackIncrease,stackLimit,stackName);
    if(auto *each = ptr->memosprite.get()){
        buffStackSingle(each,buffSet,stackIncrease,stackLimit,stackName);
    }
}
void buffStackChar(CharUnit *ptr,vector<BuffElementClass> buffSet , int stackIncrease, int stackLimit, string stackName,int extend){
    buffStackSingle(ptr,buffSet,stackIncrease,stackLimit,stackName,extend);
    if(auto *each = ptr->memosprite.get()){
        buffStackSingle(each,buffSet,stackIncrease,stackLimit,stackName,extend);
    }
}

void buffStackAllAlly(vector<BuffClass> buffSet , int stackIncrease, int stackLimit, string stackName){
    for (auto &each : allyList) {
        buffStackSingle(each,buffSet,stackIncrease,stackLimit,stackName);
    }
}
void buffStackAllAlly(vector<BuffClass> buffSet , int stackIncrease, int stackLimit, string stackName,int extend){
    for (auto &each : allyList) {
        buffStackSingle(each,buffSet,stackIncrease,stackLimit,stackName,extend);
    }
}
void buffStackAllAlly(vector<BuffElementClass> buffSet , int stackIncrease, int stackLimit, string stackName){
    for (auto &each : allyList) {
        buffStackSingle(each,buffSet,stackIncrease,stackLimit,stackName);
    }
}
void buffStackAllAlly(vector<BuffElementClass> buffSet , int stackIncrease, int stackLimit, string stackName,int extend){
    for (auto &each : allyList) {
        buffStackSingle(each,buffSet,stackIncrease,stackLimit,stackName,extend);
    }
}
//
void buffStackAllMemosprite(vector<BuffClass> buffSet , int stackIncrease, int stackLimit, string stackName){
    for (auto &each : charList) {
        if(auto *each2 = each->memosprite.get()){
            buffStackSingle(each2,buffSet,stackIncrease,stackLimit,stackName);
        }
    }
}
void buffStackAllMemosprite(vector<BuffClass> buffSet , int stackIncrease, int stackLimit, string stackName,int extend){
    for (auto &each : charList) {
        if(auto *each2 = each->memosprite.get()){
            buffStackSingle(each2,buffSet,stackIncrease,stackLimit,stackName,extend);
        }
    }
}
void buffStackAllMemosprite(vector<BuffElementClass> buffSet , int stackIncrease, int stackLimit, string stackName){
    for (auto &each : charList) {
        if(auto *each2 = each->memosprite.get()){
            buffStackSingle(each2,buffSet,stackIncrease,stackLimit,stackName);
        }
    }
}
void buffStackAllMemosprite(vector<BuffElementClass> buffSet , int stackIncrease, int stackLimit, string stackName,int extend){
    for (auto &each : charList) {
        if(auto *each2 = each->memosprite.get()){
            buffStackSingle(each2,buffSet,stackIncrease,stackLimit,stackName,extend);
        }
    }
}
//
void buffStackTargets(vector<AllyUnit*> targets, vector<BuffClass> buffSet , int stackIncrease, int stackLimit, string stackName){
    for (auto &each : targets) {
        buffStackSingle(each,buffSet,stackIncrease,stackLimit,stackName);
    }
}
void buffStackTargets(vector<AllyUnit*> targets,vector<BuffClass> buffSet , int stackIncrease, int stackLimit, string stackName, int extend){
    for (auto &each : targets) {
        buffStackSingle(each,buffSet,stackIncrease,stackLimit,stackName,extend);
    }
}
void buffStackTargets(vector<AllyUnit*> targets,vector<BuffElementClass> buffSet , int stackIncrease, int stackLimit, string stackName){
    for (auto &each : targets) {
        buffStackSingle(each,buffSet,stackIncrease,stackLimit,stackName);
    }    
}
void buffStackTargets(vector<AllyUnit*> targets,vector<BuffElementClass> buffSet , int stackIncrease, int stackLimit, string stackName, int extend){
    for (auto &each : targets) {
        buffStackSingle(each,buffSet,stackIncrease,stackLimit,stackName,extend);
    }
}

void buffStackExcludingBuffer(AllyUnit *ptr,vector<BuffClass> buffSet , int stackIncrease, int stackLimit, string stackName){
    for (auto &each : allyList) {
        if(ptr->isSameName(each))continue;
        buffStackSingle(each,buffSet,stackIncrease,stackLimit,stackName);
    }
}
void buffStackExcludingBuffer(AllyUnit *ptr,vector<BuffClass> buffSet , int stackIncrease, int stackLimit, string stackName,int extend){
    for (auto &each : allyList) {
        if(ptr->isSameName(each))continue;
        buffStackSingle(each,buffSet,stackIncrease,stackLimit,stackName,extend);
    }
}
void buffStackExcludingBuffer(AllyUnit *ptr,vector<BuffElementClass> buffSet , int stackIncrease, int stackLimit, string stackName){
    for (auto &each : allyList) {
        if(ptr->isSameName(each))continue;
        buffStackSingle(each,buffSet,stackIncrease,stackLimit,stackName);
    }
}
void buffStackExcludingBuffer(AllyUnit *ptr,vector<BuffElementClass> buffSet , int stackIncrease, int stackLimit, string stackName,int extend){
    for (auto &each : allyList) {
        if(ptr->isSameName(each))continue;
        buffStackSingle(each,buffSet,stackIncrease,stackLimit,stackName,extend);
    }
}
void buffStackExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> targets, vector<BuffClass> buffSet, int stackIncrease, int stackLimit, string stackName) {
    for (auto &each : targets) {
        if(ptr->isSameName(each))continue;
        buffStackSingle(each,buffSet,stackIncrease,stackLimit,stackName);
    }
}
void buffStackExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> targets, vector<BuffClass> buffSet, int stackIncrease, int stackLimit, string stackName, int extend) {
    for (auto &each : targets) {
        if(ptr->isSameName(each))continue;
        buffStackSingle(each,buffSet,stackIncrease,stackLimit,stackName,extend);
    }
}
void buffStackExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> targets, vector<BuffElementClass> buffSet, int stackIncrease, int stackLimit, string stackName) {
    for (auto &each : targets) {
        if(ptr->isSameName(each))continue;
        buffStackSingle(each,buffSet,stackIncrease,stackLimit,stackName);
    }
}
void buffStackExcludingBuffer(AllyUnit *ptr,vector<AllyUnit*> targets, vector<BuffElementClass> buffSet, int stackIncrease, int stackLimit, string stackName, int extend) {
    for (auto &each : targets) {
        if(ptr->isSameName(each))continue;
        buffStackSingle(each,buffSet,stackIncrease,stackLimit,stackName,extend);
    }
}

void buffResetStack(AllyUnit *ptr,vector<BuffClass> buffSet,string stackName){
    for(auto &e : buffSet){
        e.value *= -ptr->getStack(stackName);
    }
    ptr->setStack(stackName,0);
    buffSingle(ptr,buffSet);
}
void buffResetStack(AllyUnit *ptr,vector<BuffElementClass> buffSet,string stackName){
    for(auto &e : buffSet){
        e.value *= -ptr->getStack(stackName);
    }
    ptr->setStack(stackName,0);
    buffSingle(ptr,buffSet);
}
void buffCharResetStack(CharUnit *ptr,vector<BuffClass> buffSet,string stackName){
    buffResetStack(ptr,buffSet,stackName);
    if(auto *e = ptr->memosprite.get()){
        buffResetStack(e,buffSet,stackName);
    }
}
void buffCharResetStack(CharUnit *ptr,vector<BuffElementClass> buffSet,string stackName){
    buffResetStack(ptr,buffSet,stackName);
    if(auto *e = ptr->memosprite.get()){
        buffResetStack(e,buffSet,stackName);
    }
}
void buffResetStackAllAlly(vector<BuffClass> buffSet,string stackName){
    for(auto &each : allyList){
        buffResetStack(each,buffSet,stackName);
    }
}
void buffResetStackAllAlly(vector<BuffElementClass> buffSet,string stackName){
    for(auto &each : allyList){
        buffResetStack(each,buffSet,stackName);
    }
}
