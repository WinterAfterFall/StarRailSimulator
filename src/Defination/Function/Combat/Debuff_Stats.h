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

bool isDebuffEnd(Enemy *enemy,string debuffName){
    if(enemy->atvStats->turnCnt==enemy->debuffEnd[debuffName]&&turn->name==enemy->atvStats->name){
        debuffRemove(enemy,debuffName);
        return true;
    }
    return false;
}

void extendDebuff(Enemy *enemy,string debuffName,int turnExtend){
    enemy->debuffEnd[debuffName] = enemy->atvStats->turnCnt+turnExtend;
}

void extendDebuffAll(string debuffName,int turnExtend){
    for(auto &each : enemyList){
        extendDebuff(each,debuffName,turnExtend);
    }
}
void extendDebuffTargets(vector<Enemy*> targets,string debuffName,int turnExtend){
    for(auto &each : targets){
        extendDebuff(each,debuffName,turnExtend);
    }
}

vector<ElementType> weaknessApplyChoose(AllyUnit *ptr,Enemy *enemy,int amount,string debuffName,int extend){
    vector<pair<int,ElementType>> weaknessPriority;
    vector<ElementType> choose;
    int i=1;
    for(auto &each : charList){
        if(enemy->weaknessType[each->elementType])continue;
        if(each->path==Path::HARMONY)weaknessPriority.push_back({totalAlly+4,each->elementType});
        else if(each->path==Path::NIHILITY)weaknessPriority.push_back({totalAlly+1,each->elementType});
        else if(each->path==Path::ABUNDANCE)weaknessPriority.push_back({totalAlly+3,each->elementType});
        else if(each->path==Path::PRESERVATION)weaknessPriority.push_back({totalAlly+2,each->elementType});
        else weaknessPriority.push_back({i,each->elementType});
        i++;
    }
    if(weaknessPriority.size()==0){
        for(auto &e : enemy->weaknessTypeCountdown){
            weaknessPriority.push_back({e.second,e.first});
        }
    }
    sort(weaknessPriority.begin(),weaknessPriority.end());
    amount = max(0, min(amount, static_cast<int>(weaknessPriority.size())));
    for(int i = 0;i<amount;i++){
        choose.push_back(weaknessPriority[i].second);
    }
    if(amount==1)debuffName = debuffName + " " + toString(choose[0]);
    weaknessApply(ptr,enemy,choose,debuffName,extend);
    return choose;
}
void weaknessApply(AllyUnit *ptr,Enemy *enemy,vector<ElementType> elementList ,string debuffName,int extend){
    allEventBeforeApplyDebuff(ptr,enemy);
    for(auto &each : elementList){
        if(enemy->weaknessType[each] == 0){
            enemy->currentWeaknessElementAmount++;
            enemy->weaknessType[each] = 1;
        }

        enemy->weaknessTypeCountdown[each] = 
        (enemy->weaknessTypeCountdown[each] > extend + enemy->atvStats->turnCnt) ?
        enemy->weaknessTypeCountdown[each] :
        extend + enemy->atvStats->turnCnt;
    }
    allEventApplyWeakness(ptr,enemy,elementList);
    if(!enemy->getDebuff(debuffName)){
        enemy->setDebuff(debuffName,1);
        enemy->addTotalDebuff(1);
    }
    allEventAfterApplyDebuff(ptr,enemy);
    extendDebuff(enemy,debuffName,extend);
}
void weaknessApply(AllyUnit *ptr,Enemy *enemy,vector<ElementType> elementList,int extend){
    for(auto &each : elementList){
        if(enemy->weaknessType[each] == 0){
            enemy->currentWeaknessElementAmount++;
            enemy->weaknessType[each] = 1;
        }

        enemy->weaknessTypeCountdown[each] = 
        (enemy->weaknessTypeCountdown[each] > extend + enemy->atvStats->turnCnt) ?
        enemy->weaknessTypeCountdown[each] :
        extend + enemy->atvStats->turnCnt;
    }
    allEventApplyWeakness(ptr,enemy,elementList);
}

//เป้าเดี่ยว
void debuffSingle(Enemy *enemy,vector<BuffClass> debuffSet) {
    for(BuffClass &debuff : debuffSet){
        if(debuff.statsType==Stats::FLAT_SPD||debuff.statsType==Stats::SPD_P)enemy->speedBuff(debuff);
        else enemy->statsType[debuff.statsType][debuff.actionType] += debuff.value;
    }
}
void debuffSingle(Enemy *enemy,vector<BuffElementClass> debuffSet) {
    for(BuffElementClass &debuff : debuffSet){
        enemy->statsEachElement[debuff.statsType][debuff.element][debuff.actionType] += debuff.value;
    }
}

