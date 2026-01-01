#include "../include.h"

bool debuffApply(AllyUnit *ptr,Enemy *enemy ,string debuffName){
    allEventBeforeApplyDebuff(ptr,enemy);
    if(!enemy->getDebuff(debuffName)){
        enemy->setDebuff(debuffName,1);
        enemy->addTotalDebuff(1);
        allEventAfterApplyDebuff(ptr,enemy);
        return true;
    }
    allEventAfterApplyDebuff(ptr,enemy);
    return false;
}
bool debuffApply(AllyUnit *ptr,Enemy *enemy,string debuffName,int extend){
    allEventBeforeApplyDebuff(ptr,enemy);
    extendDebuff(enemy,debuffName,extend);
    if(!enemy->getDebuff(debuffName)){
        enemy->setDebuff(debuffName,1);
        enemy->addTotalDebuff(1);
        allEventAfterApplyDebuff(ptr,enemy);
        return true;
    }
    allEventAfterApplyDebuff(ptr,enemy);
    return false;
}

bool debuffMark(AllyUnit *ptr,Enemy *enemy,string debuffName){
    if(!enemy->getDebuff(debuffName)){
        allEventBeforeApplyDebuff(ptr,enemy);
        enemy->setDebuff(debuffName,1);
        enemy->addTotalDebuff(1);
        allEventAfterApplyDebuff(ptr,enemy);
        return true;
    }
    return false;
}
bool debuffMark(AllyUnit *ptr,Enemy *enemy,string debuffName,int extend){
    extendDebuff(enemy,debuffName,extend);
    if(!enemy->getDebuff(debuffName)){
        allEventBeforeApplyDebuff(ptr,enemy);
        enemy->setDebuff(debuffName,1);
        enemy->addTotalDebuff(1);
        allEventAfterApplyDebuff(ptr,enemy);
        return true;
    }
    return false;
}

void debuffRemove(Enemy *enemy,string debuffName){
    enemy->setDebuff(debuffName,0);
    enemy->addTotalDebuff(-1);
}

bool isDebuffEnd(Enemy *enemy,string Debuff_name){
    if(enemy->Atv_stats->turnCnt==enemy->Debuff_time_count[Debuff_name]&&turn->UnitName==enemy->Atv_stats->UnitName){
        debuffRemove(enemy,Debuff_name);
        return true;
    }
    return false;
}

void extendDebuff(Enemy *enemy,string Debuff_name,int Turn_extend){
    enemy->Debuff_time_count[Debuff_name] = enemy->Atv_stats->turnCnt+Turn_extend;
}

void extendDebuffAll(string Debuff_name,int Turn_extend){
    for(auto &each : enemyList){
        extendDebuff(each,Debuff_name,Turn_extend);
    }
}
void extendDebuffTargets(vector<Enemy*> targets,string Debuff_name,int Turn_extend){
    for(auto &each : targets){
        extendDebuff(each,Debuff_name,Turn_extend);
    }
}

ElementType weaknessApplyChoose(Enemy *enemy,int extend){
    vector<pair<int,ElementType>> weaknessPriority;
    ElementType ans;
    for(auto &each : charList){
        int i=1;
        if(enemy->Weakness_type[each->Element_type[0]])continue;
        if(each->path[0]==Path::Harmony)weaknessPriority.push_back({Total_ally+4,each->Element_type[0]});
        else if(each->path[0]==Path::Nihility)weaknessPriority.push_back({Total_ally+1,each->Element_type[0]});
        else if(each->path[0]==Path::Abundance)weaknessPriority.push_back({Total_ally+3,each->Element_type[0]});
        else if(each->path[0]==Path::Preservation)weaknessPriority.push_back({Total_ally+2,each->Element_type[0]});
        else weaknessPriority.push_back({i,each->Element_type[0]});
        i++;
    }
    sort(weaknessPriority.begin(),weaknessPriority.end());
    if(weaknessPriority.size()==0){
        pair<ElementType,int> mn = {ElementType::Fire,1e9};
        for(auto &e : enemy->Weakness_typeCountdown){
            if(mn.second>e.second){
                mn.first = e.first;
                mn.second = e.second;
            }
        }
        ans = mn.first;
    }else {
        ans = weaknessPriority[0].second;
    }
    weaknessApply(enemy,ans,extend);
    return ans;
}
void weaknessApply(Enemy *enemy,ElementType element ,int extend){
    if(enemy->Weakness_type[element] == 0){
        enemy->currentWeaknessElementAmount++;
        enemy->Weakness_type[element] = 1;
    }

    enemy->Weakness_typeCountdown[element] = 
    (enemy->Weakness_typeCountdown[element] > extend + enemy    ->Atv_stats->turnCnt) ?
    enemy->Weakness_typeCountdown[element] :
    extend + enemy->Atv_stats->turnCnt;
}


