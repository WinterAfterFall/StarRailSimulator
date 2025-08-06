#include "../include.h"

//check if it is ally uni
pair<int,int> SubUnit::calStack(int Stack_increase,int StackLimit,string buffName){
    Stack_increase = (this->getStack(buffName) + Stack_increase <= StackLimit) ? Stack_increase : StackLimit - this->getStack(buffName);
    this->addStack(buffName, Stack_increase);
    return {Stack_increase, this->getStack(buffName)};
}
//stack buff/debuff
void SubUnit::buffStackSingle(vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name) {
    int stack = this->calStack(Stack_increase,Stack_limit,Stack_Name).first;
    for(auto &e : buffSet){
        e.value *= stack;
    }
    this->buffSingle(buffSet);
}
void SubUnit::buffStackSingle(vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name,int extend) {
    int stack = this->calStack(Stack_increase,Stack_limit,Stack_Name).first;
    for(auto &e : buffSet){
        e.value *= stack;
    }
    this->extendBuffTime(Stack_Name,extend);
    this->buffSingle(buffSet);
}
void SubUnit::buffStackSingle(vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name) {
    int stack = this->calStack(Stack_increase,Stack_limit,Stack_Name).first;
    for(auto &e : buffSet){
        e.value *= stack;
    }
    this->buffSingle(buffSet);
}
void SubUnit::buffStackSingle(vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name,int extend) {
    int stack = this->calStack(Stack_increase,Stack_limit,Stack_Name).first;
    for(auto &e : buffSet){
        e.value *= stack;
    }
    this->extendBuffTime(Stack_Name,extend);
    this->buffSingle(buffSet);
}