//เป้าเดี่ยวแปะ
void debuffSingleApply(AllyUnit *ptr,Enemy *enemy,vector<BuffClass> debuffSet,string debuffName){
    if(!debuffApply(ptr,enemy,debuffName))return;
    for(BuffClass &debuff : debuffSet){
        if(debuff.statsType==Stats::FLAT_SPD||debuff.statsType==Stats::SPD_P)enemy->speedBuff(debuff);
        else enemy->statsType[debuff.statsType][debuff.actionType] += debuff.value;
    }
}
void debuffSingleApply(AllyUnit *ptr,Enemy *enemy,vector<BuffElementClass> debuffSet,string debuffName){
    if(!debuffApply(ptr,enemy,debuffName))return;
    for(BuffElementClass &debuff : debuffSet){
        enemy->statsEachElement[debuff.statsType][debuff.element][debuff.actionType] += debuff.value;
    }
}
//เป้าเดี่ยวแปะ + extend
void debuffSingleApply(AllyUnit *ptr,Enemy *enemy,vector<BuffClass> debuffSet,string debuffName ,int extend) {
    if(!debuffApply(ptr,enemy,debuffName,extend))return;
    for(BuffClass &debuff : debuffSet){
        if(debuff.statsType==Stats::FLAT_SPD||debuff.statsType==Stats::SPD_P)enemy->speedBuff(debuff);
        else enemy->statsType[debuff.statsType][debuff.actionType] += debuff.value;
    }
}
void debuffSingleApply(AllyUnit *ptr,Enemy *enemy,vector<BuffElementClass> debuffSet,string debuffName ,int extend) {
    if(!debuffApply(ptr,enemy,debuffName,extend))return;
    for(BuffElementClass &debuff : debuffSet){
        enemy->statsEachElement[debuff.statsType][debuff.element][debuff.actionType] += debuff.value;
    }
}
//เป้าเดี่ยวMark
void debuffSingleMark(AllyUnit *ptr,Enemy *enemy,vector<BuffClass> debuffSet,string debuffName){
    if(!debuffMark(ptr,enemy,debuffName))return;
    for(BuffClass &debuff : debuffSet){
        if(debuff.statsType==Stats::FLAT_SPD||debuff.statsType==Stats::SPD_P)enemy->speedBuff(debuff);
        else enemy->statsType[debuff.statsType][debuff.actionType] += debuff.value;
    }
}
void debuffSingleMark(AllyUnit *ptr,Enemy *enemy,vector<BuffElementClass> debuffSet,string debuffName){
    if(!debuffMark(ptr,enemy,debuffName))return;
    for(BuffElementClass &debuff : debuffSet){
        enemy->statsEachElement[debuff.statsType][debuff.element][debuff.actionType] += debuff.value;
    }
}
//ST MARK + extend
void debuffSingleMark(AllyUnit *ptr,Enemy *enemy,vector<BuffClass> debuffSet,string debuffName ,int extend) {
    if(!debuffMark(ptr,enemy,debuffName,extend))return;
    for(BuffClass &debuff : debuffSet){
        if(debuff.statsType==Stats::FLAT_SPD||debuff.statsType==Stats::SPD_P)enemy->speedBuff(debuff);
        else enemy->statsType[debuff.statsType][debuff.actionType] += debuff.value;
    }
}
void debuffSingleMark(AllyUnit *ptr,Enemy *enemy,vector<BuffElementClass> debuffSet,string debuffName ,int extend) {
    if(!debuffMark(ptr,enemy,debuffName,extend))return;
    for(BuffElementClass &debuff : debuffSet){
        enemy->statsEachElement[debuff.statsType][debuff.element][debuff.actionType] += debuff.value;
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

void debuffAllEnemyApply(AllyUnit *ptr,vector<BuffClass> debuffSet, string debuffName) {
    for (auto &each : enemyList) {
        if(!debuffApply(ptr,each,debuffName))continue;
        debuffSingle(each,debuffSet);
    }
}
void debuffAllEnemyApply(AllyUnit *ptr,vector<BuffElementClass> debuffSet, string debuffName) {
    for (auto &each : enemyList) {
        if(!debuffApply(ptr,each,debuffName))continue;
        debuffSingle(each,debuffSet);
    }
}
void debuffAllEnemyApply(AllyUnit *ptr,vector<BuffClass> debuffSet, string debuffName,int extend) {
    for (auto &each : enemyList) {
        if(!debuffApply(ptr,each,debuffName,extend))continue;
        debuffSingle(each,debuffSet);
    }
}
void debuffAllEnemyApply(AllyUnit *ptr,vector<BuffElementClass> debuffSet, string debuffName,int extend) {
    for (auto &each : enemyList) {
        if(!debuffApply(ptr,each,debuffName,extend))continue;
        debuffSingle(each,debuffSet);
    }
}
void debuffEnemyTargetsApply(AllyUnit *ptr,vector<Enemy*> targets,vector<BuffClass> debuffSet, string debuffName){
    for (auto &each : targets) {
        if(!debuffApply(ptr,each, debuffName)) continue;
        debuffSingle(each,debuffSet);
    }
}
void debuffEnemyTargetsApply(AllyUnit *ptr,vector<Enemy*> targets,vector<BuffElementClass> debuffSet, string debuffName){
    for (auto &each : targets) {
        if(!debuffApply(ptr,each, debuffName)) continue;
        debuffSingle(each,debuffSet);
    }
}
void debuffEnemyTargetsApply(AllyUnit *ptr,vector<Enemy*> targets,vector<BuffClass> debuffSet, string debuffName,int extend){
    for (auto &each : targets) {
        if(!debuffApply(ptr,each, debuffName, extend)) continue;
        debuffSingle(each,debuffSet);
    }
}
void debuffEnemyTargetsApply(AllyUnit *ptr,vector<Enemy*> targets,vector<BuffElementClass> debuffSet, string debuffName,int extend){
    for (auto &each : targets) {
        if(!debuffApply(ptr,each, debuffName, extend)) continue;
        debuffSingle(each,debuffSet);
    }
}

void debuffAllEnemyMark(vector<BuffClass> debuffSet, AllyUnit* ptr, string debuffName) {
    for (auto &each : enemyList) {
        if (!debuffMark(ptr,each, debuffName)) continue;
        debuffSingle(each,debuffSet);
    }
}

void debuffAllEnemyMark(vector<BuffElementClass> debuffSet, AllyUnit* ptr, string debuffName) {
    for (auto &each : enemyList) {
        if (!debuffMark(ptr,each, debuffName)) continue;
        debuffSingle(each,debuffSet);
    }
}

void debuffAllEnemyMark(vector<BuffClass> debuffSet, AllyUnit* ptr, string debuffName, int extend) {
    for (auto &each : enemyList) {
        if (!debuffMark(ptr,each, debuffName, extend)) continue;
        debuffSingle(each,debuffSet);
    }
}

void debuffAllEnemyMark(vector<BuffElementClass> debuffSet, AllyUnit* ptr, string debuffName, int extend) {
    for (auto &each : enemyList) {
        if (!debuffMark(ptr,each, debuffName, extend)) continue;
        debuffSingle(each,debuffSet);
    }
}
void debuffEnemyTargetsyMark(vector<Enemy*> targets, vector<BuffClass> debuffSet, AllyUnit* ptr, string debuffName) {
    for (auto& each : targets) {
        if (!debuffMark(ptr,each, debuffName)) continue;
        debuffSingle(each,debuffSet);
    }
}

void debuffEnemyTargetsyMark(vector<Enemy*> targets, vector<BuffElementClass> debuffSet, AllyUnit* ptr, string debuffName) {
    for (auto& each : targets) {
        if (!debuffMark(ptr,each, debuffName)) continue;
        debuffSingle(each,debuffSet);
    }
}

void debuffEnemyTargetsyMark(vector<Enemy*> targets, vector<BuffClass> debuffSet, AllyUnit* ptr, string debuffName, int extend) {
    for (auto& each : targets) {
        if (!debuffMark(ptr,each, debuffName, extend)) continue;
        debuffSingle(each,debuffSet);
    }
}

void debuffEnemyTargetsyMark(vector<Enemy*> targets, vector<BuffElementClass> debuffSet, AllyUnit* ptr, string debuffName, int extend) {
    for (auto& each : targets) {
        if (!debuffMark(ptr,each, debuffName, extend)) continue;
        debuffSingle(each,debuffSet);
    }
}




