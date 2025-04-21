#ifndef DEBUFF_STATS_H
#define DEBUFF_STATS_H
#include "../Class/Trigger_Function.h"
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
bool Enemy::debuffApply(SubUnit *ptr,string debuffName,int extend){
    this->extendDebuff(debuffName,extend);
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
bool Enemy::debuffMark(SubUnit *ptr,string debuffName,int extend){
    this->extendDebuff(debuffName,extend);
    if(!this->getDebuff(debuffName)){
        this->setDebuff(debuffName,1);
        this->addTotalDebuff(1);
        allEventApplyDebuff(ptr,this);
        return true;
    }
    return false;
}

void Enemy::debuffRemove(string debuffName){
    this->setDebuff(debuffName,0);
    this->addTotalDebuff(-1);
}

bool Enemy::isDebuffEnd(string Debuff_name){
    if(this->Atv_stats->turn_cnt==this->Debuff_time_count[Debuff_name]&&turn->Char_Name==this->Atv_stats->Char_Name){
        if(!this->getStack(Debuff_name))this->debuffRemove(Debuff_name);
        return true;
    }
    return false;
}

void Enemy::extendDebuff(string Debuff_name,int Turn_extend){
    this->Debuff_time_count[Debuff_name] = this->Atv_stats->turn_cnt+Turn_extend;
}

void extendDebuffAll(string Debuff_name,int Turn_extend){
    for(int i=1;i<=Total_enemy;i++){
        Enemy_unit[i]->extendDebuff(Debuff_name,Turn_extend);
    }
}

//เป้าเดี่ยว
void Enemy::debuffSingle(vector<BuffClass> debuffSet) {
    for(BuffClass &debuff : debuffSet){
        this->Stats_type[debuff.statsType][debuff.actionType] += debuff.value;
    }
}
void Enemy::debuffSingle(vector<BuffElementClass> debuffSet) {
    for(BuffElementClass &debuff : debuffSet){
        this->Stats_each_element[debuff.statsType][debuff.element][debuff.actionType] += debuff.value;
    }
}

//เป้าเดี่ยวแปะ
void Enemy::debuffSingleApply(vector<BuffClass> debuffSet,SubUnit *ptr,string debuffName){
    if(!this->debuffApply(ptr,debuffName))return;
    for(BuffClass &debuff : debuffSet){
        this->Stats_type[debuff.statsType][debuff.actionType] += debuff.value;
    }
}
void Enemy::debuffSingleApply(vector<BuffElementClass> debuffSet,SubUnit *ptr,string debuffName){
    if(!this->debuffApply(ptr,debuffName))return;
    for(BuffElementClass &debuff : debuffSet){
        this->Stats_each_element[debuff.statsType][debuff.element][debuff.actionType] += debuff.value;
    }
}
//เป้าเดี่ยวแปะ + extend
void Enemy::debuffSingleApply(vector<BuffClass> debuffSet,SubUnit *ptr,string debuffName ,int extend) {
    if(!this->debuffApply(ptr,debuffName,extend))return;
    for(BuffClass &debuff : debuffSet){
        this->Stats_type[debuff.statsType][debuff.actionType] += debuff.value;
    }
}
void Enemy::debuffSingleApply(vector<BuffElementClass> debuffSet,SubUnit *ptr,string debuffName ,int extend) {
    if(!this->debuffApply(ptr,debuffName,extend))return;
    for(BuffElementClass &debuff : debuffSet){
        this->Stats_each_element[debuff.statsType][debuff.element][debuff.actionType] += debuff.value;
    }
}
//เป้าเดี่ยวMark
void Enemy::debuffSingleMark(vector<BuffClass> debuffSet,SubUnit *ptr,string debuffName){
    if(!this->debuffMark(ptr,debuffName))return;
    for(BuffClass &debuff : debuffSet){
        this->Stats_type[debuff.statsType][debuff.actionType] += debuff.value;
    }
}
void Enemy::debuffSingleMark(vector<BuffElementClass> debuffSet,SubUnit *ptr,string debuffName){
    if(!this->debuffMark(ptr,debuffName))return;
    for(BuffElementClass &debuff : debuffSet){
        this->Stats_each_element[debuff.statsType][debuff.element][debuff.actionType] += debuff.value;
    }
}
//ST MARK + extend
void Enemy::debuffSingleMark(vector<BuffClass> debuffSet,SubUnit *ptr,string debuffName ,int extend) {
    if(!this->debuffMark(ptr,debuffName,extend))return;
    for(BuffClass &debuff : debuffSet){
        this->Stats_type[debuff.statsType][debuff.actionType] += debuff.value;
    }
}
void Enemy::debuffSingleMark(vector<BuffElementClass> debuffSet,SubUnit *ptr,string debuffName ,int extend) {
    if(!this->debuffMark(ptr,debuffName,extend))return;
    for(BuffElementClass &debuff : debuffSet){
        this->Stats_each_element[debuff.statsType][debuff.element][debuff.actionType] += debuff.value;
    }
}
void debuffAllEnemy(vector<BuffClass> debuffSet) {
    for (int i = 1; i <= Total_enemy; i++) {
        Enemy_unit[i]->debuffSingle(debuffSet);
    }
}
void debuffAllEnemy(vector<BuffElementClass> debuffSet) {
    for (int i = 1; i <= Total_enemy; i++) {
        Enemy_unit[i]->debuffSingle(debuffSet);
    }
}

void debuffAllEnemyApply(vector<BuffClass> debuffSet,SubUnit *ptr, string Debuff_Name) {
    for (int i = 1; i <= Total_enemy; i++) {
        if(!Enemy_unit[i]->debuffApply(ptr,Debuff_Name))continue;
        Enemy_unit[i]->debuffSingle(debuffSet);
    }
}
void debuffAllEnemyApply(vector<BuffElementClass> debuffSet,SubUnit *ptr, string Debuff_Name) {
    for (int i = 1; i <= Total_enemy; i++) {
        if(!Enemy_unit[i]->debuffApply(ptr,Debuff_Name))continue;
        Enemy_unit[i]->debuffSingle(debuffSet);
    }
}
void debuffAllEnemyApply(vector<BuffClass> debuffSet,SubUnit *ptr, string Debuff_Name,int extend) {
    for (int i = 1; i <= Total_enemy; i++) {
        if(!Enemy_unit[i]->debuffApply(ptr,Debuff_Name,extend))continue;
        Enemy_unit[i]->debuffSingle(debuffSet);
    }
}
void debuffAllEnemyApply(vector<BuffElementClass> debuffSet,SubUnit *ptr, string Debuff_Name,int extend) {
    for (int i = 1; i <= Total_enemy; i++) {
        if(!Enemy_unit[i]->debuffApply(ptr,Debuff_Name,extend))continue;
        Enemy_unit[i]->debuffSingle(debuffSet);
    }
}

void debuffAllEnemyMark(vector<BuffClass> debuffSet, SubUnit* ptr, string Debuff_Name) {
    for (int i = 1; i <= Total_enemy; i++) {
        if (!Enemy_unit[i]->debuffMark(ptr, Debuff_Name)) continue;
        Enemy_unit[i]->debuffSingle(debuffSet);
    }
}

void debuffAllEnemyMark(vector<BuffElementClass> debuffSet, SubUnit* ptr, string Debuff_Name) {
    for (int i = 1; i <= Total_enemy; i++) {
        if (!Enemy_unit[i]->debuffMark(ptr, Debuff_Name)) continue;
        Enemy_unit[i]->debuffSingle(debuffSet);
    }
}

void debuffAllEnemyMark(vector<BuffClass> debuffSet, SubUnit* ptr, string Debuff_Name, int extend) {
    for (int i = 1; i <= Total_enemy; i++) {
        if (!Enemy_unit[i]->debuffMark(ptr, Debuff_Name, extend)) continue;
        Enemy_unit[i]->debuffSingle(debuffSet);
    }
}

void debuffAllEnemyMark(vector<BuffElementClass> debuffSet, SubUnit* ptr, string Debuff_Name, int extend) {
    for (int i = 1; i <= Total_enemy; i++) {
        if (!Enemy_unit[i]->debuffMark(ptr, Debuff_Name, extend)) continue;
        Enemy_unit[i]->debuffSingle(debuffSet);
    }
}





#endif