//เป้าเดี่ยว
void debuffSingle(Enemy *enemy,vector<BuffClass> debuffSet) {
    for(BuffClass &debuff : debuffSet){
        if(debuff.statsType==Stats::FLAT_SPD||debuff.statsType==Stats::SPD_P)enemy->speedBuff(debuff);
        else enemy->Stats_type[debuff.statsType][debuff.actionType] += debuff.value;
    }
}
void debuffSingle(Enemy *enemy,vector<BuffElementClass> debuffSet) {
    for(BuffElementClass &debuff : debuffSet){
        enemy->Stats_each_element[debuff.statsType][debuff.element][debuff.actionType] += debuff.value;
    }
}

//เป้าเดี่ยวแปะ
void debuffSingleApply(AllyUnit *ptr,Enemy *enemy,vector<BuffClass> debuffSet,string debuffName){
    if(!debuffApply(ptr,enemy,debuffName))return;
    for(BuffClass &debuff : debuffSet){
        if(debuff.statsType==Stats::FLAT_SPD||debuff.statsType==Stats::SPD_P)enemy->speedBuff(debuff);
        else enemy->Stats_type[debuff.statsType][debuff.actionType] += debuff.value;
    }
}
void debuffSingleApply(AllyUnit *ptr,Enemy *enemy,vector<BuffElementClass> debuffSet,string debuffName){
    if(!debuffApply(ptr,enemy,debuffName))return;
    for(BuffElementClass &debuff : debuffSet){
        enemy->Stats_each_element[debuff.statsType][debuff.element][debuff.actionType] += debuff.value;
    }
}
//เป้าเดี่ยวแปะ + extend
void debuffSingleApply(AllyUnit *ptr,Enemy *enemy,vector<BuffClass> debuffSet,string debuffName ,int extend) {
    if(!debuffApply(ptr,enemy,debuffName,extend))return;
    for(BuffClass &debuff : debuffSet){
        if(debuff.statsType==Stats::FLAT_SPD||debuff.statsType==Stats::SPD_P)enemy->speedBuff(debuff);
        else enemy->Stats_type[debuff.statsType][debuff.actionType] += debuff.value;
    }
}
void debuffSingleApply(AllyUnit *ptr,Enemy *enemy,vector<BuffElementClass> debuffSet,string debuffName ,int extend) {
    if(!debuffApply(ptr,enemy,debuffName,extend))return;
    for(BuffElementClass &debuff : debuffSet){
        enemy->Stats_each_element[debuff.statsType][debuff.element][debuff.actionType] += debuff.value;
    }
}
//เป้าเดี่ยวMark
void debuffSingleMark(AllyUnit *ptr,Enemy *enemy,vector<BuffClass> debuffSet,string debuffName){
    if(!debuffMark(ptr,enemy,debuffName))return;
    for(BuffClass &debuff : debuffSet){
        if(debuff.statsType==Stats::FLAT_SPD||debuff.statsType==Stats::SPD_P)ptr->speedBuff(debuff);
        else enemy->Stats_type[debuff.statsType][debuff.actionType] += debuff.value;
    }
}
void debuffSingleMark(AllyUnit *ptr,Enemy *enemy,vector<BuffElementClass> debuffSet,string debuffName){
    if(!debuffMark(ptr,enemy,debuffName))return;
    for(BuffElementClass &debuff : debuffSet){
        enemy->Stats_each_element[debuff.statsType][debuff.element][debuff.actionType] += debuff.value;
    }
}
//ST MARK + extend
void debuffSingleMark(AllyUnit *ptr,Enemy *enemy,vector<BuffClass> debuffSet,string debuffName ,int extend) {
    if(!debuffMark(ptr,enemy,debuffName,extend))return;
    for(BuffClass &debuff : debuffSet){
        if(debuff.statsType==Stats::FLAT_SPD||debuff.statsType==Stats::SPD_P)enemy->speedBuff(debuff);
        else enemy->Stats_type[debuff.statsType][debuff.actionType] += debuff.value;
    }
}
void debuffSingleMark(AllyUnit *ptr,Enemy *enemy,vector<BuffElementClass> debuffSet,string debuffName ,int extend) {
    if(!debuffMark(ptr,enemy,debuffName,extend))return;
    for(BuffElementClass &debuff : debuffSet){
        enemy->Stats_each_element[debuff.statsType][debuff.element][debuff.actionType] += debuff.value;
    }
}
void debuffAllEnemy(vector<BuffClass> debuffSet) {
    for (auto &each : enemyList) {
        debuffSingle(each,debuffSet);
    }
}
void debuffAllEnemy(vector<BuffElementClass> debuffSet) {
    for (auto &each : enemyList) {
        debuffSingle(each,debuffSet);
    }
}
void debuffEnemyTargets(vector<Enemy*> targets,vector<BuffClass> debuffSet){
    for (auto &each : targets) {
        debuffSingle(each,debuffSet);
    }
}
void debuffEnemyTargets(vector<Enemy*> targets,vector<BuffElementClass> debuffSet){
        for (auto &each : targets) {
        debuffSingle(each,debuffSet);
    }
}

