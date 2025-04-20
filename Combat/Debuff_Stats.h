#ifndef DEBUFF_STATS_H
#define DEBUFF_STATS_H
#include "../Unit/Trigger_Function.h"
using namespace std;
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12


bool Enemy::debuffApply(SubUnit *ptr,string debuffName){
    if(!this->getDebuff(debuffName)){
        this->setDebuff(debuffName,1);
        this->addTotalDebuff(1);
        allEventApplyDebuff(ptr,this);
        return true;
    }
    allEventApplyDebuff(ptr,this);
    return false;
}
bool Enemy::debuffMark(SubUnit *ptr,string debuffName){
    if(!this->getDebuff(debuffName)){
        this->setDebuff(debuffName,1);
        this->addTotalDebuff(1);
        allEventApplyDebuff(ptr,this);
        return true;
    }
    return false;
}
void Enemy::debuffStack(SubUnit *ptr,string debuffName,int Stack_increase){

    if(!this->getStack(debuffName))this->addTotalDebuff(1);
    this->addStack(debuffName,Stack_increase);
    allEventApplyDebuff(ptr,this);
}

//return ว่า stackเต็มไหม
pair<int,int> Enemy::debuffStack(SubUnit *ptr,string debuffName,int Stack_increase,int StackLimit){
    if (!this->getStack(debuffName)) this->addTotalDebuff(1);
    Stack_increase = (this->getStack(debuffName) + Stack_increase <= StackLimit) ? Stack_increase : StackLimit - this->getStack(debuffName);
    this->addStack(debuffName, Stack_increase);
    allEventApplyDebuff(ptr, this);
    return {Stack_increase, this->getStack(debuffName)};
}
void Enemy::debuffRemove(string debuffName){
    
    this->setDebuff(debuffName,0);
    this->addTotalDebuff(-1);
    
}
void Enemy::debuffRemoveStack(string debuffName){
    
    this->setStack(debuffName,0);
    this->addTotalDebuff(-1);
    
}
bool Enemy::isDebuffEnd(string Debuff_name){
    if(this->Atv_stats->turn_cnt==this->Debuff_time_count[Debuff_name]&&turn->Char_Name==this->Atv_stats->Char_Name){
        this->Debuff[Debuff_name] = 0;
        return true;
    }
    return false;
}

void Enemy::extendDebuffTime(string Debuff_name,int Turn_extend){
    this->Debuff_time_count[Debuff_name] = this->Atv_stats->turn_cnt+Turn_extend;
}
void Extend_Debuff_All_Enemy(string Debuff_name,int Turn_extend){
    for(int i=1;i<=Total_enemy;i++){
        Enemy_unit[i]->extendDebuffTime(Debuff_name,Turn_extend);
    }
}

void Enemy::debuffSingleTarget(string stats_type, string Attack_type, double Value) {
    this->Stats_type[stats_type][Attack_type] += Value;
}

void Enemy::debuffSingleTarget(string stats_type, string Attack_type, string Element, double Value) {
    this->Stats_each_element[stats_type][Element][Attack_type] += Value;
}

void Enemy::debuffStackSingleTarget(SubUnit *ptr, string stats_type, string Attack_type, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name) {
    if (this->Stack[Stack_Name] + Stack_increase > Stack_limit) {
        Stack_increase = Stack_limit - this->Stack[Stack_Name];
    }
    this->debuffStack(ptr,Stack_Name,Stack_increase);
    if(Stack_increase==0)return;
    this->debuffSingleTarget(stats_type, Attack_type, Stack_increase * Value_per_stack);
}

void Enemy::debuffStackSingleTarget(SubUnit *ptr,string stats_type, string Attack_type, string Element, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name) {
    if (this->Stack[Stack_Name] + Stack_increase > Stack_limit) {
        Stack_increase = Stack_limit - this->Stack[Stack_Name];
    }
    this->debuffStack(ptr,Stack_Name,Stack_increase);
    if(Stack_increase==0)return;
    this->debuffSingleTarget(stats_type, Attack_type, Element, Stack_increase * Value_per_stack);
}

void debuffAllEnemyApplyVer(SubUnit *ptr, string stats_type, string Attack_type, double Value, string Debuff_Name) {
    for (int i = 1; i <= Total_enemy; i++) {
        if(!Enemy_unit[i]->debuffApply(ptr,Debuff_Name))continue;
        Enemy_unit[i]->debuffSingleTarget(stats_type, Attack_type, Value);
    }
}

void debuffAllEnemyApplyVer(SubUnit *ptr, string stats_type, string Attack_type, string Element, double Value, string Debuff_Name) {
    for (int i = 1; i <= Total_enemy; i++) {
        if(!Enemy_unit[i]->debuffApply(ptr,Debuff_Name))continue;
        Enemy_unit[i]->debuffSingleTarget(stats_type, Attack_type, Element, Value);
    }
}

void debuffAllEnemyMarkVer(SubUnit *ptr, string stats_type, string Attack_type, double Value, string Debuff_Name) {
    for (int i = 1; i <= Total_enemy; i++) {
        if(!Enemy_unit[i]->debuffMark(ptr,Debuff_Name))continue;
        Enemy_unit[i]->debuffSingleTarget(stats_type, Attack_type, Value);
    }
}

void debuffAllEnemyMarkVer(SubUnit *ptr, string stats_type, string Attack_type, string Element, double Value, string Debuff_Name) {
    for (int i = 1; i <= Total_enemy; i++) {
        if(!Enemy_unit[i]->debuffMark(ptr,Debuff_Name))continue;
        Enemy_unit[i]->debuffSingleTarget(stats_type, Attack_type, Element, Value);
    }
}

void debuffAllEnemyStack(SubUnit *ptr, string stats_type, string Attack_type, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name) {
    for (int i = 1; i <= Total_enemy; i++) {
        Enemy_unit[i]->debuffStackSingleTarget(ptr,stats_type,Attack_type,Value_per_stack,Stack_increase,Stack_limit,Stack_Name);
    }
}

void debuffAllEnemyStack(SubUnit *ptr, string stats_type, string Attack_type, string Element, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name) {
    for (int i = 1; i <= Total_enemy; i++) {
        Enemy_unit[i]->debuffStackSingleTarget(ptr,stats_type,Attack_type,Element,Value_per_stack,Stack_increase,Stack_limit,Stack_Name);
    }
}



#endif