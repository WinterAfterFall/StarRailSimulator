#include "../include.h"

bool Enemy::debuffApply(SubUnit *ptr,string debuffName){
    allEventBeforeApplyDebuff(ptr,this);
    if(!this->getDebuff(debuffName)){
        this->setDebuff(debuffName,1);
        this->addTotalDebuff(1);
        allEventAfterApplyDebuff(ptr,this);
        return true;
    }
    allEventAfterApplyDebuff(ptr,this);
    return false;
}
bool Enemy::debuffApply(SubUnit *ptr,string debuffName,int extend){
    allEventBeforeApplyDebuff(ptr,this);
    this->extendDebuff(debuffName,extend);
    if(!this->getDebuff(debuffName)){
        this->setDebuff(debuffName,1);
        this->addTotalDebuff(1);
        allEventAfterApplyDebuff(ptr,this);
        return true;
    }
    allEventAfterApplyDebuff(ptr,this);
    return false;
}

bool Enemy::debuffMark(SubUnit *ptr,string debuffName){
    if(!this->getDebuff(debuffName)){
        allEventBeforeApplyDebuff(ptr,this);
        this->setDebuff(debuffName,1);
        this->addTotalDebuff(1);
        allEventAfterApplyDebuff(ptr,this);
        return true;
    }
    return false;
}
bool Enemy::debuffMark(SubUnit *ptr,string debuffName,int extend){
    this->extendDebuff(debuffName,extend);
    if(!this->getDebuff(debuffName)){
        allEventBeforeApplyDebuff(ptr,this);
        this->setDebuff(debuffName,1);
        this->addTotalDebuff(1);
        allEventAfterApplyDebuff(ptr,this);
        return true;
    }
    return false;
}

void Enemy::debuffRemove(string debuffName){
    this->setDebuff(debuffName,0);
    this->addTotalDebuff(-1);
}

bool Enemy::isDebuffEnd(string Debuff_name){
    if(this->Atv_stats->turnCnt==this->Debuff_time_count[Debuff_name]&&turn->Char_Name==this->Atv_stats->Char_Name){
        this->debuffRemove(Debuff_name);
        return true;
    }
    return false;
}

void Enemy::extendDebuff(string Debuff_name,int Turn_extend){
    this->Debuff_time_count[Debuff_name] = this->Atv_stats->turnCnt+Turn_extend;
}

void extendDebuffAll(string Debuff_name,int Turn_extend){
    for(int i=1;i<=Total_enemy;i++){
        Enemy_unit[i]->extendDebuff(Debuff_name,Turn_extend);
    }
}
void extendDebuffTargets(vector<Enemy*> targets,string Debuff_name,int Turn_extend){
    for(auto &each : targets){
        each->extendDebuff(Debuff_name,Turn_extend);
    }
}

ElementType Enemy::weaknessApplyChoose(int extend){
    vector<pair<int,ElementType>> weaknessPriority;
    ElementType ans;
    for(int i=1;i<=Total_ally;i++){
        if(this->Weakness_type[Ally_unit[i]->getSubUnit()->Element_type[0]])continue;
        if(Ally_unit[i]->path[0]==Path::Harmony)weaknessPriority.push_back({Total_ally+4,Ally_unit[i]->getSubUnit()->Element_type[0]});
        else if(Ally_unit[i]->path[0]==Path::Nihility)weaknessPriority.push_back({Total_ally+1,Ally_unit[i]->getSubUnit()->Element_type[0]});
        else if(Ally_unit[i]->path[0]==Path::Abundance)weaknessPriority.push_back({Total_ally+3,Ally_unit[i]->getSubUnit()->Element_type[0]});
        else if(Ally_unit[i]->path[0]==Path::Preservation)weaknessPriority.push_back({Total_ally+2,Ally_unit[i]->getSubUnit()->Element_type[0]});
        else weaknessPriority.push_back({i,Ally_unit[i]->getSubUnit()->Element_type[0]});
    }
    sort(weaknessPriority.begin(),weaknessPriority.end());
    if(weaknessPriority.size()==0){
        pair<ElementType,int> mn = {ElementType::Fire,1e9};
        for(auto &e : this->Weakness_typeCountdown){
            if(mn.second>e.second){
                mn.first = e.first;
                mn.second = e.second;
            }
        }
        ans = mn.first;
    }else {
        ans = weaknessPriority[0].second;
    }
    this->weaknessApply(ans,extend);
    return ans;
}
void Enemy::weaknessApply(ElementType element ,int extend){
    if(this->Weakness_type[element] == 0){
        this->currentWeaknessElementAmount++;
        this->Weakness_type[element] = 1;
    }

    this->Weakness_typeCountdown[element] = 
    (this->Weakness_typeCountdown[element] > extend + this->Atv_stats->turnCnt) ?
    this->Weakness_typeCountdown[element] :
    extend + this->Atv_stats->turnCnt;
}