void debuffAllEnemyApply(AllyUnit *ptr,vector<BuffClass> debuffSet, string Debuff_Name) {
    for (auto &each : enemyList) {
        if(!debuffApply(ptr,each,Debuff_Name))continue;
        debuffSingle(each,debuffSet);
    }
}
void debuffAllEnemyApply(AllyUnit *ptr,vector<BuffElementClass> debuffSet, string Debuff_Name) {
    for (auto &each : enemyList) {
        if(!debuffApply(ptr,each,Debuff_Name))continue;
        debuffSingle(each,debuffSet);
    }
}
void debuffAllEnemyApply(AllyUnit *ptr,vector<BuffClass> debuffSet, string Debuff_Name,int extend) {
    for (auto &each : enemyList) {
        if(!debuffApply(ptr,each,Debuff_Name,extend))continue;
        debuffSingle(each,debuffSet);
    }
}
void debuffAllEnemyApply(AllyUnit *ptr,vector<BuffElementClass> debuffSet, string Debuff_Name,int extend) {
    for (auto &each : enemyList) {
        if(!debuffApply(ptr,each,Debuff_Name,extend))continue;
        debuffSingle(each,debuffSet);
    }
}
void debuffEnemyTargetsApply(AllyUnit *ptr,vector<Enemy*> targets,vector<BuffClass> debuffSet, string Debuff_Name){
    for (auto &each : targets) {
        if(!debuffApply(ptr,each, Debuff_Name)) continue;
        debuffSingle(each,debuffSet);
    }
}
void debuffEnemyTargetsApply(AllyUnit *ptr,vector<Enemy*> targets,vector<BuffElementClass> debuffSet, string Debuff_Name){
    for (auto &each : targets) {
        if(!debuffApply(ptr,each, Debuff_Name)) continue;
        debuffSingle(each,debuffSet);
    }
}
void debuffEnemyTargetsApply(AllyUnit *ptr,vector<Enemy*> targets,vector<BuffClass> debuffSet, string Debuff_Name,int extend){
    for (auto &each : targets) {
        if(!debuffApply(ptr,each, Debuff_Name, extend)) continue;
        debuffSingle(each,debuffSet);
    }
}
void debuffEnemyTargetsApply(AllyUnit *ptr,vector<Enemy*> targets,vector<BuffElementClass> debuffSet, string Debuff_Name,int extend){
    for (auto &each : targets) {
        if(!debuffApply(ptr,each, Debuff_Name, extend)) continue;
        debuffSingle(each,debuffSet);
    }
}

void debuffAllEnemyMark(vector<BuffClass> debuffSet, AllyUnit* ptr, string Debuff_Name) {
    for (auto &each : enemyList) {
        if (!debuffMark(ptr,each, Debuff_Name)) continue;
        debuffSingle(each,debuffSet);
    }
}

void debuffAllEnemyMark(vector<BuffElementClass> debuffSet, AllyUnit* ptr, string Debuff_Name) {
    for (auto &each : enemyList) {
        if (!debuffMark(ptr,each, Debuff_Name)) continue;
        debuffSingle(each,debuffSet);
    }
}

void debuffAllEnemyMark(vector<BuffClass> debuffSet, AllyUnit* ptr, string Debuff_Name, int extend) {
    for (auto &each : enemyList) {
        if (!debuffMark(ptr,each, Debuff_Name, extend)) continue;
        debuffSingle(each,debuffSet);
    }
}

void debuffAllEnemyMark(vector<BuffElementClass> debuffSet, AllyUnit* ptr, string Debuff_Name, int extend) {
    for (auto &each : enemyList) {
        if (!debuffMark(ptr,each, Debuff_Name, extend)) continue;
        debuffSingle(each,debuffSet);
    }
}
void debuffEnemyTargetsyMark(vector<Enemy*> targets, vector<BuffClass> debuffSet, AllyUnit* ptr, string Debuff_Name) {
    for (auto& each : targets) {
        if (!debuffMark(ptr,each, Debuff_Name)) continue;
        debuffSingle(each,debuffSet);
    }
}

void debuffEnemyTargetsyMark(vector<Enemy*> targets, vector<BuffElementClass> debuffSet, AllyUnit* ptr, string Debuff_Name) {
    for (auto& each : targets) {
        if (!debuffMark(ptr,each, Debuff_Name)) continue;
        debuffSingle(each,debuffSet);
    }
}

void debuffEnemyTargetsyMark(vector<Enemy*> targets, vector<BuffClass> debuffSet, AllyUnit* ptr, string Debuff_Name, int extend) {
    for (auto& each : targets) {
        if (!debuffMark(ptr,each, Debuff_Name, extend)) continue;
        debuffSingle(each,debuffSet);
    }
}

void debuffEnemyTargetsyMark(vector<Enemy*> targets, vector<BuffElementClass> debuffSet, AllyUnit* ptr, string Debuff_Name, int extend) {
    for (auto& each : targets) {
        if (!debuffMark(ptr,each, Debuff_Name, extend)) continue;
        debuffSingle(each,debuffSet);
    }
}




