#ifndef BUFF_STATS_H
#define BUFF_STATS_H
#include "../Class/Trigger_Function.h"
using namespace std;
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12




//check if it is ally uni
bool SubUnit::isBuffEnd(string Buff_name){
if(this->Atv_stats->turn_cnt==this->Buff_countdown[Buff_name]&&turn->Char_Name==this->Atv_stats->Char_Name){
    this->Buff_check[Buff_name] = 0;
    return true;
}
return false;
}
bool SubUnit::isHaveToAddBuff(string Buff_name){
if(this->Buff_check[Buff_name]==1){
    return false;
}
Buff_check[Buff_name] = 1;
return true;
}

pair<int,int> SubUnit::calStack(int Stack_increase,int StackLimit,string buffName){
    Stack_increase = (this->getStack(buffName) + Stack_increase <= StackLimit) ? Stack_increase : StackLimit - this->getStack(buffName);
    this->addStack(buffName, Stack_increase);
    return {Stack_increase, this->getStack(buffName)};
}
//Extend
void SubUnit::extendBuffTime(string Buff_name,int Turn_extend){
this->Buff_countdown[Buff_name] = this->Atv_stats->turn_cnt+Turn_extend;
}
void Ally::extendBuffTime(string Buff_name,int Turn_extend){
for(int i=0;i<this->Sub_Unit_ptr.size();i++){
    this->Sub_Unit_ptr[i]->extendBuffTime(Buff_name,Turn_extend);
}
}
void extendBuffTime(string Buff_name,int Turn_extend){
for(int i=1;i<=Total_ally;i++){
    Ally_unit[i]->extendBuffTime(Buff_name,Turn_extend);
}
}
void extendBuffTimeExcludingBuffer(string Buff_name,int Turn_extend,string Buffer_name){
for(int i=1;i<=Total_ally;i++){
    for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
        if(Ally_unit[i]->Sub_Unit_ptr[j]->isSameUnitName(Buffer_name))continue;
        Ally_unit[i]->Sub_Unit_ptr[j]->extendBuffTime(Buff_name,Turn_extend);
    }
}
}
void extendBuffTimeExcludingBuffer(string Buff_name,int Turn_extend,SubUnit *Buffer){
for(int i=1;i<=Total_ally;i++){
    for(int j=0;j<Ally_unit[i]->Sub_Unit_ptr.size();j++){
        if(Ally_unit[i]->Sub_Unit_ptr[j]->isSameUnit(Buffer))continue;
        Ally_unit[i]->Sub_Unit_ptr[j]->extendBuffTime(Buff_name,Turn_extend);
    }
}
}

void SubUnit::buffAlly(vector<BuffClass> buffSet){
for(BuffClass &buff : buffSet){
    this->Stats_type[buff.statsType][buff.actionType] += buff.value;
    if(buff.actionType=="None")StatsAdjust(this,buff.statsType);
}
}
void SubUnit::buffAlly(vector<BuffElementClass> buffSet){
for(BuffElementClass &buff : buffSet){
    this->Stats_each_element[buff.statsType][buff.element][buff.actionType] += buff.value;
}
}

void Ally::buffAlly(vector<BuffClass> buffSet){
for (auto &e : this->Sub_Unit_ptr) {
    e->buffAlly(buffSet);
}
}
void Ally::buffAlly(vector<BuffElementClass> buffSet){
for (auto &e : this->Sub_Unit_ptr) {
    e->buffAlly(buffSet);
}
}

void Ally::buffAlly(vector<BuffClass> buffSet,string Buff_name,int extend){
for (auto &e : this->Sub_Unit_ptr) {
    if(!e->isHaveToAddBuff(Buff_name))continue;
    e->buffAlly(buffSet);
    e->extendBuffTime(Buff_name,extend);
}
}
void Ally::buffAlly(vector<BuffElementClass> buffSet,string Buff_name,int extend){
for (auto &e : this->Sub_Unit_ptr) {
    if(!e->isHaveToAddBuff(Buff_name))continue;
    e->buffAlly(buffSet);
    e->extendBuffTime(Buff_name,extend);
}
}   

void buffAllAlly(vector<BuffClass> buffSet) {
for (int i = 1; i <= Total_ally; i++) {
    for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
        Ally_unit[i]->Sub_Unit_ptr[j]->buffAlly(buffSet);
    }
}
}
void buffAllAlly(vector<BuffElementClass> buffSet) {
for (int i = 1; i <= Total_ally; i++) {
    for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
        Ally_unit[i]->Sub_Unit_ptr[j]->buffAlly(buffSet);
    }
}
}

void buffAllAlly(vector<BuffClass> buffSet, string Buff_name,int extend) {
for (int i = 1; i <= Total_ally; i++) {
    for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
        if(Ally_unit[i]->Sub_Unit_ptr[j]->isHaveToAddBuff(Buff_name)){
            Ally_unit[i]->Sub_Unit_ptr[j]->buffAlly(buffSet);
            Ally_unit[i]->Sub_Unit_ptr[j]->extendBuffTime(Buff_name,extend);
        }
    }
}
}
void buffAllAlly(vector<BuffElementClass> buffSet, string Buff_name,int extend) {
for (int i = 1; i <= Total_ally; i++) {
    for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
        if(Ally_unit[i]->Sub_Unit_ptr[j]->isHaveToAddBuff(Buff_name)){
            Ally_unit[i]->Sub_Unit_ptr[j]->buffAlly(buffSet);
            Ally_unit[i]->Sub_Unit_ptr[j]->extendBuffTime(Buff_name,extend);
        }
    }
}
}