void Ally::buffStackAlly(vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name){
    for (auto &each : this->Sub_Unit_ptr) {
        each->buffStackSingle(buffSet,Stack_increase,Stack_limit,Stack_Name);
    }
}
void Ally::buffStackAlly(vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name,int extend){
    for (auto &each : this->Sub_Unit_ptr) {
        each->buffStackSingle(buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
    }
}
void Ally::buffStackAlly(vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name){
    for (auto &each : this->Sub_Unit_ptr) {
        each->buffStackSingle(buffSet,Stack_increase,Stack_limit,Stack_Name);
    }
}
void Ally::buffStackAlly(vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name,int extend){
    for (auto &each : this->Sub_Unit_ptr) {
        each->buffStackSingle(buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
    }
}

void buffStackAllAlly(vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name){
    for (int i = 1; i <= Total_ally; i++) {
        for (auto &each : Ally_unit[i]->Sub_Unit_ptr) {
            each->buffStackSingle(buffSet,Stack_increase,Stack_limit,Stack_Name);
        }
    }
}
void buffStackAllAlly(vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name,int extend){
    for (int i = 1; i <= Total_ally; i++) {
        for (auto &each : Ally_unit[i]->Sub_Unit_ptr) {
            each->buffStackSingle(buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
        }
    }
}
void buffStackAllAlly(vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name){
    for (int i = 1; i <= Total_ally; i++) {
        for (auto &each : Ally_unit[i]->Sub_Unit_ptr) {
            each->buffStackSingle(buffSet,Stack_increase,Stack_limit,Stack_Name);
        }
    }
}
void buffStackAllAlly(vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name,int extend){
    for (int i = 1; i <= Total_ally; i++) {
        for (auto &each : Ally_unit[i]->Sub_Unit_ptr) {
            each->buffStackSingle(buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
        }
    }
}
void buffStackTargets(vector<SubUnit*> targets, vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name){
    for (auto &each : targets) {
            each->buffStackSingle(buffSet,Stack_increase,Stack_limit,Stack_Name);
    }
}
void buffStackTargets(vector<SubUnit*> targets,vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name, int extend){
    for (auto &each : targets) {
        each->buffStackSingle(buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
    }
}
void buffStackTargets(vector<SubUnit*> targets,vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name){
    for (auto &each : targets) {
        each->buffStackSingle(buffSet,Stack_increase,Stack_limit,Stack_Name);
    }    
}
void buffStackTargets(vector<SubUnit*> targets,vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name, int extend){
    for (auto &each : targets) {
        each->buffStackSingle(buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
    }
}

void SubUnit::buffStackExcludingBuffer(vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name){
    for (int i = 1; i <= Total_ally; i++) {
        for (auto &each : Ally_unit[i]->Sub_Unit_ptr) {
            if(this->isSameChar(each.get()))continue;
            each->buffStackSingle(buffSet,Stack_increase,Stack_limit,Stack_Name);
        }
    }
}
void SubUnit::buffStackExcludingBuffer(vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name,int extend){
    for (int i = 1; i <= Total_ally; i++) {
        for (auto &each : Ally_unit[i]->Sub_Unit_ptr) {
            if(this->isSameChar(each.get()))continue;
            each->buffStackSingle(buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
        }
    }
}
void SubUnit::buffStackExcludingBuffer(vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name){
    for (int i = 1; i <= Total_ally; i++) {
        for (auto &each : Ally_unit[i]->Sub_Unit_ptr) {
            if(this->isSameChar(each.get()))continue;
            each->buffStackSingle(buffSet,Stack_increase,Stack_limit,Stack_Name);
        }
    }
}
void SubUnit::buffStackExcludingBuffer(vector<BuffElementClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name,int extend){
    for (int i = 1; i <= Total_ally; i++) {
        for (auto &each : Ally_unit[i]->Sub_Unit_ptr) {
            if(this->isSameChar(each.get()))continue;
            each->buffStackSingle(buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
        }
    }
}
void SubUnit::buffStackExcludingBuffer(vector<SubUnit*> targets, vector<BuffClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name) {
    for (auto &each : targets) {
        if(this->isSameChar(each))continue;
        each->buffStackSingle(buffSet,Stack_increase,Stack_limit,Stack_Name);
    }
}
void SubUnit::buffStackExcludingBuffer(vector<SubUnit*> targets, vector<BuffClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name, int extend) {
    for (auto &each : targets) {
        if(this->isSameChar(each))continue;
        each->buffStackSingle(buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
    }
}
void SubUnit::buffStackExcludingBuffer(vector<SubUnit*> targets, vector<BuffElementClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name) {
    for (auto &each : targets) {
        if(this->isSameChar(each))continue;
        each->buffStackSingle(buffSet,Stack_increase,Stack_limit,Stack_Name);
    }
}
void SubUnit::buffStackExcludingBuffer(vector<SubUnit*> targets, vector<BuffElementClass> buffSet, int Stack_increase, int Stack_limit, string Stack_Name, int extend) {
    for (auto &each : targets) {
        if(this->isSameChar(each))continue;
        each->buffStackSingle(buffSet,Stack_increase,Stack_limit,Stack_Name,extend);
    }
}

void SubUnit::buffResetStack(vector<BuffClass> buffSet,string Stack_Name){
    for(auto &e : buffSet){
        e.value *= -this->getStack(Stack_Name);
    }
    this->setStack(Stack_Name,0);
    this->buffSingle(buffSet);
}
void SubUnit::buffResetStack(vector<BuffElementClass> buffSet,string Stack_Name){
    for(auto &e : buffSet){
        e.value *= -this->getStack(Stack_Name);
    }
    this->setStack(Stack_Name,0);
    this->buffSingle(buffSet);
}
void Ally::buffResetStack(vector<BuffClass> buffSet,string Stack_Name){
    for(auto &e : this->Sub_Unit_ptr){
        e->buffResetStack(buffSet,Stack_Name);
    }
}
void Ally::buffResetStack(vector<BuffElementClass> buffSet,string Stack_Name){
    for(auto &e : this->Sub_Unit_ptr){
        e->buffResetStack(buffSet,Stack_Name);
    }
}
void buffResetStackAllAlly(vector<BuffClass> buffSet,string Stack_Name){
    for (int i = 1; i <= Total_ally; i++) {
        for (auto &each : Ally_unit[i]->Sub_Unit_ptr) {
            each->buffResetStack(buffSet,Stack_Name);
        }
    }
}
void buffResetStackAllAlly(vector<BuffElementClass> buffSet,string Stack_Name){
    for (int i = 1; i <= Total_ally; i++) {
        for (auto &each : Ally_unit[i]->Sub_Unit_ptr) {
            each->buffResetStack(buffSet,Stack_Name);
        }
    }
}