//เป้าเดี่ยว
void Enemy::debuffSingle(vector<BuffClass> debuffSet) {
    for(BuffClass &debuff : debuffSet){
        if(debuff.statsType==Stats::FLAT_SPD||debuff.statsType==Stats::SPD_P)this->speedBuff(debuff);
        else this->Stats_type[debuff.statsType][debuff.actionType] += debuff.value;
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
        if(debuff.statsType==Stats::FLAT_SPD||debuff.statsType==Stats::SPD_P)this->speedBuff(debuff);
        else this->Stats_type[debuff.statsType][debuff.actionType] += debuff.value;
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
        if(debuff.statsType==Stats::FLAT_SPD||debuff.statsType==Stats::SPD_P)this->speedBuff(debuff);
        else this->Stats_type[debuff.statsType][debuff.actionType] += debuff.value;
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
        if(debuff.statsType==Stats::FLAT_SPD||debuff.statsType==Stats::SPD_P)this->speedBuff(debuff);
        else this->Stats_type[debuff.statsType][debuff.actionType] += debuff.value;
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
        if(debuff.statsType==Stats::FLAT_SPD||debuff.statsType==Stats::SPD_P)this->speedBuff(debuff);
        else this->Stats_type[debuff.statsType][debuff.actionType] += debuff.value;
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
void debuffEnemyTargets(vector<Enemy*> targets,vector<BuffClass> debuffSet){
    for (auto &each : targets) {
        each->debuffSingle(debuffSet);
    }
}
void debuffEnemyTargets(vector<Enemy*> targets,vector<BuffElementClass> debuffSet){
        for (auto &each : targets) {
        each->debuffSingle(debuffSet);
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
void debuffEnemyTargetsApply(vector<Enemy*> targets,vector<BuffClass> debuffSet,SubUnit *ptr, string Debuff_Name){
    for (auto &each : targets) {
        if(!each->debuffApply(ptr, Debuff_Name)) continue;
        each->debuffSingle(debuffSet);
    }
}
void debuffEnemyTargetsApply(vector<Enemy*> targets,vector<BuffElementClass> debuffSet,SubUnit *ptr, string Debuff_Name){
    for (auto &each : targets) {
        if(!each->debuffApply(ptr, Debuff_Name)) continue;
        each->debuffSingle(debuffSet);
    }
}
void debuffEnemyTargetsApply(vector<Enemy*> targets,vector<BuffClass> debuffSet,SubUnit *ptr, string Debuff_Name,int extend){
    for (auto &each : targets) {
        if(!each->debuffApply(ptr, Debuff_Name, extend)) continue;
        each->debuffSingle(debuffSet);
    }
}
void debuffEnemyTargetsApply(vector<Enemy*> targets,vector<BuffElementClass> debuffSet,SubUnit *ptr, string Debuff_Name,int extend){
    for (auto &each : targets) {
        if(!each->debuffApply(ptr, Debuff_Name, extend)) continue;
        each->debuffSingle(debuffSet);
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
void debuffEnemyTargetsyMark(vector<Enemy*> targets, vector<BuffClass> debuffSet, SubUnit* ptr, string Debuff_Name) {
    for (auto& each : targets) {
        if (!each->debuffMark(ptr, Debuff_Name)) continue;
        each->debuffSingle(debuffSet);
    }
}

void debuffEnemyTargetsyMark(vector<Enemy*> targets, vector<BuffElementClass> debuffSet, SubUnit* ptr, string Debuff_Name) {
    for (auto& each : targets) {
        if (!each->debuffMark(ptr, Debuff_Name)) continue;
        each->debuffSingle(debuffSet);
    }
}

void debuffEnemyTargetsyMark(vector<Enemy*> targets, vector<BuffClass> debuffSet, SubUnit* ptr, string Debuff_Name, int extend) {
    for (auto& each : targets) {
        if (!each->debuffMark(ptr, Debuff_Name, extend)) continue;
        each->debuffSingle(debuffSet);
    }
}

void debuffEnemyTargetsyMark(vector<Enemy*> targets, vector<BuffElementClass> debuffSet, SubUnit* ptr, string Debuff_Name, int extend) {
    for (auto& each : targets) {
        if (!each->debuffMark(ptr, Debuff_Name, extend)) continue;
        each->debuffSingle(debuffSet);
    }
}