void SubUnit::buffAllAllyExcludingBuffer(vector<BuffClass> buffSet){
    for (int i = 1; i <= Total_ally; i++) {
        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            if (this->isSameChar(Ally_unit[i]->Sub_Unit_ptr[j].get())) continue;
            Ally_unit[i]->Sub_Unit_ptr[j]->buffAlly(buffSet);
        }
    }
}
void SubUnit::buffAllAllyExcludingBuffer(vector<BuffElementClass> buffSet) {
    for (int i = 1; i <= Total_ally; i++) {
        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            if (this->isSameChar(Ally_unit[i]->Sub_Unit_ptr[j].get())) continue;
            Ally_unit[i]->Sub_Unit_ptr[j]->buffAlly(buffSet);
        }
    }
}

void SubUnit::buffAllAllyExcludingBuffer(vector<BuffClass> buffSet, string Buff_name,int extend) {
    for (int i = 1; i <= Total_ally; i++) {
        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            if (this->isSameChar(Ally_unit[i]->Sub_Unit_ptr[j].get())) continue;
            if(Ally_unit[i]->Sub_Unit_ptr[j]->isHaveToAddBuff(Buff_name)){
                Ally_unit[i]->Sub_Unit_ptr[j]->buffAlly(buffSet);
                Ally_unit[i]->Sub_Unit_ptr[j]->extendBuffTime(Buff_name,extend);
            }
        }
    }
}
void SubUnit::buffAllAllyExcludingBuffer(vector<BuffElementClass> buffSet, string Buff_name,int extend) {
    for (int i = 1; i <= Total_ally; i++) {
        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            if (this->isSameChar(Ally_unit[i]->Sub_Unit_ptr[j].get())) continue;
            if(Ally_unit[i]->Sub_Unit_ptr[j]->isHaveToAddBuff(Buff_name)){
                Ally_unit[i]->Sub_Unit_ptr[j]->buffAlly(buffSet);
                Ally_unit[i]->Sub_Unit_ptr[j]->extendBuffTime(Buff_name,extend);
            }
        }
    }
}

//stack buff/debuff
void SubUnit::buffStackSingle(vector<BuffClass> buffSet , int Stack_increase, int Stack_limit, string Stack_Name) {
    int value = this.calStack(Stack_increase,Stack_limit,Stack_Name)
Buff_single_target(ptr, stats_type, Attack_type, Stack_increase * Value_per_stack);
}
void Stack_Buff_single_target(SubUnit *ptr, string stats_type, string Attack_type, string Element, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name) {
if (ptr->Stack[Stack_Name] >= Stack_limit) return;
if (ptr->Stack[Stack_Name] + Stack_increase > Stack_limit) {
    Stack_increase = Stack_limit - ptr->Stack[Stack_Name];
}
ptr->Stack[Stack_Name] += Stack_increase;
Buff_single_target(ptr, stats_type, Attack_type, Element, Stack_increase * Value_per_stack);
}

void Stack_Buff_single_with_all_memo(Ally *ptr, string stats_type, string Attack_type, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name) {
for (int i = 0; i < ptr->Sub_Unit_ptr.size(); i++) {
    SubUnit *unit = ptr->Sub_Unit_ptr[i].get();
    Stack_Buff_single_target(unit, stats_type, Attack_type, Value_per_stack, Stack_increase, Stack_limit, Stack_Name);
}
}
void Stack_Buff_single_with_all_memo(Ally *ptr, string stats_type, string Attack_type, string Element, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name) {
for (int i = 0; i < ptr->Sub_Unit_ptr.size(); i++) {
    SubUnit *unit = ptr->Sub_Unit_ptr[i].get();
    Stack_Buff_single_target(unit, stats_type, Attack_type,Element, Value_per_stack, Stack_increase, Stack_limit, Stack_Name);
}
}

void Stack_Buff_All_Ally(string stats_type, string Attack_type, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name) {
for (int i = 1; i <= Total_ally; i++) {
    for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
        SubUnit *unit = Ally_unit[i]->Sub_Unit_ptr[j].get();
        Stack_Buff_single_target(unit, stats_type, Attack_type, Value_per_stack, Stack_increase, Stack_limit, Stack_Name);
    }
}
}
void Stack_Buff_All_Ally(string stats_type, string Attack_type, string Element, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name) {
for (int i = 1; i <= Total_ally; i++) {
    for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
        SubUnit *unit = Ally_unit[i]->Sub_Unit_ptr[j].get();
        Stack_Buff_single_target(unit, stats_type, Attack_type,Element, Value_per_stack, Stack_increase, Stack_limit, Stack_Name);
    }
}
}

void Stack_Buff_All_Ally_Excluding_Buffer(string stats_type, string Attack_type, string Buffer_name, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name) {
for (int i = 1; i <= Total_ally; i++) {
    for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
        if (Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->Char_Name == Buffer_name) continue;
        SubUnit* ptr = Ally_unit[i]->Sub_Unit_ptr[j].get();  // ดึง pointer ออกจาก unique_ptr
        Stack_Buff_single_target(ptr, stats_type, Attack_type, Value_per_stack, Stack_increase, Stack_limit, Stack_Name);
    }
}
}
void Stack_Buff_All_Ally_Excluding_Buffer(string stats_type, string Attack_type, string Element, string Buffer_name, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name) {
int original_increase = Stack_increase;

for (int i = 1; i <= Total_ally; i++) {
    
    for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
        if (Ally_unit[i]->Sub_Unit_ptr[j]->Atv_stats->Char_Name == Buffer_name) continue;
        SubUnit* ptr = Ally_unit[i]->Sub_Unit_ptr[j].get();  // ดึง pointer ออกจาก unique_ptr
        Stack_Buff_single_target(ptr, stats_type, Attack_type,Element, Value_per_stack, Stack_increase, Stack_limit, Stack_Name);
    }
}
}


#